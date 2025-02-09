/**
 * @file
 * This file is part of SeisSol.
 *
 * @author Sebastian Rettenberger (sebastian.rettenberger AT tum.de, http://www5.in.tum.de/wiki/index.php/Sebastian_Rettenberger)
 *
 * @section LICENSE
 * Copyright (c) 2015-2016, SeisSol Group
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @section DESCRIPTION
 * Main class for POSIX checkpoints
 */

#ifndef CHECKPOINT_POSIX_CHECK_POINT_H
#define CHECKPOINT_POSIX_CHECK_POINT_H

#ifdef USE_MPI
#include <mpi.h>
#endif // USE_MPI

#include <cstring>
#include <errno.h>
#include <fcntl.h>
#include <string>
#include <unistd.h>
#include <sys/stat.h>

#include "utils/logger.h"
#include "utils/stringutils.h"

#include "Checkpoint/CheckPoint.h"
#include "Initializer/preProcessorMacros.fpp"

namespace seissol
{

namespace checkpoint
{

namespace posix
{

class CheckPoint : virtual public seissol::checkpoint::CheckPoint
{
private:
	/** Checkpoint identifier (written to the beginning of the file) */
	const unsigned long m_identifier;

	/** Identifiers of the files */
	int m_files[2];

public:
	CheckPoint(unsigned long identifier)
		: m_identifier(identifier)
	{
		m_files[0] = m_files[1] = -1;
	}

	virtual ~CheckPoint() {}

	void setFilename(const char* filename)
	{
		initFilename(filename, 0L);
	}

	void close()
	{
		if (m_files[0] >= 0) {
			for (unsigned int i = 0; i < 2; i++)
				checkErr(::close(m_files[i]));
		}
	}

protected:
	bool exists()
	{
		if (!seissol::checkpoint::CheckPoint::exists())
			return false;

		int file = open();
		if (file < 0)
			return false;

		int hasCheckpoint = validate(file);
		::close(file);

#ifdef USE_MPI
		MPI_Allreduce(MPI_IN_PLACE, &hasCheckpoint, 1, MPI_INT, MPI_LAND, comm());
#endif // USE_MPI

		return hasCheckpoint;
	}

	/**
	 * Finalize checkpoint writing: Flush the file
	 */
	void finalizeCheckpoint()
	{
		EPIK_USER_REG(r_flush, "checkpoint_flush");
		SCOREP_USER_REGION_DEFINE(r_flush);
		EPIK_USER_START(r_flush);
		SCOREP_USER_REGION_BEGIN(r_flush, "checkpoint_flush", SCOREP_USER_REGION_TYPE_COMMON);

		checkErr(fsync(m_files[odd()]));

		EPIK_USER_END(r_flush);
		SCOREP_USER_REGION_END(r_flush);
	}

	/**
	 * Open a check point file
	 *
	 * @return The file handle
	 */
	int open()
	{
		int fh = open64(linkFile().c_str(), O_RDONLY);

		if (fh < 0)
			logWarning() << "Could not open checkpoint file";

		return fh;
	}

	const std::string linkFile() const
	{
		return std::string(seissol::checkpoint::CheckPoint::linkFile())
		  + "/" + fname() + "." + utils::StringUtils::toString(rank() / groupSize());
	}

	const std::string dataFile(int odd) const
	{
		return seissol::checkpoint::CheckPoint::dataFile(odd)
		  + "/" + fname() + "." + utils::StringUtils::toString(rank() / groupSize());
	}

	/**
	 * @return The current file handle
	 */
	int file() const
	{
		return m_files[odd()];
	}

	/**
	 * @return The identifier of the file
	 */
	unsigned long identifier() const
	{
		return m_identifier;
	}

protected:
	void createFiles()
	{
		seissol::checkpoint::CheckPoint::createFiles();

		// Create the folder
		if (rank() == 0) {
			for (int i = 0; i < 2; i++) {
				int ret = mkdir(seissol::checkpoint::CheckPoint::dataFile(i).c_str(),
						S_IRWXU | S_IRWXG | S_IRWXO);
				if (ret < 0 && errno != EEXIST)
					checkErr(ret);
			}
		}

#ifdef USE_MPI
		// Make sure all processes see the folders
		MPI_Barrier(comm());
#endif // USE_MPI

		for (unsigned int i = 0; i < 2; i++) {
			m_files[i] = open64(dataFile(i).c_str(), O_WRONLY | O_CREAT,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
			checkErr(m_files[i]);

			checkErr(write(m_files[i], &m_identifier, sizeof(m_identifier)));

			// Sync file (required for performance measure)
			// TODO preallocate file first
			checkErr(fsync(m_files[i]));
		}
	}

private:
	/**
	 * Validate an existing check point file
	 */
	bool validate(int file) const
	{
		unsigned long id;
		ssize_t size = read(file, &id, sizeof(id));
		if (size < static_cast<ssize_t>(sizeof(id))) {
			logWarning() << "Could not read checkpoint header";
			return false;
		}

		if (id != identifier()) {
			logWarning() << "Checkpoint identifier does match";
			return false;
		}

		return true;
	}

protected:
	template<typename T>
	static void checkErr(T ret)
	{
		if (ret < 0)
			logError() << "Error in the POSIX checkpoint module:" << strerror(errno);
	}

	/**
	 * Can be used to check read/write errors
	 *
	 * @param ret The return value
	 * @param target The expected return value (> 0)
	 */
	template<typename T, typename U>
	static void checkErr(T ret, U target)
	{
		checkErr(ret);
		if (ret != static_cast<T>(target))
			logError() << "Error in the POSIX checkpoint module:"
				<< target << "bytes expected;" << ret << "bytes gotten";
	}
};

}

}

}

#endif // CHECKPOINT_POSIX_CHECK_POINT_H
