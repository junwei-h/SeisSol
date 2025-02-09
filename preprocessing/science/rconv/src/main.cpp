/**
 * @file
 * This file is part of SeisSol.
 *
 * @author Carsten Uphoff (c.uphoff AT tum.de, http://www5.in.tum.de/wiki/index.php/Carsten_Uphoff,_M.Sc.)
 *
 * @section LICENSE
 * Copyright (c) 2015, SeisSol Group
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
 **/

#include "SRF.h"
#include "NRFWriter.h"

#include <utils/args.h>
#include <iostream>


int main(int argc, char** argv)
{
  utils::Args args;
	args.addOption("mcs", 'm', "Proj.4 string that describes the mesh coordinate system (e.g. \"+proj=utm +zone=10 +datum=WGS84 +units=m +no_defs\").");
  args.addOption("input", 'i', "Input file (.srf)");
  args.addOption("output", 'o', "Output file (.nrf)");
  args.addOption("normalize-onset", 'n', "Subtract the minimum onset time from all onsets.", utils::Args::No, false);

	if (args.parse(argc, argv) == utils::Args::Success) {
    std::string mcs = args.getArgument<std::string>("mcs");
    std::string in = args.getArgument<std::string>("input");
    std::string out = args.getArgument<std::string>("output");
    bool normalizeOnset = args.isSet("normalize-onset");
    
    Map map(mcs);    
    std::cout << "Reading SRF..." << std::flush;
    std::vector<SRFPointSource> srf = parseSRF(in.c_str());
    std::cout << "finished." << std::endl;

    std::cout << "Writing NRF..." << std::flush;
    writeNRF(out.c_str(), srf, map, normalizeOnset);
    std::cout << "finished." << std::endl;
    
	} else {
		return -1;
	}
  
  return 0;
}
