#include <ap_int.h>
#include <ap_fixed.h>
#include <ap_axi_sdata.h>
#include <hls_stream.h>
#include <hls_math.h>
#include <math.h>
#include <stdint.h>
void default_function(float input_image[2][3][32][32], float conv1_weight[64][3][3][3], float bn1_weight[64], float bn1_bias[64], float conv2_weight1[64][64][3][3], float bn2_weight1[64], float bn2_bias1[64], float conv2_weight2[64][64][3][3], float bn2_weight2[64], float bn2_bias2[64], float conv2_weight11[64][64][3][3], float bn2_weight11[64], float bn2_bias11[64], float conv2_weight21[64][64][3][3], float bn2_weight21[64], float bn2_bias21[64], float conv3_weight1[128][64][3][3], float bn3_weight1[128], float bn3_bias1[128], float conv3_weight2[128][128][3][3], float bn3_weight2[128], float bn3_bias2[128], float conv3_shortcut_weight[128][64][1][1], float bn3_shortcut_weight[128], float bn3_shortcut_bias[128], float conv3_weight11[128][128][3][3], float bn3_weight11[128], float bn3_bias11[128], float conv3_weight21[128][128][3][3], float bn3_weight21[128], float bn3_bias21[128], float conv4_weight1[256][128][3][3], float bn4_weight1[256], float bn4_bias1[256], float conv4_weight2[256][256][3][3], float bn4_weight2[256], float bn4_bias2[256], float conv4_shortcut_weight[256][128][1][1], float bn4_shortcut_weight[256], float bn4_shortcut_bias[256], float conv4_weight11[256][256][3][3], float bn4_weight11[256], float bn4_bias11[256], float conv4_weight21[256][256][3][3], float bn4_weight21[256], float bn4_bias21[256], float conv5_weight1[512][256][3][3], float bn5_weight1[512], float bn5_bias1[512], float conv5_weight2[512][512][3][3], float bn5_weight2[512], float bn5_bias2[512], float conv5_shortcut_weight[512][256][1][1], float bn5_shortcut_weight[512], float bn5_shortcut_bias[512], float conv5_weight11[512][512][3][3], float bn5_weight11[512], float bn5_bias11[512], float conv5_weight21[512][512][3][3], float bn5_weight21[512], float bn5_bias21[512], float fc_weight[100][512], float fc_bias[100], float linear[2][100]) {
  float _top;
  float conv2d_pad[2][3][34][34];
  for (ap_int<32> indices = 0; indices < 2; ++indices) {
    for (ap_int<32> not_zero = 0; not_zero < 3; ++not_zero) {
      for (ap_int<32> index_tuple = 0; index_tuple < 34; ++index_tuple) {
        for (ap_int<32> i = 0; i < 34; ++i) {
          conv2d_pad[indices][not_zero][index_tuple][i] = (((((1 <= index_tuple) && (index_tuple < 33)) && (1 <= i)) && (i < 33)) ? ((float)input_image[((((((i - ((i + -1) % 32)) + (index_tuple * 32)) + (not_zero * 1024)) + (indices * 3072)) + -33) / 3072)][(((((((i - ((i + -1) % 32)) + (index_tuple * 32)) + (not_zero * 1024)) + (indices * 3072)) + -33) / 1024) % 3)][(((((((i - ((i + -1) % 32)) + (index_tuple * 32)) + (not_zero * 1024)) + (indices * 3072)) + -33) / 32) % 32)][((i + -1) % 32)]) : (0.000000e+00f));
        }
      }
    }
  }
  float conv2d[2][64][32][32];
  for (ap_int<32> nn = 0; nn < 2; ++nn) {
    for (ap_int<32> ff = 0; ff < 64; ++ff) {
      for (ap_int<32> yy = 0; yy < 32; ++yy) {
        for (ap_int<32> xx = 0; xx < 32; ++xx) {
          float sum;
          sum = 0.000000e+00f;
          for (ap_int<32> ra0 = 0; ra0 < 3; ++ra0) {
            for (ap_int<32> ra1 = 0; ra1 < 3; ++ra1) {
              for (ap_int<32> ra2 = 0; ra2 < 3; ++ra2) {
                sum = ((conv2d_pad[nn][ra0][(yy + ra1)][(xx + ra2)] * conv1_weight[ff][ra0][ra1][ra2]) + sum);
              }
            }
          }
          conv2d[nn][ff][yy][xx] = sum;
        }
      }
    }
  }
  float batch_norm[2][64][32][32];
  for (ap_int<32> i1 = 0; i1 < 2; ++i1) {
    for (ap_int<32> c = 0; c < 64; ++c) {
      for (ap_int<32> h = 0; h < 32; ++h) {
        for (ap_int<32> w = 0; w < 32; ++w) {
          batch_norm[i1][c][h][w] = ((bn1_weight[c] * conv2d[i1][c][h][w]) + bn1_bias[c]);
        }
      }
    }
  }
  float relu[2][64][32][32];
  for (ap_int<32> y = 0; y < 2; ++y) {
    for (ap_int<32> args0 = 0; args0 < 64; ++args0) {
      for (ap_int<32> args1 = 0; args1 < 32; ++args1) {
        for (ap_int<32> args2 = 0; args2 < 32; ++args2) {
          relu[y][args0][args1][args2] = ((0.000000e+00f < batch_norm[y][args0][args1][args2]) ? ((float)batch_norm[y][args0][args1][args2]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv1_pad[2][64][34][34];
  for (ap_int<32> indices1 = 0; indices1 < 2; ++indices1) {
    for (ap_int<32> not_zero1 = 0; not_zero1 < 64; ++not_zero1) {
      for (ap_int<32> index_tuple1 = 0; index_tuple1 < 34; ++index_tuple1) {
        for (ap_int<32> i2 = 0; i2 < 34; ++i2) {
          basicblock_conv1_pad[indices1][not_zero1][index_tuple1][i2] = (((((1 <= index_tuple1) && (index_tuple1 < 33)) && (1 <= i2)) && (i2 < 33)) ? ((float)relu[((((((i2 - ((i2 + -1) % 32)) + (index_tuple1 * 32)) + (not_zero1 * 1024)) + (indices1 * 65536)) + -33) / 65536)][(((((((i2 - ((i2 + -1) % 32)) + (index_tuple1 * 32)) + (not_zero1 * 1024)) + (indices1 * 65536)) + -33) / 1024) % 64)][(((((((i2 - ((i2 + -1) % 32)) + (index_tuple1 * 32)) + (not_zero1 * 1024)) + (indices1 * 65536)) + -33) / 32) % 32)][((i2 + -1) % 32)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv1[2][64][32][32];
  for (ap_int<32> nn1 = 0; nn1 < 2; ++nn1) {
    for (ap_int<32> ff1 = 0; ff1 < 64; ++ff1) {
      for (ap_int<32> yy1 = 0; yy1 < 32; ++yy1) {
        for (ap_int<32> xx1 = 0; xx1 < 32; ++xx1) {
          float sum1;
          sum1 = 0.000000e+00f;
          for (ap_int<32> ra3 = 0; ra3 < 64; ++ra3) {
            for (ap_int<32> ra4 = 0; ra4 < 3; ++ra4) {
              for (ap_int<32> ra5 = 0; ra5 < 3; ++ra5) {
                sum1 = ((basicblock_conv1_pad[nn1][ra3][(yy1 + ra4)][(xx1 + ra5)] * conv2_weight1[ff1][ra3][ra4][ra5]) + sum1);
              }
            }
          }
          basicblock_conv1[nn1][ff1][yy1][xx1] = sum1;
        }
      }
    }
  }
  float basicblock_bn1[2][64][32][32];
  for (ap_int<32> i3 = 0; i3 < 2; ++i3) {
    for (ap_int<32> c1 = 0; c1 < 64; ++c1) {
      for (ap_int<32> h1 = 0; h1 < 32; ++h1) {
        for (ap_int<32> w1 = 0; w1 < 32; ++w1) {
          basicblock_bn1[i3][c1][h1][w1] = ((bn2_weight1[c1] * basicblock_conv1[i3][c1][h1][w1]) + bn2_bias1[c1]);
        }
      }
    }
  }
  float basicblock_relu[2][64][32][32];
  for (ap_int<32> y1 = 0; y1 < 2; ++y1) {
    for (ap_int<32> args01 = 0; args01 < 64; ++args01) {
      for (ap_int<32> args11 = 0; args11 < 32; ++args11) {
        for (ap_int<32> args21 = 0; args21 < 32; ++args21) {
          basicblock_relu[y1][args01][args11][args21] = ((0.000000e+00f < basicblock_bn1[y1][args01][args11][args21]) ? ((float)basicblock_bn1[y1][args01][args11][args21]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv2_pad[2][64][34][34];
  for (ap_int<32> indices2 = 0; indices2 < 2; ++indices2) {
    for (ap_int<32> not_zero2 = 0; not_zero2 < 64; ++not_zero2) {
      for (ap_int<32> index_tuple2 = 0; index_tuple2 < 34; ++index_tuple2) {
        for (ap_int<32> i4 = 0; i4 < 34; ++i4) {
          basicblock_conv2_pad[indices2][not_zero2][index_tuple2][i4] = (((((1 <= index_tuple2) && (index_tuple2 < 33)) && (1 <= i4)) && (i4 < 33)) ? ((float)basicblock_relu[((((((i4 - ((i4 + -1) % 32)) + (index_tuple2 * 32)) + (not_zero2 * 1024)) + (indices2 * 65536)) + -33) / 65536)][(((((((i4 - ((i4 + -1) % 32)) + (index_tuple2 * 32)) + (not_zero2 * 1024)) + (indices2 * 65536)) + -33) / 1024) % 64)][(((((((i4 - ((i4 + -1) % 32)) + (index_tuple2 * 32)) + (not_zero2 * 1024)) + (indices2 * 65536)) + -33) / 32) % 32)][((i4 + -1) % 32)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv2[2][64][32][32];
  for (ap_int<32> nn2 = 0; nn2 < 2; ++nn2) {
    for (ap_int<32> ff2 = 0; ff2 < 64; ++ff2) {
      for (ap_int<32> yy2 = 0; yy2 < 32; ++yy2) {
        for (ap_int<32> xx2 = 0; xx2 < 32; ++xx2) {
          float sum2;
          sum2 = 0.000000e+00f;
          for (ap_int<32> ra6 = 0; ra6 < 64; ++ra6) {
            for (ap_int<32> ra7 = 0; ra7 < 3; ++ra7) {
              for (ap_int<32> ra8 = 0; ra8 < 3; ++ra8) {
                sum2 = ((basicblock_conv2_pad[nn2][ra6][(yy2 + ra7)][(xx2 + ra8)] * conv2_weight2[ff2][ra6][ra7][ra8]) + sum2);
              }
            }
          }
          basicblock_conv2[nn2][ff2][yy2][xx2] = sum2;
        }
      }
    }
  }
  float basicblock_bn2[2][64][32][32];
  for (ap_int<32> i5 = 0; i5 < 2; ++i5) {
    for (ap_int<32> c2 = 0; c2 < 64; ++c2) {
      for (ap_int<32> h2 = 0; h2 < 32; ++h2) {
        for (ap_int<32> w2 = 0; w2 < 32; ++w2) {
          basicblock_bn2[i5][c2][h2][w2] = ((bn2_weight2[c2] * basicblock_conv2[i5][c2][h2][w2]) + bn2_bias2[c2]);
        }
      }
    }
  }
  float compute0[2][64][32][32];
  for (ap_int<32> x = 0; x < 2; ++x) {
    for (ap_int<32> args02 = 0; args02 < 64; ++args02) {
      for (ap_int<32> args12 = 0; args12 < 32; ++args12) {
        for (ap_int<32> args22 = 0; args22 < 32; ++args22) {
          compute0[x][args02][args12][args22] = (basicblock_bn2[x][args02][args12][args22] + relu[x][args02][args12][args22]);
        }
      }
    }
  }
  float bb_output_relu[2][64][32][32];
  for (ap_int<32> y2 = 0; y2 < 2; ++y2) {
    for (ap_int<32> args03 = 0; args03 < 64; ++args03) {
      for (ap_int<32> args13 = 0; args13 < 32; ++args13) {
        for (ap_int<32> args23 = 0; args23 < 32; ++args23) {
          bb_output_relu[y2][args03][args13][args23] = ((0.000000e+00f < compute0[y2][args03][args13][args23]) ? ((float)compute0[y2][args03][args13][args23]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv1_pad1[2][64][34][34];
  for (ap_int<32> indices3 = 0; indices3 < 2; ++indices3) {
    for (ap_int<32> not_zero3 = 0; not_zero3 < 64; ++not_zero3) {
      for (ap_int<32> index_tuple3 = 0; index_tuple3 < 34; ++index_tuple3) {
        for (ap_int<32> i6 = 0; i6 < 34; ++i6) {
          basicblock_conv1_pad1[indices3][not_zero3][index_tuple3][i6] = (((((1 <= index_tuple3) && (index_tuple3 < 33)) && (1 <= i6)) && (i6 < 33)) ? ((float)bb_output_relu[((((((i6 - ((i6 + -1) % 32)) + (index_tuple3 * 32)) + (not_zero3 * 1024)) + (indices3 * 65536)) + -33) / 65536)][(((((((i6 - ((i6 + -1) % 32)) + (index_tuple3 * 32)) + (not_zero3 * 1024)) + (indices3 * 65536)) + -33) / 1024) % 64)][(((((((i6 - ((i6 + -1) % 32)) + (index_tuple3 * 32)) + (not_zero3 * 1024)) + (indices3 * 65536)) + -33) / 32) % 32)][((i6 + -1) % 32)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv11[2][64][32][32];
  for (ap_int<32> nn3 = 0; nn3 < 2; ++nn3) {
    for (ap_int<32> ff3 = 0; ff3 < 64; ++ff3) {
      for (ap_int<32> yy3 = 0; yy3 < 32; ++yy3) {
        for (ap_int<32> xx3 = 0; xx3 < 32; ++xx3) {
          float sum3;
          sum3 = 0.000000e+00f;
          for (ap_int<32> ra9 = 0; ra9 < 64; ++ra9) {
            for (ap_int<32> ra10 = 0; ra10 < 3; ++ra10) {
              for (ap_int<32> ra11 = 0; ra11 < 3; ++ra11) {
                sum3 = ((basicblock_conv1_pad1[nn3][ra9][(yy3 + ra10)][(xx3 + ra11)] * conv2_weight11[ff3][ra9][ra10][ra11]) + sum3);
              }
            }
          }
          basicblock_conv11[nn3][ff3][yy3][xx3] = sum3;
        }
      }
    }
  }
  float basicblock_bn11[2][64][32][32];
  for (ap_int<32> i7 = 0; i7 < 2; ++i7) {
    for (ap_int<32> c3 = 0; c3 < 64; ++c3) {
      for (ap_int<32> h3 = 0; h3 < 32; ++h3) {
        for (ap_int<32> w3 = 0; w3 < 32; ++w3) {
          basicblock_bn11[i7][c3][h3][w3] = ((bn2_weight11[c3] * basicblock_conv11[i7][c3][h3][w3]) + bn2_bias11[c3]);
        }
      }
    }
  }
  float basicblock_relu1[2][64][32][32];
  for (ap_int<32> y3 = 0; y3 < 2; ++y3) {
    for (ap_int<32> args04 = 0; args04 < 64; ++args04) {
      for (ap_int<32> args14 = 0; args14 < 32; ++args14) {
        for (ap_int<32> args24 = 0; args24 < 32; ++args24) {
          basicblock_relu1[y3][args04][args14][args24] = ((0.000000e+00f < basicblock_bn11[y3][args04][args14][args24]) ? ((float)basicblock_bn11[y3][args04][args14][args24]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv2_pad1[2][64][34][34];
  for (ap_int<32> indices4 = 0; indices4 < 2; ++indices4) {
    for (ap_int<32> not_zero4 = 0; not_zero4 < 64; ++not_zero4) {
      for (ap_int<32> index_tuple4 = 0; index_tuple4 < 34; ++index_tuple4) {
        for (ap_int<32> i8 = 0; i8 < 34; ++i8) {
          basicblock_conv2_pad1[indices4][not_zero4][index_tuple4][i8] = (((((1 <= index_tuple4) && (index_tuple4 < 33)) && (1 <= i8)) && (i8 < 33)) ? ((float)basicblock_relu1[((((((i8 - ((i8 + -1) % 32)) + (index_tuple4 * 32)) + (not_zero4 * 1024)) + (indices4 * 65536)) + -33) / 65536)][(((((((i8 - ((i8 + -1) % 32)) + (index_tuple4 * 32)) + (not_zero4 * 1024)) + (indices4 * 65536)) + -33) / 1024) % 64)][(((((((i8 - ((i8 + -1) % 32)) + (index_tuple4 * 32)) + (not_zero4 * 1024)) + (indices4 * 65536)) + -33) / 32) % 32)][((i8 + -1) % 32)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv21[2][64][32][32];
  for (ap_int<32> nn4 = 0; nn4 < 2; ++nn4) {
    for (ap_int<32> ff4 = 0; ff4 < 64; ++ff4) {
      for (ap_int<32> yy4 = 0; yy4 < 32; ++yy4) {
        for (ap_int<32> xx4 = 0; xx4 < 32; ++xx4) {
          float sum4;
          sum4 = 0.000000e+00f;
          for (ap_int<32> ra12 = 0; ra12 < 64; ++ra12) {
            for (ap_int<32> ra13 = 0; ra13 < 3; ++ra13) {
              for (ap_int<32> ra14 = 0; ra14 < 3; ++ra14) {
                sum4 = ((basicblock_conv2_pad1[nn4][ra12][(yy4 + ra13)][(xx4 + ra14)] * conv2_weight21[ff4][ra12][ra13][ra14]) + sum4);
              }
            }
          }
          basicblock_conv21[nn4][ff4][yy4][xx4] = sum4;
        }
      }
    }
  }
  float basicblock_bn21[2][64][32][32];
  for (ap_int<32> i9 = 0; i9 < 2; ++i9) {
    for (ap_int<32> c4 = 0; c4 < 64; ++c4) {
      for (ap_int<32> h4 = 0; h4 < 32; ++h4) {
        for (ap_int<32> w4 = 0; w4 < 32; ++w4) {
          basicblock_bn21[i9][c4][h4][w4] = ((bn2_weight21[c4] * basicblock_conv21[i9][c4][h4][w4]) + bn2_bias21[c4]);
        }
      }
    }
  }
  float compute1[2][64][32][32];
  for (ap_int<32> x1 = 0; x1 < 2; ++x1) {
    for (ap_int<32> args05 = 0; args05 < 64; ++args05) {
      for (ap_int<32> args15 = 0; args15 < 32; ++args15) {
        for (ap_int<32> args25 = 0; args25 < 32; ++args25) {
          compute1[x1][args05][args15][args25] = (basicblock_bn21[x1][args05][args15][args25] + bb_output_relu[x1][args05][args15][args25]);
        }
      }
    }
  }
  float bb_output_relu1[2][64][32][32];
  for (ap_int<32> y4 = 0; y4 < 2; ++y4) {
    for (ap_int<32> args06 = 0; args06 < 64; ++args06) {
      for (ap_int<32> args16 = 0; args16 < 32; ++args16) {
        for (ap_int<32> args26 = 0; args26 < 32; ++args26) {
          bb_output_relu1[y4][args06][args16][args26] = ((0.000000e+00f < compute1[y4][args06][args16][args26]) ? ((float)compute1[y4][args06][args16][args26]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv1_pad2[2][64][34][34];
  for (ap_int<32> indices5 = 0; indices5 < 2; ++indices5) {
    for (ap_int<32> not_zero5 = 0; not_zero5 < 64; ++not_zero5) {
      for (ap_int<32> index_tuple5 = 0; index_tuple5 < 34; ++index_tuple5) {
        for (ap_int<32> i10 = 0; i10 < 34; ++i10) {
          basicblock_conv1_pad2[indices5][not_zero5][index_tuple5][i10] = (((((1 <= index_tuple5) && (index_tuple5 < 33)) && (1 <= i10)) && (i10 < 33)) ? ((float)bb_output_relu1[((((((i10 - ((i10 + -1) % 32)) + (index_tuple5 * 32)) + (not_zero5 * 1024)) + (indices5 * 65536)) + -33) / 65536)][(((((((i10 - ((i10 + -1) % 32)) + (index_tuple5 * 32)) + (not_zero5 * 1024)) + (indices5 * 65536)) + -33) / 1024) % 64)][(((((((i10 - ((i10 + -1) % 32)) + (index_tuple5 * 32)) + (not_zero5 * 1024)) + (indices5 * 65536)) + -33) / 32) % 32)][((i10 + -1) % 32)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv12[2][128][16][16];
  for (ap_int<32> nn5 = 0; nn5 < 2; ++nn5) {
    for (ap_int<32> ff5 = 0; ff5 < 128; ++ff5) {
      for (ap_int<32> yy5 = 0; yy5 < 16; ++yy5) {
        for (ap_int<32> xx5 = 0; xx5 < 16; ++xx5) {
          float sum5;
          sum5 = 0.000000e+00f;
          for (ap_int<32> ra15 = 0; ra15 < 64; ++ra15) {
            for (ap_int<32> ra16 = 0; ra16 < 3; ++ra16) {
              for (ap_int<32> ra17 = 0; ra17 < 3; ++ra17) {
                sum5 = ((basicblock_conv1_pad2[nn5][ra15][((yy5 * 2) + ra16)][((xx5 * 2) + ra17)] * conv3_weight1[ff5][ra15][ra16][ra17]) + sum5);
              }
            }
          }
          basicblock_conv12[nn5][ff5][yy5][xx5] = sum5;
        }
      }
    }
  }
  float basicblock_bn12[2][128][16][16];
  for (ap_int<32> i11 = 0; i11 < 2; ++i11) {
    for (ap_int<32> c5 = 0; c5 < 128; ++c5) {
      for (ap_int<32> h5 = 0; h5 < 16; ++h5) {
        for (ap_int<32> w5 = 0; w5 < 16; ++w5) {
          basicblock_bn12[i11][c5][h5][w5] = ((bn3_weight1[c5] * basicblock_conv12[i11][c5][h5][w5]) + bn3_bias1[c5]);
        }
      }
    }
  }
  float basicblock_relu2[2][128][16][16];
  for (ap_int<32> y5 = 0; y5 < 2; ++y5) {
    for (ap_int<32> args07 = 0; args07 < 128; ++args07) {
      for (ap_int<32> args17 = 0; args17 < 16; ++args17) {
        for (ap_int<32> args27 = 0; args27 < 16; ++args27) {
          basicblock_relu2[y5][args07][args17][args27] = ((0.000000e+00f < basicblock_bn12[y5][args07][args17][args27]) ? ((float)basicblock_bn12[y5][args07][args17][args27]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv2_pad2[2][128][18][18];
  for (ap_int<32> indices6 = 0; indices6 < 2; ++indices6) {
    for (ap_int<32> not_zero6 = 0; not_zero6 < 128; ++not_zero6) {
      for (ap_int<32> index_tuple6 = 0; index_tuple6 < 18; ++index_tuple6) {
        for (ap_int<32> i12 = 0; i12 < 18; ++i12) {
          basicblock_conv2_pad2[indices6][not_zero6][index_tuple6][i12] = (((((1 <= index_tuple6) && (index_tuple6 < 17)) && (1 <= i12)) && (i12 < 17)) ? ((float)basicblock_relu2[((((((i12 - ((i12 + -1) % 16)) + (index_tuple6 * 16)) + (not_zero6 * 256)) + (indices6 * 32768)) + -17) / 32768)][(((((((i12 - ((i12 + -1) % 16)) + (index_tuple6 * 16)) + (not_zero6 * 256)) + (indices6 * 32768)) + -17) / 256) % 128)][(((((((i12 - ((i12 + -1) % 16)) + (index_tuple6 * 16)) + (not_zero6 * 256)) + (indices6 * 32768)) + -17) / 16) % 16)][((i12 + -1) % 16)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv22[2][128][16][16];
  for (ap_int<32> nn6 = 0; nn6 < 2; ++nn6) {
    for (ap_int<32> ff6 = 0; ff6 < 128; ++ff6) {
      for (ap_int<32> yy6 = 0; yy6 < 16; ++yy6) {
        for (ap_int<32> xx6 = 0; xx6 < 16; ++xx6) {
          float sum6;
          sum6 = 0.000000e+00f;
          for (ap_int<32> ra18 = 0; ra18 < 128; ++ra18) {
            for (ap_int<32> ra19 = 0; ra19 < 3; ++ra19) {
              for (ap_int<32> ra20 = 0; ra20 < 3; ++ra20) {
                sum6 = ((basicblock_conv2_pad2[nn6][ra18][(yy6 + ra19)][(xx6 + ra20)] * conv3_weight2[ff6][ra18][ra19][ra20]) + sum6);
              }
            }
          }
          basicblock_conv22[nn6][ff6][yy6][xx6] = sum6;
        }
      }
    }
  }
  float basicblock_bn22[2][128][16][16];
  for (ap_int<32> i13 = 0; i13 < 2; ++i13) {
    for (ap_int<32> c6 = 0; c6 < 128; ++c6) {
      for (ap_int<32> h6 = 0; h6 < 16; ++h6) {
        for (ap_int<32> w6 = 0; w6 < 16; ++w6) {
          basicblock_bn22[i13][c6][h6][w6] = ((bn3_weight2[c6] * basicblock_conv22[i13][c6][h6][w6]) + bn3_bias2[c6]);
        }
      }
    }
  }
  float basicblock_conv_shortcut[2][128][16][16];
  for (ap_int<32> nn7 = 0; nn7 < 2; ++nn7) {
    for (ap_int<32> ff7 = 0; ff7 < 128; ++ff7) {
      for (ap_int<32> yy7 = 0; yy7 < 16; ++yy7) {
        for (ap_int<32> xx7 = 0; xx7 < 16; ++xx7) {
          float sum7;
          sum7 = 0.000000e+00f;
          for (ap_int<32> ra21 = 0; ra21 < 64; ++ra21) {
            sum7 = ((bb_output_relu1[nn7][ra21][((xx7 / 16) + (yy7 * 2))][(((((xx7 + (yy7 * 32)) + (ra21 * 512)) + (nn7 * 32768)) * 2) % 32)] * conv3_shortcut_weight[ff7][ra21][0][0]) + sum7);
          }
          basicblock_conv_shortcut[nn7][ff7][yy7][xx7] = sum7;
        }
      }
    }
  }
  float basicblock_bn_shortcut[2][128][16][16];
  for (ap_int<32> i14 = 0; i14 < 2; ++i14) {
    for (ap_int<32> c7 = 0; c7 < 128; ++c7) {
      for (ap_int<32> h7 = 0; h7 < 16; ++h7) {
        for (ap_int<32> w7 = 0; w7 < 16; ++w7) {
          basicblock_bn_shortcut[i14][c7][h7][w7] = ((bn3_shortcut_weight[c7] * basicblock_conv_shortcut[i14][c7][h7][w7]) + bn3_shortcut_bias[c7]);
        }
      }
    }
  }
  float compute2[2][128][16][16];
  for (ap_int<32> x2 = 0; x2 < 2; ++x2) {
    for (ap_int<32> args08 = 0; args08 < 128; ++args08) {
      for (ap_int<32> args18 = 0; args18 < 16; ++args18) {
        for (ap_int<32> args28 = 0; args28 < 16; ++args28) {
          compute2[x2][args08][args18][args28] = (basicblock_bn22[x2][args08][args18][args28] + basicblock_bn_shortcut[x2][args08][args18][args28]);
        }
      }
    }
  }
  float bb_output_relu2[2][128][16][16];
  for (ap_int<32> y6 = 0; y6 < 2; ++y6) {
    for (ap_int<32> args09 = 0; args09 < 128; ++args09) {
      for (ap_int<32> args19 = 0; args19 < 16; ++args19) {
        for (ap_int<32> args29 = 0; args29 < 16; ++args29) {
          bb_output_relu2[y6][args09][args19][args29] = ((0.000000e+00f < compute2[y6][args09][args19][args29]) ? ((float)compute2[y6][args09][args19][args29]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv1_pad3[2][128][18][18];
  for (ap_int<32> indices7 = 0; indices7 < 2; ++indices7) {
    for (ap_int<32> not_zero7 = 0; not_zero7 < 128; ++not_zero7) {
      for (ap_int<32> index_tuple7 = 0; index_tuple7 < 18; ++index_tuple7) {
        for (ap_int<32> i15 = 0; i15 < 18; ++i15) {
          basicblock_conv1_pad3[indices7][not_zero7][index_tuple7][i15] = (((((1 <= index_tuple7) && (index_tuple7 < 17)) && (1 <= i15)) && (i15 < 17)) ? ((float)bb_output_relu2[((((((i15 - ((i15 + -1) % 16)) + (index_tuple7 * 16)) + (not_zero7 * 256)) + (indices7 * 32768)) + -17) / 32768)][(((((((i15 - ((i15 + -1) % 16)) + (index_tuple7 * 16)) + (not_zero7 * 256)) + (indices7 * 32768)) + -17) / 256) % 128)][(((((((i15 - ((i15 + -1) % 16)) + (index_tuple7 * 16)) + (not_zero7 * 256)) + (indices7 * 32768)) + -17) / 16) % 16)][((i15 + -1) % 16)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv13[2][128][16][16];
  for (ap_int<32> nn8 = 0; nn8 < 2; ++nn8) {
    for (ap_int<32> ff8 = 0; ff8 < 128; ++ff8) {
      for (ap_int<32> yy8 = 0; yy8 < 16; ++yy8) {
        for (ap_int<32> xx8 = 0; xx8 < 16; ++xx8) {
          float sum8;
          sum8 = 0.000000e+00f;
          for (ap_int<32> ra24 = 0; ra24 < 128; ++ra24) {
            for (ap_int<32> ra25 = 0; ra25 < 3; ++ra25) {
              for (ap_int<32> ra26 = 0; ra26 < 3; ++ra26) {
                sum8 = ((basicblock_conv1_pad3[nn8][ra24][(yy8 + ra25)][(xx8 + ra26)] * conv3_weight11[ff8][ra24][ra25][ra26]) + sum8);
              }
            }
          }
          basicblock_conv13[nn8][ff8][yy8][xx8] = sum8;
        }
      }
    }
  }
  float basicblock_bn13[2][128][16][16];
  for (ap_int<32> i16 = 0; i16 < 2; ++i16) {
    for (ap_int<32> c8 = 0; c8 < 128; ++c8) {
      for (ap_int<32> h8 = 0; h8 < 16; ++h8) {
        for (ap_int<32> w8 = 0; w8 < 16; ++w8) {
          basicblock_bn13[i16][c8][h8][w8] = ((bn3_weight11[c8] * basicblock_conv13[i16][c8][h8][w8]) + bn3_bias11[c8]);
        }
      }
    }
  }
  float basicblock_relu3[2][128][16][16];
  for (ap_int<32> y7 = 0; y7 < 2; ++y7) {
    for (ap_int<32> args010 = 0; args010 < 128; ++args010) {
      for (ap_int<32> args110 = 0; args110 < 16; ++args110) {
        for (ap_int<32> args210 = 0; args210 < 16; ++args210) {
          basicblock_relu3[y7][args010][args110][args210] = ((0.000000e+00f < basicblock_bn13[y7][args010][args110][args210]) ? ((float)basicblock_bn13[y7][args010][args110][args210]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv2_pad3[2][128][18][18];
  for (ap_int<32> indices8 = 0; indices8 < 2; ++indices8) {
    for (ap_int<32> not_zero8 = 0; not_zero8 < 128; ++not_zero8) {
      for (ap_int<32> index_tuple8 = 0; index_tuple8 < 18; ++index_tuple8) {
        for (ap_int<32> i17 = 0; i17 < 18; ++i17) {
          basicblock_conv2_pad3[indices8][not_zero8][index_tuple8][i17] = (((((1 <= index_tuple8) && (index_tuple8 < 17)) && (1 <= i17)) && (i17 < 17)) ? ((float)basicblock_relu3[((((((i17 - ((i17 + -1) % 16)) + (index_tuple8 * 16)) + (not_zero8 * 256)) + (indices8 * 32768)) + -17) / 32768)][(((((((i17 - ((i17 + -1) % 16)) + (index_tuple8 * 16)) + (not_zero8 * 256)) + (indices8 * 32768)) + -17) / 256) % 128)][(((((((i17 - ((i17 + -1) % 16)) + (index_tuple8 * 16)) + (not_zero8 * 256)) + (indices8 * 32768)) + -17) / 16) % 16)][((i17 + -1) % 16)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv23[2][128][16][16];
  for (ap_int<32> nn9 = 0; nn9 < 2; ++nn9) {
    for (ap_int<32> ff9 = 0; ff9 < 128; ++ff9) {
      for (ap_int<32> yy9 = 0; yy9 < 16; ++yy9) {
        for (ap_int<32> xx9 = 0; xx9 < 16; ++xx9) {
          float sum9;
          sum9 = 0.000000e+00f;
          for (ap_int<32> ra27 = 0; ra27 < 128; ++ra27) {
            for (ap_int<32> ra28 = 0; ra28 < 3; ++ra28) {
              for (ap_int<32> ra29 = 0; ra29 < 3; ++ra29) {
                sum9 = ((basicblock_conv2_pad3[nn9][ra27][(yy9 + ra28)][(xx9 + ra29)] * conv3_weight21[ff9][ra27][ra28][ra29]) + sum9);
              }
            }
          }
          basicblock_conv23[nn9][ff9][yy9][xx9] = sum9;
        }
      }
    }
  }
  float basicblock_bn23[2][128][16][16];
  for (ap_int<32> i18 = 0; i18 < 2; ++i18) {
    for (ap_int<32> c9 = 0; c9 < 128; ++c9) {
      for (ap_int<32> h9 = 0; h9 < 16; ++h9) {
        for (ap_int<32> w9 = 0; w9 < 16; ++w9) {
          basicblock_bn23[i18][c9][h9][w9] = ((bn3_weight21[c9] * basicblock_conv23[i18][c9][h9][w9]) + bn3_bias21[c9]);
        }
      }
    }
  }
  float compute3[2][128][16][16];
  for (ap_int<32> x3 = 0; x3 < 2; ++x3) {
    for (ap_int<32> args011 = 0; args011 < 128; ++args011) {
      for (ap_int<32> args111 = 0; args111 < 16; ++args111) {
        for (ap_int<32> args211 = 0; args211 < 16; ++args211) {
          compute3[x3][args011][args111][args211] = (basicblock_bn23[x3][args011][args111][args211] + bb_output_relu2[x3][args011][args111][args211]);
        }
      }
    }
  }
  float bb_output_relu3[2][128][16][16];
  for (ap_int<32> y8 = 0; y8 < 2; ++y8) {
    for (ap_int<32> args012 = 0; args012 < 128; ++args012) {
      for (ap_int<32> args112 = 0; args112 < 16; ++args112) {
        for (ap_int<32> args212 = 0; args212 < 16; ++args212) {
          bb_output_relu3[y8][args012][args112][args212] = ((0.000000e+00f < compute3[y8][args012][args112][args212]) ? ((float)compute3[y8][args012][args112][args212]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv1_pad4[2][128][18][18];
  for (ap_int<32> indices9 = 0; indices9 < 2; ++indices9) {
    for (ap_int<32> not_zero9 = 0; not_zero9 < 128; ++not_zero9) {
      for (ap_int<32> index_tuple9 = 0; index_tuple9 < 18; ++index_tuple9) {
        for (ap_int<32> i19 = 0; i19 < 18; ++i19) {
          basicblock_conv1_pad4[indices9][not_zero9][index_tuple9][i19] = (((((1 <= index_tuple9) && (index_tuple9 < 17)) && (1 <= i19)) && (i19 < 17)) ? ((float)bb_output_relu3[((((((i19 - ((i19 + -1) % 16)) + (index_tuple9 * 16)) + (not_zero9 * 256)) + (indices9 * 32768)) + -17) / 32768)][(((((((i19 - ((i19 + -1) % 16)) + (index_tuple9 * 16)) + (not_zero9 * 256)) + (indices9 * 32768)) + -17) / 256) % 128)][(((((((i19 - ((i19 + -1) % 16)) + (index_tuple9 * 16)) + (not_zero9 * 256)) + (indices9 * 32768)) + -17) / 16) % 16)][((i19 + -1) % 16)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv14[2][256][8][8];
  for (ap_int<32> nn10 = 0; nn10 < 2; ++nn10) {
    for (ap_int<32> ff10 = 0; ff10 < 256; ++ff10) {
      for (ap_int<32> yy10 = 0; yy10 < 8; ++yy10) {
        for (ap_int<32> xx10 = 0; xx10 < 8; ++xx10) {
          float sum10;
          sum10 = 0.000000e+00f;
          for (ap_int<32> ra30 = 0; ra30 < 128; ++ra30) {
            for (ap_int<32> ra31 = 0; ra31 < 3; ++ra31) {
              for (ap_int<32> ra32 = 0; ra32 < 3; ++ra32) {
                sum10 = ((basicblock_conv1_pad4[nn10][ra30][((yy10 * 2) + ra31)][((xx10 * 2) + ra32)] * conv4_weight1[ff10][ra30][ra31][ra32]) + sum10);
              }
            }
          }
          basicblock_conv14[nn10][ff10][yy10][xx10] = sum10;
        }
      }
    }
  }
  float basicblock_bn14[2][256][8][8];
  for (ap_int<32> i20 = 0; i20 < 2; ++i20) {
    for (ap_int<32> c10 = 0; c10 < 256; ++c10) {
      for (ap_int<32> h10 = 0; h10 < 8; ++h10) {
        for (ap_int<32> w10 = 0; w10 < 8; ++w10) {
          basicblock_bn14[i20][c10][h10][w10] = ((bn4_weight1[c10] * basicblock_conv14[i20][c10][h10][w10]) + bn4_bias1[c10]);
        }
      }
    }
  }
  float basicblock_relu4[2][256][8][8];
  for (ap_int<32> y9 = 0; y9 < 2; ++y9) {
    for (ap_int<32> args013 = 0; args013 < 256; ++args013) {
      for (ap_int<32> args113 = 0; args113 < 8; ++args113) {
        for (ap_int<32> args213 = 0; args213 < 8; ++args213) {
          basicblock_relu4[y9][args013][args113][args213] = ((0.000000e+00f < basicblock_bn14[y9][args013][args113][args213]) ? ((float)basicblock_bn14[y9][args013][args113][args213]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv2_pad4[2][256][10][10];
  for (ap_int<32> indices10 = 0; indices10 < 2; ++indices10) {
    for (ap_int<32> not_zero10 = 0; not_zero10 < 256; ++not_zero10) {
      for (ap_int<32> index_tuple10 = 0; index_tuple10 < 10; ++index_tuple10) {
        for (ap_int<32> i21 = 0; i21 < 10; ++i21) {
          basicblock_conv2_pad4[indices10][not_zero10][index_tuple10][i21] = (((((1 <= index_tuple10) && (index_tuple10 < 9)) && (1 <= i21)) && (i21 < 9)) ? ((float)basicblock_relu4[((((((i21 - ((i21 + -1) % 8)) + (index_tuple10 * 8)) + (not_zero10 * 64)) + (indices10 * 16384)) + -9) / 16384)][(((((((i21 - ((i21 + -1) % 8)) + (index_tuple10 * 8)) + (not_zero10 * 64)) + (indices10 * 16384)) + -9) / 64) % 256)][(((((((i21 - ((i21 + -1) % 8)) + (index_tuple10 * 8)) + (not_zero10 * 64)) + (indices10 * 16384)) + -9) / 8) % 8)][((i21 + -1) % 8)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv24[2][256][8][8];
  for (ap_int<32> nn11 = 0; nn11 < 2; ++nn11) {
    for (ap_int<32> ff11 = 0; ff11 < 256; ++ff11) {
      for (ap_int<32> yy11 = 0; yy11 < 8; ++yy11) {
        for (ap_int<32> xx11 = 0; xx11 < 8; ++xx11) {
          float sum11;
          sum11 = 0.000000e+00f;
          for (ap_int<32> ra33 = 0; ra33 < 256; ++ra33) {
            for (ap_int<32> ra34 = 0; ra34 < 3; ++ra34) {
              for (ap_int<32> ra35 = 0; ra35 < 3; ++ra35) {
                sum11 = ((basicblock_conv2_pad4[nn11][ra33][(yy11 + ra34)][(xx11 + ra35)] * conv4_weight2[ff11][ra33][ra34][ra35]) + sum11);
              }
            }
          }
          basicblock_conv24[nn11][ff11][yy11][xx11] = sum11;
        }
      }
    }
  }
  float basicblock_bn24[2][256][8][8];
  for (ap_int<32> i22 = 0; i22 < 2; ++i22) {
    for (ap_int<32> c11 = 0; c11 < 256; ++c11) {
      for (ap_int<32> h11 = 0; h11 < 8; ++h11) {
        for (ap_int<32> w11 = 0; w11 < 8; ++w11) {
          basicblock_bn24[i22][c11][h11][w11] = ((bn4_weight2[c11] * basicblock_conv24[i22][c11][h11][w11]) + bn4_bias2[c11]);
        }
      }
    }
  }
  float basicblock_conv_shortcut1[2][256][8][8];
  for (ap_int<32> nn12 = 0; nn12 < 2; ++nn12) {
    for (ap_int<32> ff12 = 0; ff12 < 256; ++ff12) {
      for (ap_int<32> yy12 = 0; yy12 < 8; ++yy12) {
        for (ap_int<32> xx12 = 0; xx12 < 8; ++xx12) {
          float sum12;
          sum12 = 0.000000e+00f;
          for (ap_int<32> ra36 = 0; ra36 < 128; ++ra36) {
            sum12 = ((bb_output_relu3[nn12][ra36][((xx12 / 8) + (yy12 * 2))][(((((xx12 + (yy12 * 16)) + (ra36 * 128)) + (nn12 * 16384)) * 2) % 16)] * conv4_shortcut_weight[ff12][ra36][0][0]) + sum12);
          }
          basicblock_conv_shortcut1[nn12][ff12][yy12][xx12] = sum12;
        }
      }
    }
  }
  float basicblock_bn_shortcut1[2][256][8][8];
  for (ap_int<32> i23 = 0; i23 < 2; ++i23) {
    for (ap_int<32> c12 = 0; c12 < 256; ++c12) {
      for (ap_int<32> h12 = 0; h12 < 8; ++h12) {
        for (ap_int<32> w12 = 0; w12 < 8; ++w12) {
          basicblock_bn_shortcut1[i23][c12][h12][w12] = ((bn4_shortcut_weight[c12] * basicblock_conv_shortcut1[i23][c12][h12][w12]) + bn4_shortcut_bias[c12]);
        }
      }
    }
  }
  float compute4[2][256][8][8];
  for (ap_int<32> x4 = 0; x4 < 2; ++x4) {
    for (ap_int<32> args014 = 0; args014 < 256; ++args014) {
      for (ap_int<32> args114 = 0; args114 < 8; ++args114) {
        for (ap_int<32> args214 = 0; args214 < 8; ++args214) {
          compute4[x4][args014][args114][args214] = (basicblock_bn24[x4][args014][args114][args214] + basicblock_bn_shortcut1[x4][args014][args114][args214]);
        }
      }
    }
  }
  float bb_output_relu4[2][256][8][8];
  for (ap_int<32> y10 = 0; y10 < 2; ++y10) {
    for (ap_int<32> args015 = 0; args015 < 256; ++args015) {
      for (ap_int<32> args115 = 0; args115 < 8; ++args115) {
        for (ap_int<32> args215 = 0; args215 < 8; ++args215) {
          bb_output_relu4[y10][args015][args115][args215] = ((0.000000e+00f < compute4[y10][args015][args115][args215]) ? ((float)compute4[y10][args015][args115][args215]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv1_pad5[2][256][10][10];
  for (ap_int<32> indices11 = 0; indices11 < 2; ++indices11) {
    for (ap_int<32> not_zero11 = 0; not_zero11 < 256; ++not_zero11) {
      for (ap_int<32> index_tuple11 = 0; index_tuple11 < 10; ++index_tuple11) {
        for (ap_int<32> i24 = 0; i24 < 10; ++i24) {
          basicblock_conv1_pad5[indices11][not_zero11][index_tuple11][i24] = (((((1 <= index_tuple11) && (index_tuple11 < 9)) && (1 <= i24)) && (i24 < 9)) ? ((float)bb_output_relu4[((((((i24 - ((i24 + -1) % 8)) + (index_tuple11 * 8)) + (not_zero11 * 64)) + (indices11 * 16384)) + -9) / 16384)][(((((((i24 - ((i24 + -1) % 8)) + (index_tuple11 * 8)) + (not_zero11 * 64)) + (indices11 * 16384)) + -9) / 64) % 256)][(((((((i24 - ((i24 + -1) % 8)) + (index_tuple11 * 8)) + (not_zero11 * 64)) + (indices11 * 16384)) + -9) / 8) % 8)][((i24 + -1) % 8)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv15[2][256][8][8];
  for (ap_int<32> nn13 = 0; nn13 < 2; ++nn13) {
    for (ap_int<32> ff13 = 0; ff13 < 256; ++ff13) {
      for (ap_int<32> yy13 = 0; yy13 < 8; ++yy13) {
        for (ap_int<32> xx13 = 0; xx13 < 8; ++xx13) {
          float sum13;
          sum13 = 0.000000e+00f;
          for (ap_int<32> ra39 = 0; ra39 < 256; ++ra39) {
            for (ap_int<32> ra40 = 0; ra40 < 3; ++ra40) {
              for (ap_int<32> ra41 = 0; ra41 < 3; ++ra41) {
                sum13 = ((basicblock_conv1_pad5[nn13][ra39][(yy13 + ra40)][(xx13 + ra41)] * conv4_weight11[ff13][ra39][ra40][ra41]) + sum13);
              }
            }
          }
          basicblock_conv15[nn13][ff13][yy13][xx13] = sum13;
        }
      }
    }
  }
  float basicblock_bn15[2][256][8][8];
  for (ap_int<32> i25 = 0; i25 < 2; ++i25) {
    for (ap_int<32> c13 = 0; c13 < 256; ++c13) {
      for (ap_int<32> h13 = 0; h13 < 8; ++h13) {
        for (ap_int<32> w13 = 0; w13 < 8; ++w13) {
          basicblock_bn15[i25][c13][h13][w13] = ((bn4_weight11[c13] * basicblock_conv15[i25][c13][h13][w13]) + bn4_bias11[c13]);
        }
      }
    }
  }
  float basicblock_relu5[2][256][8][8];
  for (ap_int<32> y11 = 0; y11 < 2; ++y11) {
    for (ap_int<32> args016 = 0; args016 < 256; ++args016) {
      for (ap_int<32> args116 = 0; args116 < 8; ++args116) {
        for (ap_int<32> args216 = 0; args216 < 8; ++args216) {
          basicblock_relu5[y11][args016][args116][args216] = ((0.000000e+00f < basicblock_bn15[y11][args016][args116][args216]) ? ((float)basicblock_bn15[y11][args016][args116][args216]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv2_pad5[2][256][10][10];
  for (ap_int<32> indices12 = 0; indices12 < 2; ++indices12) {
    for (ap_int<32> not_zero12 = 0; not_zero12 < 256; ++not_zero12) {
      for (ap_int<32> index_tuple12 = 0; index_tuple12 < 10; ++index_tuple12) {
        for (ap_int<32> i26 = 0; i26 < 10; ++i26) {
          basicblock_conv2_pad5[indices12][not_zero12][index_tuple12][i26] = (((((1 <= index_tuple12) && (index_tuple12 < 9)) && (1 <= i26)) && (i26 < 9)) ? ((float)basicblock_relu5[((((((i26 - ((i26 + -1) % 8)) + (index_tuple12 * 8)) + (not_zero12 * 64)) + (indices12 * 16384)) + -9) / 16384)][(((((((i26 - ((i26 + -1) % 8)) + (index_tuple12 * 8)) + (not_zero12 * 64)) + (indices12 * 16384)) + -9) / 64) % 256)][(((((((i26 - ((i26 + -1) % 8)) + (index_tuple12 * 8)) + (not_zero12 * 64)) + (indices12 * 16384)) + -9) / 8) % 8)][((i26 + -1) % 8)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv25[2][256][8][8];
  for (ap_int<32> nn14 = 0; nn14 < 2; ++nn14) {
    for (ap_int<32> ff14 = 0; ff14 < 256; ++ff14) {
      for (ap_int<32> yy14 = 0; yy14 < 8; ++yy14) {
        for (ap_int<32> xx14 = 0; xx14 < 8; ++xx14) {
          float sum14;
          sum14 = 0.000000e+00f;
          for (ap_int<32> ra42 = 0; ra42 < 256; ++ra42) {
            for (ap_int<32> ra43 = 0; ra43 < 3; ++ra43) {
              for (ap_int<32> ra44 = 0; ra44 < 3; ++ra44) {
                sum14 = ((basicblock_conv2_pad5[nn14][ra42][(yy14 + ra43)][(xx14 + ra44)] * conv4_weight21[ff14][ra42][ra43][ra44]) + sum14);
              }
            }
          }
          basicblock_conv25[nn14][ff14][yy14][xx14] = sum14;
        }
      }
    }
  }
  float basicblock_bn25[2][256][8][8];
  for (ap_int<32> i27 = 0; i27 < 2; ++i27) {
    for (ap_int<32> c14 = 0; c14 < 256; ++c14) {
      for (ap_int<32> h14 = 0; h14 < 8; ++h14) {
        for (ap_int<32> w14 = 0; w14 < 8; ++w14) {
          basicblock_bn25[i27][c14][h14][w14] = ((bn4_weight21[c14] * basicblock_conv25[i27][c14][h14][w14]) + bn4_bias21[c14]);
        }
      }
    }
  }
  float compute5[2][256][8][8];
  for (ap_int<32> x5 = 0; x5 < 2; ++x5) {
    for (ap_int<32> args017 = 0; args017 < 256; ++args017) {
      for (ap_int<32> args117 = 0; args117 < 8; ++args117) {
        for (ap_int<32> args217 = 0; args217 < 8; ++args217) {
          compute5[x5][args017][args117][args217] = (basicblock_bn25[x5][args017][args117][args217] + bb_output_relu4[x5][args017][args117][args217]);
        }
      }
    }
  }
  float bb_output_relu5[2][256][8][8];
  for (ap_int<32> y12 = 0; y12 < 2; ++y12) {
    for (ap_int<32> args018 = 0; args018 < 256; ++args018) {
      for (ap_int<32> args118 = 0; args118 < 8; ++args118) {
        for (ap_int<32> args218 = 0; args218 < 8; ++args218) {
          bb_output_relu5[y12][args018][args118][args218] = ((0.000000e+00f < compute5[y12][args018][args118][args218]) ? ((float)compute5[y12][args018][args118][args218]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv1_pad6[2][256][10][10];
  for (ap_int<32> indices13 = 0; indices13 < 2; ++indices13) {
    for (ap_int<32> not_zero13 = 0; not_zero13 < 256; ++not_zero13) {
      for (ap_int<32> index_tuple13 = 0; index_tuple13 < 10; ++index_tuple13) {
        for (ap_int<32> i28 = 0; i28 < 10; ++i28) {
          basicblock_conv1_pad6[indices13][not_zero13][index_tuple13][i28] = (((((1 <= index_tuple13) && (index_tuple13 < 9)) && (1 <= i28)) && (i28 < 9)) ? ((float)bb_output_relu5[((((((i28 - ((i28 + -1) % 8)) + (index_tuple13 * 8)) + (not_zero13 * 64)) + (indices13 * 16384)) + -9) / 16384)][(((((((i28 - ((i28 + -1) % 8)) + (index_tuple13 * 8)) + (not_zero13 * 64)) + (indices13 * 16384)) + -9) / 64) % 256)][(((((((i28 - ((i28 + -1) % 8)) + (index_tuple13 * 8)) + (not_zero13 * 64)) + (indices13 * 16384)) + -9) / 8) % 8)][((i28 + -1) % 8)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv16[2][512][4][4];
  for (ap_int<32> nn15 = 0; nn15 < 2; ++nn15) {
    for (ap_int<32> ff15 = 0; ff15 < 512; ++ff15) {
      for (ap_int<32> yy15 = 0; yy15 < 4; ++yy15) {
        for (ap_int<32> xx15 = 0; xx15 < 4; ++xx15) {
          float sum15;
          sum15 = 0.000000e+00f;
          for (ap_int<32> ra45 = 0; ra45 < 256; ++ra45) {
            for (ap_int<32> ra46 = 0; ra46 < 3; ++ra46) {
              for (ap_int<32> ra47 = 0; ra47 < 3; ++ra47) {
                sum15 = ((basicblock_conv1_pad6[nn15][ra45][((yy15 * 2) + ra46)][((xx15 * 2) + ra47)] * conv5_weight1[ff15][ra45][ra46][ra47]) + sum15);
              }
            }
          }
          basicblock_conv16[nn15][ff15][yy15][xx15] = sum15;
        }
      }
    }
  }
  float basicblock_bn16[2][512][4][4];
  for (ap_int<32> i29 = 0; i29 < 2; ++i29) {
    for (ap_int<32> c15 = 0; c15 < 512; ++c15) {
      for (ap_int<32> h15 = 0; h15 < 4; ++h15) {
        for (ap_int<32> w15 = 0; w15 < 4; ++w15) {
          basicblock_bn16[i29][c15][h15][w15] = ((bn5_weight1[c15] * basicblock_conv16[i29][c15][h15][w15]) + bn5_bias1[c15]);
        }
      }
    }
  }
  float basicblock_relu6[2][512][4][4];
  for (ap_int<32> y13 = 0; y13 < 2; ++y13) {
    for (ap_int<32> args019 = 0; args019 < 512; ++args019) {
      for (ap_int<32> args119 = 0; args119 < 4; ++args119) {
        for (ap_int<32> args219 = 0; args219 < 4; ++args219) {
          basicblock_relu6[y13][args019][args119][args219] = ((0.000000e+00f < basicblock_bn16[y13][args019][args119][args219]) ? ((float)basicblock_bn16[y13][args019][args119][args219]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv2_pad6[2][512][6][6];
  for (ap_int<32> indices14 = 0; indices14 < 2; ++indices14) {
    for (ap_int<32> not_zero14 = 0; not_zero14 < 512; ++not_zero14) {
      for (ap_int<32> index_tuple14 = 0; index_tuple14 < 6; ++index_tuple14) {
        for (ap_int<32> i30 = 0; i30 < 6; ++i30) {
          basicblock_conv2_pad6[indices14][not_zero14][index_tuple14][i30] = (((((1 <= index_tuple14) && (index_tuple14 < 5)) && (1 <= i30)) && (i30 < 5)) ? ((float)basicblock_relu6[((((((i30 - ((i30 + -1) % 4)) + (index_tuple14 * 4)) + (not_zero14 * 16)) + (indices14 * 8192)) + -5) / 8192)][(((((((i30 - ((i30 + -1) % 4)) + (index_tuple14 * 4)) + (not_zero14 * 16)) + (indices14 * 8192)) + -5) / 16) % 512)][(((((((i30 - ((i30 + -1) % 4)) + (index_tuple14 * 4)) + (not_zero14 * 16)) + (indices14 * 8192)) + -5) / 4) % 4)][((i30 + -1) % 4)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv26[2][512][4][4];
  for (ap_int<32> nn16 = 0; nn16 < 2; ++nn16) {
    for (ap_int<32> ff16 = 0; ff16 < 512; ++ff16) {
      for (ap_int<32> yy16 = 0; yy16 < 4; ++yy16) {
        for (ap_int<32> xx16 = 0; xx16 < 4; ++xx16) {
          float sum16;
          sum16 = 0.000000e+00f;
          for (ap_int<32> ra48 = 0; ra48 < 512; ++ra48) {
            for (ap_int<32> ra49 = 0; ra49 < 3; ++ra49) {
              for (ap_int<32> ra50 = 0; ra50 < 3; ++ra50) {
                sum16 = ((basicblock_conv2_pad6[nn16][ra48][(yy16 + ra49)][(xx16 + ra50)] * conv5_weight2[ff16][ra48][ra49][ra50]) + sum16);
              }
            }
          }
          basicblock_conv26[nn16][ff16][yy16][xx16] = sum16;
        }
      }
    }
  }
  float basicblock_bn26[2][512][4][4];
  for (ap_int<32> i31 = 0; i31 < 2; ++i31) {
    for (ap_int<32> c16 = 0; c16 < 512; ++c16) {
      for (ap_int<32> h16 = 0; h16 < 4; ++h16) {
        for (ap_int<32> w16 = 0; w16 < 4; ++w16) {
          basicblock_bn26[i31][c16][h16][w16] = ((bn5_weight2[c16] * basicblock_conv26[i31][c16][h16][w16]) + bn5_bias2[c16]);
        }
      }
    }
  }
  float basicblock_conv_shortcut2[2][512][4][4];
  for (ap_int<32> nn17 = 0; nn17 < 2; ++nn17) {
    for (ap_int<32> ff17 = 0; ff17 < 512; ++ff17) {
      for (ap_int<32> yy17 = 0; yy17 < 4; ++yy17) {
        for (ap_int<32> xx17 = 0; xx17 < 4; ++xx17) {
          float sum17;
          sum17 = 0.000000e+00f;
          for (ap_int<32> ra51 = 0; ra51 < 256; ++ra51) {
            sum17 = ((bb_output_relu5[nn17][ra51][((xx17 / 4) + (yy17 * 2))][(((((xx17 + (yy17 * 8)) + (ra51 * 32)) + (nn17 * 8192)) * 2) % 8)] * conv5_shortcut_weight[ff17][ra51][0][0]) + sum17);
          }
          basicblock_conv_shortcut2[nn17][ff17][yy17][xx17] = sum17;
        }
      }
    }
  }
  float basicblock_bn_shortcut2[2][512][4][4];
  for (ap_int<32> i32 = 0; i32 < 2; ++i32) {
    for (ap_int<32> c17 = 0; c17 < 512; ++c17) {
      for (ap_int<32> h17 = 0; h17 < 4; ++h17) {
        for (ap_int<32> w17 = 0; w17 < 4; ++w17) {
          basicblock_bn_shortcut2[i32][c17][h17][w17] = ((bn5_shortcut_weight[c17] * basicblock_conv_shortcut2[i32][c17][h17][w17]) + bn5_shortcut_bias[c17]);
        }
      }
    }
  }
  float compute6[2][512][4][4];
  for (ap_int<32> x6 = 0; x6 < 2; ++x6) {
    for (ap_int<32> args020 = 0; args020 < 512; ++args020) {
      for (ap_int<32> args120 = 0; args120 < 4; ++args120) {
        for (ap_int<32> args220 = 0; args220 < 4; ++args220) {
          compute6[x6][args020][args120][args220] = (basicblock_bn26[x6][args020][args120][args220] + basicblock_bn_shortcut2[x6][args020][args120][args220]);
        }
      }
    }
  }
  float bb_output_relu6[2][512][4][4];
  for (ap_int<32> y14 = 0; y14 < 2; ++y14) {
    for (ap_int<32> args021 = 0; args021 < 512; ++args021) {
      for (ap_int<32> args121 = 0; args121 < 4; ++args121) {
        for (ap_int<32> args221 = 0; args221 < 4; ++args221) {
          bb_output_relu6[y14][args021][args121][args221] = ((0.000000e+00f < compute6[y14][args021][args121][args221]) ? ((float)compute6[y14][args021][args121][args221]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv1_pad7[2][512][6][6];
  for (ap_int<32> indices15 = 0; indices15 < 2; ++indices15) {
    for (ap_int<32> not_zero15 = 0; not_zero15 < 512; ++not_zero15) {
      for (ap_int<32> index_tuple15 = 0; index_tuple15 < 6; ++index_tuple15) {
        for (ap_int<32> i33 = 0; i33 < 6; ++i33) {
          basicblock_conv1_pad7[indices15][not_zero15][index_tuple15][i33] = (((((1 <= index_tuple15) && (index_tuple15 < 5)) && (1 <= i33)) && (i33 < 5)) ? ((float)bb_output_relu6[((((((i33 - ((i33 + -1) % 4)) + (index_tuple15 * 4)) + (not_zero15 * 16)) + (indices15 * 8192)) + -5) / 8192)][(((((((i33 - ((i33 + -1) % 4)) + (index_tuple15 * 4)) + (not_zero15 * 16)) + (indices15 * 8192)) + -5) / 16) % 512)][(((((((i33 - ((i33 + -1) % 4)) + (index_tuple15 * 4)) + (not_zero15 * 16)) + (indices15 * 8192)) + -5) / 4) % 4)][((i33 + -1) % 4)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv17[2][512][4][4];
  for (ap_int<32> nn18 = 0; nn18 < 2; ++nn18) {
    for (ap_int<32> ff18 = 0; ff18 < 512; ++ff18) {
      for (ap_int<32> yy18 = 0; yy18 < 4; ++yy18) {
        for (ap_int<32> xx18 = 0; xx18 < 4; ++xx18) {
          float sum18;
          sum18 = 0.000000e+00f;
          for (ap_int<32> ra54 = 0; ra54 < 512; ++ra54) {
            for (ap_int<32> ra55 = 0; ra55 < 3; ++ra55) {
              for (ap_int<32> ra56 = 0; ra56 < 3; ++ra56) {
                sum18 = ((basicblock_conv1_pad7[nn18][ra54][(yy18 + ra55)][(xx18 + ra56)] * conv5_weight11[ff18][ra54][ra55][ra56]) + sum18);
              }
            }
          }
          basicblock_conv17[nn18][ff18][yy18][xx18] = sum18;
        }
      }
    }
  }
  float basicblock_bn17[2][512][4][4];
  for (ap_int<32> i34 = 0; i34 < 2; ++i34) {
    for (ap_int<32> c18 = 0; c18 < 512; ++c18) {
      for (ap_int<32> h18 = 0; h18 < 4; ++h18) {
        for (ap_int<32> w18 = 0; w18 < 4; ++w18) {
          basicblock_bn17[i34][c18][h18][w18] = ((bn5_weight11[c18] * basicblock_conv17[i34][c18][h18][w18]) + bn5_bias11[c18]);
        }
      }
    }
  }
  float basicblock_relu7[2][512][4][4];
  for (ap_int<32> y15 = 0; y15 < 2; ++y15) {
    for (ap_int<32> args022 = 0; args022 < 512; ++args022) {
      for (ap_int<32> args122 = 0; args122 < 4; ++args122) {
        for (ap_int<32> args222 = 0; args222 < 4; ++args222) {
          basicblock_relu7[y15][args022][args122][args222] = ((0.000000e+00f < basicblock_bn17[y15][args022][args122][args222]) ? ((float)basicblock_bn17[y15][args022][args122][args222]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv2_pad7[2][512][6][6];
  for (ap_int<32> indices16 = 0; indices16 < 2; ++indices16) {
    for (ap_int<32> not_zero16 = 0; not_zero16 < 512; ++not_zero16) {
      for (ap_int<32> index_tuple16 = 0; index_tuple16 < 6; ++index_tuple16) {
        for (ap_int<32> i35 = 0; i35 < 6; ++i35) {
          basicblock_conv2_pad7[indices16][not_zero16][index_tuple16][i35] = (((((1 <= index_tuple16) && (index_tuple16 < 5)) && (1 <= i35)) && (i35 < 5)) ? ((float)basicblock_relu7[((((((i35 - ((i35 + -1) % 4)) + (index_tuple16 * 4)) + (not_zero16 * 16)) + (indices16 * 8192)) + -5) / 8192)][(((((((i35 - ((i35 + -1) % 4)) + (index_tuple16 * 4)) + (not_zero16 * 16)) + (indices16 * 8192)) + -5) / 16) % 512)][(((((((i35 - ((i35 + -1) % 4)) + (index_tuple16 * 4)) + (not_zero16 * 16)) + (indices16 * 8192)) + -5) / 4) % 4)][((i35 + -1) % 4)]) : (0.000000e+00f));
        }
      }
    }
  }
  float basicblock_conv27[2][512][4][4];
  for (ap_int<32> nn19 = 0; nn19 < 2; ++nn19) {
    for (ap_int<32> ff19 = 0; ff19 < 512; ++ff19) {
      for (ap_int<32> yy19 = 0; yy19 < 4; ++yy19) {
        for (ap_int<32> xx19 = 0; xx19 < 4; ++xx19) {
          float sum19;
          sum19 = 0.000000e+00f;
          for (ap_int<32> ra57 = 0; ra57 < 512; ++ra57) {
            for (ap_int<32> ra58 = 0; ra58 < 3; ++ra58) {
              for (ap_int<32> ra59 = 0; ra59 < 3; ++ra59) {
                sum19 = ((basicblock_conv2_pad7[nn19][ra57][(yy19 + ra58)][(xx19 + ra59)] * conv5_weight21[ff19][ra57][ra58][ra59]) + sum19);
              }
            }
          }
          basicblock_conv27[nn19][ff19][yy19][xx19] = sum19;
        }
      }
    }
  }
  float basicblock_bn27[2][512][4][4];
  for (ap_int<32> i36 = 0; i36 < 2; ++i36) {
    for (ap_int<32> c19 = 0; c19 < 512; ++c19) {
      for (ap_int<32> h19 = 0; h19 < 4; ++h19) {
        for (ap_int<32> w19 = 0; w19 < 4; ++w19) {
          basicblock_bn27[i36][c19][h19][w19] = ((bn5_weight21[c19] * basicblock_conv27[i36][c19][h19][w19]) + bn5_bias21[c19]);
        }
      }
    }
  }
  float compute7[2][512][4][4];
  for (ap_int<32> x7 = 0; x7 < 2; ++x7) {
    for (ap_int<32> args023 = 0; args023 < 512; ++args023) {
      for (ap_int<32> args123 = 0; args123 < 4; ++args123) {
        for (ap_int<32> args223 = 0; args223 < 4; ++args223) {
          compute7[x7][args023][args123][args223] = (basicblock_bn27[x7][args023][args123][args223] + bb_output_relu6[x7][args023][args123][args223]);
        }
      }
    }
  }
  float bb_output_relu7[2][512][4][4];
  for (ap_int<32> y16 = 0; y16 < 2; ++y16) {
    for (ap_int<32> args024 = 0; args024 < 512; ++args024) {
      for (ap_int<32> args124 = 0; args124 < 4; ++args124) {
        for (ap_int<32> args224 = 0; args224 < 4; ++args224) {
          bb_output_relu7[y16][args024][args124][args224] = ((0.000000e+00f < compute7[y16][args024][args124][args224]) ? ((float)compute7[y16][args024][args124][args224]) : (0.000000e+00f));
        }
      }
    }
  }
  float avg_pool2d[2][512][1][1];
  for (ap_int<32> i37 = 0; i37 < 2; ++i37) {
    for (ap_int<32> c20 = 0; c20 < 512; ++c20) {
      float reducer0;
      reducer0 = 0.000000e+00f;
      for (ap_int<32> ra60 = 0; ra60 < 4; ++ra60) {
        for (ap_int<32> ra61 = 0; ra61 < 4; ++ra61) {
          reducer0 = ((bb_output_relu7[i37][c20][ra60][ra61] * 6.250000e-02f) + reducer0);
        }
      }
      avg_pool2d[i37][c20][0][0] = reducer0;
    }
  }
  float compute8[2][512];
  for (ap_int<32> b = 0; b < 2; ++b) {
    for (ap_int<32> c21 = 0; c21 < 512; ++c21) {
      compute8[b][c21] = avg_pool2d[b][c21][0][0];
    }
  }
  float compute9[512][100];
  for (ap_int<32> x8 = 0; x8 < 512; ++x8) {
    for (ap_int<32> y17 = 0; y17 < 100; ++y17) {
      compute9[x8][y17] = fc_weight[y17][x8];
    }
  }
  for (ap_int<32> i38 = 0; i38 < 2; ++i38) {
    for (ap_int<32> i39 = 0; i39 < 100; ++i39) {
      for (ap_int<32> i40 = 0; i40 < 512; ++i40) {
        linear[i38][i39] = ((compute8[i38][i40] * compute9[i40][i39]) + linear[i38][i39]);
      }
      linear[i38][i39] = (linear[i38][i39] + fc_bias[i39]);
    }
  }
}

