
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//
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
  int32_t v0[2][1][32][32],
  int32_t v1[6][1][5][5],
  int32_t v2[6],
  int32_t v3[16][6][5][5],
  int32_t v4[16],
  int32_t v5[16][6][5][5],
  int32_t v6[16],
  int32_t v7[120][16][5][5],
  int32_t v8[120],
  int32_t v9[84][120],
  int32_t v10[84],
  int32_t v11[10][84],
  int32_t v12[10],
  int32_t v13[2][10]
) {	// L28
  int32_t c1_conv1[2][6][28][28];	// L472
  l_c1_conv1_nn: for (int nn = 0; nn < 2; nn++) {	// L472
    l_ff: for (int ff = 0; ff < 6; ff++) {	// L472
      l_yy: for (int yy = 0; yy < 28; yy++) {	// L472
        l_xx: for (int xx = 0; xx < 28; xx++) {	// L472
          int32_t sum;	// L256
          sum = 0;	// L472
          l_ry: for (int ry = 0; ry < 5; ry++) {	// L256
            l_rx: for (int rx = 0; rx < 5; rx++) {	// L256
              if (1) {	// L472
                int32_t v22 = v0[nn][0][(yy + ry)][(xx + rx)];	// L11
                int32_t v23 = v1[ff][0][ry][rx];	// L13
                int64_t v24 = v22;	// L472
                int64_t v25 = v23;	// L472
                int64_t v26 = v24 * v25;	// L11
                int32_t v27 = v2[ff];	// L14
                ap_int<65> v28 = v26;	// L472
                ap_int<65> v29 = v27;	// L472
                ap_int<65> v30 = v28 + v29;	// L11
                int32_t v31 = sum;	// L256
                ap_int<66> v32 = v30;	// L472
                ap_int<66> v33 = v31;	// L472
                ap_int<66> v34 = v32 + v33;	// L11
                int32_t v35 = v34;	// L472
                sum = v35;	// L472
              }
            }
          }
          int32_t v36 = sum;	// L256
          c1_conv1[nn][ff][yy][xx] = v36;	// L472
        }
      }
    }
  }
  int32_t c1_relu1[2][6][28][28];	// L472
  l_c1_relu1_i0: for (int i0 = 0; i0 < 2; i0++) {	// L472
    l_i1: for (int i1 = 0; i1 < 6; i1++) {	// L472
      l_i2: for (int i2 = 0; i2 < 28; i2++) {	// L472
        l_i3: for (int i3 = 0; i3 < 28; i3++) {	// L472
          int32_t v42 = c1_conv1[i0][i1][i2][i3];	// L472
          bool v43 = v42 <= 0;	// L472
          int32_t v44 = v43 ? (int32_t)0 : (int32_t)v42;	// L127
          c1_relu1[i0][i1][i2][i3] = v44;	// L472
        }
      }
    }
  }
  int32_t c1_maxpool_pad[2][6][28][28];	// L472
  l_c1_maxpool_pad_i0_0: for (int i0_0 = 0; i0_0 < 2; i0_0++) {	// L472
    l_i1_0: for (int i1_0 = 0; i1_0 < 6; i1_0++) {	// L472
      l_i2_0: for (int i2_0 = 0; i2_0 < 28; i2_0++) {	// L472
        l_i3_0: for (int i3_0 = 0; i3_0 < 28; i3_0++) {	// L472
          int32_t v50 = c1_relu1[i0_0][i1_0][i2_0][i3_0];	// L472
          c1_maxpool_pad[i0_0][i1_0][i2_0][i3_0] = v50;	// L472
        }
      }
    }
  }
  int32_t c1_maxpool[2][6][14][14];	// L472
  l_c1_maxpool_i: for (int i = 0; i < 2; i++) {	// L472
    l_c: for (int c = 0; c < 6; c++) {	// L472
      l_h: for (int h = 0; h < 14; h++) {	// L472
        l_w: for (int w = 0; w < 14; w++) {	// L472
          int32_t maximum;	// L256
          maximum = -2147483648;	// L472
          l_r_3: for (int r_3 = 0; r_3 < 2; r_3++) {	// L256
            l_r_4: for (int r_4 = 0; r_4 < 2; r_4++) {	// L256
              if (1) {	// L472
                int32_t v59 = c1_maxpool_pad[i][c][((h * 2) + r_3)][((w * 2) + r_4)];	// L472
                int32_t v60 = maximum;	// L256
                int32_t v61 = max(v59, v60);	// L256
                maximum = v61;	// L472
              }
            }
          }
          int32_t v62 = maximum;	// L256
          c1_maxpool[i][c][h][w] = v62;	// L472
        }
      }
    }
  }
  int32_t c2_1_conv1[2][16][10][10];	// L472
  l_c2_1_conv1_nn_0: for (int nn_0 = 0; nn_0 < 2; nn_0++) {	// L472
    l_ff_0: for (int ff_0 = 0; ff_0 < 16; ff_0++) {	// L472
      l_yy_0: for (int yy_0 = 0; yy_0 < 10; yy_0++) {	// L472
        l_xx_0: for (int xx_0 = 0; xx_0 < 10; xx_0++) {	// L472
          int32_t sum_0;	// L256
          sum_0 = 0;	// L472
          l_rc_0: for (int rc_0 = 0; rc_0 < 6; rc_0++) {	// L256
            l_ry_0: for (int ry_0 = 0; ry_0 < 5; ry_0++) {	// L256
              l_rx_0: for (int rx_0 = 0; rx_0 < 5; rx_0++) {	// L256
                if (1) {	// L472
                  int32_t v72 = c1_maxpool[nn_0][rc_0][(yy_0 + ry_0)][(xx_0 + rx_0)];	// L472
                  int32_t v73 = v3[ff_0][rc_0][ry_0][rx_0];	// L16
                  int64_t v74 = v72;	// L472
                  int64_t v75 = v73;	// L472
                  int64_t v76 = v74 * v75;	// L472
                  int32_t v77 = v4[ff_0];	// L17
                  ap_int<65> v78 = v76;	// L472
                  ap_int<65> v79 = v77;	// L472
                  ap_int<65> v80 = v78 + v79;	// L472
                  int32_t v81 = sum_0;	// L256
                  ap_int<66> v82 = v80;	// L472
                  ap_int<66> v83 = v81;	// L472
                  ap_int<66> v84 = v82 + v83;	// L472
                  int32_t v85 = v84;	// L472
                  sum_0 = v85;	// L472
                }
              }
            }
          }
          int32_t v86 = sum_0;	// L256
          c2_1_conv1[nn_0][ff_0][yy_0][xx_0] = v86;	// L472
        }
      }
    }
  }
  int32_t c2_1_relu1[2][16][10][10];	// L472
  l_c2_1_relu1_i0_1: for (int i0_1 = 0; i0_1 < 2; i0_1++) {	// L472
    l_i1_1: for (int i1_1 = 0; i1_1 < 16; i1_1++) {	// L472
      l_i2_1: for (int i2_1 = 0; i2_1 < 10; i2_1++) {	// L472
        l_i3_1: for (int i3_1 = 0; i3_1 < 10; i3_1++) {	// L472
          int32_t v92 = c2_1_conv1[i0_1][i1_1][i2_1][i3_1];	// L472
          bool v93 = v92 <= 0;	// L472
          int32_t v94 = v93 ? (int32_t)0 : (int32_t)v92;	// L127
          c2_1_relu1[i0_1][i1_1][i2_1][i3_1] = v94;	// L472
        }
      }
    }
  }
  int32_t c2_1_maxpool_pad[2][16][10][10];	// L472
  l_c2_1_maxpool_pad_i0_2: for (int i0_2 = 0; i0_2 < 2; i0_2++) {	// L472
    l_i1_2: for (int i1_2 = 0; i1_2 < 16; i1_2++) {	// L472
      l_i2_2: for (int i2_2 = 0; i2_2 < 10; i2_2++) {	// L472
        l_i3_2: for (int i3_2 = 0; i3_2 < 10; i3_2++) {	// L472
          int32_t v100 = c2_1_relu1[i0_2][i1_2][i2_2][i3_2];	// L472
          c2_1_maxpool_pad[i0_2][i1_2][i2_2][i3_2] = v100;	// L472
        }
      }
    }
  }
  int32_t c2_1_maxpool[2][16][5][5];	// L472
  l_c2_1_maxpool_i_0: for (int i_0 = 0; i_0 < 2; i_0++) {	// L472
    l_c_0: for (int c_0 = 0; c_0 < 16; c_0++) {	// L472
      l_h_0: for (int h_0 = 0; h_0 < 5; h_0++) {	// L472
        l_w_0: for (int w_0 = 0; w_0 < 5; w_0++) {	// L472
          int32_t maximum_0;	// L256
          maximum_0 = -2147483648;	// L472
          l_r_5: for (int r_5 = 0; r_5 < 2; r_5++) {	// L256
            l_r_6: for (int r_6 = 0; r_6 < 2; r_6++) {	// L256
              if (1) {	// L472
                int32_t v109 = c2_1_maxpool_pad[i_0][c_0][((h_0 * 2) + r_5)][((w_0 * 2) + r_6)];	// L472
                int32_t v110 = maximum_0;	// L256
                int32_t v111 = max(v109, v110);	// L256
                maximum_0 = v111;	// L472
              }
            }
          }
          int32_t v112 = maximum_0;	// L256
          c2_1_maxpool[i_0][c_0][h_0][w_0] = v112;	// L472
        }
      }
    }
  }
  int32_t c2_2_conv1[2][16][10][10];	// L472
  l_c2_2_conv1_nn_1: for (int nn_1 = 0; nn_1 < 2; nn_1++) {	// L472
    l_ff_1: for (int ff_1 = 0; ff_1 < 16; ff_1++) {	// L472
      l_yy_1: for (int yy_1 = 0; yy_1 < 10; yy_1++) {	// L472
        l_xx_1: for (int xx_1 = 0; xx_1 < 10; xx_1++) {	// L472
          int32_t sum_1;	// L256
          sum_1 = 0;	// L472
          l_rc_1: for (int rc_1 = 0; rc_1 < 6; rc_1++) {	// L256
            l_ry_1: for (int ry_1 = 0; ry_1 < 5; ry_1++) {	// L256
              l_rx_1: for (int rx_1 = 0; rx_1 < 5; rx_1++) {	// L256
                if (1) {	// L472
                  int32_t v122 = c1_maxpool[nn_1][rc_1][(yy_1 + ry_1)][(xx_1 + rx_1)];	// L472
                  int32_t v123 = v5[ff_1][rc_1][ry_1][rx_1];	// L19
                  int64_t v124 = v122;	// L472
                  int64_t v125 = v123;	// L472
                  int64_t v126 = v124 * v125;	// L472
                  int32_t v127 = v6[ff_1];	// L20
                  ap_int<65> v128 = v126;	// L472
                  ap_int<65> v129 = v127;	// L472
                  ap_int<65> v130 = v128 + v129;	// L472
                  int32_t v131 = sum_1;	// L256
                  ap_int<66> v132 = v130;	// L472
                  ap_int<66> v133 = v131;	// L472
                  ap_int<66> v134 = v132 + v133;	// L472
                  int32_t v135 = v134;	// L472
                  sum_1 = v135;	// L472
                }
              }
            }
          }
          int32_t v136 = sum_1;	// L256
          c2_2_conv1[nn_1][ff_1][yy_1][xx_1] = v136;	// L472
        }
      }
    }
  }
  int32_t c2_2_relu1[2][16][10][10];	// L472
  l_c2_2_relu1_i0_3: for (int i0_3 = 0; i0_3 < 2; i0_3++) {	// L472
    l_i1_3: for (int i1_3 = 0; i1_3 < 16; i1_3++) {	// L472
      l_i2_3: for (int i2_3 = 0; i2_3 < 10; i2_3++) {	// L472
        l_i3_3: for (int i3_3 = 0; i3_3 < 10; i3_3++) {	// L472
          int32_t v142 = c2_2_conv1[i0_3][i1_3][i2_3][i3_3];	// L472
          bool v143 = v142 <= 0;	// L472
          int32_t v144 = v143 ? (int32_t)0 : (int32_t)v142;	// L127
          c2_2_relu1[i0_3][i1_3][i2_3][i3_3] = v144;	// L472
        }
      }
    }
  }
  int32_t c2_2_maxpool_pad[2][16][10][10];	// L472
  l_c2_2_maxpool_pad_i0_4: for (int i0_4 = 0; i0_4 < 2; i0_4++) {	// L472
    l_i1_4: for (int i1_4 = 0; i1_4 < 16; i1_4++) {	// L472
      l_i2_4: for (int i2_4 = 0; i2_4 < 10; i2_4++) {	// L472
        l_i3_4: for (int i3_4 = 0; i3_4 < 10; i3_4++) {	// L472
          int32_t v150 = c2_2_relu1[i0_4][i1_4][i2_4][i3_4];	// L472
          c2_2_maxpool_pad[i0_4][i1_4][i2_4][i3_4] = v150;	// L472
        }
      }
    }
  }
  int32_t c2_2_maxpool[2][16][5][5];	// L472
  l_c2_2_maxpool_i_1: for (int i_1 = 0; i_1 < 2; i_1++) {	// L472
    l_c_1: for (int c_1 = 0; c_1 < 16; c_1++) {	// L472
      l_h_1: for (int h_1 = 0; h_1 < 5; h_1++) {	// L472
        l_w_1: for (int w_1 = 0; w_1 < 5; w_1++) {	// L472
          int32_t maximum_1;	// L256
          maximum_1 = -2147483648;	// L472
          l_r_7: for (int r_7 = 0; r_7 < 2; r_7++) {	// L256
            l_r_8: for (int r_8 = 0; r_8 < 2; r_8++) {	// L256
              if (1) {	// L472
                int32_t v159 = c2_2_maxpool_pad[i_1][c_1][((h_1 * 2) + r_7)][((w_1 * 2) + r_8)];	// L472
                int32_t v160 = maximum_1;	// L256
                int32_t v161 = max(v159, v160);	// L256
                maximum_1 = v161;	// L472
              }
            }
          }
          int32_t v162 = maximum_1;	// L256
          c2_2_maxpool[i_1][c_1][h_1][w_1] = v162;	// L472
        }
      }
    }
  }
  int32_t tensor_25[2][16][5][5];	// L472
  l_tensor_25_i0_5: for (int i0_5 = 0; i0_5 < 2; i0_5++) {	// L472
    l_i1_5: for (int i1_5 = 0; i1_5 < 16; i1_5++) {	// L472
      l_i2_5: for (int i2_5 = 0; i2_5 < 5; i2_5++) {	// L472
        l_i3_5: for (int i3_5 = 0; i3_5 < 5; i3_5++) {	// L472
          int32_t v168 = c2_1_maxpool[i0_5][i1_5][i2_5][i3_5];	// L472
          int32_t v169 = c2_2_maxpool[i0_5][i1_5][i2_5][i3_5];	// L472
          ap_int<33> v170 = v168;	// L472
          ap_int<33> v171 = v169;	// L472
          ap_int<33> v172 = v170 + v171;	// L472
          int32_t v173 = v172;	// L472
          tensor_25[i0_5][i1_5][i2_5][i3_5] = v173;	// L472
        }
      }
    }
  }
  int32_t c3_conv1[2][120][1][1];	// L472
  l_c3_conv1_nn_2: for (int nn_2 = 0; nn_2 < 2; nn_2++) {	// L472
    l_ff_2: for (int ff_2 = 0; ff_2 < 120; ff_2++) {	// L472
      int32_t sum_2;	// L256
      sum_2 = 0;	// L472
      l_rc_2: for (int rc_2 = 0; rc_2 < 16; rc_2++) {	// L256
        l_ry_2: for (int ry_2 = 0; ry_2 < 5; ry_2++) {	// L256
          l_rx_2: for (int rx_2 = 0; rx_2 < 5; rx_2++) {	// L256
            if (1) {	// L472
              int32_t v181 = tensor_25[nn_2][rc_2][(0 + ry_2)][(0 + rx_2)];	// L472
              int32_t v182 = v7[ff_2][rc_2][ry_2][rx_2];	// L22
              int64_t v183 = v181;	// L472
              int64_t v184 = v182;	// L472
              int64_t v185 = v183 * v184;	// L472
              int32_t v186 = v8[ff_2];	// L23
              ap_int<65> v187 = v185;	// L472
              ap_int<65> v188 = v186;	// L472
              ap_int<65> v189 = v187 + v188;	// L472
              int32_t v190 = sum_2;	// L256
              ap_int<66> v191 = v189;	// L472
              ap_int<66> v192 = v190;	// L472
              ap_int<66> v193 = v191 + v192;	// L472
              int32_t v194 = v193;	// L472
              sum_2 = v194;	// L472
            }
          }
        }
      }
      int32_t v195 = sum_2;	// L256
      c3_conv1[nn_2][ff_2][0][0] = v195;	// L472
    }
  }
  int32_t c3_relu1[2][120][1][1];	// L472
  l_c3_relu1_i0_6: for (int i0_6 = 0; i0_6 < 2; i0_6++) {	// L472
    l_i1_6: for (int i1_6 = 0; i1_6 < 120; i1_6++) {	// L472
      int32_t v199 = c3_conv1[i0_6][i1_6][0][0];	// L472
      bool v200 = v199 <= 0;	// L472
      int32_t v201 = v200 ? (int32_t)0 : (int32_t)v199;	// L127
      c3_relu1[i0_6][i1_6][0][0] = v201;	// L472
    }
  }
  int32_t c3_view[2][120];	// L472
  l_c3_view_b: for (int b = 0; b < 2; b++) {	// L472
    l_c_2: for (int c_2 = 0; c_2 < 120; c_2++) {	// L472
      int32_t v205 = c3_relu1[b][c_2][0][0];	// L472
      c3_view[b][c_2] = v205;	// L472
    }
  }
  int32_t f4_linear1[2][84];	// L472
  l_f4_linear1_x: for (int x = 0; x < 2; x++) {	// L472
    l_y: for (int y = 0; y < 84; y++) {	// L472
      int32_t sum_3;	// L256
      sum_3 = 0;	// L472
      l_r_9: for (int r_9 = 0; r_9 < 120; r_9++) {	// L256
        if (1) {	// L472
          int32_t v211 = c3_view[x][r_9];	// L472
          int32_t v212 = v9[x][r_9];	// L25
          int64_t v213 = v211;	// L472
          int64_t v214 = v212;	// L472
          int64_t v215 = v213 * v214;	// L472
          int32_t v216 = sum_3;	// L256
          ap_int<65> v217 = v215;	// L472
          ap_int<65> v218 = v216;	// L472
          ap_int<65> v219 = v217 + v218;	// L472
          int32_t v220 = v219;	// L472
          sum_3 = v220;	// L472
        }
      }
      int32_t v221 = sum_3;	// L256
      int32_t v222 = v10[y];	// L26
      ap_int<33> v223 = v221;	// L472
      ap_int<33> v224 = v222;	// L472
      ap_int<33> v225 = v223 + v224;	// L256
      int32_t v226 = v225;	// L472
      f4_linear1[x][y] = v226;	// L472
    }
  }
  int32_t f4_relu1[2][84];	// L472
  l_f4_relu1_i0_7: for (int i0_7 = 0; i0_7 < 2; i0_7++) {	// L472
    l_i1_7: for (int i1_7 = 0; i1_7 < 84; i1_7++) {	// L472
      int32_t v230 = f4_linear1[i0_7][i1_7];	// L472
      bool v231 = v230 <= 0;	// L472
      int32_t v232 = v231 ? (int32_t)0 : (int32_t)v230;	// L127
      f4_relu1[i0_7][i1_7] = v232;	// L472
    }
  }
  int32_t f5_linear1[2][10];	// L472
  l_f5_linear1_x_0: for (int x_0 = 0; x_0 < 2; x_0++) {	// L472
    l_y_0: for (int y_0 = 0; y_0 < 10; y_0++) {	// L472
      int32_t sum_4;	// L256
      sum_4 = 0;	// L472
      l_r_10: for (int r_10 = 0; r_10 < 84; r_10++) {	// L256
        if (1) {	// L472
          int32_t v238 = f4_relu1[x_0][r_10];	// L472
          int32_t v239 = v11[x_0][r_10];	// L28
          int64_t v240 = v238;	// L472
          int64_t v241 = v239;	// L472
          int64_t v242 = v240 * v241;	// L472
          int32_t v243 = sum_4;	// L256
          ap_int<65> v244 = v242;	// L472
          ap_int<65> v245 = v243;	// L472
          ap_int<65> v246 = v244 + v245;	// L472
          int32_t v247 = v246;	// L472
          sum_4 = v247;	// L472
        }
      }
      int32_t v248 = sum_4;	// L256
      int32_t v249 = v12[y_0];	// L29
      ap_int<33> v250 = v248;	// L472
      ap_int<33> v251 = v249;	// L472
      ap_int<33> v252 = v250 + v251;	// L256
      int32_t v253 = v252;	// L472
      f5_linear1[x_0][y_0] = v253;	// L472
    }
  }
  l_f5_logsoftmax1_x_1: for (int x_1 = 0; x_1 < 2; x_1++) {	// L472
    l_y_1: for (int y_1 = 0; y_1 < 10; y_1++) {	// L472
      int32_t v256 = f5_linear1[x_1][y_1];	// L472
      float v257 = v256;	// L472
      float v258 = exp(v257);	// L11
      int32_t sum_5;	// L256
      sum_5 = 0;	// L472
      l_r_11: for (int r_11 = 0; r_11 < 10; r_11++) {	// L256
        if (1) {	// L472
          int32_t v261 = f5_linear1[x_1][(y_1 + r_11)];	// L472
          int32_t v262 = sum_5;	// L256
          ap_int<33> v263 = v261;	// L472
          ap_int<33> v264 = v262;	// L472
          ap_int<33> v265 = v263 + v264;	// L472
          int32_t v266 = v265;	// L472
          sum_5 = v266;	// L472
        }
      }
      int32_t v267 = sum_5;	// L256
      float v268 = v267;	// L472
      float v269 = v258 / v268;	// L11
      float v270 = log(v269);	// L23
      int32_t v271 = v270;	// L472
      v13[x_1][y_1] = v271;	// L472
    }
  }
}

