// Copyright (c) 2015, Intel Corporation
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the copyright holder nor the names of its contributors
//       may be used to endorse or promote products derived from this software
//       without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// @file
// This file is part of SeisSol.
// 
// @author Alexander Breuer (breuer AT mytum.de, http://www5.in.tum.de/wiki/index.php/Dipl.-Math._Alexander_Breuer)
// @author Alexander Heinecke (alexander.heinecke AT mytum.de, http://www5.in.tum.de/wiki/index.php/Alexander_Heinecke,_M.Sc.,_M.Sc._with_honors)
// 
// @date 2015-11-22 19:14:15.655829
// 
// @section LICENSE
// Copyright (c) 2012-2015, SeisSol Group
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from this
//    software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// 
// @section DESCRIPTION
// Remark: This file was generated.
#ifndef SPARSEDKNCCPP
#define SPARSEDKNCCPP

#if defined( __SSE3__) || defined(__MIC__)
#include <immintrin.h>
#endif

#include <cstddef>
#ifndef NDEBUG
extern long long libxsmm_num_total_flops;
#endif

void dsparse_kXiDivMT_m1_n9_k4_ldAna2_ldB8_ldC8_beta0_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_n = 0;
  #pragma nounroll_and_jam
  for ( l_n = 0; l_n < 9; l_n++) {
    unsigned int l_m = 0;
    for ( l_m = 0; l_m < 1; l_m++) {
      C[(l_n*8)+l_m] = 0.0;
    }
#if defined(__SSE3__) || defined(__AVX__)
#else
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b1 = _mm256_broadcast_sd(&B[(l_n*8)+1]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b1 = _mm_loaddup_pd(&B[(l_n*8)+1]);
#endif
    __m128d c1_0 = _mm_load_sd(&C[(l_n*8)+0]);
    __m128d a1_0 = _mm_load_sd(&A[0]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_0 = _mm_add_sd(c1_0, _mm_mul_sd(a1_0, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_0 = _mm_add_sd(c1_0, _mm_mul_sd(a1_0, b1));
#endif
    _mm_store_sd(&C[(l_n*8)+0], c1_0);
#else
    C[(l_n*8)+0] += A[0] * B[(l_n*8)+1];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#else
#endif

#if defined(__SSE3__) || defined(__AVX__)
#else
#endif

  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 18;
#endif
}

void dsparse_starMatrix_m1_n9_k9_ldA8_ldBna2_ldC8_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  for ( l_m = 0; l_m < 1; l_m++) {
    C[0+l_m] += A[48+l_m] * B[0];
    C[0+l_m] += A[56+l_m] * B[1];
    C[0+l_m] += A[64+l_m] * B[2];
    C[8+l_m] += A[48+l_m] * B[3];
    C[8+l_m] += A[56+l_m] * B[4];
    C[8+l_m] += A[64+l_m] * B[5];
    C[16+l_m] += A[48+l_m] * B[6];
    C[16+l_m] += A[56+l_m] * B[7];
    C[16+l_m] += A[64+l_m] * B[8];
    C[24+l_m] += A[48+l_m] * B[9];
    C[24+l_m] += A[56+l_m] * B[10];
    C[32+l_m] += A[56+l_m] * B[11];
    C[32+l_m] += A[64+l_m] * B[12];
    C[40+l_m] += A[48+l_m] * B[13];
    C[40+l_m] += A[64+l_m] * B[14];
    C[48+l_m] += A[0+l_m] * B[15];
    C[48+l_m] += A[24+l_m] * B[16];
    C[48+l_m] += A[40+l_m] * B[17];
    C[56+l_m] += A[8+l_m] * B[18];
    C[56+l_m] += A[24+l_m] * B[19];
    C[56+l_m] += A[32+l_m] * B[20];
    C[64+l_m] += A[16+l_m] * B[21];
    C[64+l_m] += A[32+l_m] * B[22];
    C[64+l_m] += A[40+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 48;
#endif
}

void dsparse_starMatrix_m4_n9_k9_ldA8_ldBna3_ldC8_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 4; l_m++) {
    C[0+l_m] += A[48+l_m] * B[0];
    C[0+l_m] += A[56+l_m] * B[1];
    C[0+l_m] += A[64+l_m] * B[2];
    C[8+l_m] += A[48+l_m] * B[3];
    C[8+l_m] += A[56+l_m] * B[4];
    C[8+l_m] += A[64+l_m] * B[5];
    C[16+l_m] += A[48+l_m] * B[6];
    C[16+l_m] += A[56+l_m] * B[7];
    C[16+l_m] += A[64+l_m] * B[8];
    C[24+l_m] += A[48+l_m] * B[9];
    C[24+l_m] += A[56+l_m] * B[10];
    C[32+l_m] += A[56+l_m] * B[11];
    C[32+l_m] += A[64+l_m] * B[12];
    C[40+l_m] += A[48+l_m] * B[13];
    C[40+l_m] += A[64+l_m] * B[14];
    C[48+l_m] += A[0+l_m] * B[15];
    C[48+l_m] += A[24+l_m] * B[16];
    C[48+l_m] += A[40+l_m] * B[17];
    C[56+l_m] += A[8+l_m] * B[18];
    C[56+l_m] += A[24+l_m] * B[19];
    C[56+l_m] += A[32+l_m] * B[20];
    C[64+l_m] += A[16+l_m] * B[21];
    C[64+l_m] += A[32+l_m] * B[22];
    C[64+l_m] += A[40+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 192;
#endif
}

void dsparse_starMatrix_m1_n9_k9_ldA8_ldBna3_ldC8_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  for ( l_m = 0; l_m < 1; l_m++) {
    C[0+l_m] += A[48+l_m] * B[0];
    C[0+l_m] += A[56+l_m] * B[1];
    C[0+l_m] += A[64+l_m] * B[2];
    C[8+l_m] += A[48+l_m] * B[3];
    C[8+l_m] += A[56+l_m] * B[4];
    C[8+l_m] += A[64+l_m] * B[5];
    C[16+l_m] += A[48+l_m] * B[6];
    C[16+l_m] += A[56+l_m] * B[7];
    C[16+l_m] += A[64+l_m] * B[8];
    C[24+l_m] += A[48+l_m] * B[9];
    C[24+l_m] += A[56+l_m] * B[10];
    C[32+l_m] += A[56+l_m] * B[11];
    C[32+l_m] += A[64+l_m] * B[12];
    C[40+l_m] += A[48+l_m] * B[13];
    C[40+l_m] += A[64+l_m] * B[14];
    C[48+l_m] += A[0+l_m] * B[15];
    C[48+l_m] += A[24+l_m] * B[16];
    C[48+l_m] += A[40+l_m] * B[17];
    C[56+l_m] += A[8+l_m] * B[18];
    C[56+l_m] += A[24+l_m] * B[19];
    C[56+l_m] += A[32+l_m] * B[20];
    C[64+l_m] += A[16+l_m] * B[21];
    C[64+l_m] += A[32+l_m] * B[22];
    C[64+l_m] += A[40+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 48;
#endif
}

void dsparse_starMatrix_m10_n9_k9_ldA16_ldBna4_ldC16_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 10; l_m++) {
    C[0+l_m] += A[96+l_m] * B[0];
    C[0+l_m] += A[112+l_m] * B[1];
    C[0+l_m] += A[128+l_m] * B[2];
    C[16+l_m] += A[96+l_m] * B[3];
    C[16+l_m] += A[112+l_m] * B[4];
    C[16+l_m] += A[128+l_m] * B[5];
    C[32+l_m] += A[96+l_m] * B[6];
    C[32+l_m] += A[112+l_m] * B[7];
    C[32+l_m] += A[128+l_m] * B[8];
    C[48+l_m] += A[96+l_m] * B[9];
    C[48+l_m] += A[112+l_m] * B[10];
    C[64+l_m] += A[112+l_m] * B[11];
    C[64+l_m] += A[128+l_m] * B[12];
    C[80+l_m] += A[96+l_m] * B[13];
    C[80+l_m] += A[128+l_m] * B[14];
    C[96+l_m] += A[0+l_m] * B[15];
    C[96+l_m] += A[48+l_m] * B[16];
    C[96+l_m] += A[80+l_m] * B[17];
    C[112+l_m] += A[16+l_m] * B[18];
    C[112+l_m] += A[48+l_m] * B[19];
    C[112+l_m] += A[64+l_m] * B[20];
    C[128+l_m] += A[32+l_m] * B[21];
    C[128+l_m] += A[64+l_m] * B[22];
    C[128+l_m] += A[80+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 480;
#endif
}

void dsparse_starMatrix_m4_n9_k9_ldA8_ldBna4_ldC8_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 4; l_m++) {
    C[0+l_m] += A[48+l_m] * B[0];
    C[0+l_m] += A[56+l_m] * B[1];
    C[0+l_m] += A[64+l_m] * B[2];
    C[8+l_m] += A[48+l_m] * B[3];
    C[8+l_m] += A[56+l_m] * B[4];
    C[8+l_m] += A[64+l_m] * B[5];
    C[16+l_m] += A[48+l_m] * B[6];
    C[16+l_m] += A[56+l_m] * B[7];
    C[16+l_m] += A[64+l_m] * B[8];
    C[24+l_m] += A[48+l_m] * B[9];
    C[24+l_m] += A[56+l_m] * B[10];
    C[32+l_m] += A[56+l_m] * B[11];
    C[32+l_m] += A[64+l_m] * B[12];
    C[40+l_m] += A[48+l_m] * B[13];
    C[40+l_m] += A[64+l_m] * B[14];
    C[48+l_m] += A[0+l_m] * B[15];
    C[48+l_m] += A[24+l_m] * B[16];
    C[48+l_m] += A[40+l_m] * B[17];
    C[56+l_m] += A[8+l_m] * B[18];
    C[56+l_m] += A[24+l_m] * B[19];
    C[56+l_m] += A[32+l_m] * B[20];
    C[64+l_m] += A[16+l_m] * B[21];
    C[64+l_m] += A[32+l_m] * B[22];
    C[64+l_m] += A[40+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 192;
#endif
}

void dsparse_starMatrix_m1_n9_k9_ldA8_ldBna4_ldC8_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  for ( l_m = 0; l_m < 1; l_m++) {
    C[0+l_m] += A[48+l_m] * B[0];
    C[0+l_m] += A[56+l_m] * B[1];
    C[0+l_m] += A[64+l_m] * B[2];
    C[8+l_m] += A[48+l_m] * B[3];
    C[8+l_m] += A[56+l_m] * B[4];
    C[8+l_m] += A[64+l_m] * B[5];
    C[16+l_m] += A[48+l_m] * B[6];
    C[16+l_m] += A[56+l_m] * B[7];
    C[16+l_m] += A[64+l_m] * B[8];
    C[24+l_m] += A[48+l_m] * B[9];
    C[24+l_m] += A[56+l_m] * B[10];
    C[32+l_m] += A[56+l_m] * B[11];
    C[32+l_m] += A[64+l_m] * B[12];
    C[40+l_m] += A[48+l_m] * B[13];
    C[40+l_m] += A[64+l_m] * B[14];
    C[48+l_m] += A[0+l_m] * B[15];
    C[48+l_m] += A[24+l_m] * B[16];
    C[48+l_m] += A[40+l_m] * B[17];
    C[56+l_m] += A[8+l_m] * B[18];
    C[56+l_m] += A[24+l_m] * B[19];
    C[56+l_m] += A[32+l_m] * B[20];
    C[64+l_m] += A[16+l_m] * B[21];
    C[64+l_m] += A[32+l_m] * B[22];
    C[64+l_m] += A[40+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 48;
#endif
}

void dsparse_starMatrix_m20_n9_k9_ldA24_ldBna5_ldC24_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 20; l_m++) {
    C[0+l_m] += A[144+l_m] * B[0];
    C[0+l_m] += A[168+l_m] * B[1];
    C[0+l_m] += A[192+l_m] * B[2];
    C[24+l_m] += A[144+l_m] * B[3];
    C[24+l_m] += A[168+l_m] * B[4];
    C[24+l_m] += A[192+l_m] * B[5];
    C[48+l_m] += A[144+l_m] * B[6];
    C[48+l_m] += A[168+l_m] * B[7];
    C[48+l_m] += A[192+l_m] * B[8];
    C[72+l_m] += A[144+l_m] * B[9];
    C[72+l_m] += A[168+l_m] * B[10];
    C[96+l_m] += A[168+l_m] * B[11];
    C[96+l_m] += A[192+l_m] * B[12];
    C[120+l_m] += A[144+l_m] * B[13];
    C[120+l_m] += A[192+l_m] * B[14];
    C[144+l_m] += A[0+l_m] * B[15];
    C[144+l_m] += A[72+l_m] * B[16];
    C[144+l_m] += A[120+l_m] * B[17];
    C[168+l_m] += A[24+l_m] * B[18];
    C[168+l_m] += A[72+l_m] * B[19];
    C[168+l_m] += A[96+l_m] * B[20];
    C[192+l_m] += A[48+l_m] * B[21];
    C[192+l_m] += A[96+l_m] * B[22];
    C[192+l_m] += A[120+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 960;
#endif
}

void dsparse_starMatrix_m10_n9_k9_ldA16_ldBna5_ldC16_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 10; l_m++) {
    C[0+l_m] += A[96+l_m] * B[0];
    C[0+l_m] += A[112+l_m] * B[1];
    C[0+l_m] += A[128+l_m] * B[2];
    C[16+l_m] += A[96+l_m] * B[3];
    C[16+l_m] += A[112+l_m] * B[4];
    C[16+l_m] += A[128+l_m] * B[5];
    C[32+l_m] += A[96+l_m] * B[6];
    C[32+l_m] += A[112+l_m] * B[7];
    C[32+l_m] += A[128+l_m] * B[8];
    C[48+l_m] += A[96+l_m] * B[9];
    C[48+l_m] += A[112+l_m] * B[10];
    C[64+l_m] += A[112+l_m] * B[11];
    C[64+l_m] += A[128+l_m] * B[12];
    C[80+l_m] += A[96+l_m] * B[13];
    C[80+l_m] += A[128+l_m] * B[14];
    C[96+l_m] += A[0+l_m] * B[15];
    C[96+l_m] += A[48+l_m] * B[16];
    C[96+l_m] += A[80+l_m] * B[17];
    C[112+l_m] += A[16+l_m] * B[18];
    C[112+l_m] += A[48+l_m] * B[19];
    C[112+l_m] += A[64+l_m] * B[20];
    C[128+l_m] += A[32+l_m] * B[21];
    C[128+l_m] += A[64+l_m] * B[22];
    C[128+l_m] += A[80+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 480;
#endif
}

void dsparse_starMatrix_m4_n9_k9_ldA8_ldBna5_ldC8_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 4; l_m++) {
    C[0+l_m] += A[48+l_m] * B[0];
    C[0+l_m] += A[56+l_m] * B[1];
    C[0+l_m] += A[64+l_m] * B[2];
    C[8+l_m] += A[48+l_m] * B[3];
    C[8+l_m] += A[56+l_m] * B[4];
    C[8+l_m] += A[64+l_m] * B[5];
    C[16+l_m] += A[48+l_m] * B[6];
    C[16+l_m] += A[56+l_m] * B[7];
    C[16+l_m] += A[64+l_m] * B[8];
    C[24+l_m] += A[48+l_m] * B[9];
    C[24+l_m] += A[56+l_m] * B[10];
    C[32+l_m] += A[56+l_m] * B[11];
    C[32+l_m] += A[64+l_m] * B[12];
    C[40+l_m] += A[48+l_m] * B[13];
    C[40+l_m] += A[64+l_m] * B[14];
    C[48+l_m] += A[0+l_m] * B[15];
    C[48+l_m] += A[24+l_m] * B[16];
    C[48+l_m] += A[40+l_m] * B[17];
    C[56+l_m] += A[8+l_m] * B[18];
    C[56+l_m] += A[24+l_m] * B[19];
    C[56+l_m] += A[32+l_m] * B[20];
    C[64+l_m] += A[16+l_m] * B[21];
    C[64+l_m] += A[32+l_m] * B[22];
    C[64+l_m] += A[40+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 192;
#endif
}

void dsparse_starMatrix_m1_n9_k9_ldA8_ldBna5_ldC8_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  for ( l_m = 0; l_m < 1; l_m++) {
    C[0+l_m] += A[48+l_m] * B[0];
    C[0+l_m] += A[56+l_m] * B[1];
    C[0+l_m] += A[64+l_m] * B[2];
    C[8+l_m] += A[48+l_m] * B[3];
    C[8+l_m] += A[56+l_m] * B[4];
    C[8+l_m] += A[64+l_m] * B[5];
    C[16+l_m] += A[48+l_m] * B[6];
    C[16+l_m] += A[56+l_m] * B[7];
    C[16+l_m] += A[64+l_m] * B[8];
    C[24+l_m] += A[48+l_m] * B[9];
    C[24+l_m] += A[56+l_m] * B[10];
    C[32+l_m] += A[56+l_m] * B[11];
    C[32+l_m] += A[64+l_m] * B[12];
    C[40+l_m] += A[48+l_m] * B[13];
    C[40+l_m] += A[64+l_m] * B[14];
    C[48+l_m] += A[0+l_m] * B[15];
    C[48+l_m] += A[24+l_m] * B[16];
    C[48+l_m] += A[40+l_m] * B[17];
    C[56+l_m] += A[8+l_m] * B[18];
    C[56+l_m] += A[24+l_m] * B[19];
    C[56+l_m] += A[32+l_m] * B[20];
    C[64+l_m] += A[16+l_m] * B[21];
    C[64+l_m] += A[32+l_m] * B[22];
    C[64+l_m] += A[40+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 48;
#endif
}

void dsparse_starMatrix_m35_n9_k9_ldA40_ldBna6_ldC40_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 35; l_m++) {
    C[0+l_m] += A[240+l_m] * B[0];
    C[0+l_m] += A[280+l_m] * B[1];
    C[0+l_m] += A[320+l_m] * B[2];
    C[40+l_m] += A[240+l_m] * B[3];
    C[40+l_m] += A[280+l_m] * B[4];
    C[40+l_m] += A[320+l_m] * B[5];
    C[80+l_m] += A[240+l_m] * B[6];
    C[80+l_m] += A[280+l_m] * B[7];
    C[80+l_m] += A[320+l_m] * B[8];
    C[120+l_m] += A[240+l_m] * B[9];
    C[120+l_m] += A[280+l_m] * B[10];
    C[160+l_m] += A[280+l_m] * B[11];
    C[160+l_m] += A[320+l_m] * B[12];
    C[200+l_m] += A[240+l_m] * B[13];
    C[200+l_m] += A[320+l_m] * B[14];
    C[240+l_m] += A[0+l_m] * B[15];
    C[240+l_m] += A[120+l_m] * B[16];
    C[240+l_m] += A[200+l_m] * B[17];
    C[280+l_m] += A[40+l_m] * B[18];
    C[280+l_m] += A[120+l_m] * B[19];
    C[280+l_m] += A[160+l_m] * B[20];
    C[320+l_m] += A[80+l_m] * B[21];
    C[320+l_m] += A[160+l_m] * B[22];
    C[320+l_m] += A[200+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 1680;
#endif
}

void dsparse_starMatrix_m20_n9_k9_ldA24_ldBna6_ldC24_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 20; l_m++) {
    C[0+l_m] += A[144+l_m] * B[0];
    C[0+l_m] += A[168+l_m] * B[1];
    C[0+l_m] += A[192+l_m] * B[2];
    C[24+l_m] += A[144+l_m] * B[3];
    C[24+l_m] += A[168+l_m] * B[4];
    C[24+l_m] += A[192+l_m] * B[5];
    C[48+l_m] += A[144+l_m] * B[6];
    C[48+l_m] += A[168+l_m] * B[7];
    C[48+l_m] += A[192+l_m] * B[8];
    C[72+l_m] += A[144+l_m] * B[9];
    C[72+l_m] += A[168+l_m] * B[10];
    C[96+l_m] += A[168+l_m] * B[11];
    C[96+l_m] += A[192+l_m] * B[12];
    C[120+l_m] += A[144+l_m] * B[13];
    C[120+l_m] += A[192+l_m] * B[14];
    C[144+l_m] += A[0+l_m] * B[15];
    C[144+l_m] += A[72+l_m] * B[16];
    C[144+l_m] += A[120+l_m] * B[17];
    C[168+l_m] += A[24+l_m] * B[18];
    C[168+l_m] += A[72+l_m] * B[19];
    C[168+l_m] += A[96+l_m] * B[20];
    C[192+l_m] += A[48+l_m] * B[21];
    C[192+l_m] += A[96+l_m] * B[22];
    C[192+l_m] += A[120+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 960;
#endif
}

void dsparse_starMatrix_m10_n9_k9_ldA16_ldBna6_ldC16_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 10; l_m++) {
    C[0+l_m] += A[96+l_m] * B[0];
    C[0+l_m] += A[112+l_m] * B[1];
    C[0+l_m] += A[128+l_m] * B[2];
    C[16+l_m] += A[96+l_m] * B[3];
    C[16+l_m] += A[112+l_m] * B[4];
    C[16+l_m] += A[128+l_m] * B[5];
    C[32+l_m] += A[96+l_m] * B[6];
    C[32+l_m] += A[112+l_m] * B[7];
    C[32+l_m] += A[128+l_m] * B[8];
    C[48+l_m] += A[96+l_m] * B[9];
    C[48+l_m] += A[112+l_m] * B[10];
    C[64+l_m] += A[112+l_m] * B[11];
    C[64+l_m] += A[128+l_m] * B[12];
    C[80+l_m] += A[96+l_m] * B[13];
    C[80+l_m] += A[128+l_m] * B[14];
    C[96+l_m] += A[0+l_m] * B[15];
    C[96+l_m] += A[48+l_m] * B[16];
    C[96+l_m] += A[80+l_m] * B[17];
    C[112+l_m] += A[16+l_m] * B[18];
    C[112+l_m] += A[48+l_m] * B[19];
    C[112+l_m] += A[64+l_m] * B[20];
    C[128+l_m] += A[32+l_m] * B[21];
    C[128+l_m] += A[64+l_m] * B[22];
    C[128+l_m] += A[80+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 480;
#endif
}

void dsparse_starMatrix_m4_n9_k9_ldA8_ldBna6_ldC8_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 4; l_m++) {
    C[0+l_m] += A[48+l_m] * B[0];
    C[0+l_m] += A[56+l_m] * B[1];
    C[0+l_m] += A[64+l_m] * B[2];
    C[8+l_m] += A[48+l_m] * B[3];
    C[8+l_m] += A[56+l_m] * B[4];
    C[8+l_m] += A[64+l_m] * B[5];
    C[16+l_m] += A[48+l_m] * B[6];
    C[16+l_m] += A[56+l_m] * B[7];
    C[16+l_m] += A[64+l_m] * B[8];
    C[24+l_m] += A[48+l_m] * B[9];
    C[24+l_m] += A[56+l_m] * B[10];
    C[32+l_m] += A[56+l_m] * B[11];
    C[32+l_m] += A[64+l_m] * B[12];
    C[40+l_m] += A[48+l_m] * B[13];
    C[40+l_m] += A[64+l_m] * B[14];
    C[48+l_m] += A[0+l_m] * B[15];
    C[48+l_m] += A[24+l_m] * B[16];
    C[48+l_m] += A[40+l_m] * B[17];
    C[56+l_m] += A[8+l_m] * B[18];
    C[56+l_m] += A[24+l_m] * B[19];
    C[56+l_m] += A[32+l_m] * B[20];
    C[64+l_m] += A[16+l_m] * B[21];
    C[64+l_m] += A[32+l_m] * B[22];
    C[64+l_m] += A[40+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 192;
#endif
}

void dsparse_starMatrix_m1_n9_k9_ldA8_ldBna6_ldC8_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  for ( l_m = 0; l_m < 1; l_m++) {
    C[0+l_m] += A[48+l_m] * B[0];
    C[0+l_m] += A[56+l_m] * B[1];
    C[0+l_m] += A[64+l_m] * B[2];
    C[8+l_m] += A[48+l_m] * B[3];
    C[8+l_m] += A[56+l_m] * B[4];
    C[8+l_m] += A[64+l_m] * B[5];
    C[16+l_m] += A[48+l_m] * B[6];
    C[16+l_m] += A[56+l_m] * B[7];
    C[16+l_m] += A[64+l_m] * B[8];
    C[24+l_m] += A[48+l_m] * B[9];
    C[24+l_m] += A[56+l_m] * B[10];
    C[32+l_m] += A[56+l_m] * B[11];
    C[32+l_m] += A[64+l_m] * B[12];
    C[40+l_m] += A[48+l_m] * B[13];
    C[40+l_m] += A[64+l_m] * B[14];
    C[48+l_m] += A[0+l_m] * B[15];
    C[48+l_m] += A[24+l_m] * B[16];
    C[48+l_m] += A[40+l_m] * B[17];
    C[56+l_m] += A[8+l_m] * B[18];
    C[56+l_m] += A[24+l_m] * B[19];
    C[56+l_m] += A[32+l_m] * B[20];
    C[64+l_m] += A[16+l_m] * B[21];
    C[64+l_m] += A[32+l_m] * B[22];
    C[64+l_m] += A[40+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 48;
#endif
}

void dsparse_starMatrix_m56_n9_k9_ldA56_ldBna7_ldC56_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 56; l_m++) {
    C[0+l_m] += A[336+l_m] * B[0];
    C[0+l_m] += A[392+l_m] * B[1];
    C[0+l_m] += A[448+l_m] * B[2];
    C[56+l_m] += A[336+l_m] * B[3];
    C[56+l_m] += A[392+l_m] * B[4];
    C[56+l_m] += A[448+l_m] * B[5];
    C[112+l_m] += A[336+l_m] * B[6];
    C[112+l_m] += A[392+l_m] * B[7];
    C[112+l_m] += A[448+l_m] * B[8];
    C[168+l_m] += A[336+l_m] * B[9];
    C[168+l_m] += A[392+l_m] * B[10];
    C[224+l_m] += A[392+l_m] * B[11];
    C[224+l_m] += A[448+l_m] * B[12];
    C[280+l_m] += A[336+l_m] * B[13];
    C[280+l_m] += A[448+l_m] * B[14];
    C[336+l_m] += A[0+l_m] * B[15];
    C[336+l_m] += A[168+l_m] * B[16];
    C[336+l_m] += A[280+l_m] * B[17];
    C[392+l_m] += A[56+l_m] * B[18];
    C[392+l_m] += A[168+l_m] * B[19];
    C[392+l_m] += A[224+l_m] * B[20];
    C[448+l_m] += A[112+l_m] * B[21];
    C[448+l_m] += A[224+l_m] * B[22];
    C[448+l_m] += A[280+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 2688;
#endif
}

void dsparse_starMatrix_m35_n9_k9_ldA40_ldBna7_ldC40_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 35; l_m++) {
    C[0+l_m] += A[240+l_m] * B[0];
    C[0+l_m] += A[280+l_m] * B[1];
    C[0+l_m] += A[320+l_m] * B[2];
    C[40+l_m] += A[240+l_m] * B[3];
    C[40+l_m] += A[280+l_m] * B[4];
    C[40+l_m] += A[320+l_m] * B[5];
    C[80+l_m] += A[240+l_m] * B[6];
    C[80+l_m] += A[280+l_m] * B[7];
    C[80+l_m] += A[320+l_m] * B[8];
    C[120+l_m] += A[240+l_m] * B[9];
    C[120+l_m] += A[280+l_m] * B[10];
    C[160+l_m] += A[280+l_m] * B[11];
    C[160+l_m] += A[320+l_m] * B[12];
    C[200+l_m] += A[240+l_m] * B[13];
    C[200+l_m] += A[320+l_m] * B[14];
    C[240+l_m] += A[0+l_m] * B[15];
    C[240+l_m] += A[120+l_m] * B[16];
    C[240+l_m] += A[200+l_m] * B[17];
    C[280+l_m] += A[40+l_m] * B[18];
    C[280+l_m] += A[120+l_m] * B[19];
    C[280+l_m] += A[160+l_m] * B[20];
    C[320+l_m] += A[80+l_m] * B[21];
    C[320+l_m] += A[160+l_m] * B[22];
    C[320+l_m] += A[200+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 1680;
#endif
}

void dsparse_starMatrix_m20_n9_k9_ldA24_ldBna7_ldC24_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 20; l_m++) {
    C[0+l_m] += A[144+l_m] * B[0];
    C[0+l_m] += A[168+l_m] * B[1];
    C[0+l_m] += A[192+l_m] * B[2];
    C[24+l_m] += A[144+l_m] * B[3];
    C[24+l_m] += A[168+l_m] * B[4];
    C[24+l_m] += A[192+l_m] * B[5];
    C[48+l_m] += A[144+l_m] * B[6];
    C[48+l_m] += A[168+l_m] * B[7];
    C[48+l_m] += A[192+l_m] * B[8];
    C[72+l_m] += A[144+l_m] * B[9];
    C[72+l_m] += A[168+l_m] * B[10];
    C[96+l_m] += A[168+l_m] * B[11];
    C[96+l_m] += A[192+l_m] * B[12];
    C[120+l_m] += A[144+l_m] * B[13];
    C[120+l_m] += A[192+l_m] * B[14];
    C[144+l_m] += A[0+l_m] * B[15];
    C[144+l_m] += A[72+l_m] * B[16];
    C[144+l_m] += A[120+l_m] * B[17];
    C[168+l_m] += A[24+l_m] * B[18];
    C[168+l_m] += A[72+l_m] * B[19];
    C[168+l_m] += A[96+l_m] * B[20];
    C[192+l_m] += A[48+l_m] * B[21];
    C[192+l_m] += A[96+l_m] * B[22];
    C[192+l_m] += A[120+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 960;
#endif
}

void dsparse_starMatrix_m10_n9_k9_ldA16_ldBna7_ldC16_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 10; l_m++) {
    C[0+l_m] += A[96+l_m] * B[0];
    C[0+l_m] += A[112+l_m] * B[1];
    C[0+l_m] += A[128+l_m] * B[2];
    C[16+l_m] += A[96+l_m] * B[3];
    C[16+l_m] += A[112+l_m] * B[4];
    C[16+l_m] += A[128+l_m] * B[5];
    C[32+l_m] += A[96+l_m] * B[6];
    C[32+l_m] += A[112+l_m] * B[7];
    C[32+l_m] += A[128+l_m] * B[8];
    C[48+l_m] += A[96+l_m] * B[9];
    C[48+l_m] += A[112+l_m] * B[10];
    C[64+l_m] += A[112+l_m] * B[11];
    C[64+l_m] += A[128+l_m] * B[12];
    C[80+l_m] += A[96+l_m] * B[13];
    C[80+l_m] += A[128+l_m] * B[14];
    C[96+l_m] += A[0+l_m] * B[15];
    C[96+l_m] += A[48+l_m] * B[16];
    C[96+l_m] += A[80+l_m] * B[17];
    C[112+l_m] += A[16+l_m] * B[18];
    C[112+l_m] += A[48+l_m] * B[19];
    C[112+l_m] += A[64+l_m] * B[20];
    C[128+l_m] += A[32+l_m] * B[21];
    C[128+l_m] += A[64+l_m] * B[22];
    C[128+l_m] += A[80+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 480;
#endif
}

void dsparse_starMatrix_m4_n9_k9_ldA8_ldBna7_ldC8_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 4; l_m++) {
    C[0+l_m] += A[48+l_m] * B[0];
    C[0+l_m] += A[56+l_m] * B[1];
    C[0+l_m] += A[64+l_m] * B[2];
    C[8+l_m] += A[48+l_m] * B[3];
    C[8+l_m] += A[56+l_m] * B[4];
    C[8+l_m] += A[64+l_m] * B[5];
    C[16+l_m] += A[48+l_m] * B[6];
    C[16+l_m] += A[56+l_m] * B[7];
    C[16+l_m] += A[64+l_m] * B[8];
    C[24+l_m] += A[48+l_m] * B[9];
    C[24+l_m] += A[56+l_m] * B[10];
    C[32+l_m] += A[56+l_m] * B[11];
    C[32+l_m] += A[64+l_m] * B[12];
    C[40+l_m] += A[48+l_m] * B[13];
    C[40+l_m] += A[64+l_m] * B[14];
    C[48+l_m] += A[0+l_m] * B[15];
    C[48+l_m] += A[24+l_m] * B[16];
    C[48+l_m] += A[40+l_m] * B[17];
    C[56+l_m] += A[8+l_m] * B[18];
    C[56+l_m] += A[24+l_m] * B[19];
    C[56+l_m] += A[32+l_m] * B[20];
    C[64+l_m] += A[16+l_m] * B[21];
    C[64+l_m] += A[32+l_m] * B[22];
    C[64+l_m] += A[40+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 192;
#endif
}

void dsparse_starMatrix_m1_n9_k9_ldA8_ldBna7_ldC8_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  for ( l_m = 0; l_m < 1; l_m++) {
    C[0+l_m] += A[48+l_m] * B[0];
    C[0+l_m] += A[56+l_m] * B[1];
    C[0+l_m] += A[64+l_m] * B[2];
    C[8+l_m] += A[48+l_m] * B[3];
    C[8+l_m] += A[56+l_m] * B[4];
    C[8+l_m] += A[64+l_m] * B[5];
    C[16+l_m] += A[48+l_m] * B[6];
    C[16+l_m] += A[56+l_m] * B[7];
    C[16+l_m] += A[64+l_m] * B[8];
    C[24+l_m] += A[48+l_m] * B[9];
    C[24+l_m] += A[56+l_m] * B[10];
    C[32+l_m] += A[56+l_m] * B[11];
    C[32+l_m] += A[64+l_m] * B[12];
    C[40+l_m] += A[48+l_m] * B[13];
    C[40+l_m] += A[64+l_m] * B[14];
    C[48+l_m] += A[0+l_m] * B[15];
    C[48+l_m] += A[24+l_m] * B[16];
    C[48+l_m] += A[40+l_m] * B[17];
    C[56+l_m] += A[8+l_m] * B[18];
    C[56+l_m] += A[24+l_m] * B[19];
    C[56+l_m] += A[32+l_m] * B[20];
    C[64+l_m] += A[16+l_m] * B[21];
    C[64+l_m] += A[32+l_m] * B[22];
    C[64+l_m] += A[40+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 48;
#endif
}

void dsparse_starMatrix_m4_n9_k9_ldA8_ldBna2_ldC8_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 4; l_m++) {
    C[0+l_m] += A[48+l_m] * B[0];
    C[0+l_m] += A[56+l_m] * B[1];
    C[0+l_m] += A[64+l_m] * B[2];
    C[8+l_m] += A[48+l_m] * B[3];
    C[8+l_m] += A[56+l_m] * B[4];
    C[8+l_m] += A[64+l_m] * B[5];
    C[16+l_m] += A[48+l_m] * B[6];
    C[16+l_m] += A[56+l_m] * B[7];
    C[16+l_m] += A[64+l_m] * B[8];
    C[24+l_m] += A[48+l_m] * B[9];
    C[24+l_m] += A[56+l_m] * B[10];
    C[32+l_m] += A[56+l_m] * B[11];
    C[32+l_m] += A[64+l_m] * B[12];
    C[40+l_m] += A[48+l_m] * B[13];
    C[40+l_m] += A[64+l_m] * B[14];
    C[48+l_m] += A[0+l_m] * B[15];
    C[48+l_m] += A[24+l_m] * B[16];
    C[48+l_m] += A[40+l_m] * B[17];
    C[56+l_m] += A[8+l_m] * B[18];
    C[56+l_m] += A[24+l_m] * B[19];
    C[56+l_m] += A[32+l_m] * B[20];
    C[64+l_m] += A[16+l_m] * B[21];
    C[64+l_m] += A[32+l_m] * B[22];
    C[64+l_m] += A[40+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 192;
#endif
}

void dsparse_starMatrix_m10_n9_k9_ldA16_ldBna3_ldC16_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 10; l_m++) {
    C[0+l_m] += A[96+l_m] * B[0];
    C[0+l_m] += A[112+l_m] * B[1];
    C[0+l_m] += A[128+l_m] * B[2];
    C[16+l_m] += A[96+l_m] * B[3];
    C[16+l_m] += A[112+l_m] * B[4];
    C[16+l_m] += A[128+l_m] * B[5];
    C[32+l_m] += A[96+l_m] * B[6];
    C[32+l_m] += A[112+l_m] * B[7];
    C[32+l_m] += A[128+l_m] * B[8];
    C[48+l_m] += A[96+l_m] * B[9];
    C[48+l_m] += A[112+l_m] * B[10];
    C[64+l_m] += A[112+l_m] * B[11];
    C[64+l_m] += A[128+l_m] * B[12];
    C[80+l_m] += A[96+l_m] * B[13];
    C[80+l_m] += A[128+l_m] * B[14];
    C[96+l_m] += A[0+l_m] * B[15];
    C[96+l_m] += A[48+l_m] * B[16];
    C[96+l_m] += A[80+l_m] * B[17];
    C[112+l_m] += A[16+l_m] * B[18];
    C[112+l_m] += A[48+l_m] * B[19];
    C[112+l_m] += A[64+l_m] * B[20];
    C[128+l_m] += A[32+l_m] * B[21];
    C[128+l_m] += A[64+l_m] * B[22];
    C[128+l_m] += A[80+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 480;
#endif
}

void dsparse_starMatrix_m20_n9_k9_ldA24_ldBna4_ldC24_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 20; l_m++) {
    C[0+l_m] += A[144+l_m] * B[0];
    C[0+l_m] += A[168+l_m] * B[1];
    C[0+l_m] += A[192+l_m] * B[2];
    C[24+l_m] += A[144+l_m] * B[3];
    C[24+l_m] += A[168+l_m] * B[4];
    C[24+l_m] += A[192+l_m] * B[5];
    C[48+l_m] += A[144+l_m] * B[6];
    C[48+l_m] += A[168+l_m] * B[7];
    C[48+l_m] += A[192+l_m] * B[8];
    C[72+l_m] += A[144+l_m] * B[9];
    C[72+l_m] += A[168+l_m] * B[10];
    C[96+l_m] += A[168+l_m] * B[11];
    C[96+l_m] += A[192+l_m] * B[12];
    C[120+l_m] += A[144+l_m] * B[13];
    C[120+l_m] += A[192+l_m] * B[14];
    C[144+l_m] += A[0+l_m] * B[15];
    C[144+l_m] += A[72+l_m] * B[16];
    C[144+l_m] += A[120+l_m] * B[17];
    C[168+l_m] += A[24+l_m] * B[18];
    C[168+l_m] += A[72+l_m] * B[19];
    C[168+l_m] += A[96+l_m] * B[20];
    C[192+l_m] += A[48+l_m] * B[21];
    C[192+l_m] += A[96+l_m] * B[22];
    C[192+l_m] += A[120+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 960;
#endif
}

void dsparse_starMatrix_m35_n9_k9_ldA40_ldBna5_ldC40_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 35; l_m++) {
    C[0+l_m] += A[240+l_m] * B[0];
    C[0+l_m] += A[280+l_m] * B[1];
    C[0+l_m] += A[320+l_m] * B[2];
    C[40+l_m] += A[240+l_m] * B[3];
    C[40+l_m] += A[280+l_m] * B[4];
    C[40+l_m] += A[320+l_m] * B[5];
    C[80+l_m] += A[240+l_m] * B[6];
    C[80+l_m] += A[280+l_m] * B[7];
    C[80+l_m] += A[320+l_m] * B[8];
    C[120+l_m] += A[240+l_m] * B[9];
    C[120+l_m] += A[280+l_m] * B[10];
    C[160+l_m] += A[280+l_m] * B[11];
    C[160+l_m] += A[320+l_m] * B[12];
    C[200+l_m] += A[240+l_m] * B[13];
    C[200+l_m] += A[320+l_m] * B[14];
    C[240+l_m] += A[0+l_m] * B[15];
    C[240+l_m] += A[120+l_m] * B[16];
    C[240+l_m] += A[200+l_m] * B[17];
    C[280+l_m] += A[40+l_m] * B[18];
    C[280+l_m] += A[120+l_m] * B[19];
    C[280+l_m] += A[160+l_m] * B[20];
    C[320+l_m] += A[80+l_m] * B[21];
    C[320+l_m] += A[160+l_m] * B[22];
    C[320+l_m] += A[200+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 1680;
#endif
}

void dsparse_starMatrix_m56_n9_k9_ldA56_ldBna6_ldC56_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 56; l_m++) {
    C[0+l_m] += A[336+l_m] * B[0];
    C[0+l_m] += A[392+l_m] * B[1];
    C[0+l_m] += A[448+l_m] * B[2];
    C[56+l_m] += A[336+l_m] * B[3];
    C[56+l_m] += A[392+l_m] * B[4];
    C[56+l_m] += A[448+l_m] * B[5];
    C[112+l_m] += A[336+l_m] * B[6];
    C[112+l_m] += A[392+l_m] * B[7];
    C[112+l_m] += A[448+l_m] * B[8];
    C[168+l_m] += A[336+l_m] * B[9];
    C[168+l_m] += A[392+l_m] * B[10];
    C[224+l_m] += A[392+l_m] * B[11];
    C[224+l_m] += A[448+l_m] * B[12];
    C[280+l_m] += A[336+l_m] * B[13];
    C[280+l_m] += A[448+l_m] * B[14];
    C[336+l_m] += A[0+l_m] * B[15];
    C[336+l_m] += A[168+l_m] * B[16];
    C[336+l_m] += A[280+l_m] * B[17];
    C[392+l_m] += A[56+l_m] * B[18];
    C[392+l_m] += A[168+l_m] * B[19];
    C[392+l_m] += A[224+l_m] * B[20];
    C[448+l_m] += A[112+l_m] * B[21];
    C[448+l_m] += A[224+l_m] * B[22];
    C[448+l_m] += A[280+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 2688;
#endif
}

void dsparse_fP113DivM_m56_n9_k56_ldAna6_ldB56_ldC56_beta0_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_n = 0;
  #pragma nounroll_and_jam
  for ( l_n = 0; l_n < 9; l_n++) {
    unsigned int l_m = 0;
   #pragma simd
    for ( l_m = 0; l_m < 56; l_m++) {
      C[(l_n*56)+l_m] = 0.0;
    }
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b0 = _mm256_broadcast_sd(&B[(l_n*56)+0]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b0 = _mm_loaddup_pd(&B[(l_n*56)+0]);
#endif
    __m128d c0_0 = _mm_load_sd(&C[(l_n*56)+0]);
    __m128d a0_0 = _mm_load_sd(&A[0]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_0 = _mm_add_sd(c0_0, _mm_mul_sd(a0_0, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_0 = _mm_add_sd(c0_0, _mm_mul_sd(a0_0, b0));
#endif
    _mm_store_sd(&C[(l_n*56)+0], c0_0);
    __m128d c0_1 = _mm_load_sd(&C[(l_n*56)+3]);
    __m128d a0_1 = _mm_load_sd(&A[1]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_1 = _mm_add_sd(c0_1, _mm_mul_sd(a0_1, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_1 = _mm_add_sd(c0_1, _mm_mul_sd(a0_1, b0));
#endif
    _mm_store_sd(&C[(l_n*56)+3], c0_1);
    __m128d c0_2 = _mm_load_sd(&C[(l_n*56)+9]);
    __m128d a0_2 = _mm_load_sd(&A[2]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_2 = _mm_add_sd(c0_2, _mm_mul_sd(a0_2, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_2 = _mm_add_sd(c0_2, _mm_mul_sd(a0_2, b0));
#endif
    _mm_store_sd(&C[(l_n*56)+9], c0_2);
    __m128d c0_3 = _mm_load_sd(&C[(l_n*56)+19]);
    __m128d a0_3 = _mm_load_sd(&A[3]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_3 = _mm_add_sd(c0_3, _mm_mul_sd(a0_3, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_3 = _mm_add_sd(c0_3, _mm_mul_sd(a0_3, b0));
#endif
    _mm_store_sd(&C[(l_n*56)+19], c0_3);
    __m128d c0_4 = _mm_load_sd(&C[(l_n*56)+34]);
    __m128d a0_4 = _mm_load_sd(&A[4]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_4 = _mm_add_sd(c0_4, _mm_mul_sd(a0_4, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_4 = _mm_add_sd(c0_4, _mm_mul_sd(a0_4, b0));
#endif
    _mm_store_sd(&C[(l_n*56)+34], c0_4);
    __m128d c0_5 = _mm_load_sd(&C[(l_n*56)+55]);
    __m128d a0_5 = _mm_load_sd(&A[5]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_5 = _mm_add_sd(c0_5, _mm_mul_sd(a0_5, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_5 = _mm_add_sd(c0_5, _mm_mul_sd(a0_5, b0));
#endif
    _mm_store_sd(&C[(l_n*56)+55], c0_5);
#else
    C[(l_n*56)+0] += A[0] * B[(l_n*56)+0];
    C[(l_n*56)+3] += A[1] * B[(l_n*56)+0];
    C[(l_n*56)+9] += A[2] * B[(l_n*56)+0];
    C[(l_n*56)+19] += A[3] * B[(l_n*56)+0];
    C[(l_n*56)+34] += A[4] * B[(l_n*56)+0];
    C[(l_n*56)+55] += A[5] * B[(l_n*56)+0];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b1 = _mm256_broadcast_sd(&B[(l_n*56)+1]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b1 = _mm_loaddup_pd(&B[(l_n*56)+1]);
#endif
    __m128d c1_0 = _mm_load_sd(&C[(l_n*56)+1]);
    __m128d a1_0 = _mm_load_sd(&A[6]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_0 = _mm_add_sd(c1_0, _mm_mul_sd(a1_0, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_0 = _mm_add_sd(c1_0, _mm_mul_sd(a1_0, b1));
#endif
    _mm_store_sd(&C[(l_n*56)+1], c1_0);
    __m128d c1_1 = _mm_load_sd(&C[(l_n*56)+7]);
    __m128d a1_1 = _mm_load_sd(&A[7]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_1 = _mm_add_sd(c1_1, _mm_mul_sd(a1_1, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_1 = _mm_add_sd(c1_1, _mm_mul_sd(a1_1, b1));
#endif
    _mm_store_sd(&C[(l_n*56)+7], c1_1);
    __m128d c1_2 = _mm_load_sd(&C[(l_n*56)+17]);
    __m128d a1_2 = _mm_load_sd(&A[8]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_2 = _mm_add_sd(c1_2, _mm_mul_sd(a1_2, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_2 = _mm_add_sd(c1_2, _mm_mul_sd(a1_2, b1));
#endif
    _mm_store_sd(&C[(l_n*56)+17], c1_2);
    __m128d c1_3 = _mm_load_sd(&C[(l_n*56)+32]);
    __m128d a1_3 = _mm_load_sd(&A[9]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_3 = _mm_add_sd(c1_3, _mm_mul_sd(a1_3, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_3 = _mm_add_sd(c1_3, _mm_mul_sd(a1_3, b1));
#endif
    _mm_store_sd(&C[(l_n*56)+32], c1_3);
    __m128d c1_4 = _mm_load_sd(&C[(l_n*56)+53]);
    __m128d a1_4 = _mm_load_sd(&A[10]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_4 = _mm_add_sd(c1_4, _mm_mul_sd(a1_4, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_4 = _mm_add_sd(c1_4, _mm_mul_sd(a1_4, b1));
#endif
    _mm_store_sd(&C[(l_n*56)+53], c1_4);
#else
    C[(l_n*56)+1] += A[6] * B[(l_n*56)+1];
    C[(l_n*56)+7] += A[7] * B[(l_n*56)+1];
    C[(l_n*56)+17] += A[8] * B[(l_n*56)+1];
    C[(l_n*56)+32] += A[9] * B[(l_n*56)+1];
    C[(l_n*56)+53] += A[10] * B[(l_n*56)+1];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b2 = _mm256_broadcast_sd(&B[(l_n*56)+2]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b2 = _mm_loaddup_pd(&B[(l_n*56)+2]);
#endif
    __m128d c2_0 = _mm_load_sd(&C[(l_n*56)+2]);
    __m128d a2_0 = _mm_load_sd(&A[11]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_0 = _mm_add_sd(c2_0, _mm_mul_sd(a2_0, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_0 = _mm_add_sd(c2_0, _mm_mul_sd(a2_0, b2));
#endif
    _mm_store_sd(&C[(l_n*56)+2], c2_0);
    __m128d c2_1 = _mm_load_sd(&C[(l_n*56)+8]);
    __m128d a2_1 = _mm_load_sd(&A[12]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_1 = _mm_add_sd(c2_1, _mm_mul_sd(a2_1, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_1 = _mm_add_sd(c2_1, _mm_mul_sd(a2_1, b2));
#endif
    _mm_store_sd(&C[(l_n*56)+8], c2_1);
    __m128d c2_2 = _mm_load_sd(&C[(l_n*56)+18]);
    __m128d a2_2 = _mm_load_sd(&A[13]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_2 = _mm_add_sd(c2_2, _mm_mul_sd(a2_2, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_2 = _mm_add_sd(c2_2, _mm_mul_sd(a2_2, b2));
#endif
    _mm_store_sd(&C[(l_n*56)+18], c2_2);
    __m128d c2_3 = _mm_load_sd(&C[(l_n*56)+33]);
    __m128d a2_3 = _mm_load_sd(&A[14]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_3 = _mm_add_sd(c2_3, _mm_mul_sd(a2_3, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_3 = _mm_add_sd(c2_3, _mm_mul_sd(a2_3, b2));
#endif
    _mm_store_sd(&C[(l_n*56)+33], c2_3);
    __m128d c2_4 = _mm_load_sd(&C[(l_n*56)+54]);
    __m128d a2_4 = _mm_load_sd(&A[15]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_4 = _mm_add_sd(c2_4, _mm_mul_sd(a2_4, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_4 = _mm_add_sd(c2_4, _mm_mul_sd(a2_4, b2));
#endif
    _mm_store_sd(&C[(l_n*56)+54], c2_4);
#else
    C[(l_n*56)+2] += A[11] * B[(l_n*56)+2];
    C[(l_n*56)+8] += A[12] * B[(l_n*56)+2];
    C[(l_n*56)+18] += A[13] * B[(l_n*56)+2];
    C[(l_n*56)+33] += A[14] * B[(l_n*56)+2];
    C[(l_n*56)+54] += A[15] * B[(l_n*56)+2];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b3 = _mm256_broadcast_sd(&B[(l_n*56)+3]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b3 = _mm_loaddup_pd(&B[(l_n*56)+3]);
#endif
    __m128d c3_0 = _mm_load_sd(&C[(l_n*56)+0]);
    __m128d a3_0 = _mm_load_sd(&A[16]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_0 = _mm_add_sd(c3_0, _mm_mul_sd(a3_0, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_0 = _mm_add_sd(c3_0, _mm_mul_sd(a3_0, b3));
#endif
    _mm_store_sd(&C[(l_n*56)+0], c3_0);
    __m128d c3_1 = _mm_load_sd(&C[(l_n*56)+3]);
    __m128d a3_1 = _mm_load_sd(&A[17]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_1 = _mm_add_sd(c3_1, _mm_mul_sd(a3_1, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_1 = _mm_add_sd(c3_1, _mm_mul_sd(a3_1, b3));
#endif
    _mm_store_sd(&C[(l_n*56)+3], c3_1);
    __m128d c3_2 = _mm_load_sd(&C[(l_n*56)+9]);
    __m128d a3_2 = _mm_load_sd(&A[18]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_2 = _mm_add_sd(c3_2, _mm_mul_sd(a3_2, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_2 = _mm_add_sd(c3_2, _mm_mul_sd(a3_2, b3));
#endif
    _mm_store_sd(&C[(l_n*56)+9], c3_2);
    __m128d c3_3 = _mm_load_sd(&C[(l_n*56)+19]);
    __m128d a3_3 = _mm_load_sd(&A[19]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_3 = _mm_add_sd(c3_3, _mm_mul_sd(a3_3, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_3 = _mm_add_sd(c3_3, _mm_mul_sd(a3_3, b3));
#endif
    _mm_store_sd(&C[(l_n*56)+19], c3_3);
    __m128d c3_4 = _mm_load_sd(&C[(l_n*56)+34]);
    __m128d a3_4 = _mm_load_sd(&A[20]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_4 = _mm_add_sd(c3_4, _mm_mul_sd(a3_4, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_4 = _mm_add_sd(c3_4, _mm_mul_sd(a3_4, b3));
#endif
    _mm_store_sd(&C[(l_n*56)+34], c3_4);
    __m128d c3_5 = _mm_load_sd(&C[(l_n*56)+55]);
    __m128d a3_5 = _mm_load_sd(&A[21]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_5 = _mm_add_sd(c3_5, _mm_mul_sd(a3_5, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_5 = _mm_add_sd(c3_5, _mm_mul_sd(a3_5, b3));
#endif
    _mm_store_sd(&C[(l_n*56)+55], c3_5);
#else
    C[(l_n*56)+0] += A[16] * B[(l_n*56)+3];
    C[(l_n*56)+3] += A[17] * B[(l_n*56)+3];
    C[(l_n*56)+9] += A[18] * B[(l_n*56)+3];
    C[(l_n*56)+19] += A[19] * B[(l_n*56)+3];
    C[(l_n*56)+34] += A[20] * B[(l_n*56)+3];
    C[(l_n*56)+55] += A[21] * B[(l_n*56)+3];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b4 = _mm256_broadcast_sd(&B[(l_n*56)+4]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b4 = _mm_loaddup_pd(&B[(l_n*56)+4]);
#endif
    __m128d c4_0 = _mm_load_sd(&C[(l_n*56)+4]);
    __m128d a4_0 = _mm_load_sd(&A[22]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_0 = _mm_add_sd(c4_0, _mm_mul_sd(a4_0, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_0 = _mm_add_sd(c4_0, _mm_mul_sd(a4_0, b4));
#endif
    _mm_store_sd(&C[(l_n*56)+4], c4_0);
    __m128d c4_1 = _mm_load_sd(&C[(l_n*56)+14]);
    __m128d a4_1 = _mm_load_sd(&A[23]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_1 = _mm_add_sd(c4_1, _mm_mul_sd(a4_1, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_1 = _mm_add_sd(c4_1, _mm_mul_sd(a4_1, b4));
#endif
    _mm_store_sd(&C[(l_n*56)+14], c4_1);
    __m128d c4_2 = _mm_load_sd(&C[(l_n*56)+29]);
    __m128d a4_2 = _mm_load_sd(&A[24]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_2 = _mm_add_sd(c4_2, _mm_mul_sd(a4_2, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_2 = _mm_add_sd(c4_2, _mm_mul_sd(a4_2, b4));
#endif
    _mm_store_sd(&C[(l_n*56)+29], c4_2);
    __m128d c4_3 = _mm_load_sd(&C[(l_n*56)+50]);
    __m128d a4_3 = _mm_load_sd(&A[25]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_3 = _mm_add_sd(c4_3, _mm_mul_sd(a4_3, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_3 = _mm_add_sd(c4_3, _mm_mul_sd(a4_3, b4));
#endif
    _mm_store_sd(&C[(l_n*56)+50], c4_3);
#else
    C[(l_n*56)+4] += A[22] * B[(l_n*56)+4];
    C[(l_n*56)+14] += A[23] * B[(l_n*56)+4];
    C[(l_n*56)+29] += A[24] * B[(l_n*56)+4];
    C[(l_n*56)+50] += A[25] * B[(l_n*56)+4];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b5 = _mm256_broadcast_sd(&B[(l_n*56)+5]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b5 = _mm_loaddup_pd(&B[(l_n*56)+5]);
#endif
    __m128d c5_0 = _mm_load_sd(&C[(l_n*56)+5]);
    __m128d a5_0 = _mm_load_sd(&A[26]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_0 = _mm_add_sd(c5_0, _mm_mul_sd(a5_0, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_0 = _mm_add_sd(c5_0, _mm_mul_sd(a5_0, b5));
#endif
    _mm_store_sd(&C[(l_n*56)+5], c5_0);
    __m128d c5_1 = _mm_load_sd(&C[(l_n*56)+15]);
    __m128d a5_1 = _mm_load_sd(&A[27]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_1 = _mm_add_sd(c5_1, _mm_mul_sd(a5_1, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_1 = _mm_add_sd(c5_1, _mm_mul_sd(a5_1, b5));
#endif
    _mm_store_sd(&C[(l_n*56)+15], c5_1);
    __m128d c5_2 = _mm_load_sd(&C[(l_n*56)+30]);
    __m128d a5_2 = _mm_load_sd(&A[28]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_2 = _mm_add_sd(c5_2, _mm_mul_sd(a5_2, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_2 = _mm_add_sd(c5_2, _mm_mul_sd(a5_2, b5));
#endif
    _mm_store_sd(&C[(l_n*56)+30], c5_2);
    __m128d c5_3 = _mm_load_sd(&C[(l_n*56)+51]);
    __m128d a5_3 = _mm_load_sd(&A[29]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_3 = _mm_add_sd(c5_3, _mm_mul_sd(a5_3, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_3 = _mm_add_sd(c5_3, _mm_mul_sd(a5_3, b5));
#endif
    _mm_store_sd(&C[(l_n*56)+51], c5_3);
#else
    C[(l_n*56)+5] += A[26] * B[(l_n*56)+5];
    C[(l_n*56)+15] += A[27] * B[(l_n*56)+5];
    C[(l_n*56)+30] += A[28] * B[(l_n*56)+5];
    C[(l_n*56)+51] += A[29] * B[(l_n*56)+5];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b6 = _mm256_broadcast_sd(&B[(l_n*56)+6]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b6 = _mm_loaddup_pd(&B[(l_n*56)+6]);
#endif
    __m128d c6_0 = _mm_load_sd(&C[(l_n*56)+6]);
    __m128d a6_0 = _mm_load_sd(&A[30]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_0 = _mm_add_sd(c6_0, _mm_mul_sd(a6_0, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_0 = _mm_add_sd(c6_0, _mm_mul_sd(a6_0, b6));
#endif
    _mm_store_sd(&C[(l_n*56)+6], c6_0);
    __m128d c6_1 = _mm_load_sd(&C[(l_n*56)+16]);
    __m128d a6_1 = _mm_load_sd(&A[31]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_1 = _mm_add_sd(c6_1, _mm_mul_sd(a6_1, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_1 = _mm_add_sd(c6_1, _mm_mul_sd(a6_1, b6));
#endif
    _mm_store_sd(&C[(l_n*56)+16], c6_1);
    __m128d c6_2 = _mm_load_sd(&C[(l_n*56)+31]);
    __m128d a6_2 = _mm_load_sd(&A[32]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_2 = _mm_add_sd(c6_2, _mm_mul_sd(a6_2, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_2 = _mm_add_sd(c6_2, _mm_mul_sd(a6_2, b6));
#endif
    _mm_store_sd(&C[(l_n*56)+31], c6_2);
    __m128d c6_3 = _mm_load_sd(&C[(l_n*56)+52]);
    __m128d a6_3 = _mm_load_sd(&A[33]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_3 = _mm_add_sd(c6_3, _mm_mul_sd(a6_3, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_3 = _mm_add_sd(c6_3, _mm_mul_sd(a6_3, b6));
#endif
    _mm_store_sd(&C[(l_n*56)+52], c6_3);
#else
    C[(l_n*56)+6] += A[30] * B[(l_n*56)+6];
    C[(l_n*56)+16] += A[31] * B[(l_n*56)+6];
    C[(l_n*56)+31] += A[32] * B[(l_n*56)+6];
    C[(l_n*56)+52] += A[33] * B[(l_n*56)+6];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b7 = _mm256_broadcast_sd(&B[(l_n*56)+7]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b7 = _mm_loaddup_pd(&B[(l_n*56)+7]);
#endif
    __m128d c7_0 = _mm_load_sd(&C[(l_n*56)+1]);
    __m128d a7_0 = _mm_load_sd(&A[34]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_0 = _mm_add_sd(c7_0, _mm_mul_sd(a7_0, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_0 = _mm_add_sd(c7_0, _mm_mul_sd(a7_0, b7));
#endif
    _mm_store_sd(&C[(l_n*56)+1], c7_0);
    __m128d c7_1 = _mm_load_sd(&C[(l_n*56)+7]);
    __m128d a7_1 = _mm_load_sd(&A[35]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_1 = _mm_add_sd(c7_1, _mm_mul_sd(a7_1, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_1 = _mm_add_sd(c7_1, _mm_mul_sd(a7_1, b7));
#endif
    _mm_store_sd(&C[(l_n*56)+7], c7_1);
    __m128d c7_2 = _mm_load_sd(&C[(l_n*56)+17]);
    __m128d a7_2 = _mm_load_sd(&A[36]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_2 = _mm_add_sd(c7_2, _mm_mul_sd(a7_2, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_2 = _mm_add_sd(c7_2, _mm_mul_sd(a7_2, b7));
#endif
    _mm_store_sd(&C[(l_n*56)+17], c7_2);
    __m128d c7_3 = _mm_load_sd(&C[(l_n*56)+32]);
    __m128d a7_3 = _mm_load_sd(&A[37]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_3 = _mm_add_sd(c7_3, _mm_mul_sd(a7_3, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_3 = _mm_add_sd(c7_3, _mm_mul_sd(a7_3, b7));
#endif
    _mm_store_sd(&C[(l_n*56)+32], c7_3);
    __m128d c7_4 = _mm_load_sd(&C[(l_n*56)+53]);
    __m128d a7_4 = _mm_load_sd(&A[38]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_4 = _mm_add_sd(c7_4, _mm_mul_sd(a7_4, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_4 = _mm_add_sd(c7_4, _mm_mul_sd(a7_4, b7));
#endif
    _mm_store_sd(&C[(l_n*56)+53], c7_4);
#else
    C[(l_n*56)+1] += A[34] * B[(l_n*56)+7];
    C[(l_n*56)+7] += A[35] * B[(l_n*56)+7];
    C[(l_n*56)+17] += A[36] * B[(l_n*56)+7];
    C[(l_n*56)+32] += A[37] * B[(l_n*56)+7];
    C[(l_n*56)+53] += A[38] * B[(l_n*56)+7];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b8 = _mm256_broadcast_sd(&B[(l_n*56)+8]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b8 = _mm_loaddup_pd(&B[(l_n*56)+8]);
#endif
    __m128d c8_0 = _mm_load_sd(&C[(l_n*56)+2]);
    __m128d a8_0 = _mm_load_sd(&A[39]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_0 = _mm_add_sd(c8_0, _mm_mul_sd(a8_0, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_0 = _mm_add_sd(c8_0, _mm_mul_sd(a8_0, b8));
#endif
    _mm_store_sd(&C[(l_n*56)+2], c8_0);
    __m128d c8_1 = _mm_load_sd(&C[(l_n*56)+8]);
    __m128d a8_1 = _mm_load_sd(&A[40]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_1 = _mm_add_sd(c8_1, _mm_mul_sd(a8_1, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_1 = _mm_add_sd(c8_1, _mm_mul_sd(a8_1, b8));
#endif
    _mm_store_sd(&C[(l_n*56)+8], c8_1);
    __m128d c8_2 = _mm_load_sd(&C[(l_n*56)+18]);
    __m128d a8_2 = _mm_load_sd(&A[41]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_2 = _mm_add_sd(c8_2, _mm_mul_sd(a8_2, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_2 = _mm_add_sd(c8_2, _mm_mul_sd(a8_2, b8));
#endif
    _mm_store_sd(&C[(l_n*56)+18], c8_2);
    __m128d c8_3 = _mm_load_sd(&C[(l_n*56)+33]);
    __m128d a8_3 = _mm_load_sd(&A[42]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_3 = _mm_add_sd(c8_3, _mm_mul_sd(a8_3, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_3 = _mm_add_sd(c8_3, _mm_mul_sd(a8_3, b8));
#endif
    _mm_store_sd(&C[(l_n*56)+33], c8_3);
    __m128d c8_4 = _mm_load_sd(&C[(l_n*56)+54]);
    __m128d a8_4 = _mm_load_sd(&A[43]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_4 = _mm_add_sd(c8_4, _mm_mul_sd(a8_4, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_4 = _mm_add_sd(c8_4, _mm_mul_sd(a8_4, b8));
#endif
    _mm_store_sd(&C[(l_n*56)+54], c8_4);
#else
    C[(l_n*56)+2] += A[39] * B[(l_n*56)+8];
    C[(l_n*56)+8] += A[40] * B[(l_n*56)+8];
    C[(l_n*56)+18] += A[41] * B[(l_n*56)+8];
    C[(l_n*56)+33] += A[42] * B[(l_n*56)+8];
    C[(l_n*56)+54] += A[43] * B[(l_n*56)+8];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b9 = _mm256_broadcast_sd(&B[(l_n*56)+9]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b9 = _mm_loaddup_pd(&B[(l_n*56)+9]);
#endif
    __m128d c9_0 = _mm_load_sd(&C[(l_n*56)+0]);
    __m128d a9_0 = _mm_load_sd(&A[44]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_0 = _mm_add_sd(c9_0, _mm_mul_sd(a9_0, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_0 = _mm_add_sd(c9_0, _mm_mul_sd(a9_0, b9));
#endif
    _mm_store_sd(&C[(l_n*56)+0], c9_0);
    __m128d c9_1 = _mm_load_sd(&C[(l_n*56)+3]);
    __m128d a9_1 = _mm_load_sd(&A[45]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_1 = _mm_add_sd(c9_1, _mm_mul_sd(a9_1, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_1 = _mm_add_sd(c9_1, _mm_mul_sd(a9_1, b9));
#endif
    _mm_store_sd(&C[(l_n*56)+3], c9_1);
    __m128d c9_2 = _mm_load_sd(&C[(l_n*56)+9]);
    __m128d a9_2 = _mm_load_sd(&A[46]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_2 = _mm_add_sd(c9_2, _mm_mul_sd(a9_2, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_2 = _mm_add_sd(c9_2, _mm_mul_sd(a9_2, b9));
#endif
    _mm_store_sd(&C[(l_n*56)+9], c9_2);
    __m128d c9_3 = _mm_load_sd(&C[(l_n*56)+19]);
    __m128d a9_3 = _mm_load_sd(&A[47]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_3 = _mm_add_sd(c9_3, _mm_mul_sd(a9_3, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_3 = _mm_add_sd(c9_3, _mm_mul_sd(a9_3, b9));
#endif
    _mm_store_sd(&C[(l_n*56)+19], c9_3);
    __m128d c9_4 = _mm_load_sd(&C[(l_n*56)+34]);
    __m128d a9_4 = _mm_load_sd(&A[48]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_4 = _mm_add_sd(c9_4, _mm_mul_sd(a9_4, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_4 = _mm_add_sd(c9_4, _mm_mul_sd(a9_4, b9));
#endif
    _mm_store_sd(&C[(l_n*56)+34], c9_4);
    __m128d c9_5 = _mm_load_sd(&C[(l_n*56)+55]);
    __m128d a9_5 = _mm_load_sd(&A[49]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_5 = _mm_add_sd(c9_5, _mm_mul_sd(a9_5, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_5 = _mm_add_sd(c9_5, _mm_mul_sd(a9_5, b9));
#endif
    _mm_store_sd(&C[(l_n*56)+55], c9_5);
#else
    C[(l_n*56)+0] += A[44] * B[(l_n*56)+9];
    C[(l_n*56)+3] += A[45] * B[(l_n*56)+9];
    C[(l_n*56)+9] += A[46] * B[(l_n*56)+9];
    C[(l_n*56)+19] += A[47] * B[(l_n*56)+9];
    C[(l_n*56)+34] += A[48] * B[(l_n*56)+9];
    C[(l_n*56)+55] += A[49] * B[(l_n*56)+9];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b10 = _mm256_broadcast_sd(&B[(l_n*56)+10]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b10 = _mm_loaddup_pd(&B[(l_n*56)+10]);
#endif
    __m128d c10_0 = _mm_load_sd(&C[(l_n*56)+10]);
    __m128d a10_0 = _mm_load_sd(&A[50]);
#if defined(__SSE3__) && defined(__AVX__)
    c10_0 = _mm_add_sd(c10_0, _mm_mul_sd(a10_0, _mm256_castpd256_pd128(b10)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c10_0 = _mm_add_sd(c10_0, _mm_mul_sd(a10_0, b10));
#endif
    _mm_store_sd(&C[(l_n*56)+10], c10_0);
    __m128d c10_1 = _mm_load_sd(&C[(l_n*56)+25]);
    __m128d a10_1 = _mm_load_sd(&A[51]);
#if defined(__SSE3__) && defined(__AVX__)
    c10_1 = _mm_add_sd(c10_1, _mm_mul_sd(a10_1, _mm256_castpd256_pd128(b10)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c10_1 = _mm_add_sd(c10_1, _mm_mul_sd(a10_1, b10));
#endif
    _mm_store_sd(&C[(l_n*56)+25], c10_1);
    __m128d c10_2 = _mm_load_sd(&C[(l_n*56)+46]);
    __m128d a10_2 = _mm_load_sd(&A[52]);
#if defined(__SSE3__) && defined(__AVX__)
    c10_2 = _mm_add_sd(c10_2, _mm_mul_sd(a10_2, _mm256_castpd256_pd128(b10)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c10_2 = _mm_add_sd(c10_2, _mm_mul_sd(a10_2, b10));
#endif
    _mm_store_sd(&C[(l_n*56)+46], c10_2);
#else
    C[(l_n*56)+10] += A[50] * B[(l_n*56)+10];
    C[(l_n*56)+25] += A[51] * B[(l_n*56)+10];
    C[(l_n*56)+46] += A[52] * B[(l_n*56)+10];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b11 = _mm256_broadcast_sd(&B[(l_n*56)+11]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b11 = _mm_loaddup_pd(&B[(l_n*56)+11]);
#endif
    __m128d c11_0 = _mm_load_sd(&C[(l_n*56)+11]);
    __m128d a11_0 = _mm_load_sd(&A[53]);
#if defined(__SSE3__) && defined(__AVX__)
    c11_0 = _mm_add_sd(c11_0, _mm_mul_sd(a11_0, _mm256_castpd256_pd128(b11)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c11_0 = _mm_add_sd(c11_0, _mm_mul_sd(a11_0, b11));
#endif
    _mm_store_sd(&C[(l_n*56)+11], c11_0);
    __m128d c11_1 = _mm_load_sd(&C[(l_n*56)+26]);
    __m128d a11_1 = _mm_load_sd(&A[54]);
#if defined(__SSE3__) && defined(__AVX__)
    c11_1 = _mm_add_sd(c11_1, _mm_mul_sd(a11_1, _mm256_castpd256_pd128(b11)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c11_1 = _mm_add_sd(c11_1, _mm_mul_sd(a11_1, b11));
#endif
    _mm_store_sd(&C[(l_n*56)+26], c11_1);
    __m128d c11_2 = _mm_load_sd(&C[(l_n*56)+47]);
    __m128d a11_2 = _mm_load_sd(&A[55]);
#if defined(__SSE3__) && defined(__AVX__)
    c11_2 = _mm_add_sd(c11_2, _mm_mul_sd(a11_2, _mm256_castpd256_pd128(b11)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c11_2 = _mm_add_sd(c11_2, _mm_mul_sd(a11_2, b11));
#endif
    _mm_store_sd(&C[(l_n*56)+47], c11_2);
#else
    C[(l_n*56)+11] += A[53] * B[(l_n*56)+11];
    C[(l_n*56)+26] += A[54] * B[(l_n*56)+11];
    C[(l_n*56)+47] += A[55] * B[(l_n*56)+11];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b12 = _mm256_broadcast_sd(&B[(l_n*56)+12]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b12 = _mm_loaddup_pd(&B[(l_n*56)+12]);
#endif
    __m128d c12_0 = _mm_load_sd(&C[(l_n*56)+12]);
    __m128d a12_0 = _mm_load_sd(&A[56]);
#if defined(__SSE3__) && defined(__AVX__)
    c12_0 = _mm_add_sd(c12_0, _mm_mul_sd(a12_0, _mm256_castpd256_pd128(b12)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c12_0 = _mm_add_sd(c12_0, _mm_mul_sd(a12_0, b12));
#endif
    _mm_store_sd(&C[(l_n*56)+12], c12_0);
    __m128d c12_1 = _mm_load_sd(&C[(l_n*56)+27]);
    __m128d a12_1 = _mm_load_sd(&A[57]);
#if defined(__SSE3__) && defined(__AVX__)
    c12_1 = _mm_add_sd(c12_1, _mm_mul_sd(a12_1, _mm256_castpd256_pd128(b12)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c12_1 = _mm_add_sd(c12_1, _mm_mul_sd(a12_1, b12));
#endif
    _mm_store_sd(&C[(l_n*56)+27], c12_1);
    __m128d c12_2 = _mm_load_sd(&C[(l_n*56)+48]);
    __m128d a12_2 = _mm_load_sd(&A[58]);
#if defined(__SSE3__) && defined(__AVX__)
    c12_2 = _mm_add_sd(c12_2, _mm_mul_sd(a12_2, _mm256_castpd256_pd128(b12)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c12_2 = _mm_add_sd(c12_2, _mm_mul_sd(a12_2, b12));
#endif
    _mm_store_sd(&C[(l_n*56)+48], c12_2);
#else
    C[(l_n*56)+12] += A[56] * B[(l_n*56)+12];
    C[(l_n*56)+27] += A[57] * B[(l_n*56)+12];
    C[(l_n*56)+48] += A[58] * B[(l_n*56)+12];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b13 = _mm256_broadcast_sd(&B[(l_n*56)+13]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b13 = _mm_loaddup_pd(&B[(l_n*56)+13]);
#endif
    __m128d c13_0 = _mm_load_sd(&C[(l_n*56)+13]);
    __m128d a13_0 = _mm_load_sd(&A[59]);
#if defined(__SSE3__) && defined(__AVX__)
    c13_0 = _mm_add_sd(c13_0, _mm_mul_sd(a13_0, _mm256_castpd256_pd128(b13)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c13_0 = _mm_add_sd(c13_0, _mm_mul_sd(a13_0, b13));
#endif
    _mm_store_sd(&C[(l_n*56)+13], c13_0);
    __m128d c13_1 = _mm_load_sd(&C[(l_n*56)+28]);
    __m128d a13_1 = _mm_load_sd(&A[60]);
#if defined(__SSE3__) && defined(__AVX__)
    c13_1 = _mm_add_sd(c13_1, _mm_mul_sd(a13_1, _mm256_castpd256_pd128(b13)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c13_1 = _mm_add_sd(c13_1, _mm_mul_sd(a13_1, b13));
#endif
    _mm_store_sd(&C[(l_n*56)+28], c13_1);
    __m128d c13_2 = _mm_load_sd(&C[(l_n*56)+49]);
    __m128d a13_2 = _mm_load_sd(&A[61]);
#if defined(__SSE3__) && defined(__AVX__)
    c13_2 = _mm_add_sd(c13_2, _mm_mul_sd(a13_2, _mm256_castpd256_pd128(b13)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c13_2 = _mm_add_sd(c13_2, _mm_mul_sd(a13_2, b13));
#endif
    _mm_store_sd(&C[(l_n*56)+49], c13_2);
#else
    C[(l_n*56)+13] += A[59] * B[(l_n*56)+13];
    C[(l_n*56)+28] += A[60] * B[(l_n*56)+13];
    C[(l_n*56)+49] += A[61] * B[(l_n*56)+13];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b14 = _mm256_broadcast_sd(&B[(l_n*56)+14]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b14 = _mm_loaddup_pd(&B[(l_n*56)+14]);
#endif
    __m128d c14_0 = _mm_load_sd(&C[(l_n*56)+4]);
    __m128d a14_0 = _mm_load_sd(&A[62]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_0 = _mm_add_sd(c14_0, _mm_mul_sd(a14_0, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_0 = _mm_add_sd(c14_0, _mm_mul_sd(a14_0, b14));
#endif
    _mm_store_sd(&C[(l_n*56)+4], c14_0);
    __m128d c14_1 = _mm_load_sd(&C[(l_n*56)+14]);
    __m128d a14_1 = _mm_load_sd(&A[63]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_1 = _mm_add_sd(c14_1, _mm_mul_sd(a14_1, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_1 = _mm_add_sd(c14_1, _mm_mul_sd(a14_1, b14));
#endif
    _mm_store_sd(&C[(l_n*56)+14], c14_1);
    __m128d c14_2 = _mm_load_sd(&C[(l_n*56)+29]);
    __m128d a14_2 = _mm_load_sd(&A[64]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_2 = _mm_add_sd(c14_2, _mm_mul_sd(a14_2, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_2 = _mm_add_sd(c14_2, _mm_mul_sd(a14_2, b14));
#endif
    _mm_store_sd(&C[(l_n*56)+29], c14_2);
    __m128d c14_3 = _mm_load_sd(&C[(l_n*56)+50]);
    __m128d a14_3 = _mm_load_sd(&A[65]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_3 = _mm_add_sd(c14_3, _mm_mul_sd(a14_3, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_3 = _mm_add_sd(c14_3, _mm_mul_sd(a14_3, b14));
#endif
    _mm_store_sd(&C[(l_n*56)+50], c14_3);
#else
    C[(l_n*56)+4] += A[62] * B[(l_n*56)+14];
    C[(l_n*56)+14] += A[63] * B[(l_n*56)+14];
    C[(l_n*56)+29] += A[64] * B[(l_n*56)+14];
    C[(l_n*56)+50] += A[65] * B[(l_n*56)+14];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b15 = _mm256_broadcast_sd(&B[(l_n*56)+15]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b15 = _mm_loaddup_pd(&B[(l_n*56)+15]);
#endif
    __m128d c15_0 = _mm_load_sd(&C[(l_n*56)+5]);
    __m128d a15_0 = _mm_load_sd(&A[66]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_0 = _mm_add_sd(c15_0, _mm_mul_sd(a15_0, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_0 = _mm_add_sd(c15_0, _mm_mul_sd(a15_0, b15));
#endif
    _mm_store_sd(&C[(l_n*56)+5], c15_0);
    __m128d c15_1 = _mm_load_sd(&C[(l_n*56)+15]);
    __m128d a15_1 = _mm_load_sd(&A[67]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_1 = _mm_add_sd(c15_1, _mm_mul_sd(a15_1, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_1 = _mm_add_sd(c15_1, _mm_mul_sd(a15_1, b15));
#endif
    _mm_store_sd(&C[(l_n*56)+15], c15_1);
    __m128d c15_2 = _mm_load_sd(&C[(l_n*56)+30]);
    __m128d a15_2 = _mm_load_sd(&A[68]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_2 = _mm_add_sd(c15_2, _mm_mul_sd(a15_2, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_2 = _mm_add_sd(c15_2, _mm_mul_sd(a15_2, b15));
#endif
    _mm_store_sd(&C[(l_n*56)+30], c15_2);
    __m128d c15_3 = _mm_load_sd(&C[(l_n*56)+51]);
    __m128d a15_3 = _mm_load_sd(&A[69]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_3 = _mm_add_sd(c15_3, _mm_mul_sd(a15_3, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_3 = _mm_add_sd(c15_3, _mm_mul_sd(a15_3, b15));
#endif
    _mm_store_sd(&C[(l_n*56)+51], c15_3);
#else
    C[(l_n*56)+5] += A[66] * B[(l_n*56)+15];
    C[(l_n*56)+15] += A[67] * B[(l_n*56)+15];
    C[(l_n*56)+30] += A[68] * B[(l_n*56)+15];
    C[(l_n*56)+51] += A[69] * B[(l_n*56)+15];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b16 = _mm256_broadcast_sd(&B[(l_n*56)+16]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b16 = _mm_loaddup_pd(&B[(l_n*56)+16]);
#endif
    __m128d c16_0 = _mm_load_sd(&C[(l_n*56)+6]);
    __m128d a16_0 = _mm_load_sd(&A[70]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_0 = _mm_add_sd(c16_0, _mm_mul_sd(a16_0, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_0 = _mm_add_sd(c16_0, _mm_mul_sd(a16_0, b16));
#endif
    _mm_store_sd(&C[(l_n*56)+6], c16_0);
    __m128d c16_1 = _mm_load_sd(&C[(l_n*56)+16]);
    __m128d a16_1 = _mm_load_sd(&A[71]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_1 = _mm_add_sd(c16_1, _mm_mul_sd(a16_1, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_1 = _mm_add_sd(c16_1, _mm_mul_sd(a16_1, b16));
#endif
    _mm_store_sd(&C[(l_n*56)+16], c16_1);
    __m128d c16_2 = _mm_load_sd(&C[(l_n*56)+31]);
    __m128d a16_2 = _mm_load_sd(&A[72]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_2 = _mm_add_sd(c16_2, _mm_mul_sd(a16_2, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_2 = _mm_add_sd(c16_2, _mm_mul_sd(a16_2, b16));
#endif
    _mm_store_sd(&C[(l_n*56)+31], c16_2);
    __m128d c16_3 = _mm_load_sd(&C[(l_n*56)+52]);
    __m128d a16_3 = _mm_load_sd(&A[73]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_3 = _mm_add_sd(c16_3, _mm_mul_sd(a16_3, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_3 = _mm_add_sd(c16_3, _mm_mul_sd(a16_3, b16));
#endif
    _mm_store_sd(&C[(l_n*56)+52], c16_3);
#else
    C[(l_n*56)+6] += A[70] * B[(l_n*56)+16];
    C[(l_n*56)+16] += A[71] * B[(l_n*56)+16];
    C[(l_n*56)+31] += A[72] * B[(l_n*56)+16];
    C[(l_n*56)+52] += A[73] * B[(l_n*56)+16];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b17 = _mm256_broadcast_sd(&B[(l_n*56)+17]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b17 = _mm_loaddup_pd(&B[(l_n*56)+17]);
#endif
    __m128d c17_0 = _mm_load_sd(&C[(l_n*56)+1]);
    __m128d a17_0 = _mm_load_sd(&A[74]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_0 = _mm_add_sd(c17_0, _mm_mul_sd(a17_0, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_0 = _mm_add_sd(c17_0, _mm_mul_sd(a17_0, b17));
#endif
    _mm_store_sd(&C[(l_n*56)+1], c17_0);
    __m128d c17_1 = _mm_load_sd(&C[(l_n*56)+7]);
    __m128d a17_1 = _mm_load_sd(&A[75]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_1 = _mm_add_sd(c17_1, _mm_mul_sd(a17_1, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_1 = _mm_add_sd(c17_1, _mm_mul_sd(a17_1, b17));
#endif
    _mm_store_sd(&C[(l_n*56)+7], c17_1);
    __m128d c17_2 = _mm_load_sd(&C[(l_n*56)+17]);
    __m128d a17_2 = _mm_load_sd(&A[76]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_2 = _mm_add_sd(c17_2, _mm_mul_sd(a17_2, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_2 = _mm_add_sd(c17_2, _mm_mul_sd(a17_2, b17));
#endif
    _mm_store_sd(&C[(l_n*56)+17], c17_2);
    __m128d c17_3 = _mm_load_sd(&C[(l_n*56)+32]);
    __m128d a17_3 = _mm_load_sd(&A[77]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_3 = _mm_add_sd(c17_3, _mm_mul_sd(a17_3, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_3 = _mm_add_sd(c17_3, _mm_mul_sd(a17_3, b17));
#endif
    _mm_store_sd(&C[(l_n*56)+32], c17_3);
    __m128d c17_4 = _mm_load_sd(&C[(l_n*56)+53]);
    __m128d a17_4 = _mm_load_sd(&A[78]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_4 = _mm_add_sd(c17_4, _mm_mul_sd(a17_4, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_4 = _mm_add_sd(c17_4, _mm_mul_sd(a17_4, b17));
#endif
    _mm_store_sd(&C[(l_n*56)+53], c17_4);
#else
    C[(l_n*56)+1] += A[74] * B[(l_n*56)+17];
    C[(l_n*56)+7] += A[75] * B[(l_n*56)+17];
    C[(l_n*56)+17] += A[76] * B[(l_n*56)+17];
    C[(l_n*56)+32] += A[77] * B[(l_n*56)+17];
    C[(l_n*56)+53] += A[78] * B[(l_n*56)+17];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b18 = _mm256_broadcast_sd(&B[(l_n*56)+18]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b18 = _mm_loaddup_pd(&B[(l_n*56)+18]);
#endif
    __m128d c18_0 = _mm_load_sd(&C[(l_n*56)+2]);
    __m128d a18_0 = _mm_load_sd(&A[79]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_0 = _mm_add_sd(c18_0, _mm_mul_sd(a18_0, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_0 = _mm_add_sd(c18_0, _mm_mul_sd(a18_0, b18));
#endif
    _mm_store_sd(&C[(l_n*56)+2], c18_0);
    __m128d c18_1 = _mm_load_sd(&C[(l_n*56)+8]);
    __m128d a18_1 = _mm_load_sd(&A[80]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_1 = _mm_add_sd(c18_1, _mm_mul_sd(a18_1, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_1 = _mm_add_sd(c18_1, _mm_mul_sd(a18_1, b18));
#endif
    _mm_store_sd(&C[(l_n*56)+8], c18_1);
    __m128d c18_2 = _mm_load_sd(&C[(l_n*56)+18]);
    __m128d a18_2 = _mm_load_sd(&A[81]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_2 = _mm_add_sd(c18_2, _mm_mul_sd(a18_2, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_2 = _mm_add_sd(c18_2, _mm_mul_sd(a18_2, b18));
#endif
    _mm_store_sd(&C[(l_n*56)+18], c18_2);
    __m128d c18_3 = _mm_load_sd(&C[(l_n*56)+33]);
    __m128d a18_3 = _mm_load_sd(&A[82]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_3 = _mm_add_sd(c18_3, _mm_mul_sd(a18_3, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_3 = _mm_add_sd(c18_3, _mm_mul_sd(a18_3, b18));
#endif
    _mm_store_sd(&C[(l_n*56)+33], c18_3);
    __m128d c18_4 = _mm_load_sd(&C[(l_n*56)+54]);
    __m128d a18_4 = _mm_load_sd(&A[83]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_4 = _mm_add_sd(c18_4, _mm_mul_sd(a18_4, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_4 = _mm_add_sd(c18_4, _mm_mul_sd(a18_4, b18));
#endif
    _mm_store_sd(&C[(l_n*56)+54], c18_4);
#else
    C[(l_n*56)+2] += A[79] * B[(l_n*56)+18];
    C[(l_n*56)+8] += A[80] * B[(l_n*56)+18];
    C[(l_n*56)+18] += A[81] * B[(l_n*56)+18];
    C[(l_n*56)+33] += A[82] * B[(l_n*56)+18];
    C[(l_n*56)+54] += A[83] * B[(l_n*56)+18];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b19 = _mm256_broadcast_sd(&B[(l_n*56)+19]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b19 = _mm_loaddup_pd(&B[(l_n*56)+19]);
#endif
    __m128d c19_0 = _mm_load_sd(&C[(l_n*56)+0]);
    __m128d a19_0 = _mm_load_sd(&A[84]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_0 = _mm_add_sd(c19_0, _mm_mul_sd(a19_0, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_0 = _mm_add_sd(c19_0, _mm_mul_sd(a19_0, b19));
#endif
    _mm_store_sd(&C[(l_n*56)+0], c19_0);
    __m128d c19_1 = _mm_load_sd(&C[(l_n*56)+3]);
    __m128d a19_1 = _mm_load_sd(&A[85]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_1 = _mm_add_sd(c19_1, _mm_mul_sd(a19_1, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_1 = _mm_add_sd(c19_1, _mm_mul_sd(a19_1, b19));
#endif
    _mm_store_sd(&C[(l_n*56)+3], c19_1);
    __m128d c19_2 = _mm_load_sd(&C[(l_n*56)+9]);
    __m128d a19_2 = _mm_load_sd(&A[86]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_2 = _mm_add_sd(c19_2, _mm_mul_sd(a19_2, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_2 = _mm_add_sd(c19_2, _mm_mul_sd(a19_2, b19));
#endif
    _mm_store_sd(&C[(l_n*56)+9], c19_2);
    __m128d c19_3 = _mm_load_sd(&C[(l_n*56)+19]);
    __m128d a19_3 = _mm_load_sd(&A[87]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_3 = _mm_add_sd(c19_3, _mm_mul_sd(a19_3, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_3 = _mm_add_sd(c19_3, _mm_mul_sd(a19_3, b19));
#endif
    _mm_store_sd(&C[(l_n*56)+19], c19_3);
    __m128d c19_4 = _mm_load_sd(&C[(l_n*56)+34]);
    __m128d a19_4 = _mm_load_sd(&A[88]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_4 = _mm_add_sd(c19_4, _mm_mul_sd(a19_4, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_4 = _mm_add_sd(c19_4, _mm_mul_sd(a19_4, b19));
#endif
    _mm_store_sd(&C[(l_n*56)+34], c19_4);
    __m128d c19_5 = _mm_load_sd(&C[(l_n*56)+55]);
    __m128d a19_5 = _mm_load_sd(&A[89]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_5 = _mm_add_sd(c19_5, _mm_mul_sd(a19_5, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_5 = _mm_add_sd(c19_5, _mm_mul_sd(a19_5, b19));
#endif
    _mm_store_sd(&C[(l_n*56)+55], c19_5);
#else
    C[(l_n*56)+0] += A[84] * B[(l_n*56)+19];
    C[(l_n*56)+3] += A[85] * B[(l_n*56)+19];
    C[(l_n*56)+9] += A[86] * B[(l_n*56)+19];
    C[(l_n*56)+19] += A[87] * B[(l_n*56)+19];
    C[(l_n*56)+34] += A[88] * B[(l_n*56)+19];
    C[(l_n*56)+55] += A[89] * B[(l_n*56)+19];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b20 = _mm256_broadcast_sd(&B[(l_n*56)+20]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b20 = _mm_loaddup_pd(&B[(l_n*56)+20]);
#endif
    __m128d c20_0 = _mm_load_sd(&C[(l_n*56)+20]);
    __m128d a20_0 = _mm_load_sd(&A[90]);
#if defined(__SSE3__) && defined(__AVX__)
    c20_0 = _mm_add_sd(c20_0, _mm_mul_sd(a20_0, _mm256_castpd256_pd128(b20)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c20_0 = _mm_add_sd(c20_0, _mm_mul_sd(a20_0, b20));
#endif
    _mm_store_sd(&C[(l_n*56)+20], c20_0);
    __m128d c20_1 = _mm_load_sd(&C[(l_n*56)+41]);
    __m128d a20_1 = _mm_load_sd(&A[91]);
#if defined(__SSE3__) && defined(__AVX__)
    c20_1 = _mm_add_sd(c20_1, _mm_mul_sd(a20_1, _mm256_castpd256_pd128(b20)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c20_1 = _mm_add_sd(c20_1, _mm_mul_sd(a20_1, b20));
#endif
    _mm_store_sd(&C[(l_n*56)+41], c20_1);
#else
    C[(l_n*56)+20] += A[90] * B[(l_n*56)+20];
    C[(l_n*56)+41] += A[91] * B[(l_n*56)+20];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b21 = _mm256_broadcast_sd(&B[(l_n*56)+21]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b21 = _mm_loaddup_pd(&B[(l_n*56)+21]);
#endif
    __m128d c21_0 = _mm_load_sd(&C[(l_n*56)+21]);
    __m128d a21_0 = _mm_load_sd(&A[92]);
#if defined(__SSE3__) && defined(__AVX__)
    c21_0 = _mm_add_sd(c21_0, _mm_mul_sd(a21_0, _mm256_castpd256_pd128(b21)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c21_0 = _mm_add_sd(c21_0, _mm_mul_sd(a21_0, b21));
#endif
    _mm_store_sd(&C[(l_n*56)+21], c21_0);
    __m128d c21_1 = _mm_load_sd(&C[(l_n*56)+42]);
    __m128d a21_1 = _mm_load_sd(&A[93]);
#if defined(__SSE3__) && defined(__AVX__)
    c21_1 = _mm_add_sd(c21_1, _mm_mul_sd(a21_1, _mm256_castpd256_pd128(b21)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c21_1 = _mm_add_sd(c21_1, _mm_mul_sd(a21_1, b21));
#endif
    _mm_store_sd(&C[(l_n*56)+42], c21_1);
#else
    C[(l_n*56)+21] += A[92] * B[(l_n*56)+21];
    C[(l_n*56)+42] += A[93] * B[(l_n*56)+21];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b22 = _mm256_broadcast_sd(&B[(l_n*56)+22]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b22 = _mm_loaddup_pd(&B[(l_n*56)+22]);
#endif
    __m128d c22_0 = _mm_load_sd(&C[(l_n*56)+22]);
    __m128d a22_0 = _mm_load_sd(&A[94]);
#if defined(__SSE3__) && defined(__AVX__)
    c22_0 = _mm_add_sd(c22_0, _mm_mul_sd(a22_0, _mm256_castpd256_pd128(b22)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c22_0 = _mm_add_sd(c22_0, _mm_mul_sd(a22_0, b22));
#endif
    _mm_store_sd(&C[(l_n*56)+22], c22_0);
    __m128d c22_1 = _mm_load_sd(&C[(l_n*56)+43]);
    __m128d a22_1 = _mm_load_sd(&A[95]);
#if defined(__SSE3__) && defined(__AVX__)
    c22_1 = _mm_add_sd(c22_1, _mm_mul_sd(a22_1, _mm256_castpd256_pd128(b22)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c22_1 = _mm_add_sd(c22_1, _mm_mul_sd(a22_1, b22));
#endif
    _mm_store_sd(&C[(l_n*56)+43], c22_1);
#else
    C[(l_n*56)+22] += A[94] * B[(l_n*56)+22];
    C[(l_n*56)+43] += A[95] * B[(l_n*56)+22];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b23 = _mm256_broadcast_sd(&B[(l_n*56)+23]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b23 = _mm_loaddup_pd(&B[(l_n*56)+23]);
#endif
    __m128d c23_0 = _mm_load_sd(&C[(l_n*56)+23]);
    __m128d a23_0 = _mm_load_sd(&A[96]);
#if defined(__SSE3__) && defined(__AVX__)
    c23_0 = _mm_add_sd(c23_0, _mm_mul_sd(a23_0, _mm256_castpd256_pd128(b23)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c23_0 = _mm_add_sd(c23_0, _mm_mul_sd(a23_0, b23));
#endif
    _mm_store_sd(&C[(l_n*56)+23], c23_0);
    __m128d c23_1 = _mm_load_sd(&C[(l_n*56)+44]);
    __m128d a23_1 = _mm_load_sd(&A[97]);
#if defined(__SSE3__) && defined(__AVX__)
    c23_1 = _mm_add_sd(c23_1, _mm_mul_sd(a23_1, _mm256_castpd256_pd128(b23)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c23_1 = _mm_add_sd(c23_1, _mm_mul_sd(a23_1, b23));
#endif
    _mm_store_sd(&C[(l_n*56)+44], c23_1);
#else
    C[(l_n*56)+23] += A[96] * B[(l_n*56)+23];
    C[(l_n*56)+44] += A[97] * B[(l_n*56)+23];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b24 = _mm256_broadcast_sd(&B[(l_n*56)+24]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b24 = _mm_loaddup_pd(&B[(l_n*56)+24]);
#endif
    __m128d c24_0 = _mm_load_sd(&C[(l_n*56)+24]);
    __m128d a24_0 = _mm_load_sd(&A[98]);
#if defined(__SSE3__) && defined(__AVX__)
    c24_0 = _mm_add_sd(c24_0, _mm_mul_sd(a24_0, _mm256_castpd256_pd128(b24)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c24_0 = _mm_add_sd(c24_0, _mm_mul_sd(a24_0, b24));
#endif
    _mm_store_sd(&C[(l_n*56)+24], c24_0);
    __m128d c24_1 = _mm_load_sd(&C[(l_n*56)+45]);
    __m128d a24_1 = _mm_load_sd(&A[99]);
#if defined(__SSE3__) && defined(__AVX__)
    c24_1 = _mm_add_sd(c24_1, _mm_mul_sd(a24_1, _mm256_castpd256_pd128(b24)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c24_1 = _mm_add_sd(c24_1, _mm_mul_sd(a24_1, b24));
#endif
    _mm_store_sd(&C[(l_n*56)+45], c24_1);
#else
    C[(l_n*56)+24] += A[98] * B[(l_n*56)+24];
    C[(l_n*56)+45] += A[99] * B[(l_n*56)+24];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b25 = _mm256_broadcast_sd(&B[(l_n*56)+25]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b25 = _mm_loaddup_pd(&B[(l_n*56)+25]);
#endif
    __m128d c25_0 = _mm_load_sd(&C[(l_n*56)+10]);
    __m128d a25_0 = _mm_load_sd(&A[100]);
#if defined(__SSE3__) && defined(__AVX__)
    c25_0 = _mm_add_sd(c25_0, _mm_mul_sd(a25_0, _mm256_castpd256_pd128(b25)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c25_0 = _mm_add_sd(c25_0, _mm_mul_sd(a25_0, b25));
#endif
    _mm_store_sd(&C[(l_n*56)+10], c25_0);
    __m128d c25_1 = _mm_load_sd(&C[(l_n*56)+25]);
    __m128d a25_1 = _mm_load_sd(&A[101]);
#if defined(__SSE3__) && defined(__AVX__)
    c25_1 = _mm_add_sd(c25_1, _mm_mul_sd(a25_1, _mm256_castpd256_pd128(b25)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c25_1 = _mm_add_sd(c25_1, _mm_mul_sd(a25_1, b25));
#endif
    _mm_store_sd(&C[(l_n*56)+25], c25_1);
    __m128d c25_2 = _mm_load_sd(&C[(l_n*56)+46]);
    __m128d a25_2 = _mm_load_sd(&A[102]);
#if defined(__SSE3__) && defined(__AVX__)
    c25_2 = _mm_add_sd(c25_2, _mm_mul_sd(a25_2, _mm256_castpd256_pd128(b25)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c25_2 = _mm_add_sd(c25_2, _mm_mul_sd(a25_2, b25));
#endif
    _mm_store_sd(&C[(l_n*56)+46], c25_2);
#else
    C[(l_n*56)+10] += A[100] * B[(l_n*56)+25];
    C[(l_n*56)+25] += A[101] * B[(l_n*56)+25];
    C[(l_n*56)+46] += A[102] * B[(l_n*56)+25];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b26 = _mm256_broadcast_sd(&B[(l_n*56)+26]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b26 = _mm_loaddup_pd(&B[(l_n*56)+26]);
#endif
    __m128d c26_0 = _mm_load_sd(&C[(l_n*56)+11]);
    __m128d a26_0 = _mm_load_sd(&A[103]);
#if defined(__SSE3__) && defined(__AVX__)
    c26_0 = _mm_add_sd(c26_0, _mm_mul_sd(a26_0, _mm256_castpd256_pd128(b26)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c26_0 = _mm_add_sd(c26_0, _mm_mul_sd(a26_0, b26));
#endif
    _mm_store_sd(&C[(l_n*56)+11], c26_0);
    __m128d c26_1 = _mm_load_sd(&C[(l_n*56)+26]);
    __m128d a26_1 = _mm_load_sd(&A[104]);
#if defined(__SSE3__) && defined(__AVX__)
    c26_1 = _mm_add_sd(c26_1, _mm_mul_sd(a26_1, _mm256_castpd256_pd128(b26)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c26_1 = _mm_add_sd(c26_1, _mm_mul_sd(a26_1, b26));
#endif
    _mm_store_sd(&C[(l_n*56)+26], c26_1);
    __m128d c26_2 = _mm_load_sd(&C[(l_n*56)+47]);
    __m128d a26_2 = _mm_load_sd(&A[105]);
#if defined(__SSE3__) && defined(__AVX__)
    c26_2 = _mm_add_sd(c26_2, _mm_mul_sd(a26_2, _mm256_castpd256_pd128(b26)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c26_2 = _mm_add_sd(c26_2, _mm_mul_sd(a26_2, b26));
#endif
    _mm_store_sd(&C[(l_n*56)+47], c26_2);
#else
    C[(l_n*56)+11] += A[103] * B[(l_n*56)+26];
    C[(l_n*56)+26] += A[104] * B[(l_n*56)+26];
    C[(l_n*56)+47] += A[105] * B[(l_n*56)+26];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b27 = _mm256_broadcast_sd(&B[(l_n*56)+27]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b27 = _mm_loaddup_pd(&B[(l_n*56)+27]);
#endif
    __m128d c27_0 = _mm_load_sd(&C[(l_n*56)+12]);
    __m128d a27_0 = _mm_load_sd(&A[106]);
#if defined(__SSE3__) && defined(__AVX__)
    c27_0 = _mm_add_sd(c27_0, _mm_mul_sd(a27_0, _mm256_castpd256_pd128(b27)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c27_0 = _mm_add_sd(c27_0, _mm_mul_sd(a27_0, b27));
#endif
    _mm_store_sd(&C[(l_n*56)+12], c27_0);
    __m128d c27_1 = _mm_load_sd(&C[(l_n*56)+27]);
    __m128d a27_1 = _mm_load_sd(&A[107]);
#if defined(__SSE3__) && defined(__AVX__)
    c27_1 = _mm_add_sd(c27_1, _mm_mul_sd(a27_1, _mm256_castpd256_pd128(b27)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c27_1 = _mm_add_sd(c27_1, _mm_mul_sd(a27_1, b27));
#endif
    _mm_store_sd(&C[(l_n*56)+27], c27_1);
    __m128d c27_2 = _mm_load_sd(&C[(l_n*56)+48]);
    __m128d a27_2 = _mm_load_sd(&A[108]);
#if defined(__SSE3__) && defined(__AVX__)
    c27_2 = _mm_add_sd(c27_2, _mm_mul_sd(a27_2, _mm256_castpd256_pd128(b27)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c27_2 = _mm_add_sd(c27_2, _mm_mul_sd(a27_2, b27));
#endif
    _mm_store_sd(&C[(l_n*56)+48], c27_2);
#else
    C[(l_n*56)+12] += A[106] * B[(l_n*56)+27];
    C[(l_n*56)+27] += A[107] * B[(l_n*56)+27];
    C[(l_n*56)+48] += A[108] * B[(l_n*56)+27];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b28 = _mm256_broadcast_sd(&B[(l_n*56)+28]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b28 = _mm_loaddup_pd(&B[(l_n*56)+28]);
#endif
    __m128d c28_0 = _mm_load_sd(&C[(l_n*56)+13]);
    __m128d a28_0 = _mm_load_sd(&A[109]);
#if defined(__SSE3__) && defined(__AVX__)
    c28_0 = _mm_add_sd(c28_0, _mm_mul_sd(a28_0, _mm256_castpd256_pd128(b28)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c28_0 = _mm_add_sd(c28_0, _mm_mul_sd(a28_0, b28));
#endif
    _mm_store_sd(&C[(l_n*56)+13], c28_0);
    __m128d c28_1 = _mm_load_sd(&C[(l_n*56)+28]);
    __m128d a28_1 = _mm_load_sd(&A[110]);
#if defined(__SSE3__) && defined(__AVX__)
    c28_1 = _mm_add_sd(c28_1, _mm_mul_sd(a28_1, _mm256_castpd256_pd128(b28)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c28_1 = _mm_add_sd(c28_1, _mm_mul_sd(a28_1, b28));
#endif
    _mm_store_sd(&C[(l_n*56)+28], c28_1);
    __m128d c28_2 = _mm_load_sd(&C[(l_n*56)+49]);
    __m128d a28_2 = _mm_load_sd(&A[111]);
#if defined(__SSE3__) && defined(__AVX__)
    c28_2 = _mm_add_sd(c28_2, _mm_mul_sd(a28_2, _mm256_castpd256_pd128(b28)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c28_2 = _mm_add_sd(c28_2, _mm_mul_sd(a28_2, b28));
#endif
    _mm_store_sd(&C[(l_n*56)+49], c28_2);
#else
    C[(l_n*56)+13] += A[109] * B[(l_n*56)+28];
    C[(l_n*56)+28] += A[110] * B[(l_n*56)+28];
    C[(l_n*56)+49] += A[111] * B[(l_n*56)+28];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b29 = _mm256_broadcast_sd(&B[(l_n*56)+29]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b29 = _mm_loaddup_pd(&B[(l_n*56)+29]);
#endif
    __m128d c29_0 = _mm_load_sd(&C[(l_n*56)+4]);
    __m128d a29_0 = _mm_load_sd(&A[112]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_0 = _mm_add_sd(c29_0, _mm_mul_sd(a29_0, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_0 = _mm_add_sd(c29_0, _mm_mul_sd(a29_0, b29));
#endif
    _mm_store_sd(&C[(l_n*56)+4], c29_0);
    __m128d c29_1 = _mm_load_sd(&C[(l_n*56)+14]);
    __m128d a29_1 = _mm_load_sd(&A[113]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_1 = _mm_add_sd(c29_1, _mm_mul_sd(a29_1, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_1 = _mm_add_sd(c29_1, _mm_mul_sd(a29_1, b29));
#endif
    _mm_store_sd(&C[(l_n*56)+14], c29_1);
    __m128d c29_2 = _mm_load_sd(&C[(l_n*56)+29]);
    __m128d a29_2 = _mm_load_sd(&A[114]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_2 = _mm_add_sd(c29_2, _mm_mul_sd(a29_2, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_2 = _mm_add_sd(c29_2, _mm_mul_sd(a29_2, b29));
#endif
    _mm_store_sd(&C[(l_n*56)+29], c29_2);
    __m128d c29_3 = _mm_load_sd(&C[(l_n*56)+50]);
    __m128d a29_3 = _mm_load_sd(&A[115]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_3 = _mm_add_sd(c29_3, _mm_mul_sd(a29_3, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_3 = _mm_add_sd(c29_3, _mm_mul_sd(a29_3, b29));
#endif
    _mm_store_sd(&C[(l_n*56)+50], c29_3);
#else
    C[(l_n*56)+4] += A[112] * B[(l_n*56)+29];
    C[(l_n*56)+14] += A[113] * B[(l_n*56)+29];
    C[(l_n*56)+29] += A[114] * B[(l_n*56)+29];
    C[(l_n*56)+50] += A[115] * B[(l_n*56)+29];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b30 = _mm256_broadcast_sd(&B[(l_n*56)+30]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b30 = _mm_loaddup_pd(&B[(l_n*56)+30]);
#endif
    __m128d c30_0 = _mm_load_sd(&C[(l_n*56)+5]);
    __m128d a30_0 = _mm_load_sd(&A[116]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_0 = _mm_add_sd(c30_0, _mm_mul_sd(a30_0, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_0 = _mm_add_sd(c30_0, _mm_mul_sd(a30_0, b30));
#endif
    _mm_store_sd(&C[(l_n*56)+5], c30_0);
    __m128d c30_1 = _mm_load_sd(&C[(l_n*56)+15]);
    __m128d a30_1 = _mm_load_sd(&A[117]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_1 = _mm_add_sd(c30_1, _mm_mul_sd(a30_1, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_1 = _mm_add_sd(c30_1, _mm_mul_sd(a30_1, b30));
#endif
    _mm_store_sd(&C[(l_n*56)+15], c30_1);
    __m128d c30_2 = _mm_load_sd(&C[(l_n*56)+30]);
    __m128d a30_2 = _mm_load_sd(&A[118]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_2 = _mm_add_sd(c30_2, _mm_mul_sd(a30_2, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_2 = _mm_add_sd(c30_2, _mm_mul_sd(a30_2, b30));
#endif
    _mm_store_sd(&C[(l_n*56)+30], c30_2);
    __m128d c30_3 = _mm_load_sd(&C[(l_n*56)+51]);
    __m128d a30_3 = _mm_load_sd(&A[119]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_3 = _mm_add_sd(c30_3, _mm_mul_sd(a30_3, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_3 = _mm_add_sd(c30_3, _mm_mul_sd(a30_3, b30));
#endif
    _mm_store_sd(&C[(l_n*56)+51], c30_3);
#else
    C[(l_n*56)+5] += A[116] * B[(l_n*56)+30];
    C[(l_n*56)+15] += A[117] * B[(l_n*56)+30];
    C[(l_n*56)+30] += A[118] * B[(l_n*56)+30];
    C[(l_n*56)+51] += A[119] * B[(l_n*56)+30];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b31 = _mm256_broadcast_sd(&B[(l_n*56)+31]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b31 = _mm_loaddup_pd(&B[(l_n*56)+31]);
#endif
    __m128d c31_0 = _mm_load_sd(&C[(l_n*56)+6]);
    __m128d a31_0 = _mm_load_sd(&A[120]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_0 = _mm_add_sd(c31_0, _mm_mul_sd(a31_0, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_0 = _mm_add_sd(c31_0, _mm_mul_sd(a31_0, b31));
#endif
    _mm_store_sd(&C[(l_n*56)+6], c31_0);
    __m128d c31_1 = _mm_load_sd(&C[(l_n*56)+16]);
    __m128d a31_1 = _mm_load_sd(&A[121]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_1 = _mm_add_sd(c31_1, _mm_mul_sd(a31_1, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_1 = _mm_add_sd(c31_1, _mm_mul_sd(a31_1, b31));
#endif
    _mm_store_sd(&C[(l_n*56)+16], c31_1);
    __m128d c31_2 = _mm_load_sd(&C[(l_n*56)+31]);
    __m128d a31_2 = _mm_load_sd(&A[122]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_2 = _mm_add_sd(c31_2, _mm_mul_sd(a31_2, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_2 = _mm_add_sd(c31_2, _mm_mul_sd(a31_2, b31));
#endif
    _mm_store_sd(&C[(l_n*56)+31], c31_2);
    __m128d c31_3 = _mm_load_sd(&C[(l_n*56)+52]);
    __m128d a31_3 = _mm_load_sd(&A[123]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_3 = _mm_add_sd(c31_3, _mm_mul_sd(a31_3, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_3 = _mm_add_sd(c31_3, _mm_mul_sd(a31_3, b31));
#endif
    _mm_store_sd(&C[(l_n*56)+52], c31_3);
#else
    C[(l_n*56)+6] += A[120] * B[(l_n*56)+31];
    C[(l_n*56)+16] += A[121] * B[(l_n*56)+31];
    C[(l_n*56)+31] += A[122] * B[(l_n*56)+31];
    C[(l_n*56)+52] += A[123] * B[(l_n*56)+31];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b32 = _mm256_broadcast_sd(&B[(l_n*56)+32]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b32 = _mm_loaddup_pd(&B[(l_n*56)+32]);
#endif
    __m128d c32_0 = _mm_load_sd(&C[(l_n*56)+1]);
    __m128d a32_0 = _mm_load_sd(&A[124]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_0 = _mm_add_sd(c32_0, _mm_mul_sd(a32_0, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_0 = _mm_add_sd(c32_0, _mm_mul_sd(a32_0, b32));
#endif
    _mm_store_sd(&C[(l_n*56)+1], c32_0);
    __m128d c32_1 = _mm_load_sd(&C[(l_n*56)+7]);
    __m128d a32_1 = _mm_load_sd(&A[125]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_1 = _mm_add_sd(c32_1, _mm_mul_sd(a32_1, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_1 = _mm_add_sd(c32_1, _mm_mul_sd(a32_1, b32));
#endif
    _mm_store_sd(&C[(l_n*56)+7], c32_1);
    __m128d c32_2 = _mm_load_sd(&C[(l_n*56)+17]);
    __m128d a32_2 = _mm_load_sd(&A[126]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_2 = _mm_add_sd(c32_2, _mm_mul_sd(a32_2, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_2 = _mm_add_sd(c32_2, _mm_mul_sd(a32_2, b32));
#endif
    _mm_store_sd(&C[(l_n*56)+17], c32_2);
    __m128d c32_3 = _mm_load_sd(&C[(l_n*56)+32]);
    __m128d a32_3 = _mm_load_sd(&A[127]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_3 = _mm_add_sd(c32_3, _mm_mul_sd(a32_3, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_3 = _mm_add_sd(c32_3, _mm_mul_sd(a32_3, b32));
#endif
    _mm_store_sd(&C[(l_n*56)+32], c32_3);
    __m128d c32_4 = _mm_load_sd(&C[(l_n*56)+53]);
    __m128d a32_4 = _mm_load_sd(&A[128]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_4 = _mm_add_sd(c32_4, _mm_mul_sd(a32_4, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_4 = _mm_add_sd(c32_4, _mm_mul_sd(a32_4, b32));
#endif
    _mm_store_sd(&C[(l_n*56)+53], c32_4);
#else
    C[(l_n*56)+1] += A[124] * B[(l_n*56)+32];
    C[(l_n*56)+7] += A[125] * B[(l_n*56)+32];
    C[(l_n*56)+17] += A[126] * B[(l_n*56)+32];
    C[(l_n*56)+32] += A[127] * B[(l_n*56)+32];
    C[(l_n*56)+53] += A[128] * B[(l_n*56)+32];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b33 = _mm256_broadcast_sd(&B[(l_n*56)+33]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b33 = _mm_loaddup_pd(&B[(l_n*56)+33]);
#endif
    __m128d c33_0 = _mm_load_sd(&C[(l_n*56)+2]);
    __m128d a33_0 = _mm_load_sd(&A[129]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_0 = _mm_add_sd(c33_0, _mm_mul_sd(a33_0, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_0 = _mm_add_sd(c33_0, _mm_mul_sd(a33_0, b33));
#endif
    _mm_store_sd(&C[(l_n*56)+2], c33_0);
    __m128d c33_1 = _mm_load_sd(&C[(l_n*56)+8]);
    __m128d a33_1 = _mm_load_sd(&A[130]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_1 = _mm_add_sd(c33_1, _mm_mul_sd(a33_1, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_1 = _mm_add_sd(c33_1, _mm_mul_sd(a33_1, b33));
#endif
    _mm_store_sd(&C[(l_n*56)+8], c33_1);
    __m128d c33_2 = _mm_load_sd(&C[(l_n*56)+18]);
    __m128d a33_2 = _mm_load_sd(&A[131]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_2 = _mm_add_sd(c33_2, _mm_mul_sd(a33_2, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_2 = _mm_add_sd(c33_2, _mm_mul_sd(a33_2, b33));
#endif
    _mm_store_sd(&C[(l_n*56)+18], c33_2);
    __m128d c33_3 = _mm_load_sd(&C[(l_n*56)+33]);
    __m128d a33_3 = _mm_load_sd(&A[132]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_3 = _mm_add_sd(c33_3, _mm_mul_sd(a33_3, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_3 = _mm_add_sd(c33_3, _mm_mul_sd(a33_3, b33));
#endif
    _mm_store_sd(&C[(l_n*56)+33], c33_3);
    __m128d c33_4 = _mm_load_sd(&C[(l_n*56)+54]);
    __m128d a33_4 = _mm_load_sd(&A[133]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_4 = _mm_add_sd(c33_4, _mm_mul_sd(a33_4, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_4 = _mm_add_sd(c33_4, _mm_mul_sd(a33_4, b33));
#endif
    _mm_store_sd(&C[(l_n*56)+54], c33_4);
#else
    C[(l_n*56)+2] += A[129] * B[(l_n*56)+33];
    C[(l_n*56)+8] += A[130] * B[(l_n*56)+33];
    C[(l_n*56)+18] += A[131] * B[(l_n*56)+33];
    C[(l_n*56)+33] += A[132] * B[(l_n*56)+33];
    C[(l_n*56)+54] += A[133] * B[(l_n*56)+33];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b34 = _mm256_broadcast_sd(&B[(l_n*56)+34]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b34 = _mm_loaddup_pd(&B[(l_n*56)+34]);
#endif
    __m128d c34_0 = _mm_load_sd(&C[(l_n*56)+0]);
    __m128d a34_0 = _mm_load_sd(&A[134]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_0 = _mm_add_sd(c34_0, _mm_mul_sd(a34_0, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_0 = _mm_add_sd(c34_0, _mm_mul_sd(a34_0, b34));
#endif
    _mm_store_sd(&C[(l_n*56)+0], c34_0);
    __m128d c34_1 = _mm_load_sd(&C[(l_n*56)+3]);
    __m128d a34_1 = _mm_load_sd(&A[135]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_1 = _mm_add_sd(c34_1, _mm_mul_sd(a34_1, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_1 = _mm_add_sd(c34_1, _mm_mul_sd(a34_1, b34));
#endif
    _mm_store_sd(&C[(l_n*56)+3], c34_1);
    __m128d c34_2 = _mm_load_sd(&C[(l_n*56)+9]);
    __m128d a34_2 = _mm_load_sd(&A[136]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_2 = _mm_add_sd(c34_2, _mm_mul_sd(a34_2, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_2 = _mm_add_sd(c34_2, _mm_mul_sd(a34_2, b34));
#endif
    _mm_store_sd(&C[(l_n*56)+9], c34_2);
    __m128d c34_3 = _mm_load_sd(&C[(l_n*56)+19]);
    __m128d a34_3 = _mm_load_sd(&A[137]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_3 = _mm_add_sd(c34_3, _mm_mul_sd(a34_3, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_3 = _mm_add_sd(c34_3, _mm_mul_sd(a34_3, b34));
#endif
    _mm_store_sd(&C[(l_n*56)+19], c34_3);
    __m128d c34_4 = _mm_load_sd(&C[(l_n*56)+34]);
    __m128d a34_4 = _mm_load_sd(&A[138]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_4 = _mm_add_sd(c34_4, _mm_mul_sd(a34_4, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_4 = _mm_add_sd(c34_4, _mm_mul_sd(a34_4, b34));
#endif
    _mm_store_sd(&C[(l_n*56)+34], c34_4);
    __m128d c34_5 = _mm_load_sd(&C[(l_n*56)+55]);
    __m128d a34_5 = _mm_load_sd(&A[139]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_5 = _mm_add_sd(c34_5, _mm_mul_sd(a34_5, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_5 = _mm_add_sd(c34_5, _mm_mul_sd(a34_5, b34));
#endif
    _mm_store_sd(&C[(l_n*56)+55], c34_5);
#else
    C[(l_n*56)+0] += A[134] * B[(l_n*56)+34];
    C[(l_n*56)+3] += A[135] * B[(l_n*56)+34];
    C[(l_n*56)+9] += A[136] * B[(l_n*56)+34];
    C[(l_n*56)+19] += A[137] * B[(l_n*56)+34];
    C[(l_n*56)+34] += A[138] * B[(l_n*56)+34];
    C[(l_n*56)+55] += A[139] * B[(l_n*56)+34];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b35 = _mm256_broadcast_sd(&B[(l_n*56)+35]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b35 = _mm_loaddup_pd(&B[(l_n*56)+35]);
#endif
    __m128d c35_0 = _mm_load_sd(&C[(l_n*56)+35]);
    __m128d a35_0 = _mm_load_sd(&A[140]);
#if defined(__SSE3__) && defined(__AVX__)
    c35_0 = _mm_add_sd(c35_0, _mm_mul_sd(a35_0, _mm256_castpd256_pd128(b35)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c35_0 = _mm_add_sd(c35_0, _mm_mul_sd(a35_0, b35));
#endif
    _mm_store_sd(&C[(l_n*56)+35], c35_0);
#else
    C[(l_n*56)+35] += A[140] * B[(l_n*56)+35];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b36 = _mm256_broadcast_sd(&B[(l_n*56)+36]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b36 = _mm_loaddup_pd(&B[(l_n*56)+36]);
#endif
    __m128d c36_0 = _mm_load_sd(&C[(l_n*56)+36]);
    __m128d a36_0 = _mm_load_sd(&A[141]);
#if defined(__SSE3__) && defined(__AVX__)
    c36_0 = _mm_add_sd(c36_0, _mm_mul_sd(a36_0, _mm256_castpd256_pd128(b36)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c36_0 = _mm_add_sd(c36_0, _mm_mul_sd(a36_0, b36));
#endif
    _mm_store_sd(&C[(l_n*56)+36], c36_0);
#else
    C[(l_n*56)+36] += A[141] * B[(l_n*56)+36];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b37 = _mm256_broadcast_sd(&B[(l_n*56)+37]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b37 = _mm_loaddup_pd(&B[(l_n*56)+37]);
#endif
    __m128d c37_0 = _mm_load_sd(&C[(l_n*56)+37]);
    __m128d a37_0 = _mm_load_sd(&A[142]);
#if defined(__SSE3__) && defined(__AVX__)
    c37_0 = _mm_add_sd(c37_0, _mm_mul_sd(a37_0, _mm256_castpd256_pd128(b37)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c37_0 = _mm_add_sd(c37_0, _mm_mul_sd(a37_0, b37));
#endif
    _mm_store_sd(&C[(l_n*56)+37], c37_0);
#else
    C[(l_n*56)+37] += A[142] * B[(l_n*56)+37];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b38 = _mm256_broadcast_sd(&B[(l_n*56)+38]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b38 = _mm_loaddup_pd(&B[(l_n*56)+38]);
#endif
    __m128d c38_0 = _mm_load_sd(&C[(l_n*56)+38]);
    __m128d a38_0 = _mm_load_sd(&A[143]);
#if defined(__SSE3__) && defined(__AVX__)
    c38_0 = _mm_add_sd(c38_0, _mm_mul_sd(a38_0, _mm256_castpd256_pd128(b38)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c38_0 = _mm_add_sd(c38_0, _mm_mul_sd(a38_0, b38));
#endif
    _mm_store_sd(&C[(l_n*56)+38], c38_0);
#else
    C[(l_n*56)+38] += A[143] * B[(l_n*56)+38];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b39 = _mm256_broadcast_sd(&B[(l_n*56)+39]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b39 = _mm_loaddup_pd(&B[(l_n*56)+39]);
#endif
    __m128d c39_0 = _mm_load_sd(&C[(l_n*56)+39]);
    __m128d a39_0 = _mm_load_sd(&A[144]);
#if defined(__SSE3__) && defined(__AVX__)
    c39_0 = _mm_add_sd(c39_0, _mm_mul_sd(a39_0, _mm256_castpd256_pd128(b39)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c39_0 = _mm_add_sd(c39_0, _mm_mul_sd(a39_0, b39));
#endif
    _mm_store_sd(&C[(l_n*56)+39], c39_0);
#else
    C[(l_n*56)+39] += A[144] * B[(l_n*56)+39];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b40 = _mm256_broadcast_sd(&B[(l_n*56)+40]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b40 = _mm_loaddup_pd(&B[(l_n*56)+40]);
#endif
    __m128d c40_0 = _mm_load_sd(&C[(l_n*56)+40]);
    __m128d a40_0 = _mm_load_sd(&A[145]);
#if defined(__SSE3__) && defined(__AVX__)
    c40_0 = _mm_add_sd(c40_0, _mm_mul_sd(a40_0, _mm256_castpd256_pd128(b40)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c40_0 = _mm_add_sd(c40_0, _mm_mul_sd(a40_0, b40));
#endif
    _mm_store_sd(&C[(l_n*56)+40], c40_0);
#else
    C[(l_n*56)+40] += A[145] * B[(l_n*56)+40];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b41 = _mm256_broadcast_sd(&B[(l_n*56)+41]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b41 = _mm_loaddup_pd(&B[(l_n*56)+41]);
#endif
    __m128d c41_0 = _mm_load_sd(&C[(l_n*56)+20]);
    __m128d a41_0 = _mm_load_sd(&A[146]);
#if defined(__SSE3__) && defined(__AVX__)
    c41_0 = _mm_add_sd(c41_0, _mm_mul_sd(a41_0, _mm256_castpd256_pd128(b41)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c41_0 = _mm_add_sd(c41_0, _mm_mul_sd(a41_0, b41));
#endif
    _mm_store_sd(&C[(l_n*56)+20], c41_0);
    __m128d c41_1 = _mm_load_sd(&C[(l_n*56)+41]);
    __m128d a41_1 = _mm_load_sd(&A[147]);
#if defined(__SSE3__) && defined(__AVX__)
    c41_1 = _mm_add_sd(c41_1, _mm_mul_sd(a41_1, _mm256_castpd256_pd128(b41)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c41_1 = _mm_add_sd(c41_1, _mm_mul_sd(a41_1, b41));
#endif
    _mm_store_sd(&C[(l_n*56)+41], c41_1);
#else
    C[(l_n*56)+20] += A[146] * B[(l_n*56)+41];
    C[(l_n*56)+41] += A[147] * B[(l_n*56)+41];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b42 = _mm256_broadcast_sd(&B[(l_n*56)+42]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b42 = _mm_loaddup_pd(&B[(l_n*56)+42]);
#endif
    __m128d c42_0 = _mm_load_sd(&C[(l_n*56)+21]);
    __m128d a42_0 = _mm_load_sd(&A[148]);
#if defined(__SSE3__) && defined(__AVX__)
    c42_0 = _mm_add_sd(c42_0, _mm_mul_sd(a42_0, _mm256_castpd256_pd128(b42)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c42_0 = _mm_add_sd(c42_0, _mm_mul_sd(a42_0, b42));
#endif
    _mm_store_sd(&C[(l_n*56)+21], c42_0);
    __m128d c42_1 = _mm_load_sd(&C[(l_n*56)+42]);
    __m128d a42_1 = _mm_load_sd(&A[149]);
#if defined(__SSE3__) && defined(__AVX__)
    c42_1 = _mm_add_sd(c42_1, _mm_mul_sd(a42_1, _mm256_castpd256_pd128(b42)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c42_1 = _mm_add_sd(c42_1, _mm_mul_sd(a42_1, b42));
#endif
    _mm_store_sd(&C[(l_n*56)+42], c42_1);
#else
    C[(l_n*56)+21] += A[148] * B[(l_n*56)+42];
    C[(l_n*56)+42] += A[149] * B[(l_n*56)+42];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b43 = _mm256_broadcast_sd(&B[(l_n*56)+43]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b43 = _mm_loaddup_pd(&B[(l_n*56)+43]);
#endif
    __m128d c43_0 = _mm_load_sd(&C[(l_n*56)+22]);
    __m128d a43_0 = _mm_load_sd(&A[150]);
#if defined(__SSE3__) && defined(__AVX__)
    c43_0 = _mm_add_sd(c43_0, _mm_mul_sd(a43_0, _mm256_castpd256_pd128(b43)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c43_0 = _mm_add_sd(c43_0, _mm_mul_sd(a43_0, b43));
#endif
    _mm_store_sd(&C[(l_n*56)+22], c43_0);
    __m128d c43_1 = _mm_load_sd(&C[(l_n*56)+43]);
    __m128d a43_1 = _mm_load_sd(&A[151]);
#if defined(__SSE3__) && defined(__AVX__)
    c43_1 = _mm_add_sd(c43_1, _mm_mul_sd(a43_1, _mm256_castpd256_pd128(b43)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c43_1 = _mm_add_sd(c43_1, _mm_mul_sd(a43_1, b43));
#endif
    _mm_store_sd(&C[(l_n*56)+43], c43_1);
#else
    C[(l_n*56)+22] += A[150] * B[(l_n*56)+43];
    C[(l_n*56)+43] += A[151] * B[(l_n*56)+43];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b44 = _mm256_broadcast_sd(&B[(l_n*56)+44]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b44 = _mm_loaddup_pd(&B[(l_n*56)+44]);
#endif
    __m128d c44_0 = _mm_load_sd(&C[(l_n*56)+23]);
    __m128d a44_0 = _mm_load_sd(&A[152]);
#if defined(__SSE3__) && defined(__AVX__)
    c44_0 = _mm_add_sd(c44_0, _mm_mul_sd(a44_0, _mm256_castpd256_pd128(b44)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c44_0 = _mm_add_sd(c44_0, _mm_mul_sd(a44_0, b44));
#endif
    _mm_store_sd(&C[(l_n*56)+23], c44_0);
    __m128d c44_1 = _mm_load_sd(&C[(l_n*56)+44]);
    __m128d a44_1 = _mm_load_sd(&A[153]);
#if defined(__SSE3__) && defined(__AVX__)
    c44_1 = _mm_add_sd(c44_1, _mm_mul_sd(a44_1, _mm256_castpd256_pd128(b44)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c44_1 = _mm_add_sd(c44_1, _mm_mul_sd(a44_1, b44));
#endif
    _mm_store_sd(&C[(l_n*56)+44], c44_1);
#else
    C[(l_n*56)+23] += A[152] * B[(l_n*56)+44];
    C[(l_n*56)+44] += A[153] * B[(l_n*56)+44];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b45 = _mm256_broadcast_sd(&B[(l_n*56)+45]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b45 = _mm_loaddup_pd(&B[(l_n*56)+45]);
#endif
    __m128d c45_0 = _mm_load_sd(&C[(l_n*56)+24]);
    __m128d a45_0 = _mm_load_sd(&A[154]);
#if defined(__SSE3__) && defined(__AVX__)
    c45_0 = _mm_add_sd(c45_0, _mm_mul_sd(a45_0, _mm256_castpd256_pd128(b45)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c45_0 = _mm_add_sd(c45_0, _mm_mul_sd(a45_0, b45));
#endif
    _mm_store_sd(&C[(l_n*56)+24], c45_0);
    __m128d c45_1 = _mm_load_sd(&C[(l_n*56)+45]);
    __m128d a45_1 = _mm_load_sd(&A[155]);
#if defined(__SSE3__) && defined(__AVX__)
    c45_1 = _mm_add_sd(c45_1, _mm_mul_sd(a45_1, _mm256_castpd256_pd128(b45)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c45_1 = _mm_add_sd(c45_1, _mm_mul_sd(a45_1, b45));
#endif
    _mm_store_sd(&C[(l_n*56)+45], c45_1);
#else
    C[(l_n*56)+24] += A[154] * B[(l_n*56)+45];
    C[(l_n*56)+45] += A[155] * B[(l_n*56)+45];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b46 = _mm256_broadcast_sd(&B[(l_n*56)+46]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b46 = _mm_loaddup_pd(&B[(l_n*56)+46]);
#endif
    __m128d c46_0 = _mm_load_sd(&C[(l_n*56)+10]);
    __m128d a46_0 = _mm_load_sd(&A[156]);
#if defined(__SSE3__) && defined(__AVX__)
    c46_0 = _mm_add_sd(c46_0, _mm_mul_sd(a46_0, _mm256_castpd256_pd128(b46)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c46_0 = _mm_add_sd(c46_0, _mm_mul_sd(a46_0, b46));
#endif
    _mm_store_sd(&C[(l_n*56)+10], c46_0);
    __m128d c46_1 = _mm_load_sd(&C[(l_n*56)+25]);
    __m128d a46_1 = _mm_load_sd(&A[157]);
#if defined(__SSE3__) && defined(__AVX__)
    c46_1 = _mm_add_sd(c46_1, _mm_mul_sd(a46_1, _mm256_castpd256_pd128(b46)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c46_1 = _mm_add_sd(c46_1, _mm_mul_sd(a46_1, b46));
#endif
    _mm_store_sd(&C[(l_n*56)+25], c46_1);
    __m128d c46_2 = _mm_load_sd(&C[(l_n*56)+46]);
    __m128d a46_2 = _mm_load_sd(&A[158]);
#if defined(__SSE3__) && defined(__AVX__)
    c46_2 = _mm_add_sd(c46_2, _mm_mul_sd(a46_2, _mm256_castpd256_pd128(b46)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c46_2 = _mm_add_sd(c46_2, _mm_mul_sd(a46_2, b46));
#endif
    _mm_store_sd(&C[(l_n*56)+46], c46_2);
#else
    C[(l_n*56)+10] += A[156] * B[(l_n*56)+46];
    C[(l_n*56)+25] += A[157] * B[(l_n*56)+46];
    C[(l_n*56)+46] += A[158] * B[(l_n*56)+46];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b47 = _mm256_broadcast_sd(&B[(l_n*56)+47]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b47 = _mm_loaddup_pd(&B[(l_n*56)+47]);
#endif
    __m128d c47_0 = _mm_load_sd(&C[(l_n*56)+11]);
    __m128d a47_0 = _mm_load_sd(&A[159]);
#if defined(__SSE3__) && defined(__AVX__)
    c47_0 = _mm_add_sd(c47_0, _mm_mul_sd(a47_0, _mm256_castpd256_pd128(b47)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c47_0 = _mm_add_sd(c47_0, _mm_mul_sd(a47_0, b47));
#endif
    _mm_store_sd(&C[(l_n*56)+11], c47_0);
    __m128d c47_1 = _mm_load_sd(&C[(l_n*56)+26]);
    __m128d a47_1 = _mm_load_sd(&A[160]);
#if defined(__SSE3__) && defined(__AVX__)
    c47_1 = _mm_add_sd(c47_1, _mm_mul_sd(a47_1, _mm256_castpd256_pd128(b47)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c47_1 = _mm_add_sd(c47_1, _mm_mul_sd(a47_1, b47));
#endif
    _mm_store_sd(&C[(l_n*56)+26], c47_1);
    __m128d c47_2 = _mm_load_sd(&C[(l_n*56)+47]);
    __m128d a47_2 = _mm_load_sd(&A[161]);
#if defined(__SSE3__) && defined(__AVX__)
    c47_2 = _mm_add_sd(c47_2, _mm_mul_sd(a47_2, _mm256_castpd256_pd128(b47)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c47_2 = _mm_add_sd(c47_2, _mm_mul_sd(a47_2, b47));
#endif
    _mm_store_sd(&C[(l_n*56)+47], c47_2);
#else
    C[(l_n*56)+11] += A[159] * B[(l_n*56)+47];
    C[(l_n*56)+26] += A[160] * B[(l_n*56)+47];
    C[(l_n*56)+47] += A[161] * B[(l_n*56)+47];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b48 = _mm256_broadcast_sd(&B[(l_n*56)+48]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b48 = _mm_loaddup_pd(&B[(l_n*56)+48]);
#endif
    __m128d c48_0 = _mm_load_sd(&C[(l_n*56)+12]);
    __m128d a48_0 = _mm_load_sd(&A[162]);
#if defined(__SSE3__) && defined(__AVX__)
    c48_0 = _mm_add_sd(c48_0, _mm_mul_sd(a48_0, _mm256_castpd256_pd128(b48)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c48_0 = _mm_add_sd(c48_0, _mm_mul_sd(a48_0, b48));
#endif
    _mm_store_sd(&C[(l_n*56)+12], c48_0);
    __m128d c48_1 = _mm_load_sd(&C[(l_n*56)+27]);
    __m128d a48_1 = _mm_load_sd(&A[163]);
#if defined(__SSE3__) && defined(__AVX__)
    c48_1 = _mm_add_sd(c48_1, _mm_mul_sd(a48_1, _mm256_castpd256_pd128(b48)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c48_1 = _mm_add_sd(c48_1, _mm_mul_sd(a48_1, b48));
#endif
    _mm_store_sd(&C[(l_n*56)+27], c48_1);
    __m128d c48_2 = _mm_load_sd(&C[(l_n*56)+48]);
    __m128d a48_2 = _mm_load_sd(&A[164]);
#if defined(__SSE3__) && defined(__AVX__)
    c48_2 = _mm_add_sd(c48_2, _mm_mul_sd(a48_2, _mm256_castpd256_pd128(b48)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c48_2 = _mm_add_sd(c48_2, _mm_mul_sd(a48_2, b48));
#endif
    _mm_store_sd(&C[(l_n*56)+48], c48_2);
#else
    C[(l_n*56)+12] += A[162] * B[(l_n*56)+48];
    C[(l_n*56)+27] += A[163] * B[(l_n*56)+48];
    C[(l_n*56)+48] += A[164] * B[(l_n*56)+48];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b49 = _mm256_broadcast_sd(&B[(l_n*56)+49]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b49 = _mm_loaddup_pd(&B[(l_n*56)+49]);
#endif
    __m128d c49_0 = _mm_load_sd(&C[(l_n*56)+13]);
    __m128d a49_0 = _mm_load_sd(&A[165]);
#if defined(__SSE3__) && defined(__AVX__)
    c49_0 = _mm_add_sd(c49_0, _mm_mul_sd(a49_0, _mm256_castpd256_pd128(b49)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c49_0 = _mm_add_sd(c49_0, _mm_mul_sd(a49_0, b49));
#endif
    _mm_store_sd(&C[(l_n*56)+13], c49_0);
    __m128d c49_1 = _mm_load_sd(&C[(l_n*56)+28]);
    __m128d a49_1 = _mm_load_sd(&A[166]);
#if defined(__SSE3__) && defined(__AVX__)
    c49_1 = _mm_add_sd(c49_1, _mm_mul_sd(a49_1, _mm256_castpd256_pd128(b49)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c49_1 = _mm_add_sd(c49_1, _mm_mul_sd(a49_1, b49));
#endif
    _mm_store_sd(&C[(l_n*56)+28], c49_1);
    __m128d c49_2 = _mm_load_sd(&C[(l_n*56)+49]);
    __m128d a49_2 = _mm_load_sd(&A[167]);
#if defined(__SSE3__) && defined(__AVX__)
    c49_2 = _mm_add_sd(c49_2, _mm_mul_sd(a49_2, _mm256_castpd256_pd128(b49)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c49_2 = _mm_add_sd(c49_2, _mm_mul_sd(a49_2, b49));
#endif
    _mm_store_sd(&C[(l_n*56)+49], c49_2);
#else
    C[(l_n*56)+13] += A[165] * B[(l_n*56)+49];
    C[(l_n*56)+28] += A[166] * B[(l_n*56)+49];
    C[(l_n*56)+49] += A[167] * B[(l_n*56)+49];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b50 = _mm256_broadcast_sd(&B[(l_n*56)+50]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b50 = _mm_loaddup_pd(&B[(l_n*56)+50]);
#endif
    __m128d c50_0 = _mm_load_sd(&C[(l_n*56)+4]);
    __m128d a50_0 = _mm_load_sd(&A[168]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_0 = _mm_add_sd(c50_0, _mm_mul_sd(a50_0, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_0 = _mm_add_sd(c50_0, _mm_mul_sd(a50_0, b50));
#endif
    _mm_store_sd(&C[(l_n*56)+4], c50_0);
    __m128d c50_1 = _mm_load_sd(&C[(l_n*56)+14]);
    __m128d a50_1 = _mm_load_sd(&A[169]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_1 = _mm_add_sd(c50_1, _mm_mul_sd(a50_1, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_1 = _mm_add_sd(c50_1, _mm_mul_sd(a50_1, b50));
#endif
    _mm_store_sd(&C[(l_n*56)+14], c50_1);
    __m128d c50_2 = _mm_load_sd(&C[(l_n*56)+29]);
    __m128d a50_2 = _mm_load_sd(&A[170]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_2 = _mm_add_sd(c50_2, _mm_mul_sd(a50_2, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_2 = _mm_add_sd(c50_2, _mm_mul_sd(a50_2, b50));
#endif
    _mm_store_sd(&C[(l_n*56)+29], c50_2);
    __m128d c50_3 = _mm_load_sd(&C[(l_n*56)+50]);
    __m128d a50_3 = _mm_load_sd(&A[171]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_3 = _mm_add_sd(c50_3, _mm_mul_sd(a50_3, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_3 = _mm_add_sd(c50_3, _mm_mul_sd(a50_3, b50));
#endif
    _mm_store_sd(&C[(l_n*56)+50], c50_3);
#else
    C[(l_n*56)+4] += A[168] * B[(l_n*56)+50];
    C[(l_n*56)+14] += A[169] * B[(l_n*56)+50];
    C[(l_n*56)+29] += A[170] * B[(l_n*56)+50];
    C[(l_n*56)+50] += A[171] * B[(l_n*56)+50];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b51 = _mm256_broadcast_sd(&B[(l_n*56)+51]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b51 = _mm_loaddup_pd(&B[(l_n*56)+51]);
#endif
    __m128d c51_0 = _mm_load_sd(&C[(l_n*56)+5]);
    __m128d a51_0 = _mm_load_sd(&A[172]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_0 = _mm_add_sd(c51_0, _mm_mul_sd(a51_0, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_0 = _mm_add_sd(c51_0, _mm_mul_sd(a51_0, b51));
#endif
    _mm_store_sd(&C[(l_n*56)+5], c51_0);
    __m128d c51_1 = _mm_load_sd(&C[(l_n*56)+15]);
    __m128d a51_1 = _mm_load_sd(&A[173]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_1 = _mm_add_sd(c51_1, _mm_mul_sd(a51_1, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_1 = _mm_add_sd(c51_1, _mm_mul_sd(a51_1, b51));
#endif
    _mm_store_sd(&C[(l_n*56)+15], c51_1);
    __m128d c51_2 = _mm_load_sd(&C[(l_n*56)+30]);
    __m128d a51_2 = _mm_load_sd(&A[174]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_2 = _mm_add_sd(c51_2, _mm_mul_sd(a51_2, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_2 = _mm_add_sd(c51_2, _mm_mul_sd(a51_2, b51));
#endif
    _mm_store_sd(&C[(l_n*56)+30], c51_2);
    __m128d c51_3 = _mm_load_sd(&C[(l_n*56)+51]);
    __m128d a51_3 = _mm_load_sd(&A[175]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_3 = _mm_add_sd(c51_3, _mm_mul_sd(a51_3, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_3 = _mm_add_sd(c51_3, _mm_mul_sd(a51_3, b51));
#endif
    _mm_store_sd(&C[(l_n*56)+51], c51_3);
#else
    C[(l_n*56)+5] += A[172] * B[(l_n*56)+51];
    C[(l_n*56)+15] += A[173] * B[(l_n*56)+51];
    C[(l_n*56)+30] += A[174] * B[(l_n*56)+51];
    C[(l_n*56)+51] += A[175] * B[(l_n*56)+51];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b52 = _mm256_broadcast_sd(&B[(l_n*56)+52]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b52 = _mm_loaddup_pd(&B[(l_n*56)+52]);
#endif
    __m128d c52_0 = _mm_load_sd(&C[(l_n*56)+6]);
    __m128d a52_0 = _mm_load_sd(&A[176]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_0 = _mm_add_sd(c52_0, _mm_mul_sd(a52_0, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_0 = _mm_add_sd(c52_0, _mm_mul_sd(a52_0, b52));
#endif
    _mm_store_sd(&C[(l_n*56)+6], c52_0);
    __m128d c52_1 = _mm_load_sd(&C[(l_n*56)+16]);
    __m128d a52_1 = _mm_load_sd(&A[177]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_1 = _mm_add_sd(c52_1, _mm_mul_sd(a52_1, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_1 = _mm_add_sd(c52_1, _mm_mul_sd(a52_1, b52));
#endif
    _mm_store_sd(&C[(l_n*56)+16], c52_1);
    __m128d c52_2 = _mm_load_sd(&C[(l_n*56)+31]);
    __m128d a52_2 = _mm_load_sd(&A[178]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_2 = _mm_add_sd(c52_2, _mm_mul_sd(a52_2, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_2 = _mm_add_sd(c52_2, _mm_mul_sd(a52_2, b52));
#endif
    _mm_store_sd(&C[(l_n*56)+31], c52_2);
    __m128d c52_3 = _mm_load_sd(&C[(l_n*56)+52]);
    __m128d a52_3 = _mm_load_sd(&A[179]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_3 = _mm_add_sd(c52_3, _mm_mul_sd(a52_3, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_3 = _mm_add_sd(c52_3, _mm_mul_sd(a52_3, b52));
#endif
    _mm_store_sd(&C[(l_n*56)+52], c52_3);
#else
    C[(l_n*56)+6] += A[176] * B[(l_n*56)+52];
    C[(l_n*56)+16] += A[177] * B[(l_n*56)+52];
    C[(l_n*56)+31] += A[178] * B[(l_n*56)+52];
    C[(l_n*56)+52] += A[179] * B[(l_n*56)+52];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b53 = _mm256_broadcast_sd(&B[(l_n*56)+53]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b53 = _mm_loaddup_pd(&B[(l_n*56)+53]);
#endif
    __m128d c53_0 = _mm_load_sd(&C[(l_n*56)+1]);
    __m128d a53_0 = _mm_load_sd(&A[180]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_0 = _mm_add_sd(c53_0, _mm_mul_sd(a53_0, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_0 = _mm_add_sd(c53_0, _mm_mul_sd(a53_0, b53));
#endif
    _mm_store_sd(&C[(l_n*56)+1], c53_0);
    __m128d c53_1 = _mm_load_sd(&C[(l_n*56)+7]);
    __m128d a53_1 = _mm_load_sd(&A[181]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_1 = _mm_add_sd(c53_1, _mm_mul_sd(a53_1, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_1 = _mm_add_sd(c53_1, _mm_mul_sd(a53_1, b53));
#endif
    _mm_store_sd(&C[(l_n*56)+7], c53_1);
    __m128d c53_2 = _mm_load_sd(&C[(l_n*56)+17]);
    __m128d a53_2 = _mm_load_sd(&A[182]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_2 = _mm_add_sd(c53_2, _mm_mul_sd(a53_2, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_2 = _mm_add_sd(c53_2, _mm_mul_sd(a53_2, b53));
#endif
    _mm_store_sd(&C[(l_n*56)+17], c53_2);
    __m128d c53_3 = _mm_load_sd(&C[(l_n*56)+32]);
    __m128d a53_3 = _mm_load_sd(&A[183]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_3 = _mm_add_sd(c53_3, _mm_mul_sd(a53_3, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_3 = _mm_add_sd(c53_3, _mm_mul_sd(a53_3, b53));
#endif
    _mm_store_sd(&C[(l_n*56)+32], c53_3);
    __m128d c53_4 = _mm_load_sd(&C[(l_n*56)+53]);
    __m128d a53_4 = _mm_load_sd(&A[184]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_4 = _mm_add_sd(c53_4, _mm_mul_sd(a53_4, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_4 = _mm_add_sd(c53_4, _mm_mul_sd(a53_4, b53));
#endif
    _mm_store_sd(&C[(l_n*56)+53], c53_4);
#else
    C[(l_n*56)+1] += A[180] * B[(l_n*56)+53];
    C[(l_n*56)+7] += A[181] * B[(l_n*56)+53];
    C[(l_n*56)+17] += A[182] * B[(l_n*56)+53];
    C[(l_n*56)+32] += A[183] * B[(l_n*56)+53];
    C[(l_n*56)+53] += A[184] * B[(l_n*56)+53];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b54 = _mm256_broadcast_sd(&B[(l_n*56)+54]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b54 = _mm_loaddup_pd(&B[(l_n*56)+54]);
#endif
    __m128d c54_0 = _mm_load_sd(&C[(l_n*56)+2]);
    __m128d a54_0 = _mm_load_sd(&A[185]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_0 = _mm_add_sd(c54_0, _mm_mul_sd(a54_0, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_0 = _mm_add_sd(c54_0, _mm_mul_sd(a54_0, b54));
#endif
    _mm_store_sd(&C[(l_n*56)+2], c54_0);
    __m128d c54_1 = _mm_load_sd(&C[(l_n*56)+8]);
    __m128d a54_1 = _mm_load_sd(&A[186]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_1 = _mm_add_sd(c54_1, _mm_mul_sd(a54_1, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_1 = _mm_add_sd(c54_1, _mm_mul_sd(a54_1, b54));
#endif
    _mm_store_sd(&C[(l_n*56)+8], c54_1);
    __m128d c54_2 = _mm_load_sd(&C[(l_n*56)+18]);
    __m128d a54_2 = _mm_load_sd(&A[187]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_2 = _mm_add_sd(c54_2, _mm_mul_sd(a54_2, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_2 = _mm_add_sd(c54_2, _mm_mul_sd(a54_2, b54));
#endif
    _mm_store_sd(&C[(l_n*56)+18], c54_2);
    __m128d c54_3 = _mm_load_sd(&C[(l_n*56)+33]);
    __m128d a54_3 = _mm_load_sd(&A[188]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_3 = _mm_add_sd(c54_3, _mm_mul_sd(a54_3, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_3 = _mm_add_sd(c54_3, _mm_mul_sd(a54_3, b54));
#endif
    _mm_store_sd(&C[(l_n*56)+33], c54_3);
    __m128d c54_4 = _mm_load_sd(&C[(l_n*56)+54]);
    __m128d a54_4 = _mm_load_sd(&A[189]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_4 = _mm_add_sd(c54_4, _mm_mul_sd(a54_4, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_4 = _mm_add_sd(c54_4, _mm_mul_sd(a54_4, b54));
#endif
    _mm_store_sd(&C[(l_n*56)+54], c54_4);
#else
    C[(l_n*56)+2] += A[185] * B[(l_n*56)+54];
    C[(l_n*56)+8] += A[186] * B[(l_n*56)+54];
    C[(l_n*56)+18] += A[187] * B[(l_n*56)+54];
    C[(l_n*56)+33] += A[188] * B[(l_n*56)+54];
    C[(l_n*56)+54] += A[189] * B[(l_n*56)+54];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b55 = _mm256_broadcast_sd(&B[(l_n*56)+55]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b55 = _mm_loaddup_pd(&B[(l_n*56)+55]);
#endif
    __m128d c55_0 = _mm_load_sd(&C[(l_n*56)+0]);
    __m128d a55_0 = _mm_load_sd(&A[190]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_0 = _mm_add_sd(c55_0, _mm_mul_sd(a55_0, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_0 = _mm_add_sd(c55_0, _mm_mul_sd(a55_0, b55));
#endif
    _mm_store_sd(&C[(l_n*56)+0], c55_0);
    __m128d c55_1 = _mm_load_sd(&C[(l_n*56)+3]);
    __m128d a55_1 = _mm_load_sd(&A[191]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_1 = _mm_add_sd(c55_1, _mm_mul_sd(a55_1, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_1 = _mm_add_sd(c55_1, _mm_mul_sd(a55_1, b55));
#endif
    _mm_store_sd(&C[(l_n*56)+3], c55_1);
    __m128d c55_2 = _mm_load_sd(&C[(l_n*56)+9]);
    __m128d a55_2 = _mm_load_sd(&A[192]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_2 = _mm_add_sd(c55_2, _mm_mul_sd(a55_2, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_2 = _mm_add_sd(c55_2, _mm_mul_sd(a55_2, b55));
#endif
    _mm_store_sd(&C[(l_n*56)+9], c55_2);
    __m128d c55_3 = _mm_load_sd(&C[(l_n*56)+19]);
    __m128d a55_3 = _mm_load_sd(&A[193]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_3 = _mm_add_sd(c55_3, _mm_mul_sd(a55_3, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_3 = _mm_add_sd(c55_3, _mm_mul_sd(a55_3, b55));
#endif
    _mm_store_sd(&C[(l_n*56)+19], c55_3);
    __m128d c55_4 = _mm_load_sd(&C[(l_n*56)+34]);
    __m128d a55_4 = _mm_load_sd(&A[194]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_4 = _mm_add_sd(c55_4, _mm_mul_sd(a55_4, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_4 = _mm_add_sd(c55_4, _mm_mul_sd(a55_4, b55));
#endif
    _mm_store_sd(&C[(l_n*56)+34], c55_4);
    __m128d c55_5 = _mm_load_sd(&C[(l_n*56)+55]);
    __m128d a55_5 = _mm_load_sd(&A[195]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_5 = _mm_add_sd(c55_5, _mm_mul_sd(a55_5, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_5 = _mm_add_sd(c55_5, _mm_mul_sd(a55_5, b55));
#endif
    _mm_store_sd(&C[(l_n*56)+55], c55_5);
#else
    C[(l_n*56)+0] += A[190] * B[(l_n*56)+55];
    C[(l_n*56)+3] += A[191] * B[(l_n*56)+55];
    C[(l_n*56)+9] += A[192] * B[(l_n*56)+55];
    C[(l_n*56)+19] += A[193] * B[(l_n*56)+55];
    C[(l_n*56)+34] += A[194] * B[(l_n*56)+55];
    C[(l_n*56)+55] += A[195] * B[(l_n*56)+55];
#endif

  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 3528;
#endif
}

void dsparse_starMatrix_m84_n9_k9_ldA88_ldBna7_ldC88_beta1_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_m = 0;

  #pragma simd vectorlength(32)
  #pragma vector aligned
  for ( l_m = 0; l_m < 84; l_m++) {
    C[0+l_m] += A[528+l_m] * B[0];
    C[0+l_m] += A[616+l_m] * B[1];
    C[0+l_m] += A[704+l_m] * B[2];
    C[88+l_m] += A[528+l_m] * B[3];
    C[88+l_m] += A[616+l_m] * B[4];
    C[88+l_m] += A[704+l_m] * B[5];
    C[176+l_m] += A[528+l_m] * B[6];
    C[176+l_m] += A[616+l_m] * B[7];
    C[176+l_m] += A[704+l_m] * B[8];
    C[264+l_m] += A[528+l_m] * B[9];
    C[264+l_m] += A[616+l_m] * B[10];
    C[352+l_m] += A[616+l_m] * B[11];
    C[352+l_m] += A[704+l_m] * B[12];
    C[440+l_m] += A[528+l_m] * B[13];
    C[440+l_m] += A[704+l_m] * B[14];
    C[528+l_m] += A[0+l_m] * B[15];
    C[528+l_m] += A[264+l_m] * B[16];
    C[528+l_m] += A[440+l_m] * B[17];
    C[616+l_m] += A[88+l_m] * B[18];
    C[616+l_m] += A[264+l_m] * B[19];
    C[616+l_m] += A[352+l_m] * B[20];
    C[704+l_m] += A[176+l_m] * B[21];
    C[704+l_m] += A[352+l_m] * B[22];
    C[704+l_m] += A[440+l_m] * B[23];
  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 4032;
#endif
}

void dsparse_fP113DivM_m84_n9_k84_ldAna7_ldB88_ldC88_beta0_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_n = 0;
  #pragma nounroll_and_jam
  for ( l_n = 0; l_n < 9; l_n++) {
    unsigned int l_m = 0;
   #pragma simd
    for ( l_m = 0; l_m < 84; l_m++) {
      C[(l_n*88)+l_m] = 0.0;
    }
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b0 = _mm256_broadcast_sd(&B[(l_n*88)+0]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b0 = _mm_loaddup_pd(&B[(l_n*88)+0]);
#endif
    __m128d c0_0 = _mm_load_sd(&C[(l_n*88)+0]);
    __m128d a0_0 = _mm_load_sd(&A[0]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_0 = _mm_add_sd(c0_0, _mm_mul_sd(a0_0, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_0 = _mm_add_sd(c0_0, _mm_mul_sd(a0_0, b0));
#endif
    _mm_store_sd(&C[(l_n*88)+0], c0_0);
    __m128d c0_1 = _mm_load_sd(&C[(l_n*88)+3]);
    __m128d a0_1 = _mm_load_sd(&A[1]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_1 = _mm_add_sd(c0_1, _mm_mul_sd(a0_1, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_1 = _mm_add_sd(c0_1, _mm_mul_sd(a0_1, b0));
#endif
    _mm_store_sd(&C[(l_n*88)+3], c0_1);
    __m128d c0_2 = _mm_load_sd(&C[(l_n*88)+9]);
    __m128d a0_2 = _mm_load_sd(&A[2]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_2 = _mm_add_sd(c0_2, _mm_mul_sd(a0_2, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_2 = _mm_add_sd(c0_2, _mm_mul_sd(a0_2, b0));
#endif
    _mm_store_sd(&C[(l_n*88)+9], c0_2);
    __m128d c0_3 = _mm_load_sd(&C[(l_n*88)+19]);
    __m128d a0_3 = _mm_load_sd(&A[3]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_3 = _mm_add_sd(c0_3, _mm_mul_sd(a0_3, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_3 = _mm_add_sd(c0_3, _mm_mul_sd(a0_3, b0));
#endif
    _mm_store_sd(&C[(l_n*88)+19], c0_3);
    __m128d c0_4 = _mm_load_sd(&C[(l_n*88)+34]);
    __m128d a0_4 = _mm_load_sd(&A[4]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_4 = _mm_add_sd(c0_4, _mm_mul_sd(a0_4, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_4 = _mm_add_sd(c0_4, _mm_mul_sd(a0_4, b0));
#endif
    _mm_store_sd(&C[(l_n*88)+34], c0_4);
    __m128d c0_5 = _mm_load_sd(&C[(l_n*88)+55]);
    __m128d a0_5 = _mm_load_sd(&A[5]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_5 = _mm_add_sd(c0_5, _mm_mul_sd(a0_5, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_5 = _mm_add_sd(c0_5, _mm_mul_sd(a0_5, b0));
#endif
    _mm_store_sd(&C[(l_n*88)+55], c0_5);
    __m128d c0_6 = _mm_load_sd(&C[(l_n*88)+83]);
    __m128d a0_6 = _mm_load_sd(&A[6]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_6 = _mm_add_sd(c0_6, _mm_mul_sd(a0_6, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_6 = _mm_add_sd(c0_6, _mm_mul_sd(a0_6, b0));
#endif
    _mm_store_sd(&C[(l_n*88)+83], c0_6);
#else
    C[(l_n*88)+0] += A[0] * B[(l_n*88)+0];
    C[(l_n*88)+3] += A[1] * B[(l_n*88)+0];
    C[(l_n*88)+9] += A[2] * B[(l_n*88)+0];
    C[(l_n*88)+19] += A[3] * B[(l_n*88)+0];
    C[(l_n*88)+34] += A[4] * B[(l_n*88)+0];
    C[(l_n*88)+55] += A[5] * B[(l_n*88)+0];
    C[(l_n*88)+83] += A[6] * B[(l_n*88)+0];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b1 = _mm256_broadcast_sd(&B[(l_n*88)+1]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b1 = _mm_loaddup_pd(&B[(l_n*88)+1]);
#endif
    __m128d c1_0 = _mm_load_sd(&C[(l_n*88)+1]);
    __m128d a1_0 = _mm_load_sd(&A[7]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_0 = _mm_add_sd(c1_0, _mm_mul_sd(a1_0, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_0 = _mm_add_sd(c1_0, _mm_mul_sd(a1_0, b1));
#endif
    _mm_store_sd(&C[(l_n*88)+1], c1_0);
    __m128d c1_1 = _mm_load_sd(&C[(l_n*88)+7]);
    __m128d a1_1 = _mm_load_sd(&A[8]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_1 = _mm_add_sd(c1_1, _mm_mul_sd(a1_1, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_1 = _mm_add_sd(c1_1, _mm_mul_sd(a1_1, b1));
#endif
    _mm_store_sd(&C[(l_n*88)+7], c1_1);
    __m128d c1_2 = _mm_load_sd(&C[(l_n*88)+17]);
    __m128d a1_2 = _mm_load_sd(&A[9]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_2 = _mm_add_sd(c1_2, _mm_mul_sd(a1_2, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_2 = _mm_add_sd(c1_2, _mm_mul_sd(a1_2, b1));
#endif
    _mm_store_sd(&C[(l_n*88)+17], c1_2);
    __m128d c1_3 = _mm_load_sd(&C[(l_n*88)+32]);
    __m128d a1_3 = _mm_load_sd(&A[10]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_3 = _mm_add_sd(c1_3, _mm_mul_sd(a1_3, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_3 = _mm_add_sd(c1_3, _mm_mul_sd(a1_3, b1));
#endif
    _mm_store_sd(&C[(l_n*88)+32], c1_3);
    __m128d c1_4 = _mm_load_sd(&C[(l_n*88)+53]);
    __m128d a1_4 = _mm_load_sd(&A[11]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_4 = _mm_add_sd(c1_4, _mm_mul_sd(a1_4, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_4 = _mm_add_sd(c1_4, _mm_mul_sd(a1_4, b1));
#endif
    _mm_store_sd(&C[(l_n*88)+53], c1_4);
    __m128d c1_5 = _mm_load_sd(&C[(l_n*88)+81]);
    __m128d a1_5 = _mm_load_sd(&A[12]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_5 = _mm_add_sd(c1_5, _mm_mul_sd(a1_5, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_5 = _mm_add_sd(c1_5, _mm_mul_sd(a1_5, b1));
#endif
    _mm_store_sd(&C[(l_n*88)+81], c1_5);
#else
    C[(l_n*88)+1] += A[7] * B[(l_n*88)+1];
    C[(l_n*88)+7] += A[8] * B[(l_n*88)+1];
    C[(l_n*88)+17] += A[9] * B[(l_n*88)+1];
    C[(l_n*88)+32] += A[10] * B[(l_n*88)+1];
    C[(l_n*88)+53] += A[11] * B[(l_n*88)+1];
    C[(l_n*88)+81] += A[12] * B[(l_n*88)+1];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b2 = _mm256_broadcast_sd(&B[(l_n*88)+2]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b2 = _mm_loaddup_pd(&B[(l_n*88)+2]);
#endif
    __m128d c2_0 = _mm_load_sd(&C[(l_n*88)+2]);
    __m128d a2_0 = _mm_load_sd(&A[13]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_0 = _mm_add_sd(c2_0, _mm_mul_sd(a2_0, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_0 = _mm_add_sd(c2_0, _mm_mul_sd(a2_0, b2));
#endif
    _mm_store_sd(&C[(l_n*88)+2], c2_0);
    __m128d c2_1 = _mm_load_sd(&C[(l_n*88)+8]);
    __m128d a2_1 = _mm_load_sd(&A[14]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_1 = _mm_add_sd(c2_1, _mm_mul_sd(a2_1, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_1 = _mm_add_sd(c2_1, _mm_mul_sd(a2_1, b2));
#endif
    _mm_store_sd(&C[(l_n*88)+8], c2_1);
    __m128d c2_2 = _mm_load_sd(&C[(l_n*88)+18]);
    __m128d a2_2 = _mm_load_sd(&A[15]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_2 = _mm_add_sd(c2_2, _mm_mul_sd(a2_2, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_2 = _mm_add_sd(c2_2, _mm_mul_sd(a2_2, b2));
#endif
    _mm_store_sd(&C[(l_n*88)+18], c2_2);
    __m128d c2_3 = _mm_load_sd(&C[(l_n*88)+33]);
    __m128d a2_3 = _mm_load_sd(&A[16]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_3 = _mm_add_sd(c2_3, _mm_mul_sd(a2_3, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_3 = _mm_add_sd(c2_3, _mm_mul_sd(a2_3, b2));
#endif
    _mm_store_sd(&C[(l_n*88)+33], c2_3);
    __m128d c2_4 = _mm_load_sd(&C[(l_n*88)+54]);
    __m128d a2_4 = _mm_load_sd(&A[17]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_4 = _mm_add_sd(c2_4, _mm_mul_sd(a2_4, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_4 = _mm_add_sd(c2_4, _mm_mul_sd(a2_4, b2));
#endif
    _mm_store_sd(&C[(l_n*88)+54], c2_4);
    __m128d c2_5 = _mm_load_sd(&C[(l_n*88)+82]);
    __m128d a2_5 = _mm_load_sd(&A[18]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_5 = _mm_add_sd(c2_5, _mm_mul_sd(a2_5, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_5 = _mm_add_sd(c2_5, _mm_mul_sd(a2_5, b2));
#endif
    _mm_store_sd(&C[(l_n*88)+82], c2_5);
#else
    C[(l_n*88)+2] += A[13] * B[(l_n*88)+2];
    C[(l_n*88)+8] += A[14] * B[(l_n*88)+2];
    C[(l_n*88)+18] += A[15] * B[(l_n*88)+2];
    C[(l_n*88)+33] += A[16] * B[(l_n*88)+2];
    C[(l_n*88)+54] += A[17] * B[(l_n*88)+2];
    C[(l_n*88)+82] += A[18] * B[(l_n*88)+2];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b3 = _mm256_broadcast_sd(&B[(l_n*88)+3]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b3 = _mm_loaddup_pd(&B[(l_n*88)+3]);
#endif
    __m128d c3_0 = _mm_load_sd(&C[(l_n*88)+0]);
    __m128d a3_0 = _mm_load_sd(&A[19]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_0 = _mm_add_sd(c3_0, _mm_mul_sd(a3_0, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_0 = _mm_add_sd(c3_0, _mm_mul_sd(a3_0, b3));
#endif
    _mm_store_sd(&C[(l_n*88)+0], c3_0);
    __m128d c3_1 = _mm_load_sd(&C[(l_n*88)+3]);
    __m128d a3_1 = _mm_load_sd(&A[20]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_1 = _mm_add_sd(c3_1, _mm_mul_sd(a3_1, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_1 = _mm_add_sd(c3_1, _mm_mul_sd(a3_1, b3));
#endif
    _mm_store_sd(&C[(l_n*88)+3], c3_1);
    __m128d c3_2 = _mm_load_sd(&C[(l_n*88)+9]);
    __m128d a3_2 = _mm_load_sd(&A[21]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_2 = _mm_add_sd(c3_2, _mm_mul_sd(a3_2, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_2 = _mm_add_sd(c3_2, _mm_mul_sd(a3_2, b3));
#endif
    _mm_store_sd(&C[(l_n*88)+9], c3_2);
    __m128d c3_3 = _mm_load_sd(&C[(l_n*88)+19]);
    __m128d a3_3 = _mm_load_sd(&A[22]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_3 = _mm_add_sd(c3_3, _mm_mul_sd(a3_3, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_3 = _mm_add_sd(c3_3, _mm_mul_sd(a3_3, b3));
#endif
    _mm_store_sd(&C[(l_n*88)+19], c3_3);
    __m128d c3_4 = _mm_load_sd(&C[(l_n*88)+34]);
    __m128d a3_4 = _mm_load_sd(&A[23]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_4 = _mm_add_sd(c3_4, _mm_mul_sd(a3_4, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_4 = _mm_add_sd(c3_4, _mm_mul_sd(a3_4, b3));
#endif
    _mm_store_sd(&C[(l_n*88)+34], c3_4);
    __m128d c3_5 = _mm_load_sd(&C[(l_n*88)+55]);
    __m128d a3_5 = _mm_load_sd(&A[24]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_5 = _mm_add_sd(c3_5, _mm_mul_sd(a3_5, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_5 = _mm_add_sd(c3_5, _mm_mul_sd(a3_5, b3));
#endif
    _mm_store_sd(&C[(l_n*88)+55], c3_5);
    __m128d c3_6 = _mm_load_sd(&C[(l_n*88)+83]);
    __m128d a3_6 = _mm_load_sd(&A[25]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_6 = _mm_add_sd(c3_6, _mm_mul_sd(a3_6, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_6 = _mm_add_sd(c3_6, _mm_mul_sd(a3_6, b3));
#endif
    _mm_store_sd(&C[(l_n*88)+83], c3_6);
#else
    C[(l_n*88)+0] += A[19] * B[(l_n*88)+3];
    C[(l_n*88)+3] += A[20] * B[(l_n*88)+3];
    C[(l_n*88)+9] += A[21] * B[(l_n*88)+3];
    C[(l_n*88)+19] += A[22] * B[(l_n*88)+3];
    C[(l_n*88)+34] += A[23] * B[(l_n*88)+3];
    C[(l_n*88)+55] += A[24] * B[(l_n*88)+3];
    C[(l_n*88)+83] += A[25] * B[(l_n*88)+3];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b4 = _mm256_broadcast_sd(&B[(l_n*88)+4]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b4 = _mm_loaddup_pd(&B[(l_n*88)+4]);
#endif
    __m128d c4_0 = _mm_load_sd(&C[(l_n*88)+4]);
    __m128d a4_0 = _mm_load_sd(&A[26]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_0 = _mm_add_sd(c4_0, _mm_mul_sd(a4_0, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_0 = _mm_add_sd(c4_0, _mm_mul_sd(a4_0, b4));
#endif
    _mm_store_sd(&C[(l_n*88)+4], c4_0);
    __m128d c4_1 = _mm_load_sd(&C[(l_n*88)+14]);
    __m128d a4_1 = _mm_load_sd(&A[27]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_1 = _mm_add_sd(c4_1, _mm_mul_sd(a4_1, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_1 = _mm_add_sd(c4_1, _mm_mul_sd(a4_1, b4));
#endif
    _mm_store_sd(&C[(l_n*88)+14], c4_1);
    __m128d c4_2 = _mm_load_sd(&C[(l_n*88)+29]);
    __m128d a4_2 = _mm_load_sd(&A[28]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_2 = _mm_add_sd(c4_2, _mm_mul_sd(a4_2, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_2 = _mm_add_sd(c4_2, _mm_mul_sd(a4_2, b4));
#endif
    _mm_store_sd(&C[(l_n*88)+29], c4_2);
    __m128d c4_3 = _mm_load_sd(&C[(l_n*88)+50]);
    __m128d a4_3 = _mm_load_sd(&A[29]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_3 = _mm_add_sd(c4_3, _mm_mul_sd(a4_3, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_3 = _mm_add_sd(c4_3, _mm_mul_sd(a4_3, b4));
#endif
    _mm_store_sd(&C[(l_n*88)+50], c4_3);
    __m128d c4_4 = _mm_load_sd(&C[(l_n*88)+78]);
    __m128d a4_4 = _mm_load_sd(&A[30]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_4 = _mm_add_sd(c4_4, _mm_mul_sd(a4_4, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_4 = _mm_add_sd(c4_4, _mm_mul_sd(a4_4, b4));
#endif
    _mm_store_sd(&C[(l_n*88)+78], c4_4);
#else
    C[(l_n*88)+4] += A[26] * B[(l_n*88)+4];
    C[(l_n*88)+14] += A[27] * B[(l_n*88)+4];
    C[(l_n*88)+29] += A[28] * B[(l_n*88)+4];
    C[(l_n*88)+50] += A[29] * B[(l_n*88)+4];
    C[(l_n*88)+78] += A[30] * B[(l_n*88)+4];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b5 = _mm256_broadcast_sd(&B[(l_n*88)+5]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b5 = _mm_loaddup_pd(&B[(l_n*88)+5]);
#endif
    __m128d c5_0 = _mm_load_sd(&C[(l_n*88)+5]);
    __m128d a5_0 = _mm_load_sd(&A[31]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_0 = _mm_add_sd(c5_0, _mm_mul_sd(a5_0, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_0 = _mm_add_sd(c5_0, _mm_mul_sd(a5_0, b5));
#endif
    _mm_store_sd(&C[(l_n*88)+5], c5_0);
    __m128d c5_1 = _mm_load_sd(&C[(l_n*88)+15]);
    __m128d a5_1 = _mm_load_sd(&A[32]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_1 = _mm_add_sd(c5_1, _mm_mul_sd(a5_1, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_1 = _mm_add_sd(c5_1, _mm_mul_sd(a5_1, b5));
#endif
    _mm_store_sd(&C[(l_n*88)+15], c5_1);
    __m128d c5_2 = _mm_load_sd(&C[(l_n*88)+30]);
    __m128d a5_2 = _mm_load_sd(&A[33]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_2 = _mm_add_sd(c5_2, _mm_mul_sd(a5_2, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_2 = _mm_add_sd(c5_2, _mm_mul_sd(a5_2, b5));
#endif
    _mm_store_sd(&C[(l_n*88)+30], c5_2);
    __m128d c5_3 = _mm_load_sd(&C[(l_n*88)+51]);
    __m128d a5_3 = _mm_load_sd(&A[34]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_3 = _mm_add_sd(c5_3, _mm_mul_sd(a5_3, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_3 = _mm_add_sd(c5_3, _mm_mul_sd(a5_3, b5));
#endif
    _mm_store_sd(&C[(l_n*88)+51], c5_3);
    __m128d c5_4 = _mm_load_sd(&C[(l_n*88)+79]);
    __m128d a5_4 = _mm_load_sd(&A[35]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_4 = _mm_add_sd(c5_4, _mm_mul_sd(a5_4, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_4 = _mm_add_sd(c5_4, _mm_mul_sd(a5_4, b5));
#endif
    _mm_store_sd(&C[(l_n*88)+79], c5_4);
#else
    C[(l_n*88)+5] += A[31] * B[(l_n*88)+5];
    C[(l_n*88)+15] += A[32] * B[(l_n*88)+5];
    C[(l_n*88)+30] += A[33] * B[(l_n*88)+5];
    C[(l_n*88)+51] += A[34] * B[(l_n*88)+5];
    C[(l_n*88)+79] += A[35] * B[(l_n*88)+5];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b6 = _mm256_broadcast_sd(&B[(l_n*88)+6]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b6 = _mm_loaddup_pd(&B[(l_n*88)+6]);
#endif
    __m128d c6_0 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a6_0 = _mm_load_sd(&A[36]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_0 = _mm_add_sd(c6_0, _mm_mul_sd(a6_0, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_0 = _mm_add_sd(c6_0, _mm_mul_sd(a6_0, b6));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c6_0);
    __m128d c6_1 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a6_1 = _mm_load_sd(&A[37]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_1 = _mm_add_sd(c6_1, _mm_mul_sd(a6_1, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_1 = _mm_add_sd(c6_1, _mm_mul_sd(a6_1, b6));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c6_1);
    __m128d c6_2 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a6_2 = _mm_load_sd(&A[38]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_2 = _mm_add_sd(c6_2, _mm_mul_sd(a6_2, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_2 = _mm_add_sd(c6_2, _mm_mul_sd(a6_2, b6));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c6_2);
    __m128d c6_3 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a6_3 = _mm_load_sd(&A[39]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_3 = _mm_add_sd(c6_3, _mm_mul_sd(a6_3, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_3 = _mm_add_sd(c6_3, _mm_mul_sd(a6_3, b6));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c6_3);
    __m128d c6_4 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a6_4 = _mm_load_sd(&A[40]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_4 = _mm_add_sd(c6_4, _mm_mul_sd(a6_4, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_4 = _mm_add_sd(c6_4, _mm_mul_sd(a6_4, b6));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c6_4);
#else
    C[(l_n*88)+6] += A[36] * B[(l_n*88)+6];
    C[(l_n*88)+16] += A[37] * B[(l_n*88)+6];
    C[(l_n*88)+31] += A[38] * B[(l_n*88)+6];
    C[(l_n*88)+52] += A[39] * B[(l_n*88)+6];
    C[(l_n*88)+80] += A[40] * B[(l_n*88)+6];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b7 = _mm256_broadcast_sd(&B[(l_n*88)+7]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b7 = _mm_loaddup_pd(&B[(l_n*88)+7]);
#endif
    __m128d c7_0 = _mm_load_sd(&C[(l_n*88)+1]);
    __m128d a7_0 = _mm_load_sd(&A[41]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_0 = _mm_add_sd(c7_0, _mm_mul_sd(a7_0, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_0 = _mm_add_sd(c7_0, _mm_mul_sd(a7_0, b7));
#endif
    _mm_store_sd(&C[(l_n*88)+1], c7_0);
    __m128d c7_1 = _mm_load_sd(&C[(l_n*88)+7]);
    __m128d a7_1 = _mm_load_sd(&A[42]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_1 = _mm_add_sd(c7_1, _mm_mul_sd(a7_1, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_1 = _mm_add_sd(c7_1, _mm_mul_sd(a7_1, b7));
#endif
    _mm_store_sd(&C[(l_n*88)+7], c7_1);
    __m128d c7_2 = _mm_load_sd(&C[(l_n*88)+17]);
    __m128d a7_2 = _mm_load_sd(&A[43]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_2 = _mm_add_sd(c7_2, _mm_mul_sd(a7_2, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_2 = _mm_add_sd(c7_2, _mm_mul_sd(a7_2, b7));
#endif
    _mm_store_sd(&C[(l_n*88)+17], c7_2);
    __m128d c7_3 = _mm_load_sd(&C[(l_n*88)+32]);
    __m128d a7_3 = _mm_load_sd(&A[44]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_3 = _mm_add_sd(c7_3, _mm_mul_sd(a7_3, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_3 = _mm_add_sd(c7_3, _mm_mul_sd(a7_3, b7));
#endif
    _mm_store_sd(&C[(l_n*88)+32], c7_3);
    __m128d c7_4 = _mm_load_sd(&C[(l_n*88)+53]);
    __m128d a7_4 = _mm_load_sd(&A[45]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_4 = _mm_add_sd(c7_4, _mm_mul_sd(a7_4, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_4 = _mm_add_sd(c7_4, _mm_mul_sd(a7_4, b7));
#endif
    _mm_store_sd(&C[(l_n*88)+53], c7_4);
    __m128d c7_5 = _mm_load_sd(&C[(l_n*88)+81]);
    __m128d a7_5 = _mm_load_sd(&A[46]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_5 = _mm_add_sd(c7_5, _mm_mul_sd(a7_5, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_5 = _mm_add_sd(c7_5, _mm_mul_sd(a7_5, b7));
#endif
    _mm_store_sd(&C[(l_n*88)+81], c7_5);
#else
    C[(l_n*88)+1] += A[41] * B[(l_n*88)+7];
    C[(l_n*88)+7] += A[42] * B[(l_n*88)+7];
    C[(l_n*88)+17] += A[43] * B[(l_n*88)+7];
    C[(l_n*88)+32] += A[44] * B[(l_n*88)+7];
    C[(l_n*88)+53] += A[45] * B[(l_n*88)+7];
    C[(l_n*88)+81] += A[46] * B[(l_n*88)+7];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b8 = _mm256_broadcast_sd(&B[(l_n*88)+8]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b8 = _mm_loaddup_pd(&B[(l_n*88)+8]);
#endif
    __m128d c8_0 = _mm_load_sd(&C[(l_n*88)+2]);
    __m128d a8_0 = _mm_load_sd(&A[47]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_0 = _mm_add_sd(c8_0, _mm_mul_sd(a8_0, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_0 = _mm_add_sd(c8_0, _mm_mul_sd(a8_0, b8));
#endif
    _mm_store_sd(&C[(l_n*88)+2], c8_0);
    __m128d c8_1 = _mm_load_sd(&C[(l_n*88)+8]);
    __m128d a8_1 = _mm_load_sd(&A[48]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_1 = _mm_add_sd(c8_1, _mm_mul_sd(a8_1, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_1 = _mm_add_sd(c8_1, _mm_mul_sd(a8_1, b8));
#endif
    _mm_store_sd(&C[(l_n*88)+8], c8_1);
    __m128d c8_2 = _mm_load_sd(&C[(l_n*88)+18]);
    __m128d a8_2 = _mm_load_sd(&A[49]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_2 = _mm_add_sd(c8_2, _mm_mul_sd(a8_2, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_2 = _mm_add_sd(c8_2, _mm_mul_sd(a8_2, b8));
#endif
    _mm_store_sd(&C[(l_n*88)+18], c8_2);
    __m128d c8_3 = _mm_load_sd(&C[(l_n*88)+33]);
    __m128d a8_3 = _mm_load_sd(&A[50]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_3 = _mm_add_sd(c8_3, _mm_mul_sd(a8_3, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_3 = _mm_add_sd(c8_3, _mm_mul_sd(a8_3, b8));
#endif
    _mm_store_sd(&C[(l_n*88)+33], c8_3);
    __m128d c8_4 = _mm_load_sd(&C[(l_n*88)+54]);
    __m128d a8_4 = _mm_load_sd(&A[51]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_4 = _mm_add_sd(c8_4, _mm_mul_sd(a8_4, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_4 = _mm_add_sd(c8_4, _mm_mul_sd(a8_4, b8));
#endif
    _mm_store_sd(&C[(l_n*88)+54], c8_4);
    __m128d c8_5 = _mm_load_sd(&C[(l_n*88)+82]);
    __m128d a8_5 = _mm_load_sd(&A[52]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_5 = _mm_add_sd(c8_5, _mm_mul_sd(a8_5, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_5 = _mm_add_sd(c8_5, _mm_mul_sd(a8_5, b8));
#endif
    _mm_store_sd(&C[(l_n*88)+82], c8_5);
#else
    C[(l_n*88)+2] += A[47] * B[(l_n*88)+8];
    C[(l_n*88)+8] += A[48] * B[(l_n*88)+8];
    C[(l_n*88)+18] += A[49] * B[(l_n*88)+8];
    C[(l_n*88)+33] += A[50] * B[(l_n*88)+8];
    C[(l_n*88)+54] += A[51] * B[(l_n*88)+8];
    C[(l_n*88)+82] += A[52] * B[(l_n*88)+8];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b9 = _mm256_broadcast_sd(&B[(l_n*88)+9]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b9 = _mm_loaddup_pd(&B[(l_n*88)+9]);
#endif
    __m128d c9_0 = _mm_load_sd(&C[(l_n*88)+0]);
    __m128d a9_0 = _mm_load_sd(&A[53]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_0 = _mm_add_sd(c9_0, _mm_mul_sd(a9_0, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_0 = _mm_add_sd(c9_0, _mm_mul_sd(a9_0, b9));
#endif
    _mm_store_sd(&C[(l_n*88)+0], c9_0);
    __m128d c9_1 = _mm_load_sd(&C[(l_n*88)+3]);
    __m128d a9_1 = _mm_load_sd(&A[54]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_1 = _mm_add_sd(c9_1, _mm_mul_sd(a9_1, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_1 = _mm_add_sd(c9_1, _mm_mul_sd(a9_1, b9));
#endif
    _mm_store_sd(&C[(l_n*88)+3], c9_1);
    __m128d c9_2 = _mm_load_sd(&C[(l_n*88)+9]);
    __m128d a9_2 = _mm_load_sd(&A[55]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_2 = _mm_add_sd(c9_2, _mm_mul_sd(a9_2, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_2 = _mm_add_sd(c9_2, _mm_mul_sd(a9_2, b9));
#endif
    _mm_store_sd(&C[(l_n*88)+9], c9_2);
    __m128d c9_3 = _mm_load_sd(&C[(l_n*88)+19]);
    __m128d a9_3 = _mm_load_sd(&A[56]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_3 = _mm_add_sd(c9_3, _mm_mul_sd(a9_3, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_3 = _mm_add_sd(c9_3, _mm_mul_sd(a9_3, b9));
#endif
    _mm_store_sd(&C[(l_n*88)+19], c9_3);
    __m128d c9_4 = _mm_load_sd(&C[(l_n*88)+34]);
    __m128d a9_4 = _mm_load_sd(&A[57]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_4 = _mm_add_sd(c9_4, _mm_mul_sd(a9_4, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_4 = _mm_add_sd(c9_4, _mm_mul_sd(a9_4, b9));
#endif
    _mm_store_sd(&C[(l_n*88)+34], c9_4);
    __m128d c9_5 = _mm_load_sd(&C[(l_n*88)+55]);
    __m128d a9_5 = _mm_load_sd(&A[58]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_5 = _mm_add_sd(c9_5, _mm_mul_sd(a9_5, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_5 = _mm_add_sd(c9_5, _mm_mul_sd(a9_5, b9));
#endif
    _mm_store_sd(&C[(l_n*88)+55], c9_5);
    __m128d c9_6 = _mm_load_sd(&C[(l_n*88)+83]);
    __m128d a9_6 = _mm_load_sd(&A[59]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_6 = _mm_add_sd(c9_6, _mm_mul_sd(a9_6, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_6 = _mm_add_sd(c9_6, _mm_mul_sd(a9_6, b9));
#endif
    _mm_store_sd(&C[(l_n*88)+83], c9_6);
#else
    C[(l_n*88)+0] += A[53] * B[(l_n*88)+9];
    C[(l_n*88)+3] += A[54] * B[(l_n*88)+9];
    C[(l_n*88)+9] += A[55] * B[(l_n*88)+9];
    C[(l_n*88)+19] += A[56] * B[(l_n*88)+9];
    C[(l_n*88)+34] += A[57] * B[(l_n*88)+9];
    C[(l_n*88)+55] += A[58] * B[(l_n*88)+9];
    C[(l_n*88)+83] += A[59] * B[(l_n*88)+9];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b10 = _mm256_broadcast_sd(&B[(l_n*88)+10]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b10 = _mm_loaddup_pd(&B[(l_n*88)+10]);
#endif
    __m128d c10_0 = _mm_load_sd(&C[(l_n*88)+10]);
    __m128d a10_0 = _mm_load_sd(&A[60]);
#if defined(__SSE3__) && defined(__AVX__)
    c10_0 = _mm_add_sd(c10_0, _mm_mul_sd(a10_0, _mm256_castpd256_pd128(b10)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c10_0 = _mm_add_sd(c10_0, _mm_mul_sd(a10_0, b10));
#endif
    _mm_store_sd(&C[(l_n*88)+10], c10_0);
    __m128d c10_1 = _mm_load_sd(&C[(l_n*88)+25]);
    __m128d a10_1 = _mm_load_sd(&A[61]);
#if defined(__SSE3__) && defined(__AVX__)
    c10_1 = _mm_add_sd(c10_1, _mm_mul_sd(a10_1, _mm256_castpd256_pd128(b10)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c10_1 = _mm_add_sd(c10_1, _mm_mul_sd(a10_1, b10));
#endif
    _mm_store_sd(&C[(l_n*88)+25], c10_1);
    __m128d c10_2 = _mm_load_sd(&C[(l_n*88)+46]);
    __m128d a10_2 = _mm_load_sd(&A[62]);
#if defined(__SSE3__) && defined(__AVX__)
    c10_2 = _mm_add_sd(c10_2, _mm_mul_sd(a10_2, _mm256_castpd256_pd128(b10)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c10_2 = _mm_add_sd(c10_2, _mm_mul_sd(a10_2, b10));
#endif
    _mm_store_sd(&C[(l_n*88)+46], c10_2);
    __m128d c10_3 = _mm_load_sd(&C[(l_n*88)+74]);
    __m128d a10_3 = _mm_load_sd(&A[63]);
#if defined(__SSE3__) && defined(__AVX__)
    c10_3 = _mm_add_sd(c10_3, _mm_mul_sd(a10_3, _mm256_castpd256_pd128(b10)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c10_3 = _mm_add_sd(c10_3, _mm_mul_sd(a10_3, b10));
#endif
    _mm_store_sd(&C[(l_n*88)+74], c10_3);
#else
    C[(l_n*88)+10] += A[60] * B[(l_n*88)+10];
    C[(l_n*88)+25] += A[61] * B[(l_n*88)+10];
    C[(l_n*88)+46] += A[62] * B[(l_n*88)+10];
    C[(l_n*88)+74] += A[63] * B[(l_n*88)+10];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b11 = _mm256_broadcast_sd(&B[(l_n*88)+11]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b11 = _mm_loaddup_pd(&B[(l_n*88)+11]);
#endif
    __m128d c11_0 = _mm_load_sd(&C[(l_n*88)+11]);
    __m128d a11_0 = _mm_load_sd(&A[64]);
#if defined(__SSE3__) && defined(__AVX__)
    c11_0 = _mm_add_sd(c11_0, _mm_mul_sd(a11_0, _mm256_castpd256_pd128(b11)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c11_0 = _mm_add_sd(c11_0, _mm_mul_sd(a11_0, b11));
#endif
    _mm_store_sd(&C[(l_n*88)+11], c11_0);
    __m128d c11_1 = _mm_load_sd(&C[(l_n*88)+26]);
    __m128d a11_1 = _mm_load_sd(&A[65]);
#if defined(__SSE3__) && defined(__AVX__)
    c11_1 = _mm_add_sd(c11_1, _mm_mul_sd(a11_1, _mm256_castpd256_pd128(b11)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c11_1 = _mm_add_sd(c11_1, _mm_mul_sd(a11_1, b11));
#endif
    _mm_store_sd(&C[(l_n*88)+26], c11_1);
    __m128d c11_2 = _mm_load_sd(&C[(l_n*88)+47]);
    __m128d a11_2 = _mm_load_sd(&A[66]);
#if defined(__SSE3__) && defined(__AVX__)
    c11_2 = _mm_add_sd(c11_2, _mm_mul_sd(a11_2, _mm256_castpd256_pd128(b11)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c11_2 = _mm_add_sd(c11_2, _mm_mul_sd(a11_2, b11));
#endif
    _mm_store_sd(&C[(l_n*88)+47], c11_2);
    __m128d c11_3 = _mm_load_sd(&C[(l_n*88)+75]);
    __m128d a11_3 = _mm_load_sd(&A[67]);
#if defined(__SSE3__) && defined(__AVX__)
    c11_3 = _mm_add_sd(c11_3, _mm_mul_sd(a11_3, _mm256_castpd256_pd128(b11)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c11_3 = _mm_add_sd(c11_3, _mm_mul_sd(a11_3, b11));
#endif
    _mm_store_sd(&C[(l_n*88)+75], c11_3);
#else
    C[(l_n*88)+11] += A[64] * B[(l_n*88)+11];
    C[(l_n*88)+26] += A[65] * B[(l_n*88)+11];
    C[(l_n*88)+47] += A[66] * B[(l_n*88)+11];
    C[(l_n*88)+75] += A[67] * B[(l_n*88)+11];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b12 = _mm256_broadcast_sd(&B[(l_n*88)+12]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b12 = _mm_loaddup_pd(&B[(l_n*88)+12]);
#endif
    __m128d c12_0 = _mm_load_sd(&C[(l_n*88)+12]);
    __m128d a12_0 = _mm_load_sd(&A[68]);
#if defined(__SSE3__) && defined(__AVX__)
    c12_0 = _mm_add_sd(c12_0, _mm_mul_sd(a12_0, _mm256_castpd256_pd128(b12)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c12_0 = _mm_add_sd(c12_0, _mm_mul_sd(a12_0, b12));
#endif
    _mm_store_sd(&C[(l_n*88)+12], c12_0);
    __m128d c12_1 = _mm_load_sd(&C[(l_n*88)+27]);
    __m128d a12_1 = _mm_load_sd(&A[69]);
#if defined(__SSE3__) && defined(__AVX__)
    c12_1 = _mm_add_sd(c12_1, _mm_mul_sd(a12_1, _mm256_castpd256_pd128(b12)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c12_1 = _mm_add_sd(c12_1, _mm_mul_sd(a12_1, b12));
#endif
    _mm_store_sd(&C[(l_n*88)+27], c12_1);
    __m128d c12_2 = _mm_load_sd(&C[(l_n*88)+48]);
    __m128d a12_2 = _mm_load_sd(&A[70]);
#if defined(__SSE3__) && defined(__AVX__)
    c12_2 = _mm_add_sd(c12_2, _mm_mul_sd(a12_2, _mm256_castpd256_pd128(b12)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c12_2 = _mm_add_sd(c12_2, _mm_mul_sd(a12_2, b12));
#endif
    _mm_store_sd(&C[(l_n*88)+48], c12_2);
    __m128d c12_3 = _mm_load_sd(&C[(l_n*88)+76]);
    __m128d a12_3 = _mm_load_sd(&A[71]);
#if defined(__SSE3__) && defined(__AVX__)
    c12_3 = _mm_add_sd(c12_3, _mm_mul_sd(a12_3, _mm256_castpd256_pd128(b12)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c12_3 = _mm_add_sd(c12_3, _mm_mul_sd(a12_3, b12));
#endif
    _mm_store_sd(&C[(l_n*88)+76], c12_3);
#else
    C[(l_n*88)+12] += A[68] * B[(l_n*88)+12];
    C[(l_n*88)+27] += A[69] * B[(l_n*88)+12];
    C[(l_n*88)+48] += A[70] * B[(l_n*88)+12];
    C[(l_n*88)+76] += A[71] * B[(l_n*88)+12];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b13 = _mm256_broadcast_sd(&B[(l_n*88)+13]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b13 = _mm_loaddup_pd(&B[(l_n*88)+13]);
#endif
    __m128d c13_0 = _mm_load_sd(&C[(l_n*88)+13]);
    __m128d a13_0 = _mm_load_sd(&A[72]);
#if defined(__SSE3__) && defined(__AVX__)
    c13_0 = _mm_add_sd(c13_0, _mm_mul_sd(a13_0, _mm256_castpd256_pd128(b13)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c13_0 = _mm_add_sd(c13_0, _mm_mul_sd(a13_0, b13));
#endif
    _mm_store_sd(&C[(l_n*88)+13], c13_0);
    __m128d c13_1 = _mm_load_sd(&C[(l_n*88)+28]);
    __m128d a13_1 = _mm_load_sd(&A[73]);
#if defined(__SSE3__) && defined(__AVX__)
    c13_1 = _mm_add_sd(c13_1, _mm_mul_sd(a13_1, _mm256_castpd256_pd128(b13)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c13_1 = _mm_add_sd(c13_1, _mm_mul_sd(a13_1, b13));
#endif
    _mm_store_sd(&C[(l_n*88)+28], c13_1);
    __m128d c13_2 = _mm_load_sd(&C[(l_n*88)+49]);
    __m128d a13_2 = _mm_load_sd(&A[74]);
#if defined(__SSE3__) && defined(__AVX__)
    c13_2 = _mm_add_sd(c13_2, _mm_mul_sd(a13_2, _mm256_castpd256_pd128(b13)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c13_2 = _mm_add_sd(c13_2, _mm_mul_sd(a13_2, b13));
#endif
    _mm_store_sd(&C[(l_n*88)+49], c13_2);
    __m128d c13_3 = _mm_load_sd(&C[(l_n*88)+77]);
    __m128d a13_3 = _mm_load_sd(&A[75]);
#if defined(__SSE3__) && defined(__AVX__)
    c13_3 = _mm_add_sd(c13_3, _mm_mul_sd(a13_3, _mm256_castpd256_pd128(b13)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c13_3 = _mm_add_sd(c13_3, _mm_mul_sd(a13_3, b13));
#endif
    _mm_store_sd(&C[(l_n*88)+77], c13_3);
#else
    C[(l_n*88)+13] += A[72] * B[(l_n*88)+13];
    C[(l_n*88)+28] += A[73] * B[(l_n*88)+13];
    C[(l_n*88)+49] += A[74] * B[(l_n*88)+13];
    C[(l_n*88)+77] += A[75] * B[(l_n*88)+13];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b14 = _mm256_broadcast_sd(&B[(l_n*88)+14]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b14 = _mm_loaddup_pd(&B[(l_n*88)+14]);
#endif
    __m128d c14_0 = _mm_load_sd(&C[(l_n*88)+4]);
    __m128d a14_0 = _mm_load_sd(&A[76]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_0 = _mm_add_sd(c14_0, _mm_mul_sd(a14_0, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_0 = _mm_add_sd(c14_0, _mm_mul_sd(a14_0, b14));
#endif
    _mm_store_sd(&C[(l_n*88)+4], c14_0);
    __m128d c14_1 = _mm_load_sd(&C[(l_n*88)+14]);
    __m128d a14_1 = _mm_load_sd(&A[77]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_1 = _mm_add_sd(c14_1, _mm_mul_sd(a14_1, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_1 = _mm_add_sd(c14_1, _mm_mul_sd(a14_1, b14));
#endif
    _mm_store_sd(&C[(l_n*88)+14], c14_1);
    __m128d c14_2 = _mm_load_sd(&C[(l_n*88)+29]);
    __m128d a14_2 = _mm_load_sd(&A[78]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_2 = _mm_add_sd(c14_2, _mm_mul_sd(a14_2, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_2 = _mm_add_sd(c14_2, _mm_mul_sd(a14_2, b14));
#endif
    _mm_store_sd(&C[(l_n*88)+29], c14_2);
    __m128d c14_3 = _mm_load_sd(&C[(l_n*88)+50]);
    __m128d a14_3 = _mm_load_sd(&A[79]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_3 = _mm_add_sd(c14_3, _mm_mul_sd(a14_3, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_3 = _mm_add_sd(c14_3, _mm_mul_sd(a14_3, b14));
#endif
    _mm_store_sd(&C[(l_n*88)+50], c14_3);
    __m128d c14_4 = _mm_load_sd(&C[(l_n*88)+78]);
    __m128d a14_4 = _mm_load_sd(&A[80]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_4 = _mm_add_sd(c14_4, _mm_mul_sd(a14_4, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_4 = _mm_add_sd(c14_4, _mm_mul_sd(a14_4, b14));
#endif
    _mm_store_sd(&C[(l_n*88)+78], c14_4);
#else
    C[(l_n*88)+4] += A[76] * B[(l_n*88)+14];
    C[(l_n*88)+14] += A[77] * B[(l_n*88)+14];
    C[(l_n*88)+29] += A[78] * B[(l_n*88)+14];
    C[(l_n*88)+50] += A[79] * B[(l_n*88)+14];
    C[(l_n*88)+78] += A[80] * B[(l_n*88)+14];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b15 = _mm256_broadcast_sd(&B[(l_n*88)+15]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b15 = _mm_loaddup_pd(&B[(l_n*88)+15]);
#endif
    __m128d c15_0 = _mm_load_sd(&C[(l_n*88)+5]);
    __m128d a15_0 = _mm_load_sd(&A[81]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_0 = _mm_add_sd(c15_0, _mm_mul_sd(a15_0, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_0 = _mm_add_sd(c15_0, _mm_mul_sd(a15_0, b15));
#endif
    _mm_store_sd(&C[(l_n*88)+5], c15_0);
    __m128d c15_1 = _mm_load_sd(&C[(l_n*88)+15]);
    __m128d a15_1 = _mm_load_sd(&A[82]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_1 = _mm_add_sd(c15_1, _mm_mul_sd(a15_1, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_1 = _mm_add_sd(c15_1, _mm_mul_sd(a15_1, b15));
#endif
    _mm_store_sd(&C[(l_n*88)+15], c15_1);
    __m128d c15_2 = _mm_load_sd(&C[(l_n*88)+30]);
    __m128d a15_2 = _mm_load_sd(&A[83]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_2 = _mm_add_sd(c15_2, _mm_mul_sd(a15_2, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_2 = _mm_add_sd(c15_2, _mm_mul_sd(a15_2, b15));
#endif
    _mm_store_sd(&C[(l_n*88)+30], c15_2);
    __m128d c15_3 = _mm_load_sd(&C[(l_n*88)+51]);
    __m128d a15_3 = _mm_load_sd(&A[84]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_3 = _mm_add_sd(c15_3, _mm_mul_sd(a15_3, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_3 = _mm_add_sd(c15_3, _mm_mul_sd(a15_3, b15));
#endif
    _mm_store_sd(&C[(l_n*88)+51], c15_3);
    __m128d c15_4 = _mm_load_sd(&C[(l_n*88)+79]);
    __m128d a15_4 = _mm_load_sd(&A[85]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_4 = _mm_add_sd(c15_4, _mm_mul_sd(a15_4, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_4 = _mm_add_sd(c15_4, _mm_mul_sd(a15_4, b15));
#endif
    _mm_store_sd(&C[(l_n*88)+79], c15_4);
#else
    C[(l_n*88)+5] += A[81] * B[(l_n*88)+15];
    C[(l_n*88)+15] += A[82] * B[(l_n*88)+15];
    C[(l_n*88)+30] += A[83] * B[(l_n*88)+15];
    C[(l_n*88)+51] += A[84] * B[(l_n*88)+15];
    C[(l_n*88)+79] += A[85] * B[(l_n*88)+15];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b16 = _mm256_broadcast_sd(&B[(l_n*88)+16]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b16 = _mm_loaddup_pd(&B[(l_n*88)+16]);
#endif
    __m128d c16_0 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a16_0 = _mm_load_sd(&A[86]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_0 = _mm_add_sd(c16_0, _mm_mul_sd(a16_0, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_0 = _mm_add_sd(c16_0, _mm_mul_sd(a16_0, b16));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c16_0);
    __m128d c16_1 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a16_1 = _mm_load_sd(&A[87]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_1 = _mm_add_sd(c16_1, _mm_mul_sd(a16_1, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_1 = _mm_add_sd(c16_1, _mm_mul_sd(a16_1, b16));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c16_1);
    __m128d c16_2 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a16_2 = _mm_load_sd(&A[88]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_2 = _mm_add_sd(c16_2, _mm_mul_sd(a16_2, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_2 = _mm_add_sd(c16_2, _mm_mul_sd(a16_2, b16));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c16_2);
    __m128d c16_3 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a16_3 = _mm_load_sd(&A[89]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_3 = _mm_add_sd(c16_3, _mm_mul_sd(a16_3, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_3 = _mm_add_sd(c16_3, _mm_mul_sd(a16_3, b16));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c16_3);
    __m128d c16_4 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a16_4 = _mm_load_sd(&A[90]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_4 = _mm_add_sd(c16_4, _mm_mul_sd(a16_4, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_4 = _mm_add_sd(c16_4, _mm_mul_sd(a16_4, b16));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c16_4);
#else
    C[(l_n*88)+6] += A[86] * B[(l_n*88)+16];
    C[(l_n*88)+16] += A[87] * B[(l_n*88)+16];
    C[(l_n*88)+31] += A[88] * B[(l_n*88)+16];
    C[(l_n*88)+52] += A[89] * B[(l_n*88)+16];
    C[(l_n*88)+80] += A[90] * B[(l_n*88)+16];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b17 = _mm256_broadcast_sd(&B[(l_n*88)+17]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b17 = _mm_loaddup_pd(&B[(l_n*88)+17]);
#endif
    __m128d c17_0 = _mm_load_sd(&C[(l_n*88)+1]);
    __m128d a17_0 = _mm_load_sd(&A[91]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_0 = _mm_add_sd(c17_0, _mm_mul_sd(a17_0, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_0 = _mm_add_sd(c17_0, _mm_mul_sd(a17_0, b17));
#endif
    _mm_store_sd(&C[(l_n*88)+1], c17_0);
    __m128d c17_1 = _mm_load_sd(&C[(l_n*88)+7]);
    __m128d a17_1 = _mm_load_sd(&A[92]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_1 = _mm_add_sd(c17_1, _mm_mul_sd(a17_1, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_1 = _mm_add_sd(c17_1, _mm_mul_sd(a17_1, b17));
#endif
    _mm_store_sd(&C[(l_n*88)+7], c17_1);
    __m128d c17_2 = _mm_load_sd(&C[(l_n*88)+17]);
    __m128d a17_2 = _mm_load_sd(&A[93]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_2 = _mm_add_sd(c17_2, _mm_mul_sd(a17_2, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_2 = _mm_add_sd(c17_2, _mm_mul_sd(a17_2, b17));
#endif
    _mm_store_sd(&C[(l_n*88)+17], c17_2);
    __m128d c17_3 = _mm_load_sd(&C[(l_n*88)+32]);
    __m128d a17_3 = _mm_load_sd(&A[94]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_3 = _mm_add_sd(c17_3, _mm_mul_sd(a17_3, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_3 = _mm_add_sd(c17_3, _mm_mul_sd(a17_3, b17));
#endif
    _mm_store_sd(&C[(l_n*88)+32], c17_3);
    __m128d c17_4 = _mm_load_sd(&C[(l_n*88)+53]);
    __m128d a17_4 = _mm_load_sd(&A[95]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_4 = _mm_add_sd(c17_4, _mm_mul_sd(a17_4, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_4 = _mm_add_sd(c17_4, _mm_mul_sd(a17_4, b17));
#endif
    _mm_store_sd(&C[(l_n*88)+53], c17_4);
    __m128d c17_5 = _mm_load_sd(&C[(l_n*88)+81]);
    __m128d a17_5 = _mm_load_sd(&A[96]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_5 = _mm_add_sd(c17_5, _mm_mul_sd(a17_5, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_5 = _mm_add_sd(c17_5, _mm_mul_sd(a17_5, b17));
#endif
    _mm_store_sd(&C[(l_n*88)+81], c17_5);
#else
    C[(l_n*88)+1] += A[91] * B[(l_n*88)+17];
    C[(l_n*88)+7] += A[92] * B[(l_n*88)+17];
    C[(l_n*88)+17] += A[93] * B[(l_n*88)+17];
    C[(l_n*88)+32] += A[94] * B[(l_n*88)+17];
    C[(l_n*88)+53] += A[95] * B[(l_n*88)+17];
    C[(l_n*88)+81] += A[96] * B[(l_n*88)+17];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b18 = _mm256_broadcast_sd(&B[(l_n*88)+18]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b18 = _mm_loaddup_pd(&B[(l_n*88)+18]);
#endif
    __m128d c18_0 = _mm_load_sd(&C[(l_n*88)+2]);
    __m128d a18_0 = _mm_load_sd(&A[97]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_0 = _mm_add_sd(c18_0, _mm_mul_sd(a18_0, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_0 = _mm_add_sd(c18_0, _mm_mul_sd(a18_0, b18));
#endif
    _mm_store_sd(&C[(l_n*88)+2], c18_0);
    __m128d c18_1 = _mm_load_sd(&C[(l_n*88)+8]);
    __m128d a18_1 = _mm_load_sd(&A[98]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_1 = _mm_add_sd(c18_1, _mm_mul_sd(a18_1, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_1 = _mm_add_sd(c18_1, _mm_mul_sd(a18_1, b18));
#endif
    _mm_store_sd(&C[(l_n*88)+8], c18_1);
    __m128d c18_2 = _mm_load_sd(&C[(l_n*88)+18]);
    __m128d a18_2 = _mm_load_sd(&A[99]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_2 = _mm_add_sd(c18_2, _mm_mul_sd(a18_2, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_2 = _mm_add_sd(c18_2, _mm_mul_sd(a18_2, b18));
#endif
    _mm_store_sd(&C[(l_n*88)+18], c18_2);
    __m128d c18_3 = _mm_load_sd(&C[(l_n*88)+33]);
    __m128d a18_3 = _mm_load_sd(&A[100]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_3 = _mm_add_sd(c18_3, _mm_mul_sd(a18_3, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_3 = _mm_add_sd(c18_3, _mm_mul_sd(a18_3, b18));
#endif
    _mm_store_sd(&C[(l_n*88)+33], c18_3);
    __m128d c18_4 = _mm_load_sd(&C[(l_n*88)+54]);
    __m128d a18_4 = _mm_load_sd(&A[101]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_4 = _mm_add_sd(c18_4, _mm_mul_sd(a18_4, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_4 = _mm_add_sd(c18_4, _mm_mul_sd(a18_4, b18));
#endif
    _mm_store_sd(&C[(l_n*88)+54], c18_4);
    __m128d c18_5 = _mm_load_sd(&C[(l_n*88)+82]);
    __m128d a18_5 = _mm_load_sd(&A[102]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_5 = _mm_add_sd(c18_5, _mm_mul_sd(a18_5, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_5 = _mm_add_sd(c18_5, _mm_mul_sd(a18_5, b18));
#endif
    _mm_store_sd(&C[(l_n*88)+82], c18_5);
#else
    C[(l_n*88)+2] += A[97] * B[(l_n*88)+18];
    C[(l_n*88)+8] += A[98] * B[(l_n*88)+18];
    C[(l_n*88)+18] += A[99] * B[(l_n*88)+18];
    C[(l_n*88)+33] += A[100] * B[(l_n*88)+18];
    C[(l_n*88)+54] += A[101] * B[(l_n*88)+18];
    C[(l_n*88)+82] += A[102] * B[(l_n*88)+18];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b19 = _mm256_broadcast_sd(&B[(l_n*88)+19]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b19 = _mm_loaddup_pd(&B[(l_n*88)+19]);
#endif
    __m128d c19_0 = _mm_load_sd(&C[(l_n*88)+0]);
    __m128d a19_0 = _mm_load_sd(&A[103]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_0 = _mm_add_sd(c19_0, _mm_mul_sd(a19_0, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_0 = _mm_add_sd(c19_0, _mm_mul_sd(a19_0, b19));
#endif
    _mm_store_sd(&C[(l_n*88)+0], c19_0);
    __m128d c19_1 = _mm_load_sd(&C[(l_n*88)+3]);
    __m128d a19_1 = _mm_load_sd(&A[104]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_1 = _mm_add_sd(c19_1, _mm_mul_sd(a19_1, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_1 = _mm_add_sd(c19_1, _mm_mul_sd(a19_1, b19));
#endif
    _mm_store_sd(&C[(l_n*88)+3], c19_1);
    __m128d c19_2 = _mm_load_sd(&C[(l_n*88)+9]);
    __m128d a19_2 = _mm_load_sd(&A[105]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_2 = _mm_add_sd(c19_2, _mm_mul_sd(a19_2, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_2 = _mm_add_sd(c19_2, _mm_mul_sd(a19_2, b19));
#endif
    _mm_store_sd(&C[(l_n*88)+9], c19_2);
    __m128d c19_3 = _mm_load_sd(&C[(l_n*88)+19]);
    __m128d a19_3 = _mm_load_sd(&A[106]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_3 = _mm_add_sd(c19_3, _mm_mul_sd(a19_3, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_3 = _mm_add_sd(c19_3, _mm_mul_sd(a19_3, b19));
#endif
    _mm_store_sd(&C[(l_n*88)+19], c19_3);
    __m128d c19_4 = _mm_load_sd(&C[(l_n*88)+34]);
    __m128d a19_4 = _mm_load_sd(&A[107]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_4 = _mm_add_sd(c19_4, _mm_mul_sd(a19_4, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_4 = _mm_add_sd(c19_4, _mm_mul_sd(a19_4, b19));
#endif
    _mm_store_sd(&C[(l_n*88)+34], c19_4);
    __m128d c19_5 = _mm_load_sd(&C[(l_n*88)+55]);
    __m128d a19_5 = _mm_load_sd(&A[108]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_5 = _mm_add_sd(c19_5, _mm_mul_sd(a19_5, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_5 = _mm_add_sd(c19_5, _mm_mul_sd(a19_5, b19));
#endif
    _mm_store_sd(&C[(l_n*88)+55], c19_5);
    __m128d c19_6 = _mm_load_sd(&C[(l_n*88)+83]);
    __m128d a19_6 = _mm_load_sd(&A[109]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_6 = _mm_add_sd(c19_6, _mm_mul_sd(a19_6, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_6 = _mm_add_sd(c19_6, _mm_mul_sd(a19_6, b19));
#endif
    _mm_store_sd(&C[(l_n*88)+83], c19_6);
#else
    C[(l_n*88)+0] += A[103] * B[(l_n*88)+19];
    C[(l_n*88)+3] += A[104] * B[(l_n*88)+19];
    C[(l_n*88)+9] += A[105] * B[(l_n*88)+19];
    C[(l_n*88)+19] += A[106] * B[(l_n*88)+19];
    C[(l_n*88)+34] += A[107] * B[(l_n*88)+19];
    C[(l_n*88)+55] += A[108] * B[(l_n*88)+19];
    C[(l_n*88)+83] += A[109] * B[(l_n*88)+19];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b20 = _mm256_broadcast_sd(&B[(l_n*88)+20]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b20 = _mm_loaddup_pd(&B[(l_n*88)+20]);
#endif
    __m128d c20_0 = _mm_load_sd(&C[(l_n*88)+20]);
    __m128d a20_0 = _mm_load_sd(&A[110]);
#if defined(__SSE3__) && defined(__AVX__)
    c20_0 = _mm_add_sd(c20_0, _mm_mul_sd(a20_0, _mm256_castpd256_pd128(b20)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c20_0 = _mm_add_sd(c20_0, _mm_mul_sd(a20_0, b20));
#endif
    _mm_store_sd(&C[(l_n*88)+20], c20_0);
    __m128d c20_1 = _mm_load_sd(&C[(l_n*88)+41]);
    __m128d a20_1 = _mm_load_sd(&A[111]);
#if defined(__SSE3__) && defined(__AVX__)
    c20_1 = _mm_add_sd(c20_1, _mm_mul_sd(a20_1, _mm256_castpd256_pd128(b20)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c20_1 = _mm_add_sd(c20_1, _mm_mul_sd(a20_1, b20));
#endif
    _mm_store_sd(&C[(l_n*88)+41], c20_1);
    __m128d c20_2 = _mm_load_sd(&C[(l_n*88)+69]);
    __m128d a20_2 = _mm_load_sd(&A[112]);
#if defined(__SSE3__) && defined(__AVX__)
    c20_2 = _mm_add_sd(c20_2, _mm_mul_sd(a20_2, _mm256_castpd256_pd128(b20)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c20_2 = _mm_add_sd(c20_2, _mm_mul_sd(a20_2, b20));
#endif
    _mm_store_sd(&C[(l_n*88)+69], c20_2);
#else
    C[(l_n*88)+20] += A[110] * B[(l_n*88)+20];
    C[(l_n*88)+41] += A[111] * B[(l_n*88)+20];
    C[(l_n*88)+69] += A[112] * B[(l_n*88)+20];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b21 = _mm256_broadcast_sd(&B[(l_n*88)+21]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b21 = _mm_loaddup_pd(&B[(l_n*88)+21]);
#endif
    __m128d c21_0 = _mm_load_sd(&C[(l_n*88)+21]);
    __m128d a21_0 = _mm_load_sd(&A[113]);
#if defined(__SSE3__) && defined(__AVX__)
    c21_0 = _mm_add_sd(c21_0, _mm_mul_sd(a21_0, _mm256_castpd256_pd128(b21)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c21_0 = _mm_add_sd(c21_0, _mm_mul_sd(a21_0, b21));
#endif
    _mm_store_sd(&C[(l_n*88)+21], c21_0);
    __m128d c21_1 = _mm_load_sd(&C[(l_n*88)+42]);
    __m128d a21_1 = _mm_load_sd(&A[114]);
#if defined(__SSE3__) && defined(__AVX__)
    c21_1 = _mm_add_sd(c21_1, _mm_mul_sd(a21_1, _mm256_castpd256_pd128(b21)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c21_1 = _mm_add_sd(c21_1, _mm_mul_sd(a21_1, b21));
#endif
    _mm_store_sd(&C[(l_n*88)+42], c21_1);
    __m128d c21_2 = _mm_load_sd(&C[(l_n*88)+70]);
    __m128d a21_2 = _mm_load_sd(&A[115]);
#if defined(__SSE3__) && defined(__AVX__)
    c21_2 = _mm_add_sd(c21_2, _mm_mul_sd(a21_2, _mm256_castpd256_pd128(b21)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c21_2 = _mm_add_sd(c21_2, _mm_mul_sd(a21_2, b21));
#endif
    _mm_store_sd(&C[(l_n*88)+70], c21_2);
#else
    C[(l_n*88)+21] += A[113] * B[(l_n*88)+21];
    C[(l_n*88)+42] += A[114] * B[(l_n*88)+21];
    C[(l_n*88)+70] += A[115] * B[(l_n*88)+21];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b22 = _mm256_broadcast_sd(&B[(l_n*88)+22]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b22 = _mm_loaddup_pd(&B[(l_n*88)+22]);
#endif
    __m128d c22_0 = _mm_load_sd(&C[(l_n*88)+22]);
    __m128d a22_0 = _mm_load_sd(&A[116]);
#if defined(__SSE3__) && defined(__AVX__)
    c22_0 = _mm_add_sd(c22_0, _mm_mul_sd(a22_0, _mm256_castpd256_pd128(b22)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c22_0 = _mm_add_sd(c22_0, _mm_mul_sd(a22_0, b22));
#endif
    _mm_store_sd(&C[(l_n*88)+22], c22_0);
    __m128d c22_1 = _mm_load_sd(&C[(l_n*88)+43]);
    __m128d a22_1 = _mm_load_sd(&A[117]);
#if defined(__SSE3__) && defined(__AVX__)
    c22_1 = _mm_add_sd(c22_1, _mm_mul_sd(a22_1, _mm256_castpd256_pd128(b22)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c22_1 = _mm_add_sd(c22_1, _mm_mul_sd(a22_1, b22));
#endif
    _mm_store_sd(&C[(l_n*88)+43], c22_1);
    __m128d c22_2 = _mm_load_sd(&C[(l_n*88)+71]);
    __m128d a22_2 = _mm_load_sd(&A[118]);
#if defined(__SSE3__) && defined(__AVX__)
    c22_2 = _mm_add_sd(c22_2, _mm_mul_sd(a22_2, _mm256_castpd256_pd128(b22)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c22_2 = _mm_add_sd(c22_2, _mm_mul_sd(a22_2, b22));
#endif
    _mm_store_sd(&C[(l_n*88)+71], c22_2);
#else
    C[(l_n*88)+22] += A[116] * B[(l_n*88)+22];
    C[(l_n*88)+43] += A[117] * B[(l_n*88)+22];
    C[(l_n*88)+71] += A[118] * B[(l_n*88)+22];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b23 = _mm256_broadcast_sd(&B[(l_n*88)+23]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b23 = _mm_loaddup_pd(&B[(l_n*88)+23]);
#endif
    __m128d c23_0 = _mm_load_sd(&C[(l_n*88)+23]);
    __m128d a23_0 = _mm_load_sd(&A[119]);
#if defined(__SSE3__) && defined(__AVX__)
    c23_0 = _mm_add_sd(c23_0, _mm_mul_sd(a23_0, _mm256_castpd256_pd128(b23)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c23_0 = _mm_add_sd(c23_0, _mm_mul_sd(a23_0, b23));
#endif
    _mm_store_sd(&C[(l_n*88)+23], c23_0);
    __m128d c23_1 = _mm_load_sd(&C[(l_n*88)+44]);
    __m128d a23_1 = _mm_load_sd(&A[120]);
#if defined(__SSE3__) && defined(__AVX__)
    c23_1 = _mm_add_sd(c23_1, _mm_mul_sd(a23_1, _mm256_castpd256_pd128(b23)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c23_1 = _mm_add_sd(c23_1, _mm_mul_sd(a23_1, b23));
#endif
    _mm_store_sd(&C[(l_n*88)+44], c23_1);
    __m128d c23_2 = _mm_load_sd(&C[(l_n*88)+72]);
    __m128d a23_2 = _mm_load_sd(&A[121]);
#if defined(__SSE3__) && defined(__AVX__)
    c23_2 = _mm_add_sd(c23_2, _mm_mul_sd(a23_2, _mm256_castpd256_pd128(b23)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c23_2 = _mm_add_sd(c23_2, _mm_mul_sd(a23_2, b23));
#endif
    _mm_store_sd(&C[(l_n*88)+72], c23_2);
#else
    C[(l_n*88)+23] += A[119] * B[(l_n*88)+23];
    C[(l_n*88)+44] += A[120] * B[(l_n*88)+23];
    C[(l_n*88)+72] += A[121] * B[(l_n*88)+23];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b24 = _mm256_broadcast_sd(&B[(l_n*88)+24]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b24 = _mm_loaddup_pd(&B[(l_n*88)+24]);
#endif
    __m128d c24_0 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a24_0 = _mm_load_sd(&A[122]);
#if defined(__SSE3__) && defined(__AVX__)
    c24_0 = _mm_add_sd(c24_0, _mm_mul_sd(a24_0, _mm256_castpd256_pd128(b24)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c24_0 = _mm_add_sd(c24_0, _mm_mul_sd(a24_0, b24));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c24_0);
    __m128d c24_1 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a24_1 = _mm_load_sd(&A[123]);
#if defined(__SSE3__) && defined(__AVX__)
    c24_1 = _mm_add_sd(c24_1, _mm_mul_sd(a24_1, _mm256_castpd256_pd128(b24)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c24_1 = _mm_add_sd(c24_1, _mm_mul_sd(a24_1, b24));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c24_1);
    __m128d c24_2 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a24_2 = _mm_load_sd(&A[124]);
#if defined(__SSE3__) && defined(__AVX__)
    c24_2 = _mm_add_sd(c24_2, _mm_mul_sd(a24_2, _mm256_castpd256_pd128(b24)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c24_2 = _mm_add_sd(c24_2, _mm_mul_sd(a24_2, b24));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c24_2);
#else
    C[(l_n*88)+24] += A[122] * B[(l_n*88)+24];
    C[(l_n*88)+45] += A[123] * B[(l_n*88)+24];
    C[(l_n*88)+73] += A[124] * B[(l_n*88)+24];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b25 = _mm256_broadcast_sd(&B[(l_n*88)+25]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b25 = _mm_loaddup_pd(&B[(l_n*88)+25]);
#endif
    __m128d c25_0 = _mm_load_sd(&C[(l_n*88)+10]);
    __m128d a25_0 = _mm_load_sd(&A[125]);
#if defined(__SSE3__) && defined(__AVX__)
    c25_0 = _mm_add_sd(c25_0, _mm_mul_sd(a25_0, _mm256_castpd256_pd128(b25)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c25_0 = _mm_add_sd(c25_0, _mm_mul_sd(a25_0, b25));
#endif
    _mm_store_sd(&C[(l_n*88)+10], c25_0);
    __m128d c25_1 = _mm_load_sd(&C[(l_n*88)+25]);
    __m128d a25_1 = _mm_load_sd(&A[126]);
#if defined(__SSE3__) && defined(__AVX__)
    c25_1 = _mm_add_sd(c25_1, _mm_mul_sd(a25_1, _mm256_castpd256_pd128(b25)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c25_1 = _mm_add_sd(c25_1, _mm_mul_sd(a25_1, b25));
#endif
    _mm_store_sd(&C[(l_n*88)+25], c25_1);
    __m128d c25_2 = _mm_load_sd(&C[(l_n*88)+46]);
    __m128d a25_2 = _mm_load_sd(&A[127]);
#if defined(__SSE3__) && defined(__AVX__)
    c25_2 = _mm_add_sd(c25_2, _mm_mul_sd(a25_2, _mm256_castpd256_pd128(b25)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c25_2 = _mm_add_sd(c25_2, _mm_mul_sd(a25_2, b25));
#endif
    _mm_store_sd(&C[(l_n*88)+46], c25_2);
    __m128d c25_3 = _mm_load_sd(&C[(l_n*88)+74]);
    __m128d a25_3 = _mm_load_sd(&A[128]);
#if defined(__SSE3__) && defined(__AVX__)
    c25_3 = _mm_add_sd(c25_3, _mm_mul_sd(a25_3, _mm256_castpd256_pd128(b25)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c25_3 = _mm_add_sd(c25_3, _mm_mul_sd(a25_3, b25));
#endif
    _mm_store_sd(&C[(l_n*88)+74], c25_3);
#else
    C[(l_n*88)+10] += A[125] * B[(l_n*88)+25];
    C[(l_n*88)+25] += A[126] * B[(l_n*88)+25];
    C[(l_n*88)+46] += A[127] * B[(l_n*88)+25];
    C[(l_n*88)+74] += A[128] * B[(l_n*88)+25];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b26 = _mm256_broadcast_sd(&B[(l_n*88)+26]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b26 = _mm_loaddup_pd(&B[(l_n*88)+26]);
#endif
    __m128d c26_0 = _mm_load_sd(&C[(l_n*88)+11]);
    __m128d a26_0 = _mm_load_sd(&A[129]);
#if defined(__SSE3__) && defined(__AVX__)
    c26_0 = _mm_add_sd(c26_0, _mm_mul_sd(a26_0, _mm256_castpd256_pd128(b26)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c26_0 = _mm_add_sd(c26_0, _mm_mul_sd(a26_0, b26));
#endif
    _mm_store_sd(&C[(l_n*88)+11], c26_0);
    __m128d c26_1 = _mm_load_sd(&C[(l_n*88)+26]);
    __m128d a26_1 = _mm_load_sd(&A[130]);
#if defined(__SSE3__) && defined(__AVX__)
    c26_1 = _mm_add_sd(c26_1, _mm_mul_sd(a26_1, _mm256_castpd256_pd128(b26)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c26_1 = _mm_add_sd(c26_1, _mm_mul_sd(a26_1, b26));
#endif
    _mm_store_sd(&C[(l_n*88)+26], c26_1);
    __m128d c26_2 = _mm_load_sd(&C[(l_n*88)+47]);
    __m128d a26_2 = _mm_load_sd(&A[131]);
#if defined(__SSE3__) && defined(__AVX__)
    c26_2 = _mm_add_sd(c26_2, _mm_mul_sd(a26_2, _mm256_castpd256_pd128(b26)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c26_2 = _mm_add_sd(c26_2, _mm_mul_sd(a26_2, b26));
#endif
    _mm_store_sd(&C[(l_n*88)+47], c26_2);
    __m128d c26_3 = _mm_load_sd(&C[(l_n*88)+75]);
    __m128d a26_3 = _mm_load_sd(&A[132]);
#if defined(__SSE3__) && defined(__AVX__)
    c26_3 = _mm_add_sd(c26_3, _mm_mul_sd(a26_3, _mm256_castpd256_pd128(b26)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c26_3 = _mm_add_sd(c26_3, _mm_mul_sd(a26_3, b26));
#endif
    _mm_store_sd(&C[(l_n*88)+75], c26_3);
#else
    C[(l_n*88)+11] += A[129] * B[(l_n*88)+26];
    C[(l_n*88)+26] += A[130] * B[(l_n*88)+26];
    C[(l_n*88)+47] += A[131] * B[(l_n*88)+26];
    C[(l_n*88)+75] += A[132] * B[(l_n*88)+26];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b27 = _mm256_broadcast_sd(&B[(l_n*88)+27]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b27 = _mm_loaddup_pd(&B[(l_n*88)+27]);
#endif
    __m128d c27_0 = _mm_load_sd(&C[(l_n*88)+12]);
    __m128d a27_0 = _mm_load_sd(&A[133]);
#if defined(__SSE3__) && defined(__AVX__)
    c27_0 = _mm_add_sd(c27_0, _mm_mul_sd(a27_0, _mm256_castpd256_pd128(b27)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c27_0 = _mm_add_sd(c27_0, _mm_mul_sd(a27_0, b27));
#endif
    _mm_store_sd(&C[(l_n*88)+12], c27_0);
    __m128d c27_1 = _mm_load_sd(&C[(l_n*88)+27]);
    __m128d a27_1 = _mm_load_sd(&A[134]);
#if defined(__SSE3__) && defined(__AVX__)
    c27_1 = _mm_add_sd(c27_1, _mm_mul_sd(a27_1, _mm256_castpd256_pd128(b27)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c27_1 = _mm_add_sd(c27_1, _mm_mul_sd(a27_1, b27));
#endif
    _mm_store_sd(&C[(l_n*88)+27], c27_1);
    __m128d c27_2 = _mm_load_sd(&C[(l_n*88)+48]);
    __m128d a27_2 = _mm_load_sd(&A[135]);
#if defined(__SSE3__) && defined(__AVX__)
    c27_2 = _mm_add_sd(c27_2, _mm_mul_sd(a27_2, _mm256_castpd256_pd128(b27)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c27_2 = _mm_add_sd(c27_2, _mm_mul_sd(a27_2, b27));
#endif
    _mm_store_sd(&C[(l_n*88)+48], c27_2);
    __m128d c27_3 = _mm_load_sd(&C[(l_n*88)+76]);
    __m128d a27_3 = _mm_load_sd(&A[136]);
#if defined(__SSE3__) && defined(__AVX__)
    c27_3 = _mm_add_sd(c27_3, _mm_mul_sd(a27_3, _mm256_castpd256_pd128(b27)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c27_3 = _mm_add_sd(c27_3, _mm_mul_sd(a27_3, b27));
#endif
    _mm_store_sd(&C[(l_n*88)+76], c27_3);
#else
    C[(l_n*88)+12] += A[133] * B[(l_n*88)+27];
    C[(l_n*88)+27] += A[134] * B[(l_n*88)+27];
    C[(l_n*88)+48] += A[135] * B[(l_n*88)+27];
    C[(l_n*88)+76] += A[136] * B[(l_n*88)+27];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b28 = _mm256_broadcast_sd(&B[(l_n*88)+28]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b28 = _mm_loaddup_pd(&B[(l_n*88)+28]);
#endif
    __m128d c28_0 = _mm_load_sd(&C[(l_n*88)+13]);
    __m128d a28_0 = _mm_load_sd(&A[137]);
#if defined(__SSE3__) && defined(__AVX__)
    c28_0 = _mm_add_sd(c28_0, _mm_mul_sd(a28_0, _mm256_castpd256_pd128(b28)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c28_0 = _mm_add_sd(c28_0, _mm_mul_sd(a28_0, b28));
#endif
    _mm_store_sd(&C[(l_n*88)+13], c28_0);
    __m128d c28_1 = _mm_load_sd(&C[(l_n*88)+28]);
    __m128d a28_1 = _mm_load_sd(&A[138]);
#if defined(__SSE3__) && defined(__AVX__)
    c28_1 = _mm_add_sd(c28_1, _mm_mul_sd(a28_1, _mm256_castpd256_pd128(b28)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c28_1 = _mm_add_sd(c28_1, _mm_mul_sd(a28_1, b28));
#endif
    _mm_store_sd(&C[(l_n*88)+28], c28_1);
    __m128d c28_2 = _mm_load_sd(&C[(l_n*88)+49]);
    __m128d a28_2 = _mm_load_sd(&A[139]);
#if defined(__SSE3__) && defined(__AVX__)
    c28_2 = _mm_add_sd(c28_2, _mm_mul_sd(a28_2, _mm256_castpd256_pd128(b28)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c28_2 = _mm_add_sd(c28_2, _mm_mul_sd(a28_2, b28));
#endif
    _mm_store_sd(&C[(l_n*88)+49], c28_2);
    __m128d c28_3 = _mm_load_sd(&C[(l_n*88)+77]);
    __m128d a28_3 = _mm_load_sd(&A[140]);
#if defined(__SSE3__) && defined(__AVX__)
    c28_3 = _mm_add_sd(c28_3, _mm_mul_sd(a28_3, _mm256_castpd256_pd128(b28)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c28_3 = _mm_add_sd(c28_3, _mm_mul_sd(a28_3, b28));
#endif
    _mm_store_sd(&C[(l_n*88)+77], c28_3);
#else
    C[(l_n*88)+13] += A[137] * B[(l_n*88)+28];
    C[(l_n*88)+28] += A[138] * B[(l_n*88)+28];
    C[(l_n*88)+49] += A[139] * B[(l_n*88)+28];
    C[(l_n*88)+77] += A[140] * B[(l_n*88)+28];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b29 = _mm256_broadcast_sd(&B[(l_n*88)+29]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b29 = _mm_loaddup_pd(&B[(l_n*88)+29]);
#endif
    __m128d c29_0 = _mm_load_sd(&C[(l_n*88)+4]);
    __m128d a29_0 = _mm_load_sd(&A[141]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_0 = _mm_add_sd(c29_0, _mm_mul_sd(a29_0, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_0 = _mm_add_sd(c29_0, _mm_mul_sd(a29_0, b29));
#endif
    _mm_store_sd(&C[(l_n*88)+4], c29_0);
    __m128d c29_1 = _mm_load_sd(&C[(l_n*88)+14]);
    __m128d a29_1 = _mm_load_sd(&A[142]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_1 = _mm_add_sd(c29_1, _mm_mul_sd(a29_1, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_1 = _mm_add_sd(c29_1, _mm_mul_sd(a29_1, b29));
#endif
    _mm_store_sd(&C[(l_n*88)+14], c29_1);
    __m128d c29_2 = _mm_load_sd(&C[(l_n*88)+29]);
    __m128d a29_2 = _mm_load_sd(&A[143]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_2 = _mm_add_sd(c29_2, _mm_mul_sd(a29_2, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_2 = _mm_add_sd(c29_2, _mm_mul_sd(a29_2, b29));
#endif
    _mm_store_sd(&C[(l_n*88)+29], c29_2);
    __m128d c29_3 = _mm_load_sd(&C[(l_n*88)+50]);
    __m128d a29_3 = _mm_load_sd(&A[144]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_3 = _mm_add_sd(c29_3, _mm_mul_sd(a29_3, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_3 = _mm_add_sd(c29_3, _mm_mul_sd(a29_3, b29));
#endif
    _mm_store_sd(&C[(l_n*88)+50], c29_3);
    __m128d c29_4 = _mm_load_sd(&C[(l_n*88)+78]);
    __m128d a29_4 = _mm_load_sd(&A[145]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_4 = _mm_add_sd(c29_4, _mm_mul_sd(a29_4, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_4 = _mm_add_sd(c29_4, _mm_mul_sd(a29_4, b29));
#endif
    _mm_store_sd(&C[(l_n*88)+78], c29_4);
#else
    C[(l_n*88)+4] += A[141] * B[(l_n*88)+29];
    C[(l_n*88)+14] += A[142] * B[(l_n*88)+29];
    C[(l_n*88)+29] += A[143] * B[(l_n*88)+29];
    C[(l_n*88)+50] += A[144] * B[(l_n*88)+29];
    C[(l_n*88)+78] += A[145] * B[(l_n*88)+29];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b30 = _mm256_broadcast_sd(&B[(l_n*88)+30]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b30 = _mm_loaddup_pd(&B[(l_n*88)+30]);
#endif
    __m128d c30_0 = _mm_load_sd(&C[(l_n*88)+5]);
    __m128d a30_0 = _mm_load_sd(&A[146]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_0 = _mm_add_sd(c30_0, _mm_mul_sd(a30_0, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_0 = _mm_add_sd(c30_0, _mm_mul_sd(a30_0, b30));
#endif
    _mm_store_sd(&C[(l_n*88)+5], c30_0);
    __m128d c30_1 = _mm_load_sd(&C[(l_n*88)+15]);
    __m128d a30_1 = _mm_load_sd(&A[147]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_1 = _mm_add_sd(c30_1, _mm_mul_sd(a30_1, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_1 = _mm_add_sd(c30_1, _mm_mul_sd(a30_1, b30));
#endif
    _mm_store_sd(&C[(l_n*88)+15], c30_1);
    __m128d c30_2 = _mm_load_sd(&C[(l_n*88)+30]);
    __m128d a30_2 = _mm_load_sd(&A[148]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_2 = _mm_add_sd(c30_2, _mm_mul_sd(a30_2, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_2 = _mm_add_sd(c30_2, _mm_mul_sd(a30_2, b30));
#endif
    _mm_store_sd(&C[(l_n*88)+30], c30_2);
    __m128d c30_3 = _mm_load_sd(&C[(l_n*88)+51]);
    __m128d a30_3 = _mm_load_sd(&A[149]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_3 = _mm_add_sd(c30_3, _mm_mul_sd(a30_3, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_3 = _mm_add_sd(c30_3, _mm_mul_sd(a30_3, b30));
#endif
    _mm_store_sd(&C[(l_n*88)+51], c30_3);
    __m128d c30_4 = _mm_load_sd(&C[(l_n*88)+79]);
    __m128d a30_4 = _mm_load_sd(&A[150]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_4 = _mm_add_sd(c30_4, _mm_mul_sd(a30_4, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_4 = _mm_add_sd(c30_4, _mm_mul_sd(a30_4, b30));
#endif
    _mm_store_sd(&C[(l_n*88)+79], c30_4);
#else
    C[(l_n*88)+5] += A[146] * B[(l_n*88)+30];
    C[(l_n*88)+15] += A[147] * B[(l_n*88)+30];
    C[(l_n*88)+30] += A[148] * B[(l_n*88)+30];
    C[(l_n*88)+51] += A[149] * B[(l_n*88)+30];
    C[(l_n*88)+79] += A[150] * B[(l_n*88)+30];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b31 = _mm256_broadcast_sd(&B[(l_n*88)+31]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b31 = _mm_loaddup_pd(&B[(l_n*88)+31]);
#endif
    __m128d c31_0 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a31_0 = _mm_load_sd(&A[151]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_0 = _mm_add_sd(c31_0, _mm_mul_sd(a31_0, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_0 = _mm_add_sd(c31_0, _mm_mul_sd(a31_0, b31));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c31_0);
    __m128d c31_1 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a31_1 = _mm_load_sd(&A[152]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_1 = _mm_add_sd(c31_1, _mm_mul_sd(a31_1, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_1 = _mm_add_sd(c31_1, _mm_mul_sd(a31_1, b31));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c31_1);
    __m128d c31_2 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a31_2 = _mm_load_sd(&A[153]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_2 = _mm_add_sd(c31_2, _mm_mul_sd(a31_2, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_2 = _mm_add_sd(c31_2, _mm_mul_sd(a31_2, b31));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c31_2);
    __m128d c31_3 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a31_3 = _mm_load_sd(&A[154]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_3 = _mm_add_sd(c31_3, _mm_mul_sd(a31_3, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_3 = _mm_add_sd(c31_3, _mm_mul_sd(a31_3, b31));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c31_3);
    __m128d c31_4 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a31_4 = _mm_load_sd(&A[155]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_4 = _mm_add_sd(c31_4, _mm_mul_sd(a31_4, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_4 = _mm_add_sd(c31_4, _mm_mul_sd(a31_4, b31));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c31_4);
#else
    C[(l_n*88)+6] += A[151] * B[(l_n*88)+31];
    C[(l_n*88)+16] += A[152] * B[(l_n*88)+31];
    C[(l_n*88)+31] += A[153] * B[(l_n*88)+31];
    C[(l_n*88)+52] += A[154] * B[(l_n*88)+31];
    C[(l_n*88)+80] += A[155] * B[(l_n*88)+31];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b32 = _mm256_broadcast_sd(&B[(l_n*88)+32]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b32 = _mm_loaddup_pd(&B[(l_n*88)+32]);
#endif
    __m128d c32_0 = _mm_load_sd(&C[(l_n*88)+1]);
    __m128d a32_0 = _mm_load_sd(&A[156]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_0 = _mm_add_sd(c32_0, _mm_mul_sd(a32_0, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_0 = _mm_add_sd(c32_0, _mm_mul_sd(a32_0, b32));
#endif
    _mm_store_sd(&C[(l_n*88)+1], c32_0);
    __m128d c32_1 = _mm_load_sd(&C[(l_n*88)+7]);
    __m128d a32_1 = _mm_load_sd(&A[157]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_1 = _mm_add_sd(c32_1, _mm_mul_sd(a32_1, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_1 = _mm_add_sd(c32_1, _mm_mul_sd(a32_1, b32));
#endif
    _mm_store_sd(&C[(l_n*88)+7], c32_1);
    __m128d c32_2 = _mm_load_sd(&C[(l_n*88)+17]);
    __m128d a32_2 = _mm_load_sd(&A[158]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_2 = _mm_add_sd(c32_2, _mm_mul_sd(a32_2, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_2 = _mm_add_sd(c32_2, _mm_mul_sd(a32_2, b32));
#endif
    _mm_store_sd(&C[(l_n*88)+17], c32_2);
    __m128d c32_3 = _mm_load_sd(&C[(l_n*88)+32]);
    __m128d a32_3 = _mm_load_sd(&A[159]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_3 = _mm_add_sd(c32_3, _mm_mul_sd(a32_3, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_3 = _mm_add_sd(c32_3, _mm_mul_sd(a32_3, b32));
#endif
    _mm_store_sd(&C[(l_n*88)+32], c32_3);
    __m128d c32_4 = _mm_load_sd(&C[(l_n*88)+53]);
    __m128d a32_4 = _mm_load_sd(&A[160]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_4 = _mm_add_sd(c32_4, _mm_mul_sd(a32_4, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_4 = _mm_add_sd(c32_4, _mm_mul_sd(a32_4, b32));
#endif
    _mm_store_sd(&C[(l_n*88)+53], c32_4);
    __m128d c32_5 = _mm_load_sd(&C[(l_n*88)+81]);
    __m128d a32_5 = _mm_load_sd(&A[161]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_5 = _mm_add_sd(c32_5, _mm_mul_sd(a32_5, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_5 = _mm_add_sd(c32_5, _mm_mul_sd(a32_5, b32));
#endif
    _mm_store_sd(&C[(l_n*88)+81], c32_5);
#else
    C[(l_n*88)+1] += A[156] * B[(l_n*88)+32];
    C[(l_n*88)+7] += A[157] * B[(l_n*88)+32];
    C[(l_n*88)+17] += A[158] * B[(l_n*88)+32];
    C[(l_n*88)+32] += A[159] * B[(l_n*88)+32];
    C[(l_n*88)+53] += A[160] * B[(l_n*88)+32];
    C[(l_n*88)+81] += A[161] * B[(l_n*88)+32];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b33 = _mm256_broadcast_sd(&B[(l_n*88)+33]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b33 = _mm_loaddup_pd(&B[(l_n*88)+33]);
#endif
    __m128d c33_0 = _mm_load_sd(&C[(l_n*88)+2]);
    __m128d a33_0 = _mm_load_sd(&A[162]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_0 = _mm_add_sd(c33_0, _mm_mul_sd(a33_0, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_0 = _mm_add_sd(c33_0, _mm_mul_sd(a33_0, b33));
#endif
    _mm_store_sd(&C[(l_n*88)+2], c33_0);
    __m128d c33_1 = _mm_load_sd(&C[(l_n*88)+8]);
    __m128d a33_1 = _mm_load_sd(&A[163]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_1 = _mm_add_sd(c33_1, _mm_mul_sd(a33_1, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_1 = _mm_add_sd(c33_1, _mm_mul_sd(a33_1, b33));
#endif
    _mm_store_sd(&C[(l_n*88)+8], c33_1);
    __m128d c33_2 = _mm_load_sd(&C[(l_n*88)+18]);
    __m128d a33_2 = _mm_load_sd(&A[164]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_2 = _mm_add_sd(c33_2, _mm_mul_sd(a33_2, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_2 = _mm_add_sd(c33_2, _mm_mul_sd(a33_2, b33));
#endif
    _mm_store_sd(&C[(l_n*88)+18], c33_2);
    __m128d c33_3 = _mm_load_sd(&C[(l_n*88)+33]);
    __m128d a33_3 = _mm_load_sd(&A[165]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_3 = _mm_add_sd(c33_3, _mm_mul_sd(a33_3, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_3 = _mm_add_sd(c33_3, _mm_mul_sd(a33_3, b33));
#endif
    _mm_store_sd(&C[(l_n*88)+33], c33_3);
    __m128d c33_4 = _mm_load_sd(&C[(l_n*88)+54]);
    __m128d a33_4 = _mm_load_sd(&A[166]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_4 = _mm_add_sd(c33_4, _mm_mul_sd(a33_4, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_4 = _mm_add_sd(c33_4, _mm_mul_sd(a33_4, b33));
#endif
    _mm_store_sd(&C[(l_n*88)+54], c33_4);
    __m128d c33_5 = _mm_load_sd(&C[(l_n*88)+82]);
    __m128d a33_5 = _mm_load_sd(&A[167]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_5 = _mm_add_sd(c33_5, _mm_mul_sd(a33_5, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_5 = _mm_add_sd(c33_5, _mm_mul_sd(a33_5, b33));
#endif
    _mm_store_sd(&C[(l_n*88)+82], c33_5);
#else
    C[(l_n*88)+2] += A[162] * B[(l_n*88)+33];
    C[(l_n*88)+8] += A[163] * B[(l_n*88)+33];
    C[(l_n*88)+18] += A[164] * B[(l_n*88)+33];
    C[(l_n*88)+33] += A[165] * B[(l_n*88)+33];
    C[(l_n*88)+54] += A[166] * B[(l_n*88)+33];
    C[(l_n*88)+82] += A[167] * B[(l_n*88)+33];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b34 = _mm256_broadcast_sd(&B[(l_n*88)+34]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b34 = _mm_loaddup_pd(&B[(l_n*88)+34]);
#endif
    __m128d c34_0 = _mm_load_sd(&C[(l_n*88)+0]);
    __m128d a34_0 = _mm_load_sd(&A[168]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_0 = _mm_add_sd(c34_0, _mm_mul_sd(a34_0, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_0 = _mm_add_sd(c34_0, _mm_mul_sd(a34_0, b34));
#endif
    _mm_store_sd(&C[(l_n*88)+0], c34_0);
    __m128d c34_1 = _mm_load_sd(&C[(l_n*88)+3]);
    __m128d a34_1 = _mm_load_sd(&A[169]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_1 = _mm_add_sd(c34_1, _mm_mul_sd(a34_1, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_1 = _mm_add_sd(c34_1, _mm_mul_sd(a34_1, b34));
#endif
    _mm_store_sd(&C[(l_n*88)+3], c34_1);
    __m128d c34_2 = _mm_load_sd(&C[(l_n*88)+9]);
    __m128d a34_2 = _mm_load_sd(&A[170]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_2 = _mm_add_sd(c34_2, _mm_mul_sd(a34_2, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_2 = _mm_add_sd(c34_2, _mm_mul_sd(a34_2, b34));
#endif
    _mm_store_sd(&C[(l_n*88)+9], c34_2);
    __m128d c34_3 = _mm_load_sd(&C[(l_n*88)+19]);
    __m128d a34_3 = _mm_load_sd(&A[171]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_3 = _mm_add_sd(c34_3, _mm_mul_sd(a34_3, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_3 = _mm_add_sd(c34_3, _mm_mul_sd(a34_3, b34));
#endif
    _mm_store_sd(&C[(l_n*88)+19], c34_3);
    __m128d c34_4 = _mm_load_sd(&C[(l_n*88)+34]);
    __m128d a34_4 = _mm_load_sd(&A[172]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_4 = _mm_add_sd(c34_4, _mm_mul_sd(a34_4, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_4 = _mm_add_sd(c34_4, _mm_mul_sd(a34_4, b34));
#endif
    _mm_store_sd(&C[(l_n*88)+34], c34_4);
    __m128d c34_5 = _mm_load_sd(&C[(l_n*88)+55]);
    __m128d a34_5 = _mm_load_sd(&A[173]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_5 = _mm_add_sd(c34_5, _mm_mul_sd(a34_5, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_5 = _mm_add_sd(c34_5, _mm_mul_sd(a34_5, b34));
#endif
    _mm_store_sd(&C[(l_n*88)+55], c34_5);
    __m128d c34_6 = _mm_load_sd(&C[(l_n*88)+83]);
    __m128d a34_6 = _mm_load_sd(&A[174]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_6 = _mm_add_sd(c34_6, _mm_mul_sd(a34_6, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_6 = _mm_add_sd(c34_6, _mm_mul_sd(a34_6, b34));
#endif
    _mm_store_sd(&C[(l_n*88)+83], c34_6);
#else
    C[(l_n*88)+0] += A[168] * B[(l_n*88)+34];
    C[(l_n*88)+3] += A[169] * B[(l_n*88)+34];
    C[(l_n*88)+9] += A[170] * B[(l_n*88)+34];
    C[(l_n*88)+19] += A[171] * B[(l_n*88)+34];
    C[(l_n*88)+34] += A[172] * B[(l_n*88)+34];
    C[(l_n*88)+55] += A[173] * B[(l_n*88)+34];
    C[(l_n*88)+83] += A[174] * B[(l_n*88)+34];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b35 = _mm256_broadcast_sd(&B[(l_n*88)+35]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b35 = _mm_loaddup_pd(&B[(l_n*88)+35]);
#endif
    __m128d c35_0 = _mm_load_sd(&C[(l_n*88)+35]);
    __m128d a35_0 = _mm_load_sd(&A[175]);
#if defined(__SSE3__) && defined(__AVX__)
    c35_0 = _mm_add_sd(c35_0, _mm_mul_sd(a35_0, _mm256_castpd256_pd128(b35)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c35_0 = _mm_add_sd(c35_0, _mm_mul_sd(a35_0, b35));
#endif
    _mm_store_sd(&C[(l_n*88)+35], c35_0);
    __m128d c35_1 = _mm_load_sd(&C[(l_n*88)+63]);
    __m128d a35_1 = _mm_load_sd(&A[176]);
#if defined(__SSE3__) && defined(__AVX__)
    c35_1 = _mm_add_sd(c35_1, _mm_mul_sd(a35_1, _mm256_castpd256_pd128(b35)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c35_1 = _mm_add_sd(c35_1, _mm_mul_sd(a35_1, b35));
#endif
    _mm_store_sd(&C[(l_n*88)+63], c35_1);
#else
    C[(l_n*88)+35] += A[175] * B[(l_n*88)+35];
    C[(l_n*88)+63] += A[176] * B[(l_n*88)+35];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b36 = _mm256_broadcast_sd(&B[(l_n*88)+36]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b36 = _mm_loaddup_pd(&B[(l_n*88)+36]);
#endif
    __m128d c36_0 = _mm_load_sd(&C[(l_n*88)+36]);
    __m128d a36_0 = _mm_load_sd(&A[177]);
#if defined(__SSE3__) && defined(__AVX__)
    c36_0 = _mm_add_sd(c36_0, _mm_mul_sd(a36_0, _mm256_castpd256_pd128(b36)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c36_0 = _mm_add_sd(c36_0, _mm_mul_sd(a36_0, b36));
#endif
    _mm_store_sd(&C[(l_n*88)+36], c36_0);
    __m128d c36_1 = _mm_load_sd(&C[(l_n*88)+64]);
    __m128d a36_1 = _mm_load_sd(&A[178]);
#if defined(__SSE3__) && defined(__AVX__)
    c36_1 = _mm_add_sd(c36_1, _mm_mul_sd(a36_1, _mm256_castpd256_pd128(b36)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c36_1 = _mm_add_sd(c36_1, _mm_mul_sd(a36_1, b36));
#endif
    _mm_store_sd(&C[(l_n*88)+64], c36_1);
#else
    C[(l_n*88)+36] += A[177] * B[(l_n*88)+36];
    C[(l_n*88)+64] += A[178] * B[(l_n*88)+36];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b37 = _mm256_broadcast_sd(&B[(l_n*88)+37]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b37 = _mm_loaddup_pd(&B[(l_n*88)+37]);
#endif
    __m128d c37_0 = _mm_load_sd(&C[(l_n*88)+37]);
    __m128d a37_0 = _mm_load_sd(&A[179]);
#if defined(__SSE3__) && defined(__AVX__)
    c37_0 = _mm_add_sd(c37_0, _mm_mul_sd(a37_0, _mm256_castpd256_pd128(b37)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c37_0 = _mm_add_sd(c37_0, _mm_mul_sd(a37_0, b37));
#endif
    _mm_store_sd(&C[(l_n*88)+37], c37_0);
    __m128d c37_1 = _mm_load_sd(&C[(l_n*88)+65]);
    __m128d a37_1 = _mm_load_sd(&A[180]);
#if defined(__SSE3__) && defined(__AVX__)
    c37_1 = _mm_add_sd(c37_1, _mm_mul_sd(a37_1, _mm256_castpd256_pd128(b37)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c37_1 = _mm_add_sd(c37_1, _mm_mul_sd(a37_1, b37));
#endif
    _mm_store_sd(&C[(l_n*88)+65], c37_1);
#else
    C[(l_n*88)+37] += A[179] * B[(l_n*88)+37];
    C[(l_n*88)+65] += A[180] * B[(l_n*88)+37];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b38 = _mm256_broadcast_sd(&B[(l_n*88)+38]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b38 = _mm_loaddup_pd(&B[(l_n*88)+38]);
#endif
    __m128d c38_0 = _mm_load_sd(&C[(l_n*88)+38]);
    __m128d a38_0 = _mm_load_sd(&A[181]);
#if defined(__SSE3__) && defined(__AVX__)
    c38_0 = _mm_add_sd(c38_0, _mm_mul_sd(a38_0, _mm256_castpd256_pd128(b38)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c38_0 = _mm_add_sd(c38_0, _mm_mul_sd(a38_0, b38));
#endif
    _mm_store_sd(&C[(l_n*88)+38], c38_0);
    __m128d c38_1 = _mm_load_sd(&C[(l_n*88)+66]);
    __m128d a38_1 = _mm_load_sd(&A[182]);
#if defined(__SSE3__) && defined(__AVX__)
    c38_1 = _mm_add_sd(c38_1, _mm_mul_sd(a38_1, _mm256_castpd256_pd128(b38)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c38_1 = _mm_add_sd(c38_1, _mm_mul_sd(a38_1, b38));
#endif
    _mm_store_sd(&C[(l_n*88)+66], c38_1);
#else
    C[(l_n*88)+38] += A[181] * B[(l_n*88)+38];
    C[(l_n*88)+66] += A[182] * B[(l_n*88)+38];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b39 = _mm256_broadcast_sd(&B[(l_n*88)+39]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b39 = _mm_loaddup_pd(&B[(l_n*88)+39]);
#endif
    __m128d c39_0 = _mm_load_sd(&C[(l_n*88)+39]);
    __m128d a39_0 = _mm_load_sd(&A[183]);
#if defined(__SSE3__) && defined(__AVX__)
    c39_0 = _mm_add_sd(c39_0, _mm_mul_sd(a39_0, _mm256_castpd256_pd128(b39)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c39_0 = _mm_add_sd(c39_0, _mm_mul_sd(a39_0, b39));
#endif
    _mm_store_sd(&C[(l_n*88)+39], c39_0);
    __m128d c39_1 = _mm_load_sd(&C[(l_n*88)+67]);
    __m128d a39_1 = _mm_load_sd(&A[184]);
#if defined(__SSE3__) && defined(__AVX__)
    c39_1 = _mm_add_sd(c39_1, _mm_mul_sd(a39_1, _mm256_castpd256_pd128(b39)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c39_1 = _mm_add_sd(c39_1, _mm_mul_sd(a39_1, b39));
#endif
    _mm_store_sd(&C[(l_n*88)+67], c39_1);
#else
    C[(l_n*88)+39] += A[183] * B[(l_n*88)+39];
    C[(l_n*88)+67] += A[184] * B[(l_n*88)+39];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b40 = _mm256_broadcast_sd(&B[(l_n*88)+40]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b40 = _mm_loaddup_pd(&B[(l_n*88)+40]);
#endif
    __m128d c40_0 = _mm_load_sd(&C[(l_n*88)+40]);
    __m128d a40_0 = _mm_load_sd(&A[185]);
#if defined(__SSE3__) && defined(__AVX__)
    c40_0 = _mm_add_sd(c40_0, _mm_mul_sd(a40_0, _mm256_castpd256_pd128(b40)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c40_0 = _mm_add_sd(c40_0, _mm_mul_sd(a40_0, b40));
#endif
    _mm_store_sd(&C[(l_n*88)+40], c40_0);
    __m128d c40_1 = _mm_load_sd(&C[(l_n*88)+68]);
    __m128d a40_1 = _mm_load_sd(&A[186]);
#if defined(__SSE3__) && defined(__AVX__)
    c40_1 = _mm_add_sd(c40_1, _mm_mul_sd(a40_1, _mm256_castpd256_pd128(b40)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c40_1 = _mm_add_sd(c40_1, _mm_mul_sd(a40_1, b40));
#endif
    _mm_store_sd(&C[(l_n*88)+68], c40_1);
#else
    C[(l_n*88)+40] += A[185] * B[(l_n*88)+40];
    C[(l_n*88)+68] += A[186] * B[(l_n*88)+40];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b41 = _mm256_broadcast_sd(&B[(l_n*88)+41]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b41 = _mm_loaddup_pd(&B[(l_n*88)+41]);
#endif
    __m128d c41_0 = _mm_load_sd(&C[(l_n*88)+20]);
    __m128d a41_0 = _mm_load_sd(&A[187]);
#if defined(__SSE3__) && defined(__AVX__)
    c41_0 = _mm_add_sd(c41_0, _mm_mul_sd(a41_0, _mm256_castpd256_pd128(b41)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c41_0 = _mm_add_sd(c41_0, _mm_mul_sd(a41_0, b41));
#endif
    _mm_store_sd(&C[(l_n*88)+20], c41_0);
    __m128d c41_1 = _mm_load_sd(&C[(l_n*88)+41]);
    __m128d a41_1 = _mm_load_sd(&A[188]);
#if defined(__SSE3__) && defined(__AVX__)
    c41_1 = _mm_add_sd(c41_1, _mm_mul_sd(a41_1, _mm256_castpd256_pd128(b41)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c41_1 = _mm_add_sd(c41_1, _mm_mul_sd(a41_1, b41));
#endif
    _mm_store_sd(&C[(l_n*88)+41], c41_1);
    __m128d c41_2 = _mm_load_sd(&C[(l_n*88)+69]);
    __m128d a41_2 = _mm_load_sd(&A[189]);
#if defined(__SSE3__) && defined(__AVX__)
    c41_2 = _mm_add_sd(c41_2, _mm_mul_sd(a41_2, _mm256_castpd256_pd128(b41)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c41_2 = _mm_add_sd(c41_2, _mm_mul_sd(a41_2, b41));
#endif
    _mm_store_sd(&C[(l_n*88)+69], c41_2);
#else
    C[(l_n*88)+20] += A[187] * B[(l_n*88)+41];
    C[(l_n*88)+41] += A[188] * B[(l_n*88)+41];
    C[(l_n*88)+69] += A[189] * B[(l_n*88)+41];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b42 = _mm256_broadcast_sd(&B[(l_n*88)+42]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b42 = _mm_loaddup_pd(&B[(l_n*88)+42]);
#endif
    __m128d c42_0 = _mm_load_sd(&C[(l_n*88)+21]);
    __m128d a42_0 = _mm_load_sd(&A[190]);
#if defined(__SSE3__) && defined(__AVX__)
    c42_0 = _mm_add_sd(c42_0, _mm_mul_sd(a42_0, _mm256_castpd256_pd128(b42)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c42_0 = _mm_add_sd(c42_0, _mm_mul_sd(a42_0, b42));
#endif
    _mm_store_sd(&C[(l_n*88)+21], c42_0);
    __m128d c42_1 = _mm_load_sd(&C[(l_n*88)+42]);
    __m128d a42_1 = _mm_load_sd(&A[191]);
#if defined(__SSE3__) && defined(__AVX__)
    c42_1 = _mm_add_sd(c42_1, _mm_mul_sd(a42_1, _mm256_castpd256_pd128(b42)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c42_1 = _mm_add_sd(c42_1, _mm_mul_sd(a42_1, b42));
#endif
    _mm_store_sd(&C[(l_n*88)+42], c42_1);
    __m128d c42_2 = _mm_load_sd(&C[(l_n*88)+70]);
    __m128d a42_2 = _mm_load_sd(&A[192]);
#if defined(__SSE3__) && defined(__AVX__)
    c42_2 = _mm_add_sd(c42_2, _mm_mul_sd(a42_2, _mm256_castpd256_pd128(b42)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c42_2 = _mm_add_sd(c42_2, _mm_mul_sd(a42_2, b42));
#endif
    _mm_store_sd(&C[(l_n*88)+70], c42_2);
#else
    C[(l_n*88)+21] += A[190] * B[(l_n*88)+42];
    C[(l_n*88)+42] += A[191] * B[(l_n*88)+42];
    C[(l_n*88)+70] += A[192] * B[(l_n*88)+42];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b43 = _mm256_broadcast_sd(&B[(l_n*88)+43]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b43 = _mm_loaddup_pd(&B[(l_n*88)+43]);
#endif
    __m128d c43_0 = _mm_load_sd(&C[(l_n*88)+22]);
    __m128d a43_0 = _mm_load_sd(&A[193]);
#if defined(__SSE3__) && defined(__AVX__)
    c43_0 = _mm_add_sd(c43_0, _mm_mul_sd(a43_0, _mm256_castpd256_pd128(b43)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c43_0 = _mm_add_sd(c43_0, _mm_mul_sd(a43_0, b43));
#endif
    _mm_store_sd(&C[(l_n*88)+22], c43_0);
    __m128d c43_1 = _mm_load_sd(&C[(l_n*88)+43]);
    __m128d a43_1 = _mm_load_sd(&A[194]);
#if defined(__SSE3__) && defined(__AVX__)
    c43_1 = _mm_add_sd(c43_1, _mm_mul_sd(a43_1, _mm256_castpd256_pd128(b43)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c43_1 = _mm_add_sd(c43_1, _mm_mul_sd(a43_1, b43));
#endif
    _mm_store_sd(&C[(l_n*88)+43], c43_1);
    __m128d c43_2 = _mm_load_sd(&C[(l_n*88)+71]);
    __m128d a43_2 = _mm_load_sd(&A[195]);
#if defined(__SSE3__) && defined(__AVX__)
    c43_2 = _mm_add_sd(c43_2, _mm_mul_sd(a43_2, _mm256_castpd256_pd128(b43)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c43_2 = _mm_add_sd(c43_2, _mm_mul_sd(a43_2, b43));
#endif
    _mm_store_sd(&C[(l_n*88)+71], c43_2);
#else
    C[(l_n*88)+22] += A[193] * B[(l_n*88)+43];
    C[(l_n*88)+43] += A[194] * B[(l_n*88)+43];
    C[(l_n*88)+71] += A[195] * B[(l_n*88)+43];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b44 = _mm256_broadcast_sd(&B[(l_n*88)+44]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b44 = _mm_loaddup_pd(&B[(l_n*88)+44]);
#endif
    __m128d c44_0 = _mm_load_sd(&C[(l_n*88)+23]);
    __m128d a44_0 = _mm_load_sd(&A[196]);
#if defined(__SSE3__) && defined(__AVX__)
    c44_0 = _mm_add_sd(c44_0, _mm_mul_sd(a44_0, _mm256_castpd256_pd128(b44)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c44_0 = _mm_add_sd(c44_0, _mm_mul_sd(a44_0, b44));
#endif
    _mm_store_sd(&C[(l_n*88)+23], c44_0);
    __m128d c44_1 = _mm_load_sd(&C[(l_n*88)+44]);
    __m128d a44_1 = _mm_load_sd(&A[197]);
#if defined(__SSE3__) && defined(__AVX__)
    c44_1 = _mm_add_sd(c44_1, _mm_mul_sd(a44_1, _mm256_castpd256_pd128(b44)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c44_1 = _mm_add_sd(c44_1, _mm_mul_sd(a44_1, b44));
#endif
    _mm_store_sd(&C[(l_n*88)+44], c44_1);
    __m128d c44_2 = _mm_load_sd(&C[(l_n*88)+72]);
    __m128d a44_2 = _mm_load_sd(&A[198]);
#if defined(__SSE3__) && defined(__AVX__)
    c44_2 = _mm_add_sd(c44_2, _mm_mul_sd(a44_2, _mm256_castpd256_pd128(b44)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c44_2 = _mm_add_sd(c44_2, _mm_mul_sd(a44_2, b44));
#endif
    _mm_store_sd(&C[(l_n*88)+72], c44_2);
#else
    C[(l_n*88)+23] += A[196] * B[(l_n*88)+44];
    C[(l_n*88)+44] += A[197] * B[(l_n*88)+44];
    C[(l_n*88)+72] += A[198] * B[(l_n*88)+44];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b45 = _mm256_broadcast_sd(&B[(l_n*88)+45]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b45 = _mm_loaddup_pd(&B[(l_n*88)+45]);
#endif
    __m128d c45_0 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a45_0 = _mm_load_sd(&A[199]);
#if defined(__SSE3__) && defined(__AVX__)
    c45_0 = _mm_add_sd(c45_0, _mm_mul_sd(a45_0, _mm256_castpd256_pd128(b45)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c45_0 = _mm_add_sd(c45_0, _mm_mul_sd(a45_0, b45));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c45_0);
    __m128d c45_1 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a45_1 = _mm_load_sd(&A[200]);
#if defined(__SSE3__) && defined(__AVX__)
    c45_1 = _mm_add_sd(c45_1, _mm_mul_sd(a45_1, _mm256_castpd256_pd128(b45)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c45_1 = _mm_add_sd(c45_1, _mm_mul_sd(a45_1, b45));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c45_1);
    __m128d c45_2 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a45_2 = _mm_load_sd(&A[201]);
#if defined(__SSE3__) && defined(__AVX__)
    c45_2 = _mm_add_sd(c45_2, _mm_mul_sd(a45_2, _mm256_castpd256_pd128(b45)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c45_2 = _mm_add_sd(c45_2, _mm_mul_sd(a45_2, b45));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c45_2);
#else
    C[(l_n*88)+24] += A[199] * B[(l_n*88)+45];
    C[(l_n*88)+45] += A[200] * B[(l_n*88)+45];
    C[(l_n*88)+73] += A[201] * B[(l_n*88)+45];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b46 = _mm256_broadcast_sd(&B[(l_n*88)+46]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b46 = _mm_loaddup_pd(&B[(l_n*88)+46]);
#endif
    __m128d c46_0 = _mm_load_sd(&C[(l_n*88)+10]);
    __m128d a46_0 = _mm_load_sd(&A[202]);
#if defined(__SSE3__) && defined(__AVX__)
    c46_0 = _mm_add_sd(c46_0, _mm_mul_sd(a46_0, _mm256_castpd256_pd128(b46)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c46_0 = _mm_add_sd(c46_0, _mm_mul_sd(a46_0, b46));
#endif
    _mm_store_sd(&C[(l_n*88)+10], c46_0);
    __m128d c46_1 = _mm_load_sd(&C[(l_n*88)+25]);
    __m128d a46_1 = _mm_load_sd(&A[203]);
#if defined(__SSE3__) && defined(__AVX__)
    c46_1 = _mm_add_sd(c46_1, _mm_mul_sd(a46_1, _mm256_castpd256_pd128(b46)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c46_1 = _mm_add_sd(c46_1, _mm_mul_sd(a46_1, b46));
#endif
    _mm_store_sd(&C[(l_n*88)+25], c46_1);
    __m128d c46_2 = _mm_load_sd(&C[(l_n*88)+46]);
    __m128d a46_2 = _mm_load_sd(&A[204]);
#if defined(__SSE3__) && defined(__AVX__)
    c46_2 = _mm_add_sd(c46_2, _mm_mul_sd(a46_2, _mm256_castpd256_pd128(b46)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c46_2 = _mm_add_sd(c46_2, _mm_mul_sd(a46_2, b46));
#endif
    _mm_store_sd(&C[(l_n*88)+46], c46_2);
    __m128d c46_3 = _mm_load_sd(&C[(l_n*88)+74]);
    __m128d a46_3 = _mm_load_sd(&A[205]);
#if defined(__SSE3__) && defined(__AVX__)
    c46_3 = _mm_add_sd(c46_3, _mm_mul_sd(a46_3, _mm256_castpd256_pd128(b46)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c46_3 = _mm_add_sd(c46_3, _mm_mul_sd(a46_3, b46));
#endif
    _mm_store_sd(&C[(l_n*88)+74], c46_3);
#else
    C[(l_n*88)+10] += A[202] * B[(l_n*88)+46];
    C[(l_n*88)+25] += A[203] * B[(l_n*88)+46];
    C[(l_n*88)+46] += A[204] * B[(l_n*88)+46];
    C[(l_n*88)+74] += A[205] * B[(l_n*88)+46];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b47 = _mm256_broadcast_sd(&B[(l_n*88)+47]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b47 = _mm_loaddup_pd(&B[(l_n*88)+47]);
#endif
    __m128d c47_0 = _mm_load_sd(&C[(l_n*88)+11]);
    __m128d a47_0 = _mm_load_sd(&A[206]);
#if defined(__SSE3__) && defined(__AVX__)
    c47_0 = _mm_add_sd(c47_0, _mm_mul_sd(a47_0, _mm256_castpd256_pd128(b47)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c47_0 = _mm_add_sd(c47_0, _mm_mul_sd(a47_0, b47));
#endif
    _mm_store_sd(&C[(l_n*88)+11], c47_0);
    __m128d c47_1 = _mm_load_sd(&C[(l_n*88)+26]);
    __m128d a47_1 = _mm_load_sd(&A[207]);
#if defined(__SSE3__) && defined(__AVX__)
    c47_1 = _mm_add_sd(c47_1, _mm_mul_sd(a47_1, _mm256_castpd256_pd128(b47)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c47_1 = _mm_add_sd(c47_1, _mm_mul_sd(a47_1, b47));
#endif
    _mm_store_sd(&C[(l_n*88)+26], c47_1);
    __m128d c47_2 = _mm_load_sd(&C[(l_n*88)+47]);
    __m128d a47_2 = _mm_load_sd(&A[208]);
#if defined(__SSE3__) && defined(__AVX__)
    c47_2 = _mm_add_sd(c47_2, _mm_mul_sd(a47_2, _mm256_castpd256_pd128(b47)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c47_2 = _mm_add_sd(c47_2, _mm_mul_sd(a47_2, b47));
#endif
    _mm_store_sd(&C[(l_n*88)+47], c47_2);
    __m128d c47_3 = _mm_load_sd(&C[(l_n*88)+75]);
    __m128d a47_3 = _mm_load_sd(&A[209]);
#if defined(__SSE3__) && defined(__AVX__)
    c47_3 = _mm_add_sd(c47_3, _mm_mul_sd(a47_3, _mm256_castpd256_pd128(b47)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c47_3 = _mm_add_sd(c47_3, _mm_mul_sd(a47_3, b47));
#endif
    _mm_store_sd(&C[(l_n*88)+75], c47_3);
#else
    C[(l_n*88)+11] += A[206] * B[(l_n*88)+47];
    C[(l_n*88)+26] += A[207] * B[(l_n*88)+47];
    C[(l_n*88)+47] += A[208] * B[(l_n*88)+47];
    C[(l_n*88)+75] += A[209] * B[(l_n*88)+47];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b48 = _mm256_broadcast_sd(&B[(l_n*88)+48]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b48 = _mm_loaddup_pd(&B[(l_n*88)+48]);
#endif
    __m128d c48_0 = _mm_load_sd(&C[(l_n*88)+12]);
    __m128d a48_0 = _mm_load_sd(&A[210]);
#if defined(__SSE3__) && defined(__AVX__)
    c48_0 = _mm_add_sd(c48_0, _mm_mul_sd(a48_0, _mm256_castpd256_pd128(b48)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c48_0 = _mm_add_sd(c48_0, _mm_mul_sd(a48_0, b48));
#endif
    _mm_store_sd(&C[(l_n*88)+12], c48_0);
    __m128d c48_1 = _mm_load_sd(&C[(l_n*88)+27]);
    __m128d a48_1 = _mm_load_sd(&A[211]);
#if defined(__SSE3__) && defined(__AVX__)
    c48_1 = _mm_add_sd(c48_1, _mm_mul_sd(a48_1, _mm256_castpd256_pd128(b48)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c48_1 = _mm_add_sd(c48_1, _mm_mul_sd(a48_1, b48));
#endif
    _mm_store_sd(&C[(l_n*88)+27], c48_1);
    __m128d c48_2 = _mm_load_sd(&C[(l_n*88)+48]);
    __m128d a48_2 = _mm_load_sd(&A[212]);
#if defined(__SSE3__) && defined(__AVX__)
    c48_2 = _mm_add_sd(c48_2, _mm_mul_sd(a48_2, _mm256_castpd256_pd128(b48)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c48_2 = _mm_add_sd(c48_2, _mm_mul_sd(a48_2, b48));
#endif
    _mm_store_sd(&C[(l_n*88)+48], c48_2);
    __m128d c48_3 = _mm_load_sd(&C[(l_n*88)+76]);
    __m128d a48_3 = _mm_load_sd(&A[213]);
#if defined(__SSE3__) && defined(__AVX__)
    c48_3 = _mm_add_sd(c48_3, _mm_mul_sd(a48_3, _mm256_castpd256_pd128(b48)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c48_3 = _mm_add_sd(c48_3, _mm_mul_sd(a48_3, b48));
#endif
    _mm_store_sd(&C[(l_n*88)+76], c48_3);
#else
    C[(l_n*88)+12] += A[210] * B[(l_n*88)+48];
    C[(l_n*88)+27] += A[211] * B[(l_n*88)+48];
    C[(l_n*88)+48] += A[212] * B[(l_n*88)+48];
    C[(l_n*88)+76] += A[213] * B[(l_n*88)+48];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b49 = _mm256_broadcast_sd(&B[(l_n*88)+49]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b49 = _mm_loaddup_pd(&B[(l_n*88)+49]);
#endif
    __m128d c49_0 = _mm_load_sd(&C[(l_n*88)+13]);
    __m128d a49_0 = _mm_load_sd(&A[214]);
#if defined(__SSE3__) && defined(__AVX__)
    c49_0 = _mm_add_sd(c49_0, _mm_mul_sd(a49_0, _mm256_castpd256_pd128(b49)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c49_0 = _mm_add_sd(c49_0, _mm_mul_sd(a49_0, b49));
#endif
    _mm_store_sd(&C[(l_n*88)+13], c49_0);
    __m128d c49_1 = _mm_load_sd(&C[(l_n*88)+28]);
    __m128d a49_1 = _mm_load_sd(&A[215]);
#if defined(__SSE3__) && defined(__AVX__)
    c49_1 = _mm_add_sd(c49_1, _mm_mul_sd(a49_1, _mm256_castpd256_pd128(b49)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c49_1 = _mm_add_sd(c49_1, _mm_mul_sd(a49_1, b49));
#endif
    _mm_store_sd(&C[(l_n*88)+28], c49_1);
    __m128d c49_2 = _mm_load_sd(&C[(l_n*88)+49]);
    __m128d a49_2 = _mm_load_sd(&A[216]);
#if defined(__SSE3__) && defined(__AVX__)
    c49_2 = _mm_add_sd(c49_2, _mm_mul_sd(a49_2, _mm256_castpd256_pd128(b49)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c49_2 = _mm_add_sd(c49_2, _mm_mul_sd(a49_2, b49));
#endif
    _mm_store_sd(&C[(l_n*88)+49], c49_2);
    __m128d c49_3 = _mm_load_sd(&C[(l_n*88)+77]);
    __m128d a49_3 = _mm_load_sd(&A[217]);
#if defined(__SSE3__) && defined(__AVX__)
    c49_3 = _mm_add_sd(c49_3, _mm_mul_sd(a49_3, _mm256_castpd256_pd128(b49)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c49_3 = _mm_add_sd(c49_3, _mm_mul_sd(a49_3, b49));
#endif
    _mm_store_sd(&C[(l_n*88)+77], c49_3);
#else
    C[(l_n*88)+13] += A[214] * B[(l_n*88)+49];
    C[(l_n*88)+28] += A[215] * B[(l_n*88)+49];
    C[(l_n*88)+49] += A[216] * B[(l_n*88)+49];
    C[(l_n*88)+77] += A[217] * B[(l_n*88)+49];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b50 = _mm256_broadcast_sd(&B[(l_n*88)+50]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b50 = _mm_loaddup_pd(&B[(l_n*88)+50]);
#endif
    __m128d c50_0 = _mm_load_sd(&C[(l_n*88)+4]);
    __m128d a50_0 = _mm_load_sd(&A[218]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_0 = _mm_add_sd(c50_0, _mm_mul_sd(a50_0, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_0 = _mm_add_sd(c50_0, _mm_mul_sd(a50_0, b50));
#endif
    _mm_store_sd(&C[(l_n*88)+4], c50_0);
    __m128d c50_1 = _mm_load_sd(&C[(l_n*88)+14]);
    __m128d a50_1 = _mm_load_sd(&A[219]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_1 = _mm_add_sd(c50_1, _mm_mul_sd(a50_1, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_1 = _mm_add_sd(c50_1, _mm_mul_sd(a50_1, b50));
#endif
    _mm_store_sd(&C[(l_n*88)+14], c50_1);
    __m128d c50_2 = _mm_load_sd(&C[(l_n*88)+29]);
    __m128d a50_2 = _mm_load_sd(&A[220]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_2 = _mm_add_sd(c50_2, _mm_mul_sd(a50_2, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_2 = _mm_add_sd(c50_2, _mm_mul_sd(a50_2, b50));
#endif
    _mm_store_sd(&C[(l_n*88)+29], c50_2);
    __m128d c50_3 = _mm_load_sd(&C[(l_n*88)+50]);
    __m128d a50_3 = _mm_load_sd(&A[221]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_3 = _mm_add_sd(c50_3, _mm_mul_sd(a50_3, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_3 = _mm_add_sd(c50_3, _mm_mul_sd(a50_3, b50));
#endif
    _mm_store_sd(&C[(l_n*88)+50], c50_3);
    __m128d c50_4 = _mm_load_sd(&C[(l_n*88)+78]);
    __m128d a50_4 = _mm_load_sd(&A[222]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_4 = _mm_add_sd(c50_4, _mm_mul_sd(a50_4, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_4 = _mm_add_sd(c50_4, _mm_mul_sd(a50_4, b50));
#endif
    _mm_store_sd(&C[(l_n*88)+78], c50_4);
#else
    C[(l_n*88)+4] += A[218] * B[(l_n*88)+50];
    C[(l_n*88)+14] += A[219] * B[(l_n*88)+50];
    C[(l_n*88)+29] += A[220] * B[(l_n*88)+50];
    C[(l_n*88)+50] += A[221] * B[(l_n*88)+50];
    C[(l_n*88)+78] += A[222] * B[(l_n*88)+50];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b51 = _mm256_broadcast_sd(&B[(l_n*88)+51]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b51 = _mm_loaddup_pd(&B[(l_n*88)+51]);
#endif
    __m128d c51_0 = _mm_load_sd(&C[(l_n*88)+5]);
    __m128d a51_0 = _mm_load_sd(&A[223]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_0 = _mm_add_sd(c51_0, _mm_mul_sd(a51_0, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_0 = _mm_add_sd(c51_0, _mm_mul_sd(a51_0, b51));
#endif
    _mm_store_sd(&C[(l_n*88)+5], c51_0);
    __m128d c51_1 = _mm_load_sd(&C[(l_n*88)+15]);
    __m128d a51_1 = _mm_load_sd(&A[224]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_1 = _mm_add_sd(c51_1, _mm_mul_sd(a51_1, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_1 = _mm_add_sd(c51_1, _mm_mul_sd(a51_1, b51));
#endif
    _mm_store_sd(&C[(l_n*88)+15], c51_1);
    __m128d c51_2 = _mm_load_sd(&C[(l_n*88)+30]);
    __m128d a51_2 = _mm_load_sd(&A[225]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_2 = _mm_add_sd(c51_2, _mm_mul_sd(a51_2, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_2 = _mm_add_sd(c51_2, _mm_mul_sd(a51_2, b51));
#endif
    _mm_store_sd(&C[(l_n*88)+30], c51_2);
    __m128d c51_3 = _mm_load_sd(&C[(l_n*88)+51]);
    __m128d a51_3 = _mm_load_sd(&A[226]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_3 = _mm_add_sd(c51_3, _mm_mul_sd(a51_3, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_3 = _mm_add_sd(c51_3, _mm_mul_sd(a51_3, b51));
#endif
    _mm_store_sd(&C[(l_n*88)+51], c51_3);
    __m128d c51_4 = _mm_load_sd(&C[(l_n*88)+79]);
    __m128d a51_4 = _mm_load_sd(&A[227]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_4 = _mm_add_sd(c51_4, _mm_mul_sd(a51_4, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_4 = _mm_add_sd(c51_4, _mm_mul_sd(a51_4, b51));
#endif
    _mm_store_sd(&C[(l_n*88)+79], c51_4);
#else
    C[(l_n*88)+5] += A[223] * B[(l_n*88)+51];
    C[(l_n*88)+15] += A[224] * B[(l_n*88)+51];
    C[(l_n*88)+30] += A[225] * B[(l_n*88)+51];
    C[(l_n*88)+51] += A[226] * B[(l_n*88)+51];
    C[(l_n*88)+79] += A[227] * B[(l_n*88)+51];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b52 = _mm256_broadcast_sd(&B[(l_n*88)+52]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b52 = _mm_loaddup_pd(&B[(l_n*88)+52]);
#endif
    __m128d c52_0 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a52_0 = _mm_load_sd(&A[228]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_0 = _mm_add_sd(c52_0, _mm_mul_sd(a52_0, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_0 = _mm_add_sd(c52_0, _mm_mul_sd(a52_0, b52));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c52_0);
    __m128d c52_1 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a52_1 = _mm_load_sd(&A[229]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_1 = _mm_add_sd(c52_1, _mm_mul_sd(a52_1, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_1 = _mm_add_sd(c52_1, _mm_mul_sd(a52_1, b52));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c52_1);
    __m128d c52_2 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a52_2 = _mm_load_sd(&A[230]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_2 = _mm_add_sd(c52_2, _mm_mul_sd(a52_2, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_2 = _mm_add_sd(c52_2, _mm_mul_sd(a52_2, b52));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c52_2);
    __m128d c52_3 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a52_3 = _mm_load_sd(&A[231]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_3 = _mm_add_sd(c52_3, _mm_mul_sd(a52_3, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_3 = _mm_add_sd(c52_3, _mm_mul_sd(a52_3, b52));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c52_3);
    __m128d c52_4 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a52_4 = _mm_load_sd(&A[232]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_4 = _mm_add_sd(c52_4, _mm_mul_sd(a52_4, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_4 = _mm_add_sd(c52_4, _mm_mul_sd(a52_4, b52));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c52_4);
#else
    C[(l_n*88)+6] += A[228] * B[(l_n*88)+52];
    C[(l_n*88)+16] += A[229] * B[(l_n*88)+52];
    C[(l_n*88)+31] += A[230] * B[(l_n*88)+52];
    C[(l_n*88)+52] += A[231] * B[(l_n*88)+52];
    C[(l_n*88)+80] += A[232] * B[(l_n*88)+52];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b53 = _mm256_broadcast_sd(&B[(l_n*88)+53]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b53 = _mm_loaddup_pd(&B[(l_n*88)+53]);
#endif
    __m128d c53_0 = _mm_load_sd(&C[(l_n*88)+1]);
    __m128d a53_0 = _mm_load_sd(&A[233]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_0 = _mm_add_sd(c53_0, _mm_mul_sd(a53_0, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_0 = _mm_add_sd(c53_0, _mm_mul_sd(a53_0, b53));
#endif
    _mm_store_sd(&C[(l_n*88)+1], c53_0);
    __m128d c53_1 = _mm_load_sd(&C[(l_n*88)+7]);
    __m128d a53_1 = _mm_load_sd(&A[234]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_1 = _mm_add_sd(c53_1, _mm_mul_sd(a53_1, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_1 = _mm_add_sd(c53_1, _mm_mul_sd(a53_1, b53));
#endif
    _mm_store_sd(&C[(l_n*88)+7], c53_1);
    __m128d c53_2 = _mm_load_sd(&C[(l_n*88)+17]);
    __m128d a53_2 = _mm_load_sd(&A[235]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_2 = _mm_add_sd(c53_2, _mm_mul_sd(a53_2, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_2 = _mm_add_sd(c53_2, _mm_mul_sd(a53_2, b53));
#endif
    _mm_store_sd(&C[(l_n*88)+17], c53_2);
    __m128d c53_3 = _mm_load_sd(&C[(l_n*88)+32]);
    __m128d a53_3 = _mm_load_sd(&A[236]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_3 = _mm_add_sd(c53_3, _mm_mul_sd(a53_3, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_3 = _mm_add_sd(c53_3, _mm_mul_sd(a53_3, b53));
#endif
    _mm_store_sd(&C[(l_n*88)+32], c53_3);
    __m128d c53_4 = _mm_load_sd(&C[(l_n*88)+53]);
    __m128d a53_4 = _mm_load_sd(&A[237]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_4 = _mm_add_sd(c53_4, _mm_mul_sd(a53_4, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_4 = _mm_add_sd(c53_4, _mm_mul_sd(a53_4, b53));
#endif
    _mm_store_sd(&C[(l_n*88)+53], c53_4);
    __m128d c53_5 = _mm_load_sd(&C[(l_n*88)+81]);
    __m128d a53_5 = _mm_load_sd(&A[238]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_5 = _mm_add_sd(c53_5, _mm_mul_sd(a53_5, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_5 = _mm_add_sd(c53_5, _mm_mul_sd(a53_5, b53));
#endif
    _mm_store_sd(&C[(l_n*88)+81], c53_5);
#else
    C[(l_n*88)+1] += A[233] * B[(l_n*88)+53];
    C[(l_n*88)+7] += A[234] * B[(l_n*88)+53];
    C[(l_n*88)+17] += A[235] * B[(l_n*88)+53];
    C[(l_n*88)+32] += A[236] * B[(l_n*88)+53];
    C[(l_n*88)+53] += A[237] * B[(l_n*88)+53];
    C[(l_n*88)+81] += A[238] * B[(l_n*88)+53];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b54 = _mm256_broadcast_sd(&B[(l_n*88)+54]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b54 = _mm_loaddup_pd(&B[(l_n*88)+54]);
#endif
    __m128d c54_0 = _mm_load_sd(&C[(l_n*88)+2]);
    __m128d a54_0 = _mm_load_sd(&A[239]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_0 = _mm_add_sd(c54_0, _mm_mul_sd(a54_0, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_0 = _mm_add_sd(c54_0, _mm_mul_sd(a54_0, b54));
#endif
    _mm_store_sd(&C[(l_n*88)+2], c54_0);
    __m128d c54_1 = _mm_load_sd(&C[(l_n*88)+8]);
    __m128d a54_1 = _mm_load_sd(&A[240]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_1 = _mm_add_sd(c54_1, _mm_mul_sd(a54_1, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_1 = _mm_add_sd(c54_1, _mm_mul_sd(a54_1, b54));
#endif
    _mm_store_sd(&C[(l_n*88)+8], c54_1);
    __m128d c54_2 = _mm_load_sd(&C[(l_n*88)+18]);
    __m128d a54_2 = _mm_load_sd(&A[241]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_2 = _mm_add_sd(c54_2, _mm_mul_sd(a54_2, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_2 = _mm_add_sd(c54_2, _mm_mul_sd(a54_2, b54));
#endif
    _mm_store_sd(&C[(l_n*88)+18], c54_2);
    __m128d c54_3 = _mm_load_sd(&C[(l_n*88)+33]);
    __m128d a54_3 = _mm_load_sd(&A[242]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_3 = _mm_add_sd(c54_3, _mm_mul_sd(a54_3, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_3 = _mm_add_sd(c54_3, _mm_mul_sd(a54_3, b54));
#endif
    _mm_store_sd(&C[(l_n*88)+33], c54_3);
    __m128d c54_4 = _mm_load_sd(&C[(l_n*88)+54]);
    __m128d a54_4 = _mm_load_sd(&A[243]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_4 = _mm_add_sd(c54_4, _mm_mul_sd(a54_4, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_4 = _mm_add_sd(c54_4, _mm_mul_sd(a54_4, b54));
#endif
    _mm_store_sd(&C[(l_n*88)+54], c54_4);
    __m128d c54_5 = _mm_load_sd(&C[(l_n*88)+82]);
    __m128d a54_5 = _mm_load_sd(&A[244]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_5 = _mm_add_sd(c54_5, _mm_mul_sd(a54_5, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_5 = _mm_add_sd(c54_5, _mm_mul_sd(a54_5, b54));
#endif
    _mm_store_sd(&C[(l_n*88)+82], c54_5);
#else
    C[(l_n*88)+2] += A[239] * B[(l_n*88)+54];
    C[(l_n*88)+8] += A[240] * B[(l_n*88)+54];
    C[(l_n*88)+18] += A[241] * B[(l_n*88)+54];
    C[(l_n*88)+33] += A[242] * B[(l_n*88)+54];
    C[(l_n*88)+54] += A[243] * B[(l_n*88)+54];
    C[(l_n*88)+82] += A[244] * B[(l_n*88)+54];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b55 = _mm256_broadcast_sd(&B[(l_n*88)+55]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b55 = _mm_loaddup_pd(&B[(l_n*88)+55]);
#endif
    __m128d c55_0 = _mm_load_sd(&C[(l_n*88)+0]);
    __m128d a55_0 = _mm_load_sd(&A[245]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_0 = _mm_add_sd(c55_0, _mm_mul_sd(a55_0, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_0 = _mm_add_sd(c55_0, _mm_mul_sd(a55_0, b55));
#endif
    _mm_store_sd(&C[(l_n*88)+0], c55_0);
    __m128d c55_1 = _mm_load_sd(&C[(l_n*88)+3]);
    __m128d a55_1 = _mm_load_sd(&A[246]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_1 = _mm_add_sd(c55_1, _mm_mul_sd(a55_1, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_1 = _mm_add_sd(c55_1, _mm_mul_sd(a55_1, b55));
#endif
    _mm_store_sd(&C[(l_n*88)+3], c55_1);
    __m128d c55_2 = _mm_load_sd(&C[(l_n*88)+9]);
    __m128d a55_2 = _mm_load_sd(&A[247]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_2 = _mm_add_sd(c55_2, _mm_mul_sd(a55_2, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_2 = _mm_add_sd(c55_2, _mm_mul_sd(a55_2, b55));
#endif
    _mm_store_sd(&C[(l_n*88)+9], c55_2);
    __m128d c55_3 = _mm_load_sd(&C[(l_n*88)+19]);
    __m128d a55_3 = _mm_load_sd(&A[248]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_3 = _mm_add_sd(c55_3, _mm_mul_sd(a55_3, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_3 = _mm_add_sd(c55_3, _mm_mul_sd(a55_3, b55));
#endif
    _mm_store_sd(&C[(l_n*88)+19], c55_3);
    __m128d c55_4 = _mm_load_sd(&C[(l_n*88)+34]);
    __m128d a55_4 = _mm_load_sd(&A[249]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_4 = _mm_add_sd(c55_4, _mm_mul_sd(a55_4, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_4 = _mm_add_sd(c55_4, _mm_mul_sd(a55_4, b55));
#endif
    _mm_store_sd(&C[(l_n*88)+34], c55_4);
    __m128d c55_5 = _mm_load_sd(&C[(l_n*88)+55]);
    __m128d a55_5 = _mm_load_sd(&A[250]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_5 = _mm_add_sd(c55_5, _mm_mul_sd(a55_5, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_5 = _mm_add_sd(c55_5, _mm_mul_sd(a55_5, b55));
#endif
    _mm_store_sd(&C[(l_n*88)+55], c55_5);
    __m128d c55_6 = _mm_load_sd(&C[(l_n*88)+83]);
    __m128d a55_6 = _mm_load_sd(&A[251]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_6 = _mm_add_sd(c55_6, _mm_mul_sd(a55_6, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_6 = _mm_add_sd(c55_6, _mm_mul_sd(a55_6, b55));
#endif
    _mm_store_sd(&C[(l_n*88)+83], c55_6);
#else
    C[(l_n*88)+0] += A[245] * B[(l_n*88)+55];
    C[(l_n*88)+3] += A[246] * B[(l_n*88)+55];
    C[(l_n*88)+9] += A[247] * B[(l_n*88)+55];
    C[(l_n*88)+19] += A[248] * B[(l_n*88)+55];
    C[(l_n*88)+34] += A[249] * B[(l_n*88)+55];
    C[(l_n*88)+55] += A[250] * B[(l_n*88)+55];
    C[(l_n*88)+83] += A[251] * B[(l_n*88)+55];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b56 = _mm256_broadcast_sd(&B[(l_n*88)+56]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b56 = _mm_loaddup_pd(&B[(l_n*88)+56]);
#endif
    __m128d c56_0 = _mm_load_sd(&C[(l_n*88)+56]);
    __m128d a56_0 = _mm_load_sd(&A[252]);
#if defined(__SSE3__) && defined(__AVX__)
    c56_0 = _mm_add_sd(c56_0, _mm_mul_sd(a56_0, _mm256_castpd256_pd128(b56)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c56_0 = _mm_add_sd(c56_0, _mm_mul_sd(a56_0, b56));
#endif
    _mm_store_sd(&C[(l_n*88)+56], c56_0);
#else
    C[(l_n*88)+56] += A[252] * B[(l_n*88)+56];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b57 = _mm256_broadcast_sd(&B[(l_n*88)+57]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b57 = _mm_loaddup_pd(&B[(l_n*88)+57]);
#endif
    __m128d c57_0 = _mm_load_sd(&C[(l_n*88)+57]);
    __m128d a57_0 = _mm_load_sd(&A[253]);
#if defined(__SSE3__) && defined(__AVX__)
    c57_0 = _mm_add_sd(c57_0, _mm_mul_sd(a57_0, _mm256_castpd256_pd128(b57)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c57_0 = _mm_add_sd(c57_0, _mm_mul_sd(a57_0, b57));
#endif
    _mm_store_sd(&C[(l_n*88)+57], c57_0);
#else
    C[(l_n*88)+57] += A[253] * B[(l_n*88)+57];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b58 = _mm256_broadcast_sd(&B[(l_n*88)+58]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b58 = _mm_loaddup_pd(&B[(l_n*88)+58]);
#endif
    __m128d c58_0 = _mm_load_sd(&C[(l_n*88)+58]);
    __m128d a58_0 = _mm_load_sd(&A[254]);
#if defined(__SSE3__) && defined(__AVX__)
    c58_0 = _mm_add_sd(c58_0, _mm_mul_sd(a58_0, _mm256_castpd256_pd128(b58)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c58_0 = _mm_add_sd(c58_0, _mm_mul_sd(a58_0, b58));
#endif
    _mm_store_sd(&C[(l_n*88)+58], c58_0);
#else
    C[(l_n*88)+58] += A[254] * B[(l_n*88)+58];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b59 = _mm256_broadcast_sd(&B[(l_n*88)+59]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b59 = _mm_loaddup_pd(&B[(l_n*88)+59]);
#endif
    __m128d c59_0 = _mm_load_sd(&C[(l_n*88)+59]);
    __m128d a59_0 = _mm_load_sd(&A[255]);
#if defined(__SSE3__) && defined(__AVX__)
    c59_0 = _mm_add_sd(c59_0, _mm_mul_sd(a59_0, _mm256_castpd256_pd128(b59)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c59_0 = _mm_add_sd(c59_0, _mm_mul_sd(a59_0, b59));
#endif
    _mm_store_sd(&C[(l_n*88)+59], c59_0);
#else
    C[(l_n*88)+59] += A[255] * B[(l_n*88)+59];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b60 = _mm256_broadcast_sd(&B[(l_n*88)+60]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b60 = _mm_loaddup_pd(&B[(l_n*88)+60]);
#endif
    __m128d c60_0 = _mm_load_sd(&C[(l_n*88)+60]);
    __m128d a60_0 = _mm_load_sd(&A[256]);
#if defined(__SSE3__) && defined(__AVX__)
    c60_0 = _mm_add_sd(c60_0, _mm_mul_sd(a60_0, _mm256_castpd256_pd128(b60)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c60_0 = _mm_add_sd(c60_0, _mm_mul_sd(a60_0, b60));
#endif
    _mm_store_sd(&C[(l_n*88)+60], c60_0);
#else
    C[(l_n*88)+60] += A[256] * B[(l_n*88)+60];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b61 = _mm256_broadcast_sd(&B[(l_n*88)+61]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b61 = _mm_loaddup_pd(&B[(l_n*88)+61]);
#endif
    __m128d c61_0 = _mm_load_sd(&C[(l_n*88)+61]);
    __m128d a61_0 = _mm_load_sd(&A[257]);
#if defined(__SSE3__) && defined(__AVX__)
    c61_0 = _mm_add_sd(c61_0, _mm_mul_sd(a61_0, _mm256_castpd256_pd128(b61)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c61_0 = _mm_add_sd(c61_0, _mm_mul_sd(a61_0, b61));
#endif
    _mm_store_sd(&C[(l_n*88)+61], c61_0);
#else
    C[(l_n*88)+61] += A[257] * B[(l_n*88)+61];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b62 = _mm256_broadcast_sd(&B[(l_n*88)+62]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b62 = _mm_loaddup_pd(&B[(l_n*88)+62]);
#endif
    __m128d c62_0 = _mm_load_sd(&C[(l_n*88)+62]);
    __m128d a62_0 = _mm_load_sd(&A[258]);
#if defined(__SSE3__) && defined(__AVX__)
    c62_0 = _mm_add_sd(c62_0, _mm_mul_sd(a62_0, _mm256_castpd256_pd128(b62)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c62_0 = _mm_add_sd(c62_0, _mm_mul_sd(a62_0, b62));
#endif
    _mm_store_sd(&C[(l_n*88)+62], c62_0);
#else
    C[(l_n*88)+62] += A[258] * B[(l_n*88)+62];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b63 = _mm256_broadcast_sd(&B[(l_n*88)+63]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b63 = _mm_loaddup_pd(&B[(l_n*88)+63]);
#endif
    __m128d c63_0 = _mm_load_sd(&C[(l_n*88)+35]);
    __m128d a63_0 = _mm_load_sd(&A[259]);
#if defined(__SSE3__) && defined(__AVX__)
    c63_0 = _mm_add_sd(c63_0, _mm_mul_sd(a63_0, _mm256_castpd256_pd128(b63)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c63_0 = _mm_add_sd(c63_0, _mm_mul_sd(a63_0, b63));
#endif
    _mm_store_sd(&C[(l_n*88)+35], c63_0);
    __m128d c63_1 = _mm_load_sd(&C[(l_n*88)+63]);
    __m128d a63_1 = _mm_load_sd(&A[260]);
#if defined(__SSE3__) && defined(__AVX__)
    c63_1 = _mm_add_sd(c63_1, _mm_mul_sd(a63_1, _mm256_castpd256_pd128(b63)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c63_1 = _mm_add_sd(c63_1, _mm_mul_sd(a63_1, b63));
#endif
    _mm_store_sd(&C[(l_n*88)+63], c63_1);
#else
    C[(l_n*88)+35] += A[259] * B[(l_n*88)+63];
    C[(l_n*88)+63] += A[260] * B[(l_n*88)+63];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b64 = _mm256_broadcast_sd(&B[(l_n*88)+64]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b64 = _mm_loaddup_pd(&B[(l_n*88)+64]);
#endif
    __m128d c64_0 = _mm_load_sd(&C[(l_n*88)+36]);
    __m128d a64_0 = _mm_load_sd(&A[261]);
#if defined(__SSE3__) && defined(__AVX__)
    c64_0 = _mm_add_sd(c64_0, _mm_mul_sd(a64_0, _mm256_castpd256_pd128(b64)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c64_0 = _mm_add_sd(c64_0, _mm_mul_sd(a64_0, b64));
#endif
    _mm_store_sd(&C[(l_n*88)+36], c64_0);
    __m128d c64_1 = _mm_load_sd(&C[(l_n*88)+64]);
    __m128d a64_1 = _mm_load_sd(&A[262]);
#if defined(__SSE3__) && defined(__AVX__)
    c64_1 = _mm_add_sd(c64_1, _mm_mul_sd(a64_1, _mm256_castpd256_pd128(b64)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c64_1 = _mm_add_sd(c64_1, _mm_mul_sd(a64_1, b64));
#endif
    _mm_store_sd(&C[(l_n*88)+64], c64_1);
#else
    C[(l_n*88)+36] += A[261] * B[(l_n*88)+64];
    C[(l_n*88)+64] += A[262] * B[(l_n*88)+64];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b65 = _mm256_broadcast_sd(&B[(l_n*88)+65]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b65 = _mm_loaddup_pd(&B[(l_n*88)+65]);
#endif
    __m128d c65_0 = _mm_load_sd(&C[(l_n*88)+37]);
    __m128d a65_0 = _mm_load_sd(&A[263]);
#if defined(__SSE3__) && defined(__AVX__)
    c65_0 = _mm_add_sd(c65_0, _mm_mul_sd(a65_0, _mm256_castpd256_pd128(b65)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c65_0 = _mm_add_sd(c65_0, _mm_mul_sd(a65_0, b65));
#endif
    _mm_store_sd(&C[(l_n*88)+37], c65_0);
    __m128d c65_1 = _mm_load_sd(&C[(l_n*88)+65]);
    __m128d a65_1 = _mm_load_sd(&A[264]);
#if defined(__SSE3__) && defined(__AVX__)
    c65_1 = _mm_add_sd(c65_1, _mm_mul_sd(a65_1, _mm256_castpd256_pd128(b65)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c65_1 = _mm_add_sd(c65_1, _mm_mul_sd(a65_1, b65));
#endif
    _mm_store_sd(&C[(l_n*88)+65], c65_1);
#else
    C[(l_n*88)+37] += A[263] * B[(l_n*88)+65];
    C[(l_n*88)+65] += A[264] * B[(l_n*88)+65];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b66 = _mm256_broadcast_sd(&B[(l_n*88)+66]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b66 = _mm_loaddup_pd(&B[(l_n*88)+66]);
#endif
    __m128d c66_0 = _mm_load_sd(&C[(l_n*88)+38]);
    __m128d a66_0 = _mm_load_sd(&A[265]);
#if defined(__SSE3__) && defined(__AVX__)
    c66_0 = _mm_add_sd(c66_0, _mm_mul_sd(a66_0, _mm256_castpd256_pd128(b66)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c66_0 = _mm_add_sd(c66_0, _mm_mul_sd(a66_0, b66));
#endif
    _mm_store_sd(&C[(l_n*88)+38], c66_0);
    __m128d c66_1 = _mm_load_sd(&C[(l_n*88)+66]);
    __m128d a66_1 = _mm_load_sd(&A[266]);
#if defined(__SSE3__) && defined(__AVX__)
    c66_1 = _mm_add_sd(c66_1, _mm_mul_sd(a66_1, _mm256_castpd256_pd128(b66)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c66_1 = _mm_add_sd(c66_1, _mm_mul_sd(a66_1, b66));
#endif
    _mm_store_sd(&C[(l_n*88)+66], c66_1);
#else
    C[(l_n*88)+38] += A[265] * B[(l_n*88)+66];
    C[(l_n*88)+66] += A[266] * B[(l_n*88)+66];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b67 = _mm256_broadcast_sd(&B[(l_n*88)+67]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b67 = _mm_loaddup_pd(&B[(l_n*88)+67]);
#endif
    __m128d c67_0 = _mm_load_sd(&C[(l_n*88)+39]);
    __m128d a67_0 = _mm_load_sd(&A[267]);
#if defined(__SSE3__) && defined(__AVX__)
    c67_0 = _mm_add_sd(c67_0, _mm_mul_sd(a67_0, _mm256_castpd256_pd128(b67)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c67_0 = _mm_add_sd(c67_0, _mm_mul_sd(a67_0, b67));
#endif
    _mm_store_sd(&C[(l_n*88)+39], c67_0);
    __m128d c67_1 = _mm_load_sd(&C[(l_n*88)+67]);
    __m128d a67_1 = _mm_load_sd(&A[268]);
#if defined(__SSE3__) && defined(__AVX__)
    c67_1 = _mm_add_sd(c67_1, _mm_mul_sd(a67_1, _mm256_castpd256_pd128(b67)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c67_1 = _mm_add_sd(c67_1, _mm_mul_sd(a67_1, b67));
#endif
    _mm_store_sd(&C[(l_n*88)+67], c67_1);
#else
    C[(l_n*88)+39] += A[267] * B[(l_n*88)+67];
    C[(l_n*88)+67] += A[268] * B[(l_n*88)+67];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b68 = _mm256_broadcast_sd(&B[(l_n*88)+68]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b68 = _mm_loaddup_pd(&B[(l_n*88)+68]);
#endif
    __m128d c68_0 = _mm_load_sd(&C[(l_n*88)+40]);
    __m128d a68_0 = _mm_load_sd(&A[269]);
#if defined(__SSE3__) && defined(__AVX__)
    c68_0 = _mm_add_sd(c68_0, _mm_mul_sd(a68_0, _mm256_castpd256_pd128(b68)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c68_0 = _mm_add_sd(c68_0, _mm_mul_sd(a68_0, b68));
#endif
    _mm_store_sd(&C[(l_n*88)+40], c68_0);
    __m128d c68_1 = _mm_load_sd(&C[(l_n*88)+68]);
    __m128d a68_1 = _mm_load_sd(&A[270]);
#if defined(__SSE3__) && defined(__AVX__)
    c68_1 = _mm_add_sd(c68_1, _mm_mul_sd(a68_1, _mm256_castpd256_pd128(b68)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c68_1 = _mm_add_sd(c68_1, _mm_mul_sd(a68_1, b68));
#endif
    _mm_store_sd(&C[(l_n*88)+68], c68_1);
#else
    C[(l_n*88)+40] += A[269] * B[(l_n*88)+68];
    C[(l_n*88)+68] += A[270] * B[(l_n*88)+68];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b69 = _mm256_broadcast_sd(&B[(l_n*88)+69]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b69 = _mm_loaddup_pd(&B[(l_n*88)+69]);
#endif
    __m128d c69_0 = _mm_load_sd(&C[(l_n*88)+20]);
    __m128d a69_0 = _mm_load_sd(&A[271]);
#if defined(__SSE3__) && defined(__AVX__)
    c69_0 = _mm_add_sd(c69_0, _mm_mul_sd(a69_0, _mm256_castpd256_pd128(b69)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c69_0 = _mm_add_sd(c69_0, _mm_mul_sd(a69_0, b69));
#endif
    _mm_store_sd(&C[(l_n*88)+20], c69_0);
    __m128d c69_1 = _mm_load_sd(&C[(l_n*88)+41]);
    __m128d a69_1 = _mm_load_sd(&A[272]);
#if defined(__SSE3__) && defined(__AVX__)
    c69_1 = _mm_add_sd(c69_1, _mm_mul_sd(a69_1, _mm256_castpd256_pd128(b69)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c69_1 = _mm_add_sd(c69_1, _mm_mul_sd(a69_1, b69));
#endif
    _mm_store_sd(&C[(l_n*88)+41], c69_1);
    __m128d c69_2 = _mm_load_sd(&C[(l_n*88)+69]);
    __m128d a69_2 = _mm_load_sd(&A[273]);
#if defined(__SSE3__) && defined(__AVX__)
    c69_2 = _mm_add_sd(c69_2, _mm_mul_sd(a69_2, _mm256_castpd256_pd128(b69)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c69_2 = _mm_add_sd(c69_2, _mm_mul_sd(a69_2, b69));
#endif
    _mm_store_sd(&C[(l_n*88)+69], c69_2);
#else
    C[(l_n*88)+20] += A[271] * B[(l_n*88)+69];
    C[(l_n*88)+41] += A[272] * B[(l_n*88)+69];
    C[(l_n*88)+69] += A[273] * B[(l_n*88)+69];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b70 = _mm256_broadcast_sd(&B[(l_n*88)+70]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b70 = _mm_loaddup_pd(&B[(l_n*88)+70]);
#endif
    __m128d c70_0 = _mm_load_sd(&C[(l_n*88)+21]);
    __m128d a70_0 = _mm_load_sd(&A[274]);
#if defined(__SSE3__) && defined(__AVX__)
    c70_0 = _mm_add_sd(c70_0, _mm_mul_sd(a70_0, _mm256_castpd256_pd128(b70)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c70_0 = _mm_add_sd(c70_0, _mm_mul_sd(a70_0, b70));
#endif
    _mm_store_sd(&C[(l_n*88)+21], c70_0);
    __m128d c70_1 = _mm_load_sd(&C[(l_n*88)+42]);
    __m128d a70_1 = _mm_load_sd(&A[275]);
#if defined(__SSE3__) && defined(__AVX__)
    c70_1 = _mm_add_sd(c70_1, _mm_mul_sd(a70_1, _mm256_castpd256_pd128(b70)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c70_1 = _mm_add_sd(c70_1, _mm_mul_sd(a70_1, b70));
#endif
    _mm_store_sd(&C[(l_n*88)+42], c70_1);
    __m128d c70_2 = _mm_load_sd(&C[(l_n*88)+70]);
    __m128d a70_2 = _mm_load_sd(&A[276]);
#if defined(__SSE3__) && defined(__AVX__)
    c70_2 = _mm_add_sd(c70_2, _mm_mul_sd(a70_2, _mm256_castpd256_pd128(b70)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c70_2 = _mm_add_sd(c70_2, _mm_mul_sd(a70_2, b70));
#endif
    _mm_store_sd(&C[(l_n*88)+70], c70_2);
#else
    C[(l_n*88)+21] += A[274] * B[(l_n*88)+70];
    C[(l_n*88)+42] += A[275] * B[(l_n*88)+70];
    C[(l_n*88)+70] += A[276] * B[(l_n*88)+70];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b71 = _mm256_broadcast_sd(&B[(l_n*88)+71]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b71 = _mm_loaddup_pd(&B[(l_n*88)+71]);
#endif
    __m128d c71_0 = _mm_load_sd(&C[(l_n*88)+22]);
    __m128d a71_0 = _mm_load_sd(&A[277]);
#if defined(__SSE3__) && defined(__AVX__)
    c71_0 = _mm_add_sd(c71_0, _mm_mul_sd(a71_0, _mm256_castpd256_pd128(b71)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c71_0 = _mm_add_sd(c71_0, _mm_mul_sd(a71_0, b71));
#endif
    _mm_store_sd(&C[(l_n*88)+22], c71_0);
    __m128d c71_1 = _mm_load_sd(&C[(l_n*88)+43]);
    __m128d a71_1 = _mm_load_sd(&A[278]);
#if defined(__SSE3__) && defined(__AVX__)
    c71_1 = _mm_add_sd(c71_1, _mm_mul_sd(a71_1, _mm256_castpd256_pd128(b71)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c71_1 = _mm_add_sd(c71_1, _mm_mul_sd(a71_1, b71));
#endif
    _mm_store_sd(&C[(l_n*88)+43], c71_1);
    __m128d c71_2 = _mm_load_sd(&C[(l_n*88)+71]);
    __m128d a71_2 = _mm_load_sd(&A[279]);
#if defined(__SSE3__) && defined(__AVX__)
    c71_2 = _mm_add_sd(c71_2, _mm_mul_sd(a71_2, _mm256_castpd256_pd128(b71)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c71_2 = _mm_add_sd(c71_2, _mm_mul_sd(a71_2, b71));
#endif
    _mm_store_sd(&C[(l_n*88)+71], c71_2);
#else
    C[(l_n*88)+22] += A[277] * B[(l_n*88)+71];
    C[(l_n*88)+43] += A[278] * B[(l_n*88)+71];
    C[(l_n*88)+71] += A[279] * B[(l_n*88)+71];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b72 = _mm256_broadcast_sd(&B[(l_n*88)+72]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b72 = _mm_loaddup_pd(&B[(l_n*88)+72]);
#endif
    __m128d c72_0 = _mm_load_sd(&C[(l_n*88)+23]);
    __m128d a72_0 = _mm_load_sd(&A[280]);
#if defined(__SSE3__) && defined(__AVX__)
    c72_0 = _mm_add_sd(c72_0, _mm_mul_sd(a72_0, _mm256_castpd256_pd128(b72)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c72_0 = _mm_add_sd(c72_0, _mm_mul_sd(a72_0, b72));
#endif
    _mm_store_sd(&C[(l_n*88)+23], c72_0);
    __m128d c72_1 = _mm_load_sd(&C[(l_n*88)+44]);
    __m128d a72_1 = _mm_load_sd(&A[281]);
#if defined(__SSE3__) && defined(__AVX__)
    c72_1 = _mm_add_sd(c72_1, _mm_mul_sd(a72_1, _mm256_castpd256_pd128(b72)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c72_1 = _mm_add_sd(c72_1, _mm_mul_sd(a72_1, b72));
#endif
    _mm_store_sd(&C[(l_n*88)+44], c72_1);
    __m128d c72_2 = _mm_load_sd(&C[(l_n*88)+72]);
    __m128d a72_2 = _mm_load_sd(&A[282]);
#if defined(__SSE3__) && defined(__AVX__)
    c72_2 = _mm_add_sd(c72_2, _mm_mul_sd(a72_2, _mm256_castpd256_pd128(b72)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c72_2 = _mm_add_sd(c72_2, _mm_mul_sd(a72_2, b72));
#endif
    _mm_store_sd(&C[(l_n*88)+72], c72_2);
#else
    C[(l_n*88)+23] += A[280] * B[(l_n*88)+72];
    C[(l_n*88)+44] += A[281] * B[(l_n*88)+72];
    C[(l_n*88)+72] += A[282] * B[(l_n*88)+72];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b73 = _mm256_broadcast_sd(&B[(l_n*88)+73]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b73 = _mm_loaddup_pd(&B[(l_n*88)+73]);
#endif
    __m128d c73_0 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a73_0 = _mm_load_sd(&A[283]);
#if defined(__SSE3__) && defined(__AVX__)
    c73_0 = _mm_add_sd(c73_0, _mm_mul_sd(a73_0, _mm256_castpd256_pd128(b73)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c73_0 = _mm_add_sd(c73_0, _mm_mul_sd(a73_0, b73));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c73_0);
    __m128d c73_1 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a73_1 = _mm_load_sd(&A[284]);
#if defined(__SSE3__) && defined(__AVX__)
    c73_1 = _mm_add_sd(c73_1, _mm_mul_sd(a73_1, _mm256_castpd256_pd128(b73)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c73_1 = _mm_add_sd(c73_1, _mm_mul_sd(a73_1, b73));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c73_1);
    __m128d c73_2 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a73_2 = _mm_load_sd(&A[285]);
#if defined(__SSE3__) && defined(__AVX__)
    c73_2 = _mm_add_sd(c73_2, _mm_mul_sd(a73_2, _mm256_castpd256_pd128(b73)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c73_2 = _mm_add_sd(c73_2, _mm_mul_sd(a73_2, b73));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c73_2);
#else
    C[(l_n*88)+24] += A[283] * B[(l_n*88)+73];
    C[(l_n*88)+45] += A[284] * B[(l_n*88)+73];
    C[(l_n*88)+73] += A[285] * B[(l_n*88)+73];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b74 = _mm256_broadcast_sd(&B[(l_n*88)+74]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b74 = _mm_loaddup_pd(&B[(l_n*88)+74]);
#endif
    __m128d c74_0 = _mm_load_sd(&C[(l_n*88)+10]);
    __m128d a74_0 = _mm_load_sd(&A[286]);
#if defined(__SSE3__) && defined(__AVX__)
    c74_0 = _mm_add_sd(c74_0, _mm_mul_sd(a74_0, _mm256_castpd256_pd128(b74)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c74_0 = _mm_add_sd(c74_0, _mm_mul_sd(a74_0, b74));
#endif
    _mm_store_sd(&C[(l_n*88)+10], c74_0);
    __m128d c74_1 = _mm_load_sd(&C[(l_n*88)+25]);
    __m128d a74_1 = _mm_load_sd(&A[287]);
#if defined(__SSE3__) && defined(__AVX__)
    c74_1 = _mm_add_sd(c74_1, _mm_mul_sd(a74_1, _mm256_castpd256_pd128(b74)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c74_1 = _mm_add_sd(c74_1, _mm_mul_sd(a74_1, b74));
#endif
    _mm_store_sd(&C[(l_n*88)+25], c74_1);
    __m128d c74_2 = _mm_load_sd(&C[(l_n*88)+46]);
    __m128d a74_2 = _mm_load_sd(&A[288]);
#if defined(__SSE3__) && defined(__AVX__)
    c74_2 = _mm_add_sd(c74_2, _mm_mul_sd(a74_2, _mm256_castpd256_pd128(b74)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c74_2 = _mm_add_sd(c74_2, _mm_mul_sd(a74_2, b74));
#endif
    _mm_store_sd(&C[(l_n*88)+46], c74_2);
    __m128d c74_3 = _mm_load_sd(&C[(l_n*88)+74]);
    __m128d a74_3 = _mm_load_sd(&A[289]);
#if defined(__SSE3__) && defined(__AVX__)
    c74_3 = _mm_add_sd(c74_3, _mm_mul_sd(a74_3, _mm256_castpd256_pd128(b74)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c74_3 = _mm_add_sd(c74_3, _mm_mul_sd(a74_3, b74));
#endif
    _mm_store_sd(&C[(l_n*88)+74], c74_3);
#else
    C[(l_n*88)+10] += A[286] * B[(l_n*88)+74];
    C[(l_n*88)+25] += A[287] * B[(l_n*88)+74];
    C[(l_n*88)+46] += A[288] * B[(l_n*88)+74];
    C[(l_n*88)+74] += A[289] * B[(l_n*88)+74];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b75 = _mm256_broadcast_sd(&B[(l_n*88)+75]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b75 = _mm_loaddup_pd(&B[(l_n*88)+75]);
#endif
    __m128d c75_0 = _mm_load_sd(&C[(l_n*88)+11]);
    __m128d a75_0 = _mm_load_sd(&A[290]);
#if defined(__SSE3__) && defined(__AVX__)
    c75_0 = _mm_add_sd(c75_0, _mm_mul_sd(a75_0, _mm256_castpd256_pd128(b75)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c75_0 = _mm_add_sd(c75_0, _mm_mul_sd(a75_0, b75));
#endif
    _mm_store_sd(&C[(l_n*88)+11], c75_0);
    __m128d c75_1 = _mm_load_sd(&C[(l_n*88)+26]);
    __m128d a75_1 = _mm_load_sd(&A[291]);
#if defined(__SSE3__) && defined(__AVX__)
    c75_1 = _mm_add_sd(c75_1, _mm_mul_sd(a75_1, _mm256_castpd256_pd128(b75)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c75_1 = _mm_add_sd(c75_1, _mm_mul_sd(a75_1, b75));
#endif
    _mm_store_sd(&C[(l_n*88)+26], c75_1);
    __m128d c75_2 = _mm_load_sd(&C[(l_n*88)+47]);
    __m128d a75_2 = _mm_load_sd(&A[292]);
#if defined(__SSE3__) && defined(__AVX__)
    c75_2 = _mm_add_sd(c75_2, _mm_mul_sd(a75_2, _mm256_castpd256_pd128(b75)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c75_2 = _mm_add_sd(c75_2, _mm_mul_sd(a75_2, b75));
#endif
    _mm_store_sd(&C[(l_n*88)+47], c75_2);
    __m128d c75_3 = _mm_load_sd(&C[(l_n*88)+75]);
    __m128d a75_3 = _mm_load_sd(&A[293]);
#if defined(__SSE3__) && defined(__AVX__)
    c75_3 = _mm_add_sd(c75_3, _mm_mul_sd(a75_3, _mm256_castpd256_pd128(b75)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c75_3 = _mm_add_sd(c75_3, _mm_mul_sd(a75_3, b75));
#endif
    _mm_store_sd(&C[(l_n*88)+75], c75_3);
#else
    C[(l_n*88)+11] += A[290] * B[(l_n*88)+75];
    C[(l_n*88)+26] += A[291] * B[(l_n*88)+75];
    C[(l_n*88)+47] += A[292] * B[(l_n*88)+75];
    C[(l_n*88)+75] += A[293] * B[(l_n*88)+75];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b76 = _mm256_broadcast_sd(&B[(l_n*88)+76]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b76 = _mm_loaddup_pd(&B[(l_n*88)+76]);
#endif
    __m128d c76_0 = _mm_load_sd(&C[(l_n*88)+12]);
    __m128d a76_0 = _mm_load_sd(&A[294]);
#if defined(__SSE3__) && defined(__AVX__)
    c76_0 = _mm_add_sd(c76_0, _mm_mul_sd(a76_0, _mm256_castpd256_pd128(b76)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c76_0 = _mm_add_sd(c76_0, _mm_mul_sd(a76_0, b76));
#endif
    _mm_store_sd(&C[(l_n*88)+12], c76_0);
    __m128d c76_1 = _mm_load_sd(&C[(l_n*88)+27]);
    __m128d a76_1 = _mm_load_sd(&A[295]);
#if defined(__SSE3__) && defined(__AVX__)
    c76_1 = _mm_add_sd(c76_1, _mm_mul_sd(a76_1, _mm256_castpd256_pd128(b76)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c76_1 = _mm_add_sd(c76_1, _mm_mul_sd(a76_1, b76));
#endif
    _mm_store_sd(&C[(l_n*88)+27], c76_1);
    __m128d c76_2 = _mm_load_sd(&C[(l_n*88)+48]);
    __m128d a76_2 = _mm_load_sd(&A[296]);
#if defined(__SSE3__) && defined(__AVX__)
    c76_2 = _mm_add_sd(c76_2, _mm_mul_sd(a76_2, _mm256_castpd256_pd128(b76)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c76_2 = _mm_add_sd(c76_2, _mm_mul_sd(a76_2, b76));
#endif
    _mm_store_sd(&C[(l_n*88)+48], c76_2);
    __m128d c76_3 = _mm_load_sd(&C[(l_n*88)+76]);
    __m128d a76_3 = _mm_load_sd(&A[297]);
#if defined(__SSE3__) && defined(__AVX__)
    c76_3 = _mm_add_sd(c76_3, _mm_mul_sd(a76_3, _mm256_castpd256_pd128(b76)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c76_3 = _mm_add_sd(c76_3, _mm_mul_sd(a76_3, b76));
#endif
    _mm_store_sd(&C[(l_n*88)+76], c76_3);
#else
    C[(l_n*88)+12] += A[294] * B[(l_n*88)+76];
    C[(l_n*88)+27] += A[295] * B[(l_n*88)+76];
    C[(l_n*88)+48] += A[296] * B[(l_n*88)+76];
    C[(l_n*88)+76] += A[297] * B[(l_n*88)+76];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b77 = _mm256_broadcast_sd(&B[(l_n*88)+77]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b77 = _mm_loaddup_pd(&B[(l_n*88)+77]);
#endif
    __m128d c77_0 = _mm_load_sd(&C[(l_n*88)+13]);
    __m128d a77_0 = _mm_load_sd(&A[298]);
#if defined(__SSE3__) && defined(__AVX__)
    c77_0 = _mm_add_sd(c77_0, _mm_mul_sd(a77_0, _mm256_castpd256_pd128(b77)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c77_0 = _mm_add_sd(c77_0, _mm_mul_sd(a77_0, b77));
#endif
    _mm_store_sd(&C[(l_n*88)+13], c77_0);
    __m128d c77_1 = _mm_load_sd(&C[(l_n*88)+28]);
    __m128d a77_1 = _mm_load_sd(&A[299]);
#if defined(__SSE3__) && defined(__AVX__)
    c77_1 = _mm_add_sd(c77_1, _mm_mul_sd(a77_1, _mm256_castpd256_pd128(b77)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c77_1 = _mm_add_sd(c77_1, _mm_mul_sd(a77_1, b77));
#endif
    _mm_store_sd(&C[(l_n*88)+28], c77_1);
    __m128d c77_2 = _mm_load_sd(&C[(l_n*88)+49]);
    __m128d a77_2 = _mm_load_sd(&A[300]);
#if defined(__SSE3__) && defined(__AVX__)
    c77_2 = _mm_add_sd(c77_2, _mm_mul_sd(a77_2, _mm256_castpd256_pd128(b77)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c77_2 = _mm_add_sd(c77_2, _mm_mul_sd(a77_2, b77));
#endif
    _mm_store_sd(&C[(l_n*88)+49], c77_2);
    __m128d c77_3 = _mm_load_sd(&C[(l_n*88)+77]);
    __m128d a77_3 = _mm_load_sd(&A[301]);
#if defined(__SSE3__) && defined(__AVX__)
    c77_3 = _mm_add_sd(c77_3, _mm_mul_sd(a77_3, _mm256_castpd256_pd128(b77)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c77_3 = _mm_add_sd(c77_3, _mm_mul_sd(a77_3, b77));
#endif
    _mm_store_sd(&C[(l_n*88)+77], c77_3);
#else
    C[(l_n*88)+13] += A[298] * B[(l_n*88)+77];
    C[(l_n*88)+28] += A[299] * B[(l_n*88)+77];
    C[(l_n*88)+49] += A[300] * B[(l_n*88)+77];
    C[(l_n*88)+77] += A[301] * B[(l_n*88)+77];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b78 = _mm256_broadcast_sd(&B[(l_n*88)+78]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b78 = _mm_loaddup_pd(&B[(l_n*88)+78]);
#endif
    __m128d c78_0 = _mm_load_sd(&C[(l_n*88)+4]);
    __m128d a78_0 = _mm_load_sd(&A[302]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_0 = _mm_add_sd(c78_0, _mm_mul_sd(a78_0, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_0 = _mm_add_sd(c78_0, _mm_mul_sd(a78_0, b78));
#endif
    _mm_store_sd(&C[(l_n*88)+4], c78_0);
    __m128d c78_1 = _mm_load_sd(&C[(l_n*88)+14]);
    __m128d a78_1 = _mm_load_sd(&A[303]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_1 = _mm_add_sd(c78_1, _mm_mul_sd(a78_1, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_1 = _mm_add_sd(c78_1, _mm_mul_sd(a78_1, b78));
#endif
    _mm_store_sd(&C[(l_n*88)+14], c78_1);
    __m128d c78_2 = _mm_load_sd(&C[(l_n*88)+29]);
    __m128d a78_2 = _mm_load_sd(&A[304]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_2 = _mm_add_sd(c78_2, _mm_mul_sd(a78_2, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_2 = _mm_add_sd(c78_2, _mm_mul_sd(a78_2, b78));
#endif
    _mm_store_sd(&C[(l_n*88)+29], c78_2);
    __m128d c78_3 = _mm_load_sd(&C[(l_n*88)+50]);
    __m128d a78_3 = _mm_load_sd(&A[305]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_3 = _mm_add_sd(c78_3, _mm_mul_sd(a78_3, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_3 = _mm_add_sd(c78_3, _mm_mul_sd(a78_3, b78));
#endif
    _mm_store_sd(&C[(l_n*88)+50], c78_3);
    __m128d c78_4 = _mm_load_sd(&C[(l_n*88)+78]);
    __m128d a78_4 = _mm_load_sd(&A[306]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_4 = _mm_add_sd(c78_4, _mm_mul_sd(a78_4, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_4 = _mm_add_sd(c78_4, _mm_mul_sd(a78_4, b78));
#endif
    _mm_store_sd(&C[(l_n*88)+78], c78_4);
#else
    C[(l_n*88)+4] += A[302] * B[(l_n*88)+78];
    C[(l_n*88)+14] += A[303] * B[(l_n*88)+78];
    C[(l_n*88)+29] += A[304] * B[(l_n*88)+78];
    C[(l_n*88)+50] += A[305] * B[(l_n*88)+78];
    C[(l_n*88)+78] += A[306] * B[(l_n*88)+78];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b79 = _mm256_broadcast_sd(&B[(l_n*88)+79]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b79 = _mm_loaddup_pd(&B[(l_n*88)+79]);
#endif
    __m128d c79_0 = _mm_load_sd(&C[(l_n*88)+5]);
    __m128d a79_0 = _mm_load_sd(&A[307]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_0 = _mm_add_sd(c79_0, _mm_mul_sd(a79_0, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_0 = _mm_add_sd(c79_0, _mm_mul_sd(a79_0, b79));
#endif
    _mm_store_sd(&C[(l_n*88)+5], c79_0);
    __m128d c79_1 = _mm_load_sd(&C[(l_n*88)+15]);
    __m128d a79_1 = _mm_load_sd(&A[308]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_1 = _mm_add_sd(c79_1, _mm_mul_sd(a79_1, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_1 = _mm_add_sd(c79_1, _mm_mul_sd(a79_1, b79));
#endif
    _mm_store_sd(&C[(l_n*88)+15], c79_1);
    __m128d c79_2 = _mm_load_sd(&C[(l_n*88)+30]);
    __m128d a79_2 = _mm_load_sd(&A[309]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_2 = _mm_add_sd(c79_2, _mm_mul_sd(a79_2, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_2 = _mm_add_sd(c79_2, _mm_mul_sd(a79_2, b79));
#endif
    _mm_store_sd(&C[(l_n*88)+30], c79_2);
    __m128d c79_3 = _mm_load_sd(&C[(l_n*88)+51]);
    __m128d a79_3 = _mm_load_sd(&A[310]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_3 = _mm_add_sd(c79_3, _mm_mul_sd(a79_3, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_3 = _mm_add_sd(c79_3, _mm_mul_sd(a79_3, b79));
#endif
    _mm_store_sd(&C[(l_n*88)+51], c79_3);
    __m128d c79_4 = _mm_load_sd(&C[(l_n*88)+79]);
    __m128d a79_4 = _mm_load_sd(&A[311]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_4 = _mm_add_sd(c79_4, _mm_mul_sd(a79_4, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_4 = _mm_add_sd(c79_4, _mm_mul_sd(a79_4, b79));
#endif
    _mm_store_sd(&C[(l_n*88)+79], c79_4);
#else
    C[(l_n*88)+5] += A[307] * B[(l_n*88)+79];
    C[(l_n*88)+15] += A[308] * B[(l_n*88)+79];
    C[(l_n*88)+30] += A[309] * B[(l_n*88)+79];
    C[(l_n*88)+51] += A[310] * B[(l_n*88)+79];
    C[(l_n*88)+79] += A[311] * B[(l_n*88)+79];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b80 = _mm256_broadcast_sd(&B[(l_n*88)+80]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b80 = _mm_loaddup_pd(&B[(l_n*88)+80]);
#endif
    __m128d c80_0 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a80_0 = _mm_load_sd(&A[312]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_0 = _mm_add_sd(c80_0, _mm_mul_sd(a80_0, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_0 = _mm_add_sd(c80_0, _mm_mul_sd(a80_0, b80));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c80_0);
    __m128d c80_1 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a80_1 = _mm_load_sd(&A[313]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_1 = _mm_add_sd(c80_1, _mm_mul_sd(a80_1, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_1 = _mm_add_sd(c80_1, _mm_mul_sd(a80_1, b80));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c80_1);
    __m128d c80_2 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a80_2 = _mm_load_sd(&A[314]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_2 = _mm_add_sd(c80_2, _mm_mul_sd(a80_2, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_2 = _mm_add_sd(c80_2, _mm_mul_sd(a80_2, b80));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c80_2);
    __m128d c80_3 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a80_3 = _mm_load_sd(&A[315]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_3 = _mm_add_sd(c80_3, _mm_mul_sd(a80_3, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_3 = _mm_add_sd(c80_3, _mm_mul_sd(a80_3, b80));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c80_3);
    __m128d c80_4 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a80_4 = _mm_load_sd(&A[316]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_4 = _mm_add_sd(c80_4, _mm_mul_sd(a80_4, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_4 = _mm_add_sd(c80_4, _mm_mul_sd(a80_4, b80));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c80_4);
#else
    C[(l_n*88)+6] += A[312] * B[(l_n*88)+80];
    C[(l_n*88)+16] += A[313] * B[(l_n*88)+80];
    C[(l_n*88)+31] += A[314] * B[(l_n*88)+80];
    C[(l_n*88)+52] += A[315] * B[(l_n*88)+80];
    C[(l_n*88)+80] += A[316] * B[(l_n*88)+80];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b81 = _mm256_broadcast_sd(&B[(l_n*88)+81]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b81 = _mm_loaddup_pd(&B[(l_n*88)+81]);
#endif
    __m128d c81_0 = _mm_load_sd(&C[(l_n*88)+1]);
    __m128d a81_0 = _mm_load_sd(&A[317]);
#if defined(__SSE3__) && defined(__AVX__)
    c81_0 = _mm_add_sd(c81_0, _mm_mul_sd(a81_0, _mm256_castpd256_pd128(b81)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c81_0 = _mm_add_sd(c81_0, _mm_mul_sd(a81_0, b81));
#endif
    _mm_store_sd(&C[(l_n*88)+1], c81_0);
    __m128d c81_1 = _mm_load_sd(&C[(l_n*88)+7]);
    __m128d a81_1 = _mm_load_sd(&A[318]);
#if defined(__SSE3__) && defined(__AVX__)
    c81_1 = _mm_add_sd(c81_1, _mm_mul_sd(a81_1, _mm256_castpd256_pd128(b81)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c81_1 = _mm_add_sd(c81_1, _mm_mul_sd(a81_1, b81));
#endif
    _mm_store_sd(&C[(l_n*88)+7], c81_1);
    __m128d c81_2 = _mm_load_sd(&C[(l_n*88)+17]);
    __m128d a81_2 = _mm_load_sd(&A[319]);
#if defined(__SSE3__) && defined(__AVX__)
    c81_2 = _mm_add_sd(c81_2, _mm_mul_sd(a81_2, _mm256_castpd256_pd128(b81)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c81_2 = _mm_add_sd(c81_2, _mm_mul_sd(a81_2, b81));
#endif
    _mm_store_sd(&C[(l_n*88)+17], c81_2);
    __m128d c81_3 = _mm_load_sd(&C[(l_n*88)+32]);
    __m128d a81_3 = _mm_load_sd(&A[320]);
#if defined(__SSE3__) && defined(__AVX__)
    c81_3 = _mm_add_sd(c81_3, _mm_mul_sd(a81_3, _mm256_castpd256_pd128(b81)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c81_3 = _mm_add_sd(c81_3, _mm_mul_sd(a81_3, b81));
#endif
    _mm_store_sd(&C[(l_n*88)+32], c81_3);
    __m128d c81_4 = _mm_load_sd(&C[(l_n*88)+53]);
    __m128d a81_4 = _mm_load_sd(&A[321]);
#if defined(__SSE3__) && defined(__AVX__)
    c81_4 = _mm_add_sd(c81_4, _mm_mul_sd(a81_4, _mm256_castpd256_pd128(b81)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c81_4 = _mm_add_sd(c81_4, _mm_mul_sd(a81_4, b81));
#endif
    _mm_store_sd(&C[(l_n*88)+53], c81_4);
    __m128d c81_5 = _mm_load_sd(&C[(l_n*88)+81]);
    __m128d a81_5 = _mm_load_sd(&A[322]);
#if defined(__SSE3__) && defined(__AVX__)
    c81_5 = _mm_add_sd(c81_5, _mm_mul_sd(a81_5, _mm256_castpd256_pd128(b81)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c81_5 = _mm_add_sd(c81_5, _mm_mul_sd(a81_5, b81));
#endif
    _mm_store_sd(&C[(l_n*88)+81], c81_5);
#else
    C[(l_n*88)+1] += A[317] * B[(l_n*88)+81];
    C[(l_n*88)+7] += A[318] * B[(l_n*88)+81];
    C[(l_n*88)+17] += A[319] * B[(l_n*88)+81];
    C[(l_n*88)+32] += A[320] * B[(l_n*88)+81];
    C[(l_n*88)+53] += A[321] * B[(l_n*88)+81];
    C[(l_n*88)+81] += A[322] * B[(l_n*88)+81];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b82 = _mm256_broadcast_sd(&B[(l_n*88)+82]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b82 = _mm_loaddup_pd(&B[(l_n*88)+82]);
#endif
    __m128d c82_0 = _mm_load_sd(&C[(l_n*88)+2]);
    __m128d a82_0 = _mm_load_sd(&A[323]);
#if defined(__SSE3__) && defined(__AVX__)
    c82_0 = _mm_add_sd(c82_0, _mm_mul_sd(a82_0, _mm256_castpd256_pd128(b82)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c82_0 = _mm_add_sd(c82_0, _mm_mul_sd(a82_0, b82));
#endif
    _mm_store_sd(&C[(l_n*88)+2], c82_0);
    __m128d c82_1 = _mm_load_sd(&C[(l_n*88)+8]);
    __m128d a82_1 = _mm_load_sd(&A[324]);
#if defined(__SSE3__) && defined(__AVX__)
    c82_1 = _mm_add_sd(c82_1, _mm_mul_sd(a82_1, _mm256_castpd256_pd128(b82)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c82_1 = _mm_add_sd(c82_1, _mm_mul_sd(a82_1, b82));
#endif
    _mm_store_sd(&C[(l_n*88)+8], c82_1);
    __m128d c82_2 = _mm_load_sd(&C[(l_n*88)+18]);
    __m128d a82_2 = _mm_load_sd(&A[325]);
#if defined(__SSE3__) && defined(__AVX__)
    c82_2 = _mm_add_sd(c82_2, _mm_mul_sd(a82_2, _mm256_castpd256_pd128(b82)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c82_2 = _mm_add_sd(c82_2, _mm_mul_sd(a82_2, b82));
#endif
    _mm_store_sd(&C[(l_n*88)+18], c82_2);
    __m128d c82_3 = _mm_load_sd(&C[(l_n*88)+33]);
    __m128d a82_3 = _mm_load_sd(&A[326]);
#if defined(__SSE3__) && defined(__AVX__)
    c82_3 = _mm_add_sd(c82_3, _mm_mul_sd(a82_3, _mm256_castpd256_pd128(b82)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c82_3 = _mm_add_sd(c82_3, _mm_mul_sd(a82_3, b82));
#endif
    _mm_store_sd(&C[(l_n*88)+33], c82_3);
    __m128d c82_4 = _mm_load_sd(&C[(l_n*88)+54]);
    __m128d a82_4 = _mm_load_sd(&A[327]);
#if defined(__SSE3__) && defined(__AVX__)
    c82_4 = _mm_add_sd(c82_4, _mm_mul_sd(a82_4, _mm256_castpd256_pd128(b82)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c82_4 = _mm_add_sd(c82_4, _mm_mul_sd(a82_4, b82));
#endif
    _mm_store_sd(&C[(l_n*88)+54], c82_4);
    __m128d c82_5 = _mm_load_sd(&C[(l_n*88)+82]);
    __m128d a82_5 = _mm_load_sd(&A[328]);
#if defined(__SSE3__) && defined(__AVX__)
    c82_5 = _mm_add_sd(c82_5, _mm_mul_sd(a82_5, _mm256_castpd256_pd128(b82)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c82_5 = _mm_add_sd(c82_5, _mm_mul_sd(a82_5, b82));
#endif
    _mm_store_sd(&C[(l_n*88)+82], c82_5);
#else
    C[(l_n*88)+2] += A[323] * B[(l_n*88)+82];
    C[(l_n*88)+8] += A[324] * B[(l_n*88)+82];
    C[(l_n*88)+18] += A[325] * B[(l_n*88)+82];
    C[(l_n*88)+33] += A[326] * B[(l_n*88)+82];
    C[(l_n*88)+54] += A[327] * B[(l_n*88)+82];
    C[(l_n*88)+82] += A[328] * B[(l_n*88)+82];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b83 = _mm256_broadcast_sd(&B[(l_n*88)+83]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b83 = _mm_loaddup_pd(&B[(l_n*88)+83]);
#endif
    __m128d c83_0 = _mm_load_sd(&C[(l_n*88)+0]);
    __m128d a83_0 = _mm_load_sd(&A[329]);
#if defined(__SSE3__) && defined(__AVX__)
    c83_0 = _mm_add_sd(c83_0, _mm_mul_sd(a83_0, _mm256_castpd256_pd128(b83)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c83_0 = _mm_add_sd(c83_0, _mm_mul_sd(a83_0, b83));
#endif
    _mm_store_sd(&C[(l_n*88)+0], c83_0);
    __m128d c83_1 = _mm_load_sd(&C[(l_n*88)+3]);
    __m128d a83_1 = _mm_load_sd(&A[330]);
#if defined(__SSE3__) && defined(__AVX__)
    c83_1 = _mm_add_sd(c83_1, _mm_mul_sd(a83_1, _mm256_castpd256_pd128(b83)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c83_1 = _mm_add_sd(c83_1, _mm_mul_sd(a83_1, b83));
#endif
    _mm_store_sd(&C[(l_n*88)+3], c83_1);
    __m128d c83_2 = _mm_load_sd(&C[(l_n*88)+9]);
    __m128d a83_2 = _mm_load_sd(&A[331]);
#if defined(__SSE3__) && defined(__AVX__)
    c83_2 = _mm_add_sd(c83_2, _mm_mul_sd(a83_2, _mm256_castpd256_pd128(b83)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c83_2 = _mm_add_sd(c83_2, _mm_mul_sd(a83_2, b83));
#endif
    _mm_store_sd(&C[(l_n*88)+9], c83_2);
    __m128d c83_3 = _mm_load_sd(&C[(l_n*88)+19]);
    __m128d a83_3 = _mm_load_sd(&A[332]);
#if defined(__SSE3__) && defined(__AVX__)
    c83_3 = _mm_add_sd(c83_3, _mm_mul_sd(a83_3, _mm256_castpd256_pd128(b83)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c83_3 = _mm_add_sd(c83_3, _mm_mul_sd(a83_3, b83));
#endif
    _mm_store_sd(&C[(l_n*88)+19], c83_3);
    __m128d c83_4 = _mm_load_sd(&C[(l_n*88)+34]);
    __m128d a83_4 = _mm_load_sd(&A[333]);
#if defined(__SSE3__) && defined(__AVX__)
    c83_4 = _mm_add_sd(c83_4, _mm_mul_sd(a83_4, _mm256_castpd256_pd128(b83)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c83_4 = _mm_add_sd(c83_4, _mm_mul_sd(a83_4, b83));
#endif
    _mm_store_sd(&C[(l_n*88)+34], c83_4);
    __m128d c83_5 = _mm_load_sd(&C[(l_n*88)+55]);
    __m128d a83_5 = _mm_load_sd(&A[334]);
#if defined(__SSE3__) && defined(__AVX__)
    c83_5 = _mm_add_sd(c83_5, _mm_mul_sd(a83_5, _mm256_castpd256_pd128(b83)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c83_5 = _mm_add_sd(c83_5, _mm_mul_sd(a83_5, b83));
#endif
    _mm_store_sd(&C[(l_n*88)+55], c83_5);
    __m128d c83_6 = _mm_load_sd(&C[(l_n*88)+83]);
    __m128d a83_6 = _mm_load_sd(&A[335]);
#if defined(__SSE3__) && defined(__AVX__)
    c83_6 = _mm_add_sd(c83_6, _mm_mul_sd(a83_6, _mm256_castpd256_pd128(b83)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c83_6 = _mm_add_sd(c83_6, _mm_mul_sd(a83_6, b83));
#endif
    _mm_store_sd(&C[(l_n*88)+83], c83_6);
#else
    C[(l_n*88)+0] += A[329] * B[(l_n*88)+83];
    C[(l_n*88)+3] += A[330] * B[(l_n*88)+83];
    C[(l_n*88)+9] += A[331] * B[(l_n*88)+83];
    C[(l_n*88)+19] += A[332] * B[(l_n*88)+83];
    C[(l_n*88)+34] += A[333] * B[(l_n*88)+83];
    C[(l_n*88)+55] += A[334] * B[(l_n*88)+83];
    C[(l_n*88)+83] += A[335] * B[(l_n*88)+83];
#endif

  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 6048;
#endif
}

void dsparse_fP111DivM_m84_n9_k84_ldAna7_ldB88_ldC88_beta0_pfsigonly(const double* A, const double* B, double* C, const double* A_prefetch, const double* B_prefetch, const double* C_prefetch) {
  unsigned int l_n = 0;
  #pragma nounroll_and_jam
  for ( l_n = 0; l_n < 9; l_n++) {
    unsigned int l_m = 0;
   #pragma simd
    for ( l_m = 0; l_m < 84; l_m++) {
      C[(l_n*88)+l_m] = 0.0;
    }
#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b0 = _mm256_broadcast_sd(&B[(l_n*88)+0]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b0 = _mm_loaddup_pd(&B[(l_n*88)+0]);
#endif
    __m128d c0_0 = _mm_load_sd(&C[(l_n*88)+0]);
    __m128d a0_0 = _mm_load_sd(&A[0]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_0 = _mm_add_sd(c0_0, _mm_mul_sd(a0_0, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_0 = _mm_add_sd(c0_0, _mm_mul_sd(a0_0, b0));
#endif
    _mm_store_sd(&C[(l_n*88)+0], c0_0);
    __m128d c0_1 = _mm_load_sd(&C[(l_n*88)+3]);
    __m128d a0_1 = _mm_load_sd(&A[1]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_1 = _mm_add_sd(c0_1, _mm_mul_sd(a0_1, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_1 = _mm_add_sd(c0_1, _mm_mul_sd(a0_1, b0));
#endif
    _mm_store_sd(&C[(l_n*88)+3], c0_1);
    __m128d c0_2 = _mm_load_sd(&C[(l_n*88)+9]);
    __m128d a0_2 = _mm_load_sd(&A[2]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_2 = _mm_add_sd(c0_2, _mm_mul_sd(a0_2, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_2 = _mm_add_sd(c0_2, _mm_mul_sd(a0_2, b0));
#endif
    _mm_store_sd(&C[(l_n*88)+9], c0_2);
    __m128d c0_3 = _mm_load_sd(&C[(l_n*88)+19]);
    __m128d a0_3 = _mm_load_sd(&A[3]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_3 = _mm_add_sd(c0_3, _mm_mul_sd(a0_3, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_3 = _mm_add_sd(c0_3, _mm_mul_sd(a0_3, b0));
#endif
    _mm_store_sd(&C[(l_n*88)+19], c0_3);
    __m128d c0_4 = _mm_load_sd(&C[(l_n*88)+34]);
    __m128d a0_4 = _mm_load_sd(&A[4]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_4 = _mm_add_sd(c0_4, _mm_mul_sd(a0_4, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_4 = _mm_add_sd(c0_4, _mm_mul_sd(a0_4, b0));
#endif
    _mm_store_sd(&C[(l_n*88)+34], c0_4);
    __m128d c0_5 = _mm_load_sd(&C[(l_n*88)+55]);
    __m128d a0_5 = _mm_load_sd(&A[5]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_5 = _mm_add_sd(c0_5, _mm_mul_sd(a0_5, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_5 = _mm_add_sd(c0_5, _mm_mul_sd(a0_5, b0));
#endif
    _mm_store_sd(&C[(l_n*88)+55], c0_5);
    __m128d c0_6 = _mm_load_sd(&C[(l_n*88)+83]);
    __m128d a0_6 = _mm_load_sd(&A[6]);
#if defined(__SSE3__) && defined(__AVX__)
    c0_6 = _mm_add_sd(c0_6, _mm_mul_sd(a0_6, _mm256_castpd256_pd128(b0)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c0_6 = _mm_add_sd(c0_6, _mm_mul_sd(a0_6, b0));
#endif
    _mm_store_sd(&C[(l_n*88)+83], c0_6);
#else
    C[(l_n*88)+0] += A[0] * B[(l_n*88)+0];
    C[(l_n*88)+3] += A[1] * B[(l_n*88)+0];
    C[(l_n*88)+9] += A[2] * B[(l_n*88)+0];
    C[(l_n*88)+19] += A[3] * B[(l_n*88)+0];
    C[(l_n*88)+34] += A[4] * B[(l_n*88)+0];
    C[(l_n*88)+55] += A[5] * B[(l_n*88)+0];
    C[(l_n*88)+83] += A[6] * B[(l_n*88)+0];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b1 = _mm256_broadcast_sd(&B[(l_n*88)+1]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b1 = _mm_loaddup_pd(&B[(l_n*88)+1]);
#endif
    __m128d c1_0 = _mm_loadu_pd(&C[(l_n*88)+1]);
    __m128d a1_0 = _mm_loadu_pd(&A[7]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_0 = _mm_add_pd(c1_0, _mm_mul_pd(a1_0, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_0 = _mm_add_pd(c1_0, _mm_mul_pd(a1_0, b1));
#endif
    _mm_storeu_pd(&C[(l_n*88)+1], c1_0);
    __m128d c1_2 = _mm_loadu_pd(&C[(l_n*88)+7]);
    __m128d a1_2 = _mm_loadu_pd(&A[9]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_2 = _mm_add_pd(c1_2, _mm_mul_pd(a1_2, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_2 = _mm_add_pd(c1_2, _mm_mul_pd(a1_2, b1));
#endif
    _mm_storeu_pd(&C[(l_n*88)+7], c1_2);
    __m128d c1_4 = _mm_loadu_pd(&C[(l_n*88)+17]);
    __m128d a1_4 = _mm_loadu_pd(&A[11]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_4 = _mm_add_pd(c1_4, _mm_mul_pd(a1_4, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_4 = _mm_add_pd(c1_4, _mm_mul_pd(a1_4, b1));
#endif
    _mm_storeu_pd(&C[(l_n*88)+17], c1_4);
    __m128d c1_6 = _mm_loadu_pd(&C[(l_n*88)+32]);
    __m128d a1_6 = _mm_loadu_pd(&A[13]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_6 = _mm_add_pd(c1_6, _mm_mul_pd(a1_6, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_6 = _mm_add_pd(c1_6, _mm_mul_pd(a1_6, b1));
#endif
    _mm_storeu_pd(&C[(l_n*88)+32], c1_6);
    __m128d c1_8 = _mm_loadu_pd(&C[(l_n*88)+53]);
    __m128d a1_8 = _mm_loadu_pd(&A[15]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_8 = _mm_add_pd(c1_8, _mm_mul_pd(a1_8, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_8 = _mm_add_pd(c1_8, _mm_mul_pd(a1_8, b1));
#endif
    _mm_storeu_pd(&C[(l_n*88)+53], c1_8);
    __m128d c1_10 = _mm_loadu_pd(&C[(l_n*88)+81]);
    __m128d a1_10 = _mm_loadu_pd(&A[17]);
#if defined(__SSE3__) && defined(__AVX__)
    c1_10 = _mm_add_pd(c1_10, _mm_mul_pd(a1_10, _mm256_castpd256_pd128(b1)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c1_10 = _mm_add_pd(c1_10, _mm_mul_pd(a1_10, b1));
#endif
    _mm_storeu_pd(&C[(l_n*88)+81], c1_10);
#else
    C[(l_n*88)+1] += A[7] * B[(l_n*88)+1];
    C[(l_n*88)+2] += A[8] * B[(l_n*88)+1];
    C[(l_n*88)+7] += A[9] * B[(l_n*88)+1];
    C[(l_n*88)+8] += A[10] * B[(l_n*88)+1];
    C[(l_n*88)+17] += A[11] * B[(l_n*88)+1];
    C[(l_n*88)+18] += A[12] * B[(l_n*88)+1];
    C[(l_n*88)+32] += A[13] * B[(l_n*88)+1];
    C[(l_n*88)+33] += A[14] * B[(l_n*88)+1];
    C[(l_n*88)+53] += A[15] * B[(l_n*88)+1];
    C[(l_n*88)+54] += A[16] * B[(l_n*88)+1];
    C[(l_n*88)+81] += A[17] * B[(l_n*88)+1];
    C[(l_n*88)+82] += A[18] * B[(l_n*88)+1];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b2 = _mm256_broadcast_sd(&B[(l_n*88)+2]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b2 = _mm_loaddup_pd(&B[(l_n*88)+2]);
#endif
    __m128d c2_0 = _mm_loadu_pd(&C[(l_n*88)+1]);
    __m128d a2_0 = _mm_loadu_pd(&A[19]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_0 = _mm_add_pd(c2_0, _mm_mul_pd(a2_0, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_0 = _mm_add_pd(c2_0, _mm_mul_pd(a2_0, b2));
#endif
    _mm_storeu_pd(&C[(l_n*88)+1], c2_0);
    __m128d c2_2 = _mm_loadu_pd(&C[(l_n*88)+7]);
    __m128d a2_2 = _mm_loadu_pd(&A[21]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_2 = _mm_add_pd(c2_2, _mm_mul_pd(a2_2, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_2 = _mm_add_pd(c2_2, _mm_mul_pd(a2_2, b2));
#endif
    _mm_storeu_pd(&C[(l_n*88)+7], c2_2);
    __m128d c2_4 = _mm_loadu_pd(&C[(l_n*88)+17]);
    __m128d a2_4 = _mm_loadu_pd(&A[23]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_4 = _mm_add_pd(c2_4, _mm_mul_pd(a2_4, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_4 = _mm_add_pd(c2_4, _mm_mul_pd(a2_4, b2));
#endif
    _mm_storeu_pd(&C[(l_n*88)+17], c2_4);
    __m128d c2_6 = _mm_loadu_pd(&C[(l_n*88)+32]);
    __m128d a2_6 = _mm_loadu_pd(&A[25]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_6 = _mm_add_pd(c2_6, _mm_mul_pd(a2_6, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_6 = _mm_add_pd(c2_6, _mm_mul_pd(a2_6, b2));
#endif
    _mm_storeu_pd(&C[(l_n*88)+32], c2_6);
    __m128d c2_8 = _mm_loadu_pd(&C[(l_n*88)+53]);
    __m128d a2_8 = _mm_loadu_pd(&A[27]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_8 = _mm_add_pd(c2_8, _mm_mul_pd(a2_8, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_8 = _mm_add_pd(c2_8, _mm_mul_pd(a2_8, b2));
#endif
    _mm_storeu_pd(&C[(l_n*88)+53], c2_8);
    __m128d c2_10 = _mm_loadu_pd(&C[(l_n*88)+81]);
    __m128d a2_10 = _mm_loadu_pd(&A[29]);
#if defined(__SSE3__) && defined(__AVX__)
    c2_10 = _mm_add_pd(c2_10, _mm_mul_pd(a2_10, _mm256_castpd256_pd128(b2)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c2_10 = _mm_add_pd(c2_10, _mm_mul_pd(a2_10, b2));
#endif
    _mm_storeu_pd(&C[(l_n*88)+81], c2_10);
#else
    C[(l_n*88)+1] += A[19] * B[(l_n*88)+2];
    C[(l_n*88)+2] += A[20] * B[(l_n*88)+2];
    C[(l_n*88)+7] += A[21] * B[(l_n*88)+2];
    C[(l_n*88)+8] += A[22] * B[(l_n*88)+2];
    C[(l_n*88)+17] += A[23] * B[(l_n*88)+2];
    C[(l_n*88)+18] += A[24] * B[(l_n*88)+2];
    C[(l_n*88)+32] += A[25] * B[(l_n*88)+2];
    C[(l_n*88)+33] += A[26] * B[(l_n*88)+2];
    C[(l_n*88)+53] += A[27] * B[(l_n*88)+2];
    C[(l_n*88)+54] += A[28] * B[(l_n*88)+2];
    C[(l_n*88)+81] += A[29] * B[(l_n*88)+2];
    C[(l_n*88)+82] += A[30] * B[(l_n*88)+2];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b3 = _mm256_broadcast_sd(&B[(l_n*88)+3]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b3 = _mm_loaddup_pd(&B[(l_n*88)+3]);
#endif
    __m128d c3_0 = _mm_load_sd(&C[(l_n*88)+0]);
    __m128d a3_0 = _mm_load_sd(&A[31]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_0 = _mm_add_sd(c3_0, _mm_mul_sd(a3_0, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_0 = _mm_add_sd(c3_0, _mm_mul_sd(a3_0, b3));
#endif
    _mm_store_sd(&C[(l_n*88)+0], c3_0);
    __m128d c3_1 = _mm_load_sd(&C[(l_n*88)+3]);
    __m128d a3_1 = _mm_load_sd(&A[32]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_1 = _mm_add_sd(c3_1, _mm_mul_sd(a3_1, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_1 = _mm_add_sd(c3_1, _mm_mul_sd(a3_1, b3));
#endif
    _mm_store_sd(&C[(l_n*88)+3], c3_1);
    __m128d c3_2 = _mm_load_sd(&C[(l_n*88)+9]);
    __m128d a3_2 = _mm_load_sd(&A[33]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_2 = _mm_add_sd(c3_2, _mm_mul_sd(a3_2, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_2 = _mm_add_sd(c3_2, _mm_mul_sd(a3_2, b3));
#endif
    _mm_store_sd(&C[(l_n*88)+9], c3_2);
    __m128d c3_3 = _mm_load_sd(&C[(l_n*88)+19]);
    __m128d a3_3 = _mm_load_sd(&A[34]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_3 = _mm_add_sd(c3_3, _mm_mul_sd(a3_3, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_3 = _mm_add_sd(c3_3, _mm_mul_sd(a3_3, b3));
#endif
    _mm_store_sd(&C[(l_n*88)+19], c3_3);
    __m128d c3_4 = _mm_load_sd(&C[(l_n*88)+34]);
    __m128d a3_4 = _mm_load_sd(&A[35]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_4 = _mm_add_sd(c3_4, _mm_mul_sd(a3_4, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_4 = _mm_add_sd(c3_4, _mm_mul_sd(a3_4, b3));
#endif
    _mm_store_sd(&C[(l_n*88)+34], c3_4);
    __m128d c3_5 = _mm_load_sd(&C[(l_n*88)+55]);
    __m128d a3_5 = _mm_load_sd(&A[36]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_5 = _mm_add_sd(c3_5, _mm_mul_sd(a3_5, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_5 = _mm_add_sd(c3_5, _mm_mul_sd(a3_5, b3));
#endif
    _mm_store_sd(&C[(l_n*88)+55], c3_5);
    __m128d c3_6 = _mm_load_sd(&C[(l_n*88)+83]);
    __m128d a3_6 = _mm_load_sd(&A[37]);
#if defined(__SSE3__) && defined(__AVX__)
    c3_6 = _mm_add_sd(c3_6, _mm_mul_sd(a3_6, _mm256_castpd256_pd128(b3)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c3_6 = _mm_add_sd(c3_6, _mm_mul_sd(a3_6, b3));
#endif
    _mm_store_sd(&C[(l_n*88)+83], c3_6);
#else
    C[(l_n*88)+0] += A[31] * B[(l_n*88)+3];
    C[(l_n*88)+3] += A[32] * B[(l_n*88)+3];
    C[(l_n*88)+9] += A[33] * B[(l_n*88)+3];
    C[(l_n*88)+19] += A[34] * B[(l_n*88)+3];
    C[(l_n*88)+34] += A[35] * B[(l_n*88)+3];
    C[(l_n*88)+55] += A[36] * B[(l_n*88)+3];
    C[(l_n*88)+83] += A[37] * B[(l_n*88)+3];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b4 = _mm256_broadcast_sd(&B[(l_n*88)+4]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b4 = _mm_loaddup_pd(&B[(l_n*88)+4]);
#endif
    __m128d c4_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a4_0 = _mm_loadu_pd(&A[38]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_0 = _mm_add_pd(c4_0, _mm_mul_pd(a4_0, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_0 = _mm_add_pd(c4_0, _mm_mul_pd(a4_0, b4));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c4_0);
    __m128d c4_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a4_2 = _mm_load_sd(&A[40]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_2 = _mm_add_sd(c4_2, _mm_mul_sd(a4_2, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_2 = _mm_add_sd(c4_2, _mm_mul_sd(a4_2, b4));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c4_2);
    __m128d c4_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a4_3 = _mm_loadu_pd(&A[41]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_3 = _mm_add_pd(c4_3, _mm_mul_pd(a4_3, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_3 = _mm_add_pd(c4_3, _mm_mul_pd(a4_3, b4));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c4_3);
    __m128d c4_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a4_5 = _mm_load_sd(&A[43]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_5 = _mm_add_sd(c4_5, _mm_mul_sd(a4_5, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_5 = _mm_add_sd(c4_5, _mm_mul_sd(a4_5, b4));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c4_5);
    __m128d c4_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a4_6 = _mm_loadu_pd(&A[44]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_6 = _mm_add_pd(c4_6, _mm_mul_pd(a4_6, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_6 = _mm_add_pd(c4_6, _mm_mul_pd(a4_6, b4));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c4_6);
    __m128d c4_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a4_8 = _mm_load_sd(&A[46]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_8 = _mm_add_sd(c4_8, _mm_mul_sd(a4_8, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_8 = _mm_add_sd(c4_8, _mm_mul_sd(a4_8, b4));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c4_8);
    __m128d c4_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a4_9 = _mm_loadu_pd(&A[47]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_9 = _mm_add_pd(c4_9, _mm_mul_pd(a4_9, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_9 = _mm_add_pd(c4_9, _mm_mul_pd(a4_9, b4));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c4_9);
    __m128d c4_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a4_11 = _mm_load_sd(&A[49]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_11 = _mm_add_sd(c4_11, _mm_mul_sd(a4_11, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_11 = _mm_add_sd(c4_11, _mm_mul_sd(a4_11, b4));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c4_11);
    __m128d c4_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a4_12 = _mm_loadu_pd(&A[50]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_12 = _mm_add_pd(c4_12, _mm_mul_pd(a4_12, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_12 = _mm_add_pd(c4_12, _mm_mul_pd(a4_12, b4));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c4_12);
    __m128d c4_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a4_14 = _mm_load_sd(&A[52]);
#if defined(__SSE3__) && defined(__AVX__)
    c4_14 = _mm_add_sd(c4_14, _mm_mul_sd(a4_14, _mm256_castpd256_pd128(b4)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c4_14 = _mm_add_sd(c4_14, _mm_mul_sd(a4_14, b4));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c4_14);
#else
    C[(l_n*88)+4] += A[38] * B[(l_n*88)+4];
    C[(l_n*88)+5] += A[39] * B[(l_n*88)+4];
    C[(l_n*88)+6] += A[40] * B[(l_n*88)+4];
    C[(l_n*88)+14] += A[41] * B[(l_n*88)+4];
    C[(l_n*88)+15] += A[42] * B[(l_n*88)+4];
    C[(l_n*88)+16] += A[43] * B[(l_n*88)+4];
    C[(l_n*88)+29] += A[44] * B[(l_n*88)+4];
    C[(l_n*88)+30] += A[45] * B[(l_n*88)+4];
    C[(l_n*88)+31] += A[46] * B[(l_n*88)+4];
    C[(l_n*88)+50] += A[47] * B[(l_n*88)+4];
    C[(l_n*88)+51] += A[48] * B[(l_n*88)+4];
    C[(l_n*88)+52] += A[49] * B[(l_n*88)+4];
    C[(l_n*88)+78] += A[50] * B[(l_n*88)+4];
    C[(l_n*88)+79] += A[51] * B[(l_n*88)+4];
    C[(l_n*88)+80] += A[52] * B[(l_n*88)+4];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b5 = _mm256_broadcast_sd(&B[(l_n*88)+5]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b5 = _mm_loaddup_pd(&B[(l_n*88)+5]);
#endif
    __m128d c5_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a5_0 = _mm_loadu_pd(&A[53]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_0 = _mm_add_pd(c5_0, _mm_mul_pd(a5_0, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_0 = _mm_add_pd(c5_0, _mm_mul_pd(a5_0, b5));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c5_0);
    __m128d c5_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a5_2 = _mm_load_sd(&A[55]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_2 = _mm_add_sd(c5_2, _mm_mul_sd(a5_2, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_2 = _mm_add_sd(c5_2, _mm_mul_sd(a5_2, b5));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c5_2);
    __m128d c5_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a5_3 = _mm_loadu_pd(&A[56]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_3 = _mm_add_pd(c5_3, _mm_mul_pd(a5_3, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_3 = _mm_add_pd(c5_3, _mm_mul_pd(a5_3, b5));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c5_3);
    __m128d c5_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a5_5 = _mm_load_sd(&A[58]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_5 = _mm_add_sd(c5_5, _mm_mul_sd(a5_5, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_5 = _mm_add_sd(c5_5, _mm_mul_sd(a5_5, b5));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c5_5);
    __m128d c5_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a5_6 = _mm_loadu_pd(&A[59]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_6 = _mm_add_pd(c5_6, _mm_mul_pd(a5_6, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_6 = _mm_add_pd(c5_6, _mm_mul_pd(a5_6, b5));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c5_6);
    __m128d c5_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a5_8 = _mm_load_sd(&A[61]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_8 = _mm_add_sd(c5_8, _mm_mul_sd(a5_8, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_8 = _mm_add_sd(c5_8, _mm_mul_sd(a5_8, b5));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c5_8);
    __m128d c5_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a5_9 = _mm_loadu_pd(&A[62]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_9 = _mm_add_pd(c5_9, _mm_mul_pd(a5_9, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_9 = _mm_add_pd(c5_9, _mm_mul_pd(a5_9, b5));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c5_9);
    __m128d c5_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a5_11 = _mm_load_sd(&A[64]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_11 = _mm_add_sd(c5_11, _mm_mul_sd(a5_11, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_11 = _mm_add_sd(c5_11, _mm_mul_sd(a5_11, b5));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c5_11);
    __m128d c5_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a5_12 = _mm_loadu_pd(&A[65]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_12 = _mm_add_pd(c5_12, _mm_mul_pd(a5_12, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_12 = _mm_add_pd(c5_12, _mm_mul_pd(a5_12, b5));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c5_12);
    __m128d c5_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a5_14 = _mm_load_sd(&A[67]);
#if defined(__SSE3__) && defined(__AVX__)
    c5_14 = _mm_add_sd(c5_14, _mm_mul_sd(a5_14, _mm256_castpd256_pd128(b5)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c5_14 = _mm_add_sd(c5_14, _mm_mul_sd(a5_14, b5));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c5_14);
#else
    C[(l_n*88)+4] += A[53] * B[(l_n*88)+5];
    C[(l_n*88)+5] += A[54] * B[(l_n*88)+5];
    C[(l_n*88)+6] += A[55] * B[(l_n*88)+5];
    C[(l_n*88)+14] += A[56] * B[(l_n*88)+5];
    C[(l_n*88)+15] += A[57] * B[(l_n*88)+5];
    C[(l_n*88)+16] += A[58] * B[(l_n*88)+5];
    C[(l_n*88)+29] += A[59] * B[(l_n*88)+5];
    C[(l_n*88)+30] += A[60] * B[(l_n*88)+5];
    C[(l_n*88)+31] += A[61] * B[(l_n*88)+5];
    C[(l_n*88)+50] += A[62] * B[(l_n*88)+5];
    C[(l_n*88)+51] += A[63] * B[(l_n*88)+5];
    C[(l_n*88)+52] += A[64] * B[(l_n*88)+5];
    C[(l_n*88)+78] += A[65] * B[(l_n*88)+5];
    C[(l_n*88)+79] += A[66] * B[(l_n*88)+5];
    C[(l_n*88)+80] += A[67] * B[(l_n*88)+5];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b6 = _mm256_broadcast_sd(&B[(l_n*88)+6]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b6 = _mm_loaddup_pd(&B[(l_n*88)+6]);
#endif
    __m128d c6_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a6_0 = _mm_loadu_pd(&A[68]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_0 = _mm_add_pd(c6_0, _mm_mul_pd(a6_0, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_0 = _mm_add_pd(c6_0, _mm_mul_pd(a6_0, b6));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c6_0);
    __m128d c6_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a6_2 = _mm_load_sd(&A[70]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_2 = _mm_add_sd(c6_2, _mm_mul_sd(a6_2, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_2 = _mm_add_sd(c6_2, _mm_mul_sd(a6_2, b6));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c6_2);
    __m128d c6_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a6_3 = _mm_loadu_pd(&A[71]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_3 = _mm_add_pd(c6_3, _mm_mul_pd(a6_3, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_3 = _mm_add_pd(c6_3, _mm_mul_pd(a6_3, b6));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c6_3);
    __m128d c6_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a6_5 = _mm_load_sd(&A[73]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_5 = _mm_add_sd(c6_5, _mm_mul_sd(a6_5, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_5 = _mm_add_sd(c6_5, _mm_mul_sd(a6_5, b6));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c6_5);
    __m128d c6_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a6_6 = _mm_loadu_pd(&A[74]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_6 = _mm_add_pd(c6_6, _mm_mul_pd(a6_6, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_6 = _mm_add_pd(c6_6, _mm_mul_pd(a6_6, b6));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c6_6);
    __m128d c6_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a6_8 = _mm_load_sd(&A[76]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_8 = _mm_add_sd(c6_8, _mm_mul_sd(a6_8, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_8 = _mm_add_sd(c6_8, _mm_mul_sd(a6_8, b6));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c6_8);
    __m128d c6_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a6_9 = _mm_loadu_pd(&A[77]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_9 = _mm_add_pd(c6_9, _mm_mul_pd(a6_9, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_9 = _mm_add_pd(c6_9, _mm_mul_pd(a6_9, b6));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c6_9);
    __m128d c6_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a6_11 = _mm_load_sd(&A[79]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_11 = _mm_add_sd(c6_11, _mm_mul_sd(a6_11, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_11 = _mm_add_sd(c6_11, _mm_mul_sd(a6_11, b6));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c6_11);
    __m128d c6_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a6_12 = _mm_loadu_pd(&A[80]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_12 = _mm_add_pd(c6_12, _mm_mul_pd(a6_12, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_12 = _mm_add_pd(c6_12, _mm_mul_pd(a6_12, b6));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c6_12);
    __m128d c6_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a6_14 = _mm_load_sd(&A[82]);
#if defined(__SSE3__) && defined(__AVX__)
    c6_14 = _mm_add_sd(c6_14, _mm_mul_sd(a6_14, _mm256_castpd256_pd128(b6)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c6_14 = _mm_add_sd(c6_14, _mm_mul_sd(a6_14, b6));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c6_14);
#else
    C[(l_n*88)+4] += A[68] * B[(l_n*88)+6];
    C[(l_n*88)+5] += A[69] * B[(l_n*88)+6];
    C[(l_n*88)+6] += A[70] * B[(l_n*88)+6];
    C[(l_n*88)+14] += A[71] * B[(l_n*88)+6];
    C[(l_n*88)+15] += A[72] * B[(l_n*88)+6];
    C[(l_n*88)+16] += A[73] * B[(l_n*88)+6];
    C[(l_n*88)+29] += A[74] * B[(l_n*88)+6];
    C[(l_n*88)+30] += A[75] * B[(l_n*88)+6];
    C[(l_n*88)+31] += A[76] * B[(l_n*88)+6];
    C[(l_n*88)+50] += A[77] * B[(l_n*88)+6];
    C[(l_n*88)+51] += A[78] * B[(l_n*88)+6];
    C[(l_n*88)+52] += A[79] * B[(l_n*88)+6];
    C[(l_n*88)+78] += A[80] * B[(l_n*88)+6];
    C[(l_n*88)+79] += A[81] * B[(l_n*88)+6];
    C[(l_n*88)+80] += A[82] * B[(l_n*88)+6];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b7 = _mm256_broadcast_sd(&B[(l_n*88)+7]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b7 = _mm_loaddup_pd(&B[(l_n*88)+7]);
#endif
    __m128d c7_0 = _mm_loadu_pd(&C[(l_n*88)+1]);
    __m128d a7_0 = _mm_loadu_pd(&A[83]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_0 = _mm_add_pd(c7_0, _mm_mul_pd(a7_0, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_0 = _mm_add_pd(c7_0, _mm_mul_pd(a7_0, b7));
#endif
    _mm_storeu_pd(&C[(l_n*88)+1], c7_0);
    __m128d c7_2 = _mm_loadu_pd(&C[(l_n*88)+7]);
    __m128d a7_2 = _mm_loadu_pd(&A[85]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_2 = _mm_add_pd(c7_2, _mm_mul_pd(a7_2, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_2 = _mm_add_pd(c7_2, _mm_mul_pd(a7_2, b7));
#endif
    _mm_storeu_pd(&C[(l_n*88)+7], c7_2);
    __m128d c7_4 = _mm_loadu_pd(&C[(l_n*88)+17]);
    __m128d a7_4 = _mm_loadu_pd(&A[87]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_4 = _mm_add_pd(c7_4, _mm_mul_pd(a7_4, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_4 = _mm_add_pd(c7_4, _mm_mul_pd(a7_4, b7));
#endif
    _mm_storeu_pd(&C[(l_n*88)+17], c7_4);
    __m128d c7_6 = _mm_loadu_pd(&C[(l_n*88)+32]);
    __m128d a7_6 = _mm_loadu_pd(&A[89]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_6 = _mm_add_pd(c7_6, _mm_mul_pd(a7_6, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_6 = _mm_add_pd(c7_6, _mm_mul_pd(a7_6, b7));
#endif
    _mm_storeu_pd(&C[(l_n*88)+32], c7_6);
    __m128d c7_8 = _mm_loadu_pd(&C[(l_n*88)+53]);
    __m128d a7_8 = _mm_loadu_pd(&A[91]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_8 = _mm_add_pd(c7_8, _mm_mul_pd(a7_8, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_8 = _mm_add_pd(c7_8, _mm_mul_pd(a7_8, b7));
#endif
    _mm_storeu_pd(&C[(l_n*88)+53], c7_8);
    __m128d c7_10 = _mm_loadu_pd(&C[(l_n*88)+81]);
    __m128d a7_10 = _mm_loadu_pd(&A[93]);
#if defined(__SSE3__) && defined(__AVX__)
    c7_10 = _mm_add_pd(c7_10, _mm_mul_pd(a7_10, _mm256_castpd256_pd128(b7)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c7_10 = _mm_add_pd(c7_10, _mm_mul_pd(a7_10, b7));
#endif
    _mm_storeu_pd(&C[(l_n*88)+81], c7_10);
#else
    C[(l_n*88)+1] += A[83] * B[(l_n*88)+7];
    C[(l_n*88)+2] += A[84] * B[(l_n*88)+7];
    C[(l_n*88)+7] += A[85] * B[(l_n*88)+7];
    C[(l_n*88)+8] += A[86] * B[(l_n*88)+7];
    C[(l_n*88)+17] += A[87] * B[(l_n*88)+7];
    C[(l_n*88)+18] += A[88] * B[(l_n*88)+7];
    C[(l_n*88)+32] += A[89] * B[(l_n*88)+7];
    C[(l_n*88)+33] += A[90] * B[(l_n*88)+7];
    C[(l_n*88)+53] += A[91] * B[(l_n*88)+7];
    C[(l_n*88)+54] += A[92] * B[(l_n*88)+7];
    C[(l_n*88)+81] += A[93] * B[(l_n*88)+7];
    C[(l_n*88)+82] += A[94] * B[(l_n*88)+7];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b8 = _mm256_broadcast_sd(&B[(l_n*88)+8]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b8 = _mm_loaddup_pd(&B[(l_n*88)+8]);
#endif
    __m128d c8_0 = _mm_loadu_pd(&C[(l_n*88)+1]);
    __m128d a8_0 = _mm_loadu_pd(&A[95]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_0 = _mm_add_pd(c8_0, _mm_mul_pd(a8_0, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_0 = _mm_add_pd(c8_0, _mm_mul_pd(a8_0, b8));
#endif
    _mm_storeu_pd(&C[(l_n*88)+1], c8_0);
    __m128d c8_2 = _mm_loadu_pd(&C[(l_n*88)+7]);
    __m128d a8_2 = _mm_loadu_pd(&A[97]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_2 = _mm_add_pd(c8_2, _mm_mul_pd(a8_2, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_2 = _mm_add_pd(c8_2, _mm_mul_pd(a8_2, b8));
#endif
    _mm_storeu_pd(&C[(l_n*88)+7], c8_2);
    __m128d c8_4 = _mm_loadu_pd(&C[(l_n*88)+17]);
    __m128d a8_4 = _mm_loadu_pd(&A[99]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_4 = _mm_add_pd(c8_4, _mm_mul_pd(a8_4, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_4 = _mm_add_pd(c8_4, _mm_mul_pd(a8_4, b8));
#endif
    _mm_storeu_pd(&C[(l_n*88)+17], c8_4);
    __m128d c8_6 = _mm_loadu_pd(&C[(l_n*88)+32]);
    __m128d a8_6 = _mm_loadu_pd(&A[101]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_6 = _mm_add_pd(c8_6, _mm_mul_pd(a8_6, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_6 = _mm_add_pd(c8_6, _mm_mul_pd(a8_6, b8));
#endif
    _mm_storeu_pd(&C[(l_n*88)+32], c8_6);
    __m128d c8_8 = _mm_loadu_pd(&C[(l_n*88)+53]);
    __m128d a8_8 = _mm_loadu_pd(&A[103]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_8 = _mm_add_pd(c8_8, _mm_mul_pd(a8_8, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_8 = _mm_add_pd(c8_8, _mm_mul_pd(a8_8, b8));
#endif
    _mm_storeu_pd(&C[(l_n*88)+53], c8_8);
    __m128d c8_10 = _mm_loadu_pd(&C[(l_n*88)+81]);
    __m128d a8_10 = _mm_loadu_pd(&A[105]);
#if defined(__SSE3__) && defined(__AVX__)
    c8_10 = _mm_add_pd(c8_10, _mm_mul_pd(a8_10, _mm256_castpd256_pd128(b8)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c8_10 = _mm_add_pd(c8_10, _mm_mul_pd(a8_10, b8));
#endif
    _mm_storeu_pd(&C[(l_n*88)+81], c8_10);
#else
    C[(l_n*88)+1] += A[95] * B[(l_n*88)+8];
    C[(l_n*88)+2] += A[96] * B[(l_n*88)+8];
    C[(l_n*88)+7] += A[97] * B[(l_n*88)+8];
    C[(l_n*88)+8] += A[98] * B[(l_n*88)+8];
    C[(l_n*88)+17] += A[99] * B[(l_n*88)+8];
    C[(l_n*88)+18] += A[100] * B[(l_n*88)+8];
    C[(l_n*88)+32] += A[101] * B[(l_n*88)+8];
    C[(l_n*88)+33] += A[102] * B[(l_n*88)+8];
    C[(l_n*88)+53] += A[103] * B[(l_n*88)+8];
    C[(l_n*88)+54] += A[104] * B[(l_n*88)+8];
    C[(l_n*88)+81] += A[105] * B[(l_n*88)+8];
    C[(l_n*88)+82] += A[106] * B[(l_n*88)+8];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b9 = _mm256_broadcast_sd(&B[(l_n*88)+9]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b9 = _mm_loaddup_pd(&B[(l_n*88)+9]);
#endif
    __m128d c9_0 = _mm_load_sd(&C[(l_n*88)+0]);
    __m128d a9_0 = _mm_load_sd(&A[107]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_0 = _mm_add_sd(c9_0, _mm_mul_sd(a9_0, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_0 = _mm_add_sd(c9_0, _mm_mul_sd(a9_0, b9));
#endif
    _mm_store_sd(&C[(l_n*88)+0], c9_0);
    __m128d c9_1 = _mm_load_sd(&C[(l_n*88)+3]);
    __m128d a9_1 = _mm_load_sd(&A[108]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_1 = _mm_add_sd(c9_1, _mm_mul_sd(a9_1, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_1 = _mm_add_sd(c9_1, _mm_mul_sd(a9_1, b9));
#endif
    _mm_store_sd(&C[(l_n*88)+3], c9_1);
    __m128d c9_2 = _mm_load_sd(&C[(l_n*88)+9]);
    __m128d a9_2 = _mm_load_sd(&A[109]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_2 = _mm_add_sd(c9_2, _mm_mul_sd(a9_2, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_2 = _mm_add_sd(c9_2, _mm_mul_sd(a9_2, b9));
#endif
    _mm_store_sd(&C[(l_n*88)+9], c9_2);
    __m128d c9_3 = _mm_load_sd(&C[(l_n*88)+19]);
    __m128d a9_3 = _mm_load_sd(&A[110]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_3 = _mm_add_sd(c9_3, _mm_mul_sd(a9_3, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_3 = _mm_add_sd(c9_3, _mm_mul_sd(a9_3, b9));
#endif
    _mm_store_sd(&C[(l_n*88)+19], c9_3);
    __m128d c9_4 = _mm_load_sd(&C[(l_n*88)+34]);
    __m128d a9_4 = _mm_load_sd(&A[111]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_4 = _mm_add_sd(c9_4, _mm_mul_sd(a9_4, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_4 = _mm_add_sd(c9_4, _mm_mul_sd(a9_4, b9));
#endif
    _mm_store_sd(&C[(l_n*88)+34], c9_4);
    __m128d c9_5 = _mm_load_sd(&C[(l_n*88)+55]);
    __m128d a9_5 = _mm_load_sd(&A[112]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_5 = _mm_add_sd(c9_5, _mm_mul_sd(a9_5, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_5 = _mm_add_sd(c9_5, _mm_mul_sd(a9_5, b9));
#endif
    _mm_store_sd(&C[(l_n*88)+55], c9_5);
    __m128d c9_6 = _mm_load_sd(&C[(l_n*88)+83]);
    __m128d a9_6 = _mm_load_sd(&A[113]);
#if defined(__SSE3__) && defined(__AVX__)
    c9_6 = _mm_add_sd(c9_6, _mm_mul_sd(a9_6, _mm256_castpd256_pd128(b9)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c9_6 = _mm_add_sd(c9_6, _mm_mul_sd(a9_6, b9));
#endif
    _mm_store_sd(&C[(l_n*88)+83], c9_6);
#else
    C[(l_n*88)+0] += A[107] * B[(l_n*88)+9];
    C[(l_n*88)+3] += A[108] * B[(l_n*88)+9];
    C[(l_n*88)+9] += A[109] * B[(l_n*88)+9];
    C[(l_n*88)+19] += A[110] * B[(l_n*88)+9];
    C[(l_n*88)+34] += A[111] * B[(l_n*88)+9];
    C[(l_n*88)+55] += A[112] * B[(l_n*88)+9];
    C[(l_n*88)+83] += A[113] * B[(l_n*88)+9];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b10 = _mm256_broadcast_sd(&B[(l_n*88)+10]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b10 = _mm_loaddup_pd(&B[(l_n*88)+10]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c10_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a10_0 = _mm256_loadu_pd(&A[114]);
    c10_0 = _mm256_add_pd(c10_0, _mm256_mul_pd(a10_0, b10));
    _mm256_storeu_pd(&C[(l_n*88)+10], c10_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c10_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a10_0 = _mm_loadu_pd(&A[114]);
    c10_0 = _mm_add_pd(c10_0, _mm_mul_pd(a10_0, b10));
    _mm_storeu_pd(&C[(l_n*88)+10], c10_0);
    __m128d c10_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a10_2 = _mm_loadu_pd(&A[116]);
    c10_2 = _mm_add_pd(c10_2, _mm_mul_pd(a10_2, b10));
    _mm_storeu_pd(&C[(l_n*88)+12], c10_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c10_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a10_4 = _mm256_loadu_pd(&A[118]);
    c10_4 = _mm256_add_pd(c10_4, _mm256_mul_pd(a10_4, b10));
    _mm256_storeu_pd(&C[(l_n*88)+25], c10_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c10_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a10_4 = _mm_loadu_pd(&A[118]);
    c10_4 = _mm_add_pd(c10_4, _mm_mul_pd(a10_4, b10));
    _mm_storeu_pd(&C[(l_n*88)+25], c10_4);
    __m128d c10_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a10_6 = _mm_loadu_pd(&A[120]);
    c10_6 = _mm_add_pd(c10_6, _mm_mul_pd(a10_6, b10));
    _mm_storeu_pd(&C[(l_n*88)+27], c10_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c10_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a10_8 = _mm256_loadu_pd(&A[122]);
    c10_8 = _mm256_add_pd(c10_8, _mm256_mul_pd(a10_8, b10));
    _mm256_storeu_pd(&C[(l_n*88)+46], c10_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c10_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a10_8 = _mm_loadu_pd(&A[122]);
    c10_8 = _mm_add_pd(c10_8, _mm_mul_pd(a10_8, b10));
    _mm_storeu_pd(&C[(l_n*88)+46], c10_8);
    __m128d c10_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a10_10 = _mm_loadu_pd(&A[124]);
    c10_10 = _mm_add_pd(c10_10, _mm_mul_pd(a10_10, b10));
    _mm_storeu_pd(&C[(l_n*88)+48], c10_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c10_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a10_12 = _mm256_loadu_pd(&A[126]);
    c10_12 = _mm256_add_pd(c10_12, _mm256_mul_pd(a10_12, b10));
    _mm256_storeu_pd(&C[(l_n*88)+74], c10_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c10_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a10_12 = _mm_loadu_pd(&A[126]);
    c10_12 = _mm_add_pd(c10_12, _mm_mul_pd(a10_12, b10));
    _mm_storeu_pd(&C[(l_n*88)+74], c10_12);
    __m128d c10_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a10_14 = _mm_loadu_pd(&A[128]);
    c10_14 = _mm_add_pd(c10_14, _mm_mul_pd(a10_14, b10));
    _mm_storeu_pd(&C[(l_n*88)+76], c10_14);
#endif
#else
    C[(l_n*88)+10] += A[114] * B[(l_n*88)+10];
    C[(l_n*88)+11] += A[115] * B[(l_n*88)+10];
    C[(l_n*88)+12] += A[116] * B[(l_n*88)+10];
    C[(l_n*88)+13] += A[117] * B[(l_n*88)+10];
    C[(l_n*88)+25] += A[118] * B[(l_n*88)+10];
    C[(l_n*88)+26] += A[119] * B[(l_n*88)+10];
    C[(l_n*88)+27] += A[120] * B[(l_n*88)+10];
    C[(l_n*88)+28] += A[121] * B[(l_n*88)+10];
    C[(l_n*88)+46] += A[122] * B[(l_n*88)+10];
    C[(l_n*88)+47] += A[123] * B[(l_n*88)+10];
    C[(l_n*88)+48] += A[124] * B[(l_n*88)+10];
    C[(l_n*88)+49] += A[125] * B[(l_n*88)+10];
    C[(l_n*88)+74] += A[126] * B[(l_n*88)+10];
    C[(l_n*88)+75] += A[127] * B[(l_n*88)+10];
    C[(l_n*88)+76] += A[128] * B[(l_n*88)+10];
    C[(l_n*88)+77] += A[129] * B[(l_n*88)+10];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b11 = _mm256_broadcast_sd(&B[(l_n*88)+11]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b11 = _mm_loaddup_pd(&B[(l_n*88)+11]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c11_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a11_0 = _mm256_loadu_pd(&A[130]);
    c11_0 = _mm256_add_pd(c11_0, _mm256_mul_pd(a11_0, b11));
    _mm256_storeu_pd(&C[(l_n*88)+10], c11_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c11_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a11_0 = _mm_loadu_pd(&A[130]);
    c11_0 = _mm_add_pd(c11_0, _mm_mul_pd(a11_0, b11));
    _mm_storeu_pd(&C[(l_n*88)+10], c11_0);
    __m128d c11_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a11_2 = _mm_loadu_pd(&A[132]);
    c11_2 = _mm_add_pd(c11_2, _mm_mul_pd(a11_2, b11));
    _mm_storeu_pd(&C[(l_n*88)+12], c11_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c11_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a11_4 = _mm256_loadu_pd(&A[134]);
    c11_4 = _mm256_add_pd(c11_4, _mm256_mul_pd(a11_4, b11));
    _mm256_storeu_pd(&C[(l_n*88)+25], c11_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c11_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a11_4 = _mm_loadu_pd(&A[134]);
    c11_4 = _mm_add_pd(c11_4, _mm_mul_pd(a11_4, b11));
    _mm_storeu_pd(&C[(l_n*88)+25], c11_4);
    __m128d c11_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a11_6 = _mm_loadu_pd(&A[136]);
    c11_6 = _mm_add_pd(c11_6, _mm_mul_pd(a11_6, b11));
    _mm_storeu_pd(&C[(l_n*88)+27], c11_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c11_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a11_8 = _mm256_loadu_pd(&A[138]);
    c11_8 = _mm256_add_pd(c11_8, _mm256_mul_pd(a11_8, b11));
    _mm256_storeu_pd(&C[(l_n*88)+46], c11_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c11_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a11_8 = _mm_loadu_pd(&A[138]);
    c11_8 = _mm_add_pd(c11_8, _mm_mul_pd(a11_8, b11));
    _mm_storeu_pd(&C[(l_n*88)+46], c11_8);
    __m128d c11_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a11_10 = _mm_loadu_pd(&A[140]);
    c11_10 = _mm_add_pd(c11_10, _mm_mul_pd(a11_10, b11));
    _mm_storeu_pd(&C[(l_n*88)+48], c11_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c11_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a11_12 = _mm256_loadu_pd(&A[142]);
    c11_12 = _mm256_add_pd(c11_12, _mm256_mul_pd(a11_12, b11));
    _mm256_storeu_pd(&C[(l_n*88)+74], c11_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c11_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a11_12 = _mm_loadu_pd(&A[142]);
    c11_12 = _mm_add_pd(c11_12, _mm_mul_pd(a11_12, b11));
    _mm_storeu_pd(&C[(l_n*88)+74], c11_12);
    __m128d c11_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a11_14 = _mm_loadu_pd(&A[144]);
    c11_14 = _mm_add_pd(c11_14, _mm_mul_pd(a11_14, b11));
    _mm_storeu_pd(&C[(l_n*88)+76], c11_14);
#endif
#else
    C[(l_n*88)+10] += A[130] * B[(l_n*88)+11];
    C[(l_n*88)+11] += A[131] * B[(l_n*88)+11];
    C[(l_n*88)+12] += A[132] * B[(l_n*88)+11];
    C[(l_n*88)+13] += A[133] * B[(l_n*88)+11];
    C[(l_n*88)+25] += A[134] * B[(l_n*88)+11];
    C[(l_n*88)+26] += A[135] * B[(l_n*88)+11];
    C[(l_n*88)+27] += A[136] * B[(l_n*88)+11];
    C[(l_n*88)+28] += A[137] * B[(l_n*88)+11];
    C[(l_n*88)+46] += A[138] * B[(l_n*88)+11];
    C[(l_n*88)+47] += A[139] * B[(l_n*88)+11];
    C[(l_n*88)+48] += A[140] * B[(l_n*88)+11];
    C[(l_n*88)+49] += A[141] * B[(l_n*88)+11];
    C[(l_n*88)+74] += A[142] * B[(l_n*88)+11];
    C[(l_n*88)+75] += A[143] * B[(l_n*88)+11];
    C[(l_n*88)+76] += A[144] * B[(l_n*88)+11];
    C[(l_n*88)+77] += A[145] * B[(l_n*88)+11];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b12 = _mm256_broadcast_sd(&B[(l_n*88)+12]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b12 = _mm_loaddup_pd(&B[(l_n*88)+12]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c12_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a12_0 = _mm256_loadu_pd(&A[146]);
    c12_0 = _mm256_add_pd(c12_0, _mm256_mul_pd(a12_0, b12));
    _mm256_storeu_pd(&C[(l_n*88)+10], c12_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c12_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a12_0 = _mm_loadu_pd(&A[146]);
    c12_0 = _mm_add_pd(c12_0, _mm_mul_pd(a12_0, b12));
    _mm_storeu_pd(&C[(l_n*88)+10], c12_0);
    __m128d c12_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a12_2 = _mm_loadu_pd(&A[148]);
    c12_2 = _mm_add_pd(c12_2, _mm_mul_pd(a12_2, b12));
    _mm_storeu_pd(&C[(l_n*88)+12], c12_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c12_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a12_4 = _mm256_loadu_pd(&A[150]);
    c12_4 = _mm256_add_pd(c12_4, _mm256_mul_pd(a12_4, b12));
    _mm256_storeu_pd(&C[(l_n*88)+25], c12_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c12_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a12_4 = _mm_loadu_pd(&A[150]);
    c12_4 = _mm_add_pd(c12_4, _mm_mul_pd(a12_4, b12));
    _mm_storeu_pd(&C[(l_n*88)+25], c12_4);
    __m128d c12_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a12_6 = _mm_loadu_pd(&A[152]);
    c12_6 = _mm_add_pd(c12_6, _mm_mul_pd(a12_6, b12));
    _mm_storeu_pd(&C[(l_n*88)+27], c12_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c12_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a12_8 = _mm256_loadu_pd(&A[154]);
    c12_8 = _mm256_add_pd(c12_8, _mm256_mul_pd(a12_8, b12));
    _mm256_storeu_pd(&C[(l_n*88)+46], c12_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c12_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a12_8 = _mm_loadu_pd(&A[154]);
    c12_8 = _mm_add_pd(c12_8, _mm_mul_pd(a12_8, b12));
    _mm_storeu_pd(&C[(l_n*88)+46], c12_8);
    __m128d c12_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a12_10 = _mm_loadu_pd(&A[156]);
    c12_10 = _mm_add_pd(c12_10, _mm_mul_pd(a12_10, b12));
    _mm_storeu_pd(&C[(l_n*88)+48], c12_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c12_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a12_12 = _mm256_loadu_pd(&A[158]);
    c12_12 = _mm256_add_pd(c12_12, _mm256_mul_pd(a12_12, b12));
    _mm256_storeu_pd(&C[(l_n*88)+74], c12_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c12_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a12_12 = _mm_loadu_pd(&A[158]);
    c12_12 = _mm_add_pd(c12_12, _mm_mul_pd(a12_12, b12));
    _mm_storeu_pd(&C[(l_n*88)+74], c12_12);
    __m128d c12_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a12_14 = _mm_loadu_pd(&A[160]);
    c12_14 = _mm_add_pd(c12_14, _mm_mul_pd(a12_14, b12));
    _mm_storeu_pd(&C[(l_n*88)+76], c12_14);
#endif
#else
    C[(l_n*88)+10] += A[146] * B[(l_n*88)+12];
    C[(l_n*88)+11] += A[147] * B[(l_n*88)+12];
    C[(l_n*88)+12] += A[148] * B[(l_n*88)+12];
    C[(l_n*88)+13] += A[149] * B[(l_n*88)+12];
    C[(l_n*88)+25] += A[150] * B[(l_n*88)+12];
    C[(l_n*88)+26] += A[151] * B[(l_n*88)+12];
    C[(l_n*88)+27] += A[152] * B[(l_n*88)+12];
    C[(l_n*88)+28] += A[153] * B[(l_n*88)+12];
    C[(l_n*88)+46] += A[154] * B[(l_n*88)+12];
    C[(l_n*88)+47] += A[155] * B[(l_n*88)+12];
    C[(l_n*88)+48] += A[156] * B[(l_n*88)+12];
    C[(l_n*88)+49] += A[157] * B[(l_n*88)+12];
    C[(l_n*88)+74] += A[158] * B[(l_n*88)+12];
    C[(l_n*88)+75] += A[159] * B[(l_n*88)+12];
    C[(l_n*88)+76] += A[160] * B[(l_n*88)+12];
    C[(l_n*88)+77] += A[161] * B[(l_n*88)+12];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b13 = _mm256_broadcast_sd(&B[(l_n*88)+13]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b13 = _mm_loaddup_pd(&B[(l_n*88)+13]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c13_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a13_0 = _mm256_loadu_pd(&A[162]);
    c13_0 = _mm256_add_pd(c13_0, _mm256_mul_pd(a13_0, b13));
    _mm256_storeu_pd(&C[(l_n*88)+10], c13_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c13_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a13_0 = _mm_loadu_pd(&A[162]);
    c13_0 = _mm_add_pd(c13_0, _mm_mul_pd(a13_0, b13));
    _mm_storeu_pd(&C[(l_n*88)+10], c13_0);
    __m128d c13_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a13_2 = _mm_loadu_pd(&A[164]);
    c13_2 = _mm_add_pd(c13_2, _mm_mul_pd(a13_2, b13));
    _mm_storeu_pd(&C[(l_n*88)+12], c13_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c13_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a13_4 = _mm256_loadu_pd(&A[166]);
    c13_4 = _mm256_add_pd(c13_4, _mm256_mul_pd(a13_4, b13));
    _mm256_storeu_pd(&C[(l_n*88)+25], c13_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c13_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a13_4 = _mm_loadu_pd(&A[166]);
    c13_4 = _mm_add_pd(c13_4, _mm_mul_pd(a13_4, b13));
    _mm_storeu_pd(&C[(l_n*88)+25], c13_4);
    __m128d c13_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a13_6 = _mm_loadu_pd(&A[168]);
    c13_6 = _mm_add_pd(c13_6, _mm_mul_pd(a13_6, b13));
    _mm_storeu_pd(&C[(l_n*88)+27], c13_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c13_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a13_8 = _mm256_loadu_pd(&A[170]);
    c13_8 = _mm256_add_pd(c13_8, _mm256_mul_pd(a13_8, b13));
    _mm256_storeu_pd(&C[(l_n*88)+46], c13_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c13_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a13_8 = _mm_loadu_pd(&A[170]);
    c13_8 = _mm_add_pd(c13_8, _mm_mul_pd(a13_8, b13));
    _mm_storeu_pd(&C[(l_n*88)+46], c13_8);
    __m128d c13_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a13_10 = _mm_loadu_pd(&A[172]);
    c13_10 = _mm_add_pd(c13_10, _mm_mul_pd(a13_10, b13));
    _mm_storeu_pd(&C[(l_n*88)+48], c13_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c13_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a13_12 = _mm256_loadu_pd(&A[174]);
    c13_12 = _mm256_add_pd(c13_12, _mm256_mul_pd(a13_12, b13));
    _mm256_storeu_pd(&C[(l_n*88)+74], c13_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c13_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a13_12 = _mm_loadu_pd(&A[174]);
    c13_12 = _mm_add_pd(c13_12, _mm_mul_pd(a13_12, b13));
    _mm_storeu_pd(&C[(l_n*88)+74], c13_12);
    __m128d c13_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a13_14 = _mm_loadu_pd(&A[176]);
    c13_14 = _mm_add_pd(c13_14, _mm_mul_pd(a13_14, b13));
    _mm_storeu_pd(&C[(l_n*88)+76], c13_14);
#endif
#else
    C[(l_n*88)+10] += A[162] * B[(l_n*88)+13];
    C[(l_n*88)+11] += A[163] * B[(l_n*88)+13];
    C[(l_n*88)+12] += A[164] * B[(l_n*88)+13];
    C[(l_n*88)+13] += A[165] * B[(l_n*88)+13];
    C[(l_n*88)+25] += A[166] * B[(l_n*88)+13];
    C[(l_n*88)+26] += A[167] * B[(l_n*88)+13];
    C[(l_n*88)+27] += A[168] * B[(l_n*88)+13];
    C[(l_n*88)+28] += A[169] * B[(l_n*88)+13];
    C[(l_n*88)+46] += A[170] * B[(l_n*88)+13];
    C[(l_n*88)+47] += A[171] * B[(l_n*88)+13];
    C[(l_n*88)+48] += A[172] * B[(l_n*88)+13];
    C[(l_n*88)+49] += A[173] * B[(l_n*88)+13];
    C[(l_n*88)+74] += A[174] * B[(l_n*88)+13];
    C[(l_n*88)+75] += A[175] * B[(l_n*88)+13];
    C[(l_n*88)+76] += A[176] * B[(l_n*88)+13];
    C[(l_n*88)+77] += A[177] * B[(l_n*88)+13];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b14 = _mm256_broadcast_sd(&B[(l_n*88)+14]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b14 = _mm_loaddup_pd(&B[(l_n*88)+14]);
#endif
    __m128d c14_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a14_0 = _mm_loadu_pd(&A[178]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_0 = _mm_add_pd(c14_0, _mm_mul_pd(a14_0, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_0 = _mm_add_pd(c14_0, _mm_mul_pd(a14_0, b14));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c14_0);
    __m128d c14_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a14_2 = _mm_load_sd(&A[180]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_2 = _mm_add_sd(c14_2, _mm_mul_sd(a14_2, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_2 = _mm_add_sd(c14_2, _mm_mul_sd(a14_2, b14));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c14_2);
    __m128d c14_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a14_3 = _mm_loadu_pd(&A[181]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_3 = _mm_add_pd(c14_3, _mm_mul_pd(a14_3, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_3 = _mm_add_pd(c14_3, _mm_mul_pd(a14_3, b14));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c14_3);
    __m128d c14_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a14_5 = _mm_load_sd(&A[183]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_5 = _mm_add_sd(c14_5, _mm_mul_sd(a14_5, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_5 = _mm_add_sd(c14_5, _mm_mul_sd(a14_5, b14));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c14_5);
    __m128d c14_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a14_6 = _mm_loadu_pd(&A[184]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_6 = _mm_add_pd(c14_6, _mm_mul_pd(a14_6, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_6 = _mm_add_pd(c14_6, _mm_mul_pd(a14_6, b14));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c14_6);
    __m128d c14_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a14_8 = _mm_load_sd(&A[186]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_8 = _mm_add_sd(c14_8, _mm_mul_sd(a14_8, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_8 = _mm_add_sd(c14_8, _mm_mul_sd(a14_8, b14));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c14_8);
    __m128d c14_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a14_9 = _mm_loadu_pd(&A[187]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_9 = _mm_add_pd(c14_9, _mm_mul_pd(a14_9, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_9 = _mm_add_pd(c14_9, _mm_mul_pd(a14_9, b14));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c14_9);
    __m128d c14_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a14_11 = _mm_load_sd(&A[189]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_11 = _mm_add_sd(c14_11, _mm_mul_sd(a14_11, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_11 = _mm_add_sd(c14_11, _mm_mul_sd(a14_11, b14));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c14_11);
    __m128d c14_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a14_12 = _mm_loadu_pd(&A[190]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_12 = _mm_add_pd(c14_12, _mm_mul_pd(a14_12, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_12 = _mm_add_pd(c14_12, _mm_mul_pd(a14_12, b14));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c14_12);
    __m128d c14_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a14_14 = _mm_load_sd(&A[192]);
#if defined(__SSE3__) && defined(__AVX__)
    c14_14 = _mm_add_sd(c14_14, _mm_mul_sd(a14_14, _mm256_castpd256_pd128(b14)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c14_14 = _mm_add_sd(c14_14, _mm_mul_sd(a14_14, b14));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c14_14);
#else
    C[(l_n*88)+4] += A[178] * B[(l_n*88)+14];
    C[(l_n*88)+5] += A[179] * B[(l_n*88)+14];
    C[(l_n*88)+6] += A[180] * B[(l_n*88)+14];
    C[(l_n*88)+14] += A[181] * B[(l_n*88)+14];
    C[(l_n*88)+15] += A[182] * B[(l_n*88)+14];
    C[(l_n*88)+16] += A[183] * B[(l_n*88)+14];
    C[(l_n*88)+29] += A[184] * B[(l_n*88)+14];
    C[(l_n*88)+30] += A[185] * B[(l_n*88)+14];
    C[(l_n*88)+31] += A[186] * B[(l_n*88)+14];
    C[(l_n*88)+50] += A[187] * B[(l_n*88)+14];
    C[(l_n*88)+51] += A[188] * B[(l_n*88)+14];
    C[(l_n*88)+52] += A[189] * B[(l_n*88)+14];
    C[(l_n*88)+78] += A[190] * B[(l_n*88)+14];
    C[(l_n*88)+79] += A[191] * B[(l_n*88)+14];
    C[(l_n*88)+80] += A[192] * B[(l_n*88)+14];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b15 = _mm256_broadcast_sd(&B[(l_n*88)+15]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b15 = _mm_loaddup_pd(&B[(l_n*88)+15]);
#endif
    __m128d c15_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a15_0 = _mm_loadu_pd(&A[193]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_0 = _mm_add_pd(c15_0, _mm_mul_pd(a15_0, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_0 = _mm_add_pd(c15_0, _mm_mul_pd(a15_0, b15));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c15_0);
    __m128d c15_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a15_2 = _mm_load_sd(&A[195]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_2 = _mm_add_sd(c15_2, _mm_mul_sd(a15_2, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_2 = _mm_add_sd(c15_2, _mm_mul_sd(a15_2, b15));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c15_2);
    __m128d c15_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a15_3 = _mm_loadu_pd(&A[196]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_3 = _mm_add_pd(c15_3, _mm_mul_pd(a15_3, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_3 = _mm_add_pd(c15_3, _mm_mul_pd(a15_3, b15));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c15_3);
    __m128d c15_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a15_5 = _mm_load_sd(&A[198]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_5 = _mm_add_sd(c15_5, _mm_mul_sd(a15_5, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_5 = _mm_add_sd(c15_5, _mm_mul_sd(a15_5, b15));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c15_5);
    __m128d c15_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a15_6 = _mm_loadu_pd(&A[199]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_6 = _mm_add_pd(c15_6, _mm_mul_pd(a15_6, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_6 = _mm_add_pd(c15_6, _mm_mul_pd(a15_6, b15));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c15_6);
    __m128d c15_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a15_8 = _mm_load_sd(&A[201]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_8 = _mm_add_sd(c15_8, _mm_mul_sd(a15_8, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_8 = _mm_add_sd(c15_8, _mm_mul_sd(a15_8, b15));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c15_8);
    __m128d c15_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a15_9 = _mm_loadu_pd(&A[202]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_9 = _mm_add_pd(c15_9, _mm_mul_pd(a15_9, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_9 = _mm_add_pd(c15_9, _mm_mul_pd(a15_9, b15));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c15_9);
    __m128d c15_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a15_11 = _mm_load_sd(&A[204]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_11 = _mm_add_sd(c15_11, _mm_mul_sd(a15_11, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_11 = _mm_add_sd(c15_11, _mm_mul_sd(a15_11, b15));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c15_11);
    __m128d c15_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a15_12 = _mm_loadu_pd(&A[205]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_12 = _mm_add_pd(c15_12, _mm_mul_pd(a15_12, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_12 = _mm_add_pd(c15_12, _mm_mul_pd(a15_12, b15));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c15_12);
    __m128d c15_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a15_14 = _mm_load_sd(&A[207]);
#if defined(__SSE3__) && defined(__AVX__)
    c15_14 = _mm_add_sd(c15_14, _mm_mul_sd(a15_14, _mm256_castpd256_pd128(b15)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c15_14 = _mm_add_sd(c15_14, _mm_mul_sd(a15_14, b15));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c15_14);
#else
    C[(l_n*88)+4] += A[193] * B[(l_n*88)+15];
    C[(l_n*88)+5] += A[194] * B[(l_n*88)+15];
    C[(l_n*88)+6] += A[195] * B[(l_n*88)+15];
    C[(l_n*88)+14] += A[196] * B[(l_n*88)+15];
    C[(l_n*88)+15] += A[197] * B[(l_n*88)+15];
    C[(l_n*88)+16] += A[198] * B[(l_n*88)+15];
    C[(l_n*88)+29] += A[199] * B[(l_n*88)+15];
    C[(l_n*88)+30] += A[200] * B[(l_n*88)+15];
    C[(l_n*88)+31] += A[201] * B[(l_n*88)+15];
    C[(l_n*88)+50] += A[202] * B[(l_n*88)+15];
    C[(l_n*88)+51] += A[203] * B[(l_n*88)+15];
    C[(l_n*88)+52] += A[204] * B[(l_n*88)+15];
    C[(l_n*88)+78] += A[205] * B[(l_n*88)+15];
    C[(l_n*88)+79] += A[206] * B[(l_n*88)+15];
    C[(l_n*88)+80] += A[207] * B[(l_n*88)+15];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b16 = _mm256_broadcast_sd(&B[(l_n*88)+16]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b16 = _mm_loaddup_pd(&B[(l_n*88)+16]);
#endif
    __m128d c16_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a16_0 = _mm_loadu_pd(&A[208]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_0 = _mm_add_pd(c16_0, _mm_mul_pd(a16_0, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_0 = _mm_add_pd(c16_0, _mm_mul_pd(a16_0, b16));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c16_0);
    __m128d c16_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a16_2 = _mm_load_sd(&A[210]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_2 = _mm_add_sd(c16_2, _mm_mul_sd(a16_2, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_2 = _mm_add_sd(c16_2, _mm_mul_sd(a16_2, b16));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c16_2);
    __m128d c16_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a16_3 = _mm_loadu_pd(&A[211]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_3 = _mm_add_pd(c16_3, _mm_mul_pd(a16_3, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_3 = _mm_add_pd(c16_3, _mm_mul_pd(a16_3, b16));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c16_3);
    __m128d c16_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a16_5 = _mm_load_sd(&A[213]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_5 = _mm_add_sd(c16_5, _mm_mul_sd(a16_5, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_5 = _mm_add_sd(c16_5, _mm_mul_sd(a16_5, b16));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c16_5);
    __m128d c16_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a16_6 = _mm_loadu_pd(&A[214]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_6 = _mm_add_pd(c16_6, _mm_mul_pd(a16_6, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_6 = _mm_add_pd(c16_6, _mm_mul_pd(a16_6, b16));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c16_6);
    __m128d c16_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a16_8 = _mm_load_sd(&A[216]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_8 = _mm_add_sd(c16_8, _mm_mul_sd(a16_8, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_8 = _mm_add_sd(c16_8, _mm_mul_sd(a16_8, b16));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c16_8);
    __m128d c16_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a16_9 = _mm_loadu_pd(&A[217]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_9 = _mm_add_pd(c16_9, _mm_mul_pd(a16_9, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_9 = _mm_add_pd(c16_9, _mm_mul_pd(a16_9, b16));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c16_9);
    __m128d c16_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a16_11 = _mm_load_sd(&A[219]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_11 = _mm_add_sd(c16_11, _mm_mul_sd(a16_11, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_11 = _mm_add_sd(c16_11, _mm_mul_sd(a16_11, b16));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c16_11);
    __m128d c16_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a16_12 = _mm_loadu_pd(&A[220]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_12 = _mm_add_pd(c16_12, _mm_mul_pd(a16_12, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_12 = _mm_add_pd(c16_12, _mm_mul_pd(a16_12, b16));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c16_12);
    __m128d c16_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a16_14 = _mm_load_sd(&A[222]);
#if defined(__SSE3__) && defined(__AVX__)
    c16_14 = _mm_add_sd(c16_14, _mm_mul_sd(a16_14, _mm256_castpd256_pd128(b16)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c16_14 = _mm_add_sd(c16_14, _mm_mul_sd(a16_14, b16));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c16_14);
#else
    C[(l_n*88)+4] += A[208] * B[(l_n*88)+16];
    C[(l_n*88)+5] += A[209] * B[(l_n*88)+16];
    C[(l_n*88)+6] += A[210] * B[(l_n*88)+16];
    C[(l_n*88)+14] += A[211] * B[(l_n*88)+16];
    C[(l_n*88)+15] += A[212] * B[(l_n*88)+16];
    C[(l_n*88)+16] += A[213] * B[(l_n*88)+16];
    C[(l_n*88)+29] += A[214] * B[(l_n*88)+16];
    C[(l_n*88)+30] += A[215] * B[(l_n*88)+16];
    C[(l_n*88)+31] += A[216] * B[(l_n*88)+16];
    C[(l_n*88)+50] += A[217] * B[(l_n*88)+16];
    C[(l_n*88)+51] += A[218] * B[(l_n*88)+16];
    C[(l_n*88)+52] += A[219] * B[(l_n*88)+16];
    C[(l_n*88)+78] += A[220] * B[(l_n*88)+16];
    C[(l_n*88)+79] += A[221] * B[(l_n*88)+16];
    C[(l_n*88)+80] += A[222] * B[(l_n*88)+16];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b17 = _mm256_broadcast_sd(&B[(l_n*88)+17]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b17 = _mm_loaddup_pd(&B[(l_n*88)+17]);
#endif
    __m128d c17_0 = _mm_loadu_pd(&C[(l_n*88)+1]);
    __m128d a17_0 = _mm_loadu_pd(&A[223]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_0 = _mm_add_pd(c17_0, _mm_mul_pd(a17_0, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_0 = _mm_add_pd(c17_0, _mm_mul_pd(a17_0, b17));
#endif
    _mm_storeu_pd(&C[(l_n*88)+1], c17_0);
    __m128d c17_2 = _mm_loadu_pd(&C[(l_n*88)+7]);
    __m128d a17_2 = _mm_loadu_pd(&A[225]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_2 = _mm_add_pd(c17_2, _mm_mul_pd(a17_2, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_2 = _mm_add_pd(c17_2, _mm_mul_pd(a17_2, b17));
#endif
    _mm_storeu_pd(&C[(l_n*88)+7], c17_2);
    __m128d c17_4 = _mm_loadu_pd(&C[(l_n*88)+17]);
    __m128d a17_4 = _mm_loadu_pd(&A[227]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_4 = _mm_add_pd(c17_4, _mm_mul_pd(a17_4, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_4 = _mm_add_pd(c17_4, _mm_mul_pd(a17_4, b17));
#endif
    _mm_storeu_pd(&C[(l_n*88)+17], c17_4);
    __m128d c17_6 = _mm_loadu_pd(&C[(l_n*88)+32]);
    __m128d a17_6 = _mm_loadu_pd(&A[229]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_6 = _mm_add_pd(c17_6, _mm_mul_pd(a17_6, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_6 = _mm_add_pd(c17_6, _mm_mul_pd(a17_6, b17));
#endif
    _mm_storeu_pd(&C[(l_n*88)+32], c17_6);
    __m128d c17_8 = _mm_loadu_pd(&C[(l_n*88)+53]);
    __m128d a17_8 = _mm_loadu_pd(&A[231]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_8 = _mm_add_pd(c17_8, _mm_mul_pd(a17_8, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_8 = _mm_add_pd(c17_8, _mm_mul_pd(a17_8, b17));
#endif
    _mm_storeu_pd(&C[(l_n*88)+53], c17_8);
    __m128d c17_10 = _mm_loadu_pd(&C[(l_n*88)+81]);
    __m128d a17_10 = _mm_loadu_pd(&A[233]);
#if defined(__SSE3__) && defined(__AVX__)
    c17_10 = _mm_add_pd(c17_10, _mm_mul_pd(a17_10, _mm256_castpd256_pd128(b17)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c17_10 = _mm_add_pd(c17_10, _mm_mul_pd(a17_10, b17));
#endif
    _mm_storeu_pd(&C[(l_n*88)+81], c17_10);
#else
    C[(l_n*88)+1] += A[223] * B[(l_n*88)+17];
    C[(l_n*88)+2] += A[224] * B[(l_n*88)+17];
    C[(l_n*88)+7] += A[225] * B[(l_n*88)+17];
    C[(l_n*88)+8] += A[226] * B[(l_n*88)+17];
    C[(l_n*88)+17] += A[227] * B[(l_n*88)+17];
    C[(l_n*88)+18] += A[228] * B[(l_n*88)+17];
    C[(l_n*88)+32] += A[229] * B[(l_n*88)+17];
    C[(l_n*88)+33] += A[230] * B[(l_n*88)+17];
    C[(l_n*88)+53] += A[231] * B[(l_n*88)+17];
    C[(l_n*88)+54] += A[232] * B[(l_n*88)+17];
    C[(l_n*88)+81] += A[233] * B[(l_n*88)+17];
    C[(l_n*88)+82] += A[234] * B[(l_n*88)+17];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b18 = _mm256_broadcast_sd(&B[(l_n*88)+18]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b18 = _mm_loaddup_pd(&B[(l_n*88)+18]);
#endif
    __m128d c18_0 = _mm_loadu_pd(&C[(l_n*88)+1]);
    __m128d a18_0 = _mm_loadu_pd(&A[235]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_0 = _mm_add_pd(c18_0, _mm_mul_pd(a18_0, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_0 = _mm_add_pd(c18_0, _mm_mul_pd(a18_0, b18));
#endif
    _mm_storeu_pd(&C[(l_n*88)+1], c18_0);
    __m128d c18_2 = _mm_loadu_pd(&C[(l_n*88)+7]);
    __m128d a18_2 = _mm_loadu_pd(&A[237]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_2 = _mm_add_pd(c18_2, _mm_mul_pd(a18_2, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_2 = _mm_add_pd(c18_2, _mm_mul_pd(a18_2, b18));
#endif
    _mm_storeu_pd(&C[(l_n*88)+7], c18_2);
    __m128d c18_4 = _mm_loadu_pd(&C[(l_n*88)+17]);
    __m128d a18_4 = _mm_loadu_pd(&A[239]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_4 = _mm_add_pd(c18_4, _mm_mul_pd(a18_4, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_4 = _mm_add_pd(c18_4, _mm_mul_pd(a18_4, b18));
#endif
    _mm_storeu_pd(&C[(l_n*88)+17], c18_4);
    __m128d c18_6 = _mm_loadu_pd(&C[(l_n*88)+32]);
    __m128d a18_6 = _mm_loadu_pd(&A[241]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_6 = _mm_add_pd(c18_6, _mm_mul_pd(a18_6, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_6 = _mm_add_pd(c18_6, _mm_mul_pd(a18_6, b18));
#endif
    _mm_storeu_pd(&C[(l_n*88)+32], c18_6);
    __m128d c18_8 = _mm_loadu_pd(&C[(l_n*88)+53]);
    __m128d a18_8 = _mm_loadu_pd(&A[243]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_8 = _mm_add_pd(c18_8, _mm_mul_pd(a18_8, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_8 = _mm_add_pd(c18_8, _mm_mul_pd(a18_8, b18));
#endif
    _mm_storeu_pd(&C[(l_n*88)+53], c18_8);
    __m128d c18_10 = _mm_loadu_pd(&C[(l_n*88)+81]);
    __m128d a18_10 = _mm_loadu_pd(&A[245]);
#if defined(__SSE3__) && defined(__AVX__)
    c18_10 = _mm_add_pd(c18_10, _mm_mul_pd(a18_10, _mm256_castpd256_pd128(b18)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c18_10 = _mm_add_pd(c18_10, _mm_mul_pd(a18_10, b18));
#endif
    _mm_storeu_pd(&C[(l_n*88)+81], c18_10);
#else
    C[(l_n*88)+1] += A[235] * B[(l_n*88)+18];
    C[(l_n*88)+2] += A[236] * B[(l_n*88)+18];
    C[(l_n*88)+7] += A[237] * B[(l_n*88)+18];
    C[(l_n*88)+8] += A[238] * B[(l_n*88)+18];
    C[(l_n*88)+17] += A[239] * B[(l_n*88)+18];
    C[(l_n*88)+18] += A[240] * B[(l_n*88)+18];
    C[(l_n*88)+32] += A[241] * B[(l_n*88)+18];
    C[(l_n*88)+33] += A[242] * B[(l_n*88)+18];
    C[(l_n*88)+53] += A[243] * B[(l_n*88)+18];
    C[(l_n*88)+54] += A[244] * B[(l_n*88)+18];
    C[(l_n*88)+81] += A[245] * B[(l_n*88)+18];
    C[(l_n*88)+82] += A[246] * B[(l_n*88)+18];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b19 = _mm256_broadcast_sd(&B[(l_n*88)+19]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b19 = _mm_loaddup_pd(&B[(l_n*88)+19]);
#endif
    __m128d c19_0 = _mm_load_sd(&C[(l_n*88)+0]);
    __m128d a19_0 = _mm_load_sd(&A[247]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_0 = _mm_add_sd(c19_0, _mm_mul_sd(a19_0, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_0 = _mm_add_sd(c19_0, _mm_mul_sd(a19_0, b19));
#endif
    _mm_store_sd(&C[(l_n*88)+0], c19_0);
    __m128d c19_1 = _mm_load_sd(&C[(l_n*88)+3]);
    __m128d a19_1 = _mm_load_sd(&A[248]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_1 = _mm_add_sd(c19_1, _mm_mul_sd(a19_1, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_1 = _mm_add_sd(c19_1, _mm_mul_sd(a19_1, b19));
#endif
    _mm_store_sd(&C[(l_n*88)+3], c19_1);
    __m128d c19_2 = _mm_load_sd(&C[(l_n*88)+9]);
    __m128d a19_2 = _mm_load_sd(&A[249]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_2 = _mm_add_sd(c19_2, _mm_mul_sd(a19_2, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_2 = _mm_add_sd(c19_2, _mm_mul_sd(a19_2, b19));
#endif
    _mm_store_sd(&C[(l_n*88)+9], c19_2);
    __m128d c19_3 = _mm_load_sd(&C[(l_n*88)+19]);
    __m128d a19_3 = _mm_load_sd(&A[250]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_3 = _mm_add_sd(c19_3, _mm_mul_sd(a19_3, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_3 = _mm_add_sd(c19_3, _mm_mul_sd(a19_3, b19));
#endif
    _mm_store_sd(&C[(l_n*88)+19], c19_3);
    __m128d c19_4 = _mm_load_sd(&C[(l_n*88)+34]);
    __m128d a19_4 = _mm_load_sd(&A[251]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_4 = _mm_add_sd(c19_4, _mm_mul_sd(a19_4, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_4 = _mm_add_sd(c19_4, _mm_mul_sd(a19_4, b19));
#endif
    _mm_store_sd(&C[(l_n*88)+34], c19_4);
    __m128d c19_5 = _mm_load_sd(&C[(l_n*88)+55]);
    __m128d a19_5 = _mm_load_sd(&A[252]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_5 = _mm_add_sd(c19_5, _mm_mul_sd(a19_5, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_5 = _mm_add_sd(c19_5, _mm_mul_sd(a19_5, b19));
#endif
    _mm_store_sd(&C[(l_n*88)+55], c19_5);
    __m128d c19_6 = _mm_load_sd(&C[(l_n*88)+83]);
    __m128d a19_6 = _mm_load_sd(&A[253]);
#if defined(__SSE3__) && defined(__AVX__)
    c19_6 = _mm_add_sd(c19_6, _mm_mul_sd(a19_6, _mm256_castpd256_pd128(b19)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c19_6 = _mm_add_sd(c19_6, _mm_mul_sd(a19_6, b19));
#endif
    _mm_store_sd(&C[(l_n*88)+83], c19_6);
#else
    C[(l_n*88)+0] += A[247] * B[(l_n*88)+19];
    C[(l_n*88)+3] += A[248] * B[(l_n*88)+19];
    C[(l_n*88)+9] += A[249] * B[(l_n*88)+19];
    C[(l_n*88)+19] += A[250] * B[(l_n*88)+19];
    C[(l_n*88)+34] += A[251] * B[(l_n*88)+19];
    C[(l_n*88)+55] += A[252] * B[(l_n*88)+19];
    C[(l_n*88)+83] += A[253] * B[(l_n*88)+19];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b20 = _mm256_broadcast_sd(&B[(l_n*88)+20]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b20 = _mm_loaddup_pd(&B[(l_n*88)+20]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c20_0 = _mm256_loadu_pd(&C[(l_n*88)+20]);
    __m256d a20_0 = _mm256_loadu_pd(&A[254]);
    c20_0 = _mm256_add_pd(c20_0, _mm256_mul_pd(a20_0, b20));
    _mm256_storeu_pd(&C[(l_n*88)+20], c20_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c20_0 = _mm_loadu_pd(&C[(l_n*88)+20]);
    __m128d a20_0 = _mm_loadu_pd(&A[254]);
    c20_0 = _mm_add_pd(c20_0, _mm_mul_pd(a20_0, b20));
    _mm_storeu_pd(&C[(l_n*88)+20], c20_0);
    __m128d c20_2 = _mm_loadu_pd(&C[(l_n*88)+22]);
    __m128d a20_2 = _mm_loadu_pd(&A[256]);
    c20_2 = _mm_add_pd(c20_2, _mm_mul_pd(a20_2, b20));
    _mm_storeu_pd(&C[(l_n*88)+22], c20_2);
#endif
    __m128d c20_4 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a20_4 = _mm_load_sd(&A[258]);
#if defined(__SSE3__) && defined(__AVX__)
    c20_4 = _mm_add_sd(c20_4, _mm_mul_sd(a20_4, _mm256_castpd256_pd128(b20)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c20_4 = _mm_add_sd(c20_4, _mm_mul_sd(a20_4, b20));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c20_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c20_5 = _mm256_loadu_pd(&C[(l_n*88)+41]);
    __m256d a20_5 = _mm256_loadu_pd(&A[259]);
    c20_5 = _mm256_add_pd(c20_5, _mm256_mul_pd(a20_5, b20));
    _mm256_storeu_pd(&C[(l_n*88)+41], c20_5);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c20_5 = _mm_loadu_pd(&C[(l_n*88)+41]);
    __m128d a20_5 = _mm_loadu_pd(&A[259]);
    c20_5 = _mm_add_pd(c20_5, _mm_mul_pd(a20_5, b20));
    _mm_storeu_pd(&C[(l_n*88)+41], c20_5);
    __m128d c20_7 = _mm_loadu_pd(&C[(l_n*88)+43]);
    __m128d a20_7 = _mm_loadu_pd(&A[261]);
    c20_7 = _mm_add_pd(c20_7, _mm_mul_pd(a20_7, b20));
    _mm_storeu_pd(&C[(l_n*88)+43], c20_7);
#endif
    __m128d c20_9 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a20_9 = _mm_load_sd(&A[263]);
#if defined(__SSE3__) && defined(__AVX__)
    c20_9 = _mm_add_sd(c20_9, _mm_mul_sd(a20_9, _mm256_castpd256_pd128(b20)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c20_9 = _mm_add_sd(c20_9, _mm_mul_sd(a20_9, b20));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c20_9);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c20_10 = _mm256_loadu_pd(&C[(l_n*88)+69]);
    __m256d a20_10 = _mm256_loadu_pd(&A[264]);
    c20_10 = _mm256_add_pd(c20_10, _mm256_mul_pd(a20_10, b20));
    _mm256_storeu_pd(&C[(l_n*88)+69], c20_10);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c20_10 = _mm_loadu_pd(&C[(l_n*88)+69]);
    __m128d a20_10 = _mm_loadu_pd(&A[264]);
    c20_10 = _mm_add_pd(c20_10, _mm_mul_pd(a20_10, b20));
    _mm_storeu_pd(&C[(l_n*88)+69], c20_10);
    __m128d c20_12 = _mm_loadu_pd(&C[(l_n*88)+71]);
    __m128d a20_12 = _mm_loadu_pd(&A[266]);
    c20_12 = _mm_add_pd(c20_12, _mm_mul_pd(a20_12, b20));
    _mm_storeu_pd(&C[(l_n*88)+71], c20_12);
#endif
    __m128d c20_14 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a20_14 = _mm_load_sd(&A[268]);
#if defined(__SSE3__) && defined(__AVX__)
    c20_14 = _mm_add_sd(c20_14, _mm_mul_sd(a20_14, _mm256_castpd256_pd128(b20)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c20_14 = _mm_add_sd(c20_14, _mm_mul_sd(a20_14, b20));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c20_14);
#else
    C[(l_n*88)+20] += A[254] * B[(l_n*88)+20];
    C[(l_n*88)+21] += A[255] * B[(l_n*88)+20];
    C[(l_n*88)+22] += A[256] * B[(l_n*88)+20];
    C[(l_n*88)+23] += A[257] * B[(l_n*88)+20];
    C[(l_n*88)+24] += A[258] * B[(l_n*88)+20];
    C[(l_n*88)+41] += A[259] * B[(l_n*88)+20];
    C[(l_n*88)+42] += A[260] * B[(l_n*88)+20];
    C[(l_n*88)+43] += A[261] * B[(l_n*88)+20];
    C[(l_n*88)+44] += A[262] * B[(l_n*88)+20];
    C[(l_n*88)+45] += A[263] * B[(l_n*88)+20];
    C[(l_n*88)+69] += A[264] * B[(l_n*88)+20];
    C[(l_n*88)+70] += A[265] * B[(l_n*88)+20];
    C[(l_n*88)+71] += A[266] * B[(l_n*88)+20];
    C[(l_n*88)+72] += A[267] * B[(l_n*88)+20];
    C[(l_n*88)+73] += A[268] * B[(l_n*88)+20];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b21 = _mm256_broadcast_sd(&B[(l_n*88)+21]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b21 = _mm_loaddup_pd(&B[(l_n*88)+21]);
#endif
    __m128d c21_0 = _mm_loadu_pd(&C[(l_n*88)+20]);
    __m128d a21_0 = _mm_loadu_pd(&A[269]);
#if defined(__SSE3__) && defined(__AVX__)
    c21_0 = _mm_add_pd(c21_0, _mm_mul_pd(a21_0, _mm256_castpd256_pd128(b21)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c21_0 = _mm_add_pd(c21_0, _mm_mul_pd(a21_0, b21));
#endif
    _mm_storeu_pd(&C[(l_n*88)+20], c21_0);
    __m128d c21_2 = _mm_load_sd(&C[(l_n*88)+22]);
    __m128d a21_2 = _mm_load_sd(&A[271]);
#if defined(__SSE3__) && defined(__AVX__)
    c21_2 = _mm_add_sd(c21_2, _mm_mul_sd(a21_2, _mm256_castpd256_pd128(b21)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c21_2 = _mm_add_sd(c21_2, _mm_mul_sd(a21_2, b21));
#endif
    _mm_store_sd(&C[(l_n*88)+22], c21_2);
    __m128d c21_3 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a21_3 = _mm_load_sd(&A[272]);
#if defined(__SSE3__) && defined(__AVX__)
    c21_3 = _mm_add_sd(c21_3, _mm_mul_sd(a21_3, _mm256_castpd256_pd128(b21)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c21_3 = _mm_add_sd(c21_3, _mm_mul_sd(a21_3, b21));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c21_3);
    __m128d c21_4 = _mm_loadu_pd(&C[(l_n*88)+41]);
    __m128d a21_4 = _mm_loadu_pd(&A[273]);
#if defined(__SSE3__) && defined(__AVX__)
    c21_4 = _mm_add_pd(c21_4, _mm_mul_pd(a21_4, _mm256_castpd256_pd128(b21)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c21_4 = _mm_add_pd(c21_4, _mm_mul_pd(a21_4, b21));
#endif
    _mm_storeu_pd(&C[(l_n*88)+41], c21_4);
    __m128d c21_6 = _mm_load_sd(&C[(l_n*88)+43]);
    __m128d a21_6 = _mm_load_sd(&A[275]);
#if defined(__SSE3__) && defined(__AVX__)
    c21_6 = _mm_add_sd(c21_6, _mm_mul_sd(a21_6, _mm256_castpd256_pd128(b21)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c21_6 = _mm_add_sd(c21_6, _mm_mul_sd(a21_6, b21));
#endif
    _mm_store_sd(&C[(l_n*88)+43], c21_6);
    __m128d c21_7 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a21_7 = _mm_load_sd(&A[276]);
#if defined(__SSE3__) && defined(__AVX__)
    c21_7 = _mm_add_sd(c21_7, _mm_mul_sd(a21_7, _mm256_castpd256_pd128(b21)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c21_7 = _mm_add_sd(c21_7, _mm_mul_sd(a21_7, b21));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c21_7);
    __m128d c21_8 = _mm_loadu_pd(&C[(l_n*88)+69]);
    __m128d a21_8 = _mm_loadu_pd(&A[277]);
#if defined(__SSE3__) && defined(__AVX__)
    c21_8 = _mm_add_pd(c21_8, _mm_mul_pd(a21_8, _mm256_castpd256_pd128(b21)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c21_8 = _mm_add_pd(c21_8, _mm_mul_pd(a21_8, b21));
#endif
    _mm_storeu_pd(&C[(l_n*88)+69], c21_8);
    __m128d c21_10 = _mm_load_sd(&C[(l_n*88)+71]);
    __m128d a21_10 = _mm_load_sd(&A[279]);
#if defined(__SSE3__) && defined(__AVX__)
    c21_10 = _mm_add_sd(c21_10, _mm_mul_sd(a21_10, _mm256_castpd256_pd128(b21)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c21_10 = _mm_add_sd(c21_10, _mm_mul_sd(a21_10, b21));
#endif
    _mm_store_sd(&C[(l_n*88)+71], c21_10);
    __m128d c21_11 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a21_11 = _mm_load_sd(&A[280]);
#if defined(__SSE3__) && defined(__AVX__)
    c21_11 = _mm_add_sd(c21_11, _mm_mul_sd(a21_11, _mm256_castpd256_pd128(b21)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c21_11 = _mm_add_sd(c21_11, _mm_mul_sd(a21_11, b21));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c21_11);
#else
    C[(l_n*88)+20] += A[269] * B[(l_n*88)+21];
    C[(l_n*88)+21] += A[270] * B[(l_n*88)+21];
    C[(l_n*88)+22] += A[271] * B[(l_n*88)+21];
    C[(l_n*88)+24] += A[272] * B[(l_n*88)+21];
    C[(l_n*88)+41] += A[273] * B[(l_n*88)+21];
    C[(l_n*88)+42] += A[274] * B[(l_n*88)+21];
    C[(l_n*88)+43] += A[275] * B[(l_n*88)+21];
    C[(l_n*88)+45] += A[276] * B[(l_n*88)+21];
    C[(l_n*88)+69] += A[277] * B[(l_n*88)+21];
    C[(l_n*88)+70] += A[278] * B[(l_n*88)+21];
    C[(l_n*88)+71] += A[279] * B[(l_n*88)+21];
    C[(l_n*88)+73] += A[280] * B[(l_n*88)+21];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b22 = _mm256_broadcast_sd(&B[(l_n*88)+22]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b22 = _mm_loaddup_pd(&B[(l_n*88)+22]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c22_0 = _mm256_loadu_pd(&C[(l_n*88)+20]);
    __m256d a22_0 = _mm256_loadu_pd(&A[281]);
    c22_0 = _mm256_add_pd(c22_0, _mm256_mul_pd(a22_0, b22));
    _mm256_storeu_pd(&C[(l_n*88)+20], c22_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c22_0 = _mm_loadu_pd(&C[(l_n*88)+20]);
    __m128d a22_0 = _mm_loadu_pd(&A[281]);
    c22_0 = _mm_add_pd(c22_0, _mm_mul_pd(a22_0, b22));
    _mm_storeu_pd(&C[(l_n*88)+20], c22_0);
    __m128d c22_2 = _mm_loadu_pd(&C[(l_n*88)+22]);
    __m128d a22_2 = _mm_loadu_pd(&A[283]);
    c22_2 = _mm_add_pd(c22_2, _mm_mul_pd(a22_2, b22));
    _mm_storeu_pd(&C[(l_n*88)+22], c22_2);
#endif
    __m128d c22_4 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a22_4 = _mm_load_sd(&A[285]);
#if defined(__SSE3__) && defined(__AVX__)
    c22_4 = _mm_add_sd(c22_4, _mm_mul_sd(a22_4, _mm256_castpd256_pd128(b22)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c22_4 = _mm_add_sd(c22_4, _mm_mul_sd(a22_4, b22));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c22_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c22_5 = _mm256_loadu_pd(&C[(l_n*88)+41]);
    __m256d a22_5 = _mm256_loadu_pd(&A[286]);
    c22_5 = _mm256_add_pd(c22_5, _mm256_mul_pd(a22_5, b22));
    _mm256_storeu_pd(&C[(l_n*88)+41], c22_5);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c22_5 = _mm_loadu_pd(&C[(l_n*88)+41]);
    __m128d a22_5 = _mm_loadu_pd(&A[286]);
    c22_5 = _mm_add_pd(c22_5, _mm_mul_pd(a22_5, b22));
    _mm_storeu_pd(&C[(l_n*88)+41], c22_5);
    __m128d c22_7 = _mm_loadu_pd(&C[(l_n*88)+43]);
    __m128d a22_7 = _mm_loadu_pd(&A[288]);
    c22_7 = _mm_add_pd(c22_7, _mm_mul_pd(a22_7, b22));
    _mm_storeu_pd(&C[(l_n*88)+43], c22_7);
#endif
    __m128d c22_9 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a22_9 = _mm_load_sd(&A[290]);
#if defined(__SSE3__) && defined(__AVX__)
    c22_9 = _mm_add_sd(c22_9, _mm_mul_sd(a22_9, _mm256_castpd256_pd128(b22)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c22_9 = _mm_add_sd(c22_9, _mm_mul_sd(a22_9, b22));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c22_9);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c22_10 = _mm256_loadu_pd(&C[(l_n*88)+69]);
    __m256d a22_10 = _mm256_loadu_pd(&A[291]);
    c22_10 = _mm256_add_pd(c22_10, _mm256_mul_pd(a22_10, b22));
    _mm256_storeu_pd(&C[(l_n*88)+69], c22_10);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c22_10 = _mm_loadu_pd(&C[(l_n*88)+69]);
    __m128d a22_10 = _mm_loadu_pd(&A[291]);
    c22_10 = _mm_add_pd(c22_10, _mm_mul_pd(a22_10, b22));
    _mm_storeu_pd(&C[(l_n*88)+69], c22_10);
    __m128d c22_12 = _mm_loadu_pd(&C[(l_n*88)+71]);
    __m128d a22_12 = _mm_loadu_pd(&A[293]);
    c22_12 = _mm_add_pd(c22_12, _mm_mul_pd(a22_12, b22));
    _mm_storeu_pd(&C[(l_n*88)+71], c22_12);
#endif
    __m128d c22_14 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a22_14 = _mm_load_sd(&A[295]);
#if defined(__SSE3__) && defined(__AVX__)
    c22_14 = _mm_add_sd(c22_14, _mm_mul_sd(a22_14, _mm256_castpd256_pd128(b22)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c22_14 = _mm_add_sd(c22_14, _mm_mul_sd(a22_14, b22));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c22_14);
#else
    C[(l_n*88)+20] += A[281] * B[(l_n*88)+22];
    C[(l_n*88)+21] += A[282] * B[(l_n*88)+22];
    C[(l_n*88)+22] += A[283] * B[(l_n*88)+22];
    C[(l_n*88)+23] += A[284] * B[(l_n*88)+22];
    C[(l_n*88)+24] += A[285] * B[(l_n*88)+22];
    C[(l_n*88)+41] += A[286] * B[(l_n*88)+22];
    C[(l_n*88)+42] += A[287] * B[(l_n*88)+22];
    C[(l_n*88)+43] += A[288] * B[(l_n*88)+22];
    C[(l_n*88)+44] += A[289] * B[(l_n*88)+22];
    C[(l_n*88)+45] += A[290] * B[(l_n*88)+22];
    C[(l_n*88)+69] += A[291] * B[(l_n*88)+22];
    C[(l_n*88)+70] += A[292] * B[(l_n*88)+22];
    C[(l_n*88)+71] += A[293] * B[(l_n*88)+22];
    C[(l_n*88)+72] += A[294] * B[(l_n*88)+22];
    C[(l_n*88)+73] += A[295] * B[(l_n*88)+22];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b23 = _mm256_broadcast_sd(&B[(l_n*88)+23]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b23 = _mm_loaddup_pd(&B[(l_n*88)+23]);
#endif
    __m128d c23_0 = _mm_load_sd(&C[(l_n*88)+20]);
    __m128d a23_0 = _mm_load_sd(&A[296]);
#if defined(__SSE3__) && defined(__AVX__)
    c23_0 = _mm_add_sd(c23_0, _mm_mul_sd(a23_0, _mm256_castpd256_pd128(b23)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c23_0 = _mm_add_sd(c23_0, _mm_mul_sd(a23_0, b23));
#endif
    _mm_store_sd(&C[(l_n*88)+20], c23_0);
    __m128d c23_1 = _mm_loadu_pd(&C[(l_n*88)+22]);
    __m128d a23_1 = _mm_loadu_pd(&A[297]);
#if defined(__SSE3__) && defined(__AVX__)
    c23_1 = _mm_add_pd(c23_1, _mm_mul_pd(a23_1, _mm256_castpd256_pd128(b23)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c23_1 = _mm_add_pd(c23_1, _mm_mul_pd(a23_1, b23));
#endif
    _mm_storeu_pd(&C[(l_n*88)+22], c23_1);
    __m128d c23_3 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a23_3 = _mm_load_sd(&A[299]);
#if defined(__SSE3__) && defined(__AVX__)
    c23_3 = _mm_add_sd(c23_3, _mm_mul_sd(a23_3, _mm256_castpd256_pd128(b23)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c23_3 = _mm_add_sd(c23_3, _mm_mul_sd(a23_3, b23));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c23_3);
    __m128d c23_4 = _mm_load_sd(&C[(l_n*88)+41]);
    __m128d a23_4 = _mm_load_sd(&A[300]);
#if defined(__SSE3__) && defined(__AVX__)
    c23_4 = _mm_add_sd(c23_4, _mm_mul_sd(a23_4, _mm256_castpd256_pd128(b23)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c23_4 = _mm_add_sd(c23_4, _mm_mul_sd(a23_4, b23));
#endif
    _mm_store_sd(&C[(l_n*88)+41], c23_4);
    __m128d c23_5 = _mm_loadu_pd(&C[(l_n*88)+43]);
    __m128d a23_5 = _mm_loadu_pd(&A[301]);
#if defined(__SSE3__) && defined(__AVX__)
    c23_5 = _mm_add_pd(c23_5, _mm_mul_pd(a23_5, _mm256_castpd256_pd128(b23)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c23_5 = _mm_add_pd(c23_5, _mm_mul_pd(a23_5, b23));
#endif
    _mm_storeu_pd(&C[(l_n*88)+43], c23_5);
    __m128d c23_7 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a23_7 = _mm_load_sd(&A[303]);
#if defined(__SSE3__) && defined(__AVX__)
    c23_7 = _mm_add_sd(c23_7, _mm_mul_sd(a23_7, _mm256_castpd256_pd128(b23)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c23_7 = _mm_add_sd(c23_7, _mm_mul_sd(a23_7, b23));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c23_7);
    __m128d c23_8 = _mm_load_sd(&C[(l_n*88)+69]);
    __m128d a23_8 = _mm_load_sd(&A[304]);
#if defined(__SSE3__) && defined(__AVX__)
    c23_8 = _mm_add_sd(c23_8, _mm_mul_sd(a23_8, _mm256_castpd256_pd128(b23)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c23_8 = _mm_add_sd(c23_8, _mm_mul_sd(a23_8, b23));
#endif
    _mm_store_sd(&C[(l_n*88)+69], c23_8);
    __m128d c23_9 = _mm_loadu_pd(&C[(l_n*88)+71]);
    __m128d a23_9 = _mm_loadu_pd(&A[305]);
#if defined(__SSE3__) && defined(__AVX__)
    c23_9 = _mm_add_pd(c23_9, _mm_mul_pd(a23_9, _mm256_castpd256_pd128(b23)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c23_9 = _mm_add_pd(c23_9, _mm_mul_pd(a23_9, b23));
#endif
    _mm_storeu_pd(&C[(l_n*88)+71], c23_9);
    __m128d c23_11 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a23_11 = _mm_load_sd(&A[307]);
#if defined(__SSE3__) && defined(__AVX__)
    c23_11 = _mm_add_sd(c23_11, _mm_mul_sd(a23_11, _mm256_castpd256_pd128(b23)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c23_11 = _mm_add_sd(c23_11, _mm_mul_sd(a23_11, b23));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c23_11);
#else
    C[(l_n*88)+20] += A[296] * B[(l_n*88)+23];
    C[(l_n*88)+22] += A[297] * B[(l_n*88)+23];
    C[(l_n*88)+23] += A[298] * B[(l_n*88)+23];
    C[(l_n*88)+24] += A[299] * B[(l_n*88)+23];
    C[(l_n*88)+41] += A[300] * B[(l_n*88)+23];
    C[(l_n*88)+43] += A[301] * B[(l_n*88)+23];
    C[(l_n*88)+44] += A[302] * B[(l_n*88)+23];
    C[(l_n*88)+45] += A[303] * B[(l_n*88)+23];
    C[(l_n*88)+69] += A[304] * B[(l_n*88)+23];
    C[(l_n*88)+71] += A[305] * B[(l_n*88)+23];
    C[(l_n*88)+72] += A[306] * B[(l_n*88)+23];
    C[(l_n*88)+73] += A[307] * B[(l_n*88)+23];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b24 = _mm256_broadcast_sd(&B[(l_n*88)+24]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b24 = _mm_loaddup_pd(&B[(l_n*88)+24]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c24_0 = _mm256_loadu_pd(&C[(l_n*88)+20]);
    __m256d a24_0 = _mm256_loadu_pd(&A[308]);
    c24_0 = _mm256_add_pd(c24_0, _mm256_mul_pd(a24_0, b24));
    _mm256_storeu_pd(&C[(l_n*88)+20], c24_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c24_0 = _mm_loadu_pd(&C[(l_n*88)+20]);
    __m128d a24_0 = _mm_loadu_pd(&A[308]);
    c24_0 = _mm_add_pd(c24_0, _mm_mul_pd(a24_0, b24));
    _mm_storeu_pd(&C[(l_n*88)+20], c24_0);
    __m128d c24_2 = _mm_loadu_pd(&C[(l_n*88)+22]);
    __m128d a24_2 = _mm_loadu_pd(&A[310]);
    c24_2 = _mm_add_pd(c24_2, _mm_mul_pd(a24_2, b24));
    _mm_storeu_pd(&C[(l_n*88)+22], c24_2);
#endif
    __m128d c24_4 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a24_4 = _mm_load_sd(&A[312]);
#if defined(__SSE3__) && defined(__AVX__)
    c24_4 = _mm_add_sd(c24_4, _mm_mul_sd(a24_4, _mm256_castpd256_pd128(b24)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c24_4 = _mm_add_sd(c24_4, _mm_mul_sd(a24_4, b24));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c24_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c24_5 = _mm256_loadu_pd(&C[(l_n*88)+41]);
    __m256d a24_5 = _mm256_loadu_pd(&A[313]);
    c24_5 = _mm256_add_pd(c24_5, _mm256_mul_pd(a24_5, b24));
    _mm256_storeu_pd(&C[(l_n*88)+41], c24_5);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c24_5 = _mm_loadu_pd(&C[(l_n*88)+41]);
    __m128d a24_5 = _mm_loadu_pd(&A[313]);
    c24_5 = _mm_add_pd(c24_5, _mm_mul_pd(a24_5, b24));
    _mm_storeu_pd(&C[(l_n*88)+41], c24_5);
    __m128d c24_7 = _mm_loadu_pd(&C[(l_n*88)+43]);
    __m128d a24_7 = _mm_loadu_pd(&A[315]);
    c24_7 = _mm_add_pd(c24_7, _mm_mul_pd(a24_7, b24));
    _mm_storeu_pd(&C[(l_n*88)+43], c24_7);
#endif
    __m128d c24_9 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a24_9 = _mm_load_sd(&A[317]);
#if defined(__SSE3__) && defined(__AVX__)
    c24_9 = _mm_add_sd(c24_9, _mm_mul_sd(a24_9, _mm256_castpd256_pd128(b24)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c24_9 = _mm_add_sd(c24_9, _mm_mul_sd(a24_9, b24));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c24_9);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c24_10 = _mm256_loadu_pd(&C[(l_n*88)+69]);
    __m256d a24_10 = _mm256_loadu_pd(&A[318]);
    c24_10 = _mm256_add_pd(c24_10, _mm256_mul_pd(a24_10, b24));
    _mm256_storeu_pd(&C[(l_n*88)+69], c24_10);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c24_10 = _mm_loadu_pd(&C[(l_n*88)+69]);
    __m128d a24_10 = _mm_loadu_pd(&A[318]);
    c24_10 = _mm_add_pd(c24_10, _mm_mul_pd(a24_10, b24));
    _mm_storeu_pd(&C[(l_n*88)+69], c24_10);
    __m128d c24_12 = _mm_loadu_pd(&C[(l_n*88)+71]);
    __m128d a24_12 = _mm_loadu_pd(&A[320]);
    c24_12 = _mm_add_pd(c24_12, _mm_mul_pd(a24_12, b24));
    _mm_storeu_pd(&C[(l_n*88)+71], c24_12);
#endif
    __m128d c24_14 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a24_14 = _mm_load_sd(&A[322]);
#if defined(__SSE3__) && defined(__AVX__)
    c24_14 = _mm_add_sd(c24_14, _mm_mul_sd(a24_14, _mm256_castpd256_pd128(b24)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c24_14 = _mm_add_sd(c24_14, _mm_mul_sd(a24_14, b24));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c24_14);
#else
    C[(l_n*88)+20] += A[308] * B[(l_n*88)+24];
    C[(l_n*88)+21] += A[309] * B[(l_n*88)+24];
    C[(l_n*88)+22] += A[310] * B[(l_n*88)+24];
    C[(l_n*88)+23] += A[311] * B[(l_n*88)+24];
    C[(l_n*88)+24] += A[312] * B[(l_n*88)+24];
    C[(l_n*88)+41] += A[313] * B[(l_n*88)+24];
    C[(l_n*88)+42] += A[314] * B[(l_n*88)+24];
    C[(l_n*88)+43] += A[315] * B[(l_n*88)+24];
    C[(l_n*88)+44] += A[316] * B[(l_n*88)+24];
    C[(l_n*88)+45] += A[317] * B[(l_n*88)+24];
    C[(l_n*88)+69] += A[318] * B[(l_n*88)+24];
    C[(l_n*88)+70] += A[319] * B[(l_n*88)+24];
    C[(l_n*88)+71] += A[320] * B[(l_n*88)+24];
    C[(l_n*88)+72] += A[321] * B[(l_n*88)+24];
    C[(l_n*88)+73] += A[322] * B[(l_n*88)+24];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b25 = _mm256_broadcast_sd(&B[(l_n*88)+25]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b25 = _mm_loaddup_pd(&B[(l_n*88)+25]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c25_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a25_0 = _mm256_loadu_pd(&A[323]);
    c25_0 = _mm256_add_pd(c25_0, _mm256_mul_pd(a25_0, b25));
    _mm256_storeu_pd(&C[(l_n*88)+10], c25_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c25_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a25_0 = _mm_loadu_pd(&A[323]);
    c25_0 = _mm_add_pd(c25_0, _mm_mul_pd(a25_0, b25));
    _mm_storeu_pd(&C[(l_n*88)+10], c25_0);
    __m128d c25_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a25_2 = _mm_loadu_pd(&A[325]);
    c25_2 = _mm_add_pd(c25_2, _mm_mul_pd(a25_2, b25));
    _mm_storeu_pd(&C[(l_n*88)+12], c25_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c25_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a25_4 = _mm256_loadu_pd(&A[327]);
    c25_4 = _mm256_add_pd(c25_4, _mm256_mul_pd(a25_4, b25));
    _mm256_storeu_pd(&C[(l_n*88)+25], c25_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c25_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a25_4 = _mm_loadu_pd(&A[327]);
    c25_4 = _mm_add_pd(c25_4, _mm_mul_pd(a25_4, b25));
    _mm_storeu_pd(&C[(l_n*88)+25], c25_4);
    __m128d c25_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a25_6 = _mm_loadu_pd(&A[329]);
    c25_6 = _mm_add_pd(c25_6, _mm_mul_pd(a25_6, b25));
    _mm_storeu_pd(&C[(l_n*88)+27], c25_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c25_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a25_8 = _mm256_loadu_pd(&A[331]);
    c25_8 = _mm256_add_pd(c25_8, _mm256_mul_pd(a25_8, b25));
    _mm256_storeu_pd(&C[(l_n*88)+46], c25_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c25_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a25_8 = _mm_loadu_pd(&A[331]);
    c25_8 = _mm_add_pd(c25_8, _mm_mul_pd(a25_8, b25));
    _mm_storeu_pd(&C[(l_n*88)+46], c25_8);
    __m128d c25_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a25_10 = _mm_loadu_pd(&A[333]);
    c25_10 = _mm_add_pd(c25_10, _mm_mul_pd(a25_10, b25));
    _mm_storeu_pd(&C[(l_n*88)+48], c25_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c25_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a25_12 = _mm256_loadu_pd(&A[335]);
    c25_12 = _mm256_add_pd(c25_12, _mm256_mul_pd(a25_12, b25));
    _mm256_storeu_pd(&C[(l_n*88)+74], c25_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c25_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a25_12 = _mm_loadu_pd(&A[335]);
    c25_12 = _mm_add_pd(c25_12, _mm_mul_pd(a25_12, b25));
    _mm_storeu_pd(&C[(l_n*88)+74], c25_12);
    __m128d c25_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a25_14 = _mm_loadu_pd(&A[337]);
    c25_14 = _mm_add_pd(c25_14, _mm_mul_pd(a25_14, b25));
    _mm_storeu_pd(&C[(l_n*88)+76], c25_14);
#endif
#else
    C[(l_n*88)+10] += A[323] * B[(l_n*88)+25];
    C[(l_n*88)+11] += A[324] * B[(l_n*88)+25];
    C[(l_n*88)+12] += A[325] * B[(l_n*88)+25];
    C[(l_n*88)+13] += A[326] * B[(l_n*88)+25];
    C[(l_n*88)+25] += A[327] * B[(l_n*88)+25];
    C[(l_n*88)+26] += A[328] * B[(l_n*88)+25];
    C[(l_n*88)+27] += A[329] * B[(l_n*88)+25];
    C[(l_n*88)+28] += A[330] * B[(l_n*88)+25];
    C[(l_n*88)+46] += A[331] * B[(l_n*88)+25];
    C[(l_n*88)+47] += A[332] * B[(l_n*88)+25];
    C[(l_n*88)+48] += A[333] * B[(l_n*88)+25];
    C[(l_n*88)+49] += A[334] * B[(l_n*88)+25];
    C[(l_n*88)+74] += A[335] * B[(l_n*88)+25];
    C[(l_n*88)+75] += A[336] * B[(l_n*88)+25];
    C[(l_n*88)+76] += A[337] * B[(l_n*88)+25];
    C[(l_n*88)+77] += A[338] * B[(l_n*88)+25];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b26 = _mm256_broadcast_sd(&B[(l_n*88)+26]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b26 = _mm_loaddup_pd(&B[(l_n*88)+26]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c26_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a26_0 = _mm256_loadu_pd(&A[339]);
    c26_0 = _mm256_add_pd(c26_0, _mm256_mul_pd(a26_0, b26));
    _mm256_storeu_pd(&C[(l_n*88)+10], c26_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c26_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a26_0 = _mm_loadu_pd(&A[339]);
    c26_0 = _mm_add_pd(c26_0, _mm_mul_pd(a26_0, b26));
    _mm_storeu_pd(&C[(l_n*88)+10], c26_0);
    __m128d c26_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a26_2 = _mm_loadu_pd(&A[341]);
    c26_2 = _mm_add_pd(c26_2, _mm_mul_pd(a26_2, b26));
    _mm_storeu_pd(&C[(l_n*88)+12], c26_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c26_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a26_4 = _mm256_loadu_pd(&A[343]);
    c26_4 = _mm256_add_pd(c26_4, _mm256_mul_pd(a26_4, b26));
    _mm256_storeu_pd(&C[(l_n*88)+25], c26_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c26_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a26_4 = _mm_loadu_pd(&A[343]);
    c26_4 = _mm_add_pd(c26_4, _mm_mul_pd(a26_4, b26));
    _mm_storeu_pd(&C[(l_n*88)+25], c26_4);
    __m128d c26_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a26_6 = _mm_loadu_pd(&A[345]);
    c26_6 = _mm_add_pd(c26_6, _mm_mul_pd(a26_6, b26));
    _mm_storeu_pd(&C[(l_n*88)+27], c26_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c26_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a26_8 = _mm256_loadu_pd(&A[347]);
    c26_8 = _mm256_add_pd(c26_8, _mm256_mul_pd(a26_8, b26));
    _mm256_storeu_pd(&C[(l_n*88)+46], c26_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c26_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a26_8 = _mm_loadu_pd(&A[347]);
    c26_8 = _mm_add_pd(c26_8, _mm_mul_pd(a26_8, b26));
    _mm_storeu_pd(&C[(l_n*88)+46], c26_8);
    __m128d c26_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a26_10 = _mm_loadu_pd(&A[349]);
    c26_10 = _mm_add_pd(c26_10, _mm_mul_pd(a26_10, b26));
    _mm_storeu_pd(&C[(l_n*88)+48], c26_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c26_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a26_12 = _mm256_loadu_pd(&A[351]);
    c26_12 = _mm256_add_pd(c26_12, _mm256_mul_pd(a26_12, b26));
    _mm256_storeu_pd(&C[(l_n*88)+74], c26_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c26_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a26_12 = _mm_loadu_pd(&A[351]);
    c26_12 = _mm_add_pd(c26_12, _mm_mul_pd(a26_12, b26));
    _mm_storeu_pd(&C[(l_n*88)+74], c26_12);
    __m128d c26_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a26_14 = _mm_loadu_pd(&A[353]);
    c26_14 = _mm_add_pd(c26_14, _mm_mul_pd(a26_14, b26));
    _mm_storeu_pd(&C[(l_n*88)+76], c26_14);
#endif
#else
    C[(l_n*88)+10] += A[339] * B[(l_n*88)+26];
    C[(l_n*88)+11] += A[340] * B[(l_n*88)+26];
    C[(l_n*88)+12] += A[341] * B[(l_n*88)+26];
    C[(l_n*88)+13] += A[342] * B[(l_n*88)+26];
    C[(l_n*88)+25] += A[343] * B[(l_n*88)+26];
    C[(l_n*88)+26] += A[344] * B[(l_n*88)+26];
    C[(l_n*88)+27] += A[345] * B[(l_n*88)+26];
    C[(l_n*88)+28] += A[346] * B[(l_n*88)+26];
    C[(l_n*88)+46] += A[347] * B[(l_n*88)+26];
    C[(l_n*88)+47] += A[348] * B[(l_n*88)+26];
    C[(l_n*88)+48] += A[349] * B[(l_n*88)+26];
    C[(l_n*88)+49] += A[350] * B[(l_n*88)+26];
    C[(l_n*88)+74] += A[351] * B[(l_n*88)+26];
    C[(l_n*88)+75] += A[352] * B[(l_n*88)+26];
    C[(l_n*88)+76] += A[353] * B[(l_n*88)+26];
    C[(l_n*88)+77] += A[354] * B[(l_n*88)+26];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b27 = _mm256_broadcast_sd(&B[(l_n*88)+27]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b27 = _mm_loaddup_pd(&B[(l_n*88)+27]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c27_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a27_0 = _mm256_loadu_pd(&A[355]);
    c27_0 = _mm256_add_pd(c27_0, _mm256_mul_pd(a27_0, b27));
    _mm256_storeu_pd(&C[(l_n*88)+10], c27_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c27_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a27_0 = _mm_loadu_pd(&A[355]);
    c27_0 = _mm_add_pd(c27_0, _mm_mul_pd(a27_0, b27));
    _mm_storeu_pd(&C[(l_n*88)+10], c27_0);
    __m128d c27_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a27_2 = _mm_loadu_pd(&A[357]);
    c27_2 = _mm_add_pd(c27_2, _mm_mul_pd(a27_2, b27));
    _mm_storeu_pd(&C[(l_n*88)+12], c27_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c27_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a27_4 = _mm256_loadu_pd(&A[359]);
    c27_4 = _mm256_add_pd(c27_4, _mm256_mul_pd(a27_4, b27));
    _mm256_storeu_pd(&C[(l_n*88)+25], c27_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c27_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a27_4 = _mm_loadu_pd(&A[359]);
    c27_4 = _mm_add_pd(c27_4, _mm_mul_pd(a27_4, b27));
    _mm_storeu_pd(&C[(l_n*88)+25], c27_4);
    __m128d c27_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a27_6 = _mm_loadu_pd(&A[361]);
    c27_6 = _mm_add_pd(c27_6, _mm_mul_pd(a27_6, b27));
    _mm_storeu_pd(&C[(l_n*88)+27], c27_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c27_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a27_8 = _mm256_loadu_pd(&A[363]);
    c27_8 = _mm256_add_pd(c27_8, _mm256_mul_pd(a27_8, b27));
    _mm256_storeu_pd(&C[(l_n*88)+46], c27_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c27_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a27_8 = _mm_loadu_pd(&A[363]);
    c27_8 = _mm_add_pd(c27_8, _mm_mul_pd(a27_8, b27));
    _mm_storeu_pd(&C[(l_n*88)+46], c27_8);
    __m128d c27_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a27_10 = _mm_loadu_pd(&A[365]);
    c27_10 = _mm_add_pd(c27_10, _mm_mul_pd(a27_10, b27));
    _mm_storeu_pd(&C[(l_n*88)+48], c27_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c27_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a27_12 = _mm256_loadu_pd(&A[367]);
    c27_12 = _mm256_add_pd(c27_12, _mm256_mul_pd(a27_12, b27));
    _mm256_storeu_pd(&C[(l_n*88)+74], c27_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c27_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a27_12 = _mm_loadu_pd(&A[367]);
    c27_12 = _mm_add_pd(c27_12, _mm_mul_pd(a27_12, b27));
    _mm_storeu_pd(&C[(l_n*88)+74], c27_12);
    __m128d c27_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a27_14 = _mm_loadu_pd(&A[369]);
    c27_14 = _mm_add_pd(c27_14, _mm_mul_pd(a27_14, b27));
    _mm_storeu_pd(&C[(l_n*88)+76], c27_14);
#endif
#else
    C[(l_n*88)+10] += A[355] * B[(l_n*88)+27];
    C[(l_n*88)+11] += A[356] * B[(l_n*88)+27];
    C[(l_n*88)+12] += A[357] * B[(l_n*88)+27];
    C[(l_n*88)+13] += A[358] * B[(l_n*88)+27];
    C[(l_n*88)+25] += A[359] * B[(l_n*88)+27];
    C[(l_n*88)+26] += A[360] * B[(l_n*88)+27];
    C[(l_n*88)+27] += A[361] * B[(l_n*88)+27];
    C[(l_n*88)+28] += A[362] * B[(l_n*88)+27];
    C[(l_n*88)+46] += A[363] * B[(l_n*88)+27];
    C[(l_n*88)+47] += A[364] * B[(l_n*88)+27];
    C[(l_n*88)+48] += A[365] * B[(l_n*88)+27];
    C[(l_n*88)+49] += A[366] * B[(l_n*88)+27];
    C[(l_n*88)+74] += A[367] * B[(l_n*88)+27];
    C[(l_n*88)+75] += A[368] * B[(l_n*88)+27];
    C[(l_n*88)+76] += A[369] * B[(l_n*88)+27];
    C[(l_n*88)+77] += A[370] * B[(l_n*88)+27];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b28 = _mm256_broadcast_sd(&B[(l_n*88)+28]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b28 = _mm_loaddup_pd(&B[(l_n*88)+28]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c28_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a28_0 = _mm256_loadu_pd(&A[371]);
    c28_0 = _mm256_add_pd(c28_0, _mm256_mul_pd(a28_0, b28));
    _mm256_storeu_pd(&C[(l_n*88)+10], c28_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c28_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a28_0 = _mm_loadu_pd(&A[371]);
    c28_0 = _mm_add_pd(c28_0, _mm_mul_pd(a28_0, b28));
    _mm_storeu_pd(&C[(l_n*88)+10], c28_0);
    __m128d c28_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a28_2 = _mm_loadu_pd(&A[373]);
    c28_2 = _mm_add_pd(c28_2, _mm_mul_pd(a28_2, b28));
    _mm_storeu_pd(&C[(l_n*88)+12], c28_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c28_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a28_4 = _mm256_loadu_pd(&A[375]);
    c28_4 = _mm256_add_pd(c28_4, _mm256_mul_pd(a28_4, b28));
    _mm256_storeu_pd(&C[(l_n*88)+25], c28_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c28_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a28_4 = _mm_loadu_pd(&A[375]);
    c28_4 = _mm_add_pd(c28_4, _mm_mul_pd(a28_4, b28));
    _mm_storeu_pd(&C[(l_n*88)+25], c28_4);
    __m128d c28_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a28_6 = _mm_loadu_pd(&A[377]);
    c28_6 = _mm_add_pd(c28_6, _mm_mul_pd(a28_6, b28));
    _mm_storeu_pd(&C[(l_n*88)+27], c28_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c28_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a28_8 = _mm256_loadu_pd(&A[379]);
    c28_8 = _mm256_add_pd(c28_8, _mm256_mul_pd(a28_8, b28));
    _mm256_storeu_pd(&C[(l_n*88)+46], c28_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c28_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a28_8 = _mm_loadu_pd(&A[379]);
    c28_8 = _mm_add_pd(c28_8, _mm_mul_pd(a28_8, b28));
    _mm_storeu_pd(&C[(l_n*88)+46], c28_8);
    __m128d c28_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a28_10 = _mm_loadu_pd(&A[381]);
    c28_10 = _mm_add_pd(c28_10, _mm_mul_pd(a28_10, b28));
    _mm_storeu_pd(&C[(l_n*88)+48], c28_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c28_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a28_12 = _mm256_loadu_pd(&A[383]);
    c28_12 = _mm256_add_pd(c28_12, _mm256_mul_pd(a28_12, b28));
    _mm256_storeu_pd(&C[(l_n*88)+74], c28_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c28_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a28_12 = _mm_loadu_pd(&A[383]);
    c28_12 = _mm_add_pd(c28_12, _mm_mul_pd(a28_12, b28));
    _mm_storeu_pd(&C[(l_n*88)+74], c28_12);
    __m128d c28_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a28_14 = _mm_loadu_pd(&A[385]);
    c28_14 = _mm_add_pd(c28_14, _mm_mul_pd(a28_14, b28));
    _mm_storeu_pd(&C[(l_n*88)+76], c28_14);
#endif
#else
    C[(l_n*88)+10] += A[371] * B[(l_n*88)+28];
    C[(l_n*88)+11] += A[372] * B[(l_n*88)+28];
    C[(l_n*88)+12] += A[373] * B[(l_n*88)+28];
    C[(l_n*88)+13] += A[374] * B[(l_n*88)+28];
    C[(l_n*88)+25] += A[375] * B[(l_n*88)+28];
    C[(l_n*88)+26] += A[376] * B[(l_n*88)+28];
    C[(l_n*88)+27] += A[377] * B[(l_n*88)+28];
    C[(l_n*88)+28] += A[378] * B[(l_n*88)+28];
    C[(l_n*88)+46] += A[379] * B[(l_n*88)+28];
    C[(l_n*88)+47] += A[380] * B[(l_n*88)+28];
    C[(l_n*88)+48] += A[381] * B[(l_n*88)+28];
    C[(l_n*88)+49] += A[382] * B[(l_n*88)+28];
    C[(l_n*88)+74] += A[383] * B[(l_n*88)+28];
    C[(l_n*88)+75] += A[384] * B[(l_n*88)+28];
    C[(l_n*88)+76] += A[385] * B[(l_n*88)+28];
    C[(l_n*88)+77] += A[386] * B[(l_n*88)+28];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b29 = _mm256_broadcast_sd(&B[(l_n*88)+29]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b29 = _mm_loaddup_pd(&B[(l_n*88)+29]);
#endif
    __m128d c29_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a29_0 = _mm_loadu_pd(&A[387]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_0 = _mm_add_pd(c29_0, _mm_mul_pd(a29_0, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_0 = _mm_add_pd(c29_0, _mm_mul_pd(a29_0, b29));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c29_0);
    __m128d c29_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a29_2 = _mm_load_sd(&A[389]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_2 = _mm_add_sd(c29_2, _mm_mul_sd(a29_2, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_2 = _mm_add_sd(c29_2, _mm_mul_sd(a29_2, b29));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c29_2);
    __m128d c29_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a29_3 = _mm_loadu_pd(&A[390]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_3 = _mm_add_pd(c29_3, _mm_mul_pd(a29_3, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_3 = _mm_add_pd(c29_3, _mm_mul_pd(a29_3, b29));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c29_3);
    __m128d c29_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a29_5 = _mm_load_sd(&A[392]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_5 = _mm_add_sd(c29_5, _mm_mul_sd(a29_5, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_5 = _mm_add_sd(c29_5, _mm_mul_sd(a29_5, b29));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c29_5);
    __m128d c29_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a29_6 = _mm_loadu_pd(&A[393]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_6 = _mm_add_pd(c29_6, _mm_mul_pd(a29_6, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_6 = _mm_add_pd(c29_6, _mm_mul_pd(a29_6, b29));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c29_6);
    __m128d c29_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a29_8 = _mm_load_sd(&A[395]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_8 = _mm_add_sd(c29_8, _mm_mul_sd(a29_8, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_8 = _mm_add_sd(c29_8, _mm_mul_sd(a29_8, b29));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c29_8);
    __m128d c29_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a29_9 = _mm_loadu_pd(&A[396]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_9 = _mm_add_pd(c29_9, _mm_mul_pd(a29_9, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_9 = _mm_add_pd(c29_9, _mm_mul_pd(a29_9, b29));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c29_9);
    __m128d c29_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a29_11 = _mm_load_sd(&A[398]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_11 = _mm_add_sd(c29_11, _mm_mul_sd(a29_11, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_11 = _mm_add_sd(c29_11, _mm_mul_sd(a29_11, b29));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c29_11);
    __m128d c29_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a29_12 = _mm_loadu_pd(&A[399]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_12 = _mm_add_pd(c29_12, _mm_mul_pd(a29_12, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_12 = _mm_add_pd(c29_12, _mm_mul_pd(a29_12, b29));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c29_12);
    __m128d c29_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a29_14 = _mm_load_sd(&A[401]);
#if defined(__SSE3__) && defined(__AVX__)
    c29_14 = _mm_add_sd(c29_14, _mm_mul_sd(a29_14, _mm256_castpd256_pd128(b29)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c29_14 = _mm_add_sd(c29_14, _mm_mul_sd(a29_14, b29));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c29_14);
#else
    C[(l_n*88)+4] += A[387] * B[(l_n*88)+29];
    C[(l_n*88)+5] += A[388] * B[(l_n*88)+29];
    C[(l_n*88)+6] += A[389] * B[(l_n*88)+29];
    C[(l_n*88)+14] += A[390] * B[(l_n*88)+29];
    C[(l_n*88)+15] += A[391] * B[(l_n*88)+29];
    C[(l_n*88)+16] += A[392] * B[(l_n*88)+29];
    C[(l_n*88)+29] += A[393] * B[(l_n*88)+29];
    C[(l_n*88)+30] += A[394] * B[(l_n*88)+29];
    C[(l_n*88)+31] += A[395] * B[(l_n*88)+29];
    C[(l_n*88)+50] += A[396] * B[(l_n*88)+29];
    C[(l_n*88)+51] += A[397] * B[(l_n*88)+29];
    C[(l_n*88)+52] += A[398] * B[(l_n*88)+29];
    C[(l_n*88)+78] += A[399] * B[(l_n*88)+29];
    C[(l_n*88)+79] += A[400] * B[(l_n*88)+29];
    C[(l_n*88)+80] += A[401] * B[(l_n*88)+29];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b30 = _mm256_broadcast_sd(&B[(l_n*88)+30]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b30 = _mm_loaddup_pd(&B[(l_n*88)+30]);
#endif
    __m128d c30_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a30_0 = _mm_loadu_pd(&A[402]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_0 = _mm_add_pd(c30_0, _mm_mul_pd(a30_0, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_0 = _mm_add_pd(c30_0, _mm_mul_pd(a30_0, b30));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c30_0);
    __m128d c30_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a30_2 = _mm_load_sd(&A[404]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_2 = _mm_add_sd(c30_2, _mm_mul_sd(a30_2, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_2 = _mm_add_sd(c30_2, _mm_mul_sd(a30_2, b30));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c30_2);
    __m128d c30_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a30_3 = _mm_loadu_pd(&A[405]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_3 = _mm_add_pd(c30_3, _mm_mul_pd(a30_3, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_3 = _mm_add_pd(c30_3, _mm_mul_pd(a30_3, b30));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c30_3);
    __m128d c30_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a30_5 = _mm_load_sd(&A[407]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_5 = _mm_add_sd(c30_5, _mm_mul_sd(a30_5, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_5 = _mm_add_sd(c30_5, _mm_mul_sd(a30_5, b30));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c30_5);
    __m128d c30_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a30_6 = _mm_loadu_pd(&A[408]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_6 = _mm_add_pd(c30_6, _mm_mul_pd(a30_6, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_6 = _mm_add_pd(c30_6, _mm_mul_pd(a30_6, b30));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c30_6);
    __m128d c30_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a30_8 = _mm_load_sd(&A[410]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_8 = _mm_add_sd(c30_8, _mm_mul_sd(a30_8, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_8 = _mm_add_sd(c30_8, _mm_mul_sd(a30_8, b30));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c30_8);
    __m128d c30_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a30_9 = _mm_loadu_pd(&A[411]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_9 = _mm_add_pd(c30_9, _mm_mul_pd(a30_9, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_9 = _mm_add_pd(c30_9, _mm_mul_pd(a30_9, b30));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c30_9);
    __m128d c30_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a30_11 = _mm_load_sd(&A[413]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_11 = _mm_add_sd(c30_11, _mm_mul_sd(a30_11, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_11 = _mm_add_sd(c30_11, _mm_mul_sd(a30_11, b30));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c30_11);
    __m128d c30_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a30_12 = _mm_loadu_pd(&A[414]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_12 = _mm_add_pd(c30_12, _mm_mul_pd(a30_12, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_12 = _mm_add_pd(c30_12, _mm_mul_pd(a30_12, b30));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c30_12);
    __m128d c30_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a30_14 = _mm_load_sd(&A[416]);
#if defined(__SSE3__) && defined(__AVX__)
    c30_14 = _mm_add_sd(c30_14, _mm_mul_sd(a30_14, _mm256_castpd256_pd128(b30)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c30_14 = _mm_add_sd(c30_14, _mm_mul_sd(a30_14, b30));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c30_14);
#else
    C[(l_n*88)+4] += A[402] * B[(l_n*88)+30];
    C[(l_n*88)+5] += A[403] * B[(l_n*88)+30];
    C[(l_n*88)+6] += A[404] * B[(l_n*88)+30];
    C[(l_n*88)+14] += A[405] * B[(l_n*88)+30];
    C[(l_n*88)+15] += A[406] * B[(l_n*88)+30];
    C[(l_n*88)+16] += A[407] * B[(l_n*88)+30];
    C[(l_n*88)+29] += A[408] * B[(l_n*88)+30];
    C[(l_n*88)+30] += A[409] * B[(l_n*88)+30];
    C[(l_n*88)+31] += A[410] * B[(l_n*88)+30];
    C[(l_n*88)+50] += A[411] * B[(l_n*88)+30];
    C[(l_n*88)+51] += A[412] * B[(l_n*88)+30];
    C[(l_n*88)+52] += A[413] * B[(l_n*88)+30];
    C[(l_n*88)+78] += A[414] * B[(l_n*88)+30];
    C[(l_n*88)+79] += A[415] * B[(l_n*88)+30];
    C[(l_n*88)+80] += A[416] * B[(l_n*88)+30];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b31 = _mm256_broadcast_sd(&B[(l_n*88)+31]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b31 = _mm_loaddup_pd(&B[(l_n*88)+31]);
#endif
    __m128d c31_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a31_0 = _mm_loadu_pd(&A[417]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_0 = _mm_add_pd(c31_0, _mm_mul_pd(a31_0, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_0 = _mm_add_pd(c31_0, _mm_mul_pd(a31_0, b31));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c31_0);
    __m128d c31_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a31_2 = _mm_load_sd(&A[419]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_2 = _mm_add_sd(c31_2, _mm_mul_sd(a31_2, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_2 = _mm_add_sd(c31_2, _mm_mul_sd(a31_2, b31));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c31_2);
    __m128d c31_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a31_3 = _mm_loadu_pd(&A[420]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_3 = _mm_add_pd(c31_3, _mm_mul_pd(a31_3, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_3 = _mm_add_pd(c31_3, _mm_mul_pd(a31_3, b31));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c31_3);
    __m128d c31_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a31_5 = _mm_load_sd(&A[422]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_5 = _mm_add_sd(c31_5, _mm_mul_sd(a31_5, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_5 = _mm_add_sd(c31_5, _mm_mul_sd(a31_5, b31));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c31_5);
    __m128d c31_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a31_6 = _mm_loadu_pd(&A[423]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_6 = _mm_add_pd(c31_6, _mm_mul_pd(a31_6, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_6 = _mm_add_pd(c31_6, _mm_mul_pd(a31_6, b31));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c31_6);
    __m128d c31_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a31_8 = _mm_load_sd(&A[425]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_8 = _mm_add_sd(c31_8, _mm_mul_sd(a31_8, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_8 = _mm_add_sd(c31_8, _mm_mul_sd(a31_8, b31));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c31_8);
    __m128d c31_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a31_9 = _mm_loadu_pd(&A[426]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_9 = _mm_add_pd(c31_9, _mm_mul_pd(a31_9, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_9 = _mm_add_pd(c31_9, _mm_mul_pd(a31_9, b31));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c31_9);
    __m128d c31_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a31_11 = _mm_load_sd(&A[428]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_11 = _mm_add_sd(c31_11, _mm_mul_sd(a31_11, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_11 = _mm_add_sd(c31_11, _mm_mul_sd(a31_11, b31));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c31_11);
    __m128d c31_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a31_12 = _mm_loadu_pd(&A[429]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_12 = _mm_add_pd(c31_12, _mm_mul_pd(a31_12, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_12 = _mm_add_pd(c31_12, _mm_mul_pd(a31_12, b31));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c31_12);
    __m128d c31_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a31_14 = _mm_load_sd(&A[431]);
#if defined(__SSE3__) && defined(__AVX__)
    c31_14 = _mm_add_sd(c31_14, _mm_mul_sd(a31_14, _mm256_castpd256_pd128(b31)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c31_14 = _mm_add_sd(c31_14, _mm_mul_sd(a31_14, b31));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c31_14);
#else
    C[(l_n*88)+4] += A[417] * B[(l_n*88)+31];
    C[(l_n*88)+5] += A[418] * B[(l_n*88)+31];
    C[(l_n*88)+6] += A[419] * B[(l_n*88)+31];
    C[(l_n*88)+14] += A[420] * B[(l_n*88)+31];
    C[(l_n*88)+15] += A[421] * B[(l_n*88)+31];
    C[(l_n*88)+16] += A[422] * B[(l_n*88)+31];
    C[(l_n*88)+29] += A[423] * B[(l_n*88)+31];
    C[(l_n*88)+30] += A[424] * B[(l_n*88)+31];
    C[(l_n*88)+31] += A[425] * B[(l_n*88)+31];
    C[(l_n*88)+50] += A[426] * B[(l_n*88)+31];
    C[(l_n*88)+51] += A[427] * B[(l_n*88)+31];
    C[(l_n*88)+52] += A[428] * B[(l_n*88)+31];
    C[(l_n*88)+78] += A[429] * B[(l_n*88)+31];
    C[(l_n*88)+79] += A[430] * B[(l_n*88)+31];
    C[(l_n*88)+80] += A[431] * B[(l_n*88)+31];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b32 = _mm256_broadcast_sd(&B[(l_n*88)+32]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b32 = _mm_loaddup_pd(&B[(l_n*88)+32]);
#endif
    __m128d c32_0 = _mm_loadu_pd(&C[(l_n*88)+1]);
    __m128d a32_0 = _mm_loadu_pd(&A[432]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_0 = _mm_add_pd(c32_0, _mm_mul_pd(a32_0, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_0 = _mm_add_pd(c32_0, _mm_mul_pd(a32_0, b32));
#endif
    _mm_storeu_pd(&C[(l_n*88)+1], c32_0);
    __m128d c32_2 = _mm_loadu_pd(&C[(l_n*88)+7]);
    __m128d a32_2 = _mm_loadu_pd(&A[434]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_2 = _mm_add_pd(c32_2, _mm_mul_pd(a32_2, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_2 = _mm_add_pd(c32_2, _mm_mul_pd(a32_2, b32));
#endif
    _mm_storeu_pd(&C[(l_n*88)+7], c32_2);
    __m128d c32_4 = _mm_loadu_pd(&C[(l_n*88)+17]);
    __m128d a32_4 = _mm_loadu_pd(&A[436]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_4 = _mm_add_pd(c32_4, _mm_mul_pd(a32_4, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_4 = _mm_add_pd(c32_4, _mm_mul_pd(a32_4, b32));
#endif
    _mm_storeu_pd(&C[(l_n*88)+17], c32_4);
    __m128d c32_6 = _mm_loadu_pd(&C[(l_n*88)+32]);
    __m128d a32_6 = _mm_loadu_pd(&A[438]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_6 = _mm_add_pd(c32_6, _mm_mul_pd(a32_6, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_6 = _mm_add_pd(c32_6, _mm_mul_pd(a32_6, b32));
#endif
    _mm_storeu_pd(&C[(l_n*88)+32], c32_6);
    __m128d c32_8 = _mm_loadu_pd(&C[(l_n*88)+53]);
    __m128d a32_8 = _mm_loadu_pd(&A[440]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_8 = _mm_add_pd(c32_8, _mm_mul_pd(a32_8, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_8 = _mm_add_pd(c32_8, _mm_mul_pd(a32_8, b32));
#endif
    _mm_storeu_pd(&C[(l_n*88)+53], c32_8);
    __m128d c32_10 = _mm_loadu_pd(&C[(l_n*88)+81]);
    __m128d a32_10 = _mm_loadu_pd(&A[442]);
#if defined(__SSE3__) && defined(__AVX__)
    c32_10 = _mm_add_pd(c32_10, _mm_mul_pd(a32_10, _mm256_castpd256_pd128(b32)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c32_10 = _mm_add_pd(c32_10, _mm_mul_pd(a32_10, b32));
#endif
    _mm_storeu_pd(&C[(l_n*88)+81], c32_10);
#else
    C[(l_n*88)+1] += A[432] * B[(l_n*88)+32];
    C[(l_n*88)+2] += A[433] * B[(l_n*88)+32];
    C[(l_n*88)+7] += A[434] * B[(l_n*88)+32];
    C[(l_n*88)+8] += A[435] * B[(l_n*88)+32];
    C[(l_n*88)+17] += A[436] * B[(l_n*88)+32];
    C[(l_n*88)+18] += A[437] * B[(l_n*88)+32];
    C[(l_n*88)+32] += A[438] * B[(l_n*88)+32];
    C[(l_n*88)+33] += A[439] * B[(l_n*88)+32];
    C[(l_n*88)+53] += A[440] * B[(l_n*88)+32];
    C[(l_n*88)+54] += A[441] * B[(l_n*88)+32];
    C[(l_n*88)+81] += A[442] * B[(l_n*88)+32];
    C[(l_n*88)+82] += A[443] * B[(l_n*88)+32];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b33 = _mm256_broadcast_sd(&B[(l_n*88)+33]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b33 = _mm_loaddup_pd(&B[(l_n*88)+33]);
#endif
    __m128d c33_0 = _mm_loadu_pd(&C[(l_n*88)+1]);
    __m128d a33_0 = _mm_loadu_pd(&A[444]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_0 = _mm_add_pd(c33_0, _mm_mul_pd(a33_0, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_0 = _mm_add_pd(c33_0, _mm_mul_pd(a33_0, b33));
#endif
    _mm_storeu_pd(&C[(l_n*88)+1], c33_0);
    __m128d c33_2 = _mm_loadu_pd(&C[(l_n*88)+7]);
    __m128d a33_2 = _mm_loadu_pd(&A[446]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_2 = _mm_add_pd(c33_2, _mm_mul_pd(a33_2, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_2 = _mm_add_pd(c33_2, _mm_mul_pd(a33_2, b33));
#endif
    _mm_storeu_pd(&C[(l_n*88)+7], c33_2);
    __m128d c33_4 = _mm_loadu_pd(&C[(l_n*88)+17]);
    __m128d a33_4 = _mm_loadu_pd(&A[448]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_4 = _mm_add_pd(c33_4, _mm_mul_pd(a33_4, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_4 = _mm_add_pd(c33_4, _mm_mul_pd(a33_4, b33));
#endif
    _mm_storeu_pd(&C[(l_n*88)+17], c33_4);
    __m128d c33_6 = _mm_loadu_pd(&C[(l_n*88)+32]);
    __m128d a33_6 = _mm_loadu_pd(&A[450]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_6 = _mm_add_pd(c33_6, _mm_mul_pd(a33_6, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_6 = _mm_add_pd(c33_6, _mm_mul_pd(a33_6, b33));
#endif
    _mm_storeu_pd(&C[(l_n*88)+32], c33_6);
    __m128d c33_8 = _mm_loadu_pd(&C[(l_n*88)+53]);
    __m128d a33_8 = _mm_loadu_pd(&A[452]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_8 = _mm_add_pd(c33_8, _mm_mul_pd(a33_8, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_8 = _mm_add_pd(c33_8, _mm_mul_pd(a33_8, b33));
#endif
    _mm_storeu_pd(&C[(l_n*88)+53], c33_8);
    __m128d c33_10 = _mm_loadu_pd(&C[(l_n*88)+81]);
    __m128d a33_10 = _mm_loadu_pd(&A[454]);
#if defined(__SSE3__) && defined(__AVX__)
    c33_10 = _mm_add_pd(c33_10, _mm_mul_pd(a33_10, _mm256_castpd256_pd128(b33)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c33_10 = _mm_add_pd(c33_10, _mm_mul_pd(a33_10, b33));
#endif
    _mm_storeu_pd(&C[(l_n*88)+81], c33_10);
#else
    C[(l_n*88)+1] += A[444] * B[(l_n*88)+33];
    C[(l_n*88)+2] += A[445] * B[(l_n*88)+33];
    C[(l_n*88)+7] += A[446] * B[(l_n*88)+33];
    C[(l_n*88)+8] += A[447] * B[(l_n*88)+33];
    C[(l_n*88)+17] += A[448] * B[(l_n*88)+33];
    C[(l_n*88)+18] += A[449] * B[(l_n*88)+33];
    C[(l_n*88)+32] += A[450] * B[(l_n*88)+33];
    C[(l_n*88)+33] += A[451] * B[(l_n*88)+33];
    C[(l_n*88)+53] += A[452] * B[(l_n*88)+33];
    C[(l_n*88)+54] += A[453] * B[(l_n*88)+33];
    C[(l_n*88)+81] += A[454] * B[(l_n*88)+33];
    C[(l_n*88)+82] += A[455] * B[(l_n*88)+33];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b34 = _mm256_broadcast_sd(&B[(l_n*88)+34]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b34 = _mm_loaddup_pd(&B[(l_n*88)+34]);
#endif
    __m128d c34_0 = _mm_load_sd(&C[(l_n*88)+0]);
    __m128d a34_0 = _mm_load_sd(&A[456]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_0 = _mm_add_sd(c34_0, _mm_mul_sd(a34_0, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_0 = _mm_add_sd(c34_0, _mm_mul_sd(a34_0, b34));
#endif
    _mm_store_sd(&C[(l_n*88)+0], c34_0);
    __m128d c34_1 = _mm_load_sd(&C[(l_n*88)+3]);
    __m128d a34_1 = _mm_load_sd(&A[457]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_1 = _mm_add_sd(c34_1, _mm_mul_sd(a34_1, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_1 = _mm_add_sd(c34_1, _mm_mul_sd(a34_1, b34));
#endif
    _mm_store_sd(&C[(l_n*88)+3], c34_1);
    __m128d c34_2 = _mm_load_sd(&C[(l_n*88)+9]);
    __m128d a34_2 = _mm_load_sd(&A[458]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_2 = _mm_add_sd(c34_2, _mm_mul_sd(a34_2, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_2 = _mm_add_sd(c34_2, _mm_mul_sd(a34_2, b34));
#endif
    _mm_store_sd(&C[(l_n*88)+9], c34_2);
    __m128d c34_3 = _mm_load_sd(&C[(l_n*88)+19]);
    __m128d a34_3 = _mm_load_sd(&A[459]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_3 = _mm_add_sd(c34_3, _mm_mul_sd(a34_3, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_3 = _mm_add_sd(c34_3, _mm_mul_sd(a34_3, b34));
#endif
    _mm_store_sd(&C[(l_n*88)+19], c34_3);
    __m128d c34_4 = _mm_load_sd(&C[(l_n*88)+34]);
    __m128d a34_4 = _mm_load_sd(&A[460]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_4 = _mm_add_sd(c34_4, _mm_mul_sd(a34_4, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_4 = _mm_add_sd(c34_4, _mm_mul_sd(a34_4, b34));
#endif
    _mm_store_sd(&C[(l_n*88)+34], c34_4);
    __m128d c34_5 = _mm_load_sd(&C[(l_n*88)+55]);
    __m128d a34_5 = _mm_load_sd(&A[461]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_5 = _mm_add_sd(c34_5, _mm_mul_sd(a34_5, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_5 = _mm_add_sd(c34_5, _mm_mul_sd(a34_5, b34));
#endif
    _mm_store_sd(&C[(l_n*88)+55], c34_5);
    __m128d c34_6 = _mm_load_sd(&C[(l_n*88)+83]);
    __m128d a34_6 = _mm_load_sd(&A[462]);
#if defined(__SSE3__) && defined(__AVX__)
    c34_6 = _mm_add_sd(c34_6, _mm_mul_sd(a34_6, _mm256_castpd256_pd128(b34)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c34_6 = _mm_add_sd(c34_6, _mm_mul_sd(a34_6, b34));
#endif
    _mm_store_sd(&C[(l_n*88)+83], c34_6);
#else
    C[(l_n*88)+0] += A[456] * B[(l_n*88)+34];
    C[(l_n*88)+3] += A[457] * B[(l_n*88)+34];
    C[(l_n*88)+9] += A[458] * B[(l_n*88)+34];
    C[(l_n*88)+19] += A[459] * B[(l_n*88)+34];
    C[(l_n*88)+34] += A[460] * B[(l_n*88)+34];
    C[(l_n*88)+55] += A[461] * B[(l_n*88)+34];
    C[(l_n*88)+83] += A[462] * B[(l_n*88)+34];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b35 = _mm256_broadcast_sd(&B[(l_n*88)+35]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b35 = _mm_loaddup_pd(&B[(l_n*88)+35]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c35_0 = _mm256_loadu_pd(&C[(l_n*88)+35]);
    __m256d a35_0 = _mm256_loadu_pd(&A[463]);
    c35_0 = _mm256_add_pd(c35_0, _mm256_mul_pd(a35_0, b35));
    _mm256_storeu_pd(&C[(l_n*88)+35], c35_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c35_0 = _mm_loadu_pd(&C[(l_n*88)+35]);
    __m128d a35_0 = _mm_loadu_pd(&A[463]);
    c35_0 = _mm_add_pd(c35_0, _mm_mul_pd(a35_0, b35));
    _mm_storeu_pd(&C[(l_n*88)+35], c35_0);
    __m128d c35_2 = _mm_loadu_pd(&C[(l_n*88)+37]);
    __m128d a35_2 = _mm_loadu_pd(&A[465]);
    c35_2 = _mm_add_pd(c35_2, _mm_mul_pd(a35_2, b35));
    _mm_storeu_pd(&C[(l_n*88)+37], c35_2);
#endif
    __m128d c35_4 = _mm_loadu_pd(&C[(l_n*88)+39]);
    __m128d a35_4 = _mm_loadu_pd(&A[467]);
#if defined(__SSE3__) && defined(__AVX__)
    c35_4 = _mm_add_pd(c35_4, _mm_mul_pd(a35_4, _mm256_castpd256_pd128(b35)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c35_4 = _mm_add_pd(c35_4, _mm_mul_pd(a35_4, b35));
#endif
    _mm_storeu_pd(&C[(l_n*88)+39], c35_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c35_6 = _mm256_loadu_pd(&C[(l_n*88)+63]);
    __m256d a35_6 = _mm256_loadu_pd(&A[469]);
    c35_6 = _mm256_add_pd(c35_6, _mm256_mul_pd(a35_6, b35));
    _mm256_storeu_pd(&C[(l_n*88)+63], c35_6);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c35_6 = _mm_loadu_pd(&C[(l_n*88)+63]);
    __m128d a35_6 = _mm_loadu_pd(&A[469]);
    c35_6 = _mm_add_pd(c35_6, _mm_mul_pd(a35_6, b35));
    _mm_storeu_pd(&C[(l_n*88)+63], c35_6);
    __m128d c35_8 = _mm_loadu_pd(&C[(l_n*88)+65]);
    __m128d a35_8 = _mm_loadu_pd(&A[471]);
    c35_8 = _mm_add_pd(c35_8, _mm_mul_pd(a35_8, b35));
    _mm_storeu_pd(&C[(l_n*88)+65], c35_8);
#endif
    __m128d c35_10 = _mm_loadu_pd(&C[(l_n*88)+67]);
    __m128d a35_10 = _mm_loadu_pd(&A[473]);
#if defined(__SSE3__) && defined(__AVX__)
    c35_10 = _mm_add_pd(c35_10, _mm_mul_pd(a35_10, _mm256_castpd256_pd128(b35)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c35_10 = _mm_add_pd(c35_10, _mm_mul_pd(a35_10, b35));
#endif
    _mm_storeu_pd(&C[(l_n*88)+67], c35_10);
#else
    C[(l_n*88)+35] += A[463] * B[(l_n*88)+35];
    C[(l_n*88)+36] += A[464] * B[(l_n*88)+35];
    C[(l_n*88)+37] += A[465] * B[(l_n*88)+35];
    C[(l_n*88)+38] += A[466] * B[(l_n*88)+35];
    C[(l_n*88)+39] += A[467] * B[(l_n*88)+35];
    C[(l_n*88)+40] += A[468] * B[(l_n*88)+35];
    C[(l_n*88)+63] += A[469] * B[(l_n*88)+35];
    C[(l_n*88)+64] += A[470] * B[(l_n*88)+35];
    C[(l_n*88)+65] += A[471] * B[(l_n*88)+35];
    C[(l_n*88)+66] += A[472] * B[(l_n*88)+35];
    C[(l_n*88)+67] += A[473] * B[(l_n*88)+35];
    C[(l_n*88)+68] += A[474] * B[(l_n*88)+35];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b36 = _mm256_broadcast_sd(&B[(l_n*88)+36]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b36 = _mm_loaddup_pd(&B[(l_n*88)+36]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c36_0 = _mm256_loadu_pd(&C[(l_n*88)+35]);
    __m256d a36_0 = _mm256_loadu_pd(&A[475]);
    c36_0 = _mm256_add_pd(c36_0, _mm256_mul_pd(a36_0, b36));
    _mm256_storeu_pd(&C[(l_n*88)+35], c36_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c36_0 = _mm_loadu_pd(&C[(l_n*88)+35]);
    __m128d a36_0 = _mm_loadu_pd(&A[475]);
    c36_0 = _mm_add_pd(c36_0, _mm_mul_pd(a36_0, b36));
    _mm_storeu_pd(&C[(l_n*88)+35], c36_0);
    __m128d c36_2 = _mm_loadu_pd(&C[(l_n*88)+37]);
    __m128d a36_2 = _mm_loadu_pd(&A[477]);
    c36_2 = _mm_add_pd(c36_2, _mm_mul_pd(a36_2, b36));
    _mm_storeu_pd(&C[(l_n*88)+37], c36_2);
#endif
    __m128d c36_4 = _mm_loadu_pd(&C[(l_n*88)+39]);
    __m128d a36_4 = _mm_loadu_pd(&A[479]);
#if defined(__SSE3__) && defined(__AVX__)
    c36_4 = _mm_add_pd(c36_4, _mm_mul_pd(a36_4, _mm256_castpd256_pd128(b36)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c36_4 = _mm_add_pd(c36_4, _mm_mul_pd(a36_4, b36));
#endif
    _mm_storeu_pd(&C[(l_n*88)+39], c36_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c36_6 = _mm256_loadu_pd(&C[(l_n*88)+63]);
    __m256d a36_6 = _mm256_loadu_pd(&A[481]);
    c36_6 = _mm256_add_pd(c36_6, _mm256_mul_pd(a36_6, b36));
    _mm256_storeu_pd(&C[(l_n*88)+63], c36_6);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c36_6 = _mm_loadu_pd(&C[(l_n*88)+63]);
    __m128d a36_6 = _mm_loadu_pd(&A[481]);
    c36_6 = _mm_add_pd(c36_6, _mm_mul_pd(a36_6, b36));
    _mm_storeu_pd(&C[(l_n*88)+63], c36_6);
    __m128d c36_8 = _mm_loadu_pd(&C[(l_n*88)+65]);
    __m128d a36_8 = _mm_loadu_pd(&A[483]);
    c36_8 = _mm_add_pd(c36_8, _mm_mul_pd(a36_8, b36));
    _mm_storeu_pd(&C[(l_n*88)+65], c36_8);
#endif
    __m128d c36_10 = _mm_loadu_pd(&C[(l_n*88)+67]);
    __m128d a36_10 = _mm_loadu_pd(&A[485]);
#if defined(__SSE3__) && defined(__AVX__)
    c36_10 = _mm_add_pd(c36_10, _mm_mul_pd(a36_10, _mm256_castpd256_pd128(b36)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c36_10 = _mm_add_pd(c36_10, _mm_mul_pd(a36_10, b36));
#endif
    _mm_storeu_pd(&C[(l_n*88)+67], c36_10);
#else
    C[(l_n*88)+35] += A[475] * B[(l_n*88)+36];
    C[(l_n*88)+36] += A[476] * B[(l_n*88)+36];
    C[(l_n*88)+37] += A[477] * B[(l_n*88)+36];
    C[(l_n*88)+38] += A[478] * B[(l_n*88)+36];
    C[(l_n*88)+39] += A[479] * B[(l_n*88)+36];
    C[(l_n*88)+40] += A[480] * B[(l_n*88)+36];
    C[(l_n*88)+63] += A[481] * B[(l_n*88)+36];
    C[(l_n*88)+64] += A[482] * B[(l_n*88)+36];
    C[(l_n*88)+65] += A[483] * B[(l_n*88)+36];
    C[(l_n*88)+66] += A[484] * B[(l_n*88)+36];
    C[(l_n*88)+67] += A[485] * B[(l_n*88)+36];
    C[(l_n*88)+68] += A[486] * B[(l_n*88)+36];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b37 = _mm256_broadcast_sd(&B[(l_n*88)+37]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b37 = _mm_loaddup_pd(&B[(l_n*88)+37]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c37_0 = _mm256_loadu_pd(&C[(l_n*88)+35]);
    __m256d a37_0 = _mm256_loadu_pd(&A[487]);
    c37_0 = _mm256_add_pd(c37_0, _mm256_mul_pd(a37_0, b37));
    _mm256_storeu_pd(&C[(l_n*88)+35], c37_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c37_0 = _mm_loadu_pd(&C[(l_n*88)+35]);
    __m128d a37_0 = _mm_loadu_pd(&A[487]);
    c37_0 = _mm_add_pd(c37_0, _mm_mul_pd(a37_0, b37));
    _mm_storeu_pd(&C[(l_n*88)+35], c37_0);
    __m128d c37_2 = _mm_loadu_pd(&C[(l_n*88)+37]);
    __m128d a37_2 = _mm_loadu_pd(&A[489]);
    c37_2 = _mm_add_pd(c37_2, _mm_mul_pd(a37_2, b37));
    _mm_storeu_pd(&C[(l_n*88)+37], c37_2);
#endif
    __m128d c37_4 = _mm_loadu_pd(&C[(l_n*88)+39]);
    __m128d a37_4 = _mm_loadu_pd(&A[491]);
#if defined(__SSE3__) && defined(__AVX__)
    c37_4 = _mm_add_pd(c37_4, _mm_mul_pd(a37_4, _mm256_castpd256_pd128(b37)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c37_4 = _mm_add_pd(c37_4, _mm_mul_pd(a37_4, b37));
#endif
    _mm_storeu_pd(&C[(l_n*88)+39], c37_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c37_6 = _mm256_loadu_pd(&C[(l_n*88)+63]);
    __m256d a37_6 = _mm256_loadu_pd(&A[493]);
    c37_6 = _mm256_add_pd(c37_6, _mm256_mul_pd(a37_6, b37));
    _mm256_storeu_pd(&C[(l_n*88)+63], c37_6);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c37_6 = _mm_loadu_pd(&C[(l_n*88)+63]);
    __m128d a37_6 = _mm_loadu_pd(&A[493]);
    c37_6 = _mm_add_pd(c37_6, _mm_mul_pd(a37_6, b37));
    _mm_storeu_pd(&C[(l_n*88)+63], c37_6);
    __m128d c37_8 = _mm_loadu_pd(&C[(l_n*88)+65]);
    __m128d a37_8 = _mm_loadu_pd(&A[495]);
    c37_8 = _mm_add_pd(c37_8, _mm_mul_pd(a37_8, b37));
    _mm_storeu_pd(&C[(l_n*88)+65], c37_8);
#endif
    __m128d c37_10 = _mm_loadu_pd(&C[(l_n*88)+67]);
    __m128d a37_10 = _mm_loadu_pd(&A[497]);
#if defined(__SSE3__) && defined(__AVX__)
    c37_10 = _mm_add_pd(c37_10, _mm_mul_pd(a37_10, _mm256_castpd256_pd128(b37)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c37_10 = _mm_add_pd(c37_10, _mm_mul_pd(a37_10, b37));
#endif
    _mm_storeu_pd(&C[(l_n*88)+67], c37_10);
#else
    C[(l_n*88)+35] += A[487] * B[(l_n*88)+37];
    C[(l_n*88)+36] += A[488] * B[(l_n*88)+37];
    C[(l_n*88)+37] += A[489] * B[(l_n*88)+37];
    C[(l_n*88)+38] += A[490] * B[(l_n*88)+37];
    C[(l_n*88)+39] += A[491] * B[(l_n*88)+37];
    C[(l_n*88)+40] += A[492] * B[(l_n*88)+37];
    C[(l_n*88)+63] += A[493] * B[(l_n*88)+37];
    C[(l_n*88)+64] += A[494] * B[(l_n*88)+37];
    C[(l_n*88)+65] += A[495] * B[(l_n*88)+37];
    C[(l_n*88)+66] += A[496] * B[(l_n*88)+37];
    C[(l_n*88)+67] += A[497] * B[(l_n*88)+37];
    C[(l_n*88)+68] += A[498] * B[(l_n*88)+37];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b38 = _mm256_broadcast_sd(&B[(l_n*88)+38]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b38 = _mm_loaddup_pd(&B[(l_n*88)+38]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c38_0 = _mm256_loadu_pd(&C[(l_n*88)+35]);
    __m256d a38_0 = _mm256_loadu_pd(&A[499]);
    c38_0 = _mm256_add_pd(c38_0, _mm256_mul_pd(a38_0, b38));
    _mm256_storeu_pd(&C[(l_n*88)+35], c38_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c38_0 = _mm_loadu_pd(&C[(l_n*88)+35]);
    __m128d a38_0 = _mm_loadu_pd(&A[499]);
    c38_0 = _mm_add_pd(c38_0, _mm_mul_pd(a38_0, b38));
    _mm_storeu_pd(&C[(l_n*88)+35], c38_0);
    __m128d c38_2 = _mm_loadu_pd(&C[(l_n*88)+37]);
    __m128d a38_2 = _mm_loadu_pd(&A[501]);
    c38_2 = _mm_add_pd(c38_2, _mm_mul_pd(a38_2, b38));
    _mm_storeu_pd(&C[(l_n*88)+37], c38_2);
#endif
    __m128d c38_4 = _mm_loadu_pd(&C[(l_n*88)+39]);
    __m128d a38_4 = _mm_loadu_pd(&A[503]);
#if defined(__SSE3__) && defined(__AVX__)
    c38_4 = _mm_add_pd(c38_4, _mm_mul_pd(a38_4, _mm256_castpd256_pd128(b38)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c38_4 = _mm_add_pd(c38_4, _mm_mul_pd(a38_4, b38));
#endif
    _mm_storeu_pd(&C[(l_n*88)+39], c38_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c38_6 = _mm256_loadu_pd(&C[(l_n*88)+63]);
    __m256d a38_6 = _mm256_loadu_pd(&A[505]);
    c38_6 = _mm256_add_pd(c38_6, _mm256_mul_pd(a38_6, b38));
    _mm256_storeu_pd(&C[(l_n*88)+63], c38_6);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c38_6 = _mm_loadu_pd(&C[(l_n*88)+63]);
    __m128d a38_6 = _mm_loadu_pd(&A[505]);
    c38_6 = _mm_add_pd(c38_6, _mm_mul_pd(a38_6, b38));
    _mm_storeu_pd(&C[(l_n*88)+63], c38_6);
    __m128d c38_8 = _mm_loadu_pd(&C[(l_n*88)+65]);
    __m128d a38_8 = _mm_loadu_pd(&A[507]);
    c38_8 = _mm_add_pd(c38_8, _mm_mul_pd(a38_8, b38));
    _mm_storeu_pd(&C[(l_n*88)+65], c38_8);
#endif
    __m128d c38_10 = _mm_loadu_pd(&C[(l_n*88)+67]);
    __m128d a38_10 = _mm_loadu_pd(&A[509]);
#if defined(__SSE3__) && defined(__AVX__)
    c38_10 = _mm_add_pd(c38_10, _mm_mul_pd(a38_10, _mm256_castpd256_pd128(b38)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c38_10 = _mm_add_pd(c38_10, _mm_mul_pd(a38_10, b38));
#endif
    _mm_storeu_pd(&C[(l_n*88)+67], c38_10);
#else
    C[(l_n*88)+35] += A[499] * B[(l_n*88)+38];
    C[(l_n*88)+36] += A[500] * B[(l_n*88)+38];
    C[(l_n*88)+37] += A[501] * B[(l_n*88)+38];
    C[(l_n*88)+38] += A[502] * B[(l_n*88)+38];
    C[(l_n*88)+39] += A[503] * B[(l_n*88)+38];
    C[(l_n*88)+40] += A[504] * B[(l_n*88)+38];
    C[(l_n*88)+63] += A[505] * B[(l_n*88)+38];
    C[(l_n*88)+64] += A[506] * B[(l_n*88)+38];
    C[(l_n*88)+65] += A[507] * B[(l_n*88)+38];
    C[(l_n*88)+66] += A[508] * B[(l_n*88)+38];
    C[(l_n*88)+67] += A[509] * B[(l_n*88)+38];
    C[(l_n*88)+68] += A[510] * B[(l_n*88)+38];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b39 = _mm256_broadcast_sd(&B[(l_n*88)+39]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b39 = _mm_loaddup_pd(&B[(l_n*88)+39]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c39_0 = _mm256_loadu_pd(&C[(l_n*88)+35]);
    __m256d a39_0 = _mm256_loadu_pd(&A[511]);
    c39_0 = _mm256_add_pd(c39_0, _mm256_mul_pd(a39_0, b39));
    _mm256_storeu_pd(&C[(l_n*88)+35], c39_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c39_0 = _mm_loadu_pd(&C[(l_n*88)+35]);
    __m128d a39_0 = _mm_loadu_pd(&A[511]);
    c39_0 = _mm_add_pd(c39_0, _mm_mul_pd(a39_0, b39));
    _mm_storeu_pd(&C[(l_n*88)+35], c39_0);
    __m128d c39_2 = _mm_loadu_pd(&C[(l_n*88)+37]);
    __m128d a39_2 = _mm_loadu_pd(&A[513]);
    c39_2 = _mm_add_pd(c39_2, _mm_mul_pd(a39_2, b39));
    _mm_storeu_pd(&C[(l_n*88)+37], c39_2);
#endif
    __m128d c39_4 = _mm_loadu_pd(&C[(l_n*88)+39]);
    __m128d a39_4 = _mm_loadu_pd(&A[515]);
#if defined(__SSE3__) && defined(__AVX__)
    c39_4 = _mm_add_pd(c39_4, _mm_mul_pd(a39_4, _mm256_castpd256_pd128(b39)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c39_4 = _mm_add_pd(c39_4, _mm_mul_pd(a39_4, b39));
#endif
    _mm_storeu_pd(&C[(l_n*88)+39], c39_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c39_6 = _mm256_loadu_pd(&C[(l_n*88)+63]);
    __m256d a39_6 = _mm256_loadu_pd(&A[517]);
    c39_6 = _mm256_add_pd(c39_6, _mm256_mul_pd(a39_6, b39));
    _mm256_storeu_pd(&C[(l_n*88)+63], c39_6);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c39_6 = _mm_loadu_pd(&C[(l_n*88)+63]);
    __m128d a39_6 = _mm_loadu_pd(&A[517]);
    c39_6 = _mm_add_pd(c39_6, _mm_mul_pd(a39_6, b39));
    _mm_storeu_pd(&C[(l_n*88)+63], c39_6);
    __m128d c39_8 = _mm_loadu_pd(&C[(l_n*88)+65]);
    __m128d a39_8 = _mm_loadu_pd(&A[519]);
    c39_8 = _mm_add_pd(c39_8, _mm_mul_pd(a39_8, b39));
    _mm_storeu_pd(&C[(l_n*88)+65], c39_8);
#endif
    __m128d c39_10 = _mm_loadu_pd(&C[(l_n*88)+67]);
    __m128d a39_10 = _mm_loadu_pd(&A[521]);
#if defined(__SSE3__) && defined(__AVX__)
    c39_10 = _mm_add_pd(c39_10, _mm_mul_pd(a39_10, _mm256_castpd256_pd128(b39)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c39_10 = _mm_add_pd(c39_10, _mm_mul_pd(a39_10, b39));
#endif
    _mm_storeu_pd(&C[(l_n*88)+67], c39_10);
#else
    C[(l_n*88)+35] += A[511] * B[(l_n*88)+39];
    C[(l_n*88)+36] += A[512] * B[(l_n*88)+39];
    C[(l_n*88)+37] += A[513] * B[(l_n*88)+39];
    C[(l_n*88)+38] += A[514] * B[(l_n*88)+39];
    C[(l_n*88)+39] += A[515] * B[(l_n*88)+39];
    C[(l_n*88)+40] += A[516] * B[(l_n*88)+39];
    C[(l_n*88)+63] += A[517] * B[(l_n*88)+39];
    C[(l_n*88)+64] += A[518] * B[(l_n*88)+39];
    C[(l_n*88)+65] += A[519] * B[(l_n*88)+39];
    C[(l_n*88)+66] += A[520] * B[(l_n*88)+39];
    C[(l_n*88)+67] += A[521] * B[(l_n*88)+39];
    C[(l_n*88)+68] += A[522] * B[(l_n*88)+39];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b40 = _mm256_broadcast_sd(&B[(l_n*88)+40]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b40 = _mm_loaddup_pd(&B[(l_n*88)+40]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c40_0 = _mm256_loadu_pd(&C[(l_n*88)+35]);
    __m256d a40_0 = _mm256_loadu_pd(&A[523]);
    c40_0 = _mm256_add_pd(c40_0, _mm256_mul_pd(a40_0, b40));
    _mm256_storeu_pd(&C[(l_n*88)+35], c40_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c40_0 = _mm_loadu_pd(&C[(l_n*88)+35]);
    __m128d a40_0 = _mm_loadu_pd(&A[523]);
    c40_0 = _mm_add_pd(c40_0, _mm_mul_pd(a40_0, b40));
    _mm_storeu_pd(&C[(l_n*88)+35], c40_0);
    __m128d c40_2 = _mm_loadu_pd(&C[(l_n*88)+37]);
    __m128d a40_2 = _mm_loadu_pd(&A[525]);
    c40_2 = _mm_add_pd(c40_2, _mm_mul_pd(a40_2, b40));
    _mm_storeu_pd(&C[(l_n*88)+37], c40_2);
#endif
    __m128d c40_4 = _mm_loadu_pd(&C[(l_n*88)+39]);
    __m128d a40_4 = _mm_loadu_pd(&A[527]);
#if defined(__SSE3__) && defined(__AVX__)
    c40_4 = _mm_add_pd(c40_4, _mm_mul_pd(a40_4, _mm256_castpd256_pd128(b40)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c40_4 = _mm_add_pd(c40_4, _mm_mul_pd(a40_4, b40));
#endif
    _mm_storeu_pd(&C[(l_n*88)+39], c40_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c40_6 = _mm256_loadu_pd(&C[(l_n*88)+63]);
    __m256d a40_6 = _mm256_loadu_pd(&A[529]);
    c40_6 = _mm256_add_pd(c40_6, _mm256_mul_pd(a40_6, b40));
    _mm256_storeu_pd(&C[(l_n*88)+63], c40_6);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c40_6 = _mm_loadu_pd(&C[(l_n*88)+63]);
    __m128d a40_6 = _mm_loadu_pd(&A[529]);
    c40_6 = _mm_add_pd(c40_6, _mm_mul_pd(a40_6, b40));
    _mm_storeu_pd(&C[(l_n*88)+63], c40_6);
    __m128d c40_8 = _mm_loadu_pd(&C[(l_n*88)+65]);
    __m128d a40_8 = _mm_loadu_pd(&A[531]);
    c40_8 = _mm_add_pd(c40_8, _mm_mul_pd(a40_8, b40));
    _mm_storeu_pd(&C[(l_n*88)+65], c40_8);
#endif
    __m128d c40_10 = _mm_loadu_pd(&C[(l_n*88)+67]);
    __m128d a40_10 = _mm_loadu_pd(&A[533]);
#if defined(__SSE3__) && defined(__AVX__)
    c40_10 = _mm_add_pd(c40_10, _mm_mul_pd(a40_10, _mm256_castpd256_pd128(b40)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c40_10 = _mm_add_pd(c40_10, _mm_mul_pd(a40_10, b40));
#endif
    _mm_storeu_pd(&C[(l_n*88)+67], c40_10);
#else
    C[(l_n*88)+35] += A[523] * B[(l_n*88)+40];
    C[(l_n*88)+36] += A[524] * B[(l_n*88)+40];
    C[(l_n*88)+37] += A[525] * B[(l_n*88)+40];
    C[(l_n*88)+38] += A[526] * B[(l_n*88)+40];
    C[(l_n*88)+39] += A[527] * B[(l_n*88)+40];
    C[(l_n*88)+40] += A[528] * B[(l_n*88)+40];
    C[(l_n*88)+63] += A[529] * B[(l_n*88)+40];
    C[(l_n*88)+64] += A[530] * B[(l_n*88)+40];
    C[(l_n*88)+65] += A[531] * B[(l_n*88)+40];
    C[(l_n*88)+66] += A[532] * B[(l_n*88)+40];
    C[(l_n*88)+67] += A[533] * B[(l_n*88)+40];
    C[(l_n*88)+68] += A[534] * B[(l_n*88)+40];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b41 = _mm256_broadcast_sd(&B[(l_n*88)+41]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b41 = _mm_loaddup_pd(&B[(l_n*88)+41]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c41_0 = _mm256_loadu_pd(&C[(l_n*88)+20]);
    __m256d a41_0 = _mm256_loadu_pd(&A[535]);
    c41_0 = _mm256_add_pd(c41_0, _mm256_mul_pd(a41_0, b41));
    _mm256_storeu_pd(&C[(l_n*88)+20], c41_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c41_0 = _mm_loadu_pd(&C[(l_n*88)+20]);
    __m128d a41_0 = _mm_loadu_pd(&A[535]);
    c41_0 = _mm_add_pd(c41_0, _mm_mul_pd(a41_0, b41));
    _mm_storeu_pd(&C[(l_n*88)+20], c41_0);
    __m128d c41_2 = _mm_loadu_pd(&C[(l_n*88)+22]);
    __m128d a41_2 = _mm_loadu_pd(&A[537]);
    c41_2 = _mm_add_pd(c41_2, _mm_mul_pd(a41_2, b41));
    _mm_storeu_pd(&C[(l_n*88)+22], c41_2);
#endif
    __m128d c41_4 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a41_4 = _mm_load_sd(&A[539]);
#if defined(__SSE3__) && defined(__AVX__)
    c41_4 = _mm_add_sd(c41_4, _mm_mul_sd(a41_4, _mm256_castpd256_pd128(b41)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c41_4 = _mm_add_sd(c41_4, _mm_mul_sd(a41_4, b41));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c41_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c41_5 = _mm256_loadu_pd(&C[(l_n*88)+41]);
    __m256d a41_5 = _mm256_loadu_pd(&A[540]);
    c41_5 = _mm256_add_pd(c41_5, _mm256_mul_pd(a41_5, b41));
    _mm256_storeu_pd(&C[(l_n*88)+41], c41_5);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c41_5 = _mm_loadu_pd(&C[(l_n*88)+41]);
    __m128d a41_5 = _mm_loadu_pd(&A[540]);
    c41_5 = _mm_add_pd(c41_5, _mm_mul_pd(a41_5, b41));
    _mm_storeu_pd(&C[(l_n*88)+41], c41_5);
    __m128d c41_7 = _mm_loadu_pd(&C[(l_n*88)+43]);
    __m128d a41_7 = _mm_loadu_pd(&A[542]);
    c41_7 = _mm_add_pd(c41_7, _mm_mul_pd(a41_7, b41));
    _mm_storeu_pd(&C[(l_n*88)+43], c41_7);
#endif
    __m128d c41_9 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a41_9 = _mm_load_sd(&A[544]);
#if defined(__SSE3__) && defined(__AVX__)
    c41_9 = _mm_add_sd(c41_9, _mm_mul_sd(a41_9, _mm256_castpd256_pd128(b41)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c41_9 = _mm_add_sd(c41_9, _mm_mul_sd(a41_9, b41));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c41_9);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c41_10 = _mm256_loadu_pd(&C[(l_n*88)+69]);
    __m256d a41_10 = _mm256_loadu_pd(&A[545]);
    c41_10 = _mm256_add_pd(c41_10, _mm256_mul_pd(a41_10, b41));
    _mm256_storeu_pd(&C[(l_n*88)+69], c41_10);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c41_10 = _mm_loadu_pd(&C[(l_n*88)+69]);
    __m128d a41_10 = _mm_loadu_pd(&A[545]);
    c41_10 = _mm_add_pd(c41_10, _mm_mul_pd(a41_10, b41));
    _mm_storeu_pd(&C[(l_n*88)+69], c41_10);
    __m128d c41_12 = _mm_loadu_pd(&C[(l_n*88)+71]);
    __m128d a41_12 = _mm_loadu_pd(&A[547]);
    c41_12 = _mm_add_pd(c41_12, _mm_mul_pd(a41_12, b41));
    _mm_storeu_pd(&C[(l_n*88)+71], c41_12);
#endif
    __m128d c41_14 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a41_14 = _mm_load_sd(&A[549]);
#if defined(__SSE3__) && defined(__AVX__)
    c41_14 = _mm_add_sd(c41_14, _mm_mul_sd(a41_14, _mm256_castpd256_pd128(b41)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c41_14 = _mm_add_sd(c41_14, _mm_mul_sd(a41_14, b41));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c41_14);
#else
    C[(l_n*88)+20] += A[535] * B[(l_n*88)+41];
    C[(l_n*88)+21] += A[536] * B[(l_n*88)+41];
    C[(l_n*88)+22] += A[537] * B[(l_n*88)+41];
    C[(l_n*88)+23] += A[538] * B[(l_n*88)+41];
    C[(l_n*88)+24] += A[539] * B[(l_n*88)+41];
    C[(l_n*88)+41] += A[540] * B[(l_n*88)+41];
    C[(l_n*88)+42] += A[541] * B[(l_n*88)+41];
    C[(l_n*88)+43] += A[542] * B[(l_n*88)+41];
    C[(l_n*88)+44] += A[543] * B[(l_n*88)+41];
    C[(l_n*88)+45] += A[544] * B[(l_n*88)+41];
    C[(l_n*88)+69] += A[545] * B[(l_n*88)+41];
    C[(l_n*88)+70] += A[546] * B[(l_n*88)+41];
    C[(l_n*88)+71] += A[547] * B[(l_n*88)+41];
    C[(l_n*88)+72] += A[548] * B[(l_n*88)+41];
    C[(l_n*88)+73] += A[549] * B[(l_n*88)+41];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b42 = _mm256_broadcast_sd(&B[(l_n*88)+42]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b42 = _mm_loaddup_pd(&B[(l_n*88)+42]);
#endif
    __m128d c42_0 = _mm_loadu_pd(&C[(l_n*88)+20]);
    __m128d a42_0 = _mm_loadu_pd(&A[550]);
#if defined(__SSE3__) && defined(__AVX__)
    c42_0 = _mm_add_pd(c42_0, _mm_mul_pd(a42_0, _mm256_castpd256_pd128(b42)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c42_0 = _mm_add_pd(c42_0, _mm_mul_pd(a42_0, b42));
#endif
    _mm_storeu_pd(&C[(l_n*88)+20], c42_0);
    __m128d c42_2 = _mm_load_sd(&C[(l_n*88)+22]);
    __m128d a42_2 = _mm_load_sd(&A[552]);
#if defined(__SSE3__) && defined(__AVX__)
    c42_2 = _mm_add_sd(c42_2, _mm_mul_sd(a42_2, _mm256_castpd256_pd128(b42)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c42_2 = _mm_add_sd(c42_2, _mm_mul_sd(a42_2, b42));
#endif
    _mm_store_sd(&C[(l_n*88)+22], c42_2);
    __m128d c42_3 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a42_3 = _mm_load_sd(&A[553]);
#if defined(__SSE3__) && defined(__AVX__)
    c42_3 = _mm_add_sd(c42_3, _mm_mul_sd(a42_3, _mm256_castpd256_pd128(b42)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c42_3 = _mm_add_sd(c42_3, _mm_mul_sd(a42_3, b42));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c42_3);
    __m128d c42_4 = _mm_loadu_pd(&C[(l_n*88)+41]);
    __m128d a42_4 = _mm_loadu_pd(&A[554]);
#if defined(__SSE3__) && defined(__AVX__)
    c42_4 = _mm_add_pd(c42_4, _mm_mul_pd(a42_4, _mm256_castpd256_pd128(b42)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c42_4 = _mm_add_pd(c42_4, _mm_mul_pd(a42_4, b42));
#endif
    _mm_storeu_pd(&C[(l_n*88)+41], c42_4);
    __m128d c42_6 = _mm_load_sd(&C[(l_n*88)+43]);
    __m128d a42_6 = _mm_load_sd(&A[556]);
#if defined(__SSE3__) && defined(__AVX__)
    c42_6 = _mm_add_sd(c42_6, _mm_mul_sd(a42_6, _mm256_castpd256_pd128(b42)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c42_6 = _mm_add_sd(c42_6, _mm_mul_sd(a42_6, b42));
#endif
    _mm_store_sd(&C[(l_n*88)+43], c42_6);
    __m128d c42_7 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a42_7 = _mm_load_sd(&A[557]);
#if defined(__SSE3__) && defined(__AVX__)
    c42_7 = _mm_add_sd(c42_7, _mm_mul_sd(a42_7, _mm256_castpd256_pd128(b42)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c42_7 = _mm_add_sd(c42_7, _mm_mul_sd(a42_7, b42));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c42_7);
    __m128d c42_8 = _mm_loadu_pd(&C[(l_n*88)+69]);
    __m128d a42_8 = _mm_loadu_pd(&A[558]);
#if defined(__SSE3__) && defined(__AVX__)
    c42_8 = _mm_add_pd(c42_8, _mm_mul_pd(a42_8, _mm256_castpd256_pd128(b42)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c42_8 = _mm_add_pd(c42_8, _mm_mul_pd(a42_8, b42));
#endif
    _mm_storeu_pd(&C[(l_n*88)+69], c42_8);
    __m128d c42_10 = _mm_load_sd(&C[(l_n*88)+71]);
    __m128d a42_10 = _mm_load_sd(&A[560]);
#if defined(__SSE3__) && defined(__AVX__)
    c42_10 = _mm_add_sd(c42_10, _mm_mul_sd(a42_10, _mm256_castpd256_pd128(b42)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c42_10 = _mm_add_sd(c42_10, _mm_mul_sd(a42_10, b42));
#endif
    _mm_store_sd(&C[(l_n*88)+71], c42_10);
    __m128d c42_11 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a42_11 = _mm_load_sd(&A[561]);
#if defined(__SSE3__) && defined(__AVX__)
    c42_11 = _mm_add_sd(c42_11, _mm_mul_sd(a42_11, _mm256_castpd256_pd128(b42)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c42_11 = _mm_add_sd(c42_11, _mm_mul_sd(a42_11, b42));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c42_11);
#else
    C[(l_n*88)+20] += A[550] * B[(l_n*88)+42];
    C[(l_n*88)+21] += A[551] * B[(l_n*88)+42];
    C[(l_n*88)+22] += A[552] * B[(l_n*88)+42];
    C[(l_n*88)+24] += A[553] * B[(l_n*88)+42];
    C[(l_n*88)+41] += A[554] * B[(l_n*88)+42];
    C[(l_n*88)+42] += A[555] * B[(l_n*88)+42];
    C[(l_n*88)+43] += A[556] * B[(l_n*88)+42];
    C[(l_n*88)+45] += A[557] * B[(l_n*88)+42];
    C[(l_n*88)+69] += A[558] * B[(l_n*88)+42];
    C[(l_n*88)+70] += A[559] * B[(l_n*88)+42];
    C[(l_n*88)+71] += A[560] * B[(l_n*88)+42];
    C[(l_n*88)+73] += A[561] * B[(l_n*88)+42];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b43 = _mm256_broadcast_sd(&B[(l_n*88)+43]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b43 = _mm_loaddup_pd(&B[(l_n*88)+43]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c43_0 = _mm256_loadu_pd(&C[(l_n*88)+20]);
    __m256d a43_0 = _mm256_loadu_pd(&A[562]);
    c43_0 = _mm256_add_pd(c43_0, _mm256_mul_pd(a43_0, b43));
    _mm256_storeu_pd(&C[(l_n*88)+20], c43_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c43_0 = _mm_loadu_pd(&C[(l_n*88)+20]);
    __m128d a43_0 = _mm_loadu_pd(&A[562]);
    c43_0 = _mm_add_pd(c43_0, _mm_mul_pd(a43_0, b43));
    _mm_storeu_pd(&C[(l_n*88)+20], c43_0);
    __m128d c43_2 = _mm_loadu_pd(&C[(l_n*88)+22]);
    __m128d a43_2 = _mm_loadu_pd(&A[564]);
    c43_2 = _mm_add_pd(c43_2, _mm_mul_pd(a43_2, b43));
    _mm_storeu_pd(&C[(l_n*88)+22], c43_2);
#endif
    __m128d c43_4 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a43_4 = _mm_load_sd(&A[566]);
#if defined(__SSE3__) && defined(__AVX__)
    c43_4 = _mm_add_sd(c43_4, _mm_mul_sd(a43_4, _mm256_castpd256_pd128(b43)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c43_4 = _mm_add_sd(c43_4, _mm_mul_sd(a43_4, b43));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c43_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c43_5 = _mm256_loadu_pd(&C[(l_n*88)+41]);
    __m256d a43_5 = _mm256_loadu_pd(&A[567]);
    c43_5 = _mm256_add_pd(c43_5, _mm256_mul_pd(a43_5, b43));
    _mm256_storeu_pd(&C[(l_n*88)+41], c43_5);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c43_5 = _mm_loadu_pd(&C[(l_n*88)+41]);
    __m128d a43_5 = _mm_loadu_pd(&A[567]);
    c43_5 = _mm_add_pd(c43_5, _mm_mul_pd(a43_5, b43));
    _mm_storeu_pd(&C[(l_n*88)+41], c43_5);
    __m128d c43_7 = _mm_loadu_pd(&C[(l_n*88)+43]);
    __m128d a43_7 = _mm_loadu_pd(&A[569]);
    c43_7 = _mm_add_pd(c43_7, _mm_mul_pd(a43_7, b43));
    _mm_storeu_pd(&C[(l_n*88)+43], c43_7);
#endif
    __m128d c43_9 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a43_9 = _mm_load_sd(&A[571]);
#if defined(__SSE3__) && defined(__AVX__)
    c43_9 = _mm_add_sd(c43_9, _mm_mul_sd(a43_9, _mm256_castpd256_pd128(b43)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c43_9 = _mm_add_sd(c43_9, _mm_mul_sd(a43_9, b43));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c43_9);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c43_10 = _mm256_loadu_pd(&C[(l_n*88)+69]);
    __m256d a43_10 = _mm256_loadu_pd(&A[572]);
    c43_10 = _mm256_add_pd(c43_10, _mm256_mul_pd(a43_10, b43));
    _mm256_storeu_pd(&C[(l_n*88)+69], c43_10);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c43_10 = _mm_loadu_pd(&C[(l_n*88)+69]);
    __m128d a43_10 = _mm_loadu_pd(&A[572]);
    c43_10 = _mm_add_pd(c43_10, _mm_mul_pd(a43_10, b43));
    _mm_storeu_pd(&C[(l_n*88)+69], c43_10);
    __m128d c43_12 = _mm_loadu_pd(&C[(l_n*88)+71]);
    __m128d a43_12 = _mm_loadu_pd(&A[574]);
    c43_12 = _mm_add_pd(c43_12, _mm_mul_pd(a43_12, b43));
    _mm_storeu_pd(&C[(l_n*88)+71], c43_12);
#endif
    __m128d c43_14 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a43_14 = _mm_load_sd(&A[576]);
#if defined(__SSE3__) && defined(__AVX__)
    c43_14 = _mm_add_sd(c43_14, _mm_mul_sd(a43_14, _mm256_castpd256_pd128(b43)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c43_14 = _mm_add_sd(c43_14, _mm_mul_sd(a43_14, b43));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c43_14);
#else
    C[(l_n*88)+20] += A[562] * B[(l_n*88)+43];
    C[(l_n*88)+21] += A[563] * B[(l_n*88)+43];
    C[(l_n*88)+22] += A[564] * B[(l_n*88)+43];
    C[(l_n*88)+23] += A[565] * B[(l_n*88)+43];
    C[(l_n*88)+24] += A[566] * B[(l_n*88)+43];
    C[(l_n*88)+41] += A[567] * B[(l_n*88)+43];
    C[(l_n*88)+42] += A[568] * B[(l_n*88)+43];
    C[(l_n*88)+43] += A[569] * B[(l_n*88)+43];
    C[(l_n*88)+44] += A[570] * B[(l_n*88)+43];
    C[(l_n*88)+45] += A[571] * B[(l_n*88)+43];
    C[(l_n*88)+69] += A[572] * B[(l_n*88)+43];
    C[(l_n*88)+70] += A[573] * B[(l_n*88)+43];
    C[(l_n*88)+71] += A[574] * B[(l_n*88)+43];
    C[(l_n*88)+72] += A[575] * B[(l_n*88)+43];
    C[(l_n*88)+73] += A[576] * B[(l_n*88)+43];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b44 = _mm256_broadcast_sd(&B[(l_n*88)+44]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b44 = _mm_loaddup_pd(&B[(l_n*88)+44]);
#endif
    __m128d c44_0 = _mm_load_sd(&C[(l_n*88)+20]);
    __m128d a44_0 = _mm_load_sd(&A[577]);
#if defined(__SSE3__) && defined(__AVX__)
    c44_0 = _mm_add_sd(c44_0, _mm_mul_sd(a44_0, _mm256_castpd256_pd128(b44)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c44_0 = _mm_add_sd(c44_0, _mm_mul_sd(a44_0, b44));
#endif
    _mm_store_sd(&C[(l_n*88)+20], c44_0);
    __m128d c44_1 = _mm_loadu_pd(&C[(l_n*88)+22]);
    __m128d a44_1 = _mm_loadu_pd(&A[578]);
#if defined(__SSE3__) && defined(__AVX__)
    c44_1 = _mm_add_pd(c44_1, _mm_mul_pd(a44_1, _mm256_castpd256_pd128(b44)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c44_1 = _mm_add_pd(c44_1, _mm_mul_pd(a44_1, b44));
#endif
    _mm_storeu_pd(&C[(l_n*88)+22], c44_1);
    __m128d c44_3 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a44_3 = _mm_load_sd(&A[580]);
#if defined(__SSE3__) && defined(__AVX__)
    c44_3 = _mm_add_sd(c44_3, _mm_mul_sd(a44_3, _mm256_castpd256_pd128(b44)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c44_3 = _mm_add_sd(c44_3, _mm_mul_sd(a44_3, b44));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c44_3);
    __m128d c44_4 = _mm_load_sd(&C[(l_n*88)+41]);
    __m128d a44_4 = _mm_load_sd(&A[581]);
#if defined(__SSE3__) && defined(__AVX__)
    c44_4 = _mm_add_sd(c44_4, _mm_mul_sd(a44_4, _mm256_castpd256_pd128(b44)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c44_4 = _mm_add_sd(c44_4, _mm_mul_sd(a44_4, b44));
#endif
    _mm_store_sd(&C[(l_n*88)+41], c44_4);
    __m128d c44_5 = _mm_loadu_pd(&C[(l_n*88)+43]);
    __m128d a44_5 = _mm_loadu_pd(&A[582]);
#if defined(__SSE3__) && defined(__AVX__)
    c44_5 = _mm_add_pd(c44_5, _mm_mul_pd(a44_5, _mm256_castpd256_pd128(b44)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c44_5 = _mm_add_pd(c44_5, _mm_mul_pd(a44_5, b44));
#endif
    _mm_storeu_pd(&C[(l_n*88)+43], c44_5);
    __m128d c44_7 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a44_7 = _mm_load_sd(&A[584]);
#if defined(__SSE3__) && defined(__AVX__)
    c44_7 = _mm_add_sd(c44_7, _mm_mul_sd(a44_7, _mm256_castpd256_pd128(b44)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c44_7 = _mm_add_sd(c44_7, _mm_mul_sd(a44_7, b44));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c44_7);
    __m128d c44_8 = _mm_load_sd(&C[(l_n*88)+69]);
    __m128d a44_8 = _mm_load_sd(&A[585]);
#if defined(__SSE3__) && defined(__AVX__)
    c44_8 = _mm_add_sd(c44_8, _mm_mul_sd(a44_8, _mm256_castpd256_pd128(b44)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c44_8 = _mm_add_sd(c44_8, _mm_mul_sd(a44_8, b44));
#endif
    _mm_store_sd(&C[(l_n*88)+69], c44_8);
    __m128d c44_9 = _mm_loadu_pd(&C[(l_n*88)+71]);
    __m128d a44_9 = _mm_loadu_pd(&A[586]);
#if defined(__SSE3__) && defined(__AVX__)
    c44_9 = _mm_add_pd(c44_9, _mm_mul_pd(a44_9, _mm256_castpd256_pd128(b44)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c44_9 = _mm_add_pd(c44_9, _mm_mul_pd(a44_9, b44));
#endif
    _mm_storeu_pd(&C[(l_n*88)+71], c44_9);
    __m128d c44_11 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a44_11 = _mm_load_sd(&A[588]);
#if defined(__SSE3__) && defined(__AVX__)
    c44_11 = _mm_add_sd(c44_11, _mm_mul_sd(a44_11, _mm256_castpd256_pd128(b44)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c44_11 = _mm_add_sd(c44_11, _mm_mul_sd(a44_11, b44));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c44_11);
#else
    C[(l_n*88)+20] += A[577] * B[(l_n*88)+44];
    C[(l_n*88)+22] += A[578] * B[(l_n*88)+44];
    C[(l_n*88)+23] += A[579] * B[(l_n*88)+44];
    C[(l_n*88)+24] += A[580] * B[(l_n*88)+44];
    C[(l_n*88)+41] += A[581] * B[(l_n*88)+44];
    C[(l_n*88)+43] += A[582] * B[(l_n*88)+44];
    C[(l_n*88)+44] += A[583] * B[(l_n*88)+44];
    C[(l_n*88)+45] += A[584] * B[(l_n*88)+44];
    C[(l_n*88)+69] += A[585] * B[(l_n*88)+44];
    C[(l_n*88)+71] += A[586] * B[(l_n*88)+44];
    C[(l_n*88)+72] += A[587] * B[(l_n*88)+44];
    C[(l_n*88)+73] += A[588] * B[(l_n*88)+44];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b45 = _mm256_broadcast_sd(&B[(l_n*88)+45]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b45 = _mm_loaddup_pd(&B[(l_n*88)+45]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c45_0 = _mm256_loadu_pd(&C[(l_n*88)+20]);
    __m256d a45_0 = _mm256_loadu_pd(&A[589]);
    c45_0 = _mm256_add_pd(c45_0, _mm256_mul_pd(a45_0, b45));
    _mm256_storeu_pd(&C[(l_n*88)+20], c45_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c45_0 = _mm_loadu_pd(&C[(l_n*88)+20]);
    __m128d a45_0 = _mm_loadu_pd(&A[589]);
    c45_0 = _mm_add_pd(c45_0, _mm_mul_pd(a45_0, b45));
    _mm_storeu_pd(&C[(l_n*88)+20], c45_0);
    __m128d c45_2 = _mm_loadu_pd(&C[(l_n*88)+22]);
    __m128d a45_2 = _mm_loadu_pd(&A[591]);
    c45_2 = _mm_add_pd(c45_2, _mm_mul_pd(a45_2, b45));
    _mm_storeu_pd(&C[(l_n*88)+22], c45_2);
#endif
    __m128d c45_4 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a45_4 = _mm_load_sd(&A[593]);
#if defined(__SSE3__) && defined(__AVX__)
    c45_4 = _mm_add_sd(c45_4, _mm_mul_sd(a45_4, _mm256_castpd256_pd128(b45)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c45_4 = _mm_add_sd(c45_4, _mm_mul_sd(a45_4, b45));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c45_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c45_5 = _mm256_loadu_pd(&C[(l_n*88)+41]);
    __m256d a45_5 = _mm256_loadu_pd(&A[594]);
    c45_5 = _mm256_add_pd(c45_5, _mm256_mul_pd(a45_5, b45));
    _mm256_storeu_pd(&C[(l_n*88)+41], c45_5);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c45_5 = _mm_loadu_pd(&C[(l_n*88)+41]);
    __m128d a45_5 = _mm_loadu_pd(&A[594]);
    c45_5 = _mm_add_pd(c45_5, _mm_mul_pd(a45_5, b45));
    _mm_storeu_pd(&C[(l_n*88)+41], c45_5);
    __m128d c45_7 = _mm_loadu_pd(&C[(l_n*88)+43]);
    __m128d a45_7 = _mm_loadu_pd(&A[596]);
    c45_7 = _mm_add_pd(c45_7, _mm_mul_pd(a45_7, b45));
    _mm_storeu_pd(&C[(l_n*88)+43], c45_7);
#endif
    __m128d c45_9 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a45_9 = _mm_load_sd(&A[598]);
#if defined(__SSE3__) && defined(__AVX__)
    c45_9 = _mm_add_sd(c45_9, _mm_mul_sd(a45_9, _mm256_castpd256_pd128(b45)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c45_9 = _mm_add_sd(c45_9, _mm_mul_sd(a45_9, b45));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c45_9);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c45_10 = _mm256_loadu_pd(&C[(l_n*88)+69]);
    __m256d a45_10 = _mm256_loadu_pd(&A[599]);
    c45_10 = _mm256_add_pd(c45_10, _mm256_mul_pd(a45_10, b45));
    _mm256_storeu_pd(&C[(l_n*88)+69], c45_10);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c45_10 = _mm_loadu_pd(&C[(l_n*88)+69]);
    __m128d a45_10 = _mm_loadu_pd(&A[599]);
    c45_10 = _mm_add_pd(c45_10, _mm_mul_pd(a45_10, b45));
    _mm_storeu_pd(&C[(l_n*88)+69], c45_10);
    __m128d c45_12 = _mm_loadu_pd(&C[(l_n*88)+71]);
    __m128d a45_12 = _mm_loadu_pd(&A[601]);
    c45_12 = _mm_add_pd(c45_12, _mm_mul_pd(a45_12, b45));
    _mm_storeu_pd(&C[(l_n*88)+71], c45_12);
#endif
    __m128d c45_14 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a45_14 = _mm_load_sd(&A[603]);
#if defined(__SSE3__) && defined(__AVX__)
    c45_14 = _mm_add_sd(c45_14, _mm_mul_sd(a45_14, _mm256_castpd256_pd128(b45)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c45_14 = _mm_add_sd(c45_14, _mm_mul_sd(a45_14, b45));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c45_14);
#else
    C[(l_n*88)+20] += A[589] * B[(l_n*88)+45];
    C[(l_n*88)+21] += A[590] * B[(l_n*88)+45];
    C[(l_n*88)+22] += A[591] * B[(l_n*88)+45];
    C[(l_n*88)+23] += A[592] * B[(l_n*88)+45];
    C[(l_n*88)+24] += A[593] * B[(l_n*88)+45];
    C[(l_n*88)+41] += A[594] * B[(l_n*88)+45];
    C[(l_n*88)+42] += A[595] * B[(l_n*88)+45];
    C[(l_n*88)+43] += A[596] * B[(l_n*88)+45];
    C[(l_n*88)+44] += A[597] * B[(l_n*88)+45];
    C[(l_n*88)+45] += A[598] * B[(l_n*88)+45];
    C[(l_n*88)+69] += A[599] * B[(l_n*88)+45];
    C[(l_n*88)+70] += A[600] * B[(l_n*88)+45];
    C[(l_n*88)+71] += A[601] * B[(l_n*88)+45];
    C[(l_n*88)+72] += A[602] * B[(l_n*88)+45];
    C[(l_n*88)+73] += A[603] * B[(l_n*88)+45];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b46 = _mm256_broadcast_sd(&B[(l_n*88)+46]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b46 = _mm_loaddup_pd(&B[(l_n*88)+46]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c46_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a46_0 = _mm256_loadu_pd(&A[604]);
    c46_0 = _mm256_add_pd(c46_0, _mm256_mul_pd(a46_0, b46));
    _mm256_storeu_pd(&C[(l_n*88)+10], c46_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c46_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a46_0 = _mm_loadu_pd(&A[604]);
    c46_0 = _mm_add_pd(c46_0, _mm_mul_pd(a46_0, b46));
    _mm_storeu_pd(&C[(l_n*88)+10], c46_0);
    __m128d c46_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a46_2 = _mm_loadu_pd(&A[606]);
    c46_2 = _mm_add_pd(c46_2, _mm_mul_pd(a46_2, b46));
    _mm_storeu_pd(&C[(l_n*88)+12], c46_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c46_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a46_4 = _mm256_loadu_pd(&A[608]);
    c46_4 = _mm256_add_pd(c46_4, _mm256_mul_pd(a46_4, b46));
    _mm256_storeu_pd(&C[(l_n*88)+25], c46_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c46_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a46_4 = _mm_loadu_pd(&A[608]);
    c46_4 = _mm_add_pd(c46_4, _mm_mul_pd(a46_4, b46));
    _mm_storeu_pd(&C[(l_n*88)+25], c46_4);
    __m128d c46_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a46_6 = _mm_loadu_pd(&A[610]);
    c46_6 = _mm_add_pd(c46_6, _mm_mul_pd(a46_6, b46));
    _mm_storeu_pd(&C[(l_n*88)+27], c46_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c46_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a46_8 = _mm256_loadu_pd(&A[612]);
    c46_8 = _mm256_add_pd(c46_8, _mm256_mul_pd(a46_8, b46));
    _mm256_storeu_pd(&C[(l_n*88)+46], c46_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c46_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a46_8 = _mm_loadu_pd(&A[612]);
    c46_8 = _mm_add_pd(c46_8, _mm_mul_pd(a46_8, b46));
    _mm_storeu_pd(&C[(l_n*88)+46], c46_8);
    __m128d c46_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a46_10 = _mm_loadu_pd(&A[614]);
    c46_10 = _mm_add_pd(c46_10, _mm_mul_pd(a46_10, b46));
    _mm_storeu_pd(&C[(l_n*88)+48], c46_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c46_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a46_12 = _mm256_loadu_pd(&A[616]);
    c46_12 = _mm256_add_pd(c46_12, _mm256_mul_pd(a46_12, b46));
    _mm256_storeu_pd(&C[(l_n*88)+74], c46_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c46_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a46_12 = _mm_loadu_pd(&A[616]);
    c46_12 = _mm_add_pd(c46_12, _mm_mul_pd(a46_12, b46));
    _mm_storeu_pd(&C[(l_n*88)+74], c46_12);
    __m128d c46_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a46_14 = _mm_loadu_pd(&A[618]);
    c46_14 = _mm_add_pd(c46_14, _mm_mul_pd(a46_14, b46));
    _mm_storeu_pd(&C[(l_n*88)+76], c46_14);
#endif
#else
    C[(l_n*88)+10] += A[604] * B[(l_n*88)+46];
    C[(l_n*88)+11] += A[605] * B[(l_n*88)+46];
    C[(l_n*88)+12] += A[606] * B[(l_n*88)+46];
    C[(l_n*88)+13] += A[607] * B[(l_n*88)+46];
    C[(l_n*88)+25] += A[608] * B[(l_n*88)+46];
    C[(l_n*88)+26] += A[609] * B[(l_n*88)+46];
    C[(l_n*88)+27] += A[610] * B[(l_n*88)+46];
    C[(l_n*88)+28] += A[611] * B[(l_n*88)+46];
    C[(l_n*88)+46] += A[612] * B[(l_n*88)+46];
    C[(l_n*88)+47] += A[613] * B[(l_n*88)+46];
    C[(l_n*88)+48] += A[614] * B[(l_n*88)+46];
    C[(l_n*88)+49] += A[615] * B[(l_n*88)+46];
    C[(l_n*88)+74] += A[616] * B[(l_n*88)+46];
    C[(l_n*88)+75] += A[617] * B[(l_n*88)+46];
    C[(l_n*88)+76] += A[618] * B[(l_n*88)+46];
    C[(l_n*88)+77] += A[619] * B[(l_n*88)+46];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b47 = _mm256_broadcast_sd(&B[(l_n*88)+47]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b47 = _mm_loaddup_pd(&B[(l_n*88)+47]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c47_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a47_0 = _mm256_loadu_pd(&A[620]);
    c47_0 = _mm256_add_pd(c47_0, _mm256_mul_pd(a47_0, b47));
    _mm256_storeu_pd(&C[(l_n*88)+10], c47_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c47_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a47_0 = _mm_loadu_pd(&A[620]);
    c47_0 = _mm_add_pd(c47_0, _mm_mul_pd(a47_0, b47));
    _mm_storeu_pd(&C[(l_n*88)+10], c47_0);
    __m128d c47_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a47_2 = _mm_loadu_pd(&A[622]);
    c47_2 = _mm_add_pd(c47_2, _mm_mul_pd(a47_2, b47));
    _mm_storeu_pd(&C[(l_n*88)+12], c47_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c47_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a47_4 = _mm256_loadu_pd(&A[624]);
    c47_4 = _mm256_add_pd(c47_4, _mm256_mul_pd(a47_4, b47));
    _mm256_storeu_pd(&C[(l_n*88)+25], c47_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c47_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a47_4 = _mm_loadu_pd(&A[624]);
    c47_4 = _mm_add_pd(c47_4, _mm_mul_pd(a47_4, b47));
    _mm_storeu_pd(&C[(l_n*88)+25], c47_4);
    __m128d c47_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a47_6 = _mm_loadu_pd(&A[626]);
    c47_6 = _mm_add_pd(c47_6, _mm_mul_pd(a47_6, b47));
    _mm_storeu_pd(&C[(l_n*88)+27], c47_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c47_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a47_8 = _mm256_loadu_pd(&A[628]);
    c47_8 = _mm256_add_pd(c47_8, _mm256_mul_pd(a47_8, b47));
    _mm256_storeu_pd(&C[(l_n*88)+46], c47_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c47_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a47_8 = _mm_loadu_pd(&A[628]);
    c47_8 = _mm_add_pd(c47_8, _mm_mul_pd(a47_8, b47));
    _mm_storeu_pd(&C[(l_n*88)+46], c47_8);
    __m128d c47_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a47_10 = _mm_loadu_pd(&A[630]);
    c47_10 = _mm_add_pd(c47_10, _mm_mul_pd(a47_10, b47));
    _mm_storeu_pd(&C[(l_n*88)+48], c47_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c47_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a47_12 = _mm256_loadu_pd(&A[632]);
    c47_12 = _mm256_add_pd(c47_12, _mm256_mul_pd(a47_12, b47));
    _mm256_storeu_pd(&C[(l_n*88)+74], c47_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c47_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a47_12 = _mm_loadu_pd(&A[632]);
    c47_12 = _mm_add_pd(c47_12, _mm_mul_pd(a47_12, b47));
    _mm_storeu_pd(&C[(l_n*88)+74], c47_12);
    __m128d c47_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a47_14 = _mm_loadu_pd(&A[634]);
    c47_14 = _mm_add_pd(c47_14, _mm_mul_pd(a47_14, b47));
    _mm_storeu_pd(&C[(l_n*88)+76], c47_14);
#endif
#else
    C[(l_n*88)+10] += A[620] * B[(l_n*88)+47];
    C[(l_n*88)+11] += A[621] * B[(l_n*88)+47];
    C[(l_n*88)+12] += A[622] * B[(l_n*88)+47];
    C[(l_n*88)+13] += A[623] * B[(l_n*88)+47];
    C[(l_n*88)+25] += A[624] * B[(l_n*88)+47];
    C[(l_n*88)+26] += A[625] * B[(l_n*88)+47];
    C[(l_n*88)+27] += A[626] * B[(l_n*88)+47];
    C[(l_n*88)+28] += A[627] * B[(l_n*88)+47];
    C[(l_n*88)+46] += A[628] * B[(l_n*88)+47];
    C[(l_n*88)+47] += A[629] * B[(l_n*88)+47];
    C[(l_n*88)+48] += A[630] * B[(l_n*88)+47];
    C[(l_n*88)+49] += A[631] * B[(l_n*88)+47];
    C[(l_n*88)+74] += A[632] * B[(l_n*88)+47];
    C[(l_n*88)+75] += A[633] * B[(l_n*88)+47];
    C[(l_n*88)+76] += A[634] * B[(l_n*88)+47];
    C[(l_n*88)+77] += A[635] * B[(l_n*88)+47];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b48 = _mm256_broadcast_sd(&B[(l_n*88)+48]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b48 = _mm_loaddup_pd(&B[(l_n*88)+48]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c48_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a48_0 = _mm256_loadu_pd(&A[636]);
    c48_0 = _mm256_add_pd(c48_0, _mm256_mul_pd(a48_0, b48));
    _mm256_storeu_pd(&C[(l_n*88)+10], c48_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c48_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a48_0 = _mm_loadu_pd(&A[636]);
    c48_0 = _mm_add_pd(c48_0, _mm_mul_pd(a48_0, b48));
    _mm_storeu_pd(&C[(l_n*88)+10], c48_0);
    __m128d c48_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a48_2 = _mm_loadu_pd(&A[638]);
    c48_2 = _mm_add_pd(c48_2, _mm_mul_pd(a48_2, b48));
    _mm_storeu_pd(&C[(l_n*88)+12], c48_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c48_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a48_4 = _mm256_loadu_pd(&A[640]);
    c48_4 = _mm256_add_pd(c48_4, _mm256_mul_pd(a48_4, b48));
    _mm256_storeu_pd(&C[(l_n*88)+25], c48_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c48_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a48_4 = _mm_loadu_pd(&A[640]);
    c48_4 = _mm_add_pd(c48_4, _mm_mul_pd(a48_4, b48));
    _mm_storeu_pd(&C[(l_n*88)+25], c48_4);
    __m128d c48_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a48_6 = _mm_loadu_pd(&A[642]);
    c48_6 = _mm_add_pd(c48_6, _mm_mul_pd(a48_6, b48));
    _mm_storeu_pd(&C[(l_n*88)+27], c48_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c48_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a48_8 = _mm256_loadu_pd(&A[644]);
    c48_8 = _mm256_add_pd(c48_8, _mm256_mul_pd(a48_8, b48));
    _mm256_storeu_pd(&C[(l_n*88)+46], c48_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c48_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a48_8 = _mm_loadu_pd(&A[644]);
    c48_8 = _mm_add_pd(c48_8, _mm_mul_pd(a48_8, b48));
    _mm_storeu_pd(&C[(l_n*88)+46], c48_8);
    __m128d c48_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a48_10 = _mm_loadu_pd(&A[646]);
    c48_10 = _mm_add_pd(c48_10, _mm_mul_pd(a48_10, b48));
    _mm_storeu_pd(&C[(l_n*88)+48], c48_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c48_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a48_12 = _mm256_loadu_pd(&A[648]);
    c48_12 = _mm256_add_pd(c48_12, _mm256_mul_pd(a48_12, b48));
    _mm256_storeu_pd(&C[(l_n*88)+74], c48_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c48_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a48_12 = _mm_loadu_pd(&A[648]);
    c48_12 = _mm_add_pd(c48_12, _mm_mul_pd(a48_12, b48));
    _mm_storeu_pd(&C[(l_n*88)+74], c48_12);
    __m128d c48_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a48_14 = _mm_loadu_pd(&A[650]);
    c48_14 = _mm_add_pd(c48_14, _mm_mul_pd(a48_14, b48));
    _mm_storeu_pd(&C[(l_n*88)+76], c48_14);
#endif
#else
    C[(l_n*88)+10] += A[636] * B[(l_n*88)+48];
    C[(l_n*88)+11] += A[637] * B[(l_n*88)+48];
    C[(l_n*88)+12] += A[638] * B[(l_n*88)+48];
    C[(l_n*88)+13] += A[639] * B[(l_n*88)+48];
    C[(l_n*88)+25] += A[640] * B[(l_n*88)+48];
    C[(l_n*88)+26] += A[641] * B[(l_n*88)+48];
    C[(l_n*88)+27] += A[642] * B[(l_n*88)+48];
    C[(l_n*88)+28] += A[643] * B[(l_n*88)+48];
    C[(l_n*88)+46] += A[644] * B[(l_n*88)+48];
    C[(l_n*88)+47] += A[645] * B[(l_n*88)+48];
    C[(l_n*88)+48] += A[646] * B[(l_n*88)+48];
    C[(l_n*88)+49] += A[647] * B[(l_n*88)+48];
    C[(l_n*88)+74] += A[648] * B[(l_n*88)+48];
    C[(l_n*88)+75] += A[649] * B[(l_n*88)+48];
    C[(l_n*88)+76] += A[650] * B[(l_n*88)+48];
    C[(l_n*88)+77] += A[651] * B[(l_n*88)+48];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b49 = _mm256_broadcast_sd(&B[(l_n*88)+49]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b49 = _mm_loaddup_pd(&B[(l_n*88)+49]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c49_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a49_0 = _mm256_loadu_pd(&A[652]);
    c49_0 = _mm256_add_pd(c49_0, _mm256_mul_pd(a49_0, b49));
    _mm256_storeu_pd(&C[(l_n*88)+10], c49_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c49_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a49_0 = _mm_loadu_pd(&A[652]);
    c49_0 = _mm_add_pd(c49_0, _mm_mul_pd(a49_0, b49));
    _mm_storeu_pd(&C[(l_n*88)+10], c49_0);
    __m128d c49_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a49_2 = _mm_loadu_pd(&A[654]);
    c49_2 = _mm_add_pd(c49_2, _mm_mul_pd(a49_2, b49));
    _mm_storeu_pd(&C[(l_n*88)+12], c49_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c49_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a49_4 = _mm256_loadu_pd(&A[656]);
    c49_4 = _mm256_add_pd(c49_4, _mm256_mul_pd(a49_4, b49));
    _mm256_storeu_pd(&C[(l_n*88)+25], c49_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c49_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a49_4 = _mm_loadu_pd(&A[656]);
    c49_4 = _mm_add_pd(c49_4, _mm_mul_pd(a49_4, b49));
    _mm_storeu_pd(&C[(l_n*88)+25], c49_4);
    __m128d c49_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a49_6 = _mm_loadu_pd(&A[658]);
    c49_6 = _mm_add_pd(c49_6, _mm_mul_pd(a49_6, b49));
    _mm_storeu_pd(&C[(l_n*88)+27], c49_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c49_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a49_8 = _mm256_loadu_pd(&A[660]);
    c49_8 = _mm256_add_pd(c49_8, _mm256_mul_pd(a49_8, b49));
    _mm256_storeu_pd(&C[(l_n*88)+46], c49_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c49_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a49_8 = _mm_loadu_pd(&A[660]);
    c49_8 = _mm_add_pd(c49_8, _mm_mul_pd(a49_8, b49));
    _mm_storeu_pd(&C[(l_n*88)+46], c49_8);
    __m128d c49_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a49_10 = _mm_loadu_pd(&A[662]);
    c49_10 = _mm_add_pd(c49_10, _mm_mul_pd(a49_10, b49));
    _mm_storeu_pd(&C[(l_n*88)+48], c49_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c49_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a49_12 = _mm256_loadu_pd(&A[664]);
    c49_12 = _mm256_add_pd(c49_12, _mm256_mul_pd(a49_12, b49));
    _mm256_storeu_pd(&C[(l_n*88)+74], c49_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c49_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a49_12 = _mm_loadu_pd(&A[664]);
    c49_12 = _mm_add_pd(c49_12, _mm_mul_pd(a49_12, b49));
    _mm_storeu_pd(&C[(l_n*88)+74], c49_12);
    __m128d c49_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a49_14 = _mm_loadu_pd(&A[666]);
    c49_14 = _mm_add_pd(c49_14, _mm_mul_pd(a49_14, b49));
    _mm_storeu_pd(&C[(l_n*88)+76], c49_14);
#endif
#else
    C[(l_n*88)+10] += A[652] * B[(l_n*88)+49];
    C[(l_n*88)+11] += A[653] * B[(l_n*88)+49];
    C[(l_n*88)+12] += A[654] * B[(l_n*88)+49];
    C[(l_n*88)+13] += A[655] * B[(l_n*88)+49];
    C[(l_n*88)+25] += A[656] * B[(l_n*88)+49];
    C[(l_n*88)+26] += A[657] * B[(l_n*88)+49];
    C[(l_n*88)+27] += A[658] * B[(l_n*88)+49];
    C[(l_n*88)+28] += A[659] * B[(l_n*88)+49];
    C[(l_n*88)+46] += A[660] * B[(l_n*88)+49];
    C[(l_n*88)+47] += A[661] * B[(l_n*88)+49];
    C[(l_n*88)+48] += A[662] * B[(l_n*88)+49];
    C[(l_n*88)+49] += A[663] * B[(l_n*88)+49];
    C[(l_n*88)+74] += A[664] * B[(l_n*88)+49];
    C[(l_n*88)+75] += A[665] * B[(l_n*88)+49];
    C[(l_n*88)+76] += A[666] * B[(l_n*88)+49];
    C[(l_n*88)+77] += A[667] * B[(l_n*88)+49];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b50 = _mm256_broadcast_sd(&B[(l_n*88)+50]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b50 = _mm_loaddup_pd(&B[(l_n*88)+50]);
#endif
    __m128d c50_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a50_0 = _mm_loadu_pd(&A[668]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_0 = _mm_add_pd(c50_0, _mm_mul_pd(a50_0, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_0 = _mm_add_pd(c50_0, _mm_mul_pd(a50_0, b50));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c50_0);
    __m128d c50_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a50_2 = _mm_load_sd(&A[670]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_2 = _mm_add_sd(c50_2, _mm_mul_sd(a50_2, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_2 = _mm_add_sd(c50_2, _mm_mul_sd(a50_2, b50));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c50_2);
    __m128d c50_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a50_3 = _mm_loadu_pd(&A[671]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_3 = _mm_add_pd(c50_3, _mm_mul_pd(a50_3, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_3 = _mm_add_pd(c50_3, _mm_mul_pd(a50_3, b50));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c50_3);
    __m128d c50_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a50_5 = _mm_load_sd(&A[673]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_5 = _mm_add_sd(c50_5, _mm_mul_sd(a50_5, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_5 = _mm_add_sd(c50_5, _mm_mul_sd(a50_5, b50));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c50_5);
    __m128d c50_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a50_6 = _mm_loadu_pd(&A[674]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_6 = _mm_add_pd(c50_6, _mm_mul_pd(a50_6, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_6 = _mm_add_pd(c50_6, _mm_mul_pd(a50_6, b50));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c50_6);
    __m128d c50_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a50_8 = _mm_load_sd(&A[676]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_8 = _mm_add_sd(c50_8, _mm_mul_sd(a50_8, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_8 = _mm_add_sd(c50_8, _mm_mul_sd(a50_8, b50));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c50_8);
    __m128d c50_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a50_9 = _mm_loadu_pd(&A[677]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_9 = _mm_add_pd(c50_9, _mm_mul_pd(a50_9, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_9 = _mm_add_pd(c50_9, _mm_mul_pd(a50_9, b50));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c50_9);
    __m128d c50_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a50_11 = _mm_load_sd(&A[679]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_11 = _mm_add_sd(c50_11, _mm_mul_sd(a50_11, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_11 = _mm_add_sd(c50_11, _mm_mul_sd(a50_11, b50));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c50_11);
    __m128d c50_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a50_12 = _mm_loadu_pd(&A[680]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_12 = _mm_add_pd(c50_12, _mm_mul_pd(a50_12, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_12 = _mm_add_pd(c50_12, _mm_mul_pd(a50_12, b50));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c50_12);
    __m128d c50_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a50_14 = _mm_load_sd(&A[682]);
#if defined(__SSE3__) && defined(__AVX__)
    c50_14 = _mm_add_sd(c50_14, _mm_mul_sd(a50_14, _mm256_castpd256_pd128(b50)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c50_14 = _mm_add_sd(c50_14, _mm_mul_sd(a50_14, b50));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c50_14);
#else
    C[(l_n*88)+4] += A[668] * B[(l_n*88)+50];
    C[(l_n*88)+5] += A[669] * B[(l_n*88)+50];
    C[(l_n*88)+6] += A[670] * B[(l_n*88)+50];
    C[(l_n*88)+14] += A[671] * B[(l_n*88)+50];
    C[(l_n*88)+15] += A[672] * B[(l_n*88)+50];
    C[(l_n*88)+16] += A[673] * B[(l_n*88)+50];
    C[(l_n*88)+29] += A[674] * B[(l_n*88)+50];
    C[(l_n*88)+30] += A[675] * B[(l_n*88)+50];
    C[(l_n*88)+31] += A[676] * B[(l_n*88)+50];
    C[(l_n*88)+50] += A[677] * B[(l_n*88)+50];
    C[(l_n*88)+51] += A[678] * B[(l_n*88)+50];
    C[(l_n*88)+52] += A[679] * B[(l_n*88)+50];
    C[(l_n*88)+78] += A[680] * B[(l_n*88)+50];
    C[(l_n*88)+79] += A[681] * B[(l_n*88)+50];
    C[(l_n*88)+80] += A[682] * B[(l_n*88)+50];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b51 = _mm256_broadcast_sd(&B[(l_n*88)+51]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b51 = _mm_loaddup_pd(&B[(l_n*88)+51]);
#endif
    __m128d c51_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a51_0 = _mm_loadu_pd(&A[683]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_0 = _mm_add_pd(c51_0, _mm_mul_pd(a51_0, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_0 = _mm_add_pd(c51_0, _mm_mul_pd(a51_0, b51));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c51_0);
    __m128d c51_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a51_2 = _mm_load_sd(&A[685]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_2 = _mm_add_sd(c51_2, _mm_mul_sd(a51_2, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_2 = _mm_add_sd(c51_2, _mm_mul_sd(a51_2, b51));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c51_2);
    __m128d c51_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a51_3 = _mm_loadu_pd(&A[686]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_3 = _mm_add_pd(c51_3, _mm_mul_pd(a51_3, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_3 = _mm_add_pd(c51_3, _mm_mul_pd(a51_3, b51));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c51_3);
    __m128d c51_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a51_5 = _mm_load_sd(&A[688]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_5 = _mm_add_sd(c51_5, _mm_mul_sd(a51_5, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_5 = _mm_add_sd(c51_5, _mm_mul_sd(a51_5, b51));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c51_5);
    __m128d c51_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a51_6 = _mm_loadu_pd(&A[689]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_6 = _mm_add_pd(c51_6, _mm_mul_pd(a51_6, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_6 = _mm_add_pd(c51_6, _mm_mul_pd(a51_6, b51));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c51_6);
    __m128d c51_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a51_8 = _mm_load_sd(&A[691]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_8 = _mm_add_sd(c51_8, _mm_mul_sd(a51_8, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_8 = _mm_add_sd(c51_8, _mm_mul_sd(a51_8, b51));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c51_8);
    __m128d c51_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a51_9 = _mm_loadu_pd(&A[692]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_9 = _mm_add_pd(c51_9, _mm_mul_pd(a51_9, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_9 = _mm_add_pd(c51_9, _mm_mul_pd(a51_9, b51));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c51_9);
    __m128d c51_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a51_11 = _mm_load_sd(&A[694]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_11 = _mm_add_sd(c51_11, _mm_mul_sd(a51_11, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_11 = _mm_add_sd(c51_11, _mm_mul_sd(a51_11, b51));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c51_11);
    __m128d c51_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a51_12 = _mm_loadu_pd(&A[695]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_12 = _mm_add_pd(c51_12, _mm_mul_pd(a51_12, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_12 = _mm_add_pd(c51_12, _mm_mul_pd(a51_12, b51));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c51_12);
    __m128d c51_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a51_14 = _mm_load_sd(&A[697]);
#if defined(__SSE3__) && defined(__AVX__)
    c51_14 = _mm_add_sd(c51_14, _mm_mul_sd(a51_14, _mm256_castpd256_pd128(b51)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c51_14 = _mm_add_sd(c51_14, _mm_mul_sd(a51_14, b51));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c51_14);
#else
    C[(l_n*88)+4] += A[683] * B[(l_n*88)+51];
    C[(l_n*88)+5] += A[684] * B[(l_n*88)+51];
    C[(l_n*88)+6] += A[685] * B[(l_n*88)+51];
    C[(l_n*88)+14] += A[686] * B[(l_n*88)+51];
    C[(l_n*88)+15] += A[687] * B[(l_n*88)+51];
    C[(l_n*88)+16] += A[688] * B[(l_n*88)+51];
    C[(l_n*88)+29] += A[689] * B[(l_n*88)+51];
    C[(l_n*88)+30] += A[690] * B[(l_n*88)+51];
    C[(l_n*88)+31] += A[691] * B[(l_n*88)+51];
    C[(l_n*88)+50] += A[692] * B[(l_n*88)+51];
    C[(l_n*88)+51] += A[693] * B[(l_n*88)+51];
    C[(l_n*88)+52] += A[694] * B[(l_n*88)+51];
    C[(l_n*88)+78] += A[695] * B[(l_n*88)+51];
    C[(l_n*88)+79] += A[696] * B[(l_n*88)+51];
    C[(l_n*88)+80] += A[697] * B[(l_n*88)+51];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b52 = _mm256_broadcast_sd(&B[(l_n*88)+52]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b52 = _mm_loaddup_pd(&B[(l_n*88)+52]);
#endif
    __m128d c52_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a52_0 = _mm_loadu_pd(&A[698]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_0 = _mm_add_pd(c52_0, _mm_mul_pd(a52_0, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_0 = _mm_add_pd(c52_0, _mm_mul_pd(a52_0, b52));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c52_0);
    __m128d c52_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a52_2 = _mm_load_sd(&A[700]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_2 = _mm_add_sd(c52_2, _mm_mul_sd(a52_2, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_2 = _mm_add_sd(c52_2, _mm_mul_sd(a52_2, b52));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c52_2);
    __m128d c52_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a52_3 = _mm_loadu_pd(&A[701]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_3 = _mm_add_pd(c52_3, _mm_mul_pd(a52_3, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_3 = _mm_add_pd(c52_3, _mm_mul_pd(a52_3, b52));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c52_3);
    __m128d c52_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a52_5 = _mm_load_sd(&A[703]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_5 = _mm_add_sd(c52_5, _mm_mul_sd(a52_5, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_5 = _mm_add_sd(c52_5, _mm_mul_sd(a52_5, b52));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c52_5);
    __m128d c52_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a52_6 = _mm_loadu_pd(&A[704]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_6 = _mm_add_pd(c52_6, _mm_mul_pd(a52_6, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_6 = _mm_add_pd(c52_6, _mm_mul_pd(a52_6, b52));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c52_6);
    __m128d c52_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a52_8 = _mm_load_sd(&A[706]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_8 = _mm_add_sd(c52_8, _mm_mul_sd(a52_8, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_8 = _mm_add_sd(c52_8, _mm_mul_sd(a52_8, b52));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c52_8);
    __m128d c52_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a52_9 = _mm_loadu_pd(&A[707]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_9 = _mm_add_pd(c52_9, _mm_mul_pd(a52_9, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_9 = _mm_add_pd(c52_9, _mm_mul_pd(a52_9, b52));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c52_9);
    __m128d c52_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a52_11 = _mm_load_sd(&A[709]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_11 = _mm_add_sd(c52_11, _mm_mul_sd(a52_11, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_11 = _mm_add_sd(c52_11, _mm_mul_sd(a52_11, b52));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c52_11);
    __m128d c52_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a52_12 = _mm_loadu_pd(&A[710]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_12 = _mm_add_pd(c52_12, _mm_mul_pd(a52_12, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_12 = _mm_add_pd(c52_12, _mm_mul_pd(a52_12, b52));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c52_12);
    __m128d c52_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a52_14 = _mm_load_sd(&A[712]);
#if defined(__SSE3__) && defined(__AVX__)
    c52_14 = _mm_add_sd(c52_14, _mm_mul_sd(a52_14, _mm256_castpd256_pd128(b52)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c52_14 = _mm_add_sd(c52_14, _mm_mul_sd(a52_14, b52));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c52_14);
#else
    C[(l_n*88)+4] += A[698] * B[(l_n*88)+52];
    C[(l_n*88)+5] += A[699] * B[(l_n*88)+52];
    C[(l_n*88)+6] += A[700] * B[(l_n*88)+52];
    C[(l_n*88)+14] += A[701] * B[(l_n*88)+52];
    C[(l_n*88)+15] += A[702] * B[(l_n*88)+52];
    C[(l_n*88)+16] += A[703] * B[(l_n*88)+52];
    C[(l_n*88)+29] += A[704] * B[(l_n*88)+52];
    C[(l_n*88)+30] += A[705] * B[(l_n*88)+52];
    C[(l_n*88)+31] += A[706] * B[(l_n*88)+52];
    C[(l_n*88)+50] += A[707] * B[(l_n*88)+52];
    C[(l_n*88)+51] += A[708] * B[(l_n*88)+52];
    C[(l_n*88)+52] += A[709] * B[(l_n*88)+52];
    C[(l_n*88)+78] += A[710] * B[(l_n*88)+52];
    C[(l_n*88)+79] += A[711] * B[(l_n*88)+52];
    C[(l_n*88)+80] += A[712] * B[(l_n*88)+52];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b53 = _mm256_broadcast_sd(&B[(l_n*88)+53]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b53 = _mm_loaddup_pd(&B[(l_n*88)+53]);
#endif
    __m128d c53_0 = _mm_loadu_pd(&C[(l_n*88)+1]);
    __m128d a53_0 = _mm_loadu_pd(&A[713]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_0 = _mm_add_pd(c53_0, _mm_mul_pd(a53_0, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_0 = _mm_add_pd(c53_0, _mm_mul_pd(a53_0, b53));
#endif
    _mm_storeu_pd(&C[(l_n*88)+1], c53_0);
    __m128d c53_2 = _mm_loadu_pd(&C[(l_n*88)+7]);
    __m128d a53_2 = _mm_loadu_pd(&A[715]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_2 = _mm_add_pd(c53_2, _mm_mul_pd(a53_2, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_2 = _mm_add_pd(c53_2, _mm_mul_pd(a53_2, b53));
#endif
    _mm_storeu_pd(&C[(l_n*88)+7], c53_2);
    __m128d c53_4 = _mm_loadu_pd(&C[(l_n*88)+17]);
    __m128d a53_4 = _mm_loadu_pd(&A[717]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_4 = _mm_add_pd(c53_4, _mm_mul_pd(a53_4, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_4 = _mm_add_pd(c53_4, _mm_mul_pd(a53_4, b53));
#endif
    _mm_storeu_pd(&C[(l_n*88)+17], c53_4);
    __m128d c53_6 = _mm_loadu_pd(&C[(l_n*88)+32]);
    __m128d a53_6 = _mm_loadu_pd(&A[719]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_6 = _mm_add_pd(c53_6, _mm_mul_pd(a53_6, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_6 = _mm_add_pd(c53_6, _mm_mul_pd(a53_6, b53));
#endif
    _mm_storeu_pd(&C[(l_n*88)+32], c53_6);
    __m128d c53_8 = _mm_loadu_pd(&C[(l_n*88)+53]);
    __m128d a53_8 = _mm_loadu_pd(&A[721]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_8 = _mm_add_pd(c53_8, _mm_mul_pd(a53_8, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_8 = _mm_add_pd(c53_8, _mm_mul_pd(a53_8, b53));
#endif
    _mm_storeu_pd(&C[(l_n*88)+53], c53_8);
    __m128d c53_10 = _mm_loadu_pd(&C[(l_n*88)+81]);
    __m128d a53_10 = _mm_loadu_pd(&A[723]);
#if defined(__SSE3__) && defined(__AVX__)
    c53_10 = _mm_add_pd(c53_10, _mm_mul_pd(a53_10, _mm256_castpd256_pd128(b53)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c53_10 = _mm_add_pd(c53_10, _mm_mul_pd(a53_10, b53));
#endif
    _mm_storeu_pd(&C[(l_n*88)+81], c53_10);
#else
    C[(l_n*88)+1] += A[713] * B[(l_n*88)+53];
    C[(l_n*88)+2] += A[714] * B[(l_n*88)+53];
    C[(l_n*88)+7] += A[715] * B[(l_n*88)+53];
    C[(l_n*88)+8] += A[716] * B[(l_n*88)+53];
    C[(l_n*88)+17] += A[717] * B[(l_n*88)+53];
    C[(l_n*88)+18] += A[718] * B[(l_n*88)+53];
    C[(l_n*88)+32] += A[719] * B[(l_n*88)+53];
    C[(l_n*88)+33] += A[720] * B[(l_n*88)+53];
    C[(l_n*88)+53] += A[721] * B[(l_n*88)+53];
    C[(l_n*88)+54] += A[722] * B[(l_n*88)+53];
    C[(l_n*88)+81] += A[723] * B[(l_n*88)+53];
    C[(l_n*88)+82] += A[724] * B[(l_n*88)+53];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b54 = _mm256_broadcast_sd(&B[(l_n*88)+54]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b54 = _mm_loaddup_pd(&B[(l_n*88)+54]);
#endif
    __m128d c54_0 = _mm_loadu_pd(&C[(l_n*88)+1]);
    __m128d a54_0 = _mm_loadu_pd(&A[725]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_0 = _mm_add_pd(c54_0, _mm_mul_pd(a54_0, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_0 = _mm_add_pd(c54_0, _mm_mul_pd(a54_0, b54));
#endif
    _mm_storeu_pd(&C[(l_n*88)+1], c54_0);
    __m128d c54_2 = _mm_loadu_pd(&C[(l_n*88)+7]);
    __m128d a54_2 = _mm_loadu_pd(&A[727]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_2 = _mm_add_pd(c54_2, _mm_mul_pd(a54_2, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_2 = _mm_add_pd(c54_2, _mm_mul_pd(a54_2, b54));
#endif
    _mm_storeu_pd(&C[(l_n*88)+7], c54_2);
    __m128d c54_4 = _mm_loadu_pd(&C[(l_n*88)+17]);
    __m128d a54_4 = _mm_loadu_pd(&A[729]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_4 = _mm_add_pd(c54_4, _mm_mul_pd(a54_4, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_4 = _mm_add_pd(c54_4, _mm_mul_pd(a54_4, b54));
#endif
    _mm_storeu_pd(&C[(l_n*88)+17], c54_4);
    __m128d c54_6 = _mm_loadu_pd(&C[(l_n*88)+32]);
    __m128d a54_6 = _mm_loadu_pd(&A[731]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_6 = _mm_add_pd(c54_6, _mm_mul_pd(a54_6, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_6 = _mm_add_pd(c54_6, _mm_mul_pd(a54_6, b54));
#endif
    _mm_storeu_pd(&C[(l_n*88)+32], c54_6);
    __m128d c54_8 = _mm_loadu_pd(&C[(l_n*88)+53]);
    __m128d a54_8 = _mm_loadu_pd(&A[733]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_8 = _mm_add_pd(c54_8, _mm_mul_pd(a54_8, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_8 = _mm_add_pd(c54_8, _mm_mul_pd(a54_8, b54));
#endif
    _mm_storeu_pd(&C[(l_n*88)+53], c54_8);
    __m128d c54_10 = _mm_loadu_pd(&C[(l_n*88)+81]);
    __m128d a54_10 = _mm_loadu_pd(&A[735]);
#if defined(__SSE3__) && defined(__AVX__)
    c54_10 = _mm_add_pd(c54_10, _mm_mul_pd(a54_10, _mm256_castpd256_pd128(b54)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c54_10 = _mm_add_pd(c54_10, _mm_mul_pd(a54_10, b54));
#endif
    _mm_storeu_pd(&C[(l_n*88)+81], c54_10);
#else
    C[(l_n*88)+1] += A[725] * B[(l_n*88)+54];
    C[(l_n*88)+2] += A[726] * B[(l_n*88)+54];
    C[(l_n*88)+7] += A[727] * B[(l_n*88)+54];
    C[(l_n*88)+8] += A[728] * B[(l_n*88)+54];
    C[(l_n*88)+17] += A[729] * B[(l_n*88)+54];
    C[(l_n*88)+18] += A[730] * B[(l_n*88)+54];
    C[(l_n*88)+32] += A[731] * B[(l_n*88)+54];
    C[(l_n*88)+33] += A[732] * B[(l_n*88)+54];
    C[(l_n*88)+53] += A[733] * B[(l_n*88)+54];
    C[(l_n*88)+54] += A[734] * B[(l_n*88)+54];
    C[(l_n*88)+81] += A[735] * B[(l_n*88)+54];
    C[(l_n*88)+82] += A[736] * B[(l_n*88)+54];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b55 = _mm256_broadcast_sd(&B[(l_n*88)+55]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b55 = _mm_loaddup_pd(&B[(l_n*88)+55]);
#endif
    __m128d c55_0 = _mm_load_sd(&C[(l_n*88)+0]);
    __m128d a55_0 = _mm_load_sd(&A[737]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_0 = _mm_add_sd(c55_0, _mm_mul_sd(a55_0, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_0 = _mm_add_sd(c55_0, _mm_mul_sd(a55_0, b55));
#endif
    _mm_store_sd(&C[(l_n*88)+0], c55_0);
    __m128d c55_1 = _mm_load_sd(&C[(l_n*88)+3]);
    __m128d a55_1 = _mm_load_sd(&A[738]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_1 = _mm_add_sd(c55_1, _mm_mul_sd(a55_1, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_1 = _mm_add_sd(c55_1, _mm_mul_sd(a55_1, b55));
#endif
    _mm_store_sd(&C[(l_n*88)+3], c55_1);
    __m128d c55_2 = _mm_load_sd(&C[(l_n*88)+9]);
    __m128d a55_2 = _mm_load_sd(&A[739]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_2 = _mm_add_sd(c55_2, _mm_mul_sd(a55_2, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_2 = _mm_add_sd(c55_2, _mm_mul_sd(a55_2, b55));
#endif
    _mm_store_sd(&C[(l_n*88)+9], c55_2);
    __m128d c55_3 = _mm_load_sd(&C[(l_n*88)+19]);
    __m128d a55_3 = _mm_load_sd(&A[740]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_3 = _mm_add_sd(c55_3, _mm_mul_sd(a55_3, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_3 = _mm_add_sd(c55_3, _mm_mul_sd(a55_3, b55));
#endif
    _mm_store_sd(&C[(l_n*88)+19], c55_3);
    __m128d c55_4 = _mm_load_sd(&C[(l_n*88)+34]);
    __m128d a55_4 = _mm_load_sd(&A[741]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_4 = _mm_add_sd(c55_4, _mm_mul_sd(a55_4, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_4 = _mm_add_sd(c55_4, _mm_mul_sd(a55_4, b55));
#endif
    _mm_store_sd(&C[(l_n*88)+34], c55_4);
    __m128d c55_5 = _mm_load_sd(&C[(l_n*88)+55]);
    __m128d a55_5 = _mm_load_sd(&A[742]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_5 = _mm_add_sd(c55_5, _mm_mul_sd(a55_5, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_5 = _mm_add_sd(c55_5, _mm_mul_sd(a55_5, b55));
#endif
    _mm_store_sd(&C[(l_n*88)+55], c55_5);
    __m128d c55_6 = _mm_load_sd(&C[(l_n*88)+83]);
    __m128d a55_6 = _mm_load_sd(&A[743]);
#if defined(__SSE3__) && defined(__AVX__)
    c55_6 = _mm_add_sd(c55_6, _mm_mul_sd(a55_6, _mm256_castpd256_pd128(b55)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c55_6 = _mm_add_sd(c55_6, _mm_mul_sd(a55_6, b55));
#endif
    _mm_store_sd(&C[(l_n*88)+83], c55_6);
#else
    C[(l_n*88)+0] += A[737] * B[(l_n*88)+55];
    C[(l_n*88)+3] += A[738] * B[(l_n*88)+55];
    C[(l_n*88)+9] += A[739] * B[(l_n*88)+55];
    C[(l_n*88)+19] += A[740] * B[(l_n*88)+55];
    C[(l_n*88)+34] += A[741] * B[(l_n*88)+55];
    C[(l_n*88)+55] += A[742] * B[(l_n*88)+55];
    C[(l_n*88)+83] += A[743] * B[(l_n*88)+55];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b56 = _mm256_broadcast_sd(&B[(l_n*88)+56]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b56 = _mm_loaddup_pd(&B[(l_n*88)+56]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c56_0 = _mm256_loadu_pd(&C[(l_n*88)+56]);
    __m256d a56_0 = _mm256_loadu_pd(&A[744]);
    c56_0 = _mm256_add_pd(c56_0, _mm256_mul_pd(a56_0, b56));
    _mm256_storeu_pd(&C[(l_n*88)+56], c56_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c56_0 = _mm_loadu_pd(&C[(l_n*88)+56]);
    __m128d a56_0 = _mm_loadu_pd(&A[744]);
    c56_0 = _mm_add_pd(c56_0, _mm_mul_pd(a56_0, b56));
    _mm_storeu_pd(&C[(l_n*88)+56], c56_0);
    __m128d c56_2 = _mm_loadu_pd(&C[(l_n*88)+58]);
    __m128d a56_2 = _mm_loadu_pd(&A[746]);
    c56_2 = _mm_add_pd(c56_2, _mm_mul_pd(a56_2, b56));
    _mm_storeu_pd(&C[(l_n*88)+58], c56_2);
#endif
    __m128d c56_4 = _mm_loadu_pd(&C[(l_n*88)+60]);
    __m128d a56_4 = _mm_loadu_pd(&A[748]);
#if defined(__SSE3__) && defined(__AVX__)
    c56_4 = _mm_add_pd(c56_4, _mm_mul_pd(a56_4, _mm256_castpd256_pd128(b56)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c56_4 = _mm_add_pd(c56_4, _mm_mul_pd(a56_4, b56));
#endif
    _mm_storeu_pd(&C[(l_n*88)+60], c56_4);
    __m128d c56_6 = _mm_load_sd(&C[(l_n*88)+62]);
    __m128d a56_6 = _mm_load_sd(&A[750]);
#if defined(__SSE3__) && defined(__AVX__)
    c56_6 = _mm_add_sd(c56_6, _mm_mul_sd(a56_6, _mm256_castpd256_pd128(b56)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c56_6 = _mm_add_sd(c56_6, _mm_mul_sd(a56_6, b56));
#endif
    _mm_store_sd(&C[(l_n*88)+62], c56_6);
#else
    C[(l_n*88)+56] += A[744] * B[(l_n*88)+56];
    C[(l_n*88)+57] += A[745] * B[(l_n*88)+56];
    C[(l_n*88)+58] += A[746] * B[(l_n*88)+56];
    C[(l_n*88)+59] += A[747] * B[(l_n*88)+56];
    C[(l_n*88)+60] += A[748] * B[(l_n*88)+56];
    C[(l_n*88)+61] += A[749] * B[(l_n*88)+56];
    C[(l_n*88)+62] += A[750] * B[(l_n*88)+56];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b57 = _mm256_broadcast_sd(&B[(l_n*88)+57]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b57 = _mm_loaddup_pd(&B[(l_n*88)+57]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c57_0 = _mm256_loadu_pd(&C[(l_n*88)+56]);
    __m256d a57_0 = _mm256_loadu_pd(&A[751]);
    c57_0 = _mm256_add_pd(c57_0, _mm256_mul_pd(a57_0, b57));
    _mm256_storeu_pd(&C[(l_n*88)+56], c57_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c57_0 = _mm_loadu_pd(&C[(l_n*88)+56]);
    __m128d a57_0 = _mm_loadu_pd(&A[751]);
    c57_0 = _mm_add_pd(c57_0, _mm_mul_pd(a57_0, b57));
    _mm_storeu_pd(&C[(l_n*88)+56], c57_0);
    __m128d c57_2 = _mm_loadu_pd(&C[(l_n*88)+58]);
    __m128d a57_2 = _mm_loadu_pd(&A[753]);
    c57_2 = _mm_add_pd(c57_2, _mm_mul_pd(a57_2, b57));
    _mm_storeu_pd(&C[(l_n*88)+58], c57_2);
#endif
    __m128d c57_4 = _mm_loadu_pd(&C[(l_n*88)+60]);
    __m128d a57_4 = _mm_loadu_pd(&A[755]);
#if defined(__SSE3__) && defined(__AVX__)
    c57_4 = _mm_add_pd(c57_4, _mm_mul_pd(a57_4, _mm256_castpd256_pd128(b57)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c57_4 = _mm_add_pd(c57_4, _mm_mul_pd(a57_4, b57));
#endif
    _mm_storeu_pd(&C[(l_n*88)+60], c57_4);
    __m128d c57_6 = _mm_load_sd(&C[(l_n*88)+62]);
    __m128d a57_6 = _mm_load_sd(&A[757]);
#if defined(__SSE3__) && defined(__AVX__)
    c57_6 = _mm_add_sd(c57_6, _mm_mul_sd(a57_6, _mm256_castpd256_pd128(b57)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c57_6 = _mm_add_sd(c57_6, _mm_mul_sd(a57_6, b57));
#endif
    _mm_store_sd(&C[(l_n*88)+62], c57_6);
#else
    C[(l_n*88)+56] += A[751] * B[(l_n*88)+57];
    C[(l_n*88)+57] += A[752] * B[(l_n*88)+57];
    C[(l_n*88)+58] += A[753] * B[(l_n*88)+57];
    C[(l_n*88)+59] += A[754] * B[(l_n*88)+57];
    C[(l_n*88)+60] += A[755] * B[(l_n*88)+57];
    C[(l_n*88)+61] += A[756] * B[(l_n*88)+57];
    C[(l_n*88)+62] += A[757] * B[(l_n*88)+57];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b58 = _mm256_broadcast_sd(&B[(l_n*88)+58]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b58 = _mm_loaddup_pd(&B[(l_n*88)+58]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c58_0 = _mm256_loadu_pd(&C[(l_n*88)+56]);
    __m256d a58_0 = _mm256_loadu_pd(&A[758]);
    c58_0 = _mm256_add_pd(c58_0, _mm256_mul_pd(a58_0, b58));
    _mm256_storeu_pd(&C[(l_n*88)+56], c58_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c58_0 = _mm_loadu_pd(&C[(l_n*88)+56]);
    __m128d a58_0 = _mm_loadu_pd(&A[758]);
    c58_0 = _mm_add_pd(c58_0, _mm_mul_pd(a58_0, b58));
    _mm_storeu_pd(&C[(l_n*88)+56], c58_0);
    __m128d c58_2 = _mm_loadu_pd(&C[(l_n*88)+58]);
    __m128d a58_2 = _mm_loadu_pd(&A[760]);
    c58_2 = _mm_add_pd(c58_2, _mm_mul_pd(a58_2, b58));
    _mm_storeu_pd(&C[(l_n*88)+58], c58_2);
#endif
    __m128d c58_4 = _mm_loadu_pd(&C[(l_n*88)+60]);
    __m128d a58_4 = _mm_loadu_pd(&A[762]);
#if defined(__SSE3__) && defined(__AVX__)
    c58_4 = _mm_add_pd(c58_4, _mm_mul_pd(a58_4, _mm256_castpd256_pd128(b58)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c58_4 = _mm_add_pd(c58_4, _mm_mul_pd(a58_4, b58));
#endif
    _mm_storeu_pd(&C[(l_n*88)+60], c58_4);
    __m128d c58_6 = _mm_load_sd(&C[(l_n*88)+62]);
    __m128d a58_6 = _mm_load_sd(&A[764]);
#if defined(__SSE3__) && defined(__AVX__)
    c58_6 = _mm_add_sd(c58_6, _mm_mul_sd(a58_6, _mm256_castpd256_pd128(b58)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c58_6 = _mm_add_sd(c58_6, _mm_mul_sd(a58_6, b58));
#endif
    _mm_store_sd(&C[(l_n*88)+62], c58_6);
#else
    C[(l_n*88)+56] += A[758] * B[(l_n*88)+58];
    C[(l_n*88)+57] += A[759] * B[(l_n*88)+58];
    C[(l_n*88)+58] += A[760] * B[(l_n*88)+58];
    C[(l_n*88)+59] += A[761] * B[(l_n*88)+58];
    C[(l_n*88)+60] += A[762] * B[(l_n*88)+58];
    C[(l_n*88)+61] += A[763] * B[(l_n*88)+58];
    C[(l_n*88)+62] += A[764] * B[(l_n*88)+58];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b59 = _mm256_broadcast_sd(&B[(l_n*88)+59]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b59 = _mm_loaddup_pd(&B[(l_n*88)+59]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c59_0 = _mm256_loadu_pd(&C[(l_n*88)+56]);
    __m256d a59_0 = _mm256_loadu_pd(&A[765]);
    c59_0 = _mm256_add_pd(c59_0, _mm256_mul_pd(a59_0, b59));
    _mm256_storeu_pd(&C[(l_n*88)+56], c59_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c59_0 = _mm_loadu_pd(&C[(l_n*88)+56]);
    __m128d a59_0 = _mm_loadu_pd(&A[765]);
    c59_0 = _mm_add_pd(c59_0, _mm_mul_pd(a59_0, b59));
    _mm_storeu_pd(&C[(l_n*88)+56], c59_0);
    __m128d c59_2 = _mm_loadu_pd(&C[(l_n*88)+58]);
    __m128d a59_2 = _mm_loadu_pd(&A[767]);
    c59_2 = _mm_add_pd(c59_2, _mm_mul_pd(a59_2, b59));
    _mm_storeu_pd(&C[(l_n*88)+58], c59_2);
#endif
    __m128d c59_4 = _mm_loadu_pd(&C[(l_n*88)+60]);
    __m128d a59_4 = _mm_loadu_pd(&A[769]);
#if defined(__SSE3__) && defined(__AVX__)
    c59_4 = _mm_add_pd(c59_4, _mm_mul_pd(a59_4, _mm256_castpd256_pd128(b59)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c59_4 = _mm_add_pd(c59_4, _mm_mul_pd(a59_4, b59));
#endif
    _mm_storeu_pd(&C[(l_n*88)+60], c59_4);
    __m128d c59_6 = _mm_load_sd(&C[(l_n*88)+62]);
    __m128d a59_6 = _mm_load_sd(&A[771]);
#if defined(__SSE3__) && defined(__AVX__)
    c59_6 = _mm_add_sd(c59_6, _mm_mul_sd(a59_6, _mm256_castpd256_pd128(b59)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c59_6 = _mm_add_sd(c59_6, _mm_mul_sd(a59_6, b59));
#endif
    _mm_store_sd(&C[(l_n*88)+62], c59_6);
#else
    C[(l_n*88)+56] += A[765] * B[(l_n*88)+59];
    C[(l_n*88)+57] += A[766] * B[(l_n*88)+59];
    C[(l_n*88)+58] += A[767] * B[(l_n*88)+59];
    C[(l_n*88)+59] += A[768] * B[(l_n*88)+59];
    C[(l_n*88)+60] += A[769] * B[(l_n*88)+59];
    C[(l_n*88)+61] += A[770] * B[(l_n*88)+59];
    C[(l_n*88)+62] += A[771] * B[(l_n*88)+59];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b60 = _mm256_broadcast_sd(&B[(l_n*88)+60]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b60 = _mm_loaddup_pd(&B[(l_n*88)+60]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c60_0 = _mm256_loadu_pd(&C[(l_n*88)+56]);
    __m256d a60_0 = _mm256_loadu_pd(&A[772]);
    c60_0 = _mm256_add_pd(c60_0, _mm256_mul_pd(a60_0, b60));
    _mm256_storeu_pd(&C[(l_n*88)+56], c60_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c60_0 = _mm_loadu_pd(&C[(l_n*88)+56]);
    __m128d a60_0 = _mm_loadu_pd(&A[772]);
    c60_0 = _mm_add_pd(c60_0, _mm_mul_pd(a60_0, b60));
    _mm_storeu_pd(&C[(l_n*88)+56], c60_0);
    __m128d c60_2 = _mm_loadu_pd(&C[(l_n*88)+58]);
    __m128d a60_2 = _mm_loadu_pd(&A[774]);
    c60_2 = _mm_add_pd(c60_2, _mm_mul_pd(a60_2, b60));
    _mm_storeu_pd(&C[(l_n*88)+58], c60_2);
#endif
    __m128d c60_4 = _mm_loadu_pd(&C[(l_n*88)+60]);
    __m128d a60_4 = _mm_loadu_pd(&A[776]);
#if defined(__SSE3__) && defined(__AVX__)
    c60_4 = _mm_add_pd(c60_4, _mm_mul_pd(a60_4, _mm256_castpd256_pd128(b60)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c60_4 = _mm_add_pd(c60_4, _mm_mul_pd(a60_4, b60));
#endif
    _mm_storeu_pd(&C[(l_n*88)+60], c60_4);
    __m128d c60_6 = _mm_load_sd(&C[(l_n*88)+62]);
    __m128d a60_6 = _mm_load_sd(&A[778]);
#if defined(__SSE3__) && defined(__AVX__)
    c60_6 = _mm_add_sd(c60_6, _mm_mul_sd(a60_6, _mm256_castpd256_pd128(b60)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c60_6 = _mm_add_sd(c60_6, _mm_mul_sd(a60_6, b60));
#endif
    _mm_store_sd(&C[(l_n*88)+62], c60_6);
#else
    C[(l_n*88)+56] += A[772] * B[(l_n*88)+60];
    C[(l_n*88)+57] += A[773] * B[(l_n*88)+60];
    C[(l_n*88)+58] += A[774] * B[(l_n*88)+60];
    C[(l_n*88)+59] += A[775] * B[(l_n*88)+60];
    C[(l_n*88)+60] += A[776] * B[(l_n*88)+60];
    C[(l_n*88)+61] += A[777] * B[(l_n*88)+60];
    C[(l_n*88)+62] += A[778] * B[(l_n*88)+60];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b61 = _mm256_broadcast_sd(&B[(l_n*88)+61]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b61 = _mm_loaddup_pd(&B[(l_n*88)+61]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c61_0 = _mm256_loadu_pd(&C[(l_n*88)+56]);
    __m256d a61_0 = _mm256_loadu_pd(&A[779]);
    c61_0 = _mm256_add_pd(c61_0, _mm256_mul_pd(a61_0, b61));
    _mm256_storeu_pd(&C[(l_n*88)+56], c61_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c61_0 = _mm_loadu_pd(&C[(l_n*88)+56]);
    __m128d a61_0 = _mm_loadu_pd(&A[779]);
    c61_0 = _mm_add_pd(c61_0, _mm_mul_pd(a61_0, b61));
    _mm_storeu_pd(&C[(l_n*88)+56], c61_0);
    __m128d c61_2 = _mm_loadu_pd(&C[(l_n*88)+58]);
    __m128d a61_2 = _mm_loadu_pd(&A[781]);
    c61_2 = _mm_add_pd(c61_2, _mm_mul_pd(a61_2, b61));
    _mm_storeu_pd(&C[(l_n*88)+58], c61_2);
#endif
    __m128d c61_4 = _mm_loadu_pd(&C[(l_n*88)+60]);
    __m128d a61_4 = _mm_loadu_pd(&A[783]);
#if defined(__SSE3__) && defined(__AVX__)
    c61_4 = _mm_add_pd(c61_4, _mm_mul_pd(a61_4, _mm256_castpd256_pd128(b61)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c61_4 = _mm_add_pd(c61_4, _mm_mul_pd(a61_4, b61));
#endif
    _mm_storeu_pd(&C[(l_n*88)+60], c61_4);
    __m128d c61_6 = _mm_load_sd(&C[(l_n*88)+62]);
    __m128d a61_6 = _mm_load_sd(&A[785]);
#if defined(__SSE3__) && defined(__AVX__)
    c61_6 = _mm_add_sd(c61_6, _mm_mul_sd(a61_6, _mm256_castpd256_pd128(b61)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c61_6 = _mm_add_sd(c61_6, _mm_mul_sd(a61_6, b61));
#endif
    _mm_store_sd(&C[(l_n*88)+62], c61_6);
#else
    C[(l_n*88)+56] += A[779] * B[(l_n*88)+61];
    C[(l_n*88)+57] += A[780] * B[(l_n*88)+61];
    C[(l_n*88)+58] += A[781] * B[(l_n*88)+61];
    C[(l_n*88)+59] += A[782] * B[(l_n*88)+61];
    C[(l_n*88)+60] += A[783] * B[(l_n*88)+61];
    C[(l_n*88)+61] += A[784] * B[(l_n*88)+61];
    C[(l_n*88)+62] += A[785] * B[(l_n*88)+61];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b62 = _mm256_broadcast_sd(&B[(l_n*88)+62]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b62 = _mm_loaddup_pd(&B[(l_n*88)+62]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c62_0 = _mm256_loadu_pd(&C[(l_n*88)+56]);
    __m256d a62_0 = _mm256_loadu_pd(&A[786]);
    c62_0 = _mm256_add_pd(c62_0, _mm256_mul_pd(a62_0, b62));
    _mm256_storeu_pd(&C[(l_n*88)+56], c62_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c62_0 = _mm_loadu_pd(&C[(l_n*88)+56]);
    __m128d a62_0 = _mm_loadu_pd(&A[786]);
    c62_0 = _mm_add_pd(c62_0, _mm_mul_pd(a62_0, b62));
    _mm_storeu_pd(&C[(l_n*88)+56], c62_0);
    __m128d c62_2 = _mm_loadu_pd(&C[(l_n*88)+58]);
    __m128d a62_2 = _mm_loadu_pd(&A[788]);
    c62_2 = _mm_add_pd(c62_2, _mm_mul_pd(a62_2, b62));
    _mm_storeu_pd(&C[(l_n*88)+58], c62_2);
#endif
    __m128d c62_4 = _mm_loadu_pd(&C[(l_n*88)+60]);
    __m128d a62_4 = _mm_loadu_pd(&A[790]);
#if defined(__SSE3__) && defined(__AVX__)
    c62_4 = _mm_add_pd(c62_4, _mm_mul_pd(a62_4, _mm256_castpd256_pd128(b62)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c62_4 = _mm_add_pd(c62_4, _mm_mul_pd(a62_4, b62));
#endif
    _mm_storeu_pd(&C[(l_n*88)+60], c62_4);
    __m128d c62_6 = _mm_load_sd(&C[(l_n*88)+62]);
    __m128d a62_6 = _mm_load_sd(&A[792]);
#if defined(__SSE3__) && defined(__AVX__)
    c62_6 = _mm_add_sd(c62_6, _mm_mul_sd(a62_6, _mm256_castpd256_pd128(b62)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c62_6 = _mm_add_sd(c62_6, _mm_mul_sd(a62_6, b62));
#endif
    _mm_store_sd(&C[(l_n*88)+62], c62_6);
#else
    C[(l_n*88)+56] += A[786] * B[(l_n*88)+62];
    C[(l_n*88)+57] += A[787] * B[(l_n*88)+62];
    C[(l_n*88)+58] += A[788] * B[(l_n*88)+62];
    C[(l_n*88)+59] += A[789] * B[(l_n*88)+62];
    C[(l_n*88)+60] += A[790] * B[(l_n*88)+62];
    C[(l_n*88)+61] += A[791] * B[(l_n*88)+62];
    C[(l_n*88)+62] += A[792] * B[(l_n*88)+62];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b63 = _mm256_broadcast_sd(&B[(l_n*88)+63]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b63 = _mm_loaddup_pd(&B[(l_n*88)+63]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c63_0 = _mm256_loadu_pd(&C[(l_n*88)+35]);
    __m256d a63_0 = _mm256_loadu_pd(&A[793]);
    c63_0 = _mm256_add_pd(c63_0, _mm256_mul_pd(a63_0, b63));
    _mm256_storeu_pd(&C[(l_n*88)+35], c63_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c63_0 = _mm_loadu_pd(&C[(l_n*88)+35]);
    __m128d a63_0 = _mm_loadu_pd(&A[793]);
    c63_0 = _mm_add_pd(c63_0, _mm_mul_pd(a63_0, b63));
    _mm_storeu_pd(&C[(l_n*88)+35], c63_0);
    __m128d c63_2 = _mm_loadu_pd(&C[(l_n*88)+37]);
    __m128d a63_2 = _mm_loadu_pd(&A[795]);
    c63_2 = _mm_add_pd(c63_2, _mm_mul_pd(a63_2, b63));
    _mm_storeu_pd(&C[(l_n*88)+37], c63_2);
#endif
    __m128d c63_4 = _mm_loadu_pd(&C[(l_n*88)+39]);
    __m128d a63_4 = _mm_loadu_pd(&A[797]);
#if defined(__SSE3__) && defined(__AVX__)
    c63_4 = _mm_add_pd(c63_4, _mm_mul_pd(a63_4, _mm256_castpd256_pd128(b63)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c63_4 = _mm_add_pd(c63_4, _mm_mul_pd(a63_4, b63));
#endif
    _mm_storeu_pd(&C[(l_n*88)+39], c63_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c63_6 = _mm256_loadu_pd(&C[(l_n*88)+63]);
    __m256d a63_6 = _mm256_loadu_pd(&A[799]);
    c63_6 = _mm256_add_pd(c63_6, _mm256_mul_pd(a63_6, b63));
    _mm256_storeu_pd(&C[(l_n*88)+63], c63_6);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c63_6 = _mm_loadu_pd(&C[(l_n*88)+63]);
    __m128d a63_6 = _mm_loadu_pd(&A[799]);
    c63_6 = _mm_add_pd(c63_6, _mm_mul_pd(a63_6, b63));
    _mm_storeu_pd(&C[(l_n*88)+63], c63_6);
    __m128d c63_8 = _mm_loadu_pd(&C[(l_n*88)+65]);
    __m128d a63_8 = _mm_loadu_pd(&A[801]);
    c63_8 = _mm_add_pd(c63_8, _mm_mul_pd(a63_8, b63));
    _mm_storeu_pd(&C[(l_n*88)+65], c63_8);
#endif
    __m128d c63_10 = _mm_loadu_pd(&C[(l_n*88)+67]);
    __m128d a63_10 = _mm_loadu_pd(&A[803]);
#if defined(__SSE3__) && defined(__AVX__)
    c63_10 = _mm_add_pd(c63_10, _mm_mul_pd(a63_10, _mm256_castpd256_pd128(b63)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c63_10 = _mm_add_pd(c63_10, _mm_mul_pd(a63_10, b63));
#endif
    _mm_storeu_pd(&C[(l_n*88)+67], c63_10);
#else
    C[(l_n*88)+35] += A[793] * B[(l_n*88)+63];
    C[(l_n*88)+36] += A[794] * B[(l_n*88)+63];
    C[(l_n*88)+37] += A[795] * B[(l_n*88)+63];
    C[(l_n*88)+38] += A[796] * B[(l_n*88)+63];
    C[(l_n*88)+39] += A[797] * B[(l_n*88)+63];
    C[(l_n*88)+40] += A[798] * B[(l_n*88)+63];
    C[(l_n*88)+63] += A[799] * B[(l_n*88)+63];
    C[(l_n*88)+64] += A[800] * B[(l_n*88)+63];
    C[(l_n*88)+65] += A[801] * B[(l_n*88)+63];
    C[(l_n*88)+66] += A[802] * B[(l_n*88)+63];
    C[(l_n*88)+67] += A[803] * B[(l_n*88)+63];
    C[(l_n*88)+68] += A[804] * B[(l_n*88)+63];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b64 = _mm256_broadcast_sd(&B[(l_n*88)+64]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b64 = _mm_loaddup_pd(&B[(l_n*88)+64]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c64_0 = _mm256_loadu_pd(&C[(l_n*88)+35]);
    __m256d a64_0 = _mm256_loadu_pd(&A[805]);
    c64_0 = _mm256_add_pd(c64_0, _mm256_mul_pd(a64_0, b64));
    _mm256_storeu_pd(&C[(l_n*88)+35], c64_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c64_0 = _mm_loadu_pd(&C[(l_n*88)+35]);
    __m128d a64_0 = _mm_loadu_pd(&A[805]);
    c64_0 = _mm_add_pd(c64_0, _mm_mul_pd(a64_0, b64));
    _mm_storeu_pd(&C[(l_n*88)+35], c64_0);
    __m128d c64_2 = _mm_loadu_pd(&C[(l_n*88)+37]);
    __m128d a64_2 = _mm_loadu_pd(&A[807]);
    c64_2 = _mm_add_pd(c64_2, _mm_mul_pd(a64_2, b64));
    _mm_storeu_pd(&C[(l_n*88)+37], c64_2);
#endif
    __m128d c64_4 = _mm_loadu_pd(&C[(l_n*88)+39]);
    __m128d a64_4 = _mm_loadu_pd(&A[809]);
#if defined(__SSE3__) && defined(__AVX__)
    c64_4 = _mm_add_pd(c64_4, _mm_mul_pd(a64_4, _mm256_castpd256_pd128(b64)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c64_4 = _mm_add_pd(c64_4, _mm_mul_pd(a64_4, b64));
#endif
    _mm_storeu_pd(&C[(l_n*88)+39], c64_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c64_6 = _mm256_loadu_pd(&C[(l_n*88)+63]);
    __m256d a64_6 = _mm256_loadu_pd(&A[811]);
    c64_6 = _mm256_add_pd(c64_6, _mm256_mul_pd(a64_6, b64));
    _mm256_storeu_pd(&C[(l_n*88)+63], c64_6);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c64_6 = _mm_loadu_pd(&C[(l_n*88)+63]);
    __m128d a64_6 = _mm_loadu_pd(&A[811]);
    c64_6 = _mm_add_pd(c64_6, _mm_mul_pd(a64_6, b64));
    _mm_storeu_pd(&C[(l_n*88)+63], c64_6);
    __m128d c64_8 = _mm_loadu_pd(&C[(l_n*88)+65]);
    __m128d a64_8 = _mm_loadu_pd(&A[813]);
    c64_8 = _mm_add_pd(c64_8, _mm_mul_pd(a64_8, b64));
    _mm_storeu_pd(&C[(l_n*88)+65], c64_8);
#endif
    __m128d c64_10 = _mm_loadu_pd(&C[(l_n*88)+67]);
    __m128d a64_10 = _mm_loadu_pd(&A[815]);
#if defined(__SSE3__) && defined(__AVX__)
    c64_10 = _mm_add_pd(c64_10, _mm_mul_pd(a64_10, _mm256_castpd256_pd128(b64)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c64_10 = _mm_add_pd(c64_10, _mm_mul_pd(a64_10, b64));
#endif
    _mm_storeu_pd(&C[(l_n*88)+67], c64_10);
#else
    C[(l_n*88)+35] += A[805] * B[(l_n*88)+64];
    C[(l_n*88)+36] += A[806] * B[(l_n*88)+64];
    C[(l_n*88)+37] += A[807] * B[(l_n*88)+64];
    C[(l_n*88)+38] += A[808] * B[(l_n*88)+64];
    C[(l_n*88)+39] += A[809] * B[(l_n*88)+64];
    C[(l_n*88)+40] += A[810] * B[(l_n*88)+64];
    C[(l_n*88)+63] += A[811] * B[(l_n*88)+64];
    C[(l_n*88)+64] += A[812] * B[(l_n*88)+64];
    C[(l_n*88)+65] += A[813] * B[(l_n*88)+64];
    C[(l_n*88)+66] += A[814] * B[(l_n*88)+64];
    C[(l_n*88)+67] += A[815] * B[(l_n*88)+64];
    C[(l_n*88)+68] += A[816] * B[(l_n*88)+64];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b65 = _mm256_broadcast_sd(&B[(l_n*88)+65]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b65 = _mm_loaddup_pd(&B[(l_n*88)+65]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c65_0 = _mm256_loadu_pd(&C[(l_n*88)+35]);
    __m256d a65_0 = _mm256_loadu_pd(&A[817]);
    c65_0 = _mm256_add_pd(c65_0, _mm256_mul_pd(a65_0, b65));
    _mm256_storeu_pd(&C[(l_n*88)+35], c65_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c65_0 = _mm_loadu_pd(&C[(l_n*88)+35]);
    __m128d a65_0 = _mm_loadu_pd(&A[817]);
    c65_0 = _mm_add_pd(c65_0, _mm_mul_pd(a65_0, b65));
    _mm_storeu_pd(&C[(l_n*88)+35], c65_0);
    __m128d c65_2 = _mm_loadu_pd(&C[(l_n*88)+37]);
    __m128d a65_2 = _mm_loadu_pd(&A[819]);
    c65_2 = _mm_add_pd(c65_2, _mm_mul_pd(a65_2, b65));
    _mm_storeu_pd(&C[(l_n*88)+37], c65_2);
#endif
    __m128d c65_4 = _mm_loadu_pd(&C[(l_n*88)+39]);
    __m128d a65_4 = _mm_loadu_pd(&A[821]);
#if defined(__SSE3__) && defined(__AVX__)
    c65_4 = _mm_add_pd(c65_4, _mm_mul_pd(a65_4, _mm256_castpd256_pd128(b65)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c65_4 = _mm_add_pd(c65_4, _mm_mul_pd(a65_4, b65));
#endif
    _mm_storeu_pd(&C[(l_n*88)+39], c65_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c65_6 = _mm256_loadu_pd(&C[(l_n*88)+63]);
    __m256d a65_6 = _mm256_loadu_pd(&A[823]);
    c65_6 = _mm256_add_pd(c65_6, _mm256_mul_pd(a65_6, b65));
    _mm256_storeu_pd(&C[(l_n*88)+63], c65_6);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c65_6 = _mm_loadu_pd(&C[(l_n*88)+63]);
    __m128d a65_6 = _mm_loadu_pd(&A[823]);
    c65_6 = _mm_add_pd(c65_6, _mm_mul_pd(a65_6, b65));
    _mm_storeu_pd(&C[(l_n*88)+63], c65_6);
    __m128d c65_8 = _mm_loadu_pd(&C[(l_n*88)+65]);
    __m128d a65_8 = _mm_loadu_pd(&A[825]);
    c65_8 = _mm_add_pd(c65_8, _mm_mul_pd(a65_8, b65));
    _mm_storeu_pd(&C[(l_n*88)+65], c65_8);
#endif
    __m128d c65_10 = _mm_loadu_pd(&C[(l_n*88)+67]);
    __m128d a65_10 = _mm_loadu_pd(&A[827]);
#if defined(__SSE3__) && defined(__AVX__)
    c65_10 = _mm_add_pd(c65_10, _mm_mul_pd(a65_10, _mm256_castpd256_pd128(b65)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c65_10 = _mm_add_pd(c65_10, _mm_mul_pd(a65_10, b65));
#endif
    _mm_storeu_pd(&C[(l_n*88)+67], c65_10);
#else
    C[(l_n*88)+35] += A[817] * B[(l_n*88)+65];
    C[(l_n*88)+36] += A[818] * B[(l_n*88)+65];
    C[(l_n*88)+37] += A[819] * B[(l_n*88)+65];
    C[(l_n*88)+38] += A[820] * B[(l_n*88)+65];
    C[(l_n*88)+39] += A[821] * B[(l_n*88)+65];
    C[(l_n*88)+40] += A[822] * B[(l_n*88)+65];
    C[(l_n*88)+63] += A[823] * B[(l_n*88)+65];
    C[(l_n*88)+64] += A[824] * B[(l_n*88)+65];
    C[(l_n*88)+65] += A[825] * B[(l_n*88)+65];
    C[(l_n*88)+66] += A[826] * B[(l_n*88)+65];
    C[(l_n*88)+67] += A[827] * B[(l_n*88)+65];
    C[(l_n*88)+68] += A[828] * B[(l_n*88)+65];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b66 = _mm256_broadcast_sd(&B[(l_n*88)+66]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b66 = _mm_loaddup_pd(&B[(l_n*88)+66]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c66_0 = _mm256_loadu_pd(&C[(l_n*88)+35]);
    __m256d a66_0 = _mm256_loadu_pd(&A[829]);
    c66_0 = _mm256_add_pd(c66_0, _mm256_mul_pd(a66_0, b66));
    _mm256_storeu_pd(&C[(l_n*88)+35], c66_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c66_0 = _mm_loadu_pd(&C[(l_n*88)+35]);
    __m128d a66_0 = _mm_loadu_pd(&A[829]);
    c66_0 = _mm_add_pd(c66_0, _mm_mul_pd(a66_0, b66));
    _mm_storeu_pd(&C[(l_n*88)+35], c66_0);
    __m128d c66_2 = _mm_loadu_pd(&C[(l_n*88)+37]);
    __m128d a66_2 = _mm_loadu_pd(&A[831]);
    c66_2 = _mm_add_pd(c66_2, _mm_mul_pd(a66_2, b66));
    _mm_storeu_pd(&C[(l_n*88)+37], c66_2);
#endif
    __m128d c66_4 = _mm_loadu_pd(&C[(l_n*88)+39]);
    __m128d a66_4 = _mm_loadu_pd(&A[833]);
#if defined(__SSE3__) && defined(__AVX__)
    c66_4 = _mm_add_pd(c66_4, _mm_mul_pd(a66_4, _mm256_castpd256_pd128(b66)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c66_4 = _mm_add_pd(c66_4, _mm_mul_pd(a66_4, b66));
#endif
    _mm_storeu_pd(&C[(l_n*88)+39], c66_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c66_6 = _mm256_loadu_pd(&C[(l_n*88)+63]);
    __m256d a66_6 = _mm256_loadu_pd(&A[835]);
    c66_6 = _mm256_add_pd(c66_6, _mm256_mul_pd(a66_6, b66));
    _mm256_storeu_pd(&C[(l_n*88)+63], c66_6);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c66_6 = _mm_loadu_pd(&C[(l_n*88)+63]);
    __m128d a66_6 = _mm_loadu_pd(&A[835]);
    c66_6 = _mm_add_pd(c66_6, _mm_mul_pd(a66_6, b66));
    _mm_storeu_pd(&C[(l_n*88)+63], c66_6);
    __m128d c66_8 = _mm_loadu_pd(&C[(l_n*88)+65]);
    __m128d a66_8 = _mm_loadu_pd(&A[837]);
    c66_8 = _mm_add_pd(c66_8, _mm_mul_pd(a66_8, b66));
    _mm_storeu_pd(&C[(l_n*88)+65], c66_8);
#endif
    __m128d c66_10 = _mm_loadu_pd(&C[(l_n*88)+67]);
    __m128d a66_10 = _mm_loadu_pd(&A[839]);
#if defined(__SSE3__) && defined(__AVX__)
    c66_10 = _mm_add_pd(c66_10, _mm_mul_pd(a66_10, _mm256_castpd256_pd128(b66)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c66_10 = _mm_add_pd(c66_10, _mm_mul_pd(a66_10, b66));
#endif
    _mm_storeu_pd(&C[(l_n*88)+67], c66_10);
#else
    C[(l_n*88)+35] += A[829] * B[(l_n*88)+66];
    C[(l_n*88)+36] += A[830] * B[(l_n*88)+66];
    C[(l_n*88)+37] += A[831] * B[(l_n*88)+66];
    C[(l_n*88)+38] += A[832] * B[(l_n*88)+66];
    C[(l_n*88)+39] += A[833] * B[(l_n*88)+66];
    C[(l_n*88)+40] += A[834] * B[(l_n*88)+66];
    C[(l_n*88)+63] += A[835] * B[(l_n*88)+66];
    C[(l_n*88)+64] += A[836] * B[(l_n*88)+66];
    C[(l_n*88)+65] += A[837] * B[(l_n*88)+66];
    C[(l_n*88)+66] += A[838] * B[(l_n*88)+66];
    C[(l_n*88)+67] += A[839] * B[(l_n*88)+66];
    C[(l_n*88)+68] += A[840] * B[(l_n*88)+66];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b67 = _mm256_broadcast_sd(&B[(l_n*88)+67]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b67 = _mm_loaddup_pd(&B[(l_n*88)+67]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c67_0 = _mm256_loadu_pd(&C[(l_n*88)+35]);
    __m256d a67_0 = _mm256_loadu_pd(&A[841]);
    c67_0 = _mm256_add_pd(c67_0, _mm256_mul_pd(a67_0, b67));
    _mm256_storeu_pd(&C[(l_n*88)+35], c67_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c67_0 = _mm_loadu_pd(&C[(l_n*88)+35]);
    __m128d a67_0 = _mm_loadu_pd(&A[841]);
    c67_0 = _mm_add_pd(c67_0, _mm_mul_pd(a67_0, b67));
    _mm_storeu_pd(&C[(l_n*88)+35], c67_0);
    __m128d c67_2 = _mm_loadu_pd(&C[(l_n*88)+37]);
    __m128d a67_2 = _mm_loadu_pd(&A[843]);
    c67_2 = _mm_add_pd(c67_2, _mm_mul_pd(a67_2, b67));
    _mm_storeu_pd(&C[(l_n*88)+37], c67_2);
#endif
    __m128d c67_4 = _mm_loadu_pd(&C[(l_n*88)+39]);
    __m128d a67_4 = _mm_loadu_pd(&A[845]);
#if defined(__SSE3__) && defined(__AVX__)
    c67_4 = _mm_add_pd(c67_4, _mm_mul_pd(a67_4, _mm256_castpd256_pd128(b67)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c67_4 = _mm_add_pd(c67_4, _mm_mul_pd(a67_4, b67));
#endif
    _mm_storeu_pd(&C[(l_n*88)+39], c67_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c67_6 = _mm256_loadu_pd(&C[(l_n*88)+63]);
    __m256d a67_6 = _mm256_loadu_pd(&A[847]);
    c67_6 = _mm256_add_pd(c67_6, _mm256_mul_pd(a67_6, b67));
    _mm256_storeu_pd(&C[(l_n*88)+63], c67_6);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c67_6 = _mm_loadu_pd(&C[(l_n*88)+63]);
    __m128d a67_6 = _mm_loadu_pd(&A[847]);
    c67_6 = _mm_add_pd(c67_6, _mm_mul_pd(a67_6, b67));
    _mm_storeu_pd(&C[(l_n*88)+63], c67_6);
    __m128d c67_8 = _mm_loadu_pd(&C[(l_n*88)+65]);
    __m128d a67_8 = _mm_loadu_pd(&A[849]);
    c67_8 = _mm_add_pd(c67_8, _mm_mul_pd(a67_8, b67));
    _mm_storeu_pd(&C[(l_n*88)+65], c67_8);
#endif
    __m128d c67_10 = _mm_loadu_pd(&C[(l_n*88)+67]);
    __m128d a67_10 = _mm_loadu_pd(&A[851]);
#if defined(__SSE3__) && defined(__AVX__)
    c67_10 = _mm_add_pd(c67_10, _mm_mul_pd(a67_10, _mm256_castpd256_pd128(b67)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c67_10 = _mm_add_pd(c67_10, _mm_mul_pd(a67_10, b67));
#endif
    _mm_storeu_pd(&C[(l_n*88)+67], c67_10);
#else
    C[(l_n*88)+35] += A[841] * B[(l_n*88)+67];
    C[(l_n*88)+36] += A[842] * B[(l_n*88)+67];
    C[(l_n*88)+37] += A[843] * B[(l_n*88)+67];
    C[(l_n*88)+38] += A[844] * B[(l_n*88)+67];
    C[(l_n*88)+39] += A[845] * B[(l_n*88)+67];
    C[(l_n*88)+40] += A[846] * B[(l_n*88)+67];
    C[(l_n*88)+63] += A[847] * B[(l_n*88)+67];
    C[(l_n*88)+64] += A[848] * B[(l_n*88)+67];
    C[(l_n*88)+65] += A[849] * B[(l_n*88)+67];
    C[(l_n*88)+66] += A[850] * B[(l_n*88)+67];
    C[(l_n*88)+67] += A[851] * B[(l_n*88)+67];
    C[(l_n*88)+68] += A[852] * B[(l_n*88)+67];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b68 = _mm256_broadcast_sd(&B[(l_n*88)+68]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b68 = _mm_loaddup_pd(&B[(l_n*88)+68]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c68_0 = _mm256_loadu_pd(&C[(l_n*88)+35]);
    __m256d a68_0 = _mm256_loadu_pd(&A[853]);
    c68_0 = _mm256_add_pd(c68_0, _mm256_mul_pd(a68_0, b68));
    _mm256_storeu_pd(&C[(l_n*88)+35], c68_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c68_0 = _mm_loadu_pd(&C[(l_n*88)+35]);
    __m128d a68_0 = _mm_loadu_pd(&A[853]);
    c68_0 = _mm_add_pd(c68_0, _mm_mul_pd(a68_0, b68));
    _mm_storeu_pd(&C[(l_n*88)+35], c68_0);
    __m128d c68_2 = _mm_loadu_pd(&C[(l_n*88)+37]);
    __m128d a68_2 = _mm_loadu_pd(&A[855]);
    c68_2 = _mm_add_pd(c68_2, _mm_mul_pd(a68_2, b68));
    _mm_storeu_pd(&C[(l_n*88)+37], c68_2);
#endif
    __m128d c68_4 = _mm_loadu_pd(&C[(l_n*88)+39]);
    __m128d a68_4 = _mm_loadu_pd(&A[857]);
#if defined(__SSE3__) && defined(__AVX__)
    c68_4 = _mm_add_pd(c68_4, _mm_mul_pd(a68_4, _mm256_castpd256_pd128(b68)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c68_4 = _mm_add_pd(c68_4, _mm_mul_pd(a68_4, b68));
#endif
    _mm_storeu_pd(&C[(l_n*88)+39], c68_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c68_6 = _mm256_loadu_pd(&C[(l_n*88)+63]);
    __m256d a68_6 = _mm256_loadu_pd(&A[859]);
    c68_6 = _mm256_add_pd(c68_6, _mm256_mul_pd(a68_6, b68));
    _mm256_storeu_pd(&C[(l_n*88)+63], c68_6);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c68_6 = _mm_loadu_pd(&C[(l_n*88)+63]);
    __m128d a68_6 = _mm_loadu_pd(&A[859]);
    c68_6 = _mm_add_pd(c68_6, _mm_mul_pd(a68_6, b68));
    _mm_storeu_pd(&C[(l_n*88)+63], c68_6);
    __m128d c68_8 = _mm_loadu_pd(&C[(l_n*88)+65]);
    __m128d a68_8 = _mm_loadu_pd(&A[861]);
    c68_8 = _mm_add_pd(c68_8, _mm_mul_pd(a68_8, b68));
    _mm_storeu_pd(&C[(l_n*88)+65], c68_8);
#endif
    __m128d c68_10 = _mm_loadu_pd(&C[(l_n*88)+67]);
    __m128d a68_10 = _mm_loadu_pd(&A[863]);
#if defined(__SSE3__) && defined(__AVX__)
    c68_10 = _mm_add_pd(c68_10, _mm_mul_pd(a68_10, _mm256_castpd256_pd128(b68)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c68_10 = _mm_add_pd(c68_10, _mm_mul_pd(a68_10, b68));
#endif
    _mm_storeu_pd(&C[(l_n*88)+67], c68_10);
#else
    C[(l_n*88)+35] += A[853] * B[(l_n*88)+68];
    C[(l_n*88)+36] += A[854] * B[(l_n*88)+68];
    C[(l_n*88)+37] += A[855] * B[(l_n*88)+68];
    C[(l_n*88)+38] += A[856] * B[(l_n*88)+68];
    C[(l_n*88)+39] += A[857] * B[(l_n*88)+68];
    C[(l_n*88)+40] += A[858] * B[(l_n*88)+68];
    C[(l_n*88)+63] += A[859] * B[(l_n*88)+68];
    C[(l_n*88)+64] += A[860] * B[(l_n*88)+68];
    C[(l_n*88)+65] += A[861] * B[(l_n*88)+68];
    C[(l_n*88)+66] += A[862] * B[(l_n*88)+68];
    C[(l_n*88)+67] += A[863] * B[(l_n*88)+68];
    C[(l_n*88)+68] += A[864] * B[(l_n*88)+68];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b69 = _mm256_broadcast_sd(&B[(l_n*88)+69]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b69 = _mm_loaddup_pd(&B[(l_n*88)+69]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c69_0 = _mm256_loadu_pd(&C[(l_n*88)+20]);
    __m256d a69_0 = _mm256_loadu_pd(&A[865]);
    c69_0 = _mm256_add_pd(c69_0, _mm256_mul_pd(a69_0, b69));
    _mm256_storeu_pd(&C[(l_n*88)+20], c69_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c69_0 = _mm_loadu_pd(&C[(l_n*88)+20]);
    __m128d a69_0 = _mm_loadu_pd(&A[865]);
    c69_0 = _mm_add_pd(c69_0, _mm_mul_pd(a69_0, b69));
    _mm_storeu_pd(&C[(l_n*88)+20], c69_0);
    __m128d c69_2 = _mm_loadu_pd(&C[(l_n*88)+22]);
    __m128d a69_2 = _mm_loadu_pd(&A[867]);
    c69_2 = _mm_add_pd(c69_2, _mm_mul_pd(a69_2, b69));
    _mm_storeu_pd(&C[(l_n*88)+22], c69_2);
#endif
    __m128d c69_4 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a69_4 = _mm_load_sd(&A[869]);
#if defined(__SSE3__) && defined(__AVX__)
    c69_4 = _mm_add_sd(c69_4, _mm_mul_sd(a69_4, _mm256_castpd256_pd128(b69)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c69_4 = _mm_add_sd(c69_4, _mm_mul_sd(a69_4, b69));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c69_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c69_5 = _mm256_loadu_pd(&C[(l_n*88)+41]);
    __m256d a69_5 = _mm256_loadu_pd(&A[870]);
    c69_5 = _mm256_add_pd(c69_5, _mm256_mul_pd(a69_5, b69));
    _mm256_storeu_pd(&C[(l_n*88)+41], c69_5);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c69_5 = _mm_loadu_pd(&C[(l_n*88)+41]);
    __m128d a69_5 = _mm_loadu_pd(&A[870]);
    c69_5 = _mm_add_pd(c69_5, _mm_mul_pd(a69_5, b69));
    _mm_storeu_pd(&C[(l_n*88)+41], c69_5);
    __m128d c69_7 = _mm_loadu_pd(&C[(l_n*88)+43]);
    __m128d a69_7 = _mm_loadu_pd(&A[872]);
    c69_7 = _mm_add_pd(c69_7, _mm_mul_pd(a69_7, b69));
    _mm_storeu_pd(&C[(l_n*88)+43], c69_7);
#endif
    __m128d c69_9 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a69_9 = _mm_load_sd(&A[874]);
#if defined(__SSE3__) && defined(__AVX__)
    c69_9 = _mm_add_sd(c69_9, _mm_mul_sd(a69_9, _mm256_castpd256_pd128(b69)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c69_9 = _mm_add_sd(c69_9, _mm_mul_sd(a69_9, b69));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c69_9);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c69_10 = _mm256_loadu_pd(&C[(l_n*88)+69]);
    __m256d a69_10 = _mm256_loadu_pd(&A[875]);
    c69_10 = _mm256_add_pd(c69_10, _mm256_mul_pd(a69_10, b69));
    _mm256_storeu_pd(&C[(l_n*88)+69], c69_10);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c69_10 = _mm_loadu_pd(&C[(l_n*88)+69]);
    __m128d a69_10 = _mm_loadu_pd(&A[875]);
    c69_10 = _mm_add_pd(c69_10, _mm_mul_pd(a69_10, b69));
    _mm_storeu_pd(&C[(l_n*88)+69], c69_10);
    __m128d c69_12 = _mm_loadu_pd(&C[(l_n*88)+71]);
    __m128d a69_12 = _mm_loadu_pd(&A[877]);
    c69_12 = _mm_add_pd(c69_12, _mm_mul_pd(a69_12, b69));
    _mm_storeu_pd(&C[(l_n*88)+71], c69_12);
#endif
    __m128d c69_14 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a69_14 = _mm_load_sd(&A[879]);
#if defined(__SSE3__) && defined(__AVX__)
    c69_14 = _mm_add_sd(c69_14, _mm_mul_sd(a69_14, _mm256_castpd256_pd128(b69)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c69_14 = _mm_add_sd(c69_14, _mm_mul_sd(a69_14, b69));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c69_14);
#else
    C[(l_n*88)+20] += A[865] * B[(l_n*88)+69];
    C[(l_n*88)+21] += A[866] * B[(l_n*88)+69];
    C[(l_n*88)+22] += A[867] * B[(l_n*88)+69];
    C[(l_n*88)+23] += A[868] * B[(l_n*88)+69];
    C[(l_n*88)+24] += A[869] * B[(l_n*88)+69];
    C[(l_n*88)+41] += A[870] * B[(l_n*88)+69];
    C[(l_n*88)+42] += A[871] * B[(l_n*88)+69];
    C[(l_n*88)+43] += A[872] * B[(l_n*88)+69];
    C[(l_n*88)+44] += A[873] * B[(l_n*88)+69];
    C[(l_n*88)+45] += A[874] * B[(l_n*88)+69];
    C[(l_n*88)+69] += A[875] * B[(l_n*88)+69];
    C[(l_n*88)+70] += A[876] * B[(l_n*88)+69];
    C[(l_n*88)+71] += A[877] * B[(l_n*88)+69];
    C[(l_n*88)+72] += A[878] * B[(l_n*88)+69];
    C[(l_n*88)+73] += A[879] * B[(l_n*88)+69];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b70 = _mm256_broadcast_sd(&B[(l_n*88)+70]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b70 = _mm_loaddup_pd(&B[(l_n*88)+70]);
#endif
    __m128d c70_0 = _mm_loadu_pd(&C[(l_n*88)+20]);
    __m128d a70_0 = _mm_loadu_pd(&A[880]);
#if defined(__SSE3__) && defined(__AVX__)
    c70_0 = _mm_add_pd(c70_0, _mm_mul_pd(a70_0, _mm256_castpd256_pd128(b70)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c70_0 = _mm_add_pd(c70_0, _mm_mul_pd(a70_0, b70));
#endif
    _mm_storeu_pd(&C[(l_n*88)+20], c70_0);
    __m128d c70_2 = _mm_load_sd(&C[(l_n*88)+22]);
    __m128d a70_2 = _mm_load_sd(&A[882]);
#if defined(__SSE3__) && defined(__AVX__)
    c70_2 = _mm_add_sd(c70_2, _mm_mul_sd(a70_2, _mm256_castpd256_pd128(b70)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c70_2 = _mm_add_sd(c70_2, _mm_mul_sd(a70_2, b70));
#endif
    _mm_store_sd(&C[(l_n*88)+22], c70_2);
    __m128d c70_3 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a70_3 = _mm_load_sd(&A[883]);
#if defined(__SSE3__) && defined(__AVX__)
    c70_3 = _mm_add_sd(c70_3, _mm_mul_sd(a70_3, _mm256_castpd256_pd128(b70)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c70_3 = _mm_add_sd(c70_3, _mm_mul_sd(a70_3, b70));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c70_3);
    __m128d c70_4 = _mm_loadu_pd(&C[(l_n*88)+41]);
    __m128d a70_4 = _mm_loadu_pd(&A[884]);
#if defined(__SSE3__) && defined(__AVX__)
    c70_4 = _mm_add_pd(c70_4, _mm_mul_pd(a70_4, _mm256_castpd256_pd128(b70)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c70_4 = _mm_add_pd(c70_4, _mm_mul_pd(a70_4, b70));
#endif
    _mm_storeu_pd(&C[(l_n*88)+41], c70_4);
    __m128d c70_6 = _mm_load_sd(&C[(l_n*88)+43]);
    __m128d a70_6 = _mm_load_sd(&A[886]);
#if defined(__SSE3__) && defined(__AVX__)
    c70_6 = _mm_add_sd(c70_6, _mm_mul_sd(a70_6, _mm256_castpd256_pd128(b70)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c70_6 = _mm_add_sd(c70_6, _mm_mul_sd(a70_6, b70));
#endif
    _mm_store_sd(&C[(l_n*88)+43], c70_6);
    __m128d c70_7 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a70_7 = _mm_load_sd(&A[887]);
#if defined(__SSE3__) && defined(__AVX__)
    c70_7 = _mm_add_sd(c70_7, _mm_mul_sd(a70_7, _mm256_castpd256_pd128(b70)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c70_7 = _mm_add_sd(c70_7, _mm_mul_sd(a70_7, b70));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c70_7);
    __m128d c70_8 = _mm_loadu_pd(&C[(l_n*88)+69]);
    __m128d a70_8 = _mm_loadu_pd(&A[888]);
#if defined(__SSE3__) && defined(__AVX__)
    c70_8 = _mm_add_pd(c70_8, _mm_mul_pd(a70_8, _mm256_castpd256_pd128(b70)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c70_8 = _mm_add_pd(c70_8, _mm_mul_pd(a70_8, b70));
#endif
    _mm_storeu_pd(&C[(l_n*88)+69], c70_8);
    __m128d c70_10 = _mm_load_sd(&C[(l_n*88)+71]);
    __m128d a70_10 = _mm_load_sd(&A[890]);
#if defined(__SSE3__) && defined(__AVX__)
    c70_10 = _mm_add_sd(c70_10, _mm_mul_sd(a70_10, _mm256_castpd256_pd128(b70)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c70_10 = _mm_add_sd(c70_10, _mm_mul_sd(a70_10, b70));
#endif
    _mm_store_sd(&C[(l_n*88)+71], c70_10);
    __m128d c70_11 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a70_11 = _mm_load_sd(&A[891]);
#if defined(__SSE3__) && defined(__AVX__)
    c70_11 = _mm_add_sd(c70_11, _mm_mul_sd(a70_11, _mm256_castpd256_pd128(b70)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c70_11 = _mm_add_sd(c70_11, _mm_mul_sd(a70_11, b70));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c70_11);
#else
    C[(l_n*88)+20] += A[880] * B[(l_n*88)+70];
    C[(l_n*88)+21] += A[881] * B[(l_n*88)+70];
    C[(l_n*88)+22] += A[882] * B[(l_n*88)+70];
    C[(l_n*88)+24] += A[883] * B[(l_n*88)+70];
    C[(l_n*88)+41] += A[884] * B[(l_n*88)+70];
    C[(l_n*88)+42] += A[885] * B[(l_n*88)+70];
    C[(l_n*88)+43] += A[886] * B[(l_n*88)+70];
    C[(l_n*88)+45] += A[887] * B[(l_n*88)+70];
    C[(l_n*88)+69] += A[888] * B[(l_n*88)+70];
    C[(l_n*88)+70] += A[889] * B[(l_n*88)+70];
    C[(l_n*88)+71] += A[890] * B[(l_n*88)+70];
    C[(l_n*88)+73] += A[891] * B[(l_n*88)+70];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b71 = _mm256_broadcast_sd(&B[(l_n*88)+71]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b71 = _mm_loaddup_pd(&B[(l_n*88)+71]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c71_0 = _mm256_loadu_pd(&C[(l_n*88)+20]);
    __m256d a71_0 = _mm256_loadu_pd(&A[892]);
    c71_0 = _mm256_add_pd(c71_0, _mm256_mul_pd(a71_0, b71));
    _mm256_storeu_pd(&C[(l_n*88)+20], c71_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c71_0 = _mm_loadu_pd(&C[(l_n*88)+20]);
    __m128d a71_0 = _mm_loadu_pd(&A[892]);
    c71_0 = _mm_add_pd(c71_0, _mm_mul_pd(a71_0, b71));
    _mm_storeu_pd(&C[(l_n*88)+20], c71_0);
    __m128d c71_2 = _mm_loadu_pd(&C[(l_n*88)+22]);
    __m128d a71_2 = _mm_loadu_pd(&A[894]);
    c71_2 = _mm_add_pd(c71_2, _mm_mul_pd(a71_2, b71));
    _mm_storeu_pd(&C[(l_n*88)+22], c71_2);
#endif
    __m128d c71_4 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a71_4 = _mm_load_sd(&A[896]);
#if defined(__SSE3__) && defined(__AVX__)
    c71_4 = _mm_add_sd(c71_4, _mm_mul_sd(a71_4, _mm256_castpd256_pd128(b71)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c71_4 = _mm_add_sd(c71_4, _mm_mul_sd(a71_4, b71));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c71_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c71_5 = _mm256_loadu_pd(&C[(l_n*88)+41]);
    __m256d a71_5 = _mm256_loadu_pd(&A[897]);
    c71_5 = _mm256_add_pd(c71_5, _mm256_mul_pd(a71_5, b71));
    _mm256_storeu_pd(&C[(l_n*88)+41], c71_5);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c71_5 = _mm_loadu_pd(&C[(l_n*88)+41]);
    __m128d a71_5 = _mm_loadu_pd(&A[897]);
    c71_5 = _mm_add_pd(c71_5, _mm_mul_pd(a71_5, b71));
    _mm_storeu_pd(&C[(l_n*88)+41], c71_5);
    __m128d c71_7 = _mm_loadu_pd(&C[(l_n*88)+43]);
    __m128d a71_7 = _mm_loadu_pd(&A[899]);
    c71_7 = _mm_add_pd(c71_7, _mm_mul_pd(a71_7, b71));
    _mm_storeu_pd(&C[(l_n*88)+43], c71_7);
#endif
    __m128d c71_9 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a71_9 = _mm_load_sd(&A[901]);
#if defined(__SSE3__) && defined(__AVX__)
    c71_9 = _mm_add_sd(c71_9, _mm_mul_sd(a71_9, _mm256_castpd256_pd128(b71)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c71_9 = _mm_add_sd(c71_9, _mm_mul_sd(a71_9, b71));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c71_9);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c71_10 = _mm256_loadu_pd(&C[(l_n*88)+69]);
    __m256d a71_10 = _mm256_loadu_pd(&A[902]);
    c71_10 = _mm256_add_pd(c71_10, _mm256_mul_pd(a71_10, b71));
    _mm256_storeu_pd(&C[(l_n*88)+69], c71_10);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c71_10 = _mm_loadu_pd(&C[(l_n*88)+69]);
    __m128d a71_10 = _mm_loadu_pd(&A[902]);
    c71_10 = _mm_add_pd(c71_10, _mm_mul_pd(a71_10, b71));
    _mm_storeu_pd(&C[(l_n*88)+69], c71_10);
    __m128d c71_12 = _mm_loadu_pd(&C[(l_n*88)+71]);
    __m128d a71_12 = _mm_loadu_pd(&A[904]);
    c71_12 = _mm_add_pd(c71_12, _mm_mul_pd(a71_12, b71));
    _mm_storeu_pd(&C[(l_n*88)+71], c71_12);
#endif
    __m128d c71_14 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a71_14 = _mm_load_sd(&A[906]);
#if defined(__SSE3__) && defined(__AVX__)
    c71_14 = _mm_add_sd(c71_14, _mm_mul_sd(a71_14, _mm256_castpd256_pd128(b71)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c71_14 = _mm_add_sd(c71_14, _mm_mul_sd(a71_14, b71));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c71_14);
#else
    C[(l_n*88)+20] += A[892] * B[(l_n*88)+71];
    C[(l_n*88)+21] += A[893] * B[(l_n*88)+71];
    C[(l_n*88)+22] += A[894] * B[(l_n*88)+71];
    C[(l_n*88)+23] += A[895] * B[(l_n*88)+71];
    C[(l_n*88)+24] += A[896] * B[(l_n*88)+71];
    C[(l_n*88)+41] += A[897] * B[(l_n*88)+71];
    C[(l_n*88)+42] += A[898] * B[(l_n*88)+71];
    C[(l_n*88)+43] += A[899] * B[(l_n*88)+71];
    C[(l_n*88)+44] += A[900] * B[(l_n*88)+71];
    C[(l_n*88)+45] += A[901] * B[(l_n*88)+71];
    C[(l_n*88)+69] += A[902] * B[(l_n*88)+71];
    C[(l_n*88)+70] += A[903] * B[(l_n*88)+71];
    C[(l_n*88)+71] += A[904] * B[(l_n*88)+71];
    C[(l_n*88)+72] += A[905] * B[(l_n*88)+71];
    C[(l_n*88)+73] += A[906] * B[(l_n*88)+71];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b72 = _mm256_broadcast_sd(&B[(l_n*88)+72]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b72 = _mm_loaddup_pd(&B[(l_n*88)+72]);
#endif
    __m128d c72_0 = _mm_load_sd(&C[(l_n*88)+20]);
    __m128d a72_0 = _mm_load_sd(&A[907]);
#if defined(__SSE3__) && defined(__AVX__)
    c72_0 = _mm_add_sd(c72_0, _mm_mul_sd(a72_0, _mm256_castpd256_pd128(b72)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c72_0 = _mm_add_sd(c72_0, _mm_mul_sd(a72_0, b72));
#endif
    _mm_store_sd(&C[(l_n*88)+20], c72_0);
    __m128d c72_1 = _mm_loadu_pd(&C[(l_n*88)+22]);
    __m128d a72_1 = _mm_loadu_pd(&A[908]);
#if defined(__SSE3__) && defined(__AVX__)
    c72_1 = _mm_add_pd(c72_1, _mm_mul_pd(a72_1, _mm256_castpd256_pd128(b72)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c72_1 = _mm_add_pd(c72_1, _mm_mul_pd(a72_1, b72));
#endif
    _mm_storeu_pd(&C[(l_n*88)+22], c72_1);
    __m128d c72_3 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a72_3 = _mm_load_sd(&A[910]);
#if defined(__SSE3__) && defined(__AVX__)
    c72_3 = _mm_add_sd(c72_3, _mm_mul_sd(a72_3, _mm256_castpd256_pd128(b72)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c72_3 = _mm_add_sd(c72_3, _mm_mul_sd(a72_3, b72));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c72_3);
    __m128d c72_4 = _mm_load_sd(&C[(l_n*88)+41]);
    __m128d a72_4 = _mm_load_sd(&A[911]);
#if defined(__SSE3__) && defined(__AVX__)
    c72_4 = _mm_add_sd(c72_4, _mm_mul_sd(a72_4, _mm256_castpd256_pd128(b72)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c72_4 = _mm_add_sd(c72_4, _mm_mul_sd(a72_4, b72));
#endif
    _mm_store_sd(&C[(l_n*88)+41], c72_4);
    __m128d c72_5 = _mm_loadu_pd(&C[(l_n*88)+43]);
    __m128d a72_5 = _mm_loadu_pd(&A[912]);
#if defined(__SSE3__) && defined(__AVX__)
    c72_5 = _mm_add_pd(c72_5, _mm_mul_pd(a72_5, _mm256_castpd256_pd128(b72)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c72_5 = _mm_add_pd(c72_5, _mm_mul_pd(a72_5, b72));
#endif
    _mm_storeu_pd(&C[(l_n*88)+43], c72_5);
    __m128d c72_7 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a72_7 = _mm_load_sd(&A[914]);
#if defined(__SSE3__) && defined(__AVX__)
    c72_7 = _mm_add_sd(c72_7, _mm_mul_sd(a72_7, _mm256_castpd256_pd128(b72)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c72_7 = _mm_add_sd(c72_7, _mm_mul_sd(a72_7, b72));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c72_7);
    __m128d c72_8 = _mm_load_sd(&C[(l_n*88)+69]);
    __m128d a72_8 = _mm_load_sd(&A[915]);
#if defined(__SSE3__) && defined(__AVX__)
    c72_8 = _mm_add_sd(c72_8, _mm_mul_sd(a72_8, _mm256_castpd256_pd128(b72)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c72_8 = _mm_add_sd(c72_8, _mm_mul_sd(a72_8, b72));
#endif
    _mm_store_sd(&C[(l_n*88)+69], c72_8);
    __m128d c72_9 = _mm_loadu_pd(&C[(l_n*88)+71]);
    __m128d a72_9 = _mm_loadu_pd(&A[916]);
#if defined(__SSE3__) && defined(__AVX__)
    c72_9 = _mm_add_pd(c72_9, _mm_mul_pd(a72_9, _mm256_castpd256_pd128(b72)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c72_9 = _mm_add_pd(c72_9, _mm_mul_pd(a72_9, b72));
#endif
    _mm_storeu_pd(&C[(l_n*88)+71], c72_9);
    __m128d c72_11 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a72_11 = _mm_load_sd(&A[918]);
#if defined(__SSE3__) && defined(__AVX__)
    c72_11 = _mm_add_sd(c72_11, _mm_mul_sd(a72_11, _mm256_castpd256_pd128(b72)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c72_11 = _mm_add_sd(c72_11, _mm_mul_sd(a72_11, b72));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c72_11);
#else
    C[(l_n*88)+20] += A[907] * B[(l_n*88)+72];
    C[(l_n*88)+22] += A[908] * B[(l_n*88)+72];
    C[(l_n*88)+23] += A[909] * B[(l_n*88)+72];
    C[(l_n*88)+24] += A[910] * B[(l_n*88)+72];
    C[(l_n*88)+41] += A[911] * B[(l_n*88)+72];
    C[(l_n*88)+43] += A[912] * B[(l_n*88)+72];
    C[(l_n*88)+44] += A[913] * B[(l_n*88)+72];
    C[(l_n*88)+45] += A[914] * B[(l_n*88)+72];
    C[(l_n*88)+69] += A[915] * B[(l_n*88)+72];
    C[(l_n*88)+71] += A[916] * B[(l_n*88)+72];
    C[(l_n*88)+72] += A[917] * B[(l_n*88)+72];
    C[(l_n*88)+73] += A[918] * B[(l_n*88)+72];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b73 = _mm256_broadcast_sd(&B[(l_n*88)+73]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b73 = _mm_loaddup_pd(&B[(l_n*88)+73]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c73_0 = _mm256_loadu_pd(&C[(l_n*88)+20]);
    __m256d a73_0 = _mm256_loadu_pd(&A[919]);
    c73_0 = _mm256_add_pd(c73_0, _mm256_mul_pd(a73_0, b73));
    _mm256_storeu_pd(&C[(l_n*88)+20], c73_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c73_0 = _mm_loadu_pd(&C[(l_n*88)+20]);
    __m128d a73_0 = _mm_loadu_pd(&A[919]);
    c73_0 = _mm_add_pd(c73_0, _mm_mul_pd(a73_0, b73));
    _mm_storeu_pd(&C[(l_n*88)+20], c73_0);
    __m128d c73_2 = _mm_loadu_pd(&C[(l_n*88)+22]);
    __m128d a73_2 = _mm_loadu_pd(&A[921]);
    c73_2 = _mm_add_pd(c73_2, _mm_mul_pd(a73_2, b73));
    _mm_storeu_pd(&C[(l_n*88)+22], c73_2);
#endif
    __m128d c73_4 = _mm_load_sd(&C[(l_n*88)+24]);
    __m128d a73_4 = _mm_load_sd(&A[923]);
#if defined(__SSE3__) && defined(__AVX__)
    c73_4 = _mm_add_sd(c73_4, _mm_mul_sd(a73_4, _mm256_castpd256_pd128(b73)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c73_4 = _mm_add_sd(c73_4, _mm_mul_sd(a73_4, b73));
#endif
    _mm_store_sd(&C[(l_n*88)+24], c73_4);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c73_5 = _mm256_loadu_pd(&C[(l_n*88)+41]);
    __m256d a73_5 = _mm256_loadu_pd(&A[924]);
    c73_5 = _mm256_add_pd(c73_5, _mm256_mul_pd(a73_5, b73));
    _mm256_storeu_pd(&C[(l_n*88)+41], c73_5);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c73_5 = _mm_loadu_pd(&C[(l_n*88)+41]);
    __m128d a73_5 = _mm_loadu_pd(&A[924]);
    c73_5 = _mm_add_pd(c73_5, _mm_mul_pd(a73_5, b73));
    _mm_storeu_pd(&C[(l_n*88)+41], c73_5);
    __m128d c73_7 = _mm_loadu_pd(&C[(l_n*88)+43]);
    __m128d a73_7 = _mm_loadu_pd(&A[926]);
    c73_7 = _mm_add_pd(c73_7, _mm_mul_pd(a73_7, b73));
    _mm_storeu_pd(&C[(l_n*88)+43], c73_7);
#endif
    __m128d c73_9 = _mm_load_sd(&C[(l_n*88)+45]);
    __m128d a73_9 = _mm_load_sd(&A[928]);
#if defined(__SSE3__) && defined(__AVX__)
    c73_9 = _mm_add_sd(c73_9, _mm_mul_sd(a73_9, _mm256_castpd256_pd128(b73)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c73_9 = _mm_add_sd(c73_9, _mm_mul_sd(a73_9, b73));
#endif
    _mm_store_sd(&C[(l_n*88)+45], c73_9);
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c73_10 = _mm256_loadu_pd(&C[(l_n*88)+69]);
    __m256d a73_10 = _mm256_loadu_pd(&A[929]);
    c73_10 = _mm256_add_pd(c73_10, _mm256_mul_pd(a73_10, b73));
    _mm256_storeu_pd(&C[(l_n*88)+69], c73_10);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c73_10 = _mm_loadu_pd(&C[(l_n*88)+69]);
    __m128d a73_10 = _mm_loadu_pd(&A[929]);
    c73_10 = _mm_add_pd(c73_10, _mm_mul_pd(a73_10, b73));
    _mm_storeu_pd(&C[(l_n*88)+69], c73_10);
    __m128d c73_12 = _mm_loadu_pd(&C[(l_n*88)+71]);
    __m128d a73_12 = _mm_loadu_pd(&A[931]);
    c73_12 = _mm_add_pd(c73_12, _mm_mul_pd(a73_12, b73));
    _mm_storeu_pd(&C[(l_n*88)+71], c73_12);
#endif
    __m128d c73_14 = _mm_load_sd(&C[(l_n*88)+73]);
    __m128d a73_14 = _mm_load_sd(&A[933]);
#if defined(__SSE3__) && defined(__AVX__)
    c73_14 = _mm_add_sd(c73_14, _mm_mul_sd(a73_14, _mm256_castpd256_pd128(b73)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c73_14 = _mm_add_sd(c73_14, _mm_mul_sd(a73_14, b73));
#endif
    _mm_store_sd(&C[(l_n*88)+73], c73_14);
#else
    C[(l_n*88)+20] += A[919] * B[(l_n*88)+73];
    C[(l_n*88)+21] += A[920] * B[(l_n*88)+73];
    C[(l_n*88)+22] += A[921] * B[(l_n*88)+73];
    C[(l_n*88)+23] += A[922] * B[(l_n*88)+73];
    C[(l_n*88)+24] += A[923] * B[(l_n*88)+73];
    C[(l_n*88)+41] += A[924] * B[(l_n*88)+73];
    C[(l_n*88)+42] += A[925] * B[(l_n*88)+73];
    C[(l_n*88)+43] += A[926] * B[(l_n*88)+73];
    C[(l_n*88)+44] += A[927] * B[(l_n*88)+73];
    C[(l_n*88)+45] += A[928] * B[(l_n*88)+73];
    C[(l_n*88)+69] += A[929] * B[(l_n*88)+73];
    C[(l_n*88)+70] += A[930] * B[(l_n*88)+73];
    C[(l_n*88)+71] += A[931] * B[(l_n*88)+73];
    C[(l_n*88)+72] += A[932] * B[(l_n*88)+73];
    C[(l_n*88)+73] += A[933] * B[(l_n*88)+73];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b74 = _mm256_broadcast_sd(&B[(l_n*88)+74]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b74 = _mm_loaddup_pd(&B[(l_n*88)+74]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c74_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a74_0 = _mm256_loadu_pd(&A[934]);
    c74_0 = _mm256_add_pd(c74_0, _mm256_mul_pd(a74_0, b74));
    _mm256_storeu_pd(&C[(l_n*88)+10], c74_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c74_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a74_0 = _mm_loadu_pd(&A[934]);
    c74_0 = _mm_add_pd(c74_0, _mm_mul_pd(a74_0, b74));
    _mm_storeu_pd(&C[(l_n*88)+10], c74_0);
    __m128d c74_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a74_2 = _mm_loadu_pd(&A[936]);
    c74_2 = _mm_add_pd(c74_2, _mm_mul_pd(a74_2, b74));
    _mm_storeu_pd(&C[(l_n*88)+12], c74_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c74_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a74_4 = _mm256_loadu_pd(&A[938]);
    c74_4 = _mm256_add_pd(c74_4, _mm256_mul_pd(a74_4, b74));
    _mm256_storeu_pd(&C[(l_n*88)+25], c74_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c74_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a74_4 = _mm_loadu_pd(&A[938]);
    c74_4 = _mm_add_pd(c74_4, _mm_mul_pd(a74_4, b74));
    _mm_storeu_pd(&C[(l_n*88)+25], c74_4);
    __m128d c74_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a74_6 = _mm_loadu_pd(&A[940]);
    c74_6 = _mm_add_pd(c74_6, _mm_mul_pd(a74_6, b74));
    _mm_storeu_pd(&C[(l_n*88)+27], c74_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c74_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a74_8 = _mm256_loadu_pd(&A[942]);
    c74_8 = _mm256_add_pd(c74_8, _mm256_mul_pd(a74_8, b74));
    _mm256_storeu_pd(&C[(l_n*88)+46], c74_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c74_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a74_8 = _mm_loadu_pd(&A[942]);
    c74_8 = _mm_add_pd(c74_8, _mm_mul_pd(a74_8, b74));
    _mm_storeu_pd(&C[(l_n*88)+46], c74_8);
    __m128d c74_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a74_10 = _mm_loadu_pd(&A[944]);
    c74_10 = _mm_add_pd(c74_10, _mm_mul_pd(a74_10, b74));
    _mm_storeu_pd(&C[(l_n*88)+48], c74_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c74_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a74_12 = _mm256_loadu_pd(&A[946]);
    c74_12 = _mm256_add_pd(c74_12, _mm256_mul_pd(a74_12, b74));
    _mm256_storeu_pd(&C[(l_n*88)+74], c74_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c74_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a74_12 = _mm_loadu_pd(&A[946]);
    c74_12 = _mm_add_pd(c74_12, _mm_mul_pd(a74_12, b74));
    _mm_storeu_pd(&C[(l_n*88)+74], c74_12);
    __m128d c74_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a74_14 = _mm_loadu_pd(&A[948]);
    c74_14 = _mm_add_pd(c74_14, _mm_mul_pd(a74_14, b74));
    _mm_storeu_pd(&C[(l_n*88)+76], c74_14);
#endif
#else
    C[(l_n*88)+10] += A[934] * B[(l_n*88)+74];
    C[(l_n*88)+11] += A[935] * B[(l_n*88)+74];
    C[(l_n*88)+12] += A[936] * B[(l_n*88)+74];
    C[(l_n*88)+13] += A[937] * B[(l_n*88)+74];
    C[(l_n*88)+25] += A[938] * B[(l_n*88)+74];
    C[(l_n*88)+26] += A[939] * B[(l_n*88)+74];
    C[(l_n*88)+27] += A[940] * B[(l_n*88)+74];
    C[(l_n*88)+28] += A[941] * B[(l_n*88)+74];
    C[(l_n*88)+46] += A[942] * B[(l_n*88)+74];
    C[(l_n*88)+47] += A[943] * B[(l_n*88)+74];
    C[(l_n*88)+48] += A[944] * B[(l_n*88)+74];
    C[(l_n*88)+49] += A[945] * B[(l_n*88)+74];
    C[(l_n*88)+74] += A[946] * B[(l_n*88)+74];
    C[(l_n*88)+75] += A[947] * B[(l_n*88)+74];
    C[(l_n*88)+76] += A[948] * B[(l_n*88)+74];
    C[(l_n*88)+77] += A[949] * B[(l_n*88)+74];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b75 = _mm256_broadcast_sd(&B[(l_n*88)+75]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b75 = _mm_loaddup_pd(&B[(l_n*88)+75]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c75_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a75_0 = _mm256_loadu_pd(&A[950]);
    c75_0 = _mm256_add_pd(c75_0, _mm256_mul_pd(a75_0, b75));
    _mm256_storeu_pd(&C[(l_n*88)+10], c75_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c75_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a75_0 = _mm_loadu_pd(&A[950]);
    c75_0 = _mm_add_pd(c75_0, _mm_mul_pd(a75_0, b75));
    _mm_storeu_pd(&C[(l_n*88)+10], c75_0);
    __m128d c75_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a75_2 = _mm_loadu_pd(&A[952]);
    c75_2 = _mm_add_pd(c75_2, _mm_mul_pd(a75_2, b75));
    _mm_storeu_pd(&C[(l_n*88)+12], c75_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c75_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a75_4 = _mm256_loadu_pd(&A[954]);
    c75_4 = _mm256_add_pd(c75_4, _mm256_mul_pd(a75_4, b75));
    _mm256_storeu_pd(&C[(l_n*88)+25], c75_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c75_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a75_4 = _mm_loadu_pd(&A[954]);
    c75_4 = _mm_add_pd(c75_4, _mm_mul_pd(a75_4, b75));
    _mm_storeu_pd(&C[(l_n*88)+25], c75_4);
    __m128d c75_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a75_6 = _mm_loadu_pd(&A[956]);
    c75_6 = _mm_add_pd(c75_6, _mm_mul_pd(a75_6, b75));
    _mm_storeu_pd(&C[(l_n*88)+27], c75_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c75_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a75_8 = _mm256_loadu_pd(&A[958]);
    c75_8 = _mm256_add_pd(c75_8, _mm256_mul_pd(a75_8, b75));
    _mm256_storeu_pd(&C[(l_n*88)+46], c75_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c75_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a75_8 = _mm_loadu_pd(&A[958]);
    c75_8 = _mm_add_pd(c75_8, _mm_mul_pd(a75_8, b75));
    _mm_storeu_pd(&C[(l_n*88)+46], c75_8);
    __m128d c75_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a75_10 = _mm_loadu_pd(&A[960]);
    c75_10 = _mm_add_pd(c75_10, _mm_mul_pd(a75_10, b75));
    _mm_storeu_pd(&C[(l_n*88)+48], c75_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c75_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a75_12 = _mm256_loadu_pd(&A[962]);
    c75_12 = _mm256_add_pd(c75_12, _mm256_mul_pd(a75_12, b75));
    _mm256_storeu_pd(&C[(l_n*88)+74], c75_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c75_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a75_12 = _mm_loadu_pd(&A[962]);
    c75_12 = _mm_add_pd(c75_12, _mm_mul_pd(a75_12, b75));
    _mm_storeu_pd(&C[(l_n*88)+74], c75_12);
    __m128d c75_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a75_14 = _mm_loadu_pd(&A[964]);
    c75_14 = _mm_add_pd(c75_14, _mm_mul_pd(a75_14, b75));
    _mm_storeu_pd(&C[(l_n*88)+76], c75_14);
#endif
#else
    C[(l_n*88)+10] += A[950] * B[(l_n*88)+75];
    C[(l_n*88)+11] += A[951] * B[(l_n*88)+75];
    C[(l_n*88)+12] += A[952] * B[(l_n*88)+75];
    C[(l_n*88)+13] += A[953] * B[(l_n*88)+75];
    C[(l_n*88)+25] += A[954] * B[(l_n*88)+75];
    C[(l_n*88)+26] += A[955] * B[(l_n*88)+75];
    C[(l_n*88)+27] += A[956] * B[(l_n*88)+75];
    C[(l_n*88)+28] += A[957] * B[(l_n*88)+75];
    C[(l_n*88)+46] += A[958] * B[(l_n*88)+75];
    C[(l_n*88)+47] += A[959] * B[(l_n*88)+75];
    C[(l_n*88)+48] += A[960] * B[(l_n*88)+75];
    C[(l_n*88)+49] += A[961] * B[(l_n*88)+75];
    C[(l_n*88)+74] += A[962] * B[(l_n*88)+75];
    C[(l_n*88)+75] += A[963] * B[(l_n*88)+75];
    C[(l_n*88)+76] += A[964] * B[(l_n*88)+75];
    C[(l_n*88)+77] += A[965] * B[(l_n*88)+75];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b76 = _mm256_broadcast_sd(&B[(l_n*88)+76]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b76 = _mm_loaddup_pd(&B[(l_n*88)+76]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c76_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a76_0 = _mm256_loadu_pd(&A[966]);
    c76_0 = _mm256_add_pd(c76_0, _mm256_mul_pd(a76_0, b76));
    _mm256_storeu_pd(&C[(l_n*88)+10], c76_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c76_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a76_0 = _mm_loadu_pd(&A[966]);
    c76_0 = _mm_add_pd(c76_0, _mm_mul_pd(a76_0, b76));
    _mm_storeu_pd(&C[(l_n*88)+10], c76_0);
    __m128d c76_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a76_2 = _mm_loadu_pd(&A[968]);
    c76_2 = _mm_add_pd(c76_2, _mm_mul_pd(a76_2, b76));
    _mm_storeu_pd(&C[(l_n*88)+12], c76_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c76_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a76_4 = _mm256_loadu_pd(&A[970]);
    c76_4 = _mm256_add_pd(c76_4, _mm256_mul_pd(a76_4, b76));
    _mm256_storeu_pd(&C[(l_n*88)+25], c76_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c76_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a76_4 = _mm_loadu_pd(&A[970]);
    c76_4 = _mm_add_pd(c76_4, _mm_mul_pd(a76_4, b76));
    _mm_storeu_pd(&C[(l_n*88)+25], c76_4);
    __m128d c76_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a76_6 = _mm_loadu_pd(&A[972]);
    c76_6 = _mm_add_pd(c76_6, _mm_mul_pd(a76_6, b76));
    _mm_storeu_pd(&C[(l_n*88)+27], c76_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c76_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a76_8 = _mm256_loadu_pd(&A[974]);
    c76_8 = _mm256_add_pd(c76_8, _mm256_mul_pd(a76_8, b76));
    _mm256_storeu_pd(&C[(l_n*88)+46], c76_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c76_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a76_8 = _mm_loadu_pd(&A[974]);
    c76_8 = _mm_add_pd(c76_8, _mm_mul_pd(a76_8, b76));
    _mm_storeu_pd(&C[(l_n*88)+46], c76_8);
    __m128d c76_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a76_10 = _mm_loadu_pd(&A[976]);
    c76_10 = _mm_add_pd(c76_10, _mm_mul_pd(a76_10, b76));
    _mm_storeu_pd(&C[(l_n*88)+48], c76_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c76_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a76_12 = _mm256_loadu_pd(&A[978]);
    c76_12 = _mm256_add_pd(c76_12, _mm256_mul_pd(a76_12, b76));
    _mm256_storeu_pd(&C[(l_n*88)+74], c76_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c76_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a76_12 = _mm_loadu_pd(&A[978]);
    c76_12 = _mm_add_pd(c76_12, _mm_mul_pd(a76_12, b76));
    _mm_storeu_pd(&C[(l_n*88)+74], c76_12);
    __m128d c76_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a76_14 = _mm_loadu_pd(&A[980]);
    c76_14 = _mm_add_pd(c76_14, _mm_mul_pd(a76_14, b76));
    _mm_storeu_pd(&C[(l_n*88)+76], c76_14);
#endif
#else
    C[(l_n*88)+10] += A[966] * B[(l_n*88)+76];
    C[(l_n*88)+11] += A[967] * B[(l_n*88)+76];
    C[(l_n*88)+12] += A[968] * B[(l_n*88)+76];
    C[(l_n*88)+13] += A[969] * B[(l_n*88)+76];
    C[(l_n*88)+25] += A[970] * B[(l_n*88)+76];
    C[(l_n*88)+26] += A[971] * B[(l_n*88)+76];
    C[(l_n*88)+27] += A[972] * B[(l_n*88)+76];
    C[(l_n*88)+28] += A[973] * B[(l_n*88)+76];
    C[(l_n*88)+46] += A[974] * B[(l_n*88)+76];
    C[(l_n*88)+47] += A[975] * B[(l_n*88)+76];
    C[(l_n*88)+48] += A[976] * B[(l_n*88)+76];
    C[(l_n*88)+49] += A[977] * B[(l_n*88)+76];
    C[(l_n*88)+74] += A[978] * B[(l_n*88)+76];
    C[(l_n*88)+75] += A[979] * B[(l_n*88)+76];
    C[(l_n*88)+76] += A[980] * B[(l_n*88)+76];
    C[(l_n*88)+77] += A[981] * B[(l_n*88)+76];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b77 = _mm256_broadcast_sd(&B[(l_n*88)+77]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b77 = _mm_loaddup_pd(&B[(l_n*88)+77]);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c77_0 = _mm256_loadu_pd(&C[(l_n*88)+10]);
    __m256d a77_0 = _mm256_loadu_pd(&A[982]);
    c77_0 = _mm256_add_pd(c77_0, _mm256_mul_pd(a77_0, b77));
    _mm256_storeu_pd(&C[(l_n*88)+10], c77_0);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c77_0 = _mm_loadu_pd(&C[(l_n*88)+10]);
    __m128d a77_0 = _mm_loadu_pd(&A[982]);
    c77_0 = _mm_add_pd(c77_0, _mm_mul_pd(a77_0, b77));
    _mm_storeu_pd(&C[(l_n*88)+10], c77_0);
    __m128d c77_2 = _mm_loadu_pd(&C[(l_n*88)+12]);
    __m128d a77_2 = _mm_loadu_pd(&A[984]);
    c77_2 = _mm_add_pd(c77_2, _mm_mul_pd(a77_2, b77));
    _mm_storeu_pd(&C[(l_n*88)+12], c77_2);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c77_4 = _mm256_loadu_pd(&C[(l_n*88)+25]);
    __m256d a77_4 = _mm256_loadu_pd(&A[986]);
    c77_4 = _mm256_add_pd(c77_4, _mm256_mul_pd(a77_4, b77));
    _mm256_storeu_pd(&C[(l_n*88)+25], c77_4);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c77_4 = _mm_loadu_pd(&C[(l_n*88)+25]);
    __m128d a77_4 = _mm_loadu_pd(&A[986]);
    c77_4 = _mm_add_pd(c77_4, _mm_mul_pd(a77_4, b77));
    _mm_storeu_pd(&C[(l_n*88)+25], c77_4);
    __m128d c77_6 = _mm_loadu_pd(&C[(l_n*88)+27]);
    __m128d a77_6 = _mm_loadu_pd(&A[988]);
    c77_6 = _mm_add_pd(c77_6, _mm_mul_pd(a77_6, b77));
    _mm_storeu_pd(&C[(l_n*88)+27], c77_6);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c77_8 = _mm256_loadu_pd(&C[(l_n*88)+46]);
    __m256d a77_8 = _mm256_loadu_pd(&A[990]);
    c77_8 = _mm256_add_pd(c77_8, _mm256_mul_pd(a77_8, b77));
    _mm256_storeu_pd(&C[(l_n*88)+46], c77_8);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c77_8 = _mm_loadu_pd(&C[(l_n*88)+46]);
    __m128d a77_8 = _mm_loadu_pd(&A[990]);
    c77_8 = _mm_add_pd(c77_8, _mm_mul_pd(a77_8, b77));
    _mm_storeu_pd(&C[(l_n*88)+46], c77_8);
    __m128d c77_10 = _mm_loadu_pd(&C[(l_n*88)+48]);
    __m128d a77_10 = _mm_loadu_pd(&A[992]);
    c77_10 = _mm_add_pd(c77_10, _mm_mul_pd(a77_10, b77));
    _mm_storeu_pd(&C[(l_n*88)+48], c77_10);
#endif
#if defined(__SSE3__) && defined(__AVX__)
    __m256d c77_12 = _mm256_loadu_pd(&C[(l_n*88)+74]);
    __m256d a77_12 = _mm256_loadu_pd(&A[994]);
    c77_12 = _mm256_add_pd(c77_12, _mm256_mul_pd(a77_12, b77));
    _mm256_storeu_pd(&C[(l_n*88)+74], c77_12);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d c77_12 = _mm_loadu_pd(&C[(l_n*88)+74]);
    __m128d a77_12 = _mm_loadu_pd(&A[994]);
    c77_12 = _mm_add_pd(c77_12, _mm_mul_pd(a77_12, b77));
    _mm_storeu_pd(&C[(l_n*88)+74], c77_12);
    __m128d c77_14 = _mm_loadu_pd(&C[(l_n*88)+76]);
    __m128d a77_14 = _mm_loadu_pd(&A[996]);
    c77_14 = _mm_add_pd(c77_14, _mm_mul_pd(a77_14, b77));
    _mm_storeu_pd(&C[(l_n*88)+76], c77_14);
#endif
#else
    C[(l_n*88)+10] += A[982] * B[(l_n*88)+77];
    C[(l_n*88)+11] += A[983] * B[(l_n*88)+77];
    C[(l_n*88)+12] += A[984] * B[(l_n*88)+77];
    C[(l_n*88)+13] += A[985] * B[(l_n*88)+77];
    C[(l_n*88)+25] += A[986] * B[(l_n*88)+77];
    C[(l_n*88)+26] += A[987] * B[(l_n*88)+77];
    C[(l_n*88)+27] += A[988] * B[(l_n*88)+77];
    C[(l_n*88)+28] += A[989] * B[(l_n*88)+77];
    C[(l_n*88)+46] += A[990] * B[(l_n*88)+77];
    C[(l_n*88)+47] += A[991] * B[(l_n*88)+77];
    C[(l_n*88)+48] += A[992] * B[(l_n*88)+77];
    C[(l_n*88)+49] += A[993] * B[(l_n*88)+77];
    C[(l_n*88)+74] += A[994] * B[(l_n*88)+77];
    C[(l_n*88)+75] += A[995] * B[(l_n*88)+77];
    C[(l_n*88)+76] += A[996] * B[(l_n*88)+77];
    C[(l_n*88)+77] += A[997] * B[(l_n*88)+77];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b78 = _mm256_broadcast_sd(&B[(l_n*88)+78]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b78 = _mm_loaddup_pd(&B[(l_n*88)+78]);
#endif
    __m128d c78_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a78_0 = _mm_loadu_pd(&A[998]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_0 = _mm_add_pd(c78_0, _mm_mul_pd(a78_0, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_0 = _mm_add_pd(c78_0, _mm_mul_pd(a78_0, b78));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c78_0);
    __m128d c78_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a78_2 = _mm_load_sd(&A[1000]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_2 = _mm_add_sd(c78_2, _mm_mul_sd(a78_2, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_2 = _mm_add_sd(c78_2, _mm_mul_sd(a78_2, b78));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c78_2);
    __m128d c78_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a78_3 = _mm_loadu_pd(&A[1001]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_3 = _mm_add_pd(c78_3, _mm_mul_pd(a78_3, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_3 = _mm_add_pd(c78_3, _mm_mul_pd(a78_3, b78));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c78_3);
    __m128d c78_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a78_5 = _mm_load_sd(&A[1003]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_5 = _mm_add_sd(c78_5, _mm_mul_sd(a78_5, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_5 = _mm_add_sd(c78_5, _mm_mul_sd(a78_5, b78));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c78_5);
    __m128d c78_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a78_6 = _mm_loadu_pd(&A[1004]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_6 = _mm_add_pd(c78_6, _mm_mul_pd(a78_6, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_6 = _mm_add_pd(c78_6, _mm_mul_pd(a78_6, b78));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c78_6);
    __m128d c78_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a78_8 = _mm_load_sd(&A[1006]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_8 = _mm_add_sd(c78_8, _mm_mul_sd(a78_8, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_8 = _mm_add_sd(c78_8, _mm_mul_sd(a78_8, b78));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c78_8);
    __m128d c78_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a78_9 = _mm_loadu_pd(&A[1007]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_9 = _mm_add_pd(c78_9, _mm_mul_pd(a78_9, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_9 = _mm_add_pd(c78_9, _mm_mul_pd(a78_9, b78));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c78_9);
    __m128d c78_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a78_11 = _mm_load_sd(&A[1009]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_11 = _mm_add_sd(c78_11, _mm_mul_sd(a78_11, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_11 = _mm_add_sd(c78_11, _mm_mul_sd(a78_11, b78));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c78_11);
    __m128d c78_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a78_12 = _mm_loadu_pd(&A[1010]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_12 = _mm_add_pd(c78_12, _mm_mul_pd(a78_12, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_12 = _mm_add_pd(c78_12, _mm_mul_pd(a78_12, b78));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c78_12);
    __m128d c78_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a78_14 = _mm_load_sd(&A[1012]);
#if defined(__SSE3__) && defined(__AVX__)
    c78_14 = _mm_add_sd(c78_14, _mm_mul_sd(a78_14, _mm256_castpd256_pd128(b78)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c78_14 = _mm_add_sd(c78_14, _mm_mul_sd(a78_14, b78));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c78_14);
#else
    C[(l_n*88)+4] += A[998] * B[(l_n*88)+78];
    C[(l_n*88)+5] += A[999] * B[(l_n*88)+78];
    C[(l_n*88)+6] += A[1000] * B[(l_n*88)+78];
    C[(l_n*88)+14] += A[1001] * B[(l_n*88)+78];
    C[(l_n*88)+15] += A[1002] * B[(l_n*88)+78];
    C[(l_n*88)+16] += A[1003] * B[(l_n*88)+78];
    C[(l_n*88)+29] += A[1004] * B[(l_n*88)+78];
    C[(l_n*88)+30] += A[1005] * B[(l_n*88)+78];
    C[(l_n*88)+31] += A[1006] * B[(l_n*88)+78];
    C[(l_n*88)+50] += A[1007] * B[(l_n*88)+78];
    C[(l_n*88)+51] += A[1008] * B[(l_n*88)+78];
    C[(l_n*88)+52] += A[1009] * B[(l_n*88)+78];
    C[(l_n*88)+78] += A[1010] * B[(l_n*88)+78];
    C[(l_n*88)+79] += A[1011] * B[(l_n*88)+78];
    C[(l_n*88)+80] += A[1012] * B[(l_n*88)+78];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b79 = _mm256_broadcast_sd(&B[(l_n*88)+79]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b79 = _mm_loaddup_pd(&B[(l_n*88)+79]);
#endif
    __m128d c79_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a79_0 = _mm_loadu_pd(&A[1013]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_0 = _mm_add_pd(c79_0, _mm_mul_pd(a79_0, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_0 = _mm_add_pd(c79_0, _mm_mul_pd(a79_0, b79));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c79_0);
    __m128d c79_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a79_2 = _mm_load_sd(&A[1015]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_2 = _mm_add_sd(c79_2, _mm_mul_sd(a79_2, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_2 = _mm_add_sd(c79_2, _mm_mul_sd(a79_2, b79));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c79_2);
    __m128d c79_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a79_3 = _mm_loadu_pd(&A[1016]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_3 = _mm_add_pd(c79_3, _mm_mul_pd(a79_3, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_3 = _mm_add_pd(c79_3, _mm_mul_pd(a79_3, b79));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c79_3);
    __m128d c79_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a79_5 = _mm_load_sd(&A[1018]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_5 = _mm_add_sd(c79_5, _mm_mul_sd(a79_5, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_5 = _mm_add_sd(c79_5, _mm_mul_sd(a79_5, b79));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c79_5);
    __m128d c79_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a79_6 = _mm_loadu_pd(&A[1019]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_6 = _mm_add_pd(c79_6, _mm_mul_pd(a79_6, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_6 = _mm_add_pd(c79_6, _mm_mul_pd(a79_6, b79));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c79_6);
    __m128d c79_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a79_8 = _mm_load_sd(&A[1021]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_8 = _mm_add_sd(c79_8, _mm_mul_sd(a79_8, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_8 = _mm_add_sd(c79_8, _mm_mul_sd(a79_8, b79));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c79_8);
    __m128d c79_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a79_9 = _mm_loadu_pd(&A[1022]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_9 = _mm_add_pd(c79_9, _mm_mul_pd(a79_9, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_9 = _mm_add_pd(c79_9, _mm_mul_pd(a79_9, b79));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c79_9);
    __m128d c79_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a79_11 = _mm_load_sd(&A[1024]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_11 = _mm_add_sd(c79_11, _mm_mul_sd(a79_11, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_11 = _mm_add_sd(c79_11, _mm_mul_sd(a79_11, b79));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c79_11);
    __m128d c79_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a79_12 = _mm_loadu_pd(&A[1025]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_12 = _mm_add_pd(c79_12, _mm_mul_pd(a79_12, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_12 = _mm_add_pd(c79_12, _mm_mul_pd(a79_12, b79));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c79_12);
    __m128d c79_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a79_14 = _mm_load_sd(&A[1027]);
#if defined(__SSE3__) && defined(__AVX__)
    c79_14 = _mm_add_sd(c79_14, _mm_mul_sd(a79_14, _mm256_castpd256_pd128(b79)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c79_14 = _mm_add_sd(c79_14, _mm_mul_sd(a79_14, b79));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c79_14);
#else
    C[(l_n*88)+4] += A[1013] * B[(l_n*88)+79];
    C[(l_n*88)+5] += A[1014] * B[(l_n*88)+79];
    C[(l_n*88)+6] += A[1015] * B[(l_n*88)+79];
    C[(l_n*88)+14] += A[1016] * B[(l_n*88)+79];
    C[(l_n*88)+15] += A[1017] * B[(l_n*88)+79];
    C[(l_n*88)+16] += A[1018] * B[(l_n*88)+79];
    C[(l_n*88)+29] += A[1019] * B[(l_n*88)+79];
    C[(l_n*88)+30] += A[1020] * B[(l_n*88)+79];
    C[(l_n*88)+31] += A[1021] * B[(l_n*88)+79];
    C[(l_n*88)+50] += A[1022] * B[(l_n*88)+79];
    C[(l_n*88)+51] += A[1023] * B[(l_n*88)+79];
    C[(l_n*88)+52] += A[1024] * B[(l_n*88)+79];
    C[(l_n*88)+78] += A[1025] * B[(l_n*88)+79];
    C[(l_n*88)+79] += A[1026] * B[(l_n*88)+79];
    C[(l_n*88)+80] += A[1027] * B[(l_n*88)+79];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b80 = _mm256_broadcast_sd(&B[(l_n*88)+80]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b80 = _mm_loaddup_pd(&B[(l_n*88)+80]);
#endif
    __m128d c80_0 = _mm_loadu_pd(&C[(l_n*88)+4]);
    __m128d a80_0 = _mm_loadu_pd(&A[1028]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_0 = _mm_add_pd(c80_0, _mm_mul_pd(a80_0, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_0 = _mm_add_pd(c80_0, _mm_mul_pd(a80_0, b80));
#endif
    _mm_storeu_pd(&C[(l_n*88)+4], c80_0);
    __m128d c80_2 = _mm_load_sd(&C[(l_n*88)+6]);
    __m128d a80_2 = _mm_load_sd(&A[1030]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_2 = _mm_add_sd(c80_2, _mm_mul_sd(a80_2, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_2 = _mm_add_sd(c80_2, _mm_mul_sd(a80_2, b80));
#endif
    _mm_store_sd(&C[(l_n*88)+6], c80_2);
    __m128d c80_3 = _mm_loadu_pd(&C[(l_n*88)+14]);
    __m128d a80_3 = _mm_loadu_pd(&A[1031]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_3 = _mm_add_pd(c80_3, _mm_mul_pd(a80_3, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_3 = _mm_add_pd(c80_3, _mm_mul_pd(a80_3, b80));
#endif
    _mm_storeu_pd(&C[(l_n*88)+14], c80_3);
    __m128d c80_5 = _mm_load_sd(&C[(l_n*88)+16]);
    __m128d a80_5 = _mm_load_sd(&A[1033]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_5 = _mm_add_sd(c80_5, _mm_mul_sd(a80_5, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_5 = _mm_add_sd(c80_5, _mm_mul_sd(a80_5, b80));
#endif
    _mm_store_sd(&C[(l_n*88)+16], c80_5);
    __m128d c80_6 = _mm_loadu_pd(&C[(l_n*88)+29]);
    __m128d a80_6 = _mm_loadu_pd(&A[1034]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_6 = _mm_add_pd(c80_6, _mm_mul_pd(a80_6, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_6 = _mm_add_pd(c80_6, _mm_mul_pd(a80_6, b80));
#endif
    _mm_storeu_pd(&C[(l_n*88)+29], c80_6);
    __m128d c80_8 = _mm_load_sd(&C[(l_n*88)+31]);
    __m128d a80_8 = _mm_load_sd(&A[1036]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_8 = _mm_add_sd(c80_8, _mm_mul_sd(a80_8, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_8 = _mm_add_sd(c80_8, _mm_mul_sd(a80_8, b80));
#endif
    _mm_store_sd(&C[(l_n*88)+31], c80_8);
    __m128d c80_9 = _mm_loadu_pd(&C[(l_n*88)+50]);
    __m128d a80_9 = _mm_loadu_pd(&A[1037]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_9 = _mm_add_pd(c80_9, _mm_mul_pd(a80_9, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_9 = _mm_add_pd(c80_9, _mm_mul_pd(a80_9, b80));
#endif
    _mm_storeu_pd(&C[(l_n*88)+50], c80_9);
    __m128d c80_11 = _mm_load_sd(&C[(l_n*88)+52]);
    __m128d a80_11 = _mm_load_sd(&A[1039]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_11 = _mm_add_sd(c80_11, _mm_mul_sd(a80_11, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_11 = _mm_add_sd(c80_11, _mm_mul_sd(a80_11, b80));
#endif
    _mm_store_sd(&C[(l_n*88)+52], c80_11);
    __m128d c80_12 = _mm_loadu_pd(&C[(l_n*88)+78]);
    __m128d a80_12 = _mm_loadu_pd(&A[1040]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_12 = _mm_add_pd(c80_12, _mm_mul_pd(a80_12, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_12 = _mm_add_pd(c80_12, _mm_mul_pd(a80_12, b80));
#endif
    _mm_storeu_pd(&C[(l_n*88)+78], c80_12);
    __m128d c80_14 = _mm_load_sd(&C[(l_n*88)+80]);
    __m128d a80_14 = _mm_load_sd(&A[1042]);
#if defined(__SSE3__) && defined(__AVX__)
    c80_14 = _mm_add_sd(c80_14, _mm_mul_sd(a80_14, _mm256_castpd256_pd128(b80)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c80_14 = _mm_add_sd(c80_14, _mm_mul_sd(a80_14, b80));
#endif
    _mm_store_sd(&C[(l_n*88)+80], c80_14);
#else
    C[(l_n*88)+4] += A[1028] * B[(l_n*88)+80];
    C[(l_n*88)+5] += A[1029] * B[(l_n*88)+80];
    C[(l_n*88)+6] += A[1030] * B[(l_n*88)+80];
    C[(l_n*88)+14] += A[1031] * B[(l_n*88)+80];
    C[(l_n*88)+15] += A[1032] * B[(l_n*88)+80];
    C[(l_n*88)+16] += A[1033] * B[(l_n*88)+80];
    C[(l_n*88)+29] += A[1034] * B[(l_n*88)+80];
    C[(l_n*88)+30] += A[1035] * B[(l_n*88)+80];
    C[(l_n*88)+31] += A[1036] * B[(l_n*88)+80];
    C[(l_n*88)+50] += A[1037] * B[(l_n*88)+80];
    C[(l_n*88)+51] += A[1038] * B[(l_n*88)+80];
    C[(l_n*88)+52] += A[1039] * B[(l_n*88)+80];
    C[(l_n*88)+78] += A[1040] * B[(l_n*88)+80];
    C[(l_n*88)+79] += A[1041] * B[(l_n*88)+80];
    C[(l_n*88)+80] += A[1042] * B[(l_n*88)+80];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b81 = _mm256_broadcast_sd(&B[(l_n*88)+81]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b81 = _mm_loaddup_pd(&B[(l_n*88)+81]);
#endif
    __m128d c81_0 = _mm_loadu_pd(&C[(l_n*88)+1]);
    __m128d a81_0 = _mm_loadu_pd(&A[1043]);
#if defined(__SSE3__) && defined(__AVX__)
    c81_0 = _mm_add_pd(c81_0, _mm_mul_pd(a81_0, _mm256_castpd256_pd128(b81)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c81_0 = _mm_add_pd(c81_0, _mm_mul_pd(a81_0, b81));
#endif
    _mm_storeu_pd(&C[(l_n*88)+1], c81_0);
    __m128d c81_2 = _mm_loadu_pd(&C[(l_n*88)+7]);
    __m128d a81_2 = _mm_loadu_pd(&A[1045]);
#if defined(__SSE3__) && defined(__AVX__)
    c81_2 = _mm_add_pd(c81_2, _mm_mul_pd(a81_2, _mm256_castpd256_pd128(b81)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c81_2 = _mm_add_pd(c81_2, _mm_mul_pd(a81_2, b81));
#endif
    _mm_storeu_pd(&C[(l_n*88)+7], c81_2);
    __m128d c81_4 = _mm_loadu_pd(&C[(l_n*88)+17]);
    __m128d a81_4 = _mm_loadu_pd(&A[1047]);
#if defined(__SSE3__) && defined(__AVX__)
    c81_4 = _mm_add_pd(c81_4, _mm_mul_pd(a81_4, _mm256_castpd256_pd128(b81)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c81_4 = _mm_add_pd(c81_4, _mm_mul_pd(a81_4, b81));
#endif
    _mm_storeu_pd(&C[(l_n*88)+17], c81_4);
    __m128d c81_6 = _mm_loadu_pd(&C[(l_n*88)+32]);
    __m128d a81_6 = _mm_loadu_pd(&A[1049]);
#if defined(__SSE3__) && defined(__AVX__)
    c81_6 = _mm_add_pd(c81_6, _mm_mul_pd(a81_6, _mm256_castpd256_pd128(b81)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c81_6 = _mm_add_pd(c81_6, _mm_mul_pd(a81_6, b81));
#endif
    _mm_storeu_pd(&C[(l_n*88)+32], c81_6);
    __m128d c81_8 = _mm_loadu_pd(&C[(l_n*88)+53]);
    __m128d a81_8 = _mm_loadu_pd(&A[1051]);
#if defined(__SSE3__) && defined(__AVX__)
    c81_8 = _mm_add_pd(c81_8, _mm_mul_pd(a81_8, _mm256_castpd256_pd128(b81)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c81_8 = _mm_add_pd(c81_8, _mm_mul_pd(a81_8, b81));
#endif
    _mm_storeu_pd(&C[(l_n*88)+53], c81_8);
    __m128d c81_10 = _mm_loadu_pd(&C[(l_n*88)+81]);
    __m128d a81_10 = _mm_loadu_pd(&A[1053]);
#if defined(__SSE3__) && defined(__AVX__)
    c81_10 = _mm_add_pd(c81_10, _mm_mul_pd(a81_10, _mm256_castpd256_pd128(b81)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c81_10 = _mm_add_pd(c81_10, _mm_mul_pd(a81_10, b81));
#endif
    _mm_storeu_pd(&C[(l_n*88)+81], c81_10);
#else
    C[(l_n*88)+1] += A[1043] * B[(l_n*88)+81];
    C[(l_n*88)+2] += A[1044] * B[(l_n*88)+81];
    C[(l_n*88)+7] += A[1045] * B[(l_n*88)+81];
    C[(l_n*88)+8] += A[1046] * B[(l_n*88)+81];
    C[(l_n*88)+17] += A[1047] * B[(l_n*88)+81];
    C[(l_n*88)+18] += A[1048] * B[(l_n*88)+81];
    C[(l_n*88)+32] += A[1049] * B[(l_n*88)+81];
    C[(l_n*88)+33] += A[1050] * B[(l_n*88)+81];
    C[(l_n*88)+53] += A[1051] * B[(l_n*88)+81];
    C[(l_n*88)+54] += A[1052] * B[(l_n*88)+81];
    C[(l_n*88)+81] += A[1053] * B[(l_n*88)+81];
    C[(l_n*88)+82] += A[1054] * B[(l_n*88)+81];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b82 = _mm256_broadcast_sd(&B[(l_n*88)+82]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b82 = _mm_loaddup_pd(&B[(l_n*88)+82]);
#endif
    __m128d c82_0 = _mm_loadu_pd(&C[(l_n*88)+1]);
    __m128d a82_0 = _mm_loadu_pd(&A[1055]);
#if defined(__SSE3__) && defined(__AVX__)
    c82_0 = _mm_add_pd(c82_0, _mm_mul_pd(a82_0, _mm256_castpd256_pd128(b82)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c82_0 = _mm_add_pd(c82_0, _mm_mul_pd(a82_0, b82));
#endif
    _mm_storeu_pd(&C[(l_n*88)+1], c82_0);
    __m128d c82_2 = _mm_loadu_pd(&C[(l_n*88)+7]);
    __m128d a82_2 = _mm_loadu_pd(&A[1057]);
#if defined(__SSE3__) && defined(__AVX__)
    c82_2 = _mm_add_pd(c82_2, _mm_mul_pd(a82_2, _mm256_castpd256_pd128(b82)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c82_2 = _mm_add_pd(c82_2, _mm_mul_pd(a82_2, b82));
#endif
    _mm_storeu_pd(&C[(l_n*88)+7], c82_2);
    __m128d c82_4 = _mm_loadu_pd(&C[(l_n*88)+17]);
    __m128d a82_4 = _mm_loadu_pd(&A[1059]);
#if defined(__SSE3__) && defined(__AVX__)
    c82_4 = _mm_add_pd(c82_4, _mm_mul_pd(a82_4, _mm256_castpd256_pd128(b82)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c82_4 = _mm_add_pd(c82_4, _mm_mul_pd(a82_4, b82));
#endif
    _mm_storeu_pd(&C[(l_n*88)+17], c82_4);
    __m128d c82_6 = _mm_loadu_pd(&C[(l_n*88)+32]);
    __m128d a82_6 = _mm_loadu_pd(&A[1061]);
#if defined(__SSE3__) && defined(__AVX__)
    c82_6 = _mm_add_pd(c82_6, _mm_mul_pd(a82_6, _mm256_castpd256_pd128(b82)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c82_6 = _mm_add_pd(c82_6, _mm_mul_pd(a82_6, b82));
#endif
    _mm_storeu_pd(&C[(l_n*88)+32], c82_6);
    __m128d c82_8 = _mm_loadu_pd(&C[(l_n*88)+53]);
    __m128d a82_8 = _mm_loadu_pd(&A[1063]);
#if defined(__SSE3__) && defined(__AVX__)
    c82_8 = _mm_add_pd(c82_8, _mm_mul_pd(a82_8, _mm256_castpd256_pd128(b82)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c82_8 = _mm_add_pd(c82_8, _mm_mul_pd(a82_8, b82));
#endif
    _mm_storeu_pd(&C[(l_n*88)+53], c82_8);
    __m128d c82_10 = _mm_loadu_pd(&C[(l_n*88)+81]);
    __m128d a82_10 = _mm_loadu_pd(&A[1065]);
#if defined(__SSE3__) && defined(__AVX__)
    c82_10 = _mm_add_pd(c82_10, _mm_mul_pd(a82_10, _mm256_castpd256_pd128(b82)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c82_10 = _mm_add_pd(c82_10, _mm_mul_pd(a82_10, b82));
#endif
    _mm_storeu_pd(&C[(l_n*88)+81], c82_10);
#else
    C[(l_n*88)+1] += A[1055] * B[(l_n*88)+82];
    C[(l_n*88)+2] += A[1056] * B[(l_n*88)+82];
    C[(l_n*88)+7] += A[1057] * B[(l_n*88)+82];
    C[(l_n*88)+8] += A[1058] * B[(l_n*88)+82];
    C[(l_n*88)+17] += A[1059] * B[(l_n*88)+82];
    C[(l_n*88)+18] += A[1060] * B[(l_n*88)+82];
    C[(l_n*88)+32] += A[1061] * B[(l_n*88)+82];
    C[(l_n*88)+33] += A[1062] * B[(l_n*88)+82];
    C[(l_n*88)+53] += A[1063] * B[(l_n*88)+82];
    C[(l_n*88)+54] += A[1064] * B[(l_n*88)+82];
    C[(l_n*88)+81] += A[1065] * B[(l_n*88)+82];
    C[(l_n*88)+82] += A[1066] * B[(l_n*88)+82];
#endif

#if defined(__SSE3__) || defined(__AVX__)
#if defined(__SSE3__) && defined(__AVX__)
    __m256d b83 = _mm256_broadcast_sd(&B[(l_n*88)+83]);
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    __m128d b83 = _mm_loaddup_pd(&B[(l_n*88)+83]);
#endif
    __m128d c83_0 = _mm_load_sd(&C[(l_n*88)+0]);
    __m128d a83_0 = _mm_load_sd(&A[1067]);
#if defined(__SSE3__) && defined(__AVX__)
    c83_0 = _mm_add_sd(c83_0, _mm_mul_sd(a83_0, _mm256_castpd256_pd128(b83)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c83_0 = _mm_add_sd(c83_0, _mm_mul_sd(a83_0, b83));
#endif
    _mm_store_sd(&C[(l_n*88)+0], c83_0);
    __m128d c83_1 = _mm_load_sd(&C[(l_n*88)+3]);
    __m128d a83_1 = _mm_load_sd(&A[1068]);
#if defined(__SSE3__) && defined(__AVX__)
    c83_1 = _mm_add_sd(c83_1, _mm_mul_sd(a83_1, _mm256_castpd256_pd128(b83)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c83_1 = _mm_add_sd(c83_1, _mm_mul_sd(a83_1, b83));
#endif
    _mm_store_sd(&C[(l_n*88)+3], c83_1);
    __m128d c83_2 = _mm_load_sd(&C[(l_n*88)+9]);
    __m128d a83_2 = _mm_load_sd(&A[1069]);
#if defined(__SSE3__) && defined(__AVX__)
    c83_2 = _mm_add_sd(c83_2, _mm_mul_sd(a83_2, _mm256_castpd256_pd128(b83)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c83_2 = _mm_add_sd(c83_2, _mm_mul_sd(a83_2, b83));
#endif
    _mm_store_sd(&C[(l_n*88)+9], c83_2);
    __m128d c83_3 = _mm_load_sd(&C[(l_n*88)+19]);
    __m128d a83_3 = _mm_load_sd(&A[1070]);
#if defined(__SSE3__) && defined(__AVX__)
    c83_3 = _mm_add_sd(c83_3, _mm_mul_sd(a83_3, _mm256_castpd256_pd128(b83)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c83_3 = _mm_add_sd(c83_3, _mm_mul_sd(a83_3, b83));
#endif
    _mm_store_sd(&C[(l_n*88)+19], c83_3);
    __m128d c83_4 = _mm_load_sd(&C[(l_n*88)+34]);
    __m128d a83_4 = _mm_load_sd(&A[1071]);
#if defined(__SSE3__) && defined(__AVX__)
    c83_4 = _mm_add_sd(c83_4, _mm_mul_sd(a83_4, _mm256_castpd256_pd128(b83)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c83_4 = _mm_add_sd(c83_4, _mm_mul_sd(a83_4, b83));
#endif
    _mm_store_sd(&C[(l_n*88)+34], c83_4);
    __m128d c83_5 = _mm_load_sd(&C[(l_n*88)+55]);
    __m128d a83_5 = _mm_load_sd(&A[1072]);
#if defined(__SSE3__) && defined(__AVX__)
    c83_5 = _mm_add_sd(c83_5, _mm_mul_sd(a83_5, _mm256_castpd256_pd128(b83)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c83_5 = _mm_add_sd(c83_5, _mm_mul_sd(a83_5, b83));
#endif
    _mm_store_sd(&C[(l_n*88)+55], c83_5);
    __m128d c83_6 = _mm_load_sd(&C[(l_n*88)+83]);
    __m128d a83_6 = _mm_load_sd(&A[1073]);
#if defined(__SSE3__) && defined(__AVX__)
    c83_6 = _mm_add_sd(c83_6, _mm_mul_sd(a83_6, _mm256_castpd256_pd128(b83)));
#endif
#if defined(__SSE3__) && !defined(__AVX__)
    c83_6 = _mm_add_sd(c83_6, _mm_mul_sd(a83_6, b83));
#endif
    _mm_store_sd(&C[(l_n*88)+83], c83_6);
#else
    C[(l_n*88)+0] += A[1067] * B[(l_n*88)+83];
    C[(l_n*88)+3] += A[1068] * B[(l_n*88)+83];
    C[(l_n*88)+9] += A[1069] * B[(l_n*88)+83];
    C[(l_n*88)+19] += A[1070] * B[(l_n*88)+83];
    C[(l_n*88)+34] += A[1071] * B[(l_n*88)+83];
    C[(l_n*88)+55] += A[1072] * B[(l_n*88)+83];
    C[(l_n*88)+83] += A[1073] * B[(l_n*88)+83];
#endif

  }

#ifndef NDEBUG
#ifdef _OPENMP
#pragma omp atomic
#endif
libxsmm_num_total_flops += 19332;
#endif
}

#endif
