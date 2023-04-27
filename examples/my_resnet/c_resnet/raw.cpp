
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
  ap_fixed<10, 4> v103[2][100]
) {	// L28
  ap_fixed<10, 4> conv1_x_0_conv1_pad[2][3][34][34];	// L472
  l_conv1_x_0_conv1_pad_i0: for (int i0 = 0; i0 < 2; i0++) {	// L472
    l_i1: for (int i1 = 0; i1 < 3; i1++) {	// L472
      l_i2: for (int i2 = 0; i2 < 34; i2++) {	// L472
        l_i3: for (int i3 = 0; i3 < 34; i3++) {	// L472
          ap_int<33> v109 = i2;	// L472
          ap_int<33> v110 = 1;	// L472
          bool v111 = v109 >= v110;	// L472
          bool v112 = 1 & v111;	// L30
          ap_int<33> v113 = 33;	// L472
          bool v114 = v109 < v113;	// L472
          bool v115 = v112 & v114;	// L30
          ap_int<33> v116 = i3;	// L472
          bool v117 = v116 >= v110;	// L472
          bool v118 = v115 & v117;	// L30
          bool v119 = v116 < v113;	// L472
          bool v120 = v118 & v119;	// L30
          ap_fixed<10, 4> v121 = v0[i0][i1][(i2 - 1)][(i3 - 1)];	// L62
          ap_fixed<10, 4> v122 = 0.000000;	// L472
          ap_fixed<10, 4> v123 = v120 ? (ap_fixed<10, 4>)v121 : (ap_fixed<10, 4>)v122;	// L127
          conv1_x_0_conv1_pad[i0][i1][i2][i3] = v123;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv1_x_0_conv1[2][64][32][32];	// L472
  l_conv1_x_0_conv1_nn: for (int nn = 0; nn < 2; nn++) {	// L472
    l_ff: for (int ff = 0; ff < 64; ff++) {	// L472
      l_yy: for (int yy = 0; yy < 32; yy++) {	// L472
        l_xx: for (int xx = 0; xx < 32; xx++) {	// L472
          ap_fixed<10, 4> sum;	// L256
          ap_fixed<10, 4> v130 = 0;	// L472
          sum = v130;	// L472
          l_rc: for (int rc = 0; rc < 3; rc++) {	// L256
            l_ry: for (int ry = 0; ry < 3; ry++) {	// L256
              l_rx: for (int rx = 0; rx < 3; rx++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v134 = conv1_x_0_conv1_pad[nn][rc][(yy + ry)][(xx + rx)];	// L472
                  ap_fixed<10, 4> v135 = v1[ff][rc][ry][rx];	// L71
                  ap_fixed<20, 8> v136 = v134;	// L472
                  ap_fixed<20, 8> v137 = v135;	// L472
                  ap_fixed<20, 8> v138 = v136 * v137;	// L472
                  ap_fixed<10, 4> v139 = sum;	// L256
                  ap_fixed<21, 9> v140 = v138;	// L472
                  ap_fixed<21, 9> v141 = v139;	// L472
                  ap_fixed<21, 9> v142 = v140 + v141;	// L472
                  ap_fixed<10, 4> v143 = v142;	// L472
                  sum = v143;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v144 = sum;	// L256
          conv1_x_0_conv1[nn][ff][yy][xx] = v144;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv1_x_0_bn1[2][64][32][32];	// L472
  l_conv1_x_0_bn1_i0_0: for (int i0_0 = 0; i0_0 < 2; i0_0++) {	// L472
    l_i1_0: for (int i1_0 = 0; i1_0 < 64; i1_0++) {	// L472
      l_i2_0: for (int i2_0 = 0; i2_0 < 32; i2_0++) {	// L472
        l_i3_0: for (int i3_0 = 0; i3_0 < 32; i3_0++) {	// L472
          ap_fixed<10, 4> v150 = conv1_x_0_conv1[i0_0][i1_0][i2_0][i3_0];	// L472
          ap_fixed<10, 4> v151 = v4[i1_0];	// L75
          ap_fixed<11, 5> v152 = v150;	// L472
          ap_fixed<11, 5> v153 = v151;	// L472
          ap_fixed<11, 5> v154 = v152 - v153;	// L472
          ap_fixed<10, 4> v155 = v5[i1_0];	// L75
          double v156 = v155;	// L472
          double v157 = v156 + 0.000000;	// L75
          double v158 = sqrt(v157);	// L41
          double v159 = v154;	// L472
          double v160 = v159 / v158;	// L472
          ap_fixed<10, 4> v161 = v2[i1_0];	// L75
          double v162 = v161;	// L472
          double v163 = v160 * v162;	// L472
          ap_fixed<10, 4> v164 = v3[i1_0];	// L75
          double v165 = v164;	// L472
          double v166 = v163 + v165;	// L472
          ap_fixed<10, 4> v167 = v166;	// L472
          conv1_x_0_bn1[i0_0][i1_0][i2_0][i3_0] = v167;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv1_x_0_relu[2][64][32][32];	// L472
  l_conv1_x_0_relu_i0_1: for (int i0_1 = 0; i0_1 < 2; i0_1++) {	// L472
    l_i1_1: for (int i1_1 = 0; i1_1 < 64; i1_1++) {	// L472
      l_i2_1: for (int i2_1 = 0; i2_1 < 32; i2_1++) {	// L472
        l_i3_1: for (int i3_1 = 0; i3_1 < 32; i3_1++) {	// L472
          ap_fixed<10, 4> v173 = conv1_x_0_bn1[i0_1][i1_1][i2_1][i3_1];	// L472
          ap_fixed<38, 32> v174 = v173;	// L472
          ap_fixed<38, 32> v175 = 0;	// L472
          bool v176 = v174 <= v175;	// L472
          ap_fixed<10, 4> v177 = conv1_x_0_bn1[i0_1][i1_1][i2_1][i3_1];	// L472
          ap_fixed<38, 32> v178 = 0;	// L472
          ap_fixed<38, 32> v179 = v177;	// L472
          ap_fixed<38, 32> v180 = v176 ? (ap_fixed<38, 32>)v178 : (ap_fixed<38, 32>)v179;	// L127
          ap_fixed<10, 4> v181 = v180;	// L472
          conv1_x_0_relu[i0_1][i1_1][i2_1][i3_1] = v181;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_conv1_pad[2][64][34][34];	// L472
  l_conv2_x_0_conv1_pad_i0_2: for (int i0_2 = 0; i0_2 < 2; i0_2++) {	// L472
    l_i1_2: for (int i1_2 = 0; i1_2 < 64; i1_2++) {	// L472
      l_i2_2: for (int i2_2 = 0; i2_2 < 34; i2_2++) {	// L472
        l_i3_2: for (int i3_2 = 0; i3_2 < 34; i3_2++) {	// L472
          ap_int<33> v187 = i2_2;	// L472
          ap_int<33> v188 = 1;	// L472
          bool v189 = v187 >= v188;	// L472
          bool v190 = 1 & v189;	// L30
          ap_int<33> v191 = 33;	// L472
          bool v192 = v187 < v191;	// L472
          bool v193 = v190 & v192;	// L30
          ap_int<33> v194 = i3_2;	// L472
          bool v195 = v194 >= v188;	// L472
          bool v196 = v193 & v195;	// L30
          bool v197 = v194 < v191;	// L472
          bool v198 = v196 & v197;	// L30
          ap_fixed<10, 4> v199 = conv1_x_0_relu[i0_2][i1_2][(i2_2 - 1)][(i3_2 - 1)];	// L472
          ap_fixed<10, 4> v200 = 0.000000;	// L472
          ap_fixed<10, 4> v201 = v198 ? (ap_fixed<10, 4>)v199 : (ap_fixed<10, 4>)v200;	// L127
          conv2_x_0_conv1_pad[i0_2][i1_2][i2_2][i3_2] = v201;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_conv1[2][64][32][32];	// L472
  l_conv2_x_0_conv1_nn_0: for (int nn_0 = 0; nn_0 < 2; nn_0++) {	// L472
    l_ff_0: for (int ff_0 = 0; ff_0 < 64; ff_0++) {	// L472
      l_yy_0: for (int yy_0 = 0; yy_0 < 32; yy_0++) {	// L472
        l_xx_0: for (int xx_0 = 0; xx_0 < 32; xx_0++) {	// L472
          ap_fixed<10, 4> sum_0;	// L256
          ap_fixed<10, 4> v208 = 0;	// L472
          sum_0 = v208;	// L472
          l_rc_0: for (int rc_0 = 0; rc_0 < 64; rc_0++) {	// L256
            l_ry_0: for (int ry_0 = 0; ry_0 < 3; ry_0++) {	// L256
              l_rx_0: for (int rx_0 = 0; rx_0 < 3; rx_0++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v212 = conv2_x_0_conv1_pad[nn_0][rc_0][(yy_0 + ry_0)][(xx_0 + rx_0)];	// L472
                  ap_fixed<10, 4> v213 = v6[ff_0][rc_0][ry_0][rx_0];	// L34
                  ap_fixed<20, 8> v214 = v212;	// L472
                  ap_fixed<20, 8> v215 = v213;	// L472
                  ap_fixed<20, 8> v216 = v214 * v215;	// L472
                  ap_fixed<10, 4> v217 = sum_0;	// L256
                  ap_fixed<21, 9> v218 = v216;	// L472
                  ap_fixed<21, 9> v219 = v217;	// L472
                  ap_fixed<21, 9> v220 = v218 + v219;	// L472
                  ap_fixed<10, 4> v221 = v220;	// L472
                  sum_0 = v221;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v222 = sum_0;	// L256
          conv2_x_0_conv1[nn_0][ff_0][yy_0][xx_0] = v222;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_bn1[2][64][32][32];	// L472
  l_conv2_x_0_bn1_i0_3: for (int i0_3 = 0; i0_3 < 2; i0_3++) {	// L472
    l_i1_3: for (int i1_3 = 0; i1_3 < 64; i1_3++) {	// L472
      l_i2_3: for (int i2_3 = 0; i2_3 < 32; i2_3++) {	// L472
        l_i3_3: for (int i3_3 = 0; i3_3 < 32; i3_3++) {	// L472
          ap_fixed<10, 4> v228 = conv2_x_0_conv1[i0_3][i1_3][i2_3][i3_3];	// L472
          ap_fixed<10, 4> v229 = v9[i1_3];	// L52
          ap_fixed<11, 5> v230 = v228;	// L472
          ap_fixed<11, 5> v231 = v229;	// L472
          ap_fixed<11, 5> v232 = v230 - v231;	// L472
          ap_fixed<10, 4> v233 = v10[i1_3];	// L52
          double v234 = v233;	// L472
          double v235 = v234 + 0.000000;	// L52
          double v236 = sqrt(v235);	// L41
          double v237 = v232;	// L472
          double v238 = v237 / v236;	// L472
          ap_fixed<10, 4> v239 = v7[i1_3];	// L52
          double v240 = v239;	// L472
          double v241 = v238 * v240;	// L472
          ap_fixed<10, 4> v242 = v8[i1_3];	// L52
          double v243 = v242;	// L472
          double v244 = v241 + v243;	// L472
          ap_fixed<10, 4> v245 = v244;	// L472
          conv2_x_0_bn1[i0_3][i1_3][i2_3][i3_3] = v245;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_relu1[2][64][32][32];	// L472
  l_conv2_x_0_relu1_i0_4: for (int i0_4 = 0; i0_4 < 2; i0_4++) {	// L472
    l_i1_4: for (int i1_4 = 0; i1_4 < 64; i1_4++) {	// L472
      l_i2_4: for (int i2_4 = 0; i2_4 < 32; i2_4++) {	// L472
        l_i3_4: for (int i3_4 = 0; i3_4 < 32; i3_4++) {	// L472
          ap_fixed<10, 4> v251 = conv2_x_0_bn1[i0_4][i1_4][i2_4][i3_4];	// L472
          ap_fixed<38, 32> v252 = v251;	// L472
          ap_fixed<38, 32> v253 = 0;	// L472
          bool v254 = v252 <= v253;	// L472
          ap_fixed<10, 4> v255 = conv2_x_0_bn1[i0_4][i1_4][i2_4][i3_4];	// L472
          ap_fixed<38, 32> v256 = 0;	// L472
          ap_fixed<38, 32> v257 = v255;	// L472
          ap_fixed<38, 32> v258 = v254 ? (ap_fixed<38, 32>)v256 : (ap_fixed<38, 32>)v257;	// L127
          ap_fixed<10, 4> v259 = v258;	// L472
          conv2_x_0_relu1[i0_4][i1_4][i2_4][i3_4] = v259;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_conv2_pad[2][64][34][34];	// L472
  l_conv2_x_0_conv2_pad_i0_5: for (int i0_5 = 0; i0_5 < 2; i0_5++) {	// L472
    l_i1_5: for (int i1_5 = 0; i1_5 < 64; i1_5++) {	// L472
      l_i2_5: for (int i2_5 = 0; i2_5 < 34; i2_5++) {	// L472
        l_i3_5: for (int i3_5 = 0; i3_5 < 34; i3_5++) {	// L472
          ap_int<33> v265 = i2_5;	// L472
          ap_int<33> v266 = 1;	// L472
          bool v267 = v265 >= v266;	// L472
          bool v268 = 1 & v267;	// L30
          ap_int<33> v269 = 33;	// L472
          bool v270 = v265 < v269;	// L472
          bool v271 = v268 & v270;	// L30
          ap_int<33> v272 = i3_5;	// L472
          bool v273 = v272 >= v266;	// L472
          bool v274 = v271 & v273;	// L30
          bool v275 = v272 < v269;	// L472
          bool v276 = v274 & v275;	// L30
          ap_fixed<10, 4> v277 = conv2_x_0_relu1[i0_5][i1_5][(i2_5 - 1)][(i3_5 - 1)];	// L472
          ap_fixed<10, 4> v278 = 0.000000;	// L472
          ap_fixed<10, 4> v279 = v276 ? (ap_fixed<10, 4>)v277 : (ap_fixed<10, 4>)v278;	// L127
          conv2_x_0_conv2_pad[i0_5][i1_5][i2_5][i3_5] = v279;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_conv2[2][64][32][32];	// L472
  l_conv2_x_0_conv2_nn_1: for (int nn_1 = 0; nn_1 < 2; nn_1++) {	// L472
    l_ff_1: for (int ff_1 = 0; ff_1 < 64; ff_1++) {	// L472
      l_yy_1: for (int yy_1 = 0; yy_1 < 32; yy_1++) {	// L472
        l_xx_1: for (int xx_1 = 0; xx_1 < 32; xx_1++) {	// L472
          ap_fixed<10, 4> sum_1;	// L256
          ap_fixed<10, 4> v286 = 0;	// L472
          sum_1 = v286;	// L472
          l_rc_1: for (int rc_1 = 0; rc_1 < 64; rc_1++) {	// L256
            l_ry_1: for (int ry_1 = 0; ry_1 < 3; ry_1++) {	// L256
              l_rx_1: for (int rx_1 = 0; rx_1 < 3; rx_1++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v290 = conv2_x_0_conv2_pad[nn_1][rc_1][(yy_1 + ry_1)][(xx_1 + rx_1)];	// L472
                  ap_fixed<10, 4> v291 = v11[ff_1][rc_1][ry_1][rx_1];	// L36
                  ap_fixed<20, 8> v292 = v290;	// L472
                  ap_fixed<20, 8> v293 = v291;	// L472
                  ap_fixed<20, 8> v294 = v292 * v293;	// L472
                  ap_fixed<10, 4> v295 = sum_1;	// L256
                  ap_fixed<21, 9> v296 = v294;	// L472
                  ap_fixed<21, 9> v297 = v295;	// L472
                  ap_fixed<21, 9> v298 = v296 + v297;	// L472
                  ap_fixed<10, 4> v299 = v298;	// L472
                  sum_1 = v299;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v300 = sum_1;	// L256
          conv2_x_0_conv2[nn_1][ff_1][yy_1][xx_1] = v300;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_bn2[2][64][32][32];	// L472
  l_conv2_x_0_bn2_i0_6: for (int i0_6 = 0; i0_6 < 2; i0_6++) {	// L472
    l_i1_6: for (int i1_6 = 0; i1_6 < 64; i1_6++) {	// L472
      l_i2_6: for (int i2_6 = 0; i2_6 < 32; i2_6++) {	// L472
        l_i3_6: for (int i3_6 = 0; i3_6 < 32; i3_6++) {	// L472
          ap_fixed<10, 4> v306 = conv2_x_0_conv2[i0_6][i1_6][i2_6][i3_6];	// L472
          ap_fixed<10, 4> v307 = v14[i1_6];	// L52
          ap_fixed<11, 5> v308 = v306;	// L472
          ap_fixed<11, 5> v309 = v307;	// L472
          ap_fixed<11, 5> v310 = v308 - v309;	// L472
          ap_fixed<10, 4> v311 = v15[i1_6];	// L52
          double v312 = v311;	// L472
          double v313 = v312 + 0.000000;	// L52
          double v314 = sqrt(v313);	// L41
          double v315 = v310;	// L472
          double v316 = v315 / v314;	// L472
          ap_fixed<10, 4> v317 = v12[i1_6];	// L52
          double v318 = v317;	// L472
          double v319 = v316 * v318;	// L472
          ap_fixed<10, 4> v320 = v13[i1_6];	// L52
          double v321 = v320;	// L472
          double v322 = v319 + v321;	// L472
          ap_fixed<10, 4> v323 = v322;	// L472
          conv2_x_0_bn2[i0_6][i1_6][i2_6][i3_6] = v323;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_add[2][64][32][32];	// L472
  l_conv2_x_0_add_i0_7: for (int i0_7 = 0; i0_7 < 2; i0_7++) {	// L472
    l_i1_7: for (int i1_7 = 0; i1_7 < 64; i1_7++) {	// L472
      l_i2_7: for (int i2_7 = 0; i2_7 < 32; i2_7++) {	// L472
        l_i3_7: for (int i3_7 = 0; i3_7 < 32; i3_7++) {	// L472
          ap_fixed<10, 4> v329 = conv2_x_0_bn2[i0_7][i1_7][i2_7][i3_7];	// L472
          ap_fixed<10, 4> v330 = conv1_x_0_relu[i0_7][i1_7][i2_7][i3_7];	// L472
          ap_fixed<11, 5> v331 = v329;	// L472
          ap_fixed<11, 5> v332 = v330;	// L472
          ap_fixed<11, 5> v333 = v331 + v332;	// L472
          ap_fixed<10, 4> v334 = v333;	// L472
          conv2_x_0_add[i0_7][i1_7][i2_7][i3_7] = v334;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_0_relu2[2][64][32][32];	// L472
  l_conv2_x_0_relu2_i0_8: for (int i0_8 = 0; i0_8 < 2; i0_8++) {	// L472
    l_i1_8: for (int i1_8 = 0; i1_8 < 64; i1_8++) {	// L472
      l_i2_8: for (int i2_8 = 0; i2_8 < 32; i2_8++) {	// L472
        l_i3_8: for (int i3_8 = 0; i3_8 < 32; i3_8++) {	// L472
          ap_fixed<10, 4> v340 = conv2_x_0_add[i0_8][i1_8][i2_8][i3_8];	// L472
          ap_fixed<38, 32> v341 = v340;	// L472
          ap_fixed<38, 32> v342 = 0;	// L472
          bool v343 = v341 <= v342;	// L472
          ap_fixed<10, 4> v344 = conv2_x_0_add[i0_8][i1_8][i2_8][i3_8];	// L472
          ap_fixed<38, 32> v345 = 0;	// L472
          ap_fixed<38, 32> v346 = v344;	// L472
          ap_fixed<38, 32> v347 = v343 ? (ap_fixed<38, 32>)v345 : (ap_fixed<38, 32>)v346;	// L127
          ap_fixed<10, 4> v348 = v347;	// L472
          conv2_x_0_relu2[i0_8][i1_8][i2_8][i3_8] = v348;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_conv1_pad[2][64][34][34];	// L472
  l_conv2_x_1_conv1_pad_i0_9: for (int i0_9 = 0; i0_9 < 2; i0_9++) {	// L472
    l_i1_9: for (int i1_9 = 0; i1_9 < 64; i1_9++) {	// L472
      l_i2_9: for (int i2_9 = 0; i2_9 < 34; i2_9++) {	// L472
        l_i3_9: for (int i3_9 = 0; i3_9 < 34; i3_9++) {	// L472
          ap_int<33> v354 = i2_9;	// L472
          ap_int<33> v355 = 1;	// L472
          bool v356 = v354 >= v355;	// L472
          bool v357 = 1 & v356;	// L30
          ap_int<33> v358 = 33;	// L472
          bool v359 = v354 < v358;	// L472
          bool v360 = v357 & v359;	// L30
          ap_int<33> v361 = i3_9;	// L472
          bool v362 = v361 >= v355;	// L472
          bool v363 = v360 & v362;	// L30
          bool v364 = v361 < v358;	// L472
          bool v365 = v363 & v364;	// L30
          ap_fixed<10, 4> v366 = conv2_x_0_relu2[i0_9][i1_9][(i2_9 - 1)][(i3_9 - 1)];	// L472
          ap_fixed<10, 4> v367 = 0.000000;	// L472
          ap_fixed<10, 4> v368 = v365 ? (ap_fixed<10, 4>)v366 : (ap_fixed<10, 4>)v367;	// L127
          conv2_x_1_conv1_pad[i0_9][i1_9][i2_9][i3_9] = v368;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_conv1[2][64][32][32];	// L472
  l_conv2_x_1_conv1_nn_2: for (int nn_2 = 0; nn_2 < 2; nn_2++) {	// L472
    l_ff_2: for (int ff_2 = 0; ff_2 < 64; ff_2++) {	// L472
      l_yy_2: for (int yy_2 = 0; yy_2 < 32; yy_2++) {	// L472
        l_xx_2: for (int xx_2 = 0; xx_2 < 32; xx_2++) {	// L472
          ap_fixed<10, 4> sum_2;	// L256
          ap_fixed<10, 4> v375 = 0;	// L472
          sum_2 = v375;	// L472
          l_rc_2: for (int rc_2 = 0; rc_2 < 64; rc_2++) {	// L256
            l_ry_2: for (int ry_2 = 0; ry_2 < 3; ry_2++) {	// L256
              l_rx_2: for (int rx_2 = 0; rx_2 < 3; rx_2++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v379 = conv2_x_1_conv1_pad[nn_2][rc_2][(yy_2 + ry_2)][(xx_2 + rx_2)];	// L472
                  ap_fixed<10, 4> v380 = v16[ff_2][rc_2][ry_2][rx_2];	// L34
                  ap_fixed<20, 8> v381 = v379;	// L472
                  ap_fixed<20, 8> v382 = v380;	// L472
                  ap_fixed<20, 8> v383 = v381 * v382;	// L472
                  ap_fixed<10, 4> v384 = sum_2;	// L256
                  ap_fixed<21, 9> v385 = v383;	// L472
                  ap_fixed<21, 9> v386 = v384;	// L472
                  ap_fixed<21, 9> v387 = v385 + v386;	// L472
                  ap_fixed<10, 4> v388 = v387;	// L472
                  sum_2 = v388;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v389 = sum_2;	// L256
          conv2_x_1_conv1[nn_2][ff_2][yy_2][xx_2] = v389;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_bn1[2][64][32][32];	// L472
  l_conv2_x_1_bn1_i0_10: for (int i0_10 = 0; i0_10 < 2; i0_10++) {	// L472
    l_i1_10: for (int i1_10 = 0; i1_10 < 64; i1_10++) {	// L472
      l_i2_10: for (int i2_10 = 0; i2_10 < 32; i2_10++) {	// L472
        l_i3_10: for (int i3_10 = 0; i3_10 < 32; i3_10++) {	// L472
          ap_fixed<10, 4> v395 = conv2_x_1_conv1[i0_10][i1_10][i2_10][i3_10];	// L472
          ap_fixed<10, 4> v396 = v19[i1_10];	// L52
          ap_fixed<11, 5> v397 = v395;	// L472
          ap_fixed<11, 5> v398 = v396;	// L472
          ap_fixed<11, 5> v399 = v397 - v398;	// L472
          ap_fixed<10, 4> v400 = v20[i1_10];	// L52
          double v401 = v400;	// L472
          double v402 = v401 + 0.000000;	// L52
          double v403 = sqrt(v402);	// L41
          double v404 = v399;	// L472
          double v405 = v404 / v403;	// L472
          ap_fixed<10, 4> v406 = v17[i1_10];	// L52
          double v407 = v406;	// L472
          double v408 = v405 * v407;	// L472
          ap_fixed<10, 4> v409 = v18[i1_10];	// L52
          double v410 = v409;	// L472
          double v411 = v408 + v410;	// L472
          ap_fixed<10, 4> v412 = v411;	// L472
          conv2_x_1_bn1[i0_10][i1_10][i2_10][i3_10] = v412;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_relu1[2][64][32][32];	// L472
  l_conv2_x_1_relu1_i0_11: for (int i0_11 = 0; i0_11 < 2; i0_11++) {	// L472
    l_i1_11: for (int i1_11 = 0; i1_11 < 64; i1_11++) {	// L472
      l_i2_11: for (int i2_11 = 0; i2_11 < 32; i2_11++) {	// L472
        l_i3_11: for (int i3_11 = 0; i3_11 < 32; i3_11++) {	// L472
          ap_fixed<10, 4> v418 = conv2_x_1_bn1[i0_11][i1_11][i2_11][i3_11];	// L472
          ap_fixed<38, 32> v419 = v418;	// L472
          ap_fixed<38, 32> v420 = 0;	// L472
          bool v421 = v419 <= v420;	// L472
          ap_fixed<10, 4> v422 = conv2_x_1_bn1[i0_11][i1_11][i2_11][i3_11];	// L472
          ap_fixed<38, 32> v423 = 0;	// L472
          ap_fixed<38, 32> v424 = v422;	// L472
          ap_fixed<38, 32> v425 = v421 ? (ap_fixed<38, 32>)v423 : (ap_fixed<38, 32>)v424;	// L127
          ap_fixed<10, 4> v426 = v425;	// L472
          conv2_x_1_relu1[i0_11][i1_11][i2_11][i3_11] = v426;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_conv2_pad[2][64][34][34];	// L472
  l_conv2_x_1_conv2_pad_i0_12: for (int i0_12 = 0; i0_12 < 2; i0_12++) {	// L472
    l_i1_12: for (int i1_12 = 0; i1_12 < 64; i1_12++) {	// L472
      l_i2_12: for (int i2_12 = 0; i2_12 < 34; i2_12++) {	// L472
        l_i3_12: for (int i3_12 = 0; i3_12 < 34; i3_12++) {	// L472
          ap_int<33> v432 = i2_12;	// L472
          ap_int<33> v433 = 1;	// L472
          bool v434 = v432 >= v433;	// L472
          bool v435 = 1 & v434;	// L30
          ap_int<33> v436 = 33;	// L472
          bool v437 = v432 < v436;	// L472
          bool v438 = v435 & v437;	// L30
          ap_int<33> v439 = i3_12;	// L472
          bool v440 = v439 >= v433;	// L472
          bool v441 = v438 & v440;	// L30
          bool v442 = v439 < v436;	// L472
          bool v443 = v441 & v442;	// L30
          ap_fixed<10, 4> v444 = conv2_x_1_relu1[i0_12][i1_12][(i2_12 - 1)][(i3_12 - 1)];	// L472
          ap_fixed<10, 4> v445 = 0.000000;	// L472
          ap_fixed<10, 4> v446 = v443 ? (ap_fixed<10, 4>)v444 : (ap_fixed<10, 4>)v445;	// L127
          conv2_x_1_conv2_pad[i0_12][i1_12][i2_12][i3_12] = v446;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_conv2[2][64][32][32];	// L472
  l_conv2_x_1_conv2_nn_3: for (int nn_3 = 0; nn_3 < 2; nn_3++) {	// L472
    l_ff_3: for (int ff_3 = 0; ff_3 < 64; ff_3++) {	// L472
      l_yy_3: for (int yy_3 = 0; yy_3 < 32; yy_3++) {	// L472
        l_xx_3: for (int xx_3 = 0; xx_3 < 32; xx_3++) {	// L472
          ap_fixed<10, 4> sum_3;	// L256
          ap_fixed<10, 4> v453 = 0;	// L472
          sum_3 = v453;	// L472
          l_rc_3: for (int rc_3 = 0; rc_3 < 64; rc_3++) {	// L256
            l_ry_3: for (int ry_3 = 0; ry_3 < 3; ry_3++) {	// L256
              l_rx_3: for (int rx_3 = 0; rx_3 < 3; rx_3++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v457 = conv2_x_1_conv2_pad[nn_3][rc_3][(yy_3 + ry_3)][(xx_3 + rx_3)];	// L472
                  ap_fixed<10, 4> v458 = v21[ff_3][rc_3][ry_3][rx_3];	// L36
                  ap_fixed<20, 8> v459 = v457;	// L472
                  ap_fixed<20, 8> v460 = v458;	// L472
                  ap_fixed<20, 8> v461 = v459 * v460;	// L472
                  ap_fixed<10, 4> v462 = sum_3;	// L256
                  ap_fixed<21, 9> v463 = v461;	// L472
                  ap_fixed<21, 9> v464 = v462;	// L472
                  ap_fixed<21, 9> v465 = v463 + v464;	// L472
                  ap_fixed<10, 4> v466 = v465;	// L472
                  sum_3 = v466;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v467 = sum_3;	// L256
          conv2_x_1_conv2[nn_3][ff_3][yy_3][xx_3] = v467;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_bn2[2][64][32][32];	// L472
  l_conv2_x_1_bn2_i0_13: for (int i0_13 = 0; i0_13 < 2; i0_13++) {	// L472
    l_i1_13: for (int i1_13 = 0; i1_13 < 64; i1_13++) {	// L472
      l_i2_13: for (int i2_13 = 0; i2_13 < 32; i2_13++) {	// L472
        l_i3_13: for (int i3_13 = 0; i3_13 < 32; i3_13++) {	// L472
          ap_fixed<10, 4> v473 = conv2_x_1_conv2[i0_13][i1_13][i2_13][i3_13];	// L472
          ap_fixed<10, 4> v474 = v24[i1_13];	// L52
          ap_fixed<11, 5> v475 = v473;	// L472
          ap_fixed<11, 5> v476 = v474;	// L472
          ap_fixed<11, 5> v477 = v475 - v476;	// L472
          ap_fixed<10, 4> v478 = v25[i1_13];	// L52
          double v479 = v478;	// L472
          double v480 = v479 + 0.000000;	// L52
          double v481 = sqrt(v480);	// L41
          double v482 = v477;	// L472
          double v483 = v482 / v481;	// L472
          ap_fixed<10, 4> v484 = v22[i1_13];	// L52
          double v485 = v484;	// L472
          double v486 = v483 * v485;	// L472
          ap_fixed<10, 4> v487 = v23[i1_13];	// L52
          double v488 = v487;	// L472
          double v489 = v486 + v488;	// L472
          ap_fixed<10, 4> v490 = v489;	// L472
          conv2_x_1_bn2[i0_13][i1_13][i2_13][i3_13] = v490;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_add[2][64][32][32];	// L472
  l_conv2_x_1_add_i0_14: for (int i0_14 = 0; i0_14 < 2; i0_14++) {	// L472
    l_i1_14: for (int i1_14 = 0; i1_14 < 64; i1_14++) {	// L472
      l_i2_14: for (int i2_14 = 0; i2_14 < 32; i2_14++) {	// L472
        l_i3_14: for (int i3_14 = 0; i3_14 < 32; i3_14++) {	// L472
          ap_fixed<10, 4> v496 = conv2_x_1_bn2[i0_14][i1_14][i2_14][i3_14];	// L472
          ap_fixed<10, 4> v497 = conv2_x_0_relu2[i0_14][i1_14][i2_14][i3_14];	// L472
          ap_fixed<11, 5> v498 = v496;	// L472
          ap_fixed<11, 5> v499 = v497;	// L472
          ap_fixed<11, 5> v500 = v498 + v499;	// L472
          ap_fixed<10, 4> v501 = v500;	// L472
          conv2_x_1_add[i0_14][i1_14][i2_14][i3_14] = v501;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv2_x_1_relu2[2][64][32][32];	// L472
  l_conv2_x_1_relu2_i0_15: for (int i0_15 = 0; i0_15 < 2; i0_15++) {	// L472
    l_i1_15: for (int i1_15 = 0; i1_15 < 64; i1_15++) {	// L472
      l_i2_15: for (int i2_15 = 0; i2_15 < 32; i2_15++) {	// L472
        l_i3_15: for (int i3_15 = 0; i3_15 < 32; i3_15++) {	// L472
          ap_fixed<10, 4> v507 = conv2_x_1_add[i0_15][i1_15][i2_15][i3_15];	// L472
          ap_fixed<38, 32> v508 = v507;	// L472
          ap_fixed<38, 32> v509 = 0;	// L472
          bool v510 = v508 <= v509;	// L472
          ap_fixed<10, 4> v511 = conv2_x_1_add[i0_15][i1_15][i2_15][i3_15];	// L472
          ap_fixed<38, 32> v512 = 0;	// L472
          ap_fixed<38, 32> v513 = v511;	// L472
          ap_fixed<38, 32> v514 = v510 ? (ap_fixed<38, 32>)v512 : (ap_fixed<38, 32>)v513;	// L127
          ap_fixed<10, 4> v515 = v514;	// L472
          conv2_x_1_relu2[i0_15][i1_15][i2_15][i3_15] = v515;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_conv1_pad[2][64][34][34];	// L472
  l_conv3_x_0_conv1_pad_i0_16: for (int i0_16 = 0; i0_16 < 2; i0_16++) {	// L472
    l_i1_16: for (int i1_16 = 0; i1_16 < 64; i1_16++) {	// L472
      l_i2_16: for (int i2_16 = 0; i2_16 < 34; i2_16++) {	// L472
        l_i3_16: for (int i3_16 = 0; i3_16 < 34; i3_16++) {	// L472
          ap_int<33> v521 = i2_16;	// L472
          ap_int<33> v522 = 1;	// L472
          bool v523 = v521 >= v522;	// L472
          bool v524 = 1 & v523;	// L30
          ap_int<33> v525 = 33;	// L472
          bool v526 = v521 < v525;	// L472
          bool v527 = v524 & v526;	// L30
          ap_int<33> v528 = i3_16;	// L472
          bool v529 = v528 >= v522;	// L472
          bool v530 = v527 & v529;	// L30
          bool v531 = v528 < v525;	// L472
          bool v532 = v530 & v531;	// L30
          ap_fixed<10, 4> v533 = conv2_x_1_relu2[i0_16][i1_16][(i2_16 - 1)][(i3_16 - 1)];	// L472
          ap_fixed<10, 4> v534 = 0.000000;	// L472
          ap_fixed<10, 4> v535 = v532 ? (ap_fixed<10, 4>)v533 : (ap_fixed<10, 4>)v534;	// L127
          conv3_x_0_conv1_pad[i0_16][i1_16][i2_16][i3_16] = v535;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_conv1[2][128][16][16];	// L472
  l_conv3_x_0_conv1_nn_4: for (int nn_4 = 0; nn_4 < 2; nn_4++) {	// L472
    l_ff_4: for (int ff_4 = 0; ff_4 < 128; ff_4++) {	// L472
      l_yy_4: for (int yy_4 = 0; yy_4 < 16; yy_4++) {	// L472
        l_xx_4: for (int xx_4 = 0; xx_4 < 16; xx_4++) {	// L472
          ap_fixed<10, 4> sum_4;	// L256
          ap_fixed<10, 4> v542 = 0;	// L472
          sum_4 = v542;	// L472
          l_rc_4: for (int rc_4 = 0; rc_4 < 64; rc_4++) {	// L256
            l_ry_4: for (int ry_4 = 0; ry_4 < 3; ry_4++) {	// L256
              l_rx_4: for (int rx_4 = 0; rx_4 < 3; rx_4++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v546 = conv3_x_0_conv1_pad[nn_4][rc_4][((yy_4 * 2) + ry_4)][((xx_4 * 2) + rx_4)];	// L472
                  ap_fixed<10, 4> v547 = v26[ff_4][rc_4][ry_4][rx_4];	// L34
                  ap_fixed<20, 8> v548 = v546;	// L472
                  ap_fixed<20, 8> v549 = v547;	// L472
                  ap_fixed<20, 8> v550 = v548 * v549;	// L472
                  ap_fixed<10, 4> v551 = sum_4;	// L256
                  ap_fixed<21, 9> v552 = v550;	// L472
                  ap_fixed<21, 9> v553 = v551;	// L472
                  ap_fixed<21, 9> v554 = v552 + v553;	// L472
                  ap_fixed<10, 4> v555 = v554;	// L472
                  sum_4 = v555;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v556 = sum_4;	// L256
          conv3_x_0_conv1[nn_4][ff_4][yy_4][xx_4] = v556;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_bn1[2][128][16][16];	// L472
  l_conv3_x_0_bn1_i0_17: for (int i0_17 = 0; i0_17 < 2; i0_17++) {	// L472
    l_i1_17: for (int i1_17 = 0; i1_17 < 128; i1_17++) {	// L472
      l_i2_17: for (int i2_17 = 0; i2_17 < 16; i2_17++) {	// L472
        l_i3_17: for (int i3_17 = 0; i3_17 < 16; i3_17++) {	// L472
          ap_fixed<10, 4> v562 = conv3_x_0_conv1[i0_17][i1_17][i2_17][i3_17];	// L472
          ap_fixed<10, 4> v563 = v29[i1_17];	// L44
          ap_fixed<11, 5> v564 = v562;	// L472
          ap_fixed<11, 5> v565 = v563;	// L472
          ap_fixed<11, 5> v566 = v564 - v565;	// L472
          ap_fixed<10, 4> v567 = v30[i1_17];	// L44
          double v568 = v567;	// L472
          double v569 = v568 + 0.000000;	// L44
          double v570 = sqrt(v569);	// L41
          double v571 = v566;	// L472
          double v572 = v571 / v570;	// L472
          ap_fixed<10, 4> v573 = v27[i1_17];	// L44
          double v574 = v573;	// L472
          double v575 = v572 * v574;	// L472
          ap_fixed<10, 4> v576 = v28[i1_17];	// L44
          double v577 = v576;	// L472
          double v578 = v575 + v577;	// L472
          ap_fixed<10, 4> v579 = v578;	// L472
          conv3_x_0_bn1[i0_17][i1_17][i2_17][i3_17] = v579;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_relu1[2][128][16][16];	// L472
  l_conv3_x_0_relu1_i0_18: for (int i0_18 = 0; i0_18 < 2; i0_18++) {	// L472
    l_i1_18: for (int i1_18 = 0; i1_18 < 128; i1_18++) {	// L472
      l_i2_18: for (int i2_18 = 0; i2_18 < 16; i2_18++) {	// L472
        l_i3_18: for (int i3_18 = 0; i3_18 < 16; i3_18++) {	// L472
          ap_fixed<10, 4> v585 = conv3_x_0_bn1[i0_18][i1_18][i2_18][i3_18];	// L472
          ap_fixed<38, 32> v586 = v585;	// L472
          ap_fixed<38, 32> v587 = 0;	// L472
          bool v588 = v586 <= v587;	// L472
          ap_fixed<10, 4> v589 = conv3_x_0_bn1[i0_18][i1_18][i2_18][i3_18];	// L472
          ap_fixed<38, 32> v590 = 0;	// L472
          ap_fixed<38, 32> v591 = v589;	// L472
          ap_fixed<38, 32> v592 = v588 ? (ap_fixed<38, 32>)v590 : (ap_fixed<38, 32>)v591;	// L127
          ap_fixed<10, 4> v593 = v592;	// L472
          conv3_x_0_relu1[i0_18][i1_18][i2_18][i3_18] = v593;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_conv2_pad[2][128][18][18];	// L472
  l_conv3_x_0_conv2_pad_i0_19: for (int i0_19 = 0; i0_19 < 2; i0_19++) {	// L472
    l_i1_19: for (int i1_19 = 0; i1_19 < 128; i1_19++) {	// L472
      l_i2_19: for (int i2_19 = 0; i2_19 < 18; i2_19++) {	// L472
        l_i3_19: for (int i3_19 = 0; i3_19 < 18; i3_19++) {	// L472
          ap_int<33> v599 = i2_19;	// L472
          ap_int<33> v600 = 1;	// L472
          bool v601 = v599 >= v600;	// L472
          bool v602 = 1 & v601;	// L30
          ap_int<33> v603 = 17;	// L472
          bool v604 = v599 < v603;	// L472
          bool v605 = v602 & v604;	// L30
          ap_int<33> v606 = i3_19;	// L472
          bool v607 = v606 >= v600;	// L472
          bool v608 = v605 & v607;	// L30
          bool v609 = v606 < v603;	// L472
          bool v610 = v608 & v609;	// L30
          ap_fixed<10, 4> v611 = conv3_x_0_relu1[i0_19][i1_19][(i2_19 - 1)][(i3_19 - 1)];	// L472
          ap_fixed<10, 4> v612 = 0.000000;	// L472
          ap_fixed<10, 4> v613 = v610 ? (ap_fixed<10, 4>)v611 : (ap_fixed<10, 4>)v612;	// L127
          conv3_x_0_conv2_pad[i0_19][i1_19][i2_19][i3_19] = v613;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_conv2[2][128][16][16];	// L472
  l_conv3_x_0_conv2_nn_5: for (int nn_5 = 0; nn_5 < 2; nn_5++) {	// L472
    l_ff_5: for (int ff_5 = 0; ff_5 < 128; ff_5++) {	// L472
      l_yy_5: for (int yy_5 = 0; yy_5 < 16; yy_5++) {	// L472
        l_xx_5: for (int xx_5 = 0; xx_5 < 16; xx_5++) {	// L472
          ap_fixed<10, 4> sum_5;	// L256
          ap_fixed<10, 4> v620 = 0;	// L472
          sum_5 = v620;	// L472
          l_rc_5: for (int rc_5 = 0; rc_5 < 128; rc_5++) {	// L256
            l_ry_5: for (int ry_5 = 0; ry_5 < 3; ry_5++) {	// L256
              l_rx_5: for (int rx_5 = 0; rx_5 < 3; rx_5++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v624 = conv3_x_0_conv2_pad[nn_5][rc_5][(yy_5 + ry_5)][(xx_5 + rx_5)];	// L472
                  ap_fixed<10, 4> v625 = v31[ff_5][rc_5][ry_5][rx_5];	// L36
                  ap_fixed<20, 8> v626 = v624;	// L472
                  ap_fixed<20, 8> v627 = v625;	// L472
                  ap_fixed<20, 8> v628 = v626 * v627;	// L472
                  ap_fixed<10, 4> v629 = sum_5;	// L256
                  ap_fixed<21, 9> v630 = v628;	// L472
                  ap_fixed<21, 9> v631 = v629;	// L472
                  ap_fixed<21, 9> v632 = v630 + v631;	// L472
                  ap_fixed<10, 4> v633 = v632;	// L472
                  sum_5 = v633;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v634 = sum_5;	// L256
          conv3_x_0_conv2[nn_5][ff_5][yy_5][xx_5] = v634;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_bn2[2][128][16][16];	// L472
  l_conv3_x_0_bn2_i0_20: for (int i0_20 = 0; i0_20 < 2; i0_20++) {	// L472
    l_i1_20: for (int i1_20 = 0; i1_20 < 128; i1_20++) {	// L472
      l_i2_20: for (int i2_20 = 0; i2_20 < 16; i2_20++) {	// L472
        l_i3_20: for (int i3_20 = 0; i3_20 < 16; i3_20++) {	// L472
          ap_fixed<10, 4> v640 = conv3_x_0_conv2[i0_20][i1_20][i2_20][i3_20];	// L472
          ap_fixed<10, 4> v641 = v34[i1_20];	// L44
          ap_fixed<11, 5> v642 = v640;	// L472
          ap_fixed<11, 5> v643 = v641;	// L472
          ap_fixed<11, 5> v644 = v642 - v643;	// L472
          ap_fixed<10, 4> v645 = v35[i1_20];	// L44
          double v646 = v645;	// L472
          double v647 = v646 + 0.000000;	// L44
          double v648 = sqrt(v647);	// L41
          double v649 = v644;	// L472
          double v650 = v649 / v648;	// L472
          ap_fixed<10, 4> v651 = v32[i1_20];	// L44
          double v652 = v651;	// L472
          double v653 = v650 * v652;	// L472
          ap_fixed<10, 4> v654 = v33[i1_20];	// L44
          double v655 = v654;	// L472
          double v656 = v653 + v655;	// L472
          ap_fixed<10, 4> v657 = v656;	// L472
          conv3_x_0_bn2[i0_20][i1_20][i2_20][i3_20] = v657;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_convs[2][128][16][16];	// L472
  l_conv3_x_0_convs_nn_6: for (int nn_6 = 0; nn_6 < 2; nn_6++) {	// L472
    l_ff_6: for (int ff_6 = 0; ff_6 < 128; ff_6++) {	// L472
      l_yy_6: for (int yy_6 = 0; yy_6 < 16; yy_6++) {	// L472
        l_xx_6: for (int xx_6 = 0; xx_6 < 16; xx_6++) {	// L472
          ap_fixed<10, 4> sum_6;	// L256
          ap_fixed<10, 4> v664 = 0;	// L472
          sum_6 = v664;	// L472
          l_rc_6: for (int rc_6 = 0; rc_6 < 64; rc_6++) {	// L256
            if (1) {	// L472
              ap_fixed<10, 4> v666 = conv2_x_1_relu2[nn_6][rc_6][((yy_6 * 2) + 0)][((xx_6 * 2) + 0)];	// L472
              ap_fixed<10, 4> v667 = v36[ff_6][rc_6][0][0];	// L39
              ap_fixed<20, 8> v668 = v666;	// L472
              ap_fixed<20, 8> v669 = v667;	// L472
              ap_fixed<20, 8> v670 = v668 * v669;	// L472
              ap_fixed<10, 4> v671 = sum_6;	// L256
              ap_fixed<21, 9> v672 = v670;	// L472
              ap_fixed<21, 9> v673 = v671;	// L472
              ap_fixed<21, 9> v674 = v672 + v673;	// L472
              ap_fixed<10, 4> v675 = v674;	// L472
              sum_6 = v675;	// L472
            }
          }
          ap_fixed<10, 4> v676 = sum_6;	// L256
          conv3_x_0_convs[nn_6][ff_6][yy_6][xx_6] = v676;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_bns[2][128][16][16];	// L472
  l_conv3_x_0_bns_i0_21: for (int i0_21 = 0; i0_21 < 2; i0_21++) {	// L472
    l_i1_21: for (int i1_21 = 0; i1_21 < 128; i1_21++) {	// L472
      l_i2_21: for (int i2_21 = 0; i2_21 < 16; i2_21++) {	// L472
        l_i3_21: for (int i3_21 = 0; i3_21 < 16; i3_21++) {	// L472
          ap_fixed<10, 4> v682 = conv3_x_0_convs[i0_21][i1_21][i2_21][i3_21];	// L472
          ap_fixed<10, 4> v683 = v39[i1_21];	// L44
          ap_fixed<11, 5> v684 = v682;	// L472
          ap_fixed<11, 5> v685 = v683;	// L472
          ap_fixed<11, 5> v686 = v684 - v685;	// L472
          ap_fixed<10, 4> v687 = v40[i1_21];	// L44
          double v688 = v687;	// L472
          double v689 = v688 + 0.000000;	// L44
          double v690 = sqrt(v689);	// L41
          double v691 = v686;	// L472
          double v692 = v691 / v690;	// L472
          ap_fixed<10, 4> v693 = v37[i1_21];	// L44
          double v694 = v693;	// L472
          double v695 = v692 * v694;	// L472
          ap_fixed<10, 4> v696 = v38[i1_21];	// L44
          double v697 = v696;	// L472
          double v698 = v695 + v697;	// L472
          ap_fixed<10, 4> v699 = v698;	// L472
          conv3_x_0_bns[i0_21][i1_21][i2_21][i3_21] = v699;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_add[2][128][16][16];	// L472
  l_conv3_x_0_add_i0_22: for (int i0_22 = 0; i0_22 < 2; i0_22++) {	// L472
    l_i1_22: for (int i1_22 = 0; i1_22 < 128; i1_22++) {	// L472
      l_i2_22: for (int i2_22 = 0; i2_22 < 16; i2_22++) {	// L472
        l_i3_22: for (int i3_22 = 0; i3_22 < 16; i3_22++) {	// L472
          ap_fixed<10, 4> v705 = conv3_x_0_bn2[i0_22][i1_22][i2_22][i3_22];	// L472
          ap_fixed<10, 4> v706 = conv3_x_0_bns[i0_22][i1_22][i2_22][i3_22];	// L472
          ap_fixed<11, 5> v707 = v705;	// L472
          ap_fixed<11, 5> v708 = v706;	// L472
          ap_fixed<11, 5> v709 = v707 + v708;	// L472
          ap_fixed<10, 4> v710 = v709;	// L472
          conv3_x_0_add[i0_22][i1_22][i2_22][i3_22] = v710;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_0_relu2[2][128][16][16];	// L472
  l_conv3_x_0_relu2_i0_23: for (int i0_23 = 0; i0_23 < 2; i0_23++) {	// L472
    l_i1_23: for (int i1_23 = 0; i1_23 < 128; i1_23++) {	// L472
      l_i2_23: for (int i2_23 = 0; i2_23 < 16; i2_23++) {	// L472
        l_i3_23: for (int i3_23 = 0; i3_23 < 16; i3_23++) {	// L472
          ap_fixed<10, 4> v716 = conv3_x_0_add[i0_23][i1_23][i2_23][i3_23];	// L472
          ap_fixed<38, 32> v717 = v716;	// L472
          ap_fixed<38, 32> v718 = 0;	// L472
          bool v719 = v717 <= v718;	// L472
          ap_fixed<10, 4> v720 = conv3_x_0_add[i0_23][i1_23][i2_23][i3_23];	// L472
          ap_fixed<38, 32> v721 = 0;	// L472
          ap_fixed<38, 32> v722 = v720;	// L472
          ap_fixed<38, 32> v723 = v719 ? (ap_fixed<38, 32>)v721 : (ap_fixed<38, 32>)v722;	// L127
          ap_fixed<10, 4> v724 = v723;	// L472
          conv3_x_0_relu2[i0_23][i1_23][i2_23][i3_23] = v724;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_conv1_pad[2][128][18][18];	// L472
  l_conv3_x_1_conv1_pad_i0_24: for (int i0_24 = 0; i0_24 < 2; i0_24++) {	// L472
    l_i1_24: for (int i1_24 = 0; i1_24 < 128; i1_24++) {	// L472
      l_i2_24: for (int i2_24 = 0; i2_24 < 18; i2_24++) {	// L472
        l_i3_24: for (int i3_24 = 0; i3_24 < 18; i3_24++) {	// L472
          ap_int<33> v730 = i2_24;	// L472
          ap_int<33> v731 = 1;	// L472
          bool v732 = v730 >= v731;	// L472
          bool v733 = 1 & v732;	// L30
          ap_int<33> v734 = 17;	// L472
          bool v735 = v730 < v734;	// L472
          bool v736 = v733 & v735;	// L30
          ap_int<33> v737 = i3_24;	// L472
          bool v738 = v737 >= v731;	// L472
          bool v739 = v736 & v738;	// L30
          bool v740 = v737 < v734;	// L472
          bool v741 = v739 & v740;	// L30
          ap_fixed<10, 4> v742 = conv3_x_0_relu2[i0_24][i1_24][(i2_24 - 1)][(i3_24 - 1)];	// L472
          ap_fixed<10, 4> v743 = 0.000000;	// L472
          ap_fixed<10, 4> v744 = v741 ? (ap_fixed<10, 4>)v742 : (ap_fixed<10, 4>)v743;	// L127
          conv3_x_1_conv1_pad[i0_24][i1_24][i2_24][i3_24] = v744;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_conv1[2][128][16][16];	// L472
  l_conv3_x_1_conv1_nn_7: for (int nn_7 = 0; nn_7 < 2; nn_7++) {	// L472
    l_ff_7: for (int ff_7 = 0; ff_7 < 128; ff_7++) {	// L472
      l_yy_7: for (int yy_7 = 0; yy_7 < 16; yy_7++) {	// L472
        l_xx_7: for (int xx_7 = 0; xx_7 < 16; xx_7++) {	// L472
          ap_fixed<10, 4> sum_7;	// L256
          ap_fixed<10, 4> v751 = 0;	// L472
          sum_7 = v751;	// L472
          l_rc_7: for (int rc_7 = 0; rc_7 < 128; rc_7++) {	// L256
            l_ry_7: for (int ry_7 = 0; ry_7 < 3; ry_7++) {	// L256
              l_rx_7: for (int rx_7 = 0; rx_7 < 3; rx_7++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v755 = conv3_x_1_conv1_pad[nn_7][rc_7][(yy_7 + ry_7)][(xx_7 + rx_7)];	// L472
                  ap_fixed<10, 4> v756 = v41[ff_7][rc_7][ry_7][rx_7];	// L34
                  ap_fixed<20, 8> v757 = v755;	// L472
                  ap_fixed<20, 8> v758 = v756;	// L472
                  ap_fixed<20, 8> v759 = v757 * v758;	// L472
                  ap_fixed<10, 4> v760 = sum_7;	// L256
                  ap_fixed<21, 9> v761 = v759;	// L472
                  ap_fixed<21, 9> v762 = v760;	// L472
                  ap_fixed<21, 9> v763 = v761 + v762;	// L472
                  ap_fixed<10, 4> v764 = v763;	// L472
                  sum_7 = v764;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v765 = sum_7;	// L256
          conv3_x_1_conv1[nn_7][ff_7][yy_7][xx_7] = v765;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_bn1[2][128][16][16];	// L472
  l_conv3_x_1_bn1_i0_25: for (int i0_25 = 0; i0_25 < 2; i0_25++) {	// L472
    l_i1_25: for (int i1_25 = 0; i1_25 < 128; i1_25++) {	// L472
      l_i2_25: for (int i2_25 = 0; i2_25 < 16; i2_25++) {	// L472
        l_i3_25: for (int i3_25 = 0; i3_25 < 16; i3_25++) {	// L472
          ap_fixed<10, 4> v771 = conv3_x_1_conv1[i0_25][i1_25][i2_25][i3_25];	// L472
          ap_fixed<10, 4> v772 = v44[i1_25];	// L52
          ap_fixed<11, 5> v773 = v771;	// L472
          ap_fixed<11, 5> v774 = v772;	// L472
          ap_fixed<11, 5> v775 = v773 - v774;	// L472
          ap_fixed<10, 4> v776 = v45[i1_25];	// L52
          double v777 = v776;	// L472
          double v778 = v777 + 0.000000;	// L52
          double v779 = sqrt(v778);	// L41
          double v780 = v775;	// L472
          double v781 = v780 / v779;	// L472
          ap_fixed<10, 4> v782 = v42[i1_25];	// L52
          double v783 = v782;	// L472
          double v784 = v781 * v783;	// L472
          ap_fixed<10, 4> v785 = v43[i1_25];	// L52
          double v786 = v785;	// L472
          double v787 = v784 + v786;	// L472
          ap_fixed<10, 4> v788 = v787;	// L472
          conv3_x_1_bn1[i0_25][i1_25][i2_25][i3_25] = v788;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_relu1[2][128][16][16];	// L472
  l_conv3_x_1_relu1_i0_26: for (int i0_26 = 0; i0_26 < 2; i0_26++) {	// L472
    l_i1_26: for (int i1_26 = 0; i1_26 < 128; i1_26++) {	// L472
      l_i2_26: for (int i2_26 = 0; i2_26 < 16; i2_26++) {	// L472
        l_i3_26: for (int i3_26 = 0; i3_26 < 16; i3_26++) {	// L472
          ap_fixed<10, 4> v794 = conv3_x_1_bn1[i0_26][i1_26][i2_26][i3_26];	// L472
          ap_fixed<38, 32> v795 = v794;	// L472
          ap_fixed<38, 32> v796 = 0;	// L472
          bool v797 = v795 <= v796;	// L472
          ap_fixed<10, 4> v798 = conv3_x_1_bn1[i0_26][i1_26][i2_26][i3_26];	// L472
          ap_fixed<38, 32> v799 = 0;	// L472
          ap_fixed<38, 32> v800 = v798;	// L472
          ap_fixed<38, 32> v801 = v797 ? (ap_fixed<38, 32>)v799 : (ap_fixed<38, 32>)v800;	// L127
          ap_fixed<10, 4> v802 = v801;	// L472
          conv3_x_1_relu1[i0_26][i1_26][i2_26][i3_26] = v802;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_conv2_pad[2][128][18][18];	// L472
  l_conv3_x_1_conv2_pad_i0_27: for (int i0_27 = 0; i0_27 < 2; i0_27++) {	// L472
    l_i1_27: for (int i1_27 = 0; i1_27 < 128; i1_27++) {	// L472
      l_i2_27: for (int i2_27 = 0; i2_27 < 18; i2_27++) {	// L472
        l_i3_27: for (int i3_27 = 0; i3_27 < 18; i3_27++) {	// L472
          ap_int<33> v808 = i2_27;	// L472
          ap_int<33> v809 = 1;	// L472
          bool v810 = v808 >= v809;	// L472
          bool v811 = 1 & v810;	// L30
          ap_int<33> v812 = 17;	// L472
          bool v813 = v808 < v812;	// L472
          bool v814 = v811 & v813;	// L30
          ap_int<33> v815 = i3_27;	// L472
          bool v816 = v815 >= v809;	// L472
          bool v817 = v814 & v816;	// L30
          bool v818 = v815 < v812;	// L472
          bool v819 = v817 & v818;	// L30
          ap_fixed<10, 4> v820 = conv3_x_1_relu1[i0_27][i1_27][(i2_27 - 1)][(i3_27 - 1)];	// L472
          ap_fixed<10, 4> v821 = 0.000000;	// L472
          ap_fixed<10, 4> v822 = v819 ? (ap_fixed<10, 4>)v820 : (ap_fixed<10, 4>)v821;	// L127
          conv3_x_1_conv2_pad[i0_27][i1_27][i2_27][i3_27] = v822;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_conv2[2][128][16][16];	// L472
  l_conv3_x_1_conv2_nn_8: for (int nn_8 = 0; nn_8 < 2; nn_8++) {	// L472
    l_ff_8: for (int ff_8 = 0; ff_8 < 128; ff_8++) {	// L472
      l_yy_8: for (int yy_8 = 0; yy_8 < 16; yy_8++) {	// L472
        l_xx_8: for (int xx_8 = 0; xx_8 < 16; xx_8++) {	// L472
          ap_fixed<10, 4> sum_8;	// L256
          ap_fixed<10, 4> v829 = 0;	// L472
          sum_8 = v829;	// L472
          l_rc_8: for (int rc_8 = 0; rc_8 < 128; rc_8++) {	// L256
            l_ry_8: for (int ry_8 = 0; ry_8 < 3; ry_8++) {	// L256
              l_rx_8: for (int rx_8 = 0; rx_8 < 3; rx_8++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v833 = conv3_x_1_conv2_pad[nn_8][rc_8][(yy_8 + ry_8)][(xx_8 + rx_8)];	// L472
                  ap_fixed<10, 4> v834 = v46[ff_8][rc_8][ry_8][rx_8];	// L36
                  ap_fixed<20, 8> v835 = v833;	// L472
                  ap_fixed<20, 8> v836 = v834;	// L472
                  ap_fixed<20, 8> v837 = v835 * v836;	// L472
                  ap_fixed<10, 4> v838 = sum_8;	// L256
                  ap_fixed<21, 9> v839 = v837;	// L472
                  ap_fixed<21, 9> v840 = v838;	// L472
                  ap_fixed<21, 9> v841 = v839 + v840;	// L472
                  ap_fixed<10, 4> v842 = v841;	// L472
                  sum_8 = v842;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v843 = sum_8;	// L256
          conv3_x_1_conv2[nn_8][ff_8][yy_8][xx_8] = v843;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_bn2[2][128][16][16];	// L472
  l_conv3_x_1_bn2_i0_28: for (int i0_28 = 0; i0_28 < 2; i0_28++) {	// L472
    l_i1_28: for (int i1_28 = 0; i1_28 < 128; i1_28++) {	// L472
      l_i2_28: for (int i2_28 = 0; i2_28 < 16; i2_28++) {	// L472
        l_i3_28: for (int i3_28 = 0; i3_28 < 16; i3_28++) {	// L472
          ap_fixed<10, 4> v849 = conv3_x_1_conv2[i0_28][i1_28][i2_28][i3_28];	// L472
          ap_fixed<10, 4> v850 = v49[i1_28];	// L52
          ap_fixed<11, 5> v851 = v849;	// L472
          ap_fixed<11, 5> v852 = v850;	// L472
          ap_fixed<11, 5> v853 = v851 - v852;	// L472
          ap_fixed<10, 4> v854 = v50[i1_28];	// L52
          double v855 = v854;	// L472
          double v856 = v855 + 0.000000;	// L52
          double v857 = sqrt(v856);	// L41
          double v858 = v853;	// L472
          double v859 = v858 / v857;	// L472
          ap_fixed<10, 4> v860 = v47[i1_28];	// L52
          double v861 = v860;	// L472
          double v862 = v859 * v861;	// L472
          ap_fixed<10, 4> v863 = v48[i1_28];	// L52
          double v864 = v863;	// L472
          double v865 = v862 + v864;	// L472
          ap_fixed<10, 4> v866 = v865;	// L472
          conv3_x_1_bn2[i0_28][i1_28][i2_28][i3_28] = v866;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_add[2][128][16][16];	// L472
  l_conv3_x_1_add_i0_29: for (int i0_29 = 0; i0_29 < 2; i0_29++) {	// L472
    l_i1_29: for (int i1_29 = 0; i1_29 < 128; i1_29++) {	// L472
      l_i2_29: for (int i2_29 = 0; i2_29 < 16; i2_29++) {	// L472
        l_i3_29: for (int i3_29 = 0; i3_29 < 16; i3_29++) {	// L472
          ap_fixed<10, 4> v872 = conv3_x_1_bn2[i0_29][i1_29][i2_29][i3_29];	// L472
          ap_fixed<10, 4> v873 = conv3_x_0_relu2[i0_29][i1_29][i2_29][i3_29];	// L472
          ap_fixed<11, 5> v874 = v872;	// L472
          ap_fixed<11, 5> v875 = v873;	// L472
          ap_fixed<11, 5> v876 = v874 + v875;	// L472
          ap_fixed<10, 4> v877 = v876;	// L472
          conv3_x_1_add[i0_29][i1_29][i2_29][i3_29] = v877;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv3_x_1_relu2[2][128][16][16];	// L472
  l_conv3_x_1_relu2_i0_30: for (int i0_30 = 0; i0_30 < 2; i0_30++) {	// L472
    l_i1_30: for (int i1_30 = 0; i1_30 < 128; i1_30++) {	// L472
      l_i2_30: for (int i2_30 = 0; i2_30 < 16; i2_30++) {	// L472
        l_i3_30: for (int i3_30 = 0; i3_30 < 16; i3_30++) {	// L472
          ap_fixed<10, 4> v883 = conv3_x_1_add[i0_30][i1_30][i2_30][i3_30];	// L472
          ap_fixed<38, 32> v884 = v883;	// L472
          ap_fixed<38, 32> v885 = 0;	// L472
          bool v886 = v884 <= v885;	// L472
          ap_fixed<10, 4> v887 = conv3_x_1_add[i0_30][i1_30][i2_30][i3_30];	// L472
          ap_fixed<38, 32> v888 = 0;	// L472
          ap_fixed<38, 32> v889 = v887;	// L472
          ap_fixed<38, 32> v890 = v886 ? (ap_fixed<38, 32>)v888 : (ap_fixed<38, 32>)v889;	// L127
          ap_fixed<10, 4> v891 = v890;	// L472
          conv3_x_1_relu2[i0_30][i1_30][i2_30][i3_30] = v891;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_conv1_pad[2][128][18][18];	// L472
  l_conv4_x_0_conv1_pad_i0_31: for (int i0_31 = 0; i0_31 < 2; i0_31++) {	// L472
    l_i1_31: for (int i1_31 = 0; i1_31 < 128; i1_31++) {	// L472
      l_i2_31: for (int i2_31 = 0; i2_31 < 18; i2_31++) {	// L472
        l_i3_31: for (int i3_31 = 0; i3_31 < 18; i3_31++) {	// L472
          ap_int<33> v897 = i2_31;	// L472
          ap_int<33> v898 = 1;	// L472
          bool v899 = v897 >= v898;	// L472
          bool v900 = 1 & v899;	// L30
          ap_int<33> v901 = 17;	// L472
          bool v902 = v897 < v901;	// L472
          bool v903 = v900 & v902;	// L30
          ap_int<33> v904 = i3_31;	// L472
          bool v905 = v904 >= v898;	// L472
          bool v906 = v903 & v905;	// L30
          bool v907 = v904 < v901;	// L472
          bool v908 = v906 & v907;	// L30
          ap_fixed<10, 4> v909 = conv3_x_1_relu2[i0_31][i1_31][(i2_31 - 1)][(i3_31 - 1)];	// L472
          ap_fixed<10, 4> v910 = 0.000000;	// L472
          ap_fixed<10, 4> v911 = v908 ? (ap_fixed<10, 4>)v909 : (ap_fixed<10, 4>)v910;	// L127
          conv4_x_0_conv1_pad[i0_31][i1_31][i2_31][i3_31] = v911;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_conv1[2][256][8][8];	// L472
  l_conv4_x_0_conv1_nn_9: for (int nn_9 = 0; nn_9 < 2; nn_9++) {	// L472
    l_ff_9: for (int ff_9 = 0; ff_9 < 256; ff_9++) {	// L472
      l_yy_9: for (int yy_9 = 0; yy_9 < 8; yy_9++) {	// L472
        l_xx_9: for (int xx_9 = 0; xx_9 < 8; xx_9++) {	// L472
          ap_fixed<10, 4> sum_9;	// L256
          ap_fixed<10, 4> v918 = 0;	// L472
          sum_9 = v918;	// L472
          l_rc_9: for (int rc_9 = 0; rc_9 < 128; rc_9++) {	// L256
            l_ry_9: for (int ry_9 = 0; ry_9 < 3; ry_9++) {	// L256
              l_rx_9: for (int rx_9 = 0; rx_9 < 3; rx_9++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v922 = conv4_x_0_conv1_pad[nn_9][rc_9][((yy_9 * 2) + ry_9)][((xx_9 * 2) + rx_9)];	// L472
                  ap_fixed<10, 4> v923 = v51[ff_9][rc_9][ry_9][rx_9];	// L34
                  ap_fixed<20, 8> v924 = v922;	// L472
                  ap_fixed<20, 8> v925 = v923;	// L472
                  ap_fixed<20, 8> v926 = v924 * v925;	// L472
                  ap_fixed<10, 4> v927 = sum_9;	// L256
                  ap_fixed<21, 9> v928 = v926;	// L472
                  ap_fixed<21, 9> v929 = v927;	// L472
                  ap_fixed<21, 9> v930 = v928 + v929;	// L472
                  ap_fixed<10, 4> v931 = v930;	// L472
                  sum_9 = v931;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v932 = sum_9;	// L256
          conv4_x_0_conv1[nn_9][ff_9][yy_9][xx_9] = v932;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_bn1[2][256][8][8];	// L472
  l_conv4_x_0_bn1_i0_32: for (int i0_32 = 0; i0_32 < 2; i0_32++) {	// L472
    l_i1_32: for (int i1_32 = 0; i1_32 < 256; i1_32++) {	// L472
      l_i2_32: for (int i2_32 = 0; i2_32 < 8; i2_32++) {	// L472
        l_i3_32: for (int i3_32 = 0; i3_32 < 8; i3_32++) {	// L472
          ap_fixed<10, 4> v938 = conv4_x_0_conv1[i0_32][i1_32][i2_32][i3_32];	// L472
          ap_fixed<10, 4> v939 = v54[i1_32];	// L44
          ap_fixed<11, 5> v940 = v938;	// L472
          ap_fixed<11, 5> v941 = v939;	// L472
          ap_fixed<11, 5> v942 = v940 - v941;	// L472
          ap_fixed<10, 4> v943 = v55[i1_32];	// L44
          double v944 = v943;	// L472
          double v945 = v944 + 0.000000;	// L44
          double v946 = sqrt(v945);	// L41
          double v947 = v942;	// L472
          double v948 = v947 / v946;	// L472
          ap_fixed<10, 4> v949 = v52[i1_32];	// L44
          double v950 = v949;	// L472
          double v951 = v948 * v950;	// L472
          ap_fixed<10, 4> v952 = v53[i1_32];	// L44
          double v953 = v952;	// L472
          double v954 = v951 + v953;	// L472
          ap_fixed<10, 4> v955 = v954;	// L472
          conv4_x_0_bn1[i0_32][i1_32][i2_32][i3_32] = v955;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_relu1[2][256][8][8];	// L472
  l_conv4_x_0_relu1_i0_33: for (int i0_33 = 0; i0_33 < 2; i0_33++) {	// L472
    l_i1_33: for (int i1_33 = 0; i1_33 < 256; i1_33++) {	// L472
      l_i2_33: for (int i2_33 = 0; i2_33 < 8; i2_33++) {	// L472
        l_i3_33: for (int i3_33 = 0; i3_33 < 8; i3_33++) {	// L472
          ap_fixed<10, 4> v961 = conv4_x_0_bn1[i0_33][i1_33][i2_33][i3_33];	// L472
          ap_fixed<38, 32> v962 = v961;	// L472
          ap_fixed<38, 32> v963 = 0;	// L472
          bool v964 = v962 <= v963;	// L472
          ap_fixed<10, 4> v965 = conv4_x_0_bn1[i0_33][i1_33][i2_33][i3_33];	// L472
          ap_fixed<38, 32> v966 = 0;	// L472
          ap_fixed<38, 32> v967 = v965;	// L472
          ap_fixed<38, 32> v968 = v964 ? (ap_fixed<38, 32>)v966 : (ap_fixed<38, 32>)v967;	// L127
          ap_fixed<10, 4> v969 = v968;	// L472
          conv4_x_0_relu1[i0_33][i1_33][i2_33][i3_33] = v969;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_conv2_pad[2][256][10][10];	// L472
  l_conv4_x_0_conv2_pad_i0_34: for (int i0_34 = 0; i0_34 < 2; i0_34++) {	// L472
    l_i1_34: for (int i1_34 = 0; i1_34 < 256; i1_34++) {	// L472
      l_i2_34: for (int i2_34 = 0; i2_34 < 10; i2_34++) {	// L472
        l_i3_34: for (int i3_34 = 0; i3_34 < 10; i3_34++) {	// L472
          ap_int<33> v975 = i2_34;	// L472
          ap_int<33> v976 = 1;	// L472
          bool v977 = v975 >= v976;	// L472
          bool v978 = 1 & v977;	// L30
          ap_int<33> v979 = 9;	// L472
          bool v980 = v975 < v979;	// L472
          bool v981 = v978 & v980;	// L30
          ap_int<33> v982 = i3_34;	// L472
          bool v983 = v982 >= v976;	// L472
          bool v984 = v981 & v983;	// L30
          bool v985 = v982 < v979;	// L472
          bool v986 = v984 & v985;	// L30
          ap_fixed<10, 4> v987 = conv4_x_0_relu1[i0_34][i1_34][(i2_34 - 1)][(i3_34 - 1)];	// L472
          ap_fixed<10, 4> v988 = 0.000000;	// L472
          ap_fixed<10, 4> v989 = v986 ? (ap_fixed<10, 4>)v987 : (ap_fixed<10, 4>)v988;	// L127
          conv4_x_0_conv2_pad[i0_34][i1_34][i2_34][i3_34] = v989;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_conv2[2][256][8][8];	// L472
  l_conv4_x_0_conv2_nn_10: for (int nn_10 = 0; nn_10 < 2; nn_10++) {	// L472
    l_ff_10: for (int ff_10 = 0; ff_10 < 256; ff_10++) {	// L472
      l_yy_10: for (int yy_10 = 0; yy_10 < 8; yy_10++) {	// L472
        l_xx_10: for (int xx_10 = 0; xx_10 < 8; xx_10++) {	// L472
          ap_fixed<10, 4> sum_10;	// L256
          ap_fixed<10, 4> v996 = 0;	// L472
          sum_10 = v996;	// L472
          l_rc_10: for (int rc_10 = 0; rc_10 < 256; rc_10++) {	// L256
            l_ry_10: for (int ry_10 = 0; ry_10 < 3; ry_10++) {	// L256
              l_rx_10: for (int rx_10 = 0; rx_10 < 3; rx_10++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v1000 = conv4_x_0_conv2_pad[nn_10][rc_10][(yy_10 + ry_10)][(xx_10 + rx_10)];	// L472
                  ap_fixed<10, 4> v1001 = v56[ff_10][rc_10][ry_10][rx_10];	// L36
                  ap_fixed<20, 8> v1002 = v1000;	// L472
                  ap_fixed<20, 8> v1003 = v1001;	// L472
                  ap_fixed<20, 8> v1004 = v1002 * v1003;	// L472
                  ap_fixed<10, 4> v1005 = sum_10;	// L256
                  ap_fixed<21, 9> v1006 = v1004;	// L472
                  ap_fixed<21, 9> v1007 = v1005;	// L472
                  ap_fixed<21, 9> v1008 = v1006 + v1007;	// L472
                  ap_fixed<10, 4> v1009 = v1008;	// L472
                  sum_10 = v1009;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v1010 = sum_10;	// L256
          conv4_x_0_conv2[nn_10][ff_10][yy_10][xx_10] = v1010;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_bn2[2][256][8][8];	// L472
  l_conv4_x_0_bn2_i0_35: for (int i0_35 = 0; i0_35 < 2; i0_35++) {	// L472
    l_i1_35: for (int i1_35 = 0; i1_35 < 256; i1_35++) {	// L472
      l_i2_35: for (int i2_35 = 0; i2_35 < 8; i2_35++) {	// L472
        l_i3_35: for (int i3_35 = 0; i3_35 < 8; i3_35++) {	// L472
          ap_fixed<10, 4> v1016 = conv4_x_0_conv2[i0_35][i1_35][i2_35][i3_35];	// L472
          ap_fixed<10, 4> v1017 = v59[i1_35];	// L44
          ap_fixed<11, 5> v1018 = v1016;	// L472
          ap_fixed<11, 5> v1019 = v1017;	// L472
          ap_fixed<11, 5> v1020 = v1018 - v1019;	// L472
          ap_fixed<10, 4> v1021 = v60[i1_35];	// L44
          double v1022 = v1021;	// L472
          double v1023 = v1022 + 0.000000;	// L44
          double v1024 = sqrt(v1023);	// L41
          double v1025 = v1020;	// L472
          double v1026 = v1025 / v1024;	// L472
          ap_fixed<10, 4> v1027 = v57[i1_35];	// L44
          double v1028 = v1027;	// L472
          double v1029 = v1026 * v1028;	// L472
          ap_fixed<10, 4> v1030 = v58[i1_35];	// L44
          double v1031 = v1030;	// L472
          double v1032 = v1029 + v1031;	// L472
          ap_fixed<10, 4> v1033 = v1032;	// L472
          conv4_x_0_bn2[i0_35][i1_35][i2_35][i3_35] = v1033;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_convs[2][256][8][8];	// L472
  l_conv4_x_0_convs_nn_11: for (int nn_11 = 0; nn_11 < 2; nn_11++) {	// L472
    l_ff_11: for (int ff_11 = 0; ff_11 < 256; ff_11++) {	// L472
      l_yy_11: for (int yy_11 = 0; yy_11 < 8; yy_11++) {	// L472
        l_xx_11: for (int xx_11 = 0; xx_11 < 8; xx_11++) {	// L472
          ap_fixed<10, 4> sum_11;	// L256
          ap_fixed<10, 4> v1040 = 0;	// L472
          sum_11 = v1040;	// L472
          l_rc_11: for (int rc_11 = 0; rc_11 < 128; rc_11++) {	// L256
            if (1) {	// L472
              ap_fixed<10, 4> v1042 = conv3_x_1_relu2[nn_11][rc_11][((yy_11 * 2) + 0)][((xx_11 * 2) + 0)];	// L472
              ap_fixed<10, 4> v1043 = v61[ff_11][rc_11][0][0];	// L39
              ap_fixed<20, 8> v1044 = v1042;	// L472
              ap_fixed<20, 8> v1045 = v1043;	// L472
              ap_fixed<20, 8> v1046 = v1044 * v1045;	// L472
              ap_fixed<10, 4> v1047 = sum_11;	// L256
              ap_fixed<21, 9> v1048 = v1046;	// L472
              ap_fixed<21, 9> v1049 = v1047;	// L472
              ap_fixed<21, 9> v1050 = v1048 + v1049;	// L472
              ap_fixed<10, 4> v1051 = v1050;	// L472
              sum_11 = v1051;	// L472
            }
          }
          ap_fixed<10, 4> v1052 = sum_11;	// L256
          conv4_x_0_convs[nn_11][ff_11][yy_11][xx_11] = v1052;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_bns[2][256][8][8];	// L472
  l_conv4_x_0_bns_i0_36: for (int i0_36 = 0; i0_36 < 2; i0_36++) {	// L472
    l_i1_36: for (int i1_36 = 0; i1_36 < 256; i1_36++) {	// L472
      l_i2_36: for (int i2_36 = 0; i2_36 < 8; i2_36++) {	// L472
        l_i3_36: for (int i3_36 = 0; i3_36 < 8; i3_36++) {	// L472
          ap_fixed<10, 4> v1058 = conv4_x_0_convs[i0_36][i1_36][i2_36][i3_36];	// L472
          ap_fixed<10, 4> v1059 = v64[i1_36];	// L44
          ap_fixed<11, 5> v1060 = v1058;	// L472
          ap_fixed<11, 5> v1061 = v1059;	// L472
          ap_fixed<11, 5> v1062 = v1060 - v1061;	// L472
          ap_fixed<10, 4> v1063 = v65[i1_36];	// L44
          double v1064 = v1063;	// L472
          double v1065 = v1064 + 0.000000;	// L44
          double v1066 = sqrt(v1065);	// L41
          double v1067 = v1062;	// L472
          double v1068 = v1067 / v1066;	// L472
          ap_fixed<10, 4> v1069 = v62[i1_36];	// L44
          double v1070 = v1069;	// L472
          double v1071 = v1068 * v1070;	// L472
          ap_fixed<10, 4> v1072 = v63[i1_36];	// L44
          double v1073 = v1072;	// L472
          double v1074 = v1071 + v1073;	// L472
          ap_fixed<10, 4> v1075 = v1074;	// L472
          conv4_x_0_bns[i0_36][i1_36][i2_36][i3_36] = v1075;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_add[2][256][8][8];	// L472
  l_conv4_x_0_add_i0_37: for (int i0_37 = 0; i0_37 < 2; i0_37++) {	// L472
    l_i1_37: for (int i1_37 = 0; i1_37 < 256; i1_37++) {	// L472
      l_i2_37: for (int i2_37 = 0; i2_37 < 8; i2_37++) {	// L472
        l_i3_37: for (int i3_37 = 0; i3_37 < 8; i3_37++) {	// L472
          ap_fixed<10, 4> v1081 = conv4_x_0_bn2[i0_37][i1_37][i2_37][i3_37];	// L472
          ap_fixed<10, 4> v1082 = conv4_x_0_bns[i0_37][i1_37][i2_37][i3_37];	// L472
          ap_fixed<11, 5> v1083 = v1081;	// L472
          ap_fixed<11, 5> v1084 = v1082;	// L472
          ap_fixed<11, 5> v1085 = v1083 + v1084;	// L472
          ap_fixed<10, 4> v1086 = v1085;	// L472
          conv4_x_0_add[i0_37][i1_37][i2_37][i3_37] = v1086;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_0_relu2[2][256][8][8];	// L472
  l_conv4_x_0_relu2_i0_38: for (int i0_38 = 0; i0_38 < 2; i0_38++) {	// L472
    l_i1_38: for (int i1_38 = 0; i1_38 < 256; i1_38++) {	// L472
      l_i2_38: for (int i2_38 = 0; i2_38 < 8; i2_38++) {	// L472
        l_i3_38: for (int i3_38 = 0; i3_38 < 8; i3_38++) {	// L472
          ap_fixed<10, 4> v1092 = conv4_x_0_add[i0_38][i1_38][i2_38][i3_38];	// L472
          ap_fixed<38, 32> v1093 = v1092;	// L472
          ap_fixed<38, 32> v1094 = 0;	// L472
          bool v1095 = v1093 <= v1094;	// L472
          ap_fixed<10, 4> v1096 = conv4_x_0_add[i0_38][i1_38][i2_38][i3_38];	// L472
          ap_fixed<38, 32> v1097 = 0;	// L472
          ap_fixed<38, 32> v1098 = v1096;	// L472
          ap_fixed<38, 32> v1099 = v1095 ? (ap_fixed<38, 32>)v1097 : (ap_fixed<38, 32>)v1098;	// L127
          ap_fixed<10, 4> v1100 = v1099;	// L472
          conv4_x_0_relu2[i0_38][i1_38][i2_38][i3_38] = v1100;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_conv1_pad[2][256][10][10];	// L472
  l_conv4_x_1_conv1_pad_i0_39: for (int i0_39 = 0; i0_39 < 2; i0_39++) {	// L472
    l_i1_39: for (int i1_39 = 0; i1_39 < 256; i1_39++) {	// L472
      l_i2_39: for (int i2_39 = 0; i2_39 < 10; i2_39++) {	// L472
        l_i3_39: for (int i3_39 = 0; i3_39 < 10; i3_39++) {	// L472
          ap_int<33> v1106 = i2_39;	// L472
          ap_int<33> v1107 = 1;	// L472
          bool v1108 = v1106 >= v1107;	// L472
          bool v1109 = 1 & v1108;	// L30
          ap_int<33> v1110 = 9;	// L472
          bool v1111 = v1106 < v1110;	// L472
          bool v1112 = v1109 & v1111;	// L30
          ap_int<33> v1113 = i3_39;	// L472
          bool v1114 = v1113 >= v1107;	// L472
          bool v1115 = v1112 & v1114;	// L30
          bool v1116 = v1113 < v1110;	// L472
          bool v1117 = v1115 & v1116;	// L30
          ap_fixed<10, 4> v1118 = conv4_x_0_relu2[i0_39][i1_39][(i2_39 - 1)][(i3_39 - 1)];	// L472
          ap_fixed<10, 4> v1119 = 0.000000;	// L472
          ap_fixed<10, 4> v1120 = v1117 ? (ap_fixed<10, 4>)v1118 : (ap_fixed<10, 4>)v1119;	// L127
          conv4_x_1_conv1_pad[i0_39][i1_39][i2_39][i3_39] = v1120;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_conv1[2][256][8][8];	// L472
  l_conv4_x_1_conv1_nn_12: for (int nn_12 = 0; nn_12 < 2; nn_12++) {	// L472
    l_ff_12: for (int ff_12 = 0; ff_12 < 256; ff_12++) {	// L472
      l_yy_12: for (int yy_12 = 0; yy_12 < 8; yy_12++) {	// L472
        l_xx_12: for (int xx_12 = 0; xx_12 < 8; xx_12++) {	// L472
          ap_fixed<10, 4> sum_12;	// L256
          ap_fixed<10, 4> v1127 = 0;	// L472
          sum_12 = v1127;	// L472
          l_rc_12: for (int rc_12 = 0; rc_12 < 256; rc_12++) {	// L256
            l_ry_12: for (int ry_12 = 0; ry_12 < 3; ry_12++) {	// L256
              l_rx_12: for (int rx_12 = 0; rx_12 < 3; rx_12++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v1131 = conv4_x_1_conv1_pad[nn_12][rc_12][(yy_12 + ry_12)][(xx_12 + rx_12)];	// L472
                  ap_fixed<10, 4> v1132 = v66[ff_12][rc_12][ry_12][rx_12];	// L34
                  ap_fixed<20, 8> v1133 = v1131;	// L472
                  ap_fixed<20, 8> v1134 = v1132;	// L472
                  ap_fixed<20, 8> v1135 = v1133 * v1134;	// L472
                  ap_fixed<10, 4> v1136 = sum_12;	// L256
                  ap_fixed<21, 9> v1137 = v1135;	// L472
                  ap_fixed<21, 9> v1138 = v1136;	// L472
                  ap_fixed<21, 9> v1139 = v1137 + v1138;	// L472
                  ap_fixed<10, 4> v1140 = v1139;	// L472
                  sum_12 = v1140;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v1141 = sum_12;	// L256
          conv4_x_1_conv1[nn_12][ff_12][yy_12][xx_12] = v1141;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_bn1[2][256][8][8];	// L472
  l_conv4_x_1_bn1_i0_40: for (int i0_40 = 0; i0_40 < 2; i0_40++) {	// L472
    l_i1_40: for (int i1_40 = 0; i1_40 < 256; i1_40++) {	// L472
      l_i2_40: for (int i2_40 = 0; i2_40 < 8; i2_40++) {	// L472
        l_i3_40: for (int i3_40 = 0; i3_40 < 8; i3_40++) {	// L472
          ap_fixed<10, 4> v1147 = conv4_x_1_conv1[i0_40][i1_40][i2_40][i3_40];	// L472
          ap_fixed<10, 4> v1148 = v69[i1_40];	// L52
          ap_fixed<11, 5> v1149 = v1147;	// L472
          ap_fixed<11, 5> v1150 = v1148;	// L472
          ap_fixed<11, 5> v1151 = v1149 - v1150;	// L472
          ap_fixed<10, 4> v1152 = v70[i1_40];	// L52
          double v1153 = v1152;	// L472
          double v1154 = v1153 + 0.000000;	// L52
          double v1155 = sqrt(v1154);	// L41
          double v1156 = v1151;	// L472
          double v1157 = v1156 / v1155;	// L472
          ap_fixed<10, 4> v1158 = v67[i1_40];	// L52
          double v1159 = v1158;	// L472
          double v1160 = v1157 * v1159;	// L472
          ap_fixed<10, 4> v1161 = v68[i1_40];	// L52
          double v1162 = v1161;	// L472
          double v1163 = v1160 + v1162;	// L472
          ap_fixed<10, 4> v1164 = v1163;	// L472
          conv4_x_1_bn1[i0_40][i1_40][i2_40][i3_40] = v1164;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_relu1[2][256][8][8];	// L472
  l_conv4_x_1_relu1_i0_41: for (int i0_41 = 0; i0_41 < 2; i0_41++) {	// L472
    l_i1_41: for (int i1_41 = 0; i1_41 < 256; i1_41++) {	// L472
      l_i2_41: for (int i2_41 = 0; i2_41 < 8; i2_41++) {	// L472
        l_i3_41: for (int i3_41 = 0; i3_41 < 8; i3_41++) {	// L472
          ap_fixed<10, 4> v1170 = conv4_x_1_bn1[i0_41][i1_41][i2_41][i3_41];	// L472
          ap_fixed<38, 32> v1171 = v1170;	// L472
          ap_fixed<38, 32> v1172 = 0;	// L472
          bool v1173 = v1171 <= v1172;	// L472
          ap_fixed<10, 4> v1174 = conv4_x_1_bn1[i0_41][i1_41][i2_41][i3_41];	// L472
          ap_fixed<38, 32> v1175 = 0;	// L472
          ap_fixed<38, 32> v1176 = v1174;	// L472
          ap_fixed<38, 32> v1177 = v1173 ? (ap_fixed<38, 32>)v1175 : (ap_fixed<38, 32>)v1176;	// L127
          ap_fixed<10, 4> v1178 = v1177;	// L472
          conv4_x_1_relu1[i0_41][i1_41][i2_41][i3_41] = v1178;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_conv2_pad[2][256][10][10];	// L472
  l_conv4_x_1_conv2_pad_i0_42: for (int i0_42 = 0; i0_42 < 2; i0_42++) {	// L472
    l_i1_42: for (int i1_42 = 0; i1_42 < 256; i1_42++) {	// L472
      l_i2_42: for (int i2_42 = 0; i2_42 < 10; i2_42++) {	// L472
        l_i3_42: for (int i3_42 = 0; i3_42 < 10; i3_42++) {	// L472
          ap_int<33> v1184 = i2_42;	// L472
          ap_int<33> v1185 = 1;	// L472
          bool v1186 = v1184 >= v1185;	// L472
          bool v1187 = 1 & v1186;	// L30
          ap_int<33> v1188 = 9;	// L472
          bool v1189 = v1184 < v1188;	// L472
          bool v1190 = v1187 & v1189;	// L30
          ap_int<33> v1191 = i3_42;	// L472
          bool v1192 = v1191 >= v1185;	// L472
          bool v1193 = v1190 & v1192;	// L30
          bool v1194 = v1191 < v1188;	// L472
          bool v1195 = v1193 & v1194;	// L30
          ap_fixed<10, 4> v1196 = conv4_x_1_relu1[i0_42][i1_42][(i2_42 - 1)][(i3_42 - 1)];	// L472
          ap_fixed<10, 4> v1197 = 0.000000;	// L472
          ap_fixed<10, 4> v1198 = v1195 ? (ap_fixed<10, 4>)v1196 : (ap_fixed<10, 4>)v1197;	// L127
          conv4_x_1_conv2_pad[i0_42][i1_42][i2_42][i3_42] = v1198;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_conv2[2][256][8][8];	// L472
  l_conv4_x_1_conv2_nn_13: for (int nn_13 = 0; nn_13 < 2; nn_13++) {	// L472
    l_ff_13: for (int ff_13 = 0; ff_13 < 256; ff_13++) {	// L472
      l_yy_13: for (int yy_13 = 0; yy_13 < 8; yy_13++) {	// L472
        l_xx_13: for (int xx_13 = 0; xx_13 < 8; xx_13++) {	// L472
          ap_fixed<10, 4> sum_13;	// L256
          ap_fixed<10, 4> v1205 = 0;	// L472
          sum_13 = v1205;	// L472
          l_rc_13: for (int rc_13 = 0; rc_13 < 256; rc_13++) {	// L256
            l_ry_13: for (int ry_13 = 0; ry_13 < 3; ry_13++) {	// L256
              l_rx_13: for (int rx_13 = 0; rx_13 < 3; rx_13++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v1209 = conv4_x_1_conv2_pad[nn_13][rc_13][(yy_13 + ry_13)][(xx_13 + rx_13)];	// L472
                  ap_fixed<10, 4> v1210 = v71[ff_13][rc_13][ry_13][rx_13];	// L36
                  ap_fixed<20, 8> v1211 = v1209;	// L472
                  ap_fixed<20, 8> v1212 = v1210;	// L472
                  ap_fixed<20, 8> v1213 = v1211 * v1212;	// L472
                  ap_fixed<10, 4> v1214 = sum_13;	// L256
                  ap_fixed<21, 9> v1215 = v1213;	// L472
                  ap_fixed<21, 9> v1216 = v1214;	// L472
                  ap_fixed<21, 9> v1217 = v1215 + v1216;	// L472
                  ap_fixed<10, 4> v1218 = v1217;	// L472
                  sum_13 = v1218;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v1219 = sum_13;	// L256
          conv4_x_1_conv2[nn_13][ff_13][yy_13][xx_13] = v1219;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_bn2[2][256][8][8];	// L472
  l_conv4_x_1_bn2_i0_43: for (int i0_43 = 0; i0_43 < 2; i0_43++) {	// L472
    l_i1_43: for (int i1_43 = 0; i1_43 < 256; i1_43++) {	// L472
      l_i2_43: for (int i2_43 = 0; i2_43 < 8; i2_43++) {	// L472
        l_i3_43: for (int i3_43 = 0; i3_43 < 8; i3_43++) {	// L472
          ap_fixed<10, 4> v1225 = conv4_x_1_conv2[i0_43][i1_43][i2_43][i3_43];	// L472
          ap_fixed<10, 4> v1226 = v74[i1_43];	// L52
          ap_fixed<11, 5> v1227 = v1225;	// L472
          ap_fixed<11, 5> v1228 = v1226;	// L472
          ap_fixed<11, 5> v1229 = v1227 - v1228;	// L472
          ap_fixed<10, 4> v1230 = v75[i1_43];	// L52
          double v1231 = v1230;	// L472
          double v1232 = v1231 + 0.000000;	// L52
          double v1233 = sqrt(v1232);	// L41
          double v1234 = v1229;	// L472
          double v1235 = v1234 / v1233;	// L472
          ap_fixed<10, 4> v1236 = v72[i1_43];	// L52
          double v1237 = v1236;	// L472
          double v1238 = v1235 * v1237;	// L472
          ap_fixed<10, 4> v1239 = v73[i1_43];	// L52
          double v1240 = v1239;	// L472
          double v1241 = v1238 + v1240;	// L472
          ap_fixed<10, 4> v1242 = v1241;	// L472
          conv4_x_1_bn2[i0_43][i1_43][i2_43][i3_43] = v1242;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_add[2][256][8][8];	// L472
  l_conv4_x_1_add_i0_44: for (int i0_44 = 0; i0_44 < 2; i0_44++) {	// L472
    l_i1_44: for (int i1_44 = 0; i1_44 < 256; i1_44++) {	// L472
      l_i2_44: for (int i2_44 = 0; i2_44 < 8; i2_44++) {	// L472
        l_i3_44: for (int i3_44 = 0; i3_44 < 8; i3_44++) {	// L472
          ap_fixed<10, 4> v1248 = conv4_x_1_bn2[i0_44][i1_44][i2_44][i3_44];	// L472
          ap_fixed<10, 4> v1249 = conv4_x_0_relu2[i0_44][i1_44][i2_44][i3_44];	// L472
          ap_fixed<11, 5> v1250 = v1248;	// L472
          ap_fixed<11, 5> v1251 = v1249;	// L472
          ap_fixed<11, 5> v1252 = v1250 + v1251;	// L472
          ap_fixed<10, 4> v1253 = v1252;	// L472
          conv4_x_1_add[i0_44][i1_44][i2_44][i3_44] = v1253;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv4_x_1_relu2[2][256][8][8];	// L472
  l_conv4_x_1_relu2_i0_45: for (int i0_45 = 0; i0_45 < 2; i0_45++) {	// L472
    l_i1_45: for (int i1_45 = 0; i1_45 < 256; i1_45++) {	// L472
      l_i2_45: for (int i2_45 = 0; i2_45 < 8; i2_45++) {	// L472
        l_i3_45: for (int i3_45 = 0; i3_45 < 8; i3_45++) {	// L472
          ap_fixed<10, 4> v1259 = conv4_x_1_add[i0_45][i1_45][i2_45][i3_45];	// L472
          ap_fixed<38, 32> v1260 = v1259;	// L472
          ap_fixed<38, 32> v1261 = 0;	// L472
          bool v1262 = v1260 <= v1261;	// L472
          ap_fixed<10, 4> v1263 = conv4_x_1_add[i0_45][i1_45][i2_45][i3_45];	// L472
          ap_fixed<38, 32> v1264 = 0;	// L472
          ap_fixed<38, 32> v1265 = v1263;	// L472
          ap_fixed<38, 32> v1266 = v1262 ? (ap_fixed<38, 32>)v1264 : (ap_fixed<38, 32>)v1265;	// L127
          ap_fixed<10, 4> v1267 = v1266;	// L472
          conv4_x_1_relu2[i0_45][i1_45][i2_45][i3_45] = v1267;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_conv1_pad[2][256][10][10];	// L472
  l_conv5_x_0_conv1_pad_i0_46: for (int i0_46 = 0; i0_46 < 2; i0_46++) {	// L472
    l_i1_46: for (int i1_46 = 0; i1_46 < 256; i1_46++) {	// L472
      l_i2_46: for (int i2_46 = 0; i2_46 < 10; i2_46++) {	// L472
        l_i3_46: for (int i3_46 = 0; i3_46 < 10; i3_46++) {	// L472
          ap_int<33> v1273 = i2_46;	// L472
          ap_int<33> v1274 = 1;	// L472
          bool v1275 = v1273 >= v1274;	// L472
          bool v1276 = 1 & v1275;	// L30
          ap_int<33> v1277 = 9;	// L472
          bool v1278 = v1273 < v1277;	// L472
          bool v1279 = v1276 & v1278;	// L30
          ap_int<33> v1280 = i3_46;	// L472
          bool v1281 = v1280 >= v1274;	// L472
          bool v1282 = v1279 & v1281;	// L30
          bool v1283 = v1280 < v1277;	// L472
          bool v1284 = v1282 & v1283;	// L30
          ap_fixed<10, 4> v1285 = conv4_x_1_relu2[i0_46][i1_46][(i2_46 - 1)][(i3_46 - 1)];	// L472
          ap_fixed<10, 4> v1286 = 0.000000;	// L472
          ap_fixed<10, 4> v1287 = v1284 ? (ap_fixed<10, 4>)v1285 : (ap_fixed<10, 4>)v1286;	// L127
          conv5_x_0_conv1_pad[i0_46][i1_46][i2_46][i3_46] = v1287;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_conv1[2][512][4][4];	// L472
  l_conv5_x_0_conv1_nn_14: for (int nn_14 = 0; nn_14 < 2; nn_14++) {	// L472
    l_ff_14: for (int ff_14 = 0; ff_14 < 512; ff_14++) {	// L472
      l_yy_14: for (int yy_14 = 0; yy_14 < 4; yy_14++) {	// L472
        l_xx_14: for (int xx_14 = 0; xx_14 < 4; xx_14++) {	// L472
          ap_fixed<10, 4> sum_14;	// L256
          ap_fixed<10, 4> v1294 = 0;	// L472
          sum_14 = v1294;	// L472
          l_rc_14: for (int rc_14 = 0; rc_14 < 256; rc_14++) {	// L256
            l_ry_14: for (int ry_14 = 0; ry_14 < 3; ry_14++) {	// L256
              l_rx_14: for (int rx_14 = 0; rx_14 < 3; rx_14++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v1298 = conv5_x_0_conv1_pad[nn_14][rc_14][((yy_14 * 2) + ry_14)][((xx_14 * 2) + rx_14)];	// L472
                  ap_fixed<10, 4> v1299 = v76[ff_14][rc_14][ry_14][rx_14];	// L34
                  ap_fixed<20, 8> v1300 = v1298;	// L472
                  ap_fixed<20, 8> v1301 = v1299;	// L472
                  ap_fixed<20, 8> v1302 = v1300 * v1301;	// L472
                  ap_fixed<10, 4> v1303 = sum_14;	// L256
                  ap_fixed<21, 9> v1304 = v1302;	// L472
                  ap_fixed<21, 9> v1305 = v1303;	// L472
                  ap_fixed<21, 9> v1306 = v1304 + v1305;	// L472
                  ap_fixed<10, 4> v1307 = v1306;	// L472
                  sum_14 = v1307;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v1308 = sum_14;	// L256
          conv5_x_0_conv1[nn_14][ff_14][yy_14][xx_14] = v1308;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_bn1[2][512][4][4];	// L472
  l_conv5_x_0_bn1_i0_47: for (int i0_47 = 0; i0_47 < 2; i0_47++) {	// L472
    l_i1_47: for (int i1_47 = 0; i1_47 < 512; i1_47++) {	// L472
      l_i2_47: for (int i2_47 = 0; i2_47 < 4; i2_47++) {	// L472
        l_i3_47: for (int i3_47 = 0; i3_47 < 4; i3_47++) {	// L472
          ap_fixed<10, 4> v1314 = conv5_x_0_conv1[i0_47][i1_47][i2_47][i3_47];	// L472
          ap_fixed<10, 4> v1315 = v79[i1_47];	// L44
          ap_fixed<11, 5> v1316 = v1314;	// L472
          ap_fixed<11, 5> v1317 = v1315;	// L472
          ap_fixed<11, 5> v1318 = v1316 - v1317;	// L472
          ap_fixed<10, 4> v1319 = v80[i1_47];	// L44
          double v1320 = v1319;	// L472
          double v1321 = v1320 + 0.000000;	// L44
          double v1322 = sqrt(v1321);	// L41
          double v1323 = v1318;	// L472
          double v1324 = v1323 / v1322;	// L472
          ap_fixed<10, 4> v1325 = v77[i1_47];	// L44
          double v1326 = v1325;	// L472
          double v1327 = v1324 * v1326;	// L472
          ap_fixed<10, 4> v1328 = v78[i1_47];	// L44
          double v1329 = v1328;	// L472
          double v1330 = v1327 + v1329;	// L472
          ap_fixed<10, 4> v1331 = v1330;	// L472
          conv5_x_0_bn1[i0_47][i1_47][i2_47][i3_47] = v1331;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_relu1[2][512][4][4];	// L472
  l_conv5_x_0_relu1_i0_48: for (int i0_48 = 0; i0_48 < 2; i0_48++) {	// L472
    l_i1_48: for (int i1_48 = 0; i1_48 < 512; i1_48++) {	// L472
      l_i2_48: for (int i2_48 = 0; i2_48 < 4; i2_48++) {	// L472
        l_i3_48: for (int i3_48 = 0; i3_48 < 4; i3_48++) {	// L472
          ap_fixed<10, 4> v1337 = conv5_x_0_bn1[i0_48][i1_48][i2_48][i3_48];	// L472
          ap_fixed<38, 32> v1338 = v1337;	// L472
          ap_fixed<38, 32> v1339 = 0;	// L472
          bool v1340 = v1338 <= v1339;	// L472
          ap_fixed<10, 4> v1341 = conv5_x_0_bn1[i0_48][i1_48][i2_48][i3_48];	// L472
          ap_fixed<38, 32> v1342 = 0;	// L472
          ap_fixed<38, 32> v1343 = v1341;	// L472
          ap_fixed<38, 32> v1344 = v1340 ? (ap_fixed<38, 32>)v1342 : (ap_fixed<38, 32>)v1343;	// L127
          ap_fixed<10, 4> v1345 = v1344;	// L472
          conv5_x_0_relu1[i0_48][i1_48][i2_48][i3_48] = v1345;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_conv2_pad[2][512][6][6];	// L472
  l_conv5_x_0_conv2_pad_i0_49: for (int i0_49 = 0; i0_49 < 2; i0_49++) {	// L472
    l_i1_49: for (int i1_49 = 0; i1_49 < 512; i1_49++) {	// L472
      l_i2_49: for (int i2_49 = 0; i2_49 < 6; i2_49++) {	// L472
        l_i3_49: for (int i3_49 = 0; i3_49 < 6; i3_49++) {	// L472
          ap_int<33> v1351 = i2_49;	// L472
          ap_int<33> v1352 = 1;	// L472
          bool v1353 = v1351 >= v1352;	// L472
          bool v1354 = 1 & v1353;	// L30
          ap_int<33> v1355 = 5;	// L472
          bool v1356 = v1351 < v1355;	// L472
          bool v1357 = v1354 & v1356;	// L30
          ap_int<33> v1358 = i3_49;	// L472
          bool v1359 = v1358 >= v1352;	// L472
          bool v1360 = v1357 & v1359;	// L30
          bool v1361 = v1358 < v1355;	// L472
          bool v1362 = v1360 & v1361;	// L30
          ap_fixed<10, 4> v1363 = conv5_x_0_relu1[i0_49][i1_49][(i2_49 - 1)][(i3_49 - 1)];	// L472
          ap_fixed<10, 4> v1364 = 0.000000;	// L472
          ap_fixed<10, 4> v1365 = v1362 ? (ap_fixed<10, 4>)v1363 : (ap_fixed<10, 4>)v1364;	// L127
          conv5_x_0_conv2_pad[i0_49][i1_49][i2_49][i3_49] = v1365;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_conv2[2][512][4][4];	// L472
  l_conv5_x_0_conv2_nn_15: for (int nn_15 = 0; nn_15 < 2; nn_15++) {	// L472
    l_ff_15: for (int ff_15 = 0; ff_15 < 512; ff_15++) {	// L472
      l_yy_15: for (int yy_15 = 0; yy_15 < 4; yy_15++) {	// L472
        l_xx_15: for (int xx_15 = 0; xx_15 < 4; xx_15++) {	// L472
          ap_fixed<10, 4> sum_15;	// L256
          ap_fixed<10, 4> v1372 = 0;	// L472
          sum_15 = v1372;	// L472
          l_rc_15: for (int rc_15 = 0; rc_15 < 512; rc_15++) {	// L256
            l_ry_15: for (int ry_15 = 0; ry_15 < 3; ry_15++) {	// L256
              l_rx_15: for (int rx_15 = 0; rx_15 < 3; rx_15++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v1376 = conv5_x_0_conv2_pad[nn_15][rc_15][(yy_15 + ry_15)][(xx_15 + rx_15)];	// L472
                  ap_fixed<10, 4> v1377 = v81[ff_15][rc_15][ry_15][rx_15];	// L36
                  ap_fixed<20, 8> v1378 = v1376;	// L472
                  ap_fixed<20, 8> v1379 = v1377;	// L472
                  ap_fixed<20, 8> v1380 = v1378 * v1379;	// L472
                  ap_fixed<10, 4> v1381 = sum_15;	// L256
                  ap_fixed<21, 9> v1382 = v1380;	// L472
                  ap_fixed<21, 9> v1383 = v1381;	// L472
                  ap_fixed<21, 9> v1384 = v1382 + v1383;	// L472
                  ap_fixed<10, 4> v1385 = v1384;	// L472
                  sum_15 = v1385;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v1386 = sum_15;	// L256
          conv5_x_0_conv2[nn_15][ff_15][yy_15][xx_15] = v1386;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_bn2[2][512][4][4];	// L472
  l_conv5_x_0_bn2_i0_50: for (int i0_50 = 0; i0_50 < 2; i0_50++) {	// L472
    l_i1_50: for (int i1_50 = 0; i1_50 < 512; i1_50++) {	// L472
      l_i2_50: for (int i2_50 = 0; i2_50 < 4; i2_50++) {	// L472
        l_i3_50: for (int i3_50 = 0; i3_50 < 4; i3_50++) {	// L472
          ap_fixed<10, 4> v1392 = conv5_x_0_conv2[i0_50][i1_50][i2_50][i3_50];	// L472
          ap_fixed<10, 4> v1393 = v84[i1_50];	// L44
          ap_fixed<11, 5> v1394 = v1392;	// L472
          ap_fixed<11, 5> v1395 = v1393;	// L472
          ap_fixed<11, 5> v1396 = v1394 - v1395;	// L472
          ap_fixed<10, 4> v1397 = v85[i1_50];	// L44
          double v1398 = v1397;	// L472
          double v1399 = v1398 + 0.000000;	// L44
          double v1400 = sqrt(v1399);	// L41
          double v1401 = v1396;	// L472
          double v1402 = v1401 / v1400;	// L472
          ap_fixed<10, 4> v1403 = v82[i1_50];	// L44
          double v1404 = v1403;	// L472
          double v1405 = v1402 * v1404;	// L472
          ap_fixed<10, 4> v1406 = v83[i1_50];	// L44
          double v1407 = v1406;	// L472
          double v1408 = v1405 + v1407;	// L472
          ap_fixed<10, 4> v1409 = v1408;	// L472
          conv5_x_0_bn2[i0_50][i1_50][i2_50][i3_50] = v1409;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_convs[2][512][4][4];	// L472
  l_conv5_x_0_convs_nn_16: for (int nn_16 = 0; nn_16 < 2; nn_16++) {	// L472
    l_ff_16: for (int ff_16 = 0; ff_16 < 512; ff_16++) {	// L472
      l_yy_16: for (int yy_16 = 0; yy_16 < 4; yy_16++) {	// L472
        l_xx_16: for (int xx_16 = 0; xx_16 < 4; xx_16++) {	// L472
          ap_fixed<10, 4> sum_16;	// L256
          ap_fixed<10, 4> v1416 = 0;	// L472
          sum_16 = v1416;	// L472
          l_rc_16: for (int rc_16 = 0; rc_16 < 256; rc_16++) {	// L256
            if (1) {	// L472
              ap_fixed<10, 4> v1418 = conv4_x_1_relu2[nn_16][rc_16][((yy_16 * 2) + 0)][((xx_16 * 2) + 0)];	// L472
              ap_fixed<10, 4> v1419 = v86[ff_16][rc_16][0][0];	// L39
              ap_fixed<20, 8> v1420 = v1418;	// L472
              ap_fixed<20, 8> v1421 = v1419;	// L472
              ap_fixed<20, 8> v1422 = v1420 * v1421;	// L472
              ap_fixed<10, 4> v1423 = sum_16;	// L256
              ap_fixed<21, 9> v1424 = v1422;	// L472
              ap_fixed<21, 9> v1425 = v1423;	// L472
              ap_fixed<21, 9> v1426 = v1424 + v1425;	// L472
              ap_fixed<10, 4> v1427 = v1426;	// L472
              sum_16 = v1427;	// L472
            }
          }
          ap_fixed<10, 4> v1428 = sum_16;	// L256
          conv5_x_0_convs[nn_16][ff_16][yy_16][xx_16] = v1428;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_bns[2][512][4][4];	// L472
  l_conv5_x_0_bns_i0_51: for (int i0_51 = 0; i0_51 < 2; i0_51++) {	// L472
    l_i1_51: for (int i1_51 = 0; i1_51 < 512; i1_51++) {	// L472
      l_i2_51: for (int i2_51 = 0; i2_51 < 4; i2_51++) {	// L472
        l_i3_51: for (int i3_51 = 0; i3_51 < 4; i3_51++) {	// L472
          ap_fixed<10, 4> v1434 = conv5_x_0_convs[i0_51][i1_51][i2_51][i3_51];	// L472
          ap_fixed<10, 4> v1435 = v89[i1_51];	// L44
          ap_fixed<11, 5> v1436 = v1434;	// L472
          ap_fixed<11, 5> v1437 = v1435;	// L472
          ap_fixed<11, 5> v1438 = v1436 - v1437;	// L472
          ap_fixed<10, 4> v1439 = v90[i1_51];	// L44
          double v1440 = v1439;	// L472
          double v1441 = v1440 + 0.000000;	// L44
          double v1442 = sqrt(v1441);	// L41
          double v1443 = v1438;	// L472
          double v1444 = v1443 / v1442;	// L472
          ap_fixed<10, 4> v1445 = v87[i1_51];	// L44
          double v1446 = v1445;	// L472
          double v1447 = v1444 * v1446;	// L472
          ap_fixed<10, 4> v1448 = v88[i1_51];	// L44
          double v1449 = v1448;	// L472
          double v1450 = v1447 + v1449;	// L472
          ap_fixed<10, 4> v1451 = v1450;	// L472
          conv5_x_0_bns[i0_51][i1_51][i2_51][i3_51] = v1451;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_add[2][512][4][4];	// L472
  l_conv5_x_0_add_i0_52: for (int i0_52 = 0; i0_52 < 2; i0_52++) {	// L472
    l_i1_52: for (int i1_52 = 0; i1_52 < 512; i1_52++) {	// L472
      l_i2_52: for (int i2_52 = 0; i2_52 < 4; i2_52++) {	// L472
        l_i3_52: for (int i3_52 = 0; i3_52 < 4; i3_52++) {	// L472
          ap_fixed<10, 4> v1457 = conv5_x_0_bn2[i0_52][i1_52][i2_52][i3_52];	// L472
          ap_fixed<10, 4> v1458 = conv5_x_0_bns[i0_52][i1_52][i2_52][i3_52];	// L472
          ap_fixed<11, 5> v1459 = v1457;	// L472
          ap_fixed<11, 5> v1460 = v1458;	// L472
          ap_fixed<11, 5> v1461 = v1459 + v1460;	// L472
          ap_fixed<10, 4> v1462 = v1461;	// L472
          conv5_x_0_add[i0_52][i1_52][i2_52][i3_52] = v1462;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_0_relu2[2][512][4][4];	// L472
  l_conv5_x_0_relu2_i0_53: for (int i0_53 = 0; i0_53 < 2; i0_53++) {	// L472
    l_i1_53: for (int i1_53 = 0; i1_53 < 512; i1_53++) {	// L472
      l_i2_53: for (int i2_53 = 0; i2_53 < 4; i2_53++) {	// L472
        l_i3_53: for (int i3_53 = 0; i3_53 < 4; i3_53++) {	// L472
          ap_fixed<10, 4> v1468 = conv5_x_0_add[i0_53][i1_53][i2_53][i3_53];	// L472
          ap_fixed<38, 32> v1469 = v1468;	// L472
          ap_fixed<38, 32> v1470 = 0;	// L472
          bool v1471 = v1469 <= v1470;	// L472
          ap_fixed<10, 4> v1472 = conv5_x_0_add[i0_53][i1_53][i2_53][i3_53];	// L472
          ap_fixed<38, 32> v1473 = 0;	// L472
          ap_fixed<38, 32> v1474 = v1472;	// L472
          ap_fixed<38, 32> v1475 = v1471 ? (ap_fixed<38, 32>)v1473 : (ap_fixed<38, 32>)v1474;	// L127
          ap_fixed<10, 4> v1476 = v1475;	// L472
          conv5_x_0_relu2[i0_53][i1_53][i2_53][i3_53] = v1476;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_conv1_pad[2][512][6][6];	// L472
  l_conv5_x_1_conv1_pad_i0_54: for (int i0_54 = 0; i0_54 < 2; i0_54++) {	// L472
    l_i1_54: for (int i1_54 = 0; i1_54 < 512; i1_54++) {	// L472
      l_i2_54: for (int i2_54 = 0; i2_54 < 6; i2_54++) {	// L472
        l_i3_54: for (int i3_54 = 0; i3_54 < 6; i3_54++) {	// L472
          ap_int<33> v1482 = i2_54;	// L472
          ap_int<33> v1483 = 1;	// L472
          bool v1484 = v1482 >= v1483;	// L472
          bool v1485 = 1 & v1484;	// L30
          ap_int<33> v1486 = 5;	// L472
          bool v1487 = v1482 < v1486;	// L472
          bool v1488 = v1485 & v1487;	// L30
          ap_int<33> v1489 = i3_54;	// L472
          bool v1490 = v1489 >= v1483;	// L472
          bool v1491 = v1488 & v1490;	// L30
          bool v1492 = v1489 < v1486;	// L472
          bool v1493 = v1491 & v1492;	// L30
          ap_fixed<10, 4> v1494 = conv5_x_0_relu2[i0_54][i1_54][(i2_54 - 1)][(i3_54 - 1)];	// L472
          ap_fixed<10, 4> v1495 = 0.000000;	// L472
          ap_fixed<10, 4> v1496 = v1493 ? (ap_fixed<10, 4>)v1494 : (ap_fixed<10, 4>)v1495;	// L127
          conv5_x_1_conv1_pad[i0_54][i1_54][i2_54][i3_54] = v1496;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_conv1[2][512][4][4];	// L472
  l_conv5_x_1_conv1_nn_17: for (int nn_17 = 0; nn_17 < 2; nn_17++) {	// L472
    l_ff_17: for (int ff_17 = 0; ff_17 < 512; ff_17++) {	// L472
      l_yy_17: for (int yy_17 = 0; yy_17 < 4; yy_17++) {	// L472
        l_xx_17: for (int xx_17 = 0; xx_17 < 4; xx_17++) {	// L472
          ap_fixed<10, 4> sum_17;	// L256
          ap_fixed<10, 4> v1503 = 0;	// L472
          sum_17 = v1503;	// L472
          l_rc_17: for (int rc_17 = 0; rc_17 < 512; rc_17++) {	// L256
            l_ry_17: for (int ry_17 = 0; ry_17 < 3; ry_17++) {	// L256
              l_rx_17: for (int rx_17 = 0; rx_17 < 3; rx_17++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v1507 = conv5_x_1_conv1_pad[nn_17][rc_17][(yy_17 + ry_17)][(xx_17 + rx_17)];	// L472
                  ap_fixed<10, 4> v1508 = v91[ff_17][rc_17][ry_17][rx_17];	// L34
                  ap_fixed<20, 8> v1509 = v1507;	// L472
                  ap_fixed<20, 8> v1510 = v1508;	// L472
                  ap_fixed<20, 8> v1511 = v1509 * v1510;	// L472
                  ap_fixed<10, 4> v1512 = sum_17;	// L256
                  ap_fixed<21, 9> v1513 = v1511;	// L472
                  ap_fixed<21, 9> v1514 = v1512;	// L472
                  ap_fixed<21, 9> v1515 = v1513 + v1514;	// L472
                  ap_fixed<10, 4> v1516 = v1515;	// L472
                  sum_17 = v1516;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v1517 = sum_17;	// L256
          conv5_x_1_conv1[nn_17][ff_17][yy_17][xx_17] = v1517;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_bn1[2][512][4][4];	// L472
  l_conv5_x_1_bn1_i0_55: for (int i0_55 = 0; i0_55 < 2; i0_55++) {	// L472
    l_i1_55: for (int i1_55 = 0; i1_55 < 512; i1_55++) {	// L472
      l_i2_55: for (int i2_55 = 0; i2_55 < 4; i2_55++) {	// L472
        l_i3_55: for (int i3_55 = 0; i3_55 < 4; i3_55++) {	// L472
          ap_fixed<10, 4> v1523 = conv5_x_1_conv1[i0_55][i1_55][i2_55][i3_55];	// L472
          ap_fixed<10, 4> v1524 = v94[i1_55];	// L52
          ap_fixed<11, 5> v1525 = v1523;	// L472
          ap_fixed<11, 5> v1526 = v1524;	// L472
          ap_fixed<11, 5> v1527 = v1525 - v1526;	// L472
          ap_fixed<10, 4> v1528 = v95[i1_55];	// L52
          double v1529 = v1528;	// L472
          double v1530 = v1529 + 0.000000;	// L52
          double v1531 = sqrt(v1530);	// L41
          double v1532 = v1527;	// L472
          double v1533 = v1532 / v1531;	// L472
          ap_fixed<10, 4> v1534 = v92[i1_55];	// L52
          double v1535 = v1534;	// L472
          double v1536 = v1533 * v1535;	// L472
          ap_fixed<10, 4> v1537 = v93[i1_55];	// L52
          double v1538 = v1537;	// L472
          double v1539 = v1536 + v1538;	// L472
          ap_fixed<10, 4> v1540 = v1539;	// L472
          conv5_x_1_bn1[i0_55][i1_55][i2_55][i3_55] = v1540;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_relu1[2][512][4][4];	// L472
  l_conv5_x_1_relu1_i0_56: for (int i0_56 = 0; i0_56 < 2; i0_56++) {	// L472
    l_i1_56: for (int i1_56 = 0; i1_56 < 512; i1_56++) {	// L472
      l_i2_56: for (int i2_56 = 0; i2_56 < 4; i2_56++) {	// L472
        l_i3_56: for (int i3_56 = 0; i3_56 < 4; i3_56++) {	// L472
          ap_fixed<10, 4> v1546 = conv5_x_1_bn1[i0_56][i1_56][i2_56][i3_56];	// L472
          ap_fixed<38, 32> v1547 = v1546;	// L472
          ap_fixed<38, 32> v1548 = 0;	// L472
          bool v1549 = v1547 <= v1548;	// L472
          ap_fixed<10, 4> v1550 = conv5_x_1_bn1[i0_56][i1_56][i2_56][i3_56];	// L472
          ap_fixed<38, 32> v1551 = 0;	// L472
          ap_fixed<38, 32> v1552 = v1550;	// L472
          ap_fixed<38, 32> v1553 = v1549 ? (ap_fixed<38, 32>)v1551 : (ap_fixed<38, 32>)v1552;	// L127
          ap_fixed<10, 4> v1554 = v1553;	// L472
          conv5_x_1_relu1[i0_56][i1_56][i2_56][i3_56] = v1554;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_conv2_pad[2][512][6][6];	// L472
  l_conv5_x_1_conv2_pad_i0_57: for (int i0_57 = 0; i0_57 < 2; i0_57++) {	// L472
    l_i1_57: for (int i1_57 = 0; i1_57 < 512; i1_57++) {	// L472
      l_i2_57: for (int i2_57 = 0; i2_57 < 6; i2_57++) {	// L472
        l_i3_57: for (int i3_57 = 0; i3_57 < 6; i3_57++) {	// L472
          ap_int<33> v1560 = i2_57;	// L472
          ap_int<33> v1561 = 1;	// L472
          bool v1562 = v1560 >= v1561;	// L472
          bool v1563 = 1 & v1562;	// L30
          ap_int<33> v1564 = 5;	// L472
          bool v1565 = v1560 < v1564;	// L472
          bool v1566 = v1563 & v1565;	// L30
          ap_int<33> v1567 = i3_57;	// L472
          bool v1568 = v1567 >= v1561;	// L472
          bool v1569 = v1566 & v1568;	// L30
          bool v1570 = v1567 < v1564;	// L472
          bool v1571 = v1569 & v1570;	// L30
          ap_fixed<10, 4> v1572 = conv5_x_1_relu1[i0_57][i1_57][(i2_57 - 1)][(i3_57 - 1)];	// L472
          ap_fixed<10, 4> v1573 = 0.000000;	// L472
          ap_fixed<10, 4> v1574 = v1571 ? (ap_fixed<10, 4>)v1572 : (ap_fixed<10, 4>)v1573;	// L127
          conv5_x_1_conv2_pad[i0_57][i1_57][i2_57][i3_57] = v1574;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_conv2[2][512][4][4];	// L472
  l_conv5_x_1_conv2_nn_18: for (int nn_18 = 0; nn_18 < 2; nn_18++) {	// L472
    l_ff_18: for (int ff_18 = 0; ff_18 < 512; ff_18++) {	// L472
      l_yy_18: for (int yy_18 = 0; yy_18 < 4; yy_18++) {	// L472
        l_xx_18: for (int xx_18 = 0; xx_18 < 4; xx_18++) {	// L472
          ap_fixed<10, 4> sum_18;	// L256
          ap_fixed<10, 4> v1581 = 0;	// L472
          sum_18 = v1581;	// L472
          l_rc_18: for (int rc_18 = 0; rc_18 < 512; rc_18++) {	// L256
            l_ry_18: for (int ry_18 = 0; ry_18 < 3; ry_18++) {	// L256
              l_rx_18: for (int rx_18 = 0; rx_18 < 3; rx_18++) {	// L256
                if (1) {	// L472
                  ap_fixed<10, 4> v1585 = conv5_x_1_conv2_pad[nn_18][rc_18][(yy_18 + ry_18)][(xx_18 + rx_18)];	// L472
                  ap_fixed<10, 4> v1586 = v96[ff_18][rc_18][ry_18][rx_18];	// L36
                  ap_fixed<20, 8> v1587 = v1585;	// L472
                  ap_fixed<20, 8> v1588 = v1586;	// L472
                  ap_fixed<20, 8> v1589 = v1587 * v1588;	// L472
                  ap_fixed<10, 4> v1590 = sum_18;	// L256
                  ap_fixed<21, 9> v1591 = v1589;	// L472
                  ap_fixed<21, 9> v1592 = v1590;	// L472
                  ap_fixed<21, 9> v1593 = v1591 + v1592;	// L472
                  ap_fixed<10, 4> v1594 = v1593;	// L472
                  sum_18 = v1594;	// L472
                }
              }
            }
          }
          ap_fixed<10, 4> v1595 = sum_18;	// L256
          conv5_x_1_conv2[nn_18][ff_18][yy_18][xx_18] = v1595;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_bn2[2][512][4][4];	// L472
  l_conv5_x_1_bn2_i0_58: for (int i0_58 = 0; i0_58 < 2; i0_58++) {	// L472
    l_i1_58: for (int i1_58 = 0; i1_58 < 512; i1_58++) {	// L472
      l_i2_58: for (int i2_58 = 0; i2_58 < 4; i2_58++) {	// L472
        l_i3_58: for (int i3_58 = 0; i3_58 < 4; i3_58++) {	// L472
          ap_fixed<10, 4> v1601 = conv5_x_1_conv2[i0_58][i1_58][i2_58][i3_58];	// L472
          ap_fixed<10, 4> v1602 = v99[i1_58];	// L52
          ap_fixed<11, 5> v1603 = v1601;	// L472
          ap_fixed<11, 5> v1604 = v1602;	// L472
          ap_fixed<11, 5> v1605 = v1603 - v1604;	// L472
          ap_fixed<10, 4> v1606 = v100[i1_58];	// L52
          double v1607 = v1606;	// L472
          double v1608 = v1607 + 0.000000;	// L52
          double v1609 = sqrt(v1608);	// L41
          double v1610 = v1605;	// L472
          double v1611 = v1610 / v1609;	// L472
          ap_fixed<10, 4> v1612 = v97[i1_58];	// L52
          double v1613 = v1612;	// L472
          double v1614 = v1611 * v1613;	// L472
          ap_fixed<10, 4> v1615 = v98[i1_58];	// L52
          double v1616 = v1615;	// L472
          double v1617 = v1614 + v1616;	// L472
          ap_fixed<10, 4> v1618 = v1617;	// L472
          conv5_x_1_bn2[i0_58][i1_58][i2_58][i3_58] = v1618;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_add[2][512][4][4];	// L472
  l_conv5_x_1_add_i0_59: for (int i0_59 = 0; i0_59 < 2; i0_59++) {	// L472
    l_i1_59: for (int i1_59 = 0; i1_59 < 512; i1_59++) {	// L472
      l_i2_59: for (int i2_59 = 0; i2_59 < 4; i2_59++) {	// L472
        l_i3_59: for (int i3_59 = 0; i3_59 < 4; i3_59++) {	// L472
          ap_fixed<10, 4> v1624 = conv5_x_1_bn2[i0_59][i1_59][i2_59][i3_59];	// L472
          ap_fixed<10, 4> v1625 = conv5_x_0_relu2[i0_59][i1_59][i2_59][i3_59];	// L472
          ap_fixed<11, 5> v1626 = v1624;	// L472
          ap_fixed<11, 5> v1627 = v1625;	// L472
          ap_fixed<11, 5> v1628 = v1626 + v1627;	// L472
          ap_fixed<10, 4> v1629 = v1628;	// L472
          conv5_x_1_add[i0_59][i1_59][i2_59][i3_59] = v1629;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> conv5_x_1_relu2[2][512][4][4];	// L472
  l_conv5_x_1_relu2_i0_60: for (int i0_60 = 0; i0_60 < 2; i0_60++) {	// L472
    l_i1_60: for (int i1_60 = 0; i1_60 < 512; i1_60++) {	// L472
      l_i2_60: for (int i2_60 = 0; i2_60 < 4; i2_60++) {	// L472
        l_i3_60: for (int i3_60 = 0; i3_60 < 4; i3_60++) {	// L472
          ap_fixed<10, 4> v1635 = conv5_x_1_add[i0_60][i1_60][i2_60][i3_60];	// L472
          ap_fixed<38, 32> v1636 = v1635;	// L472
          ap_fixed<38, 32> v1637 = 0;	// L472
          bool v1638 = v1636 <= v1637;	// L472
          ap_fixed<10, 4> v1639 = conv5_x_1_add[i0_60][i1_60][i2_60][i3_60];	// L472
          ap_fixed<38, 32> v1640 = 0;	// L472
          ap_fixed<38, 32> v1641 = v1639;	// L472
          ap_fixed<38, 32> v1642 = v1638 ? (ap_fixed<38, 32>)v1640 : (ap_fixed<38, 32>)v1641;	// L127
          ap_fixed<10, 4> v1643 = v1642;	// L472
          conv5_x_1_relu2[i0_60][i1_60][i2_60][i3_60] = v1643;	// L472
        }
      }
    }
  }
  ap_fixed<10, 4> avg[2][512][1][1];	// L472
  l_avg_i: for (int i = 0; i < 2; i++) {	// L472
    l_c: for (int c = 0; c < 512; c++) {	// L472
      ap_fixed<10, 4> sum_19;	// L256
      ap_fixed<10, 4> v1648 = 0;	// L472
      sum_19 = v1648;	// L472
      l_r_9: for (int r_9 = 0; r_9 < 4; r_9++) {	// L256
        l_r_10: for (int r_10 = 0; r_10 < 4; r_10++) {	// L256
          if (1) {	// L472
            ap_fixed<10, 4> v1651 = conv5_x_1_relu2[i][c][(0 + r_9)][(0 + r_10)];	// L472
            ap_fixed<10, 4> v1652 = sum_19;	// L256
            ap_fixed<11, 5> v1653 = v1651;	// L472
            ap_fixed<11, 5> v1654 = v1652;	// L472
            ap_fixed<11, 5> v1655 = v1653 + v1654;	// L472
            ap_fixed<10, 4> v1656 = v1655;	// L472
            sum_19 = v1656;	// L472
          }
        }
      }
      ap_fixed<10, 4> v1657 = sum_19;	// L256
      ap_fixed<42, 4> v1658 = v1657;	// L472
      ap_fixed<42, 4> v1659 = 16;	// L472
      ap_fixed<42, 4> v1660 = v1658 / v1659;	// L256
      ap_fixed<10, 4> v1661 = v1660;	// L472
      avg[i][c][0][0] = v1661;	// L472
    }
  }
  ap_fixed<10, 4> avg_view[2][512];	// L472
  l_avg_view_b: for (int b = 0; b < 2; b++) {	// L472
    l_c_0: for (int c_0 = 0; c_0 < 512; c_0++) {	// L472
      ap_fixed<10, 4> v1665 = avg[b][c_0][0][0];	// L472
      avg_view[b][c_0] = v1665;	// L472
    }
  }
  l_linear_x: for (int x = 0; x < 2; x++) {	// L472
    l_y: for (int y = 0; y < 100; y++) {	// L472
      int32_t sum_20;	// L256
      sum_20 = 0;	// L472
      l_r_11: for (int r_11 = 0; r_11 < 512; r_11++) {	// L256
        if (1) {	// L472
          ap_fixed<10, 4> v1670 = avg_view[x][r_11];	// L472
          ap_fixed<10, 4> v1671 = v101[x][r_11];	// L103
          ap_fixed<20, 8> v1672 = v1670;	// L472
          ap_fixed<20, 8> v1673 = v1671;	// L472
          ap_fixed<20, 8> v1674 = v1672 * v1673;	// L472
          int32_t v1675 = sum_20;	// L256
          ap_fixed<45, 33> v1676 = v1674;	// L472
          ap_fixed<45, 33> v1677 = v1675;	// L472
          ap_fixed<45, 33> v1678 = v1676 + v1677;	// L472
          int32_t v1679 = v1678;	// L472
          sum_20 = v1679;	// L472
        }
      }
      int32_t v1680 = sum_20;	// L256
      ap_fixed<10, 4> v1681 = v102[y];	// L104
      ap_fixed<39, 33> v1682 = v1680;	// L472
      ap_fixed<39, 33> v1683 = v1681;	// L472
      ap_fixed<39, 33> v1684 = v1682 + v1683;	// L256
      ap_fixed<10, 4> v1685 = v1684;	// L472
      v103[x][y] = v1685;	// L472
    }
  }
}

