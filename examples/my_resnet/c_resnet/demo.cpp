
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//
#include <gmp.h>
#define __gmp_const const

#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <math.h>
#include <stdint.h>
using namespace std;
void top(
    ap_fixed<10, 4> v0[2][3][32][32],
    ap_fixed<10, 4> v1[64][3][3][3],
    ap_fixed<10, 4> v2[64],
    ap_fixed<10, 4> v3[64],
    ap_fixed<10, 4> v4[64],
    ap_fixed<10, 4> v5[64],
    ap_fixed<10, 4> v6[64][64][3][3],
    ap_fixed<10, 4> v7[64],
    ap_fixed<10, 4> v8[64],
    ap_fixed<10, 4> v9[64],
    ap_fixed<10, 4> v10[64],
    ap_fixed<10, 4> v11[64][64][3][3],
    ap_fixed<10, 4> v12[64],
    ap_fixed<10, 4> v13[64],
    ap_fixed<10, 4> v14[64],
    ap_fixed<10, 4> v15[64],
    ap_fixed<10, 4> v16[64][64][3][3],
    ap_fixed<10, 4> v17[64],
    ap_fixed<10, 4> v18[64],
    ap_fixed<10, 4> v19[64],
    ap_fixed<10, 4> v20[64],
    ap_fixed<10, 4> v21[64][64][3][3],
    ap_fixed<10, 4> v22[64],
    ap_fixed<10, 4> v23[64],
    ap_fixed<10, 4> v24[64],
    ap_fixed<10, 4> v25[64],
    ap_fixed<10, 4> v26[128][64][3][3],
    ap_fixed<10, 4> v27[128],
    ap_fixed<10, 4> v28[128],
    ap_fixed<10, 4> v29[128],
    ap_fixed<10, 4> v30[128],
    ap_fixed<10, 4> v31[128][128][3][3],
    ap_fixed<10, 4> v32[128],
    ap_fixed<10, 4> v33[128],
    ap_fixed<10, 4> v34[128],
    ap_fixed<10, 4> v35[128],
    ap_fixed<10, 4> v36[128][64][1][1],
    ap_fixed<10, 4> v37[128],
    ap_fixed<10, 4> v38[128],
    ap_fixed<10, 4> v39[128],
    ap_fixed<10, 4> v40[128],
    ap_fixed<10, 4> v41[128][128][3][3],
    ap_fixed<10, 4> v42[128],
    ap_fixed<10, 4> v43[128],
    ap_fixed<10, 4> v44[128],
    ap_fixed<10, 4> v45[128],
    ap_fixed<10, 4> v46[128][128][3][3],
    ap_fixed<10, 4> v47[128],
    ap_fixed<10, 4> v48[128],
    ap_fixed<10, 4> v49[128],
    ap_fixed<10, 4> v50[128],
    ap_fixed<10, 4> v51[256][128][3][3],
    ap_fixed<10, 4> v52[256],
    ap_fixed<10, 4> v53[256],
    ap_fixed<10, 4> v54[256],
    ap_fixed<10, 4> v55[256],
    ap_fixed<10, 4> v56[256][256][3][3],
    ap_fixed<10, 4> v57[256],
    ap_fixed<10, 4> v58[256],
    ap_fixed<10, 4> v59[256],
    ap_fixed<10, 4> v60[256],
    ap_fixed<10, 4> v61[256][128][1][1],
    ap_fixed<10, 4> v62[256],
    ap_fixed<10, 4> v63[256],
    ap_fixed<10, 4> v64[256],
    ap_fixed<10, 4> v65[256],
    ap_fixed<10, 4> v66[256][256][3][3],
    ap_fixed<10, 4> v67[256],
    ap_fixed<10, 4> v68[256],
    ap_fixed<10, 4> v69[256],
    ap_fixed<10, 4> v70[256],
    ap_fixed<10, 4> v71[256][256][3][3],
    ap_fixed<10, 4> v72[256],
    ap_fixed<10, 4> v73[256],
    ap_fixed<10, 4> v74[256],
    ap_fixed<10, 4> v75[256],
    ap_fixed<10, 4> v76[512][256][3][3],
    ap_fixed<10, 4> v77[512],
    ap_fixed<10, 4> v78[512],
    ap_fixed<10, 4> v79[512],
    ap_fixed<10, 4> v80[512],
    ap_fixed<10, 4> v81[512][512][3][3],
    ap_fixed<10, 4> v82[512],
    ap_fixed<10, 4> v83[512],
    ap_fixed<10, 4> v84[512],
    ap_fixed<10, 4> v85[512],
    ap_fixed<10, 4> v86[512][256][1][1],
    ap_fixed<10, 4> v87[512],
    ap_fixed<10, 4> v88[512],
    ap_fixed<10, 4> v89[512],
    ap_fixed<10, 4> v90[512],
    ap_fixed<10, 4> v91[512][512][3][3],
    ap_fixed<10, 4> v92[512],
    ap_fixed<10, 4> v93[512],
    ap_fixed<10, 4> v94[512],
    ap_fixed<10, 4> v95[512],
    ap_fixed<10, 4> v96[512][512][3][3],
    ap_fixed<10, 4> v97[512],
    ap_fixed<10, 4> v98[512],
    ap_fixed<10, 4> v99[512],
    ap_fixed<10, 4> v100[512],
    ap_fixed<10, 4> v101[100][512],
    ap_fixed<10, 4> v102[100],
    ap_fixed<10, 4> v103[2][100])
{ // L28
#pragma HLS array_partition variable = v0 complete dim = 3
#pragma HLS array_partition variable = v0 complete dim = 4

#pragma HLS array_partition variable = v1 complete dim = 3
#pragma HLS array_partition variable = v1 complete dim = 4

#pragma HLS array_partition variable = v6 complete dim = 3
#pragma HLS array_partition variable = v6 complete dim = 4

#pragma HLS array_partition variable = v11 complete dim = 3
#pragma HLS array_partition variable = v11 complete dim = 4

#pragma HLS array_partition variable = v16 complete dim = 3
#pragma HLS array_partition variable = v16 complete dim = 4

#pragma HLS array_partition variable = v21 complete dim = 3
#pragma HLS array_partition variable = v21 complete dim = 4

#pragma HLS array_partition variable = v26 complete dim = 3
#pragma HLS array_partition variable = v26 complete dim = 4

#pragma HLS array_partition variable = v31 complete dim = 3
#pragma HLS array_partition variable = v31 complete dim = 4

#pragma HLS array_partition variable = v41 complete dim = 3
#pragma HLS array_partition variable = v41 complete dim = 4

#pragma HLS array_partition variable = v46 complete dim = 3
#pragma HLS array_partition variable = v46 complete dim = 4

#pragma HLS array_partition variable = v51 complete dim = 3
#pragma HLS array_partition variable = v51 complete dim = 4

#pragma HLS array_partition variable = v56 complete dim = 3
#pragma HLS array_partition variable = v56 complete dim = 4

#pragma HLS array_partition variable = v66 complete dim = 3
#pragma HLS array_partition variable = v66 complete dim = 4

#pragma HLS array_partition variable = v71 complete dim = 3
#pragma HLS array_partition variable = v71 complete dim = 4

#pragma HLS array_partition variable = v76 complete dim = 3
#pragma HLS array_partition variable = v76 complete dim = 4

#pragma HLS array_partition variable = v81 complete dim = 3
#pragma HLS array_partition variable = v81 complete dim = 4

#pragma HLS array_partition variable = v91 complete dim = 3
#pragma HLS array_partition variable = v91 complete dim = 4

#pragma HLS array_partition variable = v96 complete dim = 3
#pragma HLS array_partition variable = v96 complete dim = 4

  ap_fixed<10, 4> conv1_x_0_conv1_pad[2][3][34][34]; // L472
l_conv1_x_0_conv1_pad_i0:
  for (int i0 = 0; i0 < 2; i0++)
  { // L472
  l_i1:
    for (int i1 = 0; i1 < 3; i1++)
    { // L472
    l_i2:
      for (int i2 = 0; i2 < 34; i2++)
      { // L472
      l_i3:
        for (int i3 = 0; i3 < 34; i3++)
        {                                                                              // L472
          ap_int<33> v109 = i2;                                                        // L472
          ap_int<33> v110 = 1;                                                         // L472
          bool v111 = v109 >= v110;                                                    // L472
          bool v112 = 1 & v111;                                                        // L30
          ap_int<33> v113 = 33;                                                        // L472
          bool v114 = v109 < v113;                                                     // L472
          bool v115 = v112 & v114;                                                     // L30
          ap_int<33> v116 = i3;                                                        // L472
          bool v117 = v116 >= v110;                                                    // L472
          bool v118 = v115 & v117;                                                     // L30
          bool v119 = v116 < v113;                                                     // L472
          bool v120 = v118 & v119;                                                     // L30
          ap_fixed<10, 4> v121 = v0[i0][i1][(i2 - 1)][(i3 - 1)];                       // L62
          ap_fixed<10, 4> v122 = 0.000000;                                             // L472
          ap_fixed<10, 4> v123 = v120 ? (ap_fixed<10, 4>)v121 : (ap_fixed<10, 4>)v122; // L127
          conv1_x_0_conv1_pad[i0][i1][i2][i3] = v123;                                  // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv1_x_0_conv1[2][64][32][32];    // L472
  ap_fixed<10, 4> conv1_x_0_conv1_reuse_2[3][3][34]; // L472
#pragma HLS array_partition variable = conv1_x_0_conv1_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv1_x_0_conv1_reuse_3[3][3][3]; // L472
#pragma HLS array_partition variable = conv1_x_0_conv1_reuse_3 complete dim = 3

l_conv1_x_0_conv1_nn:
  for (int nn = 0; nn < 2; nn++)
  { // L472
  l_ff:
    for (int ff = 0; ff < 64; ff++)
    { // L472
    l_yy:
      for (int yy = 0; yy < 34; yy++)
      { // L472
      l_xx:
        for (int xx = 0; xx < 34; xx++)
        { // L472
          for (int v131 = 0; v131 < 3; v131++)
          {                                                               // L472
            ap_fixed<10, 4> v132 = conv1_x_0_conv1_reuse_2[v131][1][xx];  // L472
            conv1_x_0_conv1_reuse_2[v131][0][xx] = v132;                  // L472
            ap_fixed<10, 4> v133 = conv1_x_0_conv1_reuse_2[v131][2][xx];  // L472
            conv1_x_0_conv1_reuse_2[v131][1][xx] = v133;                  // L472
            ap_fixed<10, 4> v134 = conv1_x_0_conv1_pad[nn][v131][yy][xx]; // L472
            conv1_x_0_conv1_reuse_2[v131][2][xx] = v134;                  // L472
          }
          if ((yy - 2) >= 0)
          { // L472
            for (int v135 = 0; v135 < 3; v135++)
            { // L256
              for (int v136 = 0; v136 < 3; v136++)
              {                                                                 // L256
                ap_fixed<10, 4> v137 = conv1_x_0_conv1_reuse_3[v135][v136][1];  // L256
                conv1_x_0_conv1_reuse_3[v135][v136][0] = v137;                  // L256
                ap_fixed<10, 4> v138 = conv1_x_0_conv1_reuse_3[v135][v136][2];  // L256
                conv1_x_0_conv1_reuse_3[v135][v136][1] = v138;                  // L256
                ap_fixed<10, 4> v139 = conv1_x_0_conv1_reuse_2[v135][v136][xx]; // L256
                conv1_x_0_conv1_reuse_3[v135][v136][2] = v139;                  // L256
              }
            }
            if ((xx - 2) >= 0)
            {                           // L256
              ap_fixed<10, 4> sum;      // L256
              ap_fixed<10, 4> v141 = 0; // L472
              sum = v141;               // L472
            l_rc:
              for (int rc = 0; rc < 3; rc++)
              { // L256
              l_ry:
                for (int ry = 0; ry < 3; ry++)
                { // L256
                l_rx:
                  for (int rx = 0; rx < 3; rx++)
                  { // L256
                    if (1)
                    {                                                             // L472
                      ap_fixed<10, 4> v145 = conv1_x_0_conv1_reuse_3[rc][ry][rx]; // L472
                      ap_fixed<10, 4> v146 = v1[ff][rc][ry][rx];                  // L71
                      ap_fixed<20, 8> v147 = v145;                                // L472
                      ap_fixed<20, 8> v148 = v146;                                // L472
                      ap_fixed<20, 8> v149 = v147 * v148;                         // L472
                      ap_fixed<10, 4> v150 = sum;                                 // L256
                      ap_fixed<21, 9> v151 = v149;                                // L472
                      ap_fixed<21, 9> v152 = v150;                                // L472
                      ap_fixed<21, 9> v153 = v151 + v152;                         // L472
                      ap_fixed<10, 4> v154 = v153;                                // L472
                      sum = v154;                                                 // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v155 = sum;                         // L256
              conv1_x_0_conv1[nn][ff][(yy - 2)][(xx - 2)] = v155; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv1_x_0_bn1[2][64][32][32];  // L472
  ap_fixed<10, 4> conv1_x_0_relu[2][64][32][32]; // L472
l_conv1_x_0_relu_i0_1:
  for (int i0_1 = 0; i0_1 < 2; i0_1++)
  { // L472
  l_i1_1:
    for (int i1_1 = 0; i1_1 < 64; i1_1++)
    { // L472
    l_i2_1:
      for (int i2_1 = 0; i2_1 < 32; i2_1++)
      { // L472
      l_i3_1:
        for (int i3_1 = 0; i3_1 < 32; i3_1++)
        {                                                                                 // L472
          ap_fixed<10, 4> v162 = conv1_x_0_conv1[i0_1][i1_1][i2_1][i3_1];                 // L472
          ap_fixed<10, 4> v163 = v4[i1_1];                                                // L75
          ap_fixed<11, 5> v164 = v162;                                                    // L472
          ap_fixed<11, 5> v165 = v163;                                                    // L472
          ap_fixed<11, 5> v166 = v164 - v165;                                             // L472
          ap_fixed<10, 4> v167 = v5[i1_1];                                                // L75
          double v168 = v167;                                                             // L472
          double v169 = v168 + 0.000000;                                                  // L75
          double v170 = sqrt(v169);                                                       // L41
          double v171 = v166;                                                             // L472
          double v172 = v171 / v170;                                                      // L472
          ap_fixed<10, 4> v173 = v2[i1_1];                                                // L75
          double v174 = v173;                                                             // L472
          double v175 = v172 * v174;                                                      // L472
          ap_fixed<10, 4> v176 = v3[i1_1];                                                // L75
          double v177 = v176;                                                             // L472
          double v178 = v175 + v177;                                                      // L472
          ap_fixed<10, 4> v179 = v178;                                                    // L472
          ap_fixed<38, 32> v180 = v179;                                                   // L472
          ap_fixed<38, 32> v181 = 0;                                                      // L472
          bool v182 = v180 <= v181;                                                       // L472
          ap_fixed<10, 4> v183 = conv1_x_0_bn1[i0_1][i1_1][i2_1][i3_1];                   // L472
          ap_fixed<38, 32> v184 = 0;                                                      // L472
          ap_fixed<38, 32> v185 = v183;                                                   // L472
          ap_fixed<38, 32> v186 = v182 ? (ap_fixed<38, 32>)v184 : (ap_fixed<38, 32>)v185; // L127
          ap_fixed<10, 4> v187 = v186;                                                    // L472
          conv1_x_0_relu[i0_1][i1_1][i2_1][i3_1] = v187;                                  // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_conv1_pad[2][64][34][34]; // L472
l_conv2_x_0_conv1_pad_i0_2:
  for (int i0_2 = 0; i0_2 < 2; i0_2++)
  { // L472
  l_i1_2:
    for (int i1_2 = 0; i1_2 < 64; i1_2++)
    { // L472
    l_i2_2:
      for (int i2_2 = 0; i2_2 < 34; i2_2++)
      { // L472
      l_i3_2:
        for (int i3_2 = 0; i3_2 < 34; i3_2++)
        {                                                                              // L472
          ap_int<33> v193 = i2_2;                                                      // L472
          ap_int<33> v194 = 1;                                                         // L472
          bool v195 = v193 >= v194;                                                    // L472
          bool v196 = 1 & v195;                                                        // L30
          ap_int<33> v197 = 33;                                                        // L472
          bool v198 = v193 < v197;                                                     // L472
          bool v199 = v196 & v198;                                                     // L30
          ap_int<33> v200 = i3_2;                                                      // L472
          bool v201 = v200 >= v194;                                                    // L472
          bool v202 = v199 & v201;                                                     // L30
          bool v203 = v200 < v197;                                                     // L472
          bool v204 = v202 & v203;                                                     // L30
          ap_fixed<10, 4> v205 = conv1_x_0_relu[i0_2][i1_2][(i2_2 - 1)][(i3_2 - 1)];   // L472
          ap_fixed<10, 4> v206 = 0.000000;                                             // L472
          ap_fixed<10, 4> v207 = v204 ? (ap_fixed<10, 4>)v205 : (ap_fixed<10, 4>)v206; // L127
          conv2_x_0_conv1_pad[i0_2][i1_2][i2_2][i3_2] = v207;                          // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_conv1[2][64][32][32];     // L472
  ap_fixed<10, 4> conv2_x_0_conv1_reuse_2[64][3][34]; // L472
#pragma HLS array_partition variable = conv2_x_0_conv1_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv2_x_0_conv1_reuse_3[64][3][3]; // L472
#pragma HLS array_partition variable = conv2_x_0_conv1_reuse_3 complete dim = 3

l_conv2_x_0_conv1_nn_0:
  for (int nn_0 = 0; nn_0 < 2; nn_0++)
  { // L472
  l_ff_0:
    for (int ff_0 = 0; ff_0 < 64; ff_0++)
    { // L472
    l_yy_0:
      for (int yy_0 = 0; yy_0 < 34; yy_0++)
      { // L472
      l_xx_0:
        for (int xx_0 = 0; xx_0 < 34; xx_0++)
        { // L472
          for (int v215 = 0; v215 < 64; v215++)
          {                                                                     // L472
            ap_fixed<10, 4> v216 = conv2_x_0_conv1_reuse_2[v215][1][xx_0];      // L472
            conv2_x_0_conv1_reuse_2[v215][0][xx_0] = v216;                      // L472
            ap_fixed<10, 4> v217 = conv2_x_0_conv1_reuse_2[v215][2][xx_0];      // L472
            conv2_x_0_conv1_reuse_2[v215][1][xx_0] = v217;                      // L472
            ap_fixed<10, 4> v218 = conv2_x_0_conv1_pad[nn_0][v215][yy_0][xx_0]; // L472
            conv2_x_0_conv1_reuse_2[v215][2][xx_0] = v218;                      // L472
          }
          if ((yy_0 - 2) >= 0)
          { // L472
            for (int v219 = 0; v219 < 64; v219++)
            { // L256
              for (int v220 = 0; v220 < 3; v220++)
              {                                                                   // L256
                ap_fixed<10, 4> v221 = conv2_x_0_conv1_reuse_3[v219][v220][1];    // L256
                conv2_x_0_conv1_reuse_3[v219][v220][0] = v221;                    // L256
                ap_fixed<10, 4> v222 = conv2_x_0_conv1_reuse_3[v219][v220][2];    // L256
                conv2_x_0_conv1_reuse_3[v219][v220][1] = v222;                    // L256
                ap_fixed<10, 4> v223 = conv2_x_0_conv1_reuse_2[v219][v220][xx_0]; // L256
                conv2_x_0_conv1_reuse_3[v219][v220][2] = v223;                    // L256
              }
            }
            if ((xx_0 - 2) >= 0)
            {                           // L256
              ap_fixed<10, 4> sum_0;    // L256
              ap_fixed<10, 4> v225 = 0; // L472
              sum_0 = v225;             // L472
            l_rc_0:
              for (int rc_0 = 0; rc_0 < 64; rc_0++)
              { // L256
              l_ry_0:
                for (int ry_0 = 0; ry_0 < 3; ry_0++)
                { // L256
                l_rx_0:
                  for (int rx_0 = 0; rx_0 < 3; rx_0++)
                  { // L256
                    if (1)
                    {                                                                   // L472
                      ap_fixed<10, 4> v229 = conv2_x_0_conv1_reuse_3[rc_0][ry_0][rx_0]; // L472
                      ap_fixed<10, 4> v230 = v6[ff_0][rc_0][ry_0][rx_0];                // L34
                      ap_fixed<20, 8> v231 = v229;                                      // L472
                      ap_fixed<20, 8> v232 = v230;                                      // L472
                      ap_fixed<20, 8> v233 = v231 * v232;                               // L472
                      ap_fixed<10, 4> v234 = sum_0;                                     // L256
                      ap_fixed<21, 9> v235 = v233;                                      // L472
                      ap_fixed<21, 9> v236 = v234;                                      // L472
                      ap_fixed<21, 9> v237 = v235 + v236;                               // L472
                      ap_fixed<10, 4> v238 = v237;                                      // L472
                      sum_0 = v238;                                                     // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v239 = sum_0;                               // L256
              conv2_x_0_conv1[nn_0][ff_0][(yy_0 - 2)][(xx_0 - 2)] = v239; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_bn1[2][64][32][32];   // L472
  ap_fixed<10, 4> conv2_x_0_relu1[2][64][32][32]; // L472
l_conv2_x_0_relu1_i0_4:
  for (int i0_4 = 0; i0_4 < 2; i0_4++)
  { // L472
  l_i1_4:
    for (int i1_4 = 0; i1_4 < 64; i1_4++)
    { // L472
    l_i2_4:
      for (int i2_4 = 0; i2_4 < 32; i2_4++)
      { // L472
      l_i3_4:
        for (int i3_4 = 0; i3_4 < 32; i3_4++)
        {                                                                                 // L472
          ap_fixed<10, 4> v246 = conv2_x_0_conv1[i0_4][i1_4][i2_4][i3_4];                 // L472
          ap_fixed<10, 4> v247 = v9[i1_4];                                                // L52
          ap_fixed<11, 5> v248 = v246;                                                    // L472
          ap_fixed<11, 5> v249 = v247;                                                    // L472
          ap_fixed<11, 5> v250 = v248 - v249;                                             // L472
          ap_fixed<10, 4> v251 = v10[i1_4];                                               // L52
          double v252 = v251;                                                             // L472
          double v253 = v252 + 0.000000;                                                  // L52
          double v254 = sqrt(v253);                                                       // L41
          double v255 = v250;                                                             // L472
          double v256 = v255 / v254;                                                      // L472
          ap_fixed<10, 4> v257 = v7[i1_4];                                                // L52
          double v258 = v257;                                                             // L472
          double v259 = v256 * v258;                                                      // L472
          ap_fixed<10, 4> v260 = v8[i1_4];                                                // L52
          double v261 = v260;                                                             // L472
          double v262 = v259 + v261;                                                      // L472
          ap_fixed<10, 4> v263 = v262;                                                    // L472
          ap_fixed<38, 32> v264 = v263;                                                   // L472
          ap_fixed<38, 32> v265 = 0;                                                      // L472
          bool v266 = v264 <= v265;                                                       // L472
          ap_fixed<10, 4> v267 = conv2_x_0_bn1[i0_4][i1_4][i2_4][i3_4];                   // L472
          ap_fixed<38, 32> v268 = 0;                                                      // L472
          ap_fixed<38, 32> v269 = v267;                                                   // L472
          ap_fixed<38, 32> v270 = v266 ? (ap_fixed<38, 32>)v268 : (ap_fixed<38, 32>)v269; // L127
          ap_fixed<10, 4> v271 = v270;                                                    // L472
          conv2_x_0_relu1[i0_4][i1_4][i2_4][i3_4] = v271;                                 // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_conv2_pad[2][64][34][34]; // L472
l_conv2_x_0_conv2_pad_i0_5:
  for (int i0_5 = 0; i0_5 < 2; i0_5++)
  { // L472
  l_i1_5:
    for (int i1_5 = 0; i1_5 < 64; i1_5++)
    { // L472
    l_i2_5:
      for (int i2_5 = 0; i2_5 < 34; i2_5++)
      { // L472
      l_i3_5:
        for (int i3_5 = 0; i3_5 < 34; i3_5++)
        {                                                                              // L472
          ap_int<33> v277 = i2_5;                                                      // L472
          ap_int<33> v278 = 1;                                                         // L472
          bool v279 = v277 >= v278;                                                    // L472
          bool v280 = 1 & v279;                                                        // L30
          ap_int<33> v281 = 33;                                                        // L472
          bool v282 = v277 < v281;                                                     // L472
          bool v283 = v280 & v282;                                                     // L30
          ap_int<33> v284 = i3_5;                                                      // L472
          bool v285 = v284 >= v278;                                                    // L472
          bool v286 = v283 & v285;                                                     // L30
          bool v287 = v284 < v281;                                                     // L472
          bool v288 = v286 & v287;                                                     // L30
          ap_fixed<10, 4> v289 = conv2_x_0_relu1[i0_5][i1_5][(i2_5 - 1)][(i3_5 - 1)];  // L472
          ap_fixed<10, 4> v290 = 0.000000;                                             // L472
          ap_fixed<10, 4> v291 = v288 ? (ap_fixed<10, 4>)v289 : (ap_fixed<10, 4>)v290; // L127
          conv2_x_0_conv2_pad[i0_5][i1_5][i2_5][i3_5] = v291;                          // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_conv2[2][64][32][32];     // L472
  ap_fixed<10, 4> conv2_x_0_conv2_reuse_2[64][3][34]; // L472
#pragma HLS array_partition variable = conv2_x_0_conv2_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv2_x_0_conv2_reuse_3[64][3][3]; // L472
#pragma HLS array_partition variable = conv2_x_0_conv2_reuse_3 complete dim = 3

l_conv2_x_0_conv2_nn_1:
  for (int nn_1 = 0; nn_1 < 2; nn_1++)
  { // L472
  l_ff_1:
    for (int ff_1 = 0; ff_1 < 64; ff_1++)
    { // L472
    l_yy_1:
      for (int yy_1 = 0; yy_1 < 34; yy_1++)
      { // L472
      l_xx_1:
        for (int xx_1 = 0; xx_1 < 34; xx_1++)
        { // L472
          for (int v299 = 0; v299 < 64; v299++)
          {                                                                     // L472
            ap_fixed<10, 4> v300 = conv2_x_0_conv2_reuse_2[v299][1][xx_1];      // L472
            conv2_x_0_conv2_reuse_2[v299][0][xx_1] = v300;                      // L472
            ap_fixed<10, 4> v301 = conv2_x_0_conv2_reuse_2[v299][2][xx_1];      // L472
            conv2_x_0_conv2_reuse_2[v299][1][xx_1] = v301;                      // L472
            ap_fixed<10, 4> v302 = conv2_x_0_conv2_pad[nn_1][v299][yy_1][xx_1]; // L472
            conv2_x_0_conv2_reuse_2[v299][2][xx_1] = v302;                      // L472
          }
          if ((yy_1 - 2) >= 0)
          { // L472
            for (int v303 = 0; v303 < 64; v303++)
            { // L256
              for (int v304 = 0; v304 < 3; v304++)
              {                                                                   // L256
                ap_fixed<10, 4> v305 = conv2_x_0_conv2_reuse_3[v303][v304][1];    // L256
                conv2_x_0_conv2_reuse_3[v303][v304][0] = v305;                    // L256
                ap_fixed<10, 4> v306 = conv2_x_0_conv2_reuse_3[v303][v304][2];    // L256
                conv2_x_0_conv2_reuse_3[v303][v304][1] = v306;                    // L256
                ap_fixed<10, 4> v307 = conv2_x_0_conv2_reuse_2[v303][v304][xx_1]; // L256
                conv2_x_0_conv2_reuse_3[v303][v304][2] = v307;                    // L256
              }
            }
            if ((xx_1 - 2) >= 0)
            {                           // L256
              ap_fixed<10, 4> sum_1;    // L256
              ap_fixed<10, 4> v309 = 0; // L472
              sum_1 = v309;             // L472
            l_rc_1:
              for (int rc_1 = 0; rc_1 < 64; rc_1++)
              { // L256
              l_ry_1:
                for (int ry_1 = 0; ry_1 < 3; ry_1++)
                { // L256
                l_rx_1:
                  for (int rx_1 = 0; rx_1 < 3; rx_1++)
                  { // L256
                    if (1)
                    {                                                                   // L472
                      ap_fixed<10, 4> v313 = conv2_x_0_conv2_reuse_3[rc_1][ry_1][rx_1]; // L472
                      ap_fixed<10, 4> v314 = v11[ff_1][rc_1][ry_1][rx_1];               // L36
                      ap_fixed<20, 8> v315 = v313;                                      // L472
                      ap_fixed<20, 8> v316 = v314;                                      // L472
                      ap_fixed<20, 8> v317 = v315 * v316;                               // L472
                      ap_fixed<10, 4> v318 = sum_1;                                     // L256
                      ap_fixed<21, 9> v319 = v317;                                      // L472
                      ap_fixed<21, 9> v320 = v318;                                      // L472
                      ap_fixed<21, 9> v321 = v319 + v320;                               // L472
                      ap_fixed<10, 4> v322 = v321;                                      // L472
                      sum_1 = v322;                                                     // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v323 = sum_1;                               // L256
              conv2_x_0_conv2[nn_1][ff_1][(yy_1 - 2)][(xx_1 - 2)] = v323; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_bn2[2][64][32][32];   // L472
  ap_fixed<10, 4> conv2_x_0_add[2][64][32][32];   // L472
  ap_fixed<10, 4> conv2_x_0_relu2[2][64][32][32]; // L472
l_conv2_x_0_relu2_i0_8:
  for (int i0_8 = 0; i0_8 < 2; i0_8++)
  { // L472
  l_i1_8:
    for (int i1_8 = 0; i1_8 < 64; i1_8++)
    { // L472
    l_i2_8:
      for (int i2_8 = 0; i2_8 < 32; i2_8++)
      { // L472
      l_i3_8:
        for (int i3_8 = 0; i3_8 < 32; i3_8++)
        {                                                                                 // L472
          ap_fixed<10, 4> v331 = conv2_x_0_bn2[i0_8][i1_8][i2_8][i3_8];                   // L472
          ap_fixed<10, 4> v332 = conv1_x_0_relu[i0_8][i1_8][i2_8][i3_8];                  // L472
          ap_fixed<11, 5> v333 = v331;                                                    // L472
          ap_fixed<11, 5> v334 = v332;                                                    // L472
          ap_fixed<11, 5> v335 = v333 + v334;                                             // L472
          ap_fixed<10, 4> v336 = v335;                                                    // L472
          ap_fixed<10, 4> v337 = conv2_x_0_conv2[i0_8][i1_8][i2_8][i3_8];                 // L472
          ap_fixed<10, 4> v338 = v14[i1_8];                                               // L52
          ap_fixed<11, 5> v339 = v337;                                                    // L472
          ap_fixed<11, 5> v340 = v338;                                                    // L472
          ap_fixed<11, 5> v341 = v339 - v340;                                             // L472
          ap_fixed<10, 4> v342 = v15[i1_8];                                               // L52
          double v343 = v342;                                                             // L472
          double v344 = v343 + 0.000000;                                                  // L52
          double v345 = sqrt(v344);                                                       // L41
          double v346 = v341;                                                             // L472
          double v347 = v346 / v345;                                                      // L472
          ap_fixed<10, 4> v348 = v12[i1_8];                                               // L52
          double v349 = v348;                                                             // L472
          double v350 = v347 * v349;                                                      // L472
          ap_fixed<10, 4> v351 = v13[i1_8];                                               // L52
          double v352 = v351;                                                             // L472
          double v353 = v350 + v352;                                                      // L472
          ap_fixed<10, 4> v354 = v353;                                                    // L472
          conv2_x_0_bn2[i0_8][i1_8][i2_8][i3_8] = v354;                                   // L472
          ap_fixed<38, 32> v355 = v336;                                                   // L472
          ap_fixed<38, 32> v356 = 0;                                                      // L472
          bool v357 = v355 <= v356;                                                       // L472
          ap_fixed<10, 4> v358 = conv2_x_0_add[i0_8][i1_8][i2_8][i3_8];                   // L472
          ap_fixed<38, 32> v359 = 0;                                                      // L472
          ap_fixed<38, 32> v360 = v358;                                                   // L472
          ap_fixed<38, 32> v361 = v357 ? (ap_fixed<38, 32>)v359 : (ap_fixed<38, 32>)v360; // L127
          ap_fixed<10, 4> v362 = v361;                                                    // L472
          conv2_x_0_relu2[i0_8][i1_8][i2_8][i3_8] = v362;                                 // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_conv1_pad[2][64][34][34]; // L472
l_conv2_x_1_conv1_pad_i0_9:
  for (int i0_9 = 0; i0_9 < 2; i0_9++)
  { // L472
  l_i1_9:
    for (int i1_9 = 0; i1_9 < 64; i1_9++)
    { // L472
    l_i2_9:
      for (int i2_9 = 0; i2_9 < 34; i2_9++)
      { // L472
      l_i3_9:
        for (int i3_9 = 0; i3_9 < 34; i3_9++)
        {                                                                              // L472
          ap_int<33> v368 = i2_9;                                                      // L472
          ap_int<33> v369 = 1;                                                         // L472
          bool v370 = v368 >= v369;                                                    // L472
          bool v371 = 1 & v370;                                                        // L30
          ap_int<33> v372 = 33;                                                        // L472
          bool v373 = v368 < v372;                                                     // L472
          bool v374 = v371 & v373;                                                     // L30
          ap_int<33> v375 = i3_9;                                                      // L472
          bool v376 = v375 >= v369;                                                    // L472
          bool v377 = v374 & v376;                                                     // L30
          bool v378 = v375 < v372;                                                     // L472
          bool v379 = v377 & v378;                                                     // L30
          ap_fixed<10, 4> v380 = conv2_x_0_relu2[i0_9][i1_9][(i2_9 - 1)][(i3_9 - 1)];  // L472
          ap_fixed<10, 4> v381 = 0.000000;                                             // L472
          ap_fixed<10, 4> v382 = v379 ? (ap_fixed<10, 4>)v380 : (ap_fixed<10, 4>)v381; // L127
          conv2_x_1_conv1_pad[i0_9][i1_9][i2_9][i3_9] = v382;                          // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_conv1[2][64][32][32];     // L472
  ap_fixed<10, 4> conv2_x_1_conv1_reuse_2[64][3][34]; // L472
#pragma HLS array_partition variable = conv2_x_1_conv1_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv2_x_1_conv1_reuse_3[64][3][3]; // L472
#pragma HLS array_partition variable = conv2_x_1_conv1_reuse_3 complete dim = 3

l_conv2_x_1_conv1_nn_2:
  for (int nn_2 = 0; nn_2 < 2; nn_2++)
  { // L472
  l_ff_2:
    for (int ff_2 = 0; ff_2 < 64; ff_2++)
    { // L472
    l_yy_2:
      for (int yy_2 = 0; yy_2 < 34; yy_2++)
      { // L472
      l_xx_2:
        for (int xx_2 = 0; xx_2 < 34; xx_2++)
        { // L472
          for (int v390 = 0; v390 < 64; v390++)
          {                                                                     // L472
            ap_fixed<10, 4> v391 = conv2_x_1_conv1_reuse_2[v390][1][xx_2];      // L472
            conv2_x_1_conv1_reuse_2[v390][0][xx_2] = v391;                      // L472
            ap_fixed<10, 4> v392 = conv2_x_1_conv1_reuse_2[v390][2][xx_2];      // L472
            conv2_x_1_conv1_reuse_2[v390][1][xx_2] = v392;                      // L472
            ap_fixed<10, 4> v393 = conv2_x_1_conv1_pad[nn_2][v390][yy_2][xx_2]; // L472
            conv2_x_1_conv1_reuse_2[v390][2][xx_2] = v393;                      // L472
          }
          if ((yy_2 - 2) >= 0)
          { // L472
            for (int v394 = 0; v394 < 64; v394++)
            { // L256
              for (int v395 = 0; v395 < 3; v395++)
              {                                                                   // L256
                ap_fixed<10, 4> v396 = conv2_x_1_conv1_reuse_3[v394][v395][1];    // L256
                conv2_x_1_conv1_reuse_3[v394][v395][0] = v396;                    // L256
                ap_fixed<10, 4> v397 = conv2_x_1_conv1_reuse_3[v394][v395][2];    // L256
                conv2_x_1_conv1_reuse_3[v394][v395][1] = v397;                    // L256
                ap_fixed<10, 4> v398 = conv2_x_1_conv1_reuse_2[v394][v395][xx_2]; // L256
                conv2_x_1_conv1_reuse_3[v394][v395][2] = v398;                    // L256
              }
            }
            if ((xx_2 - 2) >= 0)
            {                           // L256
              ap_fixed<10, 4> sum_2;    // L256
              ap_fixed<10, 4> v400 = 0; // L472
              sum_2 = v400;             // L472
            l_rc_2:
              for (int rc_2 = 0; rc_2 < 64; rc_2++)
              { // L256
              l_ry_2:
                for (int ry_2 = 0; ry_2 < 3; ry_2++)
                { // L256
                l_rx_2:
                  for (int rx_2 = 0; rx_2 < 3; rx_2++)
                  { // L256
                    if (1)
                    {                                                                   // L472
                      ap_fixed<10, 4> v404 = conv2_x_1_conv1_reuse_3[rc_2][ry_2][rx_2]; // L472
                      ap_fixed<10, 4> v405 = v16[ff_2][rc_2][ry_2][rx_2];               // L34
                      ap_fixed<20, 8> v406 = v404;                                      // L472
                      ap_fixed<20, 8> v407 = v405;                                      // L472
                      ap_fixed<20, 8> v408 = v406 * v407;                               // L472
                      ap_fixed<10, 4> v409 = sum_2;                                     // L256
                      ap_fixed<21, 9> v410 = v408;                                      // L472
                      ap_fixed<21, 9> v411 = v409;                                      // L472
                      ap_fixed<21, 9> v412 = v410 + v411;                               // L472
                      ap_fixed<10, 4> v413 = v412;                                      // L472
                      sum_2 = v413;                                                     // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v414 = sum_2;                               // L256
              conv2_x_1_conv1[nn_2][ff_2][(yy_2 - 2)][(xx_2 - 2)] = v414; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_bn1[2][64][32][32];   // L472
  ap_fixed<10, 4> conv2_x_1_relu1[2][64][32][32]; // L472
l_conv2_x_1_relu1_i0_11:
  for (int i0_11 = 0; i0_11 < 2; i0_11++)
  { // L472
  l_i1_11:
    for (int i1_11 = 0; i1_11 < 64; i1_11++)
    { // L472
    l_i2_11:
      for (int i2_11 = 0; i2_11 < 32; i2_11++)
      { // L472
      l_i3_11:
        for (int i3_11 = 0; i3_11 < 32; i3_11++)
        {                                                                                 // L472
          ap_fixed<10, 4> v421 = conv2_x_1_conv1[i0_11][i1_11][i2_11][i3_11];             // L472
          ap_fixed<10, 4> v422 = v19[i1_11];                                              // L52
          ap_fixed<11, 5> v423 = v421;                                                    // L472
          ap_fixed<11, 5> v424 = v422;                                                    // L472
          ap_fixed<11, 5> v425 = v423 - v424;                                             // L472
          ap_fixed<10, 4> v426 = v20[i1_11];                                              // L52
          double v427 = v426;                                                             // L472
          double v428 = v427 + 0.000000;                                                  // L52
          double v429 = sqrt(v428);                                                       // L41
          double v430 = v425;                                                             // L472
          double v431 = v430 / v429;                                                      // L472
          ap_fixed<10, 4> v432 = v17[i1_11];                                              // L52
          double v433 = v432;                                                             // L472
          double v434 = v431 * v433;                                                      // L472
          ap_fixed<10, 4> v435 = v18[i1_11];                                              // L52
          double v436 = v435;                                                             // L472
          double v437 = v434 + v436;                                                      // L472
          ap_fixed<10, 4> v438 = v437;                                                    // L472
          ap_fixed<38, 32> v439 = v438;                                                   // L472
          ap_fixed<38, 32> v440 = 0;                                                      // L472
          bool v441 = v439 <= v440;                                                       // L472
          ap_fixed<10, 4> v442 = conv2_x_1_bn1[i0_11][i1_11][i2_11][i3_11];               // L472
          ap_fixed<38, 32> v443 = 0;                                                      // L472
          ap_fixed<38, 32> v444 = v442;                                                   // L472
          ap_fixed<38, 32> v445 = v441 ? (ap_fixed<38, 32>)v443 : (ap_fixed<38, 32>)v444; // L127
          ap_fixed<10, 4> v446 = v445;                                                    // L472
          conv2_x_1_relu1[i0_11][i1_11][i2_11][i3_11] = v446;                             // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_conv2_pad[2][64][34][34]; // L472
l_conv2_x_1_conv2_pad_i0_12:
  for (int i0_12 = 0; i0_12 < 2; i0_12++)
  { // L472
  l_i1_12:
    for (int i1_12 = 0; i1_12 < 64; i1_12++)
    { // L472
    l_i2_12:
      for (int i2_12 = 0; i2_12 < 34; i2_12++)
      { // L472
      l_i3_12:
        for (int i3_12 = 0; i3_12 < 34; i3_12++)
        {                                                                                 // L472
          ap_int<33> v452 = i2_12;                                                        // L472
          ap_int<33> v453 = 1;                                                            // L472
          bool v454 = v452 >= v453;                                                       // L472
          bool v455 = 1 & v454;                                                           // L30
          ap_int<33> v456 = 33;                                                           // L472
          bool v457 = v452 < v456;                                                        // L472
          bool v458 = v455 & v457;                                                        // L30
          ap_int<33> v459 = i3_12;                                                        // L472
          bool v460 = v459 >= v453;                                                       // L472
          bool v461 = v458 & v460;                                                        // L30
          bool v462 = v459 < v456;                                                        // L472
          bool v463 = v461 & v462;                                                        // L30
          ap_fixed<10, 4> v464 = conv2_x_1_relu1[i0_12][i1_12][(i2_12 - 1)][(i3_12 - 1)]; // L472
          ap_fixed<10, 4> v465 = 0.000000;                                                // L472
          ap_fixed<10, 4> v466 = v463 ? (ap_fixed<10, 4>)v464 : (ap_fixed<10, 4>)v465;    // L127
          conv2_x_1_conv2_pad[i0_12][i1_12][i2_12][i3_12] = v466;                         // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_conv2[2][64][32][32];     // L472
  ap_fixed<10, 4> conv2_x_1_conv2_reuse_2[64][3][34]; // L472
#pragma HLS array_partition variable = conv2_x_1_conv2_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv2_x_1_conv2_reuse_3[64][3][3]; // L472
#pragma HLS array_partition variable = conv2_x_1_conv2_reuse_3 complete dim = 3

l_conv2_x_1_conv2_nn_3:
  for (int nn_3 = 0; nn_3 < 2; nn_3++)
  { // L472
  l_ff_3:
    for (int ff_3 = 0; ff_3 < 64; ff_3++)
    { // L472
    l_yy_3:
      for (int yy_3 = 0; yy_3 < 34; yy_3++)
      { // L472
      l_xx_3:
        for (int xx_3 = 0; xx_3 < 34; xx_3++)
        { // L472
          for (int v474 = 0; v474 < 64; v474++)
          {                                                                     // L472
            ap_fixed<10, 4> v475 = conv2_x_1_conv2_reuse_2[v474][1][xx_3];      // L472
            conv2_x_1_conv2_reuse_2[v474][0][xx_3] = v475;                      // L472
            ap_fixed<10, 4> v476 = conv2_x_1_conv2_reuse_2[v474][2][xx_3];      // L472
            conv2_x_1_conv2_reuse_2[v474][1][xx_3] = v476;                      // L472
            ap_fixed<10, 4> v477 = conv2_x_1_conv2_pad[nn_3][v474][yy_3][xx_3]; // L472
            conv2_x_1_conv2_reuse_2[v474][2][xx_3] = v477;                      // L472
          }
          if ((yy_3 - 2) >= 0)
          { // L472
            for (int v478 = 0; v478 < 64; v478++)
            { // L256
              for (int v479 = 0; v479 < 3; v479++)
              {                                                                   // L256
                ap_fixed<10, 4> v480 = conv2_x_1_conv2_reuse_3[v478][v479][1];    // L256
                conv2_x_1_conv2_reuse_3[v478][v479][0] = v480;                    // L256
                ap_fixed<10, 4> v481 = conv2_x_1_conv2_reuse_3[v478][v479][2];    // L256
                conv2_x_1_conv2_reuse_3[v478][v479][1] = v481;                    // L256
                ap_fixed<10, 4> v482 = conv2_x_1_conv2_reuse_2[v478][v479][xx_3]; // L256
                conv2_x_1_conv2_reuse_3[v478][v479][2] = v482;                    // L256
              }
            }
            if ((xx_3 - 2) >= 0)
            {                           // L256
              ap_fixed<10, 4> sum_3;    // L256
              ap_fixed<10, 4> v484 = 0; // L472
              sum_3 = v484;             // L472
            l_rc_3:
              for (int rc_3 = 0; rc_3 < 64; rc_3++)
              { // L256
              l_ry_3:
                for (int ry_3 = 0; ry_3 < 3; ry_3++)
                { // L256
                l_rx_3:
                  for (int rx_3 = 0; rx_3 < 3; rx_3++)
                  { // L256
                    if (1)
                    {                                                                   // L472
                      ap_fixed<10, 4> v488 = conv2_x_1_conv2_reuse_3[rc_3][ry_3][rx_3]; // L472
                      ap_fixed<10, 4> v489 = v21[ff_3][rc_3][ry_3][rx_3];               // L36
                      ap_fixed<20, 8> v490 = v488;                                      // L472
                      ap_fixed<20, 8> v491 = v489;                                      // L472
                      ap_fixed<20, 8> v492 = v490 * v491;                               // L472
                      ap_fixed<10, 4> v493 = sum_3;                                     // L256
                      ap_fixed<21, 9> v494 = v492;                                      // L472
                      ap_fixed<21, 9> v495 = v493;                                      // L472
                      ap_fixed<21, 9> v496 = v494 + v495;                               // L472
                      ap_fixed<10, 4> v497 = v496;                                      // L472
                      sum_3 = v497;                                                     // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v498 = sum_3;                               // L256
              conv2_x_1_conv2[nn_3][ff_3][(yy_3 - 2)][(xx_3 - 2)] = v498; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_bn2[2][64][32][32];   // L472
  ap_fixed<10, 4> conv2_x_1_add[2][64][32][32];   // L472
  ap_fixed<10, 4> conv2_x_1_relu2[2][64][32][32]; // L472
l_conv2_x_1_relu2_i0_15:
  for (int i0_15 = 0; i0_15 < 2; i0_15++)
  { // L472
  l_i1_15:
    for (int i1_15 = 0; i1_15 < 64; i1_15++)
    { // L472
    l_i2_15:
      for (int i2_15 = 0; i2_15 < 32; i2_15++)
      { // L472
      l_i3_15:
        for (int i3_15 = 0; i3_15 < 32; i3_15++)
        {                                                                                 // L472
          ap_fixed<10, 4> v506 = conv2_x_1_bn2[i0_15][i1_15][i2_15][i3_15];               // L472
          ap_fixed<10, 4> v507 = conv2_x_0_relu2[i0_15][i1_15][i2_15][i3_15];             // L472
          ap_fixed<11, 5> v508 = v506;                                                    // L472
          ap_fixed<11, 5> v509 = v507;                                                    // L472
          ap_fixed<11, 5> v510 = v508 + v509;                                             // L472
          ap_fixed<10, 4> v511 = v510;                                                    // L472
          ap_fixed<10, 4> v512 = conv2_x_1_conv2[i0_15][i1_15][i2_15][i3_15];             // L472
          ap_fixed<10, 4> v513 = v24[i1_15];                                              // L52
          ap_fixed<11, 5> v514 = v512;                                                    // L472
          ap_fixed<11, 5> v515 = v513;                                                    // L472
          ap_fixed<11, 5> v516 = v514 - v515;                                             // L472
          ap_fixed<10, 4> v517 = v25[i1_15];                                              // L52
          double v518 = v517;                                                             // L472
          double v519 = v518 + 0.000000;                                                  // L52
          double v520 = sqrt(v519);                                                       // L41
          double v521 = v516;                                                             // L472
          double v522 = v521 / v520;                                                      // L472
          ap_fixed<10, 4> v523 = v22[i1_15];                                              // L52
          double v524 = v523;                                                             // L472
          double v525 = v522 * v524;                                                      // L472
          ap_fixed<10, 4> v526 = v23[i1_15];                                              // L52
          double v527 = v526;                                                             // L472
          double v528 = v525 + v527;                                                      // L472
          ap_fixed<10, 4> v529 = v528;                                                    // L472
          conv2_x_1_bn2[i0_15][i1_15][i2_15][i3_15] = v529;                               // L472
          ap_fixed<38, 32> v530 = v511;                                                   // L472
          ap_fixed<38, 32> v531 = 0;                                                      // L472
          bool v532 = v530 <= v531;                                                       // L472
          ap_fixed<10, 4> v533 = conv2_x_1_add[i0_15][i1_15][i2_15][i3_15];               // L472
          ap_fixed<38, 32> v534 = 0;                                                      // L472
          ap_fixed<38, 32> v535 = v533;                                                   // L472
          ap_fixed<38, 32> v536 = v532 ? (ap_fixed<38, 32>)v534 : (ap_fixed<38, 32>)v535; // L127
          ap_fixed<10, 4> v537 = v536;                                                    // L472
          conv2_x_1_relu2[i0_15][i1_15][i2_15][i3_15] = v537;                             // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_conv1_pad[2][64][34][34]; // L472
l_conv3_x_0_conv1_pad_i0_16:
  for (int i0_16 = 0; i0_16 < 2; i0_16++)
  { // L472
  l_i1_16:
    for (int i1_16 = 0; i1_16 < 64; i1_16++)
    { // L472
    l_i2_16:
      for (int i2_16 = 0; i2_16 < 34; i2_16++)
      { // L472
      l_i3_16:
        for (int i3_16 = 0; i3_16 < 34; i3_16++)
        {                                                                                 // L472
          ap_int<33> v543 = i2_16;                                                        // L472
          ap_int<33> v544 = 1;                                                            // L472
          bool v545 = v543 >= v544;                                                       // L472
          bool v546 = 1 & v545;                                                           // L30
          ap_int<33> v547 = 33;                                                           // L472
          bool v548 = v543 < v547;                                                        // L472
          bool v549 = v546 & v548;                                                        // L30
          ap_int<33> v550 = i3_16;                                                        // L472
          bool v551 = v550 >= v544;                                                       // L472
          bool v552 = v549 & v551;                                                        // L30
          bool v553 = v550 < v547;                                                        // L472
          bool v554 = v552 & v553;                                                        // L30
          ap_fixed<10, 4> v555 = conv2_x_1_relu2[i0_16][i1_16][(i2_16 - 1)][(i3_16 - 1)]; // L472
          ap_fixed<10, 4> v556 = 0.000000;                                                // L472
          ap_fixed<10, 4> v557 = v554 ? (ap_fixed<10, 4>)v555 : (ap_fixed<10, 4>)v556;    // L127
          conv3_x_0_conv1_pad[i0_16][i1_16][i2_16][i3_16] = v557;                         // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_conv1[2][128][16][16];    // L472
  ap_fixed<10, 4> conv3_x_0_conv1_reuse_2[64][3][34]; // L472
#pragma HLS array_partition variable = conv3_x_0_conv1_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv3_x_0_conv1_reuse_3[64][3][3]; // L472
#pragma HLS array_partition variable = conv3_x_0_conv1_reuse_3 complete dim = 3

l_conv3_x_0_conv1_nn_4:
  for (int nn_4 = 0; nn_4 < 2; nn_4++)
  { // L472
  l_ff_4:
    for (int ff_4 = 0; ff_4 < 128; ff_4++)
    { // L472
    l_yy_4:
      for (int yy_4 = 0; yy_4 < 34; yy_4++)
      { // L472
      l_xx_4:
        for (int xx_4 = 0; xx_4 < 34; xx_4++)
        { // L472
          for (int v565 = 0; v565 < 64; v565++)
          {                                                                     // L472
            ap_fixed<10, 4> v566 = conv3_x_0_conv1_reuse_2[v565][1][xx_4];      // L472
            conv3_x_0_conv1_reuse_2[v565][0][xx_4] = v566;                      // L472
            ap_fixed<10, 4> v567 = conv3_x_0_conv1_reuse_2[v565][2][xx_4];      // L472
            conv3_x_0_conv1_reuse_2[v565][1][xx_4] = v567;                      // L472
            ap_fixed<10, 4> v568 = conv3_x_0_conv1_pad[nn_4][v565][yy_4][xx_4]; // L472
            conv3_x_0_conv1_reuse_2[v565][2][xx_4] = v568;                      // L472
          }
          if ((yy_4 % 2) == 0 && (yy_4 - 2) >= 0 && (((-yy_4) + ((yy_4 / 2) * 2)) + 1) >= 0 && (yy_4 % 2) >= 0)
          { // L472
            for (int v569 = 0; v569 < 64; v569++)
            { // L256
              for (int v570 = 0; v570 < 3; v570++)
              {                                                                   // L256
                ap_fixed<10, 4> v571 = conv3_x_0_conv1_reuse_3[v569][v570][1];    // L256
                conv3_x_0_conv1_reuse_3[v569][v570][0] = v571;                    // L256
                ap_fixed<10, 4> v572 = conv3_x_0_conv1_reuse_3[v569][v570][2];    // L256
                conv3_x_0_conv1_reuse_3[v569][v570][1] = v572;                    // L256
                ap_fixed<10, 4> v573 = conv3_x_0_conv1_reuse_2[v569][v570][xx_4]; // L256
                conv3_x_0_conv1_reuse_3[v569][v570][2] = v573;                    // L256
              }
            }
            if ((xx_4 % 2) == 0 && (xx_4 - 2) >= 0 && (((-xx_4) + ((xx_4 / 2) * 2)) + 1) >= 0 && (xx_4 % 2) >= 0)
            {                           // L256
              ap_fixed<10, 4> sum_4;    // L256
              ap_fixed<10, 4> v575 = 0; // L472
              sum_4 = v575;             // L472
            l_rc_4:
              for (int rc_4 = 0; rc_4 < 64; rc_4++)
              { // L256
              l_ry_4:
                for (int ry_4 = 0; ry_4 < 3; ry_4++)
                { // L256
                l_rx_4:
                  for (int rx_4 = 0; rx_4 < 3; rx_4++)
                  { // L256
                    if (1)
                    {                                                                   // L472
                      ap_fixed<10, 4> v579 = conv3_x_0_conv1_reuse_3[rc_4][ry_4][rx_4]; // L472
                      ap_fixed<10, 4> v580 = v26[ff_4][rc_4][ry_4][rx_4];               // L34
                      ap_fixed<20, 8> v581 = v579;                                      // L472
                      ap_fixed<20, 8> v582 = v580;                                      // L472
                      ap_fixed<20, 8> v583 = v581 * v582;                               // L472
                      ap_fixed<10, 4> v584 = sum_4;                                     // L256
                      ap_fixed<21, 9> v585 = v583;                                      // L472
                      ap_fixed<21, 9> v586 = v584;                                      // L472
                      ap_fixed<21, 9> v587 = v585 + v586;                               // L472
                      ap_fixed<10, 4> v588 = v587;                                      // L472
                      sum_4 = v588;                                                     // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v589 = sum_4;                                           // L256
              conv3_x_0_conv1[nn_4][ff_4][((yy_4 / 2) - 1)][((xx_4 / 2) - 1)] = v589; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_bn1[2][128][16][16];   // L472
  ap_fixed<10, 4> conv3_x_0_relu1[2][128][16][16]; // L472
l_conv3_x_0_relu1_i0_18:
  for (int i0_18 = 0; i0_18 < 2; i0_18++)
  { // L472
  l_i1_18:
    for (int i1_18 = 0; i1_18 < 128; i1_18++)
    { // L472
    l_i2_18:
      for (int i2_18 = 0; i2_18 < 16; i2_18++)
      { // L472
      l_i3_18:
        for (int i3_18 = 0; i3_18 < 16; i3_18++)
        {                                                                                 // L472
          ap_fixed<10, 4> v596 = conv3_x_0_conv1[i0_18][i1_18][i2_18][i3_18];             // L472
          ap_fixed<10, 4> v597 = v29[i1_18];                                              // L44
          ap_fixed<11, 5> v598 = v596;                                                    // L472
          ap_fixed<11, 5> v599 = v597;                                                    // L472
          ap_fixed<11, 5> v600 = v598 - v599;                                             // L472
          ap_fixed<10, 4> v601 = v30[i1_18];                                              // L44
          double v602 = v601;                                                             // L472
          double v603 = v602 + 0.000000;                                                  // L44
          double v604 = sqrt(v603);                                                       // L41
          double v605 = v600;                                                             // L472
          double v606 = v605 / v604;                                                      // L472
          ap_fixed<10, 4> v607 = v27[i1_18];                                              // L44
          double v608 = v607;                                                             // L472
          double v609 = v606 * v608;                                                      // L472
          ap_fixed<10, 4> v610 = v28[i1_18];                                              // L44
          double v611 = v610;                                                             // L472
          double v612 = v609 + v611;                                                      // L472
          ap_fixed<10, 4> v613 = v612;                                                    // L472
          ap_fixed<38, 32> v614 = v613;                                                   // L472
          ap_fixed<38, 32> v615 = 0;                                                      // L472
          bool v616 = v614 <= v615;                                                       // L472
          ap_fixed<10, 4> v617 = conv3_x_0_bn1[i0_18][i1_18][i2_18][i3_18];               // L472
          ap_fixed<38, 32> v618 = 0;                                                      // L472
          ap_fixed<38, 32> v619 = v617;                                                   // L472
          ap_fixed<38, 32> v620 = v616 ? (ap_fixed<38, 32>)v618 : (ap_fixed<38, 32>)v619; // L127
          ap_fixed<10, 4> v621 = v620;                                                    // L472
          conv3_x_0_relu1[i0_18][i1_18][i2_18][i3_18] = v621;                             // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_conv2_pad[2][128][18][18]; // L472
l_conv3_x_0_conv2_pad_i0_19:
  for (int i0_19 = 0; i0_19 < 2; i0_19++)
  { // L472
  l_i1_19:
    for (int i1_19 = 0; i1_19 < 128; i1_19++)
    { // L472
    l_i2_19:
      for (int i2_19 = 0; i2_19 < 18; i2_19++)
      { // L472
      l_i3_19:
        for (int i3_19 = 0; i3_19 < 18; i3_19++)
        {                                                                                 // L472
          ap_int<33> v627 = i2_19;                                                        // L472
          ap_int<33> v628 = 1;                                                            // L472
          bool v629 = v627 >= v628;                                                       // L472
          bool v630 = 1 & v629;                                                           // L30
          ap_int<33> v631 = 17;                                                           // L472
          bool v632 = v627 < v631;                                                        // L472
          bool v633 = v630 & v632;                                                        // L30
          ap_int<33> v634 = i3_19;                                                        // L472
          bool v635 = v634 >= v628;                                                       // L472
          bool v636 = v633 & v635;                                                        // L30
          bool v637 = v634 < v631;                                                        // L472
          bool v638 = v636 & v637;                                                        // L30
          ap_fixed<10, 4> v639 = conv3_x_0_relu1[i0_19][i1_19][(i2_19 - 1)][(i3_19 - 1)]; // L472
          ap_fixed<10, 4> v640 = 0.000000;                                                // L472
          ap_fixed<10, 4> v641 = v638 ? (ap_fixed<10, 4>)v639 : (ap_fixed<10, 4>)v640;    // L127
          conv3_x_0_conv2_pad[i0_19][i1_19][i2_19][i3_19] = v641;                         // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_conv2[2][128][16][16];     // L472
  ap_fixed<10, 4> conv3_x_0_conv2_reuse_2[128][3][18]; // L472
#pragma HLS array_partition variable = conv3_x_0_conv2_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv3_x_0_conv2_reuse_3[128][3][3]; // L472
#pragma HLS array_partition variable = conv3_x_0_conv2_reuse_3 complete dim = 3

l_conv3_x_0_conv2_nn_5:
  for (int nn_5 = 0; nn_5 < 2; nn_5++)
  { // L472
  l_ff_5:
    for (int ff_5 = 0; ff_5 < 128; ff_5++)
    { // L472
    l_yy_5:
      for (int yy_5 = 0; yy_5 < 18; yy_5++)
      { // L472
      l_xx_5:
        for (int xx_5 = 0; xx_5 < 18; xx_5++)
        { // L472
          for (int v649 = 0; v649 < 128; v649++)
          {                                                                     // L472
            ap_fixed<10, 4> v650 = conv3_x_0_conv2_reuse_2[v649][1][xx_5];      // L472
            conv3_x_0_conv2_reuse_2[v649][0][xx_5] = v650;                      // L472
            ap_fixed<10, 4> v651 = conv3_x_0_conv2_reuse_2[v649][2][xx_5];      // L472
            conv3_x_0_conv2_reuse_2[v649][1][xx_5] = v651;                      // L472
            ap_fixed<10, 4> v652 = conv3_x_0_conv2_pad[nn_5][v649][yy_5][xx_5]; // L472
            conv3_x_0_conv2_reuse_2[v649][2][xx_5] = v652;                      // L472
          }
          if ((yy_5 - 2) >= 0)
          { // L472
            for (int v653 = 0; v653 < 128; v653++)
            { // L256
              for (int v654 = 0; v654 < 3; v654++)
              {                                                                   // L256
                ap_fixed<10, 4> v655 = conv3_x_0_conv2_reuse_3[v653][v654][1];    // L256
                conv3_x_0_conv2_reuse_3[v653][v654][0] = v655;                    // L256
                ap_fixed<10, 4> v656 = conv3_x_0_conv2_reuse_3[v653][v654][2];    // L256
                conv3_x_0_conv2_reuse_3[v653][v654][1] = v656;                    // L256
                ap_fixed<10, 4> v657 = conv3_x_0_conv2_reuse_2[v653][v654][xx_5]; // L256
                conv3_x_0_conv2_reuse_3[v653][v654][2] = v657;                    // L256
              }
            }
            if ((xx_5 - 2) >= 0)
            {                           // L256
              ap_fixed<10, 4> sum_5;    // L256
              ap_fixed<10, 4> v659 = 0; // L472
              sum_5 = v659;             // L472
            l_rc_5:
              for (int rc_5 = 0; rc_5 < 128; rc_5++)
              { // L256
              l_ry_5:
                for (int ry_5 = 0; ry_5 < 3; ry_5++)
                { // L256
                l_rx_5:
                  for (int rx_5 = 0; rx_5 < 3; rx_5++)
                  { // L256
                    if (1)
                    {                                                                   // L472
                      ap_fixed<10, 4> v663 = conv3_x_0_conv2_reuse_3[rc_5][ry_5][rx_5]; // L472
                      ap_fixed<10, 4> v664 = v31[ff_5][rc_5][ry_5][rx_5];               // L36
                      ap_fixed<20, 8> v665 = v663;                                      // L472
                      ap_fixed<20, 8> v666 = v664;                                      // L472
                      ap_fixed<20, 8> v667 = v665 * v666;                               // L472
                      ap_fixed<10, 4> v668 = sum_5;                                     // L256
                      ap_fixed<21, 9> v669 = v667;                                      // L472
                      ap_fixed<21, 9> v670 = v668;                                      // L472
                      ap_fixed<21, 9> v671 = v669 + v670;                               // L472
                      ap_fixed<10, 4> v672 = v671;                                      // L472
                      sum_5 = v672;                                                     // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v673 = sum_5;                               // L256
              conv3_x_0_conv2[nn_5][ff_5][(yy_5 - 2)][(xx_5 - 2)] = v673; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_bn2[2][128][16][16];   // L472
  ap_fixed<10, 4> conv3_x_0_convs[2][128][16][16]; // L472
l_conv3_x_0_convs_nn_6:
  for (int nn_6 = 0; nn_6 < 2; nn_6++)
  { // L472
  l_ff_6:
    for (int ff_6 = 0; ff_6 < 128; ff_6++)
    { // L472
    l_yy_6:
      for (int yy_6 = 0; yy_6 < 16; yy_6++)
      { // L472
      l_xx_6:
        for (int xx_6 = 0; xx_6 < 16; xx_6++)
        {                           // L472
          ap_fixed<10, 4> sum_6;    // L256
          ap_fixed<10, 4> v681 = 0; // L472
          sum_6 = v681;             // L472
        l_rc_6:
          for (int rc_6 = 0; rc_6 < 64; rc_6++)
          { // L256
            if (1)
            {                                                                                         // L472
              ap_fixed<10, 4> v683 = conv2_x_1_relu2[nn_6][rc_6][((yy_6 * 2) + 0)][((xx_6 * 2) + 0)]; // L472
              ap_fixed<10, 4> v684 = v36[ff_6][rc_6][0][0];                                           // L39
              ap_fixed<20, 8> v685 = v683;                                                            // L472
              ap_fixed<20, 8> v686 = v684;                                                            // L472
              ap_fixed<20, 8> v687 = v685 * v686;                                                     // L472
              ap_fixed<10, 4> v688 = sum_6;                                                           // L256
              ap_fixed<21, 9> v689 = v687;                                                            // L472
              ap_fixed<21, 9> v690 = v688;                                                            // L472
              ap_fixed<21, 9> v691 = v689 + v690;                                                     // L472
              ap_fixed<10, 4> v692 = v691;                                                            // L472
              sum_6 = v692;                                                                           // L472
            }
          }
          ap_fixed<10, 4> v693 = sum_6;                   // L256
          conv3_x_0_convs[nn_6][ff_6][yy_6][xx_6] = v693; // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_bns[2][128][16][16]; // L472
l_conv3_x_0_bns_i0_21:
  for (int i0_21 = 0; i0_21 < 2; i0_21++)
  { // L472
  l_i1_21:
    for (int i1_21 = 0; i1_21 < 128; i1_21++)
    { // L472
    l_i2_21:
      for (int i2_21 = 0; i2_21 < 16; i2_21++)
      { // L472
      l_i3_21:
        for (int i3_21 = 0; i3_21 < 16; i3_21++)
        {                                                                     // L472
          ap_fixed<10, 4> v699 = conv3_x_0_convs[i0_21][i1_21][i2_21][i3_21]; // L472
          ap_fixed<10, 4> v700 = v39[i1_21];                                  // L44
          ap_fixed<11, 5> v701 = v699;                                        // L472
          ap_fixed<11, 5> v702 = v700;                                        // L472
          ap_fixed<11, 5> v703 = v701 - v702;                                 // L472
          ap_fixed<10, 4> v704 = v40[i1_21];                                  // L44
          double v705 = v704;                                                 // L472
          double v706 = v705 + 0.000000;                                      // L44
          double v707 = sqrt(v706);                                           // L41
          double v708 = v703;                                                 // L472
          double v709 = v708 / v707;                                          // L472
          ap_fixed<10, 4> v710 = v37[i1_21];                                  // L44
          double v711 = v710;                                                 // L472
          double v712 = v709 * v711;                                          // L472
          ap_fixed<10, 4> v713 = v38[i1_21];                                  // L44
          double v714 = v713;                                                 // L472
          double v715 = v712 + v714;                                          // L472
          ap_fixed<10, 4> v716 = v715;                                        // L472
          conv3_x_0_bns[i0_21][i1_21][i2_21][i3_21] = v716;                   // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_add[2][128][16][16];   // L472
  ap_fixed<10, 4> conv3_x_0_relu2[2][128][16][16]; // L472
l_conv3_x_0_relu2_i0_23:
  for (int i0_23 = 0; i0_23 < 2; i0_23++)
  { // L472
  l_i1_23:
    for (int i1_23 = 0; i1_23 < 128; i1_23++)
    { // L472
    l_i2_23:
      for (int i2_23 = 0; i2_23 < 16; i2_23++)
      { // L472
      l_i3_23:
        for (int i3_23 = 0; i3_23 < 16; i3_23++)
        {                                                                                 // L472
          ap_fixed<10, 4> v723 = conv3_x_0_bn2[i0_23][i1_23][i2_23][i3_23];               // L472
          ap_fixed<10, 4> v724 = conv3_x_0_bns[i0_23][i1_23][i2_23][i3_23];               // L472
          ap_fixed<11, 5> v725 = v723;                                                    // L472
          ap_fixed<11, 5> v726 = v724;                                                    // L472
          ap_fixed<11, 5> v727 = v725 + v726;                                             // L472
          ap_fixed<10, 4> v728 = v727;                                                    // L472
          ap_fixed<10, 4> v729 = conv3_x_0_conv2[i0_23][i1_23][i2_23][i3_23];             // L472
          ap_fixed<10, 4> v730 = v34[i1_23];                                              // L44
          ap_fixed<11, 5> v731 = v729;                                                    // L472
          ap_fixed<11, 5> v732 = v730;                                                    // L472
          ap_fixed<11, 5> v733 = v731 - v732;                                             // L472
          ap_fixed<10, 4> v734 = v35[i1_23];                                              // L44
          double v735 = v734;                                                             // L472
          double v736 = v735 + 0.000000;                                                  // L44
          double v737 = sqrt(v736);                                                       // L41
          double v738 = v733;                                                             // L472
          double v739 = v738 / v737;                                                      // L472
          ap_fixed<10, 4> v740 = v32[i1_23];                                              // L44
          double v741 = v740;                                                             // L472
          double v742 = v739 * v741;                                                      // L472
          ap_fixed<10, 4> v743 = v33[i1_23];                                              // L44
          double v744 = v743;                                                             // L472
          double v745 = v742 + v744;                                                      // L472
          ap_fixed<10, 4> v746 = v745;                                                    // L472
          conv3_x_0_bn2[i0_23][i1_23][i2_23][i3_23] = v746;                               // L472
          ap_fixed<38, 32> v747 = v728;                                                   // L472
          ap_fixed<38, 32> v748 = 0;                                                      // L472
          bool v749 = v747 <= v748;                                                       // L472
          ap_fixed<10, 4> v750 = conv3_x_0_add[i0_23][i1_23][i2_23][i3_23];               // L472
          ap_fixed<38, 32> v751 = 0;                                                      // L472
          ap_fixed<38, 32> v752 = v750;                                                   // L472
          ap_fixed<38, 32> v753 = v749 ? (ap_fixed<38, 32>)v751 : (ap_fixed<38, 32>)v752; // L127
          ap_fixed<10, 4> v754 = v753;                                                    // L472
          conv3_x_0_relu2[i0_23][i1_23][i2_23][i3_23] = v754;                             // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_conv1_pad[2][128][18][18]; // L472
l_conv3_x_1_conv1_pad_i0_24:
  for (int i0_24 = 0; i0_24 < 2; i0_24++)
  { // L472
  l_i1_24:
    for (int i1_24 = 0; i1_24 < 128; i1_24++)
    { // L472
    l_i2_24:
      for (int i2_24 = 0; i2_24 < 18; i2_24++)
      { // L472
      l_i3_24:
        for (int i3_24 = 0; i3_24 < 18; i3_24++)
        {                                                                                 // L472
          ap_int<33> v760 = i2_24;                                                        // L472
          ap_int<33> v761 = 1;                                                            // L472
          bool v762 = v760 >= v761;                                                       // L472
          bool v763 = 1 & v762;                                                           // L30
          ap_int<33> v764 = 17;                                                           // L472
          bool v765 = v760 < v764;                                                        // L472
          bool v766 = v763 & v765;                                                        // L30
          ap_int<33> v767 = i3_24;                                                        // L472
          bool v768 = v767 >= v761;                                                       // L472
          bool v769 = v766 & v768;                                                        // L30
          bool v770 = v767 < v764;                                                        // L472
          bool v771 = v769 & v770;                                                        // L30
          ap_fixed<10, 4> v772 = conv3_x_0_relu2[i0_24][i1_24][(i2_24 - 1)][(i3_24 - 1)]; // L472
          ap_fixed<10, 4> v773 = 0.000000;                                                // L472
          ap_fixed<10, 4> v774 = v771 ? (ap_fixed<10, 4>)v772 : (ap_fixed<10, 4>)v773;    // L127
          conv3_x_1_conv1_pad[i0_24][i1_24][i2_24][i3_24] = v774;                         // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_conv1[2][128][16][16];     // L472
  ap_fixed<10, 4> conv3_x_1_conv1_reuse_2[128][3][18]; // L472
#pragma HLS array_partition variable = conv3_x_1_conv1_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv3_x_1_conv1_reuse_3[128][3][3]; // L472
#pragma HLS array_partition variable = conv3_x_1_conv1_reuse_3 complete dim = 3

l_conv3_x_1_conv1_nn_7:
  for (int nn_7 = 0; nn_7 < 2; nn_7++)
  { // L472
  l_ff_7:
    for (int ff_7 = 0; ff_7 < 128; ff_7++)
    { // L472
    l_yy_7:
      for (int yy_7 = 0; yy_7 < 18; yy_7++)
      { // L472
      l_xx_7:
        for (int xx_7 = 0; xx_7 < 18; xx_7++)
        { // L472
          for (int v782 = 0; v782 < 128; v782++)
          {                                                                     // L472
            ap_fixed<10, 4> v783 = conv3_x_1_conv1_reuse_2[v782][1][xx_7];      // L472
            conv3_x_1_conv1_reuse_2[v782][0][xx_7] = v783;                      // L472
            ap_fixed<10, 4> v784 = conv3_x_1_conv1_reuse_2[v782][2][xx_7];      // L472
            conv3_x_1_conv1_reuse_2[v782][1][xx_7] = v784;                      // L472
            ap_fixed<10, 4> v785 = conv3_x_1_conv1_pad[nn_7][v782][yy_7][xx_7]; // L472
            conv3_x_1_conv1_reuse_2[v782][2][xx_7] = v785;                      // L472
          }
          if ((yy_7 - 2) >= 0)
          { // L472
            for (int v786 = 0; v786 < 128; v786++)
            { // L256
              for (int v787 = 0; v787 < 3; v787++)
              {                                                                   // L256
                ap_fixed<10, 4> v788 = conv3_x_1_conv1_reuse_3[v786][v787][1];    // L256
                conv3_x_1_conv1_reuse_3[v786][v787][0] = v788;                    // L256
                ap_fixed<10, 4> v789 = conv3_x_1_conv1_reuse_3[v786][v787][2];    // L256
                conv3_x_1_conv1_reuse_3[v786][v787][1] = v789;                    // L256
                ap_fixed<10, 4> v790 = conv3_x_1_conv1_reuse_2[v786][v787][xx_7]; // L256
                conv3_x_1_conv1_reuse_3[v786][v787][2] = v790;                    // L256
              }
            }
            if ((xx_7 - 2) >= 0)
            {                           // L256
              ap_fixed<10, 4> sum_7;    // L256
              ap_fixed<10, 4> v792 = 0; // L472
              sum_7 = v792;             // L472
            l_rc_7:
              for (int rc_7 = 0; rc_7 < 128; rc_7++)
              { // L256
              l_ry_7:
                for (int ry_7 = 0; ry_7 < 3; ry_7++)
                { // L256
                l_rx_7:
                  for (int rx_7 = 0; rx_7 < 3; rx_7++)
                  { // L256
                    if (1)
                    {                                                                   // L472
                      ap_fixed<10, 4> v796 = conv3_x_1_conv1_reuse_3[rc_7][ry_7][rx_7]; // L472
                      ap_fixed<10, 4> v797 = v41[ff_7][rc_7][ry_7][rx_7];               // L34
                      ap_fixed<20, 8> v798 = v796;                                      // L472
                      ap_fixed<20, 8> v799 = v797;                                      // L472
                      ap_fixed<20, 8> v800 = v798 * v799;                               // L472
                      ap_fixed<10, 4> v801 = sum_7;                                     // L256
                      ap_fixed<21, 9> v802 = v800;                                      // L472
                      ap_fixed<21, 9> v803 = v801;                                      // L472
                      ap_fixed<21, 9> v804 = v802 + v803;                               // L472
                      ap_fixed<10, 4> v805 = v804;                                      // L472
                      sum_7 = v805;                                                     // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v806 = sum_7;                               // L256
              conv3_x_1_conv1[nn_7][ff_7][(yy_7 - 2)][(xx_7 - 2)] = v806; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_bn1[2][128][16][16];   // L472
  ap_fixed<10, 4> conv3_x_1_relu1[2][128][16][16]; // L472
l_conv3_x_1_relu1_i0_26:
  for (int i0_26 = 0; i0_26 < 2; i0_26++)
  { // L472
  l_i1_26:
    for (int i1_26 = 0; i1_26 < 128; i1_26++)
    { // L472
    l_i2_26:
      for (int i2_26 = 0; i2_26 < 16; i2_26++)
      { // L472
      l_i3_26:
        for (int i3_26 = 0; i3_26 < 16; i3_26++)
        {                                                                                 // L472
          ap_fixed<10, 4> v813 = conv3_x_1_conv1[i0_26][i1_26][i2_26][i3_26];             // L472
          ap_fixed<10, 4> v814 = v44[i1_26];                                              // L52
          ap_fixed<11, 5> v815 = v813;                                                    // L472
          ap_fixed<11, 5> v816 = v814;                                                    // L472
          ap_fixed<11, 5> v817 = v815 - v816;                                             // L472
          ap_fixed<10, 4> v818 = v45[i1_26];                                              // L52
          double v819 = v818;                                                             // L472
          double v820 = v819 + 0.000000;                                                  // L52
          double v821 = sqrt(v820);                                                       // L41
          double v822 = v817;                                                             // L472
          double v823 = v822 / v821;                                                      // L472
          ap_fixed<10, 4> v824 = v42[i1_26];                                              // L52
          double v825 = v824;                                                             // L472
          double v826 = v823 * v825;                                                      // L472
          ap_fixed<10, 4> v827 = v43[i1_26];                                              // L52
          double v828 = v827;                                                             // L472
          double v829 = v826 + v828;                                                      // L472
          ap_fixed<10, 4> v830 = v829;                                                    // L472
          ap_fixed<38, 32> v831 = v830;                                                   // L472
          ap_fixed<38, 32> v832 = 0;                                                      // L472
          bool v833 = v831 <= v832;                                                       // L472
          ap_fixed<10, 4> v834 = conv3_x_1_bn1[i0_26][i1_26][i2_26][i3_26];               // L472
          ap_fixed<38, 32> v835 = 0;                                                      // L472
          ap_fixed<38, 32> v836 = v834;                                                   // L472
          ap_fixed<38, 32> v837 = v833 ? (ap_fixed<38, 32>)v835 : (ap_fixed<38, 32>)v836; // L127
          ap_fixed<10, 4> v838 = v837;                                                    // L472
          conv3_x_1_relu1[i0_26][i1_26][i2_26][i3_26] = v838;                             // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_conv2_pad[2][128][18][18]; // L472
l_conv3_x_1_conv2_pad_i0_27:
  for (int i0_27 = 0; i0_27 < 2; i0_27++)
  { // L472
  l_i1_27:
    for (int i1_27 = 0; i1_27 < 128; i1_27++)
    { // L472
    l_i2_27:
      for (int i2_27 = 0; i2_27 < 18; i2_27++)
      { // L472
      l_i3_27:
        for (int i3_27 = 0; i3_27 < 18; i3_27++)
        {                                                                                 // L472
          ap_int<33> v844 = i2_27;                                                        // L472
          ap_int<33> v845 = 1;                                                            // L472
          bool v846 = v844 >= v845;                                                       // L472
          bool v847 = 1 & v846;                                                           // L30
          ap_int<33> v848 = 17;                                                           // L472
          bool v849 = v844 < v848;                                                        // L472
          bool v850 = v847 & v849;                                                        // L30
          ap_int<33> v851 = i3_27;                                                        // L472
          bool v852 = v851 >= v845;                                                       // L472
          bool v853 = v850 & v852;                                                        // L30
          bool v854 = v851 < v848;                                                        // L472
          bool v855 = v853 & v854;                                                        // L30
          ap_fixed<10, 4> v856 = conv3_x_1_relu1[i0_27][i1_27][(i2_27 - 1)][(i3_27 - 1)]; // L472
          ap_fixed<10, 4> v857 = 0.000000;                                                // L472
          ap_fixed<10, 4> v858 = v855 ? (ap_fixed<10, 4>)v856 : (ap_fixed<10, 4>)v857;    // L127
          conv3_x_1_conv2_pad[i0_27][i1_27][i2_27][i3_27] = v858;                         // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_conv2[2][128][16][16];     // L472
  ap_fixed<10, 4> conv3_x_1_conv2_reuse_2[128][3][18]; // L472
#pragma HLS array_partition variable = conv3_x_1_conv2_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv3_x_1_conv2_reuse_3[128][3][3]; // L472
#pragma HLS array_partition variable = conv3_x_1_conv2_reuse_3 complete dim = 3

l_conv3_x_1_conv2_nn_8:
  for (int nn_8 = 0; nn_8 < 2; nn_8++)
  { // L472
  l_ff_8:
    for (int ff_8 = 0; ff_8 < 128; ff_8++)
    { // L472
    l_yy_8:
      for (int yy_8 = 0; yy_8 < 18; yy_8++)
      { // L472
      l_xx_8:
        for (int xx_8 = 0; xx_8 < 18; xx_8++)
        { // L472
          for (int v866 = 0; v866 < 128; v866++)
          {                                                                     // L472
            ap_fixed<10, 4> v867 = conv3_x_1_conv2_reuse_2[v866][1][xx_8];      // L472
            conv3_x_1_conv2_reuse_2[v866][0][xx_8] = v867;                      // L472
            ap_fixed<10, 4> v868 = conv3_x_1_conv2_reuse_2[v866][2][xx_8];      // L472
            conv3_x_1_conv2_reuse_2[v866][1][xx_8] = v868;                      // L472
            ap_fixed<10, 4> v869 = conv3_x_1_conv2_pad[nn_8][v866][yy_8][xx_8]; // L472
            conv3_x_1_conv2_reuse_2[v866][2][xx_8] = v869;                      // L472
          }
          if ((yy_8 - 2) >= 0)
          { // L472
            for (int v870 = 0; v870 < 128; v870++)
            { // L256
              for (int v871 = 0; v871 < 3; v871++)
              {                                                                   // L256
                ap_fixed<10, 4> v872 = conv3_x_1_conv2_reuse_3[v870][v871][1];    // L256
                conv3_x_1_conv2_reuse_3[v870][v871][0] = v872;                    // L256
                ap_fixed<10, 4> v873 = conv3_x_1_conv2_reuse_3[v870][v871][2];    // L256
                conv3_x_1_conv2_reuse_3[v870][v871][1] = v873;                    // L256
                ap_fixed<10, 4> v874 = conv3_x_1_conv2_reuse_2[v870][v871][xx_8]; // L256
                conv3_x_1_conv2_reuse_3[v870][v871][2] = v874;                    // L256
              }
            }
            if ((xx_8 - 2) >= 0)
            {                           // L256
              ap_fixed<10, 4> sum_8;    // L256
              ap_fixed<10, 4> v876 = 0; // L472
              sum_8 = v876;             // L472
            l_rc_8:
              for (int rc_8 = 0; rc_8 < 128; rc_8++)
              { // L256
              l_ry_8:
                for (int ry_8 = 0; ry_8 < 3; ry_8++)
                { // L256
                l_rx_8:
                  for (int rx_8 = 0; rx_8 < 3; rx_8++)
                  { // L256
                    if (1)
                    {                                                                   // L472
                      ap_fixed<10, 4> v880 = conv3_x_1_conv2_reuse_3[rc_8][ry_8][rx_8]; // L472
                      ap_fixed<10, 4> v881 = v46[ff_8][rc_8][ry_8][rx_8];               // L36
                      ap_fixed<20, 8> v882 = v880;                                      // L472
                      ap_fixed<20, 8> v883 = v881;                                      // L472
                      ap_fixed<20, 8> v884 = v882 * v883;                               // L472
                      ap_fixed<10, 4> v885 = sum_8;                                     // L256
                      ap_fixed<21, 9> v886 = v884;                                      // L472
                      ap_fixed<21, 9> v887 = v885;                                      // L472
                      ap_fixed<21, 9> v888 = v886 + v887;                               // L472
                      ap_fixed<10, 4> v889 = v888;                                      // L472
                      sum_8 = v889;                                                     // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v890 = sum_8;                               // L256
              conv3_x_1_conv2[nn_8][ff_8][(yy_8 - 2)][(xx_8 - 2)] = v890; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_bn2[2][128][16][16];   // L472
  ap_fixed<10, 4> conv3_x_1_add[2][128][16][16];   // L472
  ap_fixed<10, 4> conv3_x_1_relu2[2][128][16][16]; // L472
l_conv3_x_1_relu2_i0_30:
  for (int i0_30 = 0; i0_30 < 2; i0_30++)
  { // L472
  l_i1_30:
    for (int i1_30 = 0; i1_30 < 128; i1_30++)
    { // L472
    l_i2_30:
      for (int i2_30 = 0; i2_30 < 16; i2_30++)
      { // L472
      l_i3_30:
        for (int i3_30 = 0; i3_30 < 16; i3_30++)
        {                                                                                 // L472
          ap_fixed<10, 4> v898 = conv3_x_1_bn2[i0_30][i1_30][i2_30][i3_30];               // L472
          ap_fixed<10, 4> v899 = conv3_x_0_relu2[i0_30][i1_30][i2_30][i3_30];             // L472
          ap_fixed<11, 5> v900 = v898;                                                    // L472
          ap_fixed<11, 5> v901 = v899;                                                    // L472
          ap_fixed<11, 5> v902 = v900 + v901;                                             // L472
          ap_fixed<10, 4> v903 = v902;                                                    // L472
          ap_fixed<10, 4> v904 = conv3_x_1_conv2[i0_30][i1_30][i2_30][i3_30];             // L472
          ap_fixed<10, 4> v905 = v49[i1_30];                                              // L52
          ap_fixed<11, 5> v906 = v904;                                                    // L472
          ap_fixed<11, 5> v907 = v905;                                                    // L472
          ap_fixed<11, 5> v908 = v906 - v907;                                             // L472
          ap_fixed<10, 4> v909 = v50[i1_30];                                              // L52
          double v910 = v909;                                                             // L472
          double v911 = v910 + 0.000000;                                                  // L52
          double v912 = sqrt(v911);                                                       // L41
          double v913 = v908;                                                             // L472
          double v914 = v913 / v912;                                                      // L472
          ap_fixed<10, 4> v915 = v47[i1_30];                                              // L52
          double v916 = v915;                                                             // L472
          double v917 = v914 * v916;                                                      // L472
          ap_fixed<10, 4> v918 = v48[i1_30];                                              // L52
          double v919 = v918;                                                             // L472
          double v920 = v917 + v919;                                                      // L472
          ap_fixed<10, 4> v921 = v920;                                                    // L472
          conv3_x_1_bn2[i0_30][i1_30][i2_30][i3_30] = v921;                               // L472
          ap_fixed<38, 32> v922 = v903;                                                   // L472
          ap_fixed<38, 32> v923 = 0;                                                      // L472
          bool v924 = v922 <= v923;                                                       // L472
          ap_fixed<10, 4> v925 = conv3_x_1_add[i0_30][i1_30][i2_30][i3_30];               // L472
          ap_fixed<38, 32> v926 = 0;                                                      // L472
          ap_fixed<38, 32> v927 = v925;                                                   // L472
          ap_fixed<38, 32> v928 = v924 ? (ap_fixed<38, 32>)v926 : (ap_fixed<38, 32>)v927; // L127
          ap_fixed<10, 4> v929 = v928;                                                    // L472
          conv3_x_1_relu2[i0_30][i1_30][i2_30][i3_30] = v929;                             // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_conv1_pad[2][128][18][18]; // L472
l_conv4_x_0_conv1_pad_i0_31:
  for (int i0_31 = 0; i0_31 < 2; i0_31++)
  { // L472
  l_i1_31:
    for (int i1_31 = 0; i1_31 < 128; i1_31++)
    { // L472
    l_i2_31:
      for (int i2_31 = 0; i2_31 < 18; i2_31++)
      { // L472
      l_i3_31:
        for (int i3_31 = 0; i3_31 < 18; i3_31++)
        {                                                                                 // L472
          ap_int<33> v935 = i2_31;                                                        // L472
          ap_int<33> v936 = 1;                                                            // L472
          bool v937 = v935 >= v936;                                                       // L472
          bool v938 = 1 & v937;                                                           // L30
          ap_int<33> v939 = 17;                                                           // L472
          bool v940 = v935 < v939;                                                        // L472
          bool v941 = v938 & v940;                                                        // L30
          ap_int<33> v942 = i3_31;                                                        // L472
          bool v943 = v942 >= v936;                                                       // L472
          bool v944 = v941 & v943;                                                        // L30
          bool v945 = v942 < v939;                                                        // L472
          bool v946 = v944 & v945;                                                        // L30
          ap_fixed<10, 4> v947 = conv3_x_1_relu2[i0_31][i1_31][(i2_31 - 1)][(i3_31 - 1)]; // L472
          ap_fixed<10, 4> v948 = 0.000000;                                                // L472
          ap_fixed<10, 4> v949 = v946 ? (ap_fixed<10, 4>)v947 : (ap_fixed<10, 4>)v948;    // L127
          conv4_x_0_conv1_pad[i0_31][i1_31][i2_31][i3_31] = v949;                         // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_conv1[2][256][8][8];       // L472
  ap_fixed<10, 4> conv4_x_0_conv1_reuse_2[128][3][18]; // L472
#pragma HLS array_partition variable = conv4_x_0_conv1_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv4_x_0_conv1_reuse_3[128][3][3]; // L472
#pragma HLS array_partition variable = conv4_x_0_conv1_reuse_3 complete dim = 3

l_conv4_x_0_conv1_nn_9:
  for (int nn_9 = 0; nn_9 < 2; nn_9++)
  { // L472
  l_ff_9:
    for (int ff_9 = 0; ff_9 < 256; ff_9++)
    { // L472
    l_yy_9:
      for (int yy_9 = 0; yy_9 < 18; yy_9++)
      { // L472
      l_xx_9:
        for (int xx_9 = 0; xx_9 < 18; xx_9++)
        { // L472
          for (int v957 = 0; v957 < 128; v957++)
          {                                                                     // L472
            ap_fixed<10, 4> v958 = conv4_x_0_conv1_reuse_2[v957][1][xx_9];      // L472
            conv4_x_0_conv1_reuse_2[v957][0][xx_9] = v958;                      // L472
            ap_fixed<10, 4> v959 = conv4_x_0_conv1_reuse_2[v957][2][xx_9];      // L472
            conv4_x_0_conv1_reuse_2[v957][1][xx_9] = v959;                      // L472
            ap_fixed<10, 4> v960 = conv4_x_0_conv1_pad[nn_9][v957][yy_9][xx_9]; // L472
            conv4_x_0_conv1_reuse_2[v957][2][xx_9] = v960;                      // L472
          }
          if ((yy_9 % 2) == 0 && (yy_9 - 2) >= 0 && (((-yy_9) + ((yy_9 / 2) * 2)) + 1) >= 0 && (yy_9 % 2) >= 0)
          { // L472
            for (int v961 = 0; v961 < 128; v961++)
            { // L256
              for (int v962 = 0; v962 < 3; v962++)
              {                                                                   // L256
                ap_fixed<10, 4> v963 = conv4_x_0_conv1_reuse_3[v961][v962][1];    // L256
                conv4_x_0_conv1_reuse_3[v961][v962][0] = v963;                    // L256
                ap_fixed<10, 4> v964 = conv4_x_0_conv1_reuse_3[v961][v962][2];    // L256
                conv4_x_0_conv1_reuse_3[v961][v962][1] = v964;                    // L256
                ap_fixed<10, 4> v965 = conv4_x_0_conv1_reuse_2[v961][v962][xx_9]; // L256
                conv4_x_0_conv1_reuse_3[v961][v962][2] = v965;                    // L256
              }
            }
            if ((xx_9 % 2) == 0 && (xx_9 - 2) >= 0 && (((-xx_9) + ((xx_9 / 2) * 2)) + 1) >= 0 && (xx_9 % 2) >= 0)
            {                           // L256
              ap_fixed<10, 4> sum_9;    // L256
              ap_fixed<10, 4> v967 = 0; // L472
              sum_9 = v967;             // L472
            l_rc_9:
              for (int rc_9 = 0; rc_9 < 128; rc_9++)
              { // L256
              l_ry_9:
                for (int ry_9 = 0; ry_9 < 3; ry_9++)
                { // L256
                l_rx_9:
                  for (int rx_9 = 0; rx_9 < 3; rx_9++)
                  { // L256
                    if (1)
                    {                                                                   // L472
                      ap_fixed<10, 4> v971 = conv4_x_0_conv1_reuse_3[rc_9][ry_9][rx_9]; // L472
                      ap_fixed<10, 4> v972 = v51[ff_9][rc_9][ry_9][rx_9];               // L34
                      ap_fixed<20, 8> v973 = v971;                                      // L472
                      ap_fixed<20, 8> v974 = v972;                                      // L472
                      ap_fixed<20, 8> v975 = v973 * v974;                               // L472
                      ap_fixed<10, 4> v976 = sum_9;                                     // L256
                      ap_fixed<21, 9> v977 = v975;                                      // L472
                      ap_fixed<21, 9> v978 = v976;                                      // L472
                      ap_fixed<21, 9> v979 = v977 + v978;                               // L472
                      ap_fixed<10, 4> v980 = v979;                                      // L472
                      sum_9 = v980;                                                     // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v981 = sum_9;                                           // L256
              conv4_x_0_conv1[nn_9][ff_9][((yy_9 / 2) - 1)][((xx_9 / 2) - 1)] = v981; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_bn1[2][256][8][8];   // L472
  ap_fixed<10, 4> conv4_x_0_relu1[2][256][8][8]; // L472
l_conv4_x_0_relu1_i0_33:
  for (int i0_33 = 0; i0_33 < 2; i0_33++)
  { // L472
  l_i1_33:
    for (int i1_33 = 0; i1_33 < 256; i1_33++)
    { // L472
    l_i2_33:
      for (int i2_33 = 0; i2_33 < 8; i2_33++)
      { // L472
      l_i3_33:
        for (int i3_33 = 0; i3_33 < 8; i3_33++)
        {                                                                                     // L472
          ap_fixed<10, 4> v988 = conv4_x_0_conv1[i0_33][i1_33][i2_33][i3_33];                 // L472
          ap_fixed<10, 4> v989 = v54[i1_33];                                                  // L44
          ap_fixed<11, 5> v990 = v988;                                                        // L472
          ap_fixed<11, 5> v991 = v989;                                                        // L472
          ap_fixed<11, 5> v992 = v990 - v991;                                                 // L472
          ap_fixed<10, 4> v993 = v55[i1_33];                                                  // L44
          double v994 = v993;                                                                 // L472
          double v995 = v994 + 0.000000;                                                      // L44
          double v996 = sqrt(v995);                                                           // L41
          double v997 = v992;                                                                 // L472
          double v998 = v997 / v996;                                                          // L472
          ap_fixed<10, 4> v999 = v52[i1_33];                                                  // L44
          double v1000 = v999;                                                                // L472
          double v1001 = v998 * v1000;                                                        // L472
          ap_fixed<10, 4> v1002 = v53[i1_33];                                                 // L44
          double v1003 = v1002;                                                               // L472
          double v1004 = v1001 + v1003;                                                       // L472
          ap_fixed<10, 4> v1005 = v1004;                                                      // L472
          ap_fixed<38, 32> v1006 = v1005;                                                     // L472
          ap_fixed<38, 32> v1007 = 0;                                                         // L472
          bool v1008 = v1006 <= v1007;                                                        // L472
          ap_fixed<10, 4> v1009 = conv4_x_0_bn1[i0_33][i1_33][i2_33][i3_33];                  // L472
          ap_fixed<38, 32> v1010 = 0;                                                         // L472
          ap_fixed<38, 32> v1011 = v1009;                                                     // L472
          ap_fixed<38, 32> v1012 = v1008 ? (ap_fixed<38, 32>)v1010 : (ap_fixed<38, 32>)v1011; // L127
          ap_fixed<10, 4> v1013 = v1012;                                                      // L472
          conv4_x_0_relu1[i0_33][i1_33][i2_33][i3_33] = v1013;                                // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_conv2_pad[2][256][10][10]; // L472
l_conv4_x_0_conv2_pad_i0_34:
  for (int i0_34 = 0; i0_34 < 2; i0_34++)
  { // L472
  l_i1_34:
    for (int i1_34 = 0; i1_34 < 256; i1_34++)
    { // L472
    l_i2_34:
      for (int i2_34 = 0; i2_34 < 10; i2_34++)
      { // L472
      l_i3_34:
        for (int i3_34 = 0; i3_34 < 10; i3_34++)
        {                                                                                  // L472
          ap_int<33> v1019 = i2_34;                                                        // L472
          ap_int<33> v1020 = 1;                                                            // L472
          bool v1021 = v1019 >= v1020;                                                     // L472
          bool v1022 = 1 & v1021;                                                          // L30
          ap_int<33> v1023 = 9;                                                            // L472
          bool v1024 = v1019 < v1023;                                                      // L472
          bool v1025 = v1022 & v1024;                                                      // L30
          ap_int<33> v1026 = i3_34;                                                        // L472
          bool v1027 = v1026 >= v1020;                                                     // L472
          bool v1028 = v1025 & v1027;                                                      // L30
          bool v1029 = v1026 < v1023;                                                      // L472
          bool v1030 = v1028 & v1029;                                                      // L30
          ap_fixed<10, 4> v1031 = conv4_x_0_relu1[i0_34][i1_34][(i2_34 - 1)][(i3_34 - 1)]; // L472
          ap_fixed<10, 4> v1032 = 0.000000;                                                // L472
          ap_fixed<10, 4> v1033 = v1030 ? (ap_fixed<10, 4>)v1031 : (ap_fixed<10, 4>)v1032; // L127
          conv4_x_0_conv2_pad[i0_34][i1_34][i2_34][i3_34] = v1033;                         // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_conv2[2][256][8][8];       // L472
  ap_fixed<10, 4> conv4_x_0_conv2_reuse_2[256][3][10]; // L472
#pragma HLS array_partition variable = conv4_x_0_conv2_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv4_x_0_conv2_reuse_3[256][3][3]; // L472
#pragma HLS array_partition variable = conv4_x_0_conv2_reuse_3 complete dim = 3

l_conv4_x_0_conv2_nn_10:
  for (int nn_10 = 0; nn_10 < 2; nn_10++)
  { // L472
  l_ff_10:
    for (int ff_10 = 0; ff_10 < 256; ff_10++)
    { // L472
    l_yy_10:
      for (int yy_10 = 0; yy_10 < 10; yy_10++)
      { // L472
      l_xx_10:
        for (int xx_10 = 0; xx_10 < 10; xx_10++)
        { // L472
          for (int v1041 = 0; v1041 < 256; v1041++)
          {                                                                          // L472
            ap_fixed<10, 4> v1042 = conv4_x_0_conv2_reuse_2[v1041][1][xx_10];        // L472
            conv4_x_0_conv2_reuse_2[v1041][0][xx_10] = v1042;                        // L472
            ap_fixed<10, 4> v1043 = conv4_x_0_conv2_reuse_2[v1041][2][xx_10];        // L472
            conv4_x_0_conv2_reuse_2[v1041][1][xx_10] = v1043;                        // L472
            ap_fixed<10, 4> v1044 = conv4_x_0_conv2_pad[nn_10][v1041][yy_10][xx_10]; // L472
            conv4_x_0_conv2_reuse_2[v1041][2][xx_10] = v1044;                        // L472
          }
          if ((yy_10 - 2) >= 0)
          { // L472
            for (int v1045 = 0; v1045 < 256; v1045++)
            { // L256
              for (int v1046 = 0; v1046 < 3; v1046++)
              {                                                                       // L256
                ap_fixed<10, 4> v1047 = conv4_x_0_conv2_reuse_3[v1045][v1046][1];     // L256
                conv4_x_0_conv2_reuse_3[v1045][v1046][0] = v1047;                     // L256
                ap_fixed<10, 4> v1048 = conv4_x_0_conv2_reuse_3[v1045][v1046][2];     // L256
                conv4_x_0_conv2_reuse_3[v1045][v1046][1] = v1048;                     // L256
                ap_fixed<10, 4> v1049 = conv4_x_0_conv2_reuse_2[v1045][v1046][xx_10]; // L256
                conv4_x_0_conv2_reuse_3[v1045][v1046][2] = v1049;                     // L256
              }
            }
            if ((xx_10 - 2) >= 0)
            {                            // L256
              ap_fixed<10, 4> sum_10;    // L256
              ap_fixed<10, 4> v1051 = 0; // L472
              sum_10 = v1051;            // L472
            l_rc_10:
              for (int rc_10 = 0; rc_10 < 256; rc_10++)
              { // L256
              l_ry_10:
                for (int ry_10 = 0; ry_10 < 3; ry_10++)
                { // L256
                l_rx_10:
                  for (int rx_10 = 0; rx_10 < 3; rx_10++)
                  { // L256
                    if (1)
                    {                                                                       // L472
                      ap_fixed<10, 4> v1055 = conv4_x_0_conv2_reuse_3[rc_10][ry_10][rx_10]; // L472
                      ap_fixed<10, 4> v1056 = v56[ff_10][rc_10][ry_10][rx_10];              // L36
                      ap_fixed<20, 8> v1057 = v1055;                                        // L472
                      ap_fixed<20, 8> v1058 = v1056;                                        // L472
                      ap_fixed<20, 8> v1059 = v1057 * v1058;                                // L472
                      ap_fixed<10, 4> v1060 = sum_10;                                       // L256
                      ap_fixed<21, 9> v1061 = v1059;                                        // L472
                      ap_fixed<21, 9> v1062 = v1060;                                        // L472
                      ap_fixed<21, 9> v1063 = v1061 + v1062;                                // L472
                      ap_fixed<10, 4> v1064 = v1063;                                        // L472
                      sum_10 = v1064;                                                       // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v1065 = sum_10;                                  // L256
              conv4_x_0_conv2[nn_10][ff_10][(yy_10 - 2)][(xx_10 - 2)] = v1065; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_bn2[2][256][8][8];   // L472
  ap_fixed<10, 4> conv4_x_0_convs[2][256][8][8]; // L472
l_conv4_x_0_convs_nn_11:
  for (int nn_11 = 0; nn_11 < 2; nn_11++)
  { // L472
  l_ff_11:
    for (int ff_11 = 0; ff_11 < 256; ff_11++)
    { // L472
    l_yy_11:
      for (int yy_11 = 0; yy_11 < 8; yy_11++)
      { // L472
      l_xx_11:
        for (int xx_11 = 0; xx_11 < 8; xx_11++)
        {                            // L472
          ap_fixed<10, 4> sum_11;    // L256
          ap_fixed<10, 4> v1073 = 0; // L472
          sum_11 = v1073;            // L472
        l_rc_11:
          for (int rc_11 = 0; rc_11 < 128; rc_11++)
          { // L256
            if (1)
            {                                                                                              // L472
              ap_fixed<10, 4> v1075 = conv3_x_1_relu2[nn_11][rc_11][((yy_11 * 2) + 0)][((xx_11 * 2) + 0)]; // L472
              ap_fixed<10, 4> v1076 = v61[ff_11][rc_11][0][0];                                             // L39
              ap_fixed<20, 8> v1077 = v1075;                                                               // L472
              ap_fixed<20, 8> v1078 = v1076;                                                               // L472
              ap_fixed<20, 8> v1079 = v1077 * v1078;                                                       // L472
              ap_fixed<10, 4> v1080 = sum_11;                                                              // L256
              ap_fixed<21, 9> v1081 = v1079;                                                               // L472
              ap_fixed<21, 9> v1082 = v1080;                                                               // L472
              ap_fixed<21, 9> v1083 = v1081 + v1082;                                                       // L472
              ap_fixed<10, 4> v1084 = v1083;                                                               // L472
              sum_11 = v1084;                                                                              // L472
            }
          }
          ap_fixed<10, 4> v1085 = sum_11;                      // L256
          conv4_x_0_convs[nn_11][ff_11][yy_11][xx_11] = v1085; // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_bns[2][256][8][8]; // L472
l_conv4_x_0_bns_i0_36:
  for (int i0_36 = 0; i0_36 < 2; i0_36++)
  { // L472
  l_i1_36:
    for (int i1_36 = 0; i1_36 < 256; i1_36++)
    { // L472
    l_i2_36:
      for (int i2_36 = 0; i2_36 < 8; i2_36++)
      { // L472
      l_i3_36:
        for (int i3_36 = 0; i3_36 < 8; i3_36++)
        {                                                                      // L472
          ap_fixed<10, 4> v1091 = conv4_x_0_convs[i0_36][i1_36][i2_36][i3_36]; // L472
          ap_fixed<10, 4> v1092 = v64[i1_36];                                  // L44
          ap_fixed<11, 5> v1093 = v1091;                                       // L472
          ap_fixed<11, 5> v1094 = v1092;                                       // L472
          ap_fixed<11, 5> v1095 = v1093 - v1094;                               // L472
          ap_fixed<10, 4> v1096 = v65[i1_36];                                  // L44
          double v1097 = v1096;                                                // L472
          double v1098 = v1097 + 0.000000;                                     // L44
          double v1099 = sqrt(v1098);                                          // L41
          double v1100 = v1095;                                                // L472
          double v1101 = v1100 / v1099;                                        // L472
          ap_fixed<10, 4> v1102 = v62[i1_36];                                  // L44
          double v1103 = v1102;                                                // L472
          double v1104 = v1101 * v1103;                                        // L472
          ap_fixed<10, 4> v1105 = v63[i1_36];                                  // L44
          double v1106 = v1105;                                                // L472
          double v1107 = v1104 + v1106;                                        // L472
          ap_fixed<10, 4> v1108 = v1107;                                       // L472
          conv4_x_0_bns[i0_36][i1_36][i2_36][i3_36] = v1108;                   // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_add[2][256][8][8];   // L472
  ap_fixed<10, 4> conv4_x_0_relu2[2][256][8][8]; // L472
l_conv4_x_0_relu2_i0_38:
  for (int i0_38 = 0; i0_38 < 2; i0_38++)
  { // L472
  l_i1_38:
    for (int i1_38 = 0; i1_38 < 256; i1_38++)
    { // L472
    l_i2_38:
      for (int i2_38 = 0; i2_38 < 8; i2_38++)
      { // L472
      l_i3_38:
        for (int i3_38 = 0; i3_38 < 8; i3_38++)
        {                                                                                     // L472
          ap_fixed<10, 4> v1115 = conv4_x_0_bn2[i0_38][i1_38][i2_38][i3_38];                  // L472
          ap_fixed<10, 4> v1116 = conv4_x_0_bns[i0_38][i1_38][i2_38][i3_38];                  // L472
          ap_fixed<11, 5> v1117 = v1115;                                                      // L472
          ap_fixed<11, 5> v1118 = v1116;                                                      // L472
          ap_fixed<11, 5> v1119 = v1117 + v1118;                                              // L472
          ap_fixed<10, 4> v1120 = v1119;                                                      // L472
          ap_fixed<10, 4> v1121 = conv4_x_0_conv2[i0_38][i1_38][i2_38][i3_38];                // L472
          ap_fixed<10, 4> v1122 = v59[i1_38];                                                 // L44
          ap_fixed<11, 5> v1123 = v1121;                                                      // L472
          ap_fixed<11, 5> v1124 = v1122;                                                      // L472
          ap_fixed<11, 5> v1125 = v1123 - v1124;                                              // L472
          ap_fixed<10, 4> v1126 = v60[i1_38];                                                 // L44
          double v1127 = v1126;                                                               // L472
          double v1128 = v1127 + 0.000000;                                                    // L44
          double v1129 = sqrt(v1128);                                                         // L41
          double v1130 = v1125;                                                               // L472
          double v1131 = v1130 / v1129;                                                       // L472
          ap_fixed<10, 4> v1132 = v57[i1_38];                                                 // L44
          double v1133 = v1132;                                                               // L472
          double v1134 = v1131 * v1133;                                                       // L472
          ap_fixed<10, 4> v1135 = v58[i1_38];                                                 // L44
          double v1136 = v1135;                                                               // L472
          double v1137 = v1134 + v1136;                                                       // L472
          ap_fixed<10, 4> v1138 = v1137;                                                      // L472
          conv4_x_0_bn2[i0_38][i1_38][i2_38][i3_38] = v1138;                                  // L472
          ap_fixed<38, 32> v1139 = v1120;                                                     // L472
          ap_fixed<38, 32> v1140 = 0;                                                         // L472
          bool v1141 = v1139 <= v1140;                                                        // L472
          ap_fixed<10, 4> v1142 = conv4_x_0_add[i0_38][i1_38][i2_38][i3_38];                  // L472
          ap_fixed<38, 32> v1143 = 0;                                                         // L472
          ap_fixed<38, 32> v1144 = v1142;                                                     // L472
          ap_fixed<38, 32> v1145 = v1141 ? (ap_fixed<38, 32>)v1143 : (ap_fixed<38, 32>)v1144; // L127
          ap_fixed<10, 4> v1146 = v1145;                                                      // L472
          conv4_x_0_relu2[i0_38][i1_38][i2_38][i3_38] = v1146;                                // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_conv1_pad[2][256][10][10]; // L472
l_conv4_x_1_conv1_pad_i0_39:
  for (int i0_39 = 0; i0_39 < 2; i0_39++)
  { // L472
  l_i1_39:
    for (int i1_39 = 0; i1_39 < 256; i1_39++)
    { // L472
    l_i2_39:
      for (int i2_39 = 0; i2_39 < 10; i2_39++)
      { // L472
      l_i3_39:
        for (int i3_39 = 0; i3_39 < 10; i3_39++)
        {                                                                                  // L472
          ap_int<33> v1152 = i2_39;                                                        // L472
          ap_int<33> v1153 = 1;                                                            // L472
          bool v1154 = v1152 >= v1153;                                                     // L472
          bool v1155 = 1 & v1154;                                                          // L30
          ap_int<33> v1156 = 9;                                                            // L472
          bool v1157 = v1152 < v1156;                                                      // L472
          bool v1158 = v1155 & v1157;                                                      // L30
          ap_int<33> v1159 = i3_39;                                                        // L472
          bool v1160 = v1159 >= v1153;                                                     // L472
          bool v1161 = v1158 & v1160;                                                      // L30
          bool v1162 = v1159 < v1156;                                                      // L472
          bool v1163 = v1161 & v1162;                                                      // L30
          ap_fixed<10, 4> v1164 = conv4_x_0_relu2[i0_39][i1_39][(i2_39 - 1)][(i3_39 - 1)]; // L472
          ap_fixed<10, 4> v1165 = 0.000000;                                                // L472
          ap_fixed<10, 4> v1166 = v1163 ? (ap_fixed<10, 4>)v1164 : (ap_fixed<10, 4>)v1165; // L127
          conv4_x_1_conv1_pad[i0_39][i1_39][i2_39][i3_39] = v1166;                         // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_conv1[2][256][8][8];       // L472
  ap_fixed<10, 4> conv4_x_1_conv1_reuse_2[256][3][10]; // L472
#pragma HLS array_partition variable = conv4_x_1_conv1_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv4_x_1_conv1_reuse_3[256][3][3]; // L472
#pragma HLS array_partition variable = conv4_x_1_conv1_reuse_3 complete dim = 3

l_conv4_x_1_conv1_nn_12:
  for (int nn_12 = 0; nn_12 < 2; nn_12++)
  { // L472
  l_ff_12:
    for (int ff_12 = 0; ff_12 < 256; ff_12++)
    { // L472
    l_yy_12:
      for (int yy_12 = 0; yy_12 < 10; yy_12++)
      { // L472
      l_xx_12:
        for (int xx_12 = 0; xx_12 < 10; xx_12++)
        { // L472
          for (int v1174 = 0; v1174 < 256; v1174++)
          {                                                                          // L472
            ap_fixed<10, 4> v1175 = conv4_x_1_conv1_reuse_2[v1174][1][xx_12];        // L472
            conv4_x_1_conv1_reuse_2[v1174][0][xx_12] = v1175;                        // L472
            ap_fixed<10, 4> v1176 = conv4_x_1_conv1_reuse_2[v1174][2][xx_12];        // L472
            conv4_x_1_conv1_reuse_2[v1174][1][xx_12] = v1176;                        // L472
            ap_fixed<10, 4> v1177 = conv4_x_1_conv1_pad[nn_12][v1174][yy_12][xx_12]; // L472
            conv4_x_1_conv1_reuse_2[v1174][2][xx_12] = v1177;                        // L472
          }
          if ((yy_12 - 2) >= 0)
          { // L472
            for (int v1178 = 0; v1178 < 256; v1178++)
            { // L256
              for (int v1179 = 0; v1179 < 3; v1179++)
              {                                                                       // L256
                ap_fixed<10, 4> v1180 = conv4_x_1_conv1_reuse_3[v1178][v1179][1];     // L256
                conv4_x_1_conv1_reuse_3[v1178][v1179][0] = v1180;                     // L256
                ap_fixed<10, 4> v1181 = conv4_x_1_conv1_reuse_3[v1178][v1179][2];     // L256
                conv4_x_1_conv1_reuse_3[v1178][v1179][1] = v1181;                     // L256
                ap_fixed<10, 4> v1182 = conv4_x_1_conv1_reuse_2[v1178][v1179][xx_12]; // L256
                conv4_x_1_conv1_reuse_3[v1178][v1179][2] = v1182;                     // L256
              }
            }
            if ((xx_12 - 2) >= 0)
            {                            // L256
              ap_fixed<10, 4> sum_12;    // L256
              ap_fixed<10, 4> v1184 = 0; // L472
              sum_12 = v1184;            // L472
            l_rc_12:
              for (int rc_12 = 0; rc_12 < 256; rc_12++)
              { // L256
              l_ry_12:
                for (int ry_12 = 0; ry_12 < 3; ry_12++)
                { // L256
                l_rx_12:
                  for (int rx_12 = 0; rx_12 < 3; rx_12++)
                  { // L256
                    if (1)
                    {                                                                       // L472
                      ap_fixed<10, 4> v1188 = conv4_x_1_conv1_reuse_3[rc_12][ry_12][rx_12]; // L472
                      ap_fixed<10, 4> v1189 = v66[ff_12][rc_12][ry_12][rx_12];              // L34
                      ap_fixed<20, 8> v1190 = v1188;                                        // L472
                      ap_fixed<20, 8> v1191 = v1189;                                        // L472
                      ap_fixed<20, 8> v1192 = v1190 * v1191;                                // L472
                      ap_fixed<10, 4> v1193 = sum_12;                                       // L256
                      ap_fixed<21, 9> v1194 = v1192;                                        // L472
                      ap_fixed<21, 9> v1195 = v1193;                                        // L472
                      ap_fixed<21, 9> v1196 = v1194 + v1195;                                // L472
                      ap_fixed<10, 4> v1197 = v1196;                                        // L472
                      sum_12 = v1197;                                                       // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v1198 = sum_12;                                  // L256
              conv4_x_1_conv1[nn_12][ff_12][(yy_12 - 2)][(xx_12 - 2)] = v1198; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_bn1[2][256][8][8];   // L472
  ap_fixed<10, 4> conv4_x_1_relu1[2][256][8][8]; // L472
l_conv4_x_1_relu1_i0_41:
  for (int i0_41 = 0; i0_41 < 2; i0_41++)
  { // L472
  l_i1_41:
    for (int i1_41 = 0; i1_41 < 256; i1_41++)
    { // L472
    l_i2_41:
      for (int i2_41 = 0; i2_41 < 8; i2_41++)
      { // L472
      l_i3_41:
        for (int i3_41 = 0; i3_41 < 8; i3_41++)
        {                                                                                     // L472
          ap_fixed<10, 4> v1205 = conv4_x_1_conv1[i0_41][i1_41][i2_41][i3_41];                // L472
          ap_fixed<10, 4> v1206 = v69[i1_41];                                                 // L52
          ap_fixed<11, 5> v1207 = v1205;                                                      // L472
          ap_fixed<11, 5> v1208 = v1206;                                                      // L472
          ap_fixed<11, 5> v1209 = v1207 - v1208;                                              // L472
          ap_fixed<10, 4> v1210 = v70[i1_41];                                                 // L52
          double v1211 = v1210;                                                               // L472
          double v1212 = v1211 + 0.000000;                                                    // L52
          double v1213 = sqrt(v1212);                                                         // L41
          double v1214 = v1209;                                                               // L472
          double v1215 = v1214 / v1213;                                                       // L472
          ap_fixed<10, 4> v1216 = v67[i1_41];                                                 // L52
          double v1217 = v1216;                                                               // L472
          double v1218 = v1215 * v1217;                                                       // L472
          ap_fixed<10, 4> v1219 = v68[i1_41];                                                 // L52
          double v1220 = v1219;                                                               // L472
          double v1221 = v1218 + v1220;                                                       // L472
          ap_fixed<10, 4> v1222 = v1221;                                                      // L472
          ap_fixed<38, 32> v1223 = v1222;                                                     // L472
          ap_fixed<38, 32> v1224 = 0;                                                         // L472
          bool v1225 = v1223 <= v1224;                                                        // L472
          ap_fixed<10, 4> v1226 = conv4_x_1_bn1[i0_41][i1_41][i2_41][i3_41];                  // L472
          ap_fixed<38, 32> v1227 = 0;                                                         // L472
          ap_fixed<38, 32> v1228 = v1226;                                                     // L472
          ap_fixed<38, 32> v1229 = v1225 ? (ap_fixed<38, 32>)v1227 : (ap_fixed<38, 32>)v1228; // L127
          ap_fixed<10, 4> v1230 = v1229;                                                      // L472
          conv4_x_1_relu1[i0_41][i1_41][i2_41][i3_41] = v1230;                                // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_conv2_pad[2][256][10][10]; // L472
l_conv4_x_1_conv2_pad_i0_42:
  for (int i0_42 = 0; i0_42 < 2; i0_42++)
  { // L472
  l_i1_42:
    for (int i1_42 = 0; i1_42 < 256; i1_42++)
    { // L472
    l_i2_42:
      for (int i2_42 = 0; i2_42 < 10; i2_42++)
      { // L472
      l_i3_42:
        for (int i3_42 = 0; i3_42 < 10; i3_42++)
        {                                                                                  // L472
          ap_int<33> v1236 = i2_42;                                                        // L472
          ap_int<33> v1237 = 1;                                                            // L472
          bool v1238 = v1236 >= v1237;                                                     // L472
          bool v1239 = 1 & v1238;                                                          // L30
          ap_int<33> v1240 = 9;                                                            // L472
          bool v1241 = v1236 < v1240;                                                      // L472
          bool v1242 = v1239 & v1241;                                                      // L30
          ap_int<33> v1243 = i3_42;                                                        // L472
          bool v1244 = v1243 >= v1237;                                                     // L472
          bool v1245 = v1242 & v1244;                                                      // L30
          bool v1246 = v1243 < v1240;                                                      // L472
          bool v1247 = v1245 & v1246;                                                      // L30
          ap_fixed<10, 4> v1248 = conv4_x_1_relu1[i0_42][i1_42][(i2_42 - 1)][(i3_42 - 1)]; // L472
          ap_fixed<10, 4> v1249 = 0.000000;                                                // L472
          ap_fixed<10, 4> v1250 = v1247 ? (ap_fixed<10, 4>)v1248 : (ap_fixed<10, 4>)v1249; // L127
          conv4_x_1_conv2_pad[i0_42][i1_42][i2_42][i3_42] = v1250;                         // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_conv2[2][256][8][8];       // L472
  ap_fixed<10, 4> conv4_x_1_conv2_reuse_2[256][3][10]; // L472
#pragma HLS array_partition variable = conv4_x_1_conv2_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv4_x_1_conv2_reuse_3[256][3][3]; // L472
#pragma HLS array_partition variable = conv4_x_1_conv2_reuse_3 complete dim = 3

l_conv4_x_1_conv2_nn_13:
  for (int nn_13 = 0; nn_13 < 2; nn_13++)
  { // L472
  l_ff_13:
    for (int ff_13 = 0; ff_13 < 256; ff_13++)
    { // L472
    l_yy_13:
      for (int yy_13 = 0; yy_13 < 10; yy_13++)
      { // L472
      l_xx_13:
        for (int xx_13 = 0; xx_13 < 10; xx_13++)
        { // L472
          for (int v1258 = 0; v1258 < 256; v1258++)
          {                                                                          // L472
            ap_fixed<10, 4> v1259 = conv4_x_1_conv2_reuse_2[v1258][1][xx_13];        // L472
            conv4_x_1_conv2_reuse_2[v1258][0][xx_13] = v1259;                        // L472
            ap_fixed<10, 4> v1260 = conv4_x_1_conv2_reuse_2[v1258][2][xx_13];        // L472
            conv4_x_1_conv2_reuse_2[v1258][1][xx_13] = v1260;                        // L472
            ap_fixed<10, 4> v1261 = conv4_x_1_conv2_pad[nn_13][v1258][yy_13][xx_13]; // L472
            conv4_x_1_conv2_reuse_2[v1258][2][xx_13] = v1261;                        // L472
          }
          if ((yy_13 - 2) >= 0)
          { // L472
            for (int v1262 = 0; v1262 < 256; v1262++)
            { // L256
              for (int v1263 = 0; v1263 < 3; v1263++)
              {                                                                       // L256
                ap_fixed<10, 4> v1264 = conv4_x_1_conv2_reuse_3[v1262][v1263][1];     // L256
                conv4_x_1_conv2_reuse_3[v1262][v1263][0] = v1264;                     // L256
                ap_fixed<10, 4> v1265 = conv4_x_1_conv2_reuse_3[v1262][v1263][2];     // L256
                conv4_x_1_conv2_reuse_3[v1262][v1263][1] = v1265;                     // L256
                ap_fixed<10, 4> v1266 = conv4_x_1_conv2_reuse_2[v1262][v1263][xx_13]; // L256
                conv4_x_1_conv2_reuse_3[v1262][v1263][2] = v1266;                     // L256
              }
            }
            if ((xx_13 - 2) >= 0)
            {                            // L256
              ap_fixed<10, 4> sum_13;    // L256
              ap_fixed<10, 4> v1268 = 0; // L472
              sum_13 = v1268;            // L472
            l_rc_13:
              for (int rc_13 = 0; rc_13 < 256; rc_13++)
              { // L256
              l_ry_13:
                for (int ry_13 = 0; ry_13 < 3; ry_13++)
                { // L256
                l_rx_13:
                  for (int rx_13 = 0; rx_13 < 3; rx_13++)
                  { // L256
                    if (1)
                    {                                                                       // L472
                      ap_fixed<10, 4> v1272 = conv4_x_1_conv2_reuse_3[rc_13][ry_13][rx_13]; // L472
                      ap_fixed<10, 4> v1273 = v71[ff_13][rc_13][ry_13][rx_13];              // L36
                      ap_fixed<20, 8> v1274 = v1272;                                        // L472
                      ap_fixed<20, 8> v1275 = v1273;                                        // L472
                      ap_fixed<20, 8> v1276 = v1274 * v1275;                                // L472
                      ap_fixed<10, 4> v1277 = sum_13;                                       // L256
                      ap_fixed<21, 9> v1278 = v1276;                                        // L472
                      ap_fixed<21, 9> v1279 = v1277;                                        // L472
                      ap_fixed<21, 9> v1280 = v1278 + v1279;                                // L472
                      ap_fixed<10, 4> v1281 = v1280;                                        // L472
                      sum_13 = v1281;                                                       // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v1282 = sum_13;                                  // L256
              conv4_x_1_conv2[nn_13][ff_13][(yy_13 - 2)][(xx_13 - 2)] = v1282; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_bn2[2][256][8][8];   // L472
  ap_fixed<10, 4> conv4_x_1_add[2][256][8][8];   // L472
  ap_fixed<10, 4> conv4_x_1_relu2[2][256][8][8]; // L472
l_conv4_x_1_relu2_i0_45:
  for (int i0_45 = 0; i0_45 < 2; i0_45++)
  { // L472
  l_i1_45:
    for (int i1_45 = 0; i1_45 < 256; i1_45++)
    { // L472
    l_i2_45:
      for (int i2_45 = 0; i2_45 < 8; i2_45++)
      { // L472
      l_i3_45:
        for (int i3_45 = 0; i3_45 < 8; i3_45++)
        {                                                                                     // L472
          ap_fixed<10, 4> v1290 = conv4_x_1_bn2[i0_45][i1_45][i2_45][i3_45];                  // L472
          ap_fixed<10, 4> v1291 = conv4_x_0_relu2[i0_45][i1_45][i2_45][i3_45];                // L472
          ap_fixed<11, 5> v1292 = v1290;                                                      // L472
          ap_fixed<11, 5> v1293 = v1291;                                                      // L472
          ap_fixed<11, 5> v1294 = v1292 + v1293;                                              // L472
          ap_fixed<10, 4> v1295 = v1294;                                                      // L472
          ap_fixed<10, 4> v1296 = conv4_x_1_conv2[i0_45][i1_45][i2_45][i3_45];                // L472
          ap_fixed<10, 4> v1297 = v74[i1_45];                                                 // L52
          ap_fixed<11, 5> v1298 = v1296;                                                      // L472
          ap_fixed<11, 5> v1299 = v1297;                                                      // L472
          ap_fixed<11, 5> v1300 = v1298 - v1299;                                              // L472
          ap_fixed<10, 4> v1301 = v75[i1_45];                                                 // L52
          double v1302 = v1301;                                                               // L472
          double v1303 = v1302 + 0.000000;                                                    // L52
          double v1304 = sqrt(v1303);                                                         // L41
          double v1305 = v1300;                                                               // L472
          double v1306 = v1305 / v1304;                                                       // L472
          ap_fixed<10, 4> v1307 = v72[i1_45];                                                 // L52
          double v1308 = v1307;                                                               // L472
          double v1309 = v1306 * v1308;                                                       // L472
          ap_fixed<10, 4> v1310 = v73[i1_45];                                                 // L52
          double v1311 = v1310;                                                               // L472
          double v1312 = v1309 + v1311;                                                       // L472
          ap_fixed<10, 4> v1313 = v1312;                                                      // L472
          conv4_x_1_bn2[i0_45][i1_45][i2_45][i3_45] = v1313;                                  // L472
          ap_fixed<38, 32> v1314 = v1295;                                                     // L472
          ap_fixed<38, 32> v1315 = 0;                                                         // L472
          bool v1316 = v1314 <= v1315;                                                        // L472
          ap_fixed<10, 4> v1317 = conv4_x_1_add[i0_45][i1_45][i2_45][i3_45];                  // L472
          ap_fixed<38, 32> v1318 = 0;                                                         // L472
          ap_fixed<38, 32> v1319 = v1317;                                                     // L472
          ap_fixed<38, 32> v1320 = v1316 ? (ap_fixed<38, 32>)v1318 : (ap_fixed<38, 32>)v1319; // L127
          ap_fixed<10, 4> v1321 = v1320;                                                      // L472
          conv4_x_1_relu2[i0_45][i1_45][i2_45][i3_45] = v1321;                                // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_conv1_pad[2][256][10][10]; // L472
l_conv5_x_0_conv1_pad_i0_46:
  for (int i0_46 = 0; i0_46 < 2; i0_46++)
  { // L472
  l_i1_46:
    for (int i1_46 = 0; i1_46 < 256; i1_46++)
    { // L472
    l_i2_46:
      for (int i2_46 = 0; i2_46 < 10; i2_46++)
      { // L472
      l_i3_46:
        for (int i3_46 = 0; i3_46 < 10; i3_46++)
        {                                                                                  // L472
          ap_int<33> v1327 = i2_46;                                                        // L472
          ap_int<33> v1328 = 1;                                                            // L472
          bool v1329 = v1327 >= v1328;                                                     // L472
          bool v1330 = 1 & v1329;                                                          // L30
          ap_int<33> v1331 = 9;                                                            // L472
          bool v1332 = v1327 < v1331;                                                      // L472
          bool v1333 = v1330 & v1332;                                                      // L30
          ap_int<33> v1334 = i3_46;                                                        // L472
          bool v1335 = v1334 >= v1328;                                                     // L472
          bool v1336 = v1333 & v1335;                                                      // L30
          bool v1337 = v1334 < v1331;                                                      // L472
          bool v1338 = v1336 & v1337;                                                      // L30
          ap_fixed<10, 4> v1339 = conv4_x_1_relu2[i0_46][i1_46][(i2_46 - 1)][(i3_46 - 1)]; // L472
          ap_fixed<10, 4> v1340 = 0.000000;                                                // L472
          ap_fixed<10, 4> v1341 = v1338 ? (ap_fixed<10, 4>)v1339 : (ap_fixed<10, 4>)v1340; // L127
          conv5_x_0_conv1_pad[i0_46][i1_46][i2_46][i3_46] = v1341;                         // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_conv1[2][512][4][4];       // L472
  ap_fixed<10, 4> conv5_x_0_conv1_reuse_2[256][3][10]; // L472
#pragma HLS array_partition variable = conv5_x_0_conv1_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv5_x_0_conv1_reuse_3[256][3][3]; // L472
#pragma HLS array_partition variable = conv5_x_0_conv1_reuse_3 complete dim = 3

l_conv5_x_0_conv1_nn_14:
  for (int nn_14 = 0; nn_14 < 2; nn_14++)
  { // L472
  l_ff_14:
    for (int ff_14 = 0; ff_14 < 512; ff_14++)
    { // L472
    l_yy_14:
      for (int yy_14 = 0; yy_14 < 10; yy_14++)
      { // L472
      l_xx_14:
        for (int xx_14 = 0; xx_14 < 10; xx_14++)
        { // L472
          for (int v1349 = 0; v1349 < 256; v1349++)
          {                                                                          // L472
            ap_fixed<10, 4> v1350 = conv5_x_0_conv1_reuse_2[v1349][1][xx_14];        // L472
            conv5_x_0_conv1_reuse_2[v1349][0][xx_14] = v1350;                        // L472
            ap_fixed<10, 4> v1351 = conv5_x_0_conv1_reuse_2[v1349][2][xx_14];        // L472
            conv5_x_0_conv1_reuse_2[v1349][1][xx_14] = v1351;                        // L472
            ap_fixed<10, 4> v1352 = conv5_x_0_conv1_pad[nn_14][v1349][yy_14][xx_14]; // L472
            conv5_x_0_conv1_reuse_2[v1349][2][xx_14] = v1352;                        // L472
          }
          if ((yy_14 % 2) == 0 && (yy_14 - 2) >= 0 && (((-yy_14) + ((yy_14 / 2) * 2)) + 1) >= 0 && (yy_14 % 2) >= 0)
          { // L472
            for (int v1353 = 0; v1353 < 256; v1353++)
            { // L256
              for (int v1354 = 0; v1354 < 3; v1354++)
              {                                                                       // L256
                ap_fixed<10, 4> v1355 = conv5_x_0_conv1_reuse_3[v1353][v1354][1];     // L256
                conv5_x_0_conv1_reuse_3[v1353][v1354][0] = v1355;                     // L256
                ap_fixed<10, 4> v1356 = conv5_x_0_conv1_reuse_3[v1353][v1354][2];     // L256
                conv5_x_0_conv1_reuse_3[v1353][v1354][1] = v1356;                     // L256
                ap_fixed<10, 4> v1357 = conv5_x_0_conv1_reuse_2[v1353][v1354][xx_14]; // L256
                conv5_x_0_conv1_reuse_3[v1353][v1354][2] = v1357;                     // L256
              }
            }
            if ((xx_14 % 2) == 0 && (xx_14 - 2) >= 0 && (((-xx_14) + ((xx_14 / 2) * 2)) + 1) >= 0 && (xx_14 % 2) >= 0)
            {                            // L256
              ap_fixed<10, 4> sum_14;    // L256
              ap_fixed<10, 4> v1359 = 0; // L472
              sum_14 = v1359;            // L472
            l_rc_14:
              for (int rc_14 = 0; rc_14 < 256; rc_14++)
              { // L256
              l_ry_14:
                for (int ry_14 = 0; ry_14 < 3; ry_14++)
                { // L256
                l_rx_14:
                  for (int rx_14 = 0; rx_14 < 3; rx_14++)
                  { // L256
                    if (1)
                    {                                                                       // L472
                      ap_fixed<10, 4> v1363 = conv5_x_0_conv1_reuse_3[rc_14][ry_14][rx_14]; // L472
                      ap_fixed<10, 4> v1364 = v76[ff_14][rc_14][ry_14][rx_14];              // L34
                      ap_fixed<20, 8> v1365 = v1363;                                        // L472
                      ap_fixed<20, 8> v1366 = v1364;                                        // L472
                      ap_fixed<20, 8> v1367 = v1365 * v1366;                                // L472
                      ap_fixed<10, 4> v1368 = sum_14;                                       // L256
                      ap_fixed<21, 9> v1369 = v1367;                                        // L472
                      ap_fixed<21, 9> v1370 = v1368;                                        // L472
                      ap_fixed<21, 9> v1371 = v1369 + v1370;                                // L472
                      ap_fixed<10, 4> v1372 = v1371;                                        // L472
                      sum_14 = v1372;                                                       // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v1373 = sum_14;                                              // L256
              conv5_x_0_conv1[nn_14][ff_14][((yy_14 / 2) - 1)][((xx_14 / 2) - 1)] = v1373; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_bn1[2][512][4][4];   // L472
  ap_fixed<10, 4> conv5_x_0_relu1[2][512][4][4]; // L472
l_conv5_x_0_relu1_i0_48:
  for (int i0_48 = 0; i0_48 < 2; i0_48++)
  { // L472
  l_i1_48:
    for (int i1_48 = 0; i1_48 < 512; i1_48++)
    { // L472
    l_i2_48:
      for (int i2_48 = 0; i2_48 < 4; i2_48++)
      { // L472
      l_i3_48:
        for (int i3_48 = 0; i3_48 < 4; i3_48++)
        {                                                                                     // L472
          ap_fixed<10, 4> v1380 = conv5_x_0_conv1[i0_48][i1_48][i2_48][i3_48];                // L472
          ap_fixed<10, 4> v1381 = v79[i1_48];                                                 // L44
          ap_fixed<11, 5> v1382 = v1380;                                                      // L472
          ap_fixed<11, 5> v1383 = v1381;                                                      // L472
          ap_fixed<11, 5> v1384 = v1382 - v1383;                                              // L472
          ap_fixed<10, 4> v1385 = v80[i1_48];                                                 // L44
          double v1386 = v1385;                                                               // L472
          double v1387 = v1386 + 0.000000;                                                    // L44
          double v1388 = sqrt(v1387);                                                         // L41
          double v1389 = v1384;                                                               // L472
          double v1390 = v1389 / v1388;                                                       // L472
          ap_fixed<10, 4> v1391 = v77[i1_48];                                                 // L44
          double v1392 = v1391;                                                               // L472
          double v1393 = v1390 * v1392;                                                       // L472
          ap_fixed<10, 4> v1394 = v78[i1_48];                                                 // L44
          double v1395 = v1394;                                                               // L472
          double v1396 = v1393 + v1395;                                                       // L472
          ap_fixed<10, 4> v1397 = v1396;                                                      // L472
          ap_fixed<38, 32> v1398 = v1397;                                                     // L472
          ap_fixed<38, 32> v1399 = 0;                                                         // L472
          bool v1400 = v1398 <= v1399;                                                        // L472
          ap_fixed<10, 4> v1401 = conv5_x_0_bn1[i0_48][i1_48][i2_48][i3_48];                  // L472
          ap_fixed<38, 32> v1402 = 0;                                                         // L472
          ap_fixed<38, 32> v1403 = v1401;                                                     // L472
          ap_fixed<38, 32> v1404 = v1400 ? (ap_fixed<38, 32>)v1402 : (ap_fixed<38, 32>)v1403; // L127
          ap_fixed<10, 4> v1405 = v1404;                                                      // L472
          conv5_x_0_relu1[i0_48][i1_48][i2_48][i3_48] = v1405;                                // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_conv2_pad[2][512][6][6]; // L472
l_conv5_x_0_conv2_pad_i0_49:
  for (int i0_49 = 0; i0_49 < 2; i0_49++)
  { // L472
  l_i1_49:
    for (int i1_49 = 0; i1_49 < 512; i1_49++)
    { // L472
    l_i2_49:
      for (int i2_49 = 0; i2_49 < 6; i2_49++)
      { // L472
      l_i3_49:
        for (int i3_49 = 0; i3_49 < 6; i3_49++)
        {                                                                                  // L472
          ap_int<33> v1411 = i2_49;                                                        // L472
          ap_int<33> v1412 = 1;                                                            // L472
          bool v1413 = v1411 >= v1412;                                                     // L472
          bool v1414 = 1 & v1413;                                                          // L30
          ap_int<33> v1415 = 5;                                                            // L472
          bool v1416 = v1411 < v1415;                                                      // L472
          bool v1417 = v1414 & v1416;                                                      // L30
          ap_int<33> v1418 = i3_49;                                                        // L472
          bool v1419 = v1418 >= v1412;                                                     // L472
          bool v1420 = v1417 & v1419;                                                      // L30
          bool v1421 = v1418 < v1415;                                                      // L472
          bool v1422 = v1420 & v1421;                                                      // L30
          ap_fixed<10, 4> v1423 = conv5_x_0_relu1[i0_49][i1_49][(i2_49 - 1)][(i3_49 - 1)]; // L472
          ap_fixed<10, 4> v1424 = 0.000000;                                                // L472
          ap_fixed<10, 4> v1425 = v1422 ? (ap_fixed<10, 4>)v1423 : (ap_fixed<10, 4>)v1424; // L127
          conv5_x_0_conv2_pad[i0_49][i1_49][i2_49][i3_49] = v1425;                         // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_conv2[2][512][4][4];      // L472
  ap_fixed<10, 4> conv5_x_0_conv2_reuse_2[512][3][6]; // L472
#pragma HLS array_partition variable = conv5_x_0_conv2_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv5_x_0_conv2_reuse_3[512][3][3]; // L472
#pragma HLS array_partition variable = conv5_x_0_conv2_reuse_3 complete dim = 3

l_conv5_x_0_conv2_nn_15:
  for (int nn_15 = 0; nn_15 < 2; nn_15++)
  { // L472
  l_ff_15:
    for (int ff_15 = 0; ff_15 < 512; ff_15++)
    { // L472
    l_yy_15:
      for (int yy_15 = 0; yy_15 < 6; yy_15++)
      { // L472
      l_xx_15:
        for (int xx_15 = 0; xx_15 < 6; xx_15++)
        { // L472
          for (int v1433 = 0; v1433 < 512; v1433++)
          {                                                                          // L472
            ap_fixed<10, 4> v1434 = conv5_x_0_conv2_reuse_2[v1433][1][xx_15];        // L472
            conv5_x_0_conv2_reuse_2[v1433][0][xx_15] = v1434;                        // L472
            ap_fixed<10, 4> v1435 = conv5_x_0_conv2_reuse_2[v1433][2][xx_15];        // L472
            conv5_x_0_conv2_reuse_2[v1433][1][xx_15] = v1435;                        // L472
            ap_fixed<10, 4> v1436 = conv5_x_0_conv2_pad[nn_15][v1433][yy_15][xx_15]; // L472
            conv5_x_0_conv2_reuse_2[v1433][2][xx_15] = v1436;                        // L472
          }
          if ((yy_15 - 2) >= 0)
          { // L472
            for (int v1437 = 0; v1437 < 512; v1437++)
            { // L256
              for (int v1438 = 0; v1438 < 3; v1438++)
              {                                                                       // L256
                ap_fixed<10, 4> v1439 = conv5_x_0_conv2_reuse_3[v1437][v1438][1];     // L256
                conv5_x_0_conv2_reuse_3[v1437][v1438][0] = v1439;                     // L256
                ap_fixed<10, 4> v1440 = conv5_x_0_conv2_reuse_3[v1437][v1438][2];     // L256
                conv5_x_0_conv2_reuse_3[v1437][v1438][1] = v1440;                     // L256
                ap_fixed<10, 4> v1441 = conv5_x_0_conv2_reuse_2[v1437][v1438][xx_15]; // L256
                conv5_x_0_conv2_reuse_3[v1437][v1438][2] = v1441;                     // L256
              }
            }
            if ((xx_15 - 2) >= 0)
            {                            // L256
              ap_fixed<10, 4> sum_15;    // L256
              ap_fixed<10, 4> v1443 = 0; // L472
              sum_15 = v1443;            // L472
            l_rc_15:
              for (int rc_15 = 0; rc_15 < 512; rc_15++)
              { // L256
              l_ry_15:
                for (int ry_15 = 0; ry_15 < 3; ry_15++)
                { // L256
                l_rx_15:
                  for (int rx_15 = 0; rx_15 < 3; rx_15++)
                  { // L256
                    if (1)
                    {                                                                       // L472
                      ap_fixed<10, 4> v1447 = conv5_x_0_conv2_reuse_3[rc_15][ry_15][rx_15]; // L472
                      ap_fixed<10, 4> v1448 = v81[ff_15][rc_15][ry_15][rx_15];              // L36
                      ap_fixed<20, 8> v1449 = v1447;                                        // L472
                      ap_fixed<20, 8> v1450 = v1448;                                        // L472
                      ap_fixed<20, 8> v1451 = v1449 * v1450;                                // L472
                      ap_fixed<10, 4> v1452 = sum_15;                                       // L256
                      ap_fixed<21, 9> v1453 = v1451;                                        // L472
                      ap_fixed<21, 9> v1454 = v1452;                                        // L472
                      ap_fixed<21, 9> v1455 = v1453 + v1454;                                // L472
                      ap_fixed<10, 4> v1456 = v1455;                                        // L472
                      sum_15 = v1456;                                                       // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v1457 = sum_15;                                  // L256
              conv5_x_0_conv2[nn_15][ff_15][(yy_15 - 2)][(xx_15 - 2)] = v1457; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_bn2[2][512][4][4];   // L472
  ap_fixed<10, 4> conv5_x_0_convs[2][512][4][4]; // L472
l_conv5_x_0_convs_nn_16:
  for (int nn_16 = 0; nn_16 < 2; nn_16++)
  { // L472
  l_ff_16:
    for (int ff_16 = 0; ff_16 < 512; ff_16++)
    { // L472
    l_yy_16:
      for (int yy_16 = 0; yy_16 < 4; yy_16++)
      { // L472
      l_xx_16:
        for (int xx_16 = 0; xx_16 < 4; xx_16++)
        {                            // L472
          ap_fixed<10, 4> sum_16;    // L256
          ap_fixed<10, 4> v1465 = 0; // L472
          sum_16 = v1465;            // L472
        l_rc_16:
          for (int rc_16 = 0; rc_16 < 256; rc_16++)
          { // L256
            if (1)
            {                                                                                              // L472
              ap_fixed<10, 4> v1467 = conv4_x_1_relu2[nn_16][rc_16][((yy_16 * 2) + 0)][((xx_16 * 2) + 0)]; // L472
              ap_fixed<10, 4> v1468 = v86[ff_16][rc_16][0][0];                                             // L39
              ap_fixed<20, 8> v1469 = v1467;                                                               // L472
              ap_fixed<20, 8> v1470 = v1468;                                                               // L472
              ap_fixed<20, 8> v1471 = v1469 * v1470;                                                       // L472
              ap_fixed<10, 4> v1472 = sum_16;                                                              // L256
              ap_fixed<21, 9> v1473 = v1471;                                                               // L472
              ap_fixed<21, 9> v1474 = v1472;                                                               // L472
              ap_fixed<21, 9> v1475 = v1473 + v1474;                                                       // L472
              ap_fixed<10, 4> v1476 = v1475;                                                               // L472
              sum_16 = v1476;                                                                              // L472
            }
          }
          ap_fixed<10, 4> v1477 = sum_16;                      // L256
          conv5_x_0_convs[nn_16][ff_16][yy_16][xx_16] = v1477; // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_bns[2][512][4][4]; // L472
l_conv5_x_0_bns_i0_51:
  for (int i0_51 = 0; i0_51 < 2; i0_51++)
  { // L472
  l_i1_51:
    for (int i1_51 = 0; i1_51 < 512; i1_51++)
    { // L472
    l_i2_51:
      for (int i2_51 = 0; i2_51 < 4; i2_51++)
      { // L472
      l_i3_51:
        for (int i3_51 = 0; i3_51 < 4; i3_51++)
        {                                                                      // L472
          ap_fixed<10, 4> v1483 = conv5_x_0_convs[i0_51][i1_51][i2_51][i3_51]; // L472
          ap_fixed<10, 4> v1484 = v89[i1_51];                                  // L44
          ap_fixed<11, 5> v1485 = v1483;                                       // L472
          ap_fixed<11, 5> v1486 = v1484;                                       // L472
          ap_fixed<11, 5> v1487 = v1485 - v1486;                               // L472
          ap_fixed<10, 4> v1488 = v90[i1_51];                                  // L44
          double v1489 = v1488;                                                // L472
          double v1490 = v1489 + 0.000000;                                     // L44
          double v1491 = sqrt(v1490);                                          // L41
          double v1492 = v1487;                                                // L472
          double v1493 = v1492 / v1491;                                        // L472
          ap_fixed<10, 4> v1494 = v87[i1_51];                                  // L44
          double v1495 = v1494;                                                // L472
          double v1496 = v1493 * v1495;                                        // L472
          ap_fixed<10, 4> v1497 = v88[i1_51];                                  // L44
          double v1498 = v1497;                                                // L472
          double v1499 = v1496 + v1498;                                        // L472
          ap_fixed<10, 4> v1500 = v1499;                                       // L472
          conv5_x_0_bns[i0_51][i1_51][i2_51][i3_51] = v1500;                   // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_add[2][512][4][4];   // L472
  ap_fixed<10, 4> conv5_x_0_relu2[2][512][4][4]; // L472
l_conv5_x_0_relu2_i0_53:
  for (int i0_53 = 0; i0_53 < 2; i0_53++)
  { // L472
  l_i1_53:
    for (int i1_53 = 0; i1_53 < 512; i1_53++)
    { // L472
    l_i2_53:
      for (int i2_53 = 0; i2_53 < 4; i2_53++)
      { // L472
      l_i3_53:
        for (int i3_53 = 0; i3_53 < 4; i3_53++)
        {                                                                                     // L472
          ap_fixed<10, 4> v1507 = conv5_x_0_bn2[i0_53][i1_53][i2_53][i3_53];                  // L472
          ap_fixed<10, 4> v1508 = conv5_x_0_bns[i0_53][i1_53][i2_53][i3_53];                  // L472
          ap_fixed<11, 5> v1509 = v1507;                                                      // L472
          ap_fixed<11, 5> v1510 = v1508;                                                      // L472
          ap_fixed<11, 5> v1511 = v1509 + v1510;                                              // L472
          ap_fixed<10, 4> v1512 = v1511;                                                      // L472
          ap_fixed<10, 4> v1513 = conv5_x_0_conv2[i0_53][i1_53][i2_53][i3_53];                // L472
          ap_fixed<10, 4> v1514 = v84[i1_53];                                                 // L44
          ap_fixed<11, 5> v1515 = v1513;                                                      // L472
          ap_fixed<11, 5> v1516 = v1514;                                                      // L472
          ap_fixed<11, 5> v1517 = v1515 - v1516;                                              // L472
          ap_fixed<10, 4> v1518 = v85[i1_53];                                                 // L44
          double v1519 = v1518;                                                               // L472
          double v1520 = v1519 + 0.000000;                                                    // L44
          double v1521 = sqrt(v1520);                                                         // L41
          double v1522 = v1517;                                                               // L472
          double v1523 = v1522 / v1521;                                                       // L472
          ap_fixed<10, 4> v1524 = v82[i1_53];                                                 // L44
          double v1525 = v1524;                                                               // L472
          double v1526 = v1523 * v1525;                                                       // L472
          ap_fixed<10, 4> v1527 = v83[i1_53];                                                 // L44
          double v1528 = v1527;                                                               // L472
          double v1529 = v1526 + v1528;                                                       // L472
          ap_fixed<10, 4> v1530 = v1529;                                                      // L472
          conv5_x_0_bn2[i0_53][i1_53][i2_53][i3_53] = v1530;                                  // L472
          ap_fixed<38, 32> v1531 = v1512;                                                     // L472
          ap_fixed<38, 32> v1532 = 0;                                                         // L472
          bool v1533 = v1531 <= v1532;                                                        // L472
          ap_fixed<10, 4> v1534 = conv5_x_0_add[i0_53][i1_53][i2_53][i3_53];                  // L472
          ap_fixed<38, 32> v1535 = 0;                                                         // L472
          ap_fixed<38, 32> v1536 = v1534;                                                     // L472
          ap_fixed<38, 32> v1537 = v1533 ? (ap_fixed<38, 32>)v1535 : (ap_fixed<38, 32>)v1536; // L127
          ap_fixed<10, 4> v1538 = v1537;                                                      // L472
          conv5_x_0_relu2[i0_53][i1_53][i2_53][i3_53] = v1538;                                // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_conv1_pad[2][512][6][6]; // L472
l_conv5_x_1_conv1_pad_i0_54:
  for (int i0_54 = 0; i0_54 < 2; i0_54++)
  { // L472
  l_i1_54:
    for (int i1_54 = 0; i1_54 < 512; i1_54++)
    { // L472
    l_i2_54:
      for (int i2_54 = 0; i2_54 < 6; i2_54++)
      { // L472
      l_i3_54:
        for (int i3_54 = 0; i3_54 < 6; i3_54++)
        {                                                                                  // L472
          ap_int<33> v1544 = i2_54;                                                        // L472
          ap_int<33> v1545 = 1;                                                            // L472
          bool v1546 = v1544 >= v1545;                                                     // L472
          bool v1547 = 1 & v1546;                                                          // L30
          ap_int<33> v1548 = 5;                                                            // L472
          bool v1549 = v1544 < v1548;                                                      // L472
          bool v1550 = v1547 & v1549;                                                      // L30
          ap_int<33> v1551 = i3_54;                                                        // L472
          bool v1552 = v1551 >= v1545;                                                     // L472
          bool v1553 = v1550 & v1552;                                                      // L30
          bool v1554 = v1551 < v1548;                                                      // L472
          bool v1555 = v1553 & v1554;                                                      // L30
          ap_fixed<10, 4> v1556 = conv5_x_0_relu2[i0_54][i1_54][(i2_54 - 1)][(i3_54 - 1)]; // L472
          ap_fixed<10, 4> v1557 = 0.000000;                                                // L472
          ap_fixed<10, 4> v1558 = v1555 ? (ap_fixed<10, 4>)v1556 : (ap_fixed<10, 4>)v1557; // L127
          conv5_x_1_conv1_pad[i0_54][i1_54][i2_54][i3_54] = v1558;                         // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_conv1[2][512][4][4];      // L472
  ap_fixed<10, 4> conv5_x_1_conv1_reuse_2[512][3][6]; // L472
#pragma HLS array_partition variable = conv5_x_1_conv1_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv5_x_1_conv1_reuse_3[512][3][3]; // L472
#pragma HLS array_partition variable = conv5_x_1_conv1_reuse_3 complete dim = 3

l_conv5_x_1_conv1_nn_17:
  for (int nn_17 = 0; nn_17 < 2; nn_17++)
  { // L472
  l_ff_17:
    for (int ff_17 = 0; ff_17 < 512; ff_17++)
    { // L472
    l_yy_17:
      for (int yy_17 = 0; yy_17 < 6; yy_17++)
      { // L472
      l_xx_17:
        for (int xx_17 = 0; xx_17 < 6; xx_17++)
        { // L472
          for (int v1566 = 0; v1566 < 512; v1566++)
          {                                                                          // L472
            ap_fixed<10, 4> v1567 = conv5_x_1_conv1_reuse_2[v1566][1][xx_17];        // L472
            conv5_x_1_conv1_reuse_2[v1566][0][xx_17] = v1567;                        // L472
            ap_fixed<10, 4> v1568 = conv5_x_1_conv1_reuse_2[v1566][2][xx_17];        // L472
            conv5_x_1_conv1_reuse_2[v1566][1][xx_17] = v1568;                        // L472
            ap_fixed<10, 4> v1569 = conv5_x_1_conv1_pad[nn_17][v1566][yy_17][xx_17]; // L472
            conv5_x_1_conv1_reuse_2[v1566][2][xx_17] = v1569;                        // L472
          }
          if ((yy_17 - 2) >= 0)
          { // L472
            for (int v1570 = 0; v1570 < 512; v1570++)
            { // L256
              for (int v1571 = 0; v1571 < 3; v1571++)
              {                                                                       // L256
                ap_fixed<10, 4> v1572 = conv5_x_1_conv1_reuse_3[v1570][v1571][1];     // L256
                conv5_x_1_conv1_reuse_3[v1570][v1571][0] = v1572;                     // L256
                ap_fixed<10, 4> v1573 = conv5_x_1_conv1_reuse_3[v1570][v1571][2];     // L256
                conv5_x_1_conv1_reuse_3[v1570][v1571][1] = v1573;                     // L256
                ap_fixed<10, 4> v1574 = conv5_x_1_conv1_reuse_2[v1570][v1571][xx_17]; // L256
                conv5_x_1_conv1_reuse_3[v1570][v1571][2] = v1574;                     // L256
              }
            }
            if ((xx_17 - 2) >= 0)
            {                            // L256
              ap_fixed<10, 4> sum_17;    // L256
              ap_fixed<10, 4> v1576 = 0; // L472
              sum_17 = v1576;            // L472
            l_rc_17:
              for (int rc_17 = 0; rc_17 < 512; rc_17++)
              { // L256
              l_ry_17:
                for (int ry_17 = 0; ry_17 < 3; ry_17++)
                { // L256
                l_rx_17:
                  for (int rx_17 = 0; rx_17 < 3; rx_17++)
                  { // L256
                    if (1)
                    {                                                                       // L472
                      ap_fixed<10, 4> v1580 = conv5_x_1_conv1_reuse_3[rc_17][ry_17][rx_17]; // L472
                      ap_fixed<10, 4> v1581 = v91[ff_17][rc_17][ry_17][rx_17];              // L34
                      ap_fixed<20, 8> v1582 = v1580;                                        // L472
                      ap_fixed<20, 8> v1583 = v1581;                                        // L472
                      ap_fixed<20, 8> v1584 = v1582 * v1583;                                // L472
                      ap_fixed<10, 4> v1585 = sum_17;                                       // L256
                      ap_fixed<21, 9> v1586 = v1584;                                        // L472
                      ap_fixed<21, 9> v1587 = v1585;                                        // L472
                      ap_fixed<21, 9> v1588 = v1586 + v1587;                                // L472
                      ap_fixed<10, 4> v1589 = v1588;                                        // L472
                      sum_17 = v1589;                                                       // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v1590 = sum_17;                                  // L256
              conv5_x_1_conv1[nn_17][ff_17][(yy_17 - 2)][(xx_17 - 2)] = v1590; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_bn1[2][512][4][4];   // L472
  ap_fixed<10, 4> conv5_x_1_relu1[2][512][4][4]; // L472
l_conv5_x_1_relu1_i0_56:
  for (int i0_56 = 0; i0_56 < 2; i0_56++)
  { // L472
  l_i1_56:
    for (int i1_56 = 0; i1_56 < 512; i1_56++)
    { // L472
    l_i2_56:
      for (int i2_56 = 0; i2_56 < 4; i2_56++)
      { // L472
      l_i3_56:
        for (int i3_56 = 0; i3_56 < 4; i3_56++)
        {                                                                                     // L472
          ap_fixed<10, 4> v1597 = conv5_x_1_conv1[i0_56][i1_56][i2_56][i3_56];                // L472
          ap_fixed<10, 4> v1598 = v94[i1_56];                                                 // L52
          ap_fixed<11, 5> v1599 = v1597;                                                      // L472
          ap_fixed<11, 5> v1600 = v1598;                                                      // L472
          ap_fixed<11, 5> v1601 = v1599 - v1600;                                              // L472
          ap_fixed<10, 4> v1602 = v95[i1_56];                                                 // L52
          double v1603 = v1602;                                                               // L472
          double v1604 = v1603 + 0.000000;                                                    // L52
          double v1605 = sqrt(v1604);                                                         // L41
          double v1606 = v1601;                                                               // L472
          double v1607 = v1606 / v1605;                                                       // L472
          ap_fixed<10, 4> v1608 = v92[i1_56];                                                 // L52
          double v1609 = v1608;                                                               // L472
          double v1610 = v1607 * v1609;                                                       // L472
          ap_fixed<10, 4> v1611 = v93[i1_56];                                                 // L52
          double v1612 = v1611;                                                               // L472
          double v1613 = v1610 + v1612;                                                       // L472
          ap_fixed<10, 4> v1614 = v1613;                                                      // L472
          ap_fixed<38, 32> v1615 = v1614;                                                     // L472
          ap_fixed<38, 32> v1616 = 0;                                                         // L472
          bool v1617 = v1615 <= v1616;                                                        // L472
          ap_fixed<10, 4> v1618 = conv5_x_1_bn1[i0_56][i1_56][i2_56][i3_56];                  // L472
          ap_fixed<38, 32> v1619 = 0;                                                         // L472
          ap_fixed<38, 32> v1620 = v1618;                                                     // L472
          ap_fixed<38, 32> v1621 = v1617 ? (ap_fixed<38, 32>)v1619 : (ap_fixed<38, 32>)v1620; // L127
          ap_fixed<10, 4> v1622 = v1621;                                                      // L472
          conv5_x_1_relu1[i0_56][i1_56][i2_56][i3_56] = v1622;                                // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_conv2_pad[2][512][6][6]; // L472
l_conv5_x_1_conv2_pad_i0_57:
  for (int i0_57 = 0; i0_57 < 2; i0_57++)
  { // L472
  l_i1_57:
    for (int i1_57 = 0; i1_57 < 512; i1_57++)
    { // L472
    l_i2_57:
      for (int i2_57 = 0; i2_57 < 6; i2_57++)
      { // L472
      l_i3_57:
        for (int i3_57 = 0; i3_57 < 6; i3_57++)
        {                                                                                  // L472
          ap_int<33> v1628 = i2_57;                                                        // L472
          ap_int<33> v1629 = 1;                                                            // L472
          bool v1630 = v1628 >= v1629;                                                     // L472
          bool v1631 = 1 & v1630;                                                          // L30
          ap_int<33> v1632 = 5;                                                            // L472
          bool v1633 = v1628 < v1632;                                                      // L472
          bool v1634 = v1631 & v1633;                                                      // L30
          ap_int<33> v1635 = i3_57;                                                        // L472
          bool v1636 = v1635 >= v1629;                                                     // L472
          bool v1637 = v1634 & v1636;                                                      // L30
          bool v1638 = v1635 < v1632;                                                      // L472
          bool v1639 = v1637 & v1638;                                                      // L30
          ap_fixed<10, 4> v1640 = conv5_x_1_relu1[i0_57][i1_57][(i2_57 - 1)][(i3_57 - 1)]; // L472
          ap_fixed<10, 4> v1641 = 0.000000;                                                // L472
          ap_fixed<10, 4> v1642 = v1639 ? (ap_fixed<10, 4>)v1640 : (ap_fixed<10, 4>)v1641; // L127
          conv5_x_1_conv2_pad[i0_57][i1_57][i2_57][i3_57] = v1642;                         // L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_conv2[2][512][4][4];      // L472
  ap_fixed<10, 4> conv5_x_1_conv2_reuse_2[512][3][6]; // L472
#pragma HLS array_partition variable = conv5_x_1_conv2_reuse_2 complete dim = 2

  ap_fixed<10, 4> conv5_x_1_conv2_reuse_3[512][3][3]; // L472
#pragma HLS array_partition variable = conv5_x_1_conv2_reuse_3 complete dim = 3

l_conv5_x_1_conv2_nn_18:
  for (int nn_18 = 0; nn_18 < 2; nn_18++)
  { // L472
  l_ff_18:
    for (int ff_18 = 0; ff_18 < 512; ff_18++)
    { // L472
    l_yy_18:
      for (int yy_18 = 0; yy_18 < 6; yy_18++)
      { // L472
      l_xx_18:
        for (int xx_18 = 0; xx_18 < 6; xx_18++)
        { // L472
          for (int v1650 = 0; v1650 < 512; v1650++)
          {                                                                          // L472
            ap_fixed<10, 4> v1651 = conv5_x_1_conv2_reuse_2[v1650][1][xx_18];        // L472
            conv5_x_1_conv2_reuse_2[v1650][0][xx_18] = v1651;                        // L472
            ap_fixed<10, 4> v1652 = conv5_x_1_conv2_reuse_2[v1650][2][xx_18];        // L472
            conv5_x_1_conv2_reuse_2[v1650][1][xx_18] = v1652;                        // L472
            ap_fixed<10, 4> v1653 = conv5_x_1_conv2_pad[nn_18][v1650][yy_18][xx_18]; // L472
            conv5_x_1_conv2_reuse_2[v1650][2][xx_18] = v1653;                        // L472
          }
          if ((yy_18 - 2) >= 0)
          { // L472
            for (int v1654 = 0; v1654 < 512; v1654++)
            { // L256
              for (int v1655 = 0; v1655 < 3; v1655++)
              {                                                                       // L256
                ap_fixed<10, 4> v1656 = conv5_x_1_conv2_reuse_3[v1654][v1655][1];     // L256
                conv5_x_1_conv2_reuse_3[v1654][v1655][0] = v1656;                     // L256
                ap_fixed<10, 4> v1657 = conv5_x_1_conv2_reuse_3[v1654][v1655][2];     // L256
                conv5_x_1_conv2_reuse_3[v1654][v1655][1] = v1657;                     // L256
                ap_fixed<10, 4> v1658 = conv5_x_1_conv2_reuse_2[v1654][v1655][xx_18]; // L256
                conv5_x_1_conv2_reuse_3[v1654][v1655][2] = v1658;                     // L256
              }
            }
            if ((xx_18 - 2) >= 0)
            {                            // L256
              ap_fixed<10, 4> sum_18;    // L256
              ap_fixed<10, 4> v1660 = 0; // L472
              sum_18 = v1660;            // L472
            l_rc_18:
              for (int rc_18 = 0; rc_18 < 512; rc_18++)
              { // L256
              l_ry_18:
                for (int ry_18 = 0; ry_18 < 3; ry_18++)
                { // L256
                l_rx_18:
                  for (int rx_18 = 0; rx_18 < 3; rx_18++)
                  { // L256
                    if (1)
                    {                                                                       // L472
                      ap_fixed<10, 4> v1664 = conv5_x_1_conv2_reuse_3[rc_18][ry_18][rx_18]; // L472
                      ap_fixed<10, 4> v1665 = v96[ff_18][rc_18][ry_18][rx_18];              // L36
                      ap_fixed<20, 8> v1666 = v1664;                                        // L472
                      ap_fixed<20, 8> v1667 = v1665;                                        // L472
                      ap_fixed<20, 8> v1668 = v1666 * v1667;                                // L472
                      ap_fixed<10, 4> v1669 = sum_18;                                       // L256
                      ap_fixed<21, 9> v1670 = v1668;                                        // L472
                      ap_fixed<21, 9> v1671 = v1669;                                        // L472
                      ap_fixed<21, 9> v1672 = v1670 + v1671;                                // L472
                      ap_fixed<10, 4> v1673 = v1672;                                        // L472
                      sum_18 = v1673;                                                       // L472
                    }
                  }
                }
              }
              ap_fixed<10, 4> v1674 = sum_18;                                  // L256
              conv5_x_1_conv2[nn_18][ff_18][(yy_18 - 2)][(xx_18 - 2)] = v1674; // L472
            }
          }
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_bn2[2][512][4][4];   // L472
  ap_fixed<10, 4> conv5_x_1_add[2][512][4][4];   // L472
  ap_fixed<10, 4> conv5_x_1_relu2[2][512][4][4]; // L472
l_conv5_x_1_relu2_i0_60:
  for (int i0_60 = 0; i0_60 < 2; i0_60++)
  { // L472
  l_i1_60:
    for (int i1_60 = 0; i1_60 < 512; i1_60++)
    { // L472
    l_i2_60:
      for (int i2_60 = 0; i2_60 < 4; i2_60++)
      { // L472
      l_i3_60:
        for (int i3_60 = 0; i3_60 < 4; i3_60++)
        {                                                                                     // L472
          ap_fixed<10, 4> v1682 = conv5_x_1_bn2[i0_60][i1_60][i2_60][i3_60];                  // L472
          ap_fixed<10, 4> v1683 = conv5_x_0_relu2[i0_60][i1_60][i2_60][i3_60];                // L472
          ap_fixed<11, 5> v1684 = v1682;                                                      // L472
          ap_fixed<11, 5> v1685 = v1683;                                                      // L472
          ap_fixed<11, 5> v1686 = v1684 + v1685;                                              // L472
          ap_fixed<10, 4> v1687 = v1686;                                                      // L472
          ap_fixed<10, 4> v1688 = conv5_x_1_conv2[i0_60][i1_60][i2_60][i3_60];                // L472
          ap_fixed<10, 4> v1689 = v99[i1_60];                                                 // L52
          ap_fixed<11, 5> v1690 = v1688;                                                      // L472
          ap_fixed<11, 5> v1691 = v1689;                                                      // L472
          ap_fixed<11, 5> v1692 = v1690 - v1691;                                              // L472
          ap_fixed<10, 4> v1693 = v100[i1_60];                                                // L52
          double v1694 = v1693;                                                               // L472
          double v1695 = v1694 + 0.000000;                                                    // L52
          double v1696 = sqrt(v1695);                                                         // L41
          double v1697 = v1692;                                                               // L472
          double v1698 = v1697 / v1696;                                                       // L472
          ap_fixed<10, 4> v1699 = v97[i1_60];                                                 // L52
          double v1700 = v1699;                                                               // L472
          double v1701 = v1698 * v1700;                                                       // L472
          ap_fixed<10, 4> v1702 = v98[i1_60];                                                 // L52
          double v1703 = v1702;                                                               // L472
          double v1704 = v1701 + v1703;                                                       // L472
          ap_fixed<10, 4> v1705 = v1704;                                                      // L472
          conv5_x_1_bn2[i0_60][i1_60][i2_60][i3_60] = v1705;                                  // L472
          ap_fixed<38, 32> v1706 = v1687;                                                     // L472
          ap_fixed<38, 32> v1707 = 0;                                                         // L472
          bool v1708 = v1706 <= v1707;                                                        // L472
          ap_fixed<10, 4> v1709 = conv5_x_1_add[i0_60][i1_60][i2_60][i3_60];                  // L472
          ap_fixed<38, 32> v1710 = 0;                                                         // L472
          ap_fixed<38, 32> v1711 = v1709;                                                     // L472
          ap_fixed<38, 32> v1712 = v1708 ? (ap_fixed<38, 32>)v1710 : (ap_fixed<38, 32>)v1711; // L127
          ap_fixed<10, 4> v1713 = v1712;                                                      // L472
          conv5_x_1_relu2[i0_60][i1_60][i2_60][i3_60] = v1713;                                // L472
        }
      }
    }
  }
  ap_fixed<10, 4> avg[2][512][1][1]; // L472
l_avg_i:
  for (int i = 0; i < 2; i++)
  { // L472
  l_c:
    for (int c = 0; c < 512; c++)
    {                            // L472
      ap_fixed<10, 4> sum_19;    // L256
      ap_fixed<10, 4> v1718 = 0; // L472
      sum_19 = v1718;            // L472
    l_r_9:
      for (int r_9 = 0; r_9 < 4; r_9++)
      { // L256
      l_r_10:
        for (int r_10 = 0; r_10 < 4; r_10++)
        { // L256
          if (1)
          {                                                                       // L472
            ap_fixed<10, 4> v1721 = conv5_x_1_relu2[i][c][(0 + r_9)][(0 + r_10)]; // L472
            ap_fixed<10, 4> v1722 = sum_19;                                       // L256
            ap_fixed<11, 5> v1723 = v1721;                                        // L472
            ap_fixed<11, 5> v1724 = v1722;                                        // L472
            ap_fixed<11, 5> v1725 = v1723 + v1724;                                // L472
            ap_fixed<10, 4> v1726 = v1725;                                        // L472
            sum_19 = v1726;                                                       // L472
          }
        }
      }
      ap_fixed<10, 4> v1727 = sum_19;        // L256
      ap_fixed<42, 4> v1728 = v1727;         // L472
      ap_fixed<42, 4> v1729 = 16;            // L472
      ap_fixed<42, 4> v1730 = v1728 / v1729; // L256
      ap_fixed<10, 4> v1731 = v1730;         // L472
      avg[i][c][0][0] = v1731;               // L472
    }
  }
  ap_fixed<10, 4> avg_view[2][512]; // L472
l_avg_view_b:
  for (int b = 0; b < 2; b++)
  { // L472
  l_c_0:
    for (int c_0 = 0; c_0 < 512; c_0++)
    {                                            // L472
      ap_fixed<10, 4> v1735 = avg[b][c_0][0][0]; // L472
      avg_view[b][c_0] = v1735;                  // L472
    }
  }
l_linear_x:
  for (int x = 0; x < 2; x++)
  { // L472
  l_y:
    for (int y = 0; y < 100; y++)
    {                 // L472
      int32_t sum_20; // L256
      sum_20 = 0;     // L472
    l_r_11:
      for (int r_11 = 0; r_11 < 512; r_11++)
      { // L256
        if (1)
        {                                            // L472
          ap_fixed<10, 4> v1740 = avg_view[x][r_11]; // L472
          ap_fixed<10, 4> v1741 = v101[x][r_11];     // L103
          ap_fixed<20, 8> v1742 = v1740;             // L472
          ap_fixed<20, 8> v1743 = v1741;             // L472
          ap_fixed<20, 8> v1744 = v1742 * v1743;     // L472
          int32_t v1745 = sum_20;                    // L256
          ap_fixed<45, 33> v1746 = v1744;            // L472
          ap_fixed<45, 33> v1747 = v1745;            // L472
          ap_fixed<45, 33> v1748 = v1746 + v1747;    // L472
          int32_t v1749 = v1748;                     // L472
          sum_20 = v1749;                            // L472
        }
      }
      int32_t v1750 = sum_20;                 // L256
      ap_fixed<10, 4> v1751 = v102[y];        // L104
      ap_fixed<39, 33> v1752 = v1750;         // L472
      ap_fixed<39, 33> v1753 = v1751;         // L472
      ap_fixed<39, 33> v1754 = v1752 + v1753; // L256
      ap_fixed<10, 4> v1755 = v1754;          // L472
      v103[x][y] = v1755;                     // L472
    }
  }
}
