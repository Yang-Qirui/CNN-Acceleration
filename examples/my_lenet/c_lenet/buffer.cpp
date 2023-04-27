
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
  ap_fixed<10, 6> v0[2][1][32][32],
  ap_fixed<10, 6> v1[6][1][5][5],
  ap_fixed<10, 6> v2[6],
  ap_fixed<10, 6> v3[16][6][5][5],
  ap_fixed<10, 6> v4[16],
  ap_fixed<10, 6> v5[16][6][5][5],
  ap_fixed<10, 6> v6[16],
  ap_fixed<10, 6> v7[120][16][5][5],
  ap_fixed<10, 6> v8[120],
  ap_fixed<10, 6> v9[84][120],
  ap_fixed<10, 6> v10[84],
  ap_fixed<10, 6> v11[10][84],
  ap_fixed<10, 6> v12[10],
  ap_fixed<10, 6> v13[2][10]
) {	// L28
  #pragma HLS array_partition variable=v0 complete dim=3
  #pragma HLS array_partition variable=v0 complete dim=4

  #pragma HLS array_partition variable=v1 complete dim=3
  #pragma HLS array_partition variable=v1 complete dim=4

  #pragma HLS array_partition variable=v3 complete dim=3
  #pragma HLS array_partition variable=v3 complete dim=4

  #pragma HLS array_partition variable=v5 complete dim=3
  #pragma HLS array_partition variable=v5 complete dim=4

  #pragma HLS array_partition variable=v7 complete dim=3
  #pragma HLS array_partition variable=v7 complete dim=4

  ap_fixed<10, 6> c1_conv1[2][6][28][28];	// L472
  l_c1_conv1_nn: for (int nn = 0; nn < 2; nn++) {	// L472
    l_ff: for (int ff = 0; ff < 6; ff++) {	// L472
      l_yy: for (int yy = 0; yy < 28; yy++) {	// L472
        l_xx: for (int xx = 0; xx < 28; xx++) {	// L472
          ap_fixed<10, 6> sum;	// L256
          ap_fixed<10, 6> v20 = 0;	// L472
          sum = v20;	// L472
          l_ry: for (int ry = 0; ry < 5; ry++) {	// L256
            l_rx: for (int rx = 0; rx < 5; rx++) {	// L256
              if (1) {	// L472
                ap_fixed<10, 6> v23 = v0[nn][0][(yy + ry)][(xx + rx)];	// L13
                ap_fixed<10, 6> v24 = v1[ff][0][ry][rx];	// L15
                ap_fixed<20, 12> v25 = v23;	// L472
                ap_fixed<20, 12> v26 = v24;	// L472
                ap_fixed<20, 12> v27 = v25 * v26;	// L13
                ap_fixed<10, 6> v28 = v2[ff];	// L16
                ap_fixed<21, 13> v29 = v27;	// L472
                ap_fixed<21, 13> v30 = v28;	// L472
                ap_fixed<21, 13> v31 = v29 + v30;	// L13
                ap_fixed<10, 6> v32 = sum;	// L256
                ap_fixed<22, 14> v33 = v31;	// L472
                ap_fixed<22, 14> v34 = v32;	// L472
                ap_fixed<22, 14> v35 = v33 + v34;	// L13
                ap_fixed<10, 6> v36 = v35;	// L472
                sum = v36;	// L472
              }
            }
          }
          ap_fixed<10, 6> v37 = sum;	// L256
          c1_conv1[nn][ff][yy][xx] = v37;	// L472
        }
      }
    }
  }
  ap_fixed<10, 6> c1_relu1[2][6][28][28];	// L472
  l_c1_relu1_i0: for (int i0 = 0; i0 < 2; i0++) {	// L472
    l_i1: for (int i1 = 0; i1 < 6; i1++) {	// L472
      l_i2: for (int i2 = 0; i2 < 28; i2++) {	// L472
        l_i3: for (int i3 = 0; i3 < 28; i3++) {	// L472
          ap_fixed<10, 6> v43 = c1_conv1[i0][i1][i2][i3];	// L472
          ap_fixed<36, 32> v44 = v43;	// L472
          ap_fixed<36, 32> v45 = 0;	// L472
          bool v46 = v44 <= v45;	// L472
          ap_fixed<10, 6> v47 = c1_conv1[i0][i1][i2][i3];	// L472
          ap_fixed<36, 32> v48 = 0;	// L472
          ap_fixed<36, 32> v49 = v47;	// L472
          ap_fixed<36, 32> v50 = v46 ? (ap_fixed<36, 32>)v48 : (ap_fixed<36, 32>)v49;	// L127
          ap_fixed<10, 6> v51 = v50;	// L472
          c1_relu1[i0][i1][i2][i3] = v51;	// L472
        }
      }
    }
  }
  ap_fixed<10, 6> c1_maxpool_pad[2][6][28][28];	// L472
  l_c1_maxpool_pad_i0_0: for (int i0_0 = 0; i0_0 < 2; i0_0++) {	// L472
    l_i1_0: for (int i1_0 = 0; i1_0 < 6; i1_0++) {	// L472
      l_i2_0: for (int i2_0 = 0; i2_0 < 28; i2_0++) {	// L472
        l_i3_0: for (int i3_0 = 0; i3_0 < 28; i3_0++) {	// L472
          ap_fixed<10, 6> v57 = c1_relu1[i0_0][i1_0][i2_0][i3_0];	// L472
          c1_maxpool_pad[i0_0][i1_0][i2_0][i3_0] = v57;	// L472
        }
      }
    }
  }
  ap_fixed<10, 6> c1_maxpool[2][6][14][14];	// L472
  l_c1_maxpool_i: for (int i = 0; i < 2; i++) {	// L472
    l_c: for (int c = 0; c < 6; c++) {	// L472
      l_h: for (int h = 0; h < 14; h++) {	// L472
        l_w: for (int w = 0; w < 14; w++) {	// L472
          int32_t maximum;	// L256
          maximum = -2147483648;	// L472
          l_r_3: for (int r_3 = 0; r_3 < 2; r_3++) {	// L256
            l_r_4: for (int r_4 = 0; r_4 < 2; r_4++) {	// L256
              if (1) {	// L472
                ap_fixed<10, 6> v66 = c1_maxpool_pad[i][c][((h * 2) + r_3)][((w * 2) + r_4)];	// L472
                int32_t v67 = maximum;	// L256
                ap_fixed<32, 32> v68 = v66;	// L472
                ap_fixed<32, 32> v69 = v67;	// L472
                ap_fixed<32, 32> v70 = max(v68, v69);	// L256
                int32_t v71 = v70;	// L472
                maximum = v71;	// L472
              }
            }
          }
          int32_t v72 = maximum;	// L256
          ap_fixed<10, 6> v73 = v72;	// L472
          c1_maxpool[i][c][h][w] = v73;	// L472
        }
      }
    }
  }
  ap_fixed<10, 6> c2_1_conv1[2][16][10][10];	// L472
  ap_fixed<10, 6> c2_1_conv1_reuse_3[6][5][5];	// L472
  #pragma HLS array_partition variable=c2_1_conv1_reuse_3 complete dim=3

  l_c2_1_conv1_nn_0: for (int nn_0 = 0; nn_0 < 2; nn_0++) {	// L472
    l_ff_0: for (int ff_0 = 0; ff_0 < 16; ff_0++) {	// L472
      l_yy_0: for (int yy_0 = 0; yy_0 < 10; yy_0++) {	// L472
        l_xx_0: for (int xx_0 = 0; xx_0 < 14; xx_0++) {	// L472
          for (int v80 = 0; v80 < 6; v80++) {	// L256
            for (int v81 = 0; v81 < 5; v81++) {	// L256
              ap_fixed<10, 6> v82 = c2_1_conv1_reuse_3[v80][v81][1];	// L256
              c2_1_conv1_reuse_3[v80][v81][0] = v82;	// L256
              ap_fixed<10, 6> v83 = c2_1_conv1_reuse_3[v80][v81][2];	// L256
              c2_1_conv1_reuse_3[v80][v81][1] = v83;	// L256
              ap_fixed<10, 6> v84 = c2_1_conv1_reuse_3[v80][v81][3];	// L256
              c2_1_conv1_reuse_3[v80][v81][2] = v84;	// L256
              ap_fixed<10, 6> v85 = c2_1_conv1_reuse_3[v80][v81][4];	// L256
              c2_1_conv1_reuse_3[v80][v81][3] = v85;	// L256
              ap_fixed<10, 6> v86 = c1_maxpool[nn_0][v80][(yy_0 + v81)][xx_0];	// L256
              c2_1_conv1_reuse_3[v80][v81][4] = v86;	// L256
            }
          }
          if ((xx_0 - 4) >= 0) {	// L256
            ap_fixed<10, 6> sum_0;	// L256
            ap_fixed<10, 6> v88 = 0;	// L472
            sum_0 = v88;	// L472
            l_rc_0: for (int rc_0 = 0; rc_0 < 6; rc_0++) {	// L256
            #pragma HLS pipeline
              l_ry_0: for (int ry_0 = 0; ry_0 < 5; ry_0++) {	// L256
                l_rx_0: for (int rx_0 = 0; rx_0 < 5; rx_0++) {	// L256
                  if (1) {	// L472
                    ap_fixed<10, 6> v92 = c2_1_conv1_reuse_3[rc_0][ry_0][rx_0];	// L472
                    ap_fixed<10, 6> v93 = v3[ff_0][rc_0][ry_0][rx_0];	// L18
                    ap_fixed<20, 12> v94 = v92;	// L472
                    ap_fixed<20, 12> v95 = v93;	// L472
                    ap_fixed<20, 12> v96 = v94 * v95;	// L472
                    ap_fixed<10, 6> v97 = v4[ff_0];	// L19
                    ap_fixed<21, 13> v98 = v96;	// L472
                    ap_fixed<21, 13> v99 = v97;	// L472
                    ap_fixed<21, 13> v100 = v98 + v99;	// L472
                    ap_fixed<10, 6> v101 = sum_0;	// L256
                    ap_fixed<22, 14> v102 = v100;	// L472
                    ap_fixed<22, 14> v103 = v101;	// L472
                    ap_fixed<22, 14> v104 = v102 + v103;	// L472
                    ap_fixed<10, 6> v105 = v104;	// L472
                    sum_0 = v105;	// L472
                  }
                }
              }
            }
            ap_fixed<10, 6> v106 = sum_0;	// L256
            c2_1_conv1[nn_0][ff_0][yy_0][(xx_0 - 4)] = v106;	// L472
          }
        }
      }
    }
  }
  ap_fixed<10, 6> c2_1_relu1[2][16][10][10];	// L472
  l_c2_1_relu1_i0_1: for (int i0_1 = 0; i0_1 < 2; i0_1++) {	// L472
    l_i1_1: for (int i1_1 = 0; i1_1 < 16; i1_1++) {	// L472
      l_i2_1: for (int i2_1 = 0; i2_1 < 10; i2_1++) {	// L472
        l_i3_1: for (int i3_1 = 0; i3_1 < 10; i3_1++) {	// L472
          ap_fixed<10, 6> v112 = c2_1_conv1[i0_1][i1_1][i2_1][i3_1];	// L472
          ap_fixed<36, 32> v113 = v112;	// L472
          ap_fixed<36, 32> v114 = 0;	// L472
          bool v115 = v113 <= v114;	// L472
          ap_fixed<10, 6> v116 = c2_1_conv1[i0_1][i1_1][i2_1][i3_1];	// L472
          ap_fixed<36, 32> v117 = 0;	// L472
          ap_fixed<36, 32> v118 = v116;	// L472
          ap_fixed<36, 32> v119 = v115 ? (ap_fixed<36, 32>)v117 : (ap_fixed<36, 32>)v118;	// L127
          ap_fixed<10, 6> v120 = v119;	// L472
          c2_1_relu1[i0_1][i1_1][i2_1][i3_1] = v120;	// L472
        }
      }
    }
  }
  ap_fixed<10, 6> c2_1_maxpool_pad[2][16][10][10];	// L472
  l_c2_1_maxpool_pad_i0_2: for (int i0_2 = 0; i0_2 < 2; i0_2++) {	// L472
    l_i1_2: for (int i1_2 = 0; i1_2 < 16; i1_2++) {	// L472
      l_i2_2: for (int i2_2 = 0; i2_2 < 10; i2_2++) {	// L472
        l_i3_2: for (int i3_2 = 0; i3_2 < 10; i3_2++) {	// L472
          ap_fixed<10, 6> v126 = c2_1_relu1[i0_2][i1_2][i2_2][i3_2];	// L472
          c2_1_maxpool_pad[i0_2][i1_2][i2_2][i3_2] = v126;	// L472
        }
      }
    }
  }
  ap_fixed<10, 6> c2_1_maxpool[2][16][5][5];	// L472
  l_c2_1_maxpool_i_0: for (int i_0 = 0; i_0 < 2; i_0++) {	// L472
    l_c_0: for (int c_0 = 0; c_0 < 16; c_0++) {	// L472
      l_h_0: for (int h_0 = 0; h_0 < 5; h_0++) {	// L472
        l_w_0: for (int w_0 = 0; w_0 < 5; w_0++) {	// L472
          int32_t maximum_0;	// L256
          maximum_0 = -2147483648;	// L472
          l_r_5: for (int r_5 = 0; r_5 < 2; r_5++) {	// L256
            l_r_6: for (int r_6 = 0; r_6 < 2; r_6++) {	// L256
              if (1) {	// L472
                ap_fixed<10, 6> v135 = c2_1_maxpool_pad[i_0][c_0][((h_0 * 2) + r_5)][((w_0 * 2) + r_6)];	// L472
                int32_t v136 = maximum_0;	// L256
                ap_fixed<32, 32> v137 = v135;	// L472
                ap_fixed<32, 32> v138 = v136;	// L472
                ap_fixed<32, 32> v139 = max(v137, v138);	// L256
                int32_t v140 = v139;	// L472
                maximum_0 = v140;	// L472
              }
            }
          }
          int32_t v141 = maximum_0;	// L256
          ap_fixed<10, 6> v142 = v141;	// L472
          c2_1_maxpool[i_0][c_0][h_0][w_0] = v142;	// L472
        }
      }
    }
  }
  ap_fixed<10, 6> c2_2_conv1[2][16][10][10];	// L472
  ap_fixed<10, 6> c2_2_conv1_reuse_3[6][5][5];	// L472
  #pragma HLS array_partition variable=c2_2_conv1_reuse_3 complete dim=3

  l_c2_2_conv1_nn_1: for (int nn_1 = 0; nn_1 < 2; nn_1++) {	// L472
    l_ff_1: for (int ff_1 = 0; ff_1 < 16; ff_1++) {	// L472
      l_yy_1: for (int yy_1 = 0; yy_1 < 10; yy_1++) {	// L472
        l_xx_1: for (int xx_1 = 0; xx_1 < 14; xx_1++) {	// L472
          for (int v149 = 0; v149 < 6; v149++) {	// L256
            for (int v150 = 0; v150 < 5; v150++) {	// L256
              ap_fixed<10, 6> v151 = c2_2_conv1_reuse_3[v149][v150][1];	// L256
              c2_2_conv1_reuse_3[v149][v150][0] = v151;	// L256
              ap_fixed<10, 6> v152 = c2_2_conv1_reuse_3[v149][v150][2];	// L256
              c2_2_conv1_reuse_3[v149][v150][1] = v152;	// L256
              ap_fixed<10, 6> v153 = c2_2_conv1_reuse_3[v149][v150][3];	// L256
              c2_2_conv1_reuse_3[v149][v150][2] = v153;	// L256
              ap_fixed<10, 6> v154 = c2_2_conv1_reuse_3[v149][v150][4];	// L256
              c2_2_conv1_reuse_3[v149][v150][3] = v154;	// L256
              ap_fixed<10, 6> v155 = c1_maxpool[nn_1][v149][(yy_1 + v150)][xx_1];	// L256
              c2_2_conv1_reuse_3[v149][v150][4] = v155;	// L256
            }
          }
          if ((xx_1 - 4) >= 0) {	// L256
            ap_fixed<10, 6> sum_1;	// L256
            ap_fixed<10, 6> v157 = 0;	// L472
            sum_1 = v157;	// L472
            l_rc_1: for (int rc_1 = 0; rc_1 < 6; rc_1++) {	// L256
            #pragma HLS pipeline
              l_ry_1: for (int ry_1 = 0; ry_1 < 5; ry_1++) {	// L256
                l_rx_1: for (int rx_1 = 0; rx_1 < 5; rx_1++) {	// L256
                  if (1) {	// L472
                    ap_fixed<10, 6> v161 = c2_2_conv1_reuse_3[rc_1][ry_1][rx_1];	// L472
                    ap_fixed<10, 6> v162 = v5[ff_1][rc_1][ry_1][rx_1];	// L21
                    ap_fixed<20, 12> v163 = v161;	// L472
                    ap_fixed<20, 12> v164 = v162;	// L472
                    ap_fixed<20, 12> v165 = v163 * v164;	// L472
                    ap_fixed<10, 6> v166 = v6[ff_1];	// L22
                    ap_fixed<21, 13> v167 = v165;	// L472
                    ap_fixed<21, 13> v168 = v166;	// L472
                    ap_fixed<21, 13> v169 = v167 + v168;	// L472
                    ap_fixed<10, 6> v170 = sum_1;	// L256
                    ap_fixed<22, 14> v171 = v169;	// L472
                    ap_fixed<22, 14> v172 = v170;	// L472
                    ap_fixed<22, 14> v173 = v171 + v172;	// L472
                    ap_fixed<10, 6> v174 = v173;	// L472
                    sum_1 = v174;	// L472
                  }
                }
              }
            }
            ap_fixed<10, 6> v175 = sum_1;	// L256
            c2_2_conv1[nn_1][ff_1][yy_1][(xx_1 - 4)] = v175;	// L472
          }
        }
      }
    }
  }
  ap_fixed<10, 6> c2_2_relu1[2][16][10][10];	// L472
  l_c2_2_relu1_i0_3: for (int i0_3 = 0; i0_3 < 2; i0_3++) {	// L472
    l_i1_3: for (int i1_3 = 0; i1_3 < 16; i1_3++) {	// L472
      l_i2_3: for (int i2_3 = 0; i2_3 < 10; i2_3++) {	// L472
        l_i3_3: for (int i3_3 = 0; i3_3 < 10; i3_3++) {	// L472
          ap_fixed<10, 6> v181 = c2_2_conv1[i0_3][i1_3][i2_3][i3_3];	// L472
          ap_fixed<36, 32> v182 = v181;	// L472
          ap_fixed<36, 32> v183 = 0;	// L472
          bool v184 = v182 <= v183;	// L472
          ap_fixed<10, 6> v185 = c2_2_conv1[i0_3][i1_3][i2_3][i3_3];	// L472
          ap_fixed<36, 32> v186 = 0;	// L472
          ap_fixed<36, 32> v187 = v185;	// L472
          ap_fixed<36, 32> v188 = v184 ? (ap_fixed<36, 32>)v186 : (ap_fixed<36, 32>)v187;	// L127
          ap_fixed<10, 6> v189 = v188;	// L472
          c2_2_relu1[i0_3][i1_3][i2_3][i3_3] = v189;	// L472
        }
      }
    }
  }
  ap_fixed<10, 6> c2_2_maxpool_pad[2][16][10][10];	// L472
  l_c2_2_maxpool_pad_i0_4: for (int i0_4 = 0; i0_4 < 2; i0_4++) {	// L472
    l_i1_4: for (int i1_4 = 0; i1_4 < 16; i1_4++) {	// L472
      l_i2_4: for (int i2_4 = 0; i2_4 < 10; i2_4++) {	// L472
        l_i3_4: for (int i3_4 = 0; i3_4 < 10; i3_4++) {	// L472
          ap_fixed<10, 6> v195 = c2_2_relu1[i0_4][i1_4][i2_4][i3_4];	// L472
          c2_2_maxpool_pad[i0_4][i1_4][i2_4][i3_4] = v195;	// L472
        }
      }
    }
  }
  ap_fixed<10, 6> c2_2_maxpool[2][16][5][5];	// L472
  l_c2_2_maxpool_i_1: for (int i_1 = 0; i_1 < 2; i_1++) {	// L472
    l_c_1: for (int c_1 = 0; c_1 < 16; c_1++) {	// L472
      l_h_1: for (int h_1 = 0; h_1 < 5; h_1++) {	// L472
        l_w_1: for (int w_1 = 0; w_1 < 5; w_1++) {	// L472
          int32_t maximum_1;	// L256
          maximum_1 = -2147483648;	// L472
          l_r_7: for (int r_7 = 0; r_7 < 2; r_7++) {	// L256
            l_r_8: for (int r_8 = 0; r_8 < 2; r_8++) {	// L256
              if (1) {	// L472
                ap_fixed<10, 6> v204 = c2_2_maxpool_pad[i_1][c_1][((h_1 * 2) + r_7)][((w_1 * 2) + r_8)];	// L472
                int32_t v205 = maximum_1;	// L256
                ap_fixed<32, 32> v206 = v204;	// L472
                ap_fixed<32, 32> v207 = v205;	// L472
                ap_fixed<32, 32> v208 = max(v206, v207);	// L256
                int32_t v209 = v208;	// L472
                maximum_1 = v209;	// L472
              }
            }
          }
          int32_t v210 = maximum_1;	// L256
          ap_fixed<10, 6> v211 = v210;	// L472
          c2_2_maxpool[i_1][c_1][h_1][w_1] = v211;	// L472
        }
      }
    }
  }
  ap_fixed<10, 6> add[2][16][5][5];	// L472
  l_add_i0_5: for (int i0_5 = 0; i0_5 < 2; i0_5++) {	// L472
    l_i1_5: for (int i1_5 = 0; i1_5 < 16; i1_5++) {	// L472
      l_i2_5: for (int i2_5 = 0; i2_5 < 5; i2_5++) {	// L472
        l_i3_5: for (int i3_5 = 0; i3_5 < 5; i3_5++) {	// L472
          ap_fixed<10, 6> v217 = c2_1_maxpool[i0_5][i1_5][i2_5][i3_5];	// L472
          ap_fixed<10, 6> v218 = c2_2_maxpool[i0_5][i1_5][i2_5][i3_5];	// L472
          ap_fixed<11, 7> v219 = v217;	// L472
          ap_fixed<11, 7> v220 = v218;	// L472
          ap_fixed<11, 7> v221 = v219 + v220;	// L472
          ap_fixed<10, 6> v222 = v221;	// L472
          add[i0_5][i1_5][i2_5][i3_5] = v222;	// L472
        }
      }
    }
  }
  ap_fixed<10, 6> c3_conv1[2][120][1][1];	// L472
  ap_fixed<10, 6> c3_conv1_reuse_3[16][5][5];	// L472
  #pragma HLS array_partition variable=c3_conv1_reuse_3 complete dim=3

  l_c3_conv1_nn_2: for (int nn_2 = 0; nn_2 < 2; nn_2++) {	// L472
    l_ff_2: for (int ff_2 = 0; ff_2 < 120; ff_2++) {	// L472
      l_xx_2: for (int xx_2 = 0; xx_2 < 5; xx_2++) {	// L472
        for (int v228 = 0; v228 < 16; v228++) {	// L256
          for (int v229 = 0; v229 < 5; v229++) {	// L256
            ap_fixed<10, 6> v230 = c3_conv1_reuse_3[v228][v229][1];	// L256
            c3_conv1_reuse_3[v228][v229][0] = v230;	// L256
            ap_fixed<10, 6> v231 = c3_conv1_reuse_3[v228][v229][2];	// L256
            c3_conv1_reuse_3[v228][v229][1] = v231;	// L256
            ap_fixed<10, 6> v232 = c3_conv1_reuse_3[v228][v229][3];	// L256
            c3_conv1_reuse_3[v228][v229][2] = v232;	// L256
            ap_fixed<10, 6> v233 = c3_conv1_reuse_3[v228][v229][4];	// L256
            c3_conv1_reuse_3[v228][v229][3] = v233;	// L256
            ap_fixed<10, 6> v234 = add[nn_2][v228][(0 + v229)][xx_2];	// L256
            c3_conv1_reuse_3[v228][v229][4] = v234;	// L256
          }
        }
        if ((xx_2 - 4) >= 0) {	// L256
          ap_fixed<10, 6> sum_2;	// L256
          ap_fixed<10, 6> v236 = 0;	// L472
          sum_2 = v236;	// L472
          l_rc_2: for (int rc_2 = 0; rc_2 < 16; rc_2++) {	// L256
            #pragma HLS pipeline
            l_ry_2: for (int ry_2 = 0; ry_2 < 5; ry_2++) {	// L256
              l_rx_2: for (int rx_2 = 0; rx_2 < 5; rx_2++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 6> v240 = c3_conv1_reuse_3[rc_2][ry_2][rx_2];	// L472
                  ap_fixed<10, 6> v241 = v7[ff_2][rc_2][ry_2][rx_2];	// L24
                  ap_fixed<20, 12> v242 = v240;	// L472
                  ap_fixed<20, 12> v243 = v241;	// L472
                  ap_fixed<20, 12> v244 = v242 * v243;	// L472
                  ap_fixed<10, 6> v245 = v8[ff_2];	// L25
                  ap_fixed<21, 13> v246 = v244;	// L472
                  ap_fixed<21, 13> v247 = v245;	// L472
                  ap_fixed<21, 13> v248 = v246 + v247;	// L472
                  ap_fixed<10, 6> v249 = sum_2;	// L256
                  ap_fixed<22, 14> v250 = v248;	// L472
                  ap_fixed<22, 14> v251 = v249;	// L472
                  ap_fixed<22, 14> v252 = v250 + v251;	// L472
                  ap_fixed<10, 6> v253 = v252;	// L472
                  sum_2 = v253;	// L472
                }
              }
            }
          }
          ap_fixed<10, 6> v254 = sum_2;	// L256
          c3_conv1[nn_2][ff_2][0][(xx_2 - 4)] = v254;	// L472
        }
      }
    }
  }
  ap_fixed<10, 6> c3_relu1[2][120][1][1];	// L472
  l_c3_relu1_i0_6: for (int i0_6 = 0; i0_6 < 2; i0_6++) {	// L472
    l_i1_6: for (int i1_6 = 0; i1_6 < 120; i1_6++) {	// L472
      ap_fixed<10, 6> v258 = c3_conv1[i0_6][i1_6][0][0];	// L472
      ap_fixed<36, 32> v259 = v258;	// L472
      ap_fixed<36, 32> v260 = 0;	// L472
      bool v261 = v259 <= v260;	// L472
      ap_fixed<10, 6> v262 = c3_conv1[i0_6][i1_6][0][0];	// L472
      ap_fixed<36, 32> v263 = 0;	// L472
      ap_fixed<36, 32> v264 = v262;	// L472
      ap_fixed<36, 32> v265 = v261 ? (ap_fixed<36, 32>)v263 : (ap_fixed<36, 32>)v264;	// L127
      ap_fixed<10, 6> v266 = v265;	// L472
      c3_relu1[i0_6][i1_6][0][0] = v266;	// L472
    }
  }
  ap_fixed<10, 6> c3_view[2][120];	// L472
  l_c3_view_b: for (int b = 0; b < 2; b++) {	// L472
    l_c_2: for (int c_2 = 0; c_2 < 120; c_2++) {	// L472
      ap_fixed<10, 6> v270 = c3_relu1[b][c_2][0][0];	// L472
      c3_view[b][c_2] = v270;	// L472
    }
  }
  ap_fixed<10, 6> f4_linear1[2][84];	// L472
  l_f4_linear1_x: for (int x = 0; x < 2; x++) {	// L472
    l_y: for (int y = 0; y < 84; y++) {	// L472
      int32_t sum_3;	// L256
      sum_3 = 0;	// L472
      l_r_9: for (int r_9 = 0; r_9 < 120; r_9++) {	// L256
        if (1) {	// L472
          ap_fixed<10, 6> v276 = c3_view[x][r_9];	// L472
          ap_fixed<10, 6> v277 = v9[x][r_9];	// L27
          ap_fixed<20, 12> v278 = v276;	// L472
          ap_fixed<20, 12> v279 = v277;	// L472
          ap_fixed<20, 12> v280 = v278 * v279;	// L472
          int32_t v281 = sum_3;	// L256
          ap_fixed<41, 33> v282 = v280;	// L472
          ap_fixed<41, 33> v283 = v281;	// L472
          ap_fixed<41, 33> v284 = v282 + v283;	// L472
          int32_t v285 = v284;	// L472
          sum_3 = v285;	// L472
        }
      }
      int32_t v286 = sum_3;	// L256
      ap_fixed<10, 6> v287 = v10[y];	// L28
      ap_fixed<37, 33> v288 = v286;	// L472
      ap_fixed<37, 33> v289 = v287;	// L472
      ap_fixed<37, 33> v290 = v288 + v289;	// L256
      ap_fixed<10, 6> v291 = v290;	// L472
      f4_linear1[x][y] = v291;	// L472
    }
  }
  ap_fixed<10, 6> f4_relu1[2][84];	// L472
  l_f4_relu1_i0_7: for (int i0_7 = 0; i0_7 < 2; i0_7++) {	// L472
    l_i1_7: for (int i1_7 = 0; i1_7 < 84; i1_7++) {	// L472
      ap_fixed<10, 6> v295 = f4_linear1[i0_7][i1_7];	// L472
      ap_fixed<36, 32> v296 = v295;	// L472
      ap_fixed<36, 32> v297 = 0;	// L472
      bool v298 = v296 <= v297;	// L472
      ap_fixed<10, 6> v299 = f4_linear1[i0_7][i1_7];	// L472
      ap_fixed<36, 32> v300 = 0;	// L472
      ap_fixed<36, 32> v301 = v299;	// L472
      ap_fixed<36, 32> v302 = v298 ? (ap_fixed<36, 32>)v300 : (ap_fixed<36, 32>)v301;	// L127
      ap_fixed<10, 6> v303 = v302;	// L472
      f4_relu1[i0_7][i1_7] = v303;	// L472
    }
  }
  ap_fixed<10, 6> f5_linear1[2][10];	// L472
  l_f5_linear1_x_0: for (int x_0 = 0; x_0 < 2; x_0++) {	// L472
    l_y_0: for (int y_0 = 0; y_0 < 10; y_0++) {	// L472
      int32_t sum_4;	// L256
      sum_4 = 0;	// L472
      l_r_10: for (int r_10 = 0; r_10 < 84; r_10++) {	// L256
        if (1) {	// L472
          ap_fixed<10, 6> v309 = f4_relu1[x_0][r_10];	// L472
          ap_fixed<10, 6> v310 = v11[x_0][r_10];	// L30
          ap_fixed<20, 12> v311 = v309;	// L472
          ap_fixed<20, 12> v312 = v310;	// L472
          ap_fixed<20, 12> v313 = v311 * v312;	// L472
          int32_t v314 = sum_4;	// L256
          ap_fixed<41, 33> v315 = v313;	// L472
          ap_fixed<41, 33> v316 = v314;	// L472
          ap_fixed<41, 33> v317 = v315 + v316;	// L472
          int32_t v318 = v317;	// L472
          sum_4 = v318;	// L472
        }
      }
      int32_t v319 = sum_4;	// L256
      ap_fixed<10, 6> v320 = v12[y_0];	// L31
      ap_fixed<37, 33> v321 = v319;	// L472
      ap_fixed<37, 33> v322 = v320;	// L472
      ap_fixed<37, 33> v323 = v321 + v322;	// L256
      ap_fixed<10, 6> v324 = v323;	// L472
      f5_linear1[x_0][y_0] = v324;	// L472
    }
  }
  l_f5_logsoftmax1_x_1: for (int x_1 = 0; x_1 < 2; x_1++) {	// L472
    l_y_1: for (int y_1 = 0; y_1 < 10; y_1++) {	// L472
      ap_fixed<10, 6> v327 = f5_linear1[x_1][y_1];	// L472
      float v328 = v327;	// L472
      float v329 = exp(v328);	// L11
      int32_t sum_5;	// L256
      sum_5 = 0;	// L472
      l_r_11: for (int r_11 = 0; r_11 < 10; r_11++) {	// L256
        if (1) {	// L472
          ap_fixed<10, 6> v332 = f5_linear1[x_1][(y_1 + r_11)];	// L472
          int32_t v333 = sum_5;	// L256
          ap_fixed<37, 33> v334 = v332;	// L472
          ap_fixed<37, 33> v335 = v333;	// L472
          ap_fixed<37, 33> v336 = v334 + v335;	// L472
          int32_t v337 = v336;	// L472
          sum_5 = v337;	// L472
        }
      }
      int32_t v338 = sum_5;	// L256
      float v339 = v338;	// L472
      float v340 = v329 / v339;	// L11
      float v341 = log(v340);	// L23
      ap_fixed<10, 6> v342 = v341;	// L472
      v13[x_1][y_1] = v342;	// L472
    }
  }
}

