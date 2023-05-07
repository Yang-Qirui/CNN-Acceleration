
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
    float v0[2][1][32][32],
    float v1[6][1][5][5],
    float v2[6],
    float v3[16][6][5][5],
    float v4[16],
    float v5[16][6][5][5],
    float v6[16],
    float v7[120][16][5][5],
    float v8[120],
    float v9[84][120],
    float v10[84],
    float v11[10][84],
    float v12[10],
    float v13[2][10])
{ // L28
  // #pragma HLS array_partition variable = v0 complete dim = 3
  // #pragma HLS array_partition variable = v0 complete dim = 4

  // #pragma HLS array_partition variable = v1 complete dim = 3
  // #pragma HLS array_partition variable = v1 complete dim = 4

  // #pragma HLS array_partition variable = v3 complete dim = 3
  // #pragma HLS array_partition variable = v3 complete dim = 4

  // #pragma HLS array_partition variable = v5 complete dim = 3
  // #pragma HLS array_partition variable = v5 complete dim = 4

  // #pragma HLS array_partition variable = v7 complete dim = 3
  // #pragma HLS array_partition variable = v7 complete dim = 4

  static float c1_conv1[2][6][28][28]; // L472
l_c1_conv1_nn:
  for (int nn = 0; nn < 2; nn++)
  { // L472
  l_ff:
    for (int ff = 0; ff < 6; ff++)
    { // L472
    l_yy:
      for (int yy = 0; yy < 28; yy++)
      { // L472
      l_xx:
        for (int xx = 0; xx < 28; xx++)
        {                // L472
                         // #pragma HLS pipeline
          float sum;     // L256
          float v20 = 0; // L472
          sum = v20;     // L472
        l_ry:
          for (int ry = 0; ry < 5; ry++)
          { // L256
          l_rx:
            for (int rx = 0; rx < 5; rx++)
            { // L256
              if (1)
              {                                              // L472
                float v23 = v0[nn][0][(yy + ry)][(xx + rx)]; // L13
                float v24 = v1[ff][0][ry][rx];               // L15
                float v25 = v23 * v24;                       // L13
                float v26 = sum;                             // L256
                float v27 = v25 + v26;                       // L13
                sum = v27;                                   // L472
              }
            }
          }
          float v28 = sum;                // L256
          float v29 = v2[ff];             // L16
          float v30 = v28 + v29;          // L256
          c1_conv1[nn][ff][yy][xx] = v30; // L472
        }
      }
    }
  }
  static float c1_relu1[2][6][28][28]; // L472
l_c1_relu1_i0:
  for (int i0 = 0; i0 < 2; i0++)
  { // L472
  l_i1:
    for (int i1 = 0; i1 < 6; i1++)
    { // L472
    l_i2:
      for (int i2 = 0; i2 < 28; i2++)
      { // L472
        // #pragma HLS pipeline
      l_i3:
        for (int i3 = 0; i3 < 28; i3++)
        {                                            // L472
          float v36 = c1_conv1[i0][i1][i2][i3];      // L472
          float v37 = 0;                             // L472
          bool v38 = v36 <= v37;                     // L472
          float v39 = v38 ? (float)v37 : (float)v36; // L127
          c1_relu1[i0][i1][i2][i3] = v39;            // L472
        }
      }
    }
  }
  static float c1_maxpool_pad[2][6][28][28]; // L472
l_c1_maxpool_pad_i0_0:
  for (int i0_0 = 0; i0_0 < 2; i0_0++)
  { // L472
  l_i1_0:
    for (int i1_0 = 0; i1_0 < 6; i1_0++)
    { // L472
    l_i2_0:
      for (int i2_0 = 0; i2_0 < 28; i2_0++)
      { // L472
        // #pragma HLS pipeline
      l_i3_0:
        for (int i3_0 = 0; i3_0 < 28; i3_0++)
        {                                               // L472
          float v45 = c1_relu1[i0_0][i1_0][i2_0][i3_0]; // L472
          c1_maxpool_pad[i0_0][i1_0][i2_0][i3_0] = v45; // L472
        }
      }
    }
  }
  static float c1_maxpool[2][6][14][14]; // L472
l_c1_maxpool_i:
  for (int i = 0; i < 2; i++)
  { // L472
  l_c:
    for (int c = 0; c < 6; c++)
    { // L472
    l_h:
      for (int h = 0; h < 14; h++)
      { // L472
      l_w:
        for (int w = 0; w < 14; w++)
        {                        // L472
                                 // #pragma HLS pipeline
          float maximum;         // L256
          maximum = -2147483648; // L472
        l_r_3:
          for (int r_3 = 0; r_3 < 2; r_3++)
          { // L256
          l_r_4:
            for (int r_4 = 0; r_4 < 2; r_4++)
            { // L256
              if (1)
              {                                                                     // L472
                float v54 = c1_maxpool_pad[i][c][((h * 2) + r_3)][((w * 2) + r_4)]; // L472
                float v55 = maximum;                                                // L256
                float v56 = v54;                                                    // L472
                float v57 = max(v56, v55);                                          // L256
                maximum = v57;                                                      // L472
              }
            }
          }
          float v58 = maximum;          // L256
          float v59 = v58;              // L472
          c1_maxpool[i][c][h][w] = v59; // L472
        }
      }
    }
  }
  static float c2_1_conv1[2][16][10][10];   // L472
  static float c2_1_conv1_reuse_3[6][5][5]; // L472
  // #pragma HLS array_partition variable = c2_1_conv1_reuse_3 complete dim = 3

l_c2_1_conv1_nn_0:
  for (int nn_0 = 0; nn_0 < 2; nn_0++)
  { // L472
  l_ff_0:
    for (int ff_0 = 0; ff_0 < 16; ff_0++)
    { // L472
    l_yy_0:
      for (int yy_0 = 0; yy_0 < 10; yy_0++)
      { // L472
      l_xx_0:
        for (int xx_0 = 0; xx_0 < 14; xx_0++)
        { // L472
          // #pragma HLS pipeline
          for (int v66 = 0; v66 < 6; v66++)
          { // L256
            for (int v67 = 0; v67 < 5; v67++)
            {                                                        // L256
              float v68 = c2_1_conv1_reuse_3[v66][v67][1];           // L256
              c2_1_conv1_reuse_3[v66][v67][0] = v68;                 // L256
              float v69 = c2_1_conv1_reuse_3[v66][v67][2];           // L256
              c2_1_conv1_reuse_3[v66][v67][1] = v69;                 // L256
              float v70 = c2_1_conv1_reuse_3[v66][v67][3];           // L256
              c2_1_conv1_reuse_3[v66][v67][2] = v70;                 // L256
              float v71 = c2_1_conv1_reuse_3[v66][v67][4];           // L256
              c2_1_conv1_reuse_3[v66][v67][3] = v71;                 // L256
              float v72 = c1_maxpool[nn_0][v66][(yy_0 + v67)][xx_0]; // L256
              c2_1_conv1_reuse_3[v66][v67][4] = v72;                 // L256
            }
          }
          if ((xx_0 - 4) >= 0)
          {                // L256
            float sum_0;   // L256
            float v74 = 0; // L472
            sum_0 = v74;   // L472
          l_rc_0:
            for (int rc_0 = 0; rc_0 < 6; rc_0++)
            { // L256
            l_ry_0:
              for (int ry_0 = 0; ry_0 < 5; ry_0++)
              { // L256
              l_rx_0:
                for (int rx_0 = 0; rx_0 < 5; rx_0++)
                { // L256
                  if (1)
                  {                                                   // L472
                    float v78 = c2_1_conv1_reuse_3[rc_0][ry_0][rx_0]; // L472
                    float v79 = v3[ff_0][rc_0][ry_0][rx_0];           // L18
                    float v80 = v78 * v79;                            // L472
                    float v81 = sum_0;                                // L256
                    float v82 = v80 + v81;                            // L472
                    sum_0 = v82;                                      // L472
                  }
                }
              }
            }
            float v83 = sum_0;                              // L256
            float v84 = v4[ff_0];                           // L19
            float v85 = v83 + v84;                          // L256
            c2_1_conv1[nn_0][ff_0][yy_0][(xx_0 - 4)] = v85; // L472
          }
        }
      }
    }
  }
  static float c2_1_relu1[2][16][10][10]; // L472
l_c2_1_relu1_i0_1:
  for (int i0_1 = 0; i0_1 < 2; i0_1++)
  { // L472
  l_i1_1:
    for (int i1_1 = 0; i1_1 < 16; i1_1++)
    { // L472
    l_i2_1:
      for (int i2_1 = 0; i2_1 < 10; i2_1++)
      { // L472
        // #pragma HLS pipeline
      l_i3_1:
        for (int i3_1 = 0; i3_1 < 10; i3_1++)
        {                                                 // L472
          float v91 = c2_1_conv1[i0_1][i1_1][i2_1][i3_1]; // L472
          float v92 = 0;                                  // L472
          bool v93 = v91 <= v92;                          // L472
          float v94 = v93 ? (float)v92 : (float)v91;      // L127
          c2_1_relu1[i0_1][i1_1][i2_1][i3_1] = v94;       // L472
        }
      }
    }
  }
  static float c2_1_maxpool_pad[2][16][10][10]; // L472
l_c2_1_maxpool_pad_i0_2:
  for (int i0_2 = 0; i0_2 < 2; i0_2++)
  { // L472
  l_i1_2:
    for (int i1_2 = 0; i1_2 < 16; i1_2++)
    { // L472
    l_i2_2:
      for (int i2_2 = 0; i2_2 < 10; i2_2++)
      { // L472
        // #pragma HLS pipeline
      l_i3_2:
        for (int i3_2 = 0; i3_2 < 10; i3_2++)
        {                                                  // L472
          float v100 = c2_1_relu1[i0_2][i1_2][i2_2][i3_2]; // L472
          c2_1_maxpool_pad[i0_2][i1_2][i2_2][i3_2] = v100; // L472
        }
      }
    }
  }
  static float c2_1_maxpool[2][16][5][5]; // L472
l_c2_1_maxpool_i_0:
  for (int i_0 = 0; i_0 < 2; i_0++)
  { // L472
  l_c_0:
    for (int c_0 = 0; c_0 < 16; c_0++)
    { // L472
    l_h_0:
      for (int h_0 = 0; h_0 < 5; h_0++)
      { // L472
      l_w_0:
        for (int w_0 = 0; w_0 < 5; w_0++)
        {                          // L472
                                   // #pragma HLS pipeline
          float maximum_0;         // L256
          maximum_0 = -2147483648; // L472
        l_r_5:
          for (int r_5 = 0; r_5 < 2; r_5++)
          { // L256
          l_r_6:
            for (int r_6 = 0; r_6 < 2; r_6++)
            { // L256
              if (1)
              {                                                                                // L472
                float v109 = c2_1_maxpool_pad[i_0][c_0][((h_0 * 2) + r_5)][((w_0 * 2) + r_6)]; // L472
                float v110 = maximum_0;                                                        // L256
                float v111 = v109;                                                             // L472
                float v112 = max(v111, v110);                                                  // L256
                maximum_0 = v112;                                                              // L472
              }
            }
          }
          float v113 = maximum_0;                  // L256
          float v114 = v113;                       // L472
          c2_1_maxpool[i_0][c_0][h_0][w_0] = v114; // L472
        }
      }
    }
  }
  static float c2_2_conv1[2][16][10][10];   // L472
  static float c2_2_conv1_reuse_3[6][5][5]; // L472
  // #pragma HLS array_partition variable = c2_2_conv1_reuse_3 complete dim = 3

l_c2_2_conv1_nn_1:
  for (int nn_1 = 0; nn_1 < 2; nn_1++)
  { // L472
  l_ff_1:
    for (int ff_1 = 0; ff_1 < 16; ff_1++)
    { // L472
    l_yy_1:
      for (int yy_1 = 0; yy_1 < 10; yy_1++)
      { // L472
      l_xx_1:
        for (int xx_1 = 0; xx_1 < 14; xx_1++)
        { // L472
          // #pragma HLS pipeline
          for (int v121 = 0; v121 < 6; v121++)
          { // L256
            for (int v122 = 0; v122 < 5; v122++)
            {                                                           // L256
              float v123 = c2_2_conv1_reuse_3[v121][v122][1];           // L256
              c2_2_conv1_reuse_3[v121][v122][0] = v123;                 // L256
              float v124 = c2_2_conv1_reuse_3[v121][v122][2];           // L256
              c2_2_conv1_reuse_3[v121][v122][1] = v124;                 // L256
              float v125 = c2_2_conv1_reuse_3[v121][v122][3];           // L256
              c2_2_conv1_reuse_3[v121][v122][2] = v125;                 // L256
              float v126 = c2_2_conv1_reuse_3[v121][v122][4];           // L256
              c2_2_conv1_reuse_3[v121][v122][3] = v126;                 // L256
              float v127 = c1_maxpool[nn_1][v121][(yy_1 + v122)][xx_1]; // L256
              c2_2_conv1_reuse_3[v121][v122][4] = v127;                 // L256
            }
          }
          if ((xx_1 - 4) >= 0)
          {                 // L256
            float sum_1;    // L256
            float v129 = 0; // L472
            sum_1 = v129;   // L472
          l_rc_1:
            for (int rc_1 = 0; rc_1 < 6; rc_1++)
            { // L256
            l_ry_1:
              for (int ry_1 = 0; ry_1 < 5; ry_1++)
              { // L256
              l_rx_1:
                for (int rx_1 = 0; rx_1 < 5; rx_1++)
                { // L256
                  if (1)
                  {                                                    // L472
                    float v133 = c2_2_conv1_reuse_3[rc_1][ry_1][rx_1]; // L472
                    float v134 = v5[ff_1][rc_1][ry_1][rx_1];           // L21
                    float v135 = v133 * v134;                          // L472
                    float v136 = sum_1;                                // L256
                    float v137 = v135 + v136;                          // L472
                    sum_1 = v137;                                      // L472
                  }
                }
              }
            }
            float v138 = sum_1;                              // L256
            float v139 = v6[ff_1];                           // L22
            float v140 = v138 + v139;                        // L256
            c2_2_conv1[nn_1][ff_1][yy_1][(xx_1 - 4)] = v140; // L472
          }
        }
      }
    }
  }
  static float c2_2_relu1[2][16][10][10]; // L472
l_c2_2_relu1_i0_3:
  for (int i0_3 = 0; i0_3 < 2; i0_3++)
  { // L472
  l_i1_3:
    for (int i1_3 = 0; i1_3 < 16; i1_3++)
    { // L472
    l_i2_3:
      for (int i2_3 = 0; i2_3 < 10; i2_3++)
      { // L472
        // #pragma HLS pipeline
      l_i3_3:
        for (int i3_3 = 0; i3_3 < 10; i3_3++)
        {                                                  // L472
          float v146 = c2_2_conv1[i0_3][i1_3][i2_3][i3_3]; // L472
          float v147 = 0;                                  // L472
          bool v148 = v146 <= v147;                        // L472
          float v149 = v148 ? (float)v147 : (float)v146;   // L127
          c2_2_relu1[i0_3][i1_3][i2_3][i3_3] = v149;       // L472
        }
      }
    }
  }
  static float c2_2_maxpool_pad[2][16][10][10]; // L472
l_c2_2_maxpool_pad_i0_4:
  for (int i0_4 = 0; i0_4 < 2; i0_4++)
  { // L472
  l_i1_4:
    for (int i1_4 = 0; i1_4 < 16; i1_4++)
    { // L472
    l_i2_4:
      for (int i2_4 = 0; i2_4 < 10; i2_4++)
      { // L472
        // #pragma HLS pipeline
      l_i3_4:
        for (int i3_4 = 0; i3_4 < 10; i3_4++)
        {                                                  // L472
          float v155 = c2_2_relu1[i0_4][i1_4][i2_4][i3_4]; // L472
          c2_2_maxpool_pad[i0_4][i1_4][i2_4][i3_4] = v155; // L472
        }
      }
    }
  }
  static float c2_2_maxpool[2][16][5][5]; // L472
l_c2_2_maxpool_i_1:
  for (int i_1 = 0; i_1 < 2; i_1++)
  { // L472
  l_c_1:
    for (int c_1 = 0; c_1 < 16; c_1++)
    { // L472
    l_h_1:
      for (int h_1 = 0; h_1 < 5; h_1++)
      { // L472
      l_w_1:
        for (int w_1 = 0; w_1 < 5; w_1++)
        {                          // L472
                                   // #pragma HLS pipeline
          float maximum_1;         // L256
          maximum_1 = -2147483648; // L472
        l_r_7:
          for (int r_7 = 0; r_7 < 2; r_7++)
          { // L256
          l_r_8:
            for (int r_8 = 0; r_8 < 2; r_8++)
            { // L256
              if (1)
              {                                                                                // L472
                float v164 = c2_2_maxpool_pad[i_1][c_1][((h_1 * 2) + r_7)][((w_1 * 2) + r_8)]; // L472
                float v165 = maximum_1;                                                        // L256
                float v166 = v164;                                                             // L472
                float v167 = max(v166, v165);                                                  // L256
                maximum_1 = v167;                                                              // L472
              }
            }
          }
          float v168 = maximum_1;                  // L256
          float v169 = v168;                       // L472
          c2_2_maxpool[i_1][c_1][h_1][w_1] = v169; // L472
        }
      }
    }
  }
  static float add[2][16][5][5]; // L472
l_add_i0_5:
  for (int i0_5 = 0; i0_5 < 2; i0_5++)
  { // L472
  l_i1_5:
    for (int i1_5 = 0; i1_5 < 16; i1_5++)
    { // L472
    l_i2_5:
      for (int i2_5 = 0; i2_5 < 5; i2_5++)
      { // L472
        // #pragma HLS pipeline
      l_i3_5:
        for (int i3_5 = 0; i3_5 < 5; i3_5++)
        {                                                    // L472
          float v175 = c2_1_maxpool[i0_5][i1_5][i2_5][i3_5]; // L472
          float v176 = c2_2_maxpool[i0_5][i1_5][i2_5][i3_5]; // L472
          float v177 = v175 + v176;                          // L472
          add[i0_5][i1_5][i2_5][i3_5] = v177;                // L472
        }
      }
    }
  }
  static float c3_conv1[2][120][1][1];     // L472
  static float c3_conv1_reuse_3[16][5][5]; // L472
  // #pragma HLS array_partition variable = c3_conv1_reuse_3 complete dim = 3

l_c3_conv1_nn_2:
  for (int nn_2 = 0; nn_2 < 2; nn_2++)
  { // L472
  l_ff_2:
    for (int ff_2 = 0; ff_2 < 120; ff_2++)
    { // L472
    l_xx_2:
      for (int xx_2 = 0; xx_2 < 5; xx_2++)
      { // L472
        // #pragma HLS pipeline
        for (int v183 = 0; v183 < 16; v183++)
        { // L256
          for (int v184 = 0; v184 < 5; v184++)
          {                                                 // L256
            float v185 = c3_conv1_reuse_3[v183][v184][1];   // L256
            c3_conv1_reuse_3[v183][v184][0] = v185;         // L256
            float v186 = c3_conv1_reuse_3[v183][v184][2];   // L256
            c3_conv1_reuse_3[v183][v184][1] = v186;         // L256
            float v187 = c3_conv1_reuse_3[v183][v184][3];   // L256
            c3_conv1_reuse_3[v183][v184][2] = v187;         // L256
            float v188 = c3_conv1_reuse_3[v183][v184][4];   // L256
            c3_conv1_reuse_3[v183][v184][3] = v188;         // L256
            float v189 = add[nn_2][v183][(0 + v184)][xx_2]; // L256
            c3_conv1_reuse_3[v183][v184][4] = v189;         // L256
          }
        }
        if ((xx_2 - 4) >= 0)
        {                 // L256
          float sum_2;    // L256
          float v191 = 0; // L472
          sum_2 = v191;   // L472
        l_rc_2:
          for (int rc_2 = 0; rc_2 < 16; rc_2++)
          { // L256
          l_ry_2:
            for (int ry_2 = 0; ry_2 < 5; ry_2++)
            { // L256
            l_rx_2:
              for (int rx_2 = 0; rx_2 < 5; rx_2++)
              { // L256
                if (1)
                {                                                  // L472
                  float v195 = c3_conv1_reuse_3[rc_2][ry_2][rx_2]; // L472
                  float v196 = v7[ff_2][rc_2][ry_2][rx_2];         // L24
                  float v197 = v195 * v196;                        // L472
                  float v198 = sum_2;                              // L256
                  float v199 = v197 + v198;                        // L472
                  sum_2 = v199;                                    // L472
                }
              }
            }
          }
          float v200 = sum_2;                         // L256
          float v201 = v8[ff_2];                      // L25
          float v202 = v200 + v201;                   // L256
          c3_conv1[nn_2][ff_2][0][(xx_2 - 4)] = v202; // L472
        }
      }
    }
  }
  static float c3_relu1[2][120][1][1]; // L472
l_c3_relu1_i0_6:
  for (int i0_6 = 0; i0_6 < 2; i0_6++)
  { // L472
  l_i1_6:
    for (int i1_6 = 0; i1_6 < 120; i1_6++)
    {                                                // L472
      float v206 = c3_conv1[i0_6][i1_6][0][0];       // L472
      float v207 = 0;                                // L472
      bool v208 = v206 <= v207;                      // L472
      float v209 = v208 ? (float)v207 : (float)v206; // L127
      c3_relu1[i0_6][i1_6][0][0] = v209;             // L472
    }
  }
  static float c3_view[2][120]; // L472
l_c3_view_b:
  for (int b = 0; b < 2; b++)
  { // L472
  l_c_2:
    for (int c_2 = 0; c_2 < 120; c_2++)
    {                                      // L472
      float v213 = c3_relu1[b][c_2][0][0]; // L472
      c3_view[b][c_2] = v213;              // L472
    }
  }
  static float f4_linear1[2][84]; // L472
l_f4_linear1_x:
  for (int x = 0; x < 2; x++)
  { // L472
  l_y:
    for (int y = 0; y < 84; y++)
    {                 // L472
      float sum_3;    // L256
      float v218 = 0; // L472
      sum_3 = v218;   // L472
    l_r_9:
      for (int r_9 = 0; r_9 < 120; r_9++)
      { // L256
        if (1)
        {                               // L472
          float v220 = c3_view[x][r_9]; // L472
          float v221 = v9[y][r_9];      // L27
          float v222 = v220 * v221;     // L472
          float v223 = sum_3;           // L256
          float v224 = v222 + v223;     // L472
          sum_3 = v224;                 // L472
        }
      }
      float v225 = sum_3;       // L256
      float v226 = v10[y];      // L28
      float v227 = v225 + v226; // L256
      f4_linear1[x][y] = v227;  // L472
    }
  }
  static float f4_relu1[2][84]; // L472
l_f4_relu1_i0_7:
  for (int i0_7 = 0; i0_7 < 2; i0_7++)
  { // L472
  l_i1_7:
    for (int i1_7 = 0; i1_7 < 84; i1_7++)
    {                                                // L472
      float v231 = f4_linear1[i0_7][i1_7];           // L472
      float v232 = 0;                                // L472
      bool v233 = v231 <= v232;                      // L472
      float v234 = v233 ? (float)v232 : (float)v231; // L127
      f4_relu1[i0_7][i1_7] = v234;                   // L472
    }
  }
  static float f5_linear1[2][10]; // L472
l_f5_linear1_x_0:
  for (int x_0 = 0; x_0 < 2; x_0++)
  { // L472
  l_y_0:
    for (int y_0 = 0; y_0 < 10; y_0++)
    {                 // L472
      float sum_4;    // L256
      float v239 = 0; // L472
      sum_4 = v239;   // L472
    l_r_10:
      for (int r_10 = 0; r_10 < 84; r_10++)
      { // L256
        if (1)
        {                                   // L472
          float v241 = f4_relu1[x_0][r_10]; // L472
          float v242 = v11[y_0][r_10];      // L30
          float v243 = v241 * v242;         // L472
          float v244 = sum_4;               // L256
          float v245 = v243 + v244;         // L472
          sum_4 = v245;                     // L472
        }
      }
      float v246 = sum_4;          // L256
      float v247 = v12[y_0];       // L31
      float v248 = v246 + v247;    // L256
      f5_linear1[x_0][y_0] = v248; // L472
    }
  }
  static float f5_logsoftmax1_expsum[2]; // L472
l_f5_logsoftmax1_expsum_x_1:
  for (int x_1 = 0; x_1 < 2; x_1++)
  {                 // L472
    float sum_5;    // L256
    float v252 = 0; // L472
    sum_5 = v252;   // L472
  l_r_11:
    for (int r_11 = 0; r_11 < 10; r_11++)
    { // L256
      if (1)
      {                                     // L472
        float v254 = f5_linear1[x_1][r_11]; // L472
        float v255 = exp(v254);             // L11
        float v256 = sum_5;                 // L256
        float v257 = v255 + v256;           // L11
        sum_5 = v257;                       // L472
      }
    }
    float v258 = sum_5;                // L256
    f5_logsoftmax1_expsum[x_1] = v258; // L472
  }
l_f5_logsoftmax1_x_2:
  for (int x_2 = 0; x_2 < 2; x_2++)
  { // L472
  l_y_1:
    for (int y_1 = 0; y_1 < 10; y_1++)
    {                                          // L472
      float v261 = f5_linear1[x_2][y_1];       // L472
      float v262 = exp(v261);                  // L11
      float v263 = f5_logsoftmax1_expsum[x_2]; // L472
      float v264 = v262 / v263;                // L11
      float v265 = log(v264);                  // L23
      v13[x_2][y_1] = v265;                    // L472
    }
  }
}
