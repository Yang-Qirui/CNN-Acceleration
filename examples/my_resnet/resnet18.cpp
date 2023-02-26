#include <ap_int.h>
#include <ap_fixed.h>
#include <ap_axi_sdata.h>
#include <hls_stream.h>
#include <hls_math.h>
#include <math.h>
#include <stdint.h>
void default_function(ap_int<32> input_image[32][3][32][32], ap_int<32> conv1_weight[64][3][3][3], ap_int<32> bn1_weight[64], ap_int<32> bn1_bias[64], ap_int<32> conv2_weight1[64][64][3][3], ap_int<32> bn2_weight1[64], ap_int<32> bn2_bias1[64], ap_int<32> conv2_weight2[64][64][3][3], ap_int<32> bn2_weight2[64], ap_int<32> bn2_bias2[64], ap_int<32> conv2_shortcut_weight[64][64][1][1], ap_int<32> bn2_shortcut_weight[64], ap_int<32> bn2_shortcut_bias[64], ap_int<32> conv2_weight11[64][64][3][3], ap_int<32> bn2_weight11[64], ap_int<32> bn2_bias11[64], ap_int<32> conv2_weight21[64][64][3][3], ap_int<32> bn2_weight21[64], ap_int<32> bn2_bias21[64], ap_int<32> conv2_shortcut_weight1[64][64][1][1], ap_int<32> bn2_shortcut_weight1[64], ap_int<32> bn2_shortcut_bias1[64], ap_int<32> conv3_weight1[64][64][3][3], ap_int<32> bn3_weight1[64], ap_int<32> bn3_bias1[64], ap_int<32> conv3_weight2[64][64][3][3], ap_int<32> bn3_weight2[64], ap_int<32> bn3_bias2[64], ap_int<32> conv3_shortcut_weight[64][64][1][1], ap_int<32> bn3_shortcut_weight[64], ap_int<32> bn3_shortcut_bias[64], ap_int<32> conv3_weight11[64][64][3][3], ap_int<32> bn3_weight11[64], ap_int<32> bn3_bias11[64], ap_int<32> conv3_weight21[64][64][3][3], ap_int<32> bn3_weight21[64], ap_int<32> bn3_bias21[64], ap_int<32> conv3_shortcut_weight1[64][64][1][1], ap_int<32> bn3_shortcut_weight1[64], ap_int<32> bn3_shortcut_bias1[64], ap_int<32> conv4_weight1[64][64][3][3], ap_int<32> bn4_weight1[64], ap_int<32> bn4_bias1[64], ap_int<32> conv4_weight2[64][64][3][3], ap_int<32> bn4_weight2[64], ap_int<32> bn4_bias2[64], ap_int<32> conv4_shortcut_weight[64][64][1][1], ap_int<32> bn4_shortcut_weight[64], ap_int<32> bn4_shortcut_bias[64], ap_int<32> conv4_weight11[64][64][3][3], ap_int<32> bn4_weight11[64], ap_int<32> bn4_bias11[64], ap_int<32> conv4_weight21[64][64][3][3], ap_int<32> bn4_weight21[64], ap_int<32> bn4_bias21[64], ap_int<32> conv4_shortcut_weight1[64][64][1][1], ap_int<32> bn4_shortcut_weight1[64], ap_int<32> bn4_shortcut_bias1[64], ap_int<32> conv5_weight1[64][64][3][3], ap_int<32> bn5_weight1[64], ap_int<32> bn5_bias1[64], ap_int<32> conv5_weight2[64][64][3][3], ap_int<32> bn5_weight2[64], ap_int<32> bn5_bias2[64], ap_int<32> conv5_shortcut_weight[64][64][1][1], ap_int<32> bn5_shortcut_weight[64], ap_int<32> bn5_shortcut_bias[64], ap_int<32> conv5_weight11[64][64][3][3], ap_int<32> bn5_weight11[64], ap_int<32> bn5_bias11[64], ap_int<32> conv5_weight21[64][64][3][3], ap_int<32> bn5_weight21[64], ap_int<32> bn5_bias21[64], ap_int<32> conv5_shortcut_weight1[64][64][1][1], ap_int<32> bn5_shortcut_weight1[64], ap_int<32> bn5_shortcut_bias1[64], ap_int<32> full_connection[100][64], ap_int<32> linear[32][64]) {
  ap_int<32> _top;
  ap_int<32> conv2d_pad[32][3][34][34];
  for (ap_int<32> indices = 0; indices < 32; ++indices) {
    for (ap_int<32> not_zero = 0; not_zero < 3; ++not_zero) {
      for (ap_int<32> index_tuple = 0; index_tuple < 34; ++index_tuple) {
        for (ap_int<32> i = 0; i < 34; ++i) {
          conv2d_pad[indices][not_zero][index_tuple][i] = (((((1 <= index_tuple) && (index_tuple < 33)) && (1 <= i)) && (i < 33)) ? ((ap_int<32>)input_image[((((((i - ((i + -1) % 32)) + (index_tuple * 32)) + (not_zero * 1024)) + (indices * 3072)) + -33) / 3072)][(((((((i - ((i + -1) % 32)) + (index_tuple * 32)) + (not_zero * 1024)) + (indices * 3072)) + -33) / 1024) % 3)][(((((((i - ((i + -1) % 32)) + (index_tuple * 32)) + (not_zero * 1024)) + (indices * 3072)) + -33) / 32) % 32)][((i + -1) % 32)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> conv2d[32][64][32][32];
  for (ap_int<32> nn = 0; nn < 32; ++nn) {
    for (ap_int<32> ff = 0; ff < 64; ++ff) {
      for (ap_int<32> yy = 0; yy < 32; ++yy) {
        for (ap_int<32> xx = 0; xx < 32; ++xx) {
          ap_fixed<16, 8> sum;
          sum = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra0 = 0; ra0 < 3; ++ra0) {
            for (ap_int<32> ra1 = 0; ra1 < 3; ++ra1) {
              for (ap_int<32> ra2 = 0; ra2 < 3; ++ra2) {
                sum = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)conv2d_pad[nn][ra0][(yy + ra1)][(xx + ra2)]) * ((ap_int<64>)conv1_weight[ff][ra0][ra1][ra2]))) + ((ap_fixed<73, 65>)sum)));
              }
            }
          }
          conv2d[nn][ff][yy][xx] = ((ap_int<32>)sum);
        }
      }
    }
  }
  ap_fixed<16, 8> batch_norm[32][64][32][32];
  for (ap_int<32> x = 0; x < 32; ++x) {
    for (ap_int<32> args0 = 0; args0 < 64; ++args0) {
      for (ap_int<32> args1 = 0; args1 < 32; ++args1) {
        for (ap_int<32> args2 = 0; args2 < 32; ++args2) {
          batch_norm[x][args0][args1][args2] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn1_weight[args2]) * ((ap_int<64>)conv2d[x][args0][args1][args2]))) + ((ap_int<65>)bn1_bias[args2])));
        }
      }
    }
  }
  ap_int<32> relu_x1[32][64][32][32];
  for (ap_int<32> y = 0; y < 32; ++y) {
    for (ap_int<32> args01 = 0; args01 < 64; ++args01) {
      for (ap_int<32> args11 = 0; args11 < 32; ++args11) {
        for (ap_int<32> args21 = 0; args21 < 32; ++args21) {
          relu_x1[y][args01][args11][args21] = ((ap_int<32>)((((ap_fixed<40, 32>)batch_norm[y][args01][args11][args21]) < (ap_fixed<40, 32>)0) ? (((ap_fixed<16, 8>)0)) : ((ap_fixed<16, 8>)batch_norm[y][args01][args11][args21])));
        }
      }
    }
  }
  ap_int<32> relu[32][64][32][32];
  for (ap_int<32> y1 = 0; y1 < 32; ++y1) {
    for (ap_int<32> args02 = 0; args02 < 64; ++args02) {
      for (ap_int<32> args12 = 0; args12 < 32; ++args12) {
        for (ap_int<32> args22 = 0; args22 < 32; ++args22) {
          relu[y1][args02][args12][args22] = ((ap_int<32>)((1 < relu_x1[y1][args02][args12][args22]) ? (((ap_fixed<40, 32>)((ap_fixed<16, 8>)1))) : (((ap_fixed<40, 32>)relu_x1[y1][args02][args12][args22]))));
        }
      }
    }
  }
  ap_int<32> basicblock_conv1_pad[32][64][34][34];
  for (ap_int<32> indices1 = 0; indices1 < 32; ++indices1) {
    for (ap_int<32> not_zero1 = 0; not_zero1 < 64; ++not_zero1) {
      for (ap_int<32> index_tuple1 = 0; index_tuple1 < 34; ++index_tuple1) {
        for (ap_int<32> i1 = 0; i1 < 34; ++i1) {
          basicblock_conv1_pad[indices1][not_zero1][index_tuple1][i1] = (((((1 <= index_tuple1) && (index_tuple1 < 33)) && (1 <= i1)) && (i1 < 33)) ? ((ap_int<32>)relu[((((((i1 - ((i1 + -1) % 32)) + (index_tuple1 * 32)) + (not_zero1 * 1024)) + (indices1 * 65536)) + -33) / 65536)][(((((((i1 - ((i1 + -1) % 32)) + (index_tuple1 * 32)) + (not_zero1 * 1024)) + (indices1 * 65536)) + -33) / 1024) % 64)][(((((((i1 - ((i1 + -1) % 32)) + (index_tuple1 * 32)) + (not_zero1 * 1024)) + (indices1 * 65536)) + -33) / 32) % 32)][((i1 + -1) % 32)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv1[32][64][32][32];
  for (ap_int<32> nn1 = 0; nn1 < 32; ++nn1) {
    for (ap_int<32> ff1 = 0; ff1 < 64; ++ff1) {
      for (ap_int<32> yy1 = 0; yy1 < 32; ++yy1) {
        for (ap_int<32> xx1 = 0; xx1 < 32; ++xx1) {
          ap_fixed<16, 8> sum1;
          sum1 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra3 = 0; ra3 < 64; ++ra3) {
            for (ap_int<32> ra4 = 0; ra4 < 3; ++ra4) {
              for (ap_int<32> ra5 = 0; ra5 < 3; ++ra5) {
                sum1 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv1_pad[nn1][ra3][(yy1 + ra4)][(xx1 + ra5)]) * ((ap_int<64>)conv2_weight1[ff1][ra3][ra4][ra5]))) + ((ap_fixed<73, 65>)sum1)));
              }
            }
          }
          basicblock_conv1[nn1][ff1][yy1][xx1] = ((ap_int<32>)sum1);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn1[32][64][32][32];
  for (ap_int<32> x1 = 0; x1 < 32; ++x1) {
    for (ap_int<32> args03 = 0; args03 < 64; ++args03) {
      for (ap_int<32> args13 = 0; args13 < 32; ++args13) {
        for (ap_int<32> args23 = 0; args23 < 32; ++args23) {
          basicblock_bn1[x1][args03][args13][args23] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn2_weight1[args23]) * ((ap_int<64>)basicblock_conv1[x1][args03][args13][args23]))) + ((ap_int<65>)bn2_bias1[args23])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu_x1[32][64][32][32];
  for (ap_int<32> y2 = 0; y2 < 32; ++y2) {
    for (ap_int<32> args04 = 0; args04 < 64; ++args04) {
      for (ap_int<32> args14 = 0; args14 < 32; ++args14) {
        for (ap_int<32> args24 = 0; args24 < 32; ++args24) {
          basicblock_relu_x1[y2][args04][args14][args24] = ((ap_int<32>)((((ap_fixed<40, 32>)basicblock_bn1[y2][args04][args14][args24]) < (ap_fixed<40, 32>)0) ? (((ap_fixed<16, 8>)0)) : ((ap_fixed<16, 8>)basicblock_bn1[y2][args04][args14][args24])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu[32][64][32][32];
  for (ap_int<32> y3 = 0; y3 < 32; ++y3) {
    for (ap_int<32> args05 = 0; args05 < 64; ++args05) {
      for (ap_int<32> args15 = 0; args15 < 32; ++args15) {
        for (ap_int<32> args25 = 0; args25 < 32; ++args25) {
          basicblock_relu[y3][args05][args15][args25] = ((ap_int<32>)((1 < basicblock_relu_x1[y3][args05][args15][args25]) ? (((ap_fixed<40, 32>)((ap_fixed<16, 8>)1))) : (((ap_fixed<40, 32>)basicblock_relu_x1[y3][args05][args15][args25]))));
        }
      }
    }
  }
  ap_int<32> basicblock_conv2_pad[32][64][34][34];
  for (ap_int<32> indices2 = 0; indices2 < 32; ++indices2) {
    for (ap_int<32> not_zero2 = 0; not_zero2 < 64; ++not_zero2) {
      for (ap_int<32> index_tuple2 = 0; index_tuple2 < 34; ++index_tuple2) {
        for (ap_int<32> i2 = 0; i2 < 34; ++i2) {
          basicblock_conv2_pad[indices2][not_zero2][index_tuple2][i2] = (((((1 <= index_tuple2) && (index_tuple2 < 33)) && (1 <= i2)) && (i2 < 33)) ? ((ap_int<32>)basicblock_relu[((((((i2 - ((i2 + -1) % 32)) + (index_tuple2 * 32)) + (not_zero2 * 1024)) + (indices2 * 65536)) + -33) / 65536)][(((((((i2 - ((i2 + -1) % 32)) + (index_tuple2 * 32)) + (not_zero2 * 1024)) + (indices2 * 65536)) + -33) / 1024) % 64)][(((((((i2 - ((i2 + -1) % 32)) + (index_tuple2 * 32)) + (not_zero2 * 1024)) + (indices2 * 65536)) + -33) / 32) % 32)][((i2 + -1) % 32)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv2[32][64][32][32];
  for (ap_int<32> nn2 = 0; nn2 < 32; ++nn2) {
    for (ap_int<32> ff2 = 0; ff2 < 64; ++ff2) {
      for (ap_int<32> yy2 = 0; yy2 < 32; ++yy2) {
        for (ap_int<32> xx2 = 0; xx2 < 32; ++xx2) {
          ap_fixed<16, 8> sum2;
          sum2 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra6 = 0; ra6 < 64; ++ra6) {
            for (ap_int<32> ra7 = 0; ra7 < 3; ++ra7) {
              for (ap_int<32> ra8 = 0; ra8 < 3; ++ra8) {
                sum2 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv2_pad[nn2][ra6][(yy2 + ra7)][(xx2 + ra8)]) * ((ap_int<64>)conv2_weight2[ff2][ra6][ra7][ra8]))) + ((ap_fixed<73, 65>)sum2)));
              }
            }
          }
          basicblock_conv2[nn2][ff2][yy2][xx2] = ((ap_int<32>)sum2);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn2[32][64][32][32];
  for (ap_int<32> x2 = 0; x2 < 32; ++x2) {
    for (ap_int<32> args06 = 0; args06 < 64; ++args06) {
      for (ap_int<32> args16 = 0; args16 < 32; ++args16) {
        for (ap_int<32> args26 = 0; args26 < 32; ++args26) {
          basicblock_bn2[x2][args06][args16][args26] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn2_weight2[args26]) * ((ap_int<64>)basicblock_conv2[x2][args06][args16][args26]))) + ((ap_int<65>)bn2_bias2[args26])));
        }
      }
    }
  }
  ap_int<32> compute0[32][64][32][32];
  for (ap_int<32> i3 = 0; i3 < 32; ++i3) {
    for (ap_int<32> c = 0; c < 64; ++c) {
      for (ap_int<32> h = 0; h < 32; ++h) {
        for (ap_int<32> w = 0; w < 32; ++w) {
          compute0[i3][c][h][w] = ((ap_int<32>)(((ap_fixed<41, 33>)basicblock_bn2[i3][c][h][w]) + ((ap_fixed<41, 33>)relu[i3][c][h][w])));
        }
      }
    }
  }
  ap_int<32> bb_output_relu_x1[32][64][32][32];
  for (ap_int<32> y4 = 0; y4 < 32; ++y4) {
    for (ap_int<32> args07 = 0; args07 < 64; ++args07) {
      for (ap_int<32> args17 = 0; args17 < 32; ++args17) {
        for (ap_int<32> args27 = 0; args27 < 32; ++args27) {
          bb_output_relu_x1[y4][args07][args17][args27] = ((compute0[y4][args07][args17][args27] < 0) ? ((ap_int<32>)0) : ((ap_int<32>)compute0[y4][args07][args17][args27]));
        }
      }
    }
  }
  ap_int<32> bb_output_relu[32][64][32][32];
  for (ap_int<32> y5 = 0; y5 < 32; ++y5) {
    for (ap_int<32> args08 = 0; args08 < 64; ++args08) {
      for (ap_int<32> args18 = 0; args18 < 32; ++args18) {
        for (ap_int<32> args28 = 0; args28 < 32; ++args28) {
          bb_output_relu[y5][args08][args18][args28] = ((1 < bb_output_relu_x1[y5][args08][args18][args28]) ? ((ap_int<32>)1) : ((ap_int<32>)bb_output_relu_x1[y5][args08][args18][args28]));
        }
      }
    }
  }
  ap_int<32> basicblock_conv1_pad1[32][64][34][34];
  for (ap_int<32> indices3 = 0; indices3 < 32; ++indices3) {
    for (ap_int<32> not_zero3 = 0; not_zero3 < 64; ++not_zero3) {
      for (ap_int<32> index_tuple3 = 0; index_tuple3 < 34; ++index_tuple3) {
        for (ap_int<32> i4 = 0; i4 < 34; ++i4) {
          basicblock_conv1_pad1[indices3][not_zero3][index_tuple3][i4] = (((((1 <= index_tuple3) && (index_tuple3 < 33)) && (1 <= i4)) && (i4 < 33)) ? ((ap_int<32>)bb_output_relu[((((((i4 - ((i4 + -1) % 32)) + (index_tuple3 * 32)) + (not_zero3 * 1024)) + (indices3 * 65536)) + -33) / 65536)][(((((((i4 - ((i4 + -1) % 32)) + (index_tuple3 * 32)) + (not_zero3 * 1024)) + (indices3 * 65536)) + -33) / 1024) % 64)][(((((((i4 - ((i4 + -1) % 32)) + (index_tuple3 * 32)) + (not_zero3 * 1024)) + (indices3 * 65536)) + -33) / 32) % 32)][((i4 + -1) % 32)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv11[32][64][32][32];
  for (ap_int<32> nn3 = 0; nn3 < 32; ++nn3) {
    for (ap_int<32> ff3 = 0; ff3 < 64; ++ff3) {
      for (ap_int<32> yy3 = 0; yy3 < 32; ++yy3) {
        for (ap_int<32> xx3 = 0; xx3 < 32; ++xx3) {
          ap_fixed<16, 8> sum3;
          sum3 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra9 = 0; ra9 < 64; ++ra9) {
            for (ap_int<32> ra10 = 0; ra10 < 3; ++ra10) {
              for (ap_int<32> ra11 = 0; ra11 < 3; ++ra11) {
                sum3 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv1_pad1[nn3][ra9][(yy3 + ra10)][(xx3 + ra11)]) * ((ap_int<64>)conv2_weight11[ff3][ra9][ra10][ra11]))) + ((ap_fixed<73, 65>)sum3)));
              }
            }
          }
          basicblock_conv11[nn3][ff3][yy3][xx3] = ((ap_int<32>)sum3);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn11[32][64][32][32];
  for (ap_int<32> x3 = 0; x3 < 32; ++x3) {
    for (ap_int<32> args09 = 0; args09 < 64; ++args09) {
      for (ap_int<32> args19 = 0; args19 < 32; ++args19) {
        for (ap_int<32> args29 = 0; args29 < 32; ++args29) {
          basicblock_bn11[x3][args09][args19][args29] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn2_weight11[args29]) * ((ap_int<64>)basicblock_conv11[x3][args09][args19][args29]))) + ((ap_int<65>)bn2_bias11[args29])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu_x11[32][64][32][32];
  for (ap_int<32> y6 = 0; y6 < 32; ++y6) {
    for (ap_int<32> args010 = 0; args010 < 64; ++args010) {
      for (ap_int<32> args110 = 0; args110 < 32; ++args110) {
        for (ap_int<32> args210 = 0; args210 < 32; ++args210) {
          basicblock_relu_x11[y6][args010][args110][args210] = ((ap_int<32>)((((ap_fixed<40, 32>)basicblock_bn11[y6][args010][args110][args210]) < (ap_fixed<40, 32>)0) ? (((ap_fixed<16, 8>)0)) : ((ap_fixed<16, 8>)basicblock_bn11[y6][args010][args110][args210])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu1[32][64][32][32];
  for (ap_int<32> y7 = 0; y7 < 32; ++y7) {
    for (ap_int<32> args011 = 0; args011 < 64; ++args011) {
      for (ap_int<32> args111 = 0; args111 < 32; ++args111) {
        for (ap_int<32> args211 = 0; args211 < 32; ++args211) {
          basicblock_relu1[y7][args011][args111][args211] = ((ap_int<32>)((1 < basicblock_relu_x11[y7][args011][args111][args211]) ? (((ap_fixed<40, 32>)((ap_fixed<16, 8>)1))) : (((ap_fixed<40, 32>)basicblock_relu_x11[y7][args011][args111][args211]))));
        }
      }
    }
  }
  ap_int<32> basicblock_conv2_pad1[32][64][34][34];
  for (ap_int<32> indices4 = 0; indices4 < 32; ++indices4) {
    for (ap_int<32> not_zero4 = 0; not_zero4 < 64; ++not_zero4) {
      for (ap_int<32> index_tuple4 = 0; index_tuple4 < 34; ++index_tuple4) {
        for (ap_int<32> i5 = 0; i5 < 34; ++i5) {
          basicblock_conv2_pad1[indices4][not_zero4][index_tuple4][i5] = (((((1 <= index_tuple4) && (index_tuple4 < 33)) && (1 <= i5)) && (i5 < 33)) ? ((ap_int<32>)basicblock_relu1[((((((i5 - ((i5 + -1) % 32)) + (index_tuple4 * 32)) + (not_zero4 * 1024)) + (indices4 * 65536)) + -33) / 65536)][(((((((i5 - ((i5 + -1) % 32)) + (index_tuple4 * 32)) + (not_zero4 * 1024)) + (indices4 * 65536)) + -33) / 1024) % 64)][(((((((i5 - ((i5 + -1) % 32)) + (index_tuple4 * 32)) + (not_zero4 * 1024)) + (indices4 * 65536)) + -33) / 32) % 32)][((i5 + -1) % 32)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv21[32][64][32][32];
  for (ap_int<32> nn4 = 0; nn4 < 32; ++nn4) {
    for (ap_int<32> ff4 = 0; ff4 < 64; ++ff4) {
      for (ap_int<32> yy4 = 0; yy4 < 32; ++yy4) {
        for (ap_int<32> xx4 = 0; xx4 < 32; ++xx4) {
          ap_fixed<16, 8> sum4;
          sum4 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra12 = 0; ra12 < 64; ++ra12) {
            for (ap_int<32> ra13 = 0; ra13 < 3; ++ra13) {
              for (ap_int<32> ra14 = 0; ra14 < 3; ++ra14) {
                sum4 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv2_pad1[nn4][ra12][(yy4 + ra13)][(xx4 + ra14)]) * ((ap_int<64>)conv2_weight21[ff4][ra12][ra13][ra14]))) + ((ap_fixed<73, 65>)sum4)));
              }
            }
          }
          basicblock_conv21[nn4][ff4][yy4][xx4] = ((ap_int<32>)sum4);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn21[32][64][32][32];
  for (ap_int<32> x4 = 0; x4 < 32; ++x4) {
    for (ap_int<32> args012 = 0; args012 < 64; ++args012) {
      for (ap_int<32> args112 = 0; args112 < 32; ++args112) {
        for (ap_int<32> args212 = 0; args212 < 32; ++args212) {
          basicblock_bn21[x4][args012][args112][args212] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn2_weight21[args212]) * ((ap_int<64>)basicblock_conv21[x4][args012][args112][args212]))) + ((ap_int<65>)bn2_bias21[args212])));
        }
      }
    }
  }
  ap_int<32> compute1[32][64][32][32];
  for (ap_int<32> i6 = 0; i6 < 32; ++i6) {
    for (ap_int<32> c1 = 0; c1 < 64; ++c1) {
      for (ap_int<32> h1 = 0; h1 < 32; ++h1) {
        for (ap_int<32> w1 = 0; w1 < 32; ++w1) {
          compute1[i6][c1][h1][w1] = ((ap_int<32>)(((ap_fixed<41, 33>)basicblock_bn21[i6][c1][h1][w1]) + ((ap_fixed<41, 33>)bb_output_relu[i6][c1][h1][w1])));
        }
      }
    }
  }
  ap_int<32> bb_output_relu_x11[32][64][32][32];
  for (ap_int<32> y8 = 0; y8 < 32; ++y8) {
    for (ap_int<32> args013 = 0; args013 < 64; ++args013) {
      for (ap_int<32> args113 = 0; args113 < 32; ++args113) {
        for (ap_int<32> args213 = 0; args213 < 32; ++args213) {
          bb_output_relu_x11[y8][args013][args113][args213] = ((compute1[y8][args013][args113][args213] < 0) ? ((ap_int<32>)0) : ((ap_int<32>)compute1[y8][args013][args113][args213]));
        }
      }
    }
  }
  ap_int<32> bb_output_relu1[32][64][32][32];
  for (ap_int<32> y9 = 0; y9 < 32; ++y9) {
    for (ap_int<32> args014 = 0; args014 < 64; ++args014) {
      for (ap_int<32> args114 = 0; args114 < 32; ++args114) {
        for (ap_int<32> args214 = 0; args214 < 32; ++args214) {
          bb_output_relu1[y9][args014][args114][args214] = ((1 < bb_output_relu_x11[y9][args014][args114][args214]) ? ((ap_int<32>)1) : ((ap_int<32>)bb_output_relu_x11[y9][args014][args114][args214]));
        }
      }
    }
  }
  ap_int<32> basicblock_conv1_pad2[32][64][34][34];
  for (ap_int<32> indices5 = 0; indices5 < 32; ++indices5) {
    for (ap_int<32> not_zero5 = 0; not_zero5 < 64; ++not_zero5) {
      for (ap_int<32> index_tuple5 = 0; index_tuple5 < 34; ++index_tuple5) {
        for (ap_int<32> i7 = 0; i7 < 34; ++i7) {
          basicblock_conv1_pad2[indices5][not_zero5][index_tuple5][i7] = (((((1 <= index_tuple5) && (index_tuple5 < 33)) && (1 <= i7)) && (i7 < 33)) ? ((ap_int<32>)bb_output_relu1[((((((i7 - ((i7 + -1) % 32)) + (index_tuple5 * 32)) + (not_zero5 * 1024)) + (indices5 * 65536)) + -33) / 65536)][(((((((i7 - ((i7 + -1) % 32)) + (index_tuple5 * 32)) + (not_zero5 * 1024)) + (indices5 * 65536)) + -33) / 1024) % 64)][(((((((i7 - ((i7 + -1) % 32)) + (index_tuple5 * 32)) + (not_zero5 * 1024)) + (indices5 * 65536)) + -33) / 32) % 32)][((i7 + -1) % 32)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv12[32][64][16][16];
  for (ap_int<32> nn5 = 0; nn5 < 32; ++nn5) {
    for (ap_int<32> ff5 = 0; ff5 < 64; ++ff5) {
      for (ap_int<32> yy5 = 0; yy5 < 16; ++yy5) {
        for (ap_int<32> xx5 = 0; xx5 < 16; ++xx5) {
          ap_fixed<16, 8> sum5;
          sum5 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra15 = 0; ra15 < 64; ++ra15) {
            for (ap_int<32> ra16 = 0; ra16 < 3; ++ra16) {
              for (ap_int<32> ra17 = 0; ra17 < 3; ++ra17) {
                sum5 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv1_pad2[nn5][ra15][((yy5 * 2) + ra16)][((xx5 * 2) + ra17)]) * ((ap_int<64>)conv3_weight1[ff5][ra15][ra16][ra17]))) + ((ap_fixed<73, 65>)sum5)));
              }
            }
          }
          basicblock_conv12[nn5][ff5][yy5][xx5] = ((ap_int<32>)sum5);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn12[32][64][16][16];
  for (ap_int<32> x5 = 0; x5 < 32; ++x5) {
    for (ap_int<32> args015 = 0; args015 < 64; ++args015) {
      for (ap_int<32> args115 = 0; args115 < 16; ++args115) {
        for (ap_int<32> args215 = 0; args215 < 16; ++args215) {
          basicblock_bn12[x5][args015][args115][args215] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn3_weight1[args215]) * ((ap_int<64>)basicblock_conv12[x5][args015][args115][args215]))) + ((ap_int<65>)bn3_bias1[args215])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu_x12[32][64][16][16];
  for (ap_int<32> y10 = 0; y10 < 32; ++y10) {
    for (ap_int<32> args016 = 0; args016 < 64; ++args016) {
      for (ap_int<32> args116 = 0; args116 < 16; ++args116) {
        for (ap_int<32> args216 = 0; args216 < 16; ++args216) {
          basicblock_relu_x12[y10][args016][args116][args216] = ((ap_int<32>)((((ap_fixed<40, 32>)basicblock_bn12[y10][args016][args116][args216]) < (ap_fixed<40, 32>)0) ? (((ap_fixed<16, 8>)0)) : ((ap_fixed<16, 8>)basicblock_bn12[y10][args016][args116][args216])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu2[32][64][16][16];
  for (ap_int<32> y11 = 0; y11 < 32; ++y11) {
    for (ap_int<32> args017 = 0; args017 < 64; ++args017) {
      for (ap_int<32> args117 = 0; args117 < 16; ++args117) {
        for (ap_int<32> args217 = 0; args217 < 16; ++args217) {
          basicblock_relu2[y11][args017][args117][args217] = ((ap_int<32>)((1 < basicblock_relu_x12[y11][args017][args117][args217]) ? (((ap_fixed<40, 32>)((ap_fixed<16, 8>)1))) : (((ap_fixed<40, 32>)basicblock_relu_x12[y11][args017][args117][args217]))));
        }
      }
    }
  }
  ap_int<32> basicblock_conv2_pad2[32][64][18][18];
  for (ap_int<32> indices6 = 0; indices6 < 32; ++indices6) {
    for (ap_int<32> not_zero6 = 0; not_zero6 < 64; ++not_zero6) {
      for (ap_int<32> index_tuple6 = 0; index_tuple6 < 18; ++index_tuple6) {
        for (ap_int<32> i8 = 0; i8 < 18; ++i8) {
          basicblock_conv2_pad2[indices6][not_zero6][index_tuple6][i8] = (((((1 <= index_tuple6) && (index_tuple6 < 17)) && (1 <= i8)) && (i8 < 17)) ? ((ap_int<32>)basicblock_relu2[((((((i8 - ((i8 + -1) % 16)) + (index_tuple6 * 16)) + (not_zero6 * 256)) + (indices6 * 16384)) + -17) / 16384)][(((((((i8 - ((i8 + -1) % 16)) + (index_tuple6 * 16)) + (not_zero6 * 256)) + (indices6 * 16384)) + -17) / 256) % 64)][(((((((i8 - ((i8 + -1) % 16)) + (index_tuple6 * 16)) + (not_zero6 * 256)) + (indices6 * 16384)) + -17) / 16) % 16)][((i8 + -1) % 16)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv22[32][64][16][16];
  for (ap_int<32> nn6 = 0; nn6 < 32; ++nn6) {
    for (ap_int<32> ff6 = 0; ff6 < 64; ++ff6) {
      for (ap_int<32> yy6 = 0; yy6 < 16; ++yy6) {
        for (ap_int<32> xx6 = 0; xx6 < 16; ++xx6) {
          ap_fixed<16, 8> sum6;
          sum6 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra18 = 0; ra18 < 64; ++ra18) {
            for (ap_int<32> ra19 = 0; ra19 < 3; ++ra19) {
              for (ap_int<32> ra20 = 0; ra20 < 3; ++ra20) {
                sum6 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv2_pad2[nn6][ra18][(yy6 + ra19)][(xx6 + ra20)]) * ((ap_int<64>)conv3_weight2[ff6][ra18][ra19][ra20]))) + ((ap_fixed<73, 65>)sum6)));
              }
            }
          }
          basicblock_conv22[nn6][ff6][yy6][xx6] = ((ap_int<32>)sum6);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn22[32][64][16][16];
  for (ap_int<32> x6 = 0; x6 < 32; ++x6) {
    for (ap_int<32> args018 = 0; args018 < 64; ++args018) {
      for (ap_int<32> args118 = 0; args118 < 16; ++args118) {
        for (ap_int<32> args218 = 0; args218 < 16; ++args218) {
          basicblock_bn22[x6][args018][args118][args218] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn3_weight2[args218]) * ((ap_int<64>)basicblock_conv22[x6][args018][args118][args218]))) + ((ap_int<65>)bn3_bias2[args218])));
        }
      }
    }
  }
  ap_int<32> basicblock_conv_shortcut_pad[32][64][34][34];
  for (ap_int<32> indices7 = 0; indices7 < 32; ++indices7) {
    for (ap_int<32> not_zero7 = 0; not_zero7 < 64; ++not_zero7) {
      for (ap_int<32> index_tuple7 = 0; index_tuple7 < 34; ++index_tuple7) {
        for (ap_int<32> i9 = 0; i9 < 34; ++i9) {
          basicblock_conv_shortcut_pad[indices7][not_zero7][index_tuple7][i9] = (((((1 <= index_tuple7) && (index_tuple7 < 33)) && (1 <= i9)) && (i9 < 33)) ? ((ap_int<32>)bb_output_relu1[((((((i9 - ((i9 + -1) % 32)) + (index_tuple7 * 32)) + (not_zero7 * 1024)) + (indices7 * 65536)) + -33) / 65536)][(((((((i9 - ((i9 + -1) % 32)) + (index_tuple7 * 32)) + (not_zero7 * 1024)) + (indices7 * 65536)) + -33) / 1024) % 64)][(((((((i9 - ((i9 + -1) % 32)) + (index_tuple7 * 32)) + (not_zero7 * 1024)) + (indices7 * 65536)) + -33) / 32) % 32)][((i9 + -1) % 32)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv_shortcut[32][64][17][17];
  for (ap_int<32> nn7 = 0; nn7 < 32; ++nn7) {
    for (ap_int<32> ff7 = 0; ff7 < 64; ++ff7) {
      for (ap_int<32> yy7 = 0; yy7 < 17; ++yy7) {
        for (ap_int<32> xx7 = 0; xx7 < 17; ++xx7) {
          ap_fixed<16, 8> sum7;
          sum7 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra21 = 0; ra21 < 64; ++ra21) {
            sum7 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv_shortcut_pad[nn7][ra21][((xx7 / 17) + (yy7 * 2))][(((((xx7 + (yy7 * 34)) + (ra21 * 578)) + (nn7 * 36992)) * 2) % 34)]) * ((ap_int<64>)conv3_shortcut_weight[ff7][ra21][0][0]))) + ((ap_fixed<73, 65>)sum7)));
          }
          basicblock_conv_shortcut[nn7][ff7][yy7][xx7] = ((ap_int<32>)sum7);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn_shortcut[32][64][17][17];
  for (ap_int<32> x7 = 0; x7 < 32; ++x7) {
    for (ap_int<32> args019 = 0; args019 < 64; ++args019) {
      for (ap_int<32> args119 = 0; args119 < 17; ++args119) {
        for (ap_int<32> args219 = 0; args219 < 17; ++args219) {
          basicblock_bn_shortcut[x7][args019][args119][args219] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn3_shortcut_weight[args219]) * ((ap_int<64>)basicblock_conv_shortcut[x7][args019][args119][args219]))) + ((ap_int<65>)bn3_shortcut_bias[args219])));
        }
      }
    }
  }
  ap_int<32> compute2[32][64][17][17];
  for (ap_int<32> i10 = 0; i10 < 32; ++i10) {
    for (ap_int<32> c2 = 0; c2 < 64; ++c2) {
      for (ap_int<32> h2 = 0; h2 < 17; ++h2) {
        for (ap_int<32> w2 = 0; w2 < 17; ++w2) {
          compute2[i10][c2][h2][w2] = ((ap_int<32>)(((ap_fixed<17, 9>)basicblock_bn22[((((((((w2 / 16) - (((w2 / 16) + h2) % 16)) + h2) / 16) - ((((((w2 / 16) - (((w2 / 16) + h2) % 16)) + h2) / 16) + c2) % 64)) + c2) / 64) + i10)][((((((w2 / 16) - (((w2 / 16) + h2) % 16)) + h2) / 16) + c2) % 64)][(((w2 / 16) + h2) % 16)][(w2 % 16)]) + ((ap_fixed<17, 9>)basicblock_bn_shortcut[i10][c2][h2][w2])));
        }
      }
    }
  }
  ap_int<32> bb_output_relu_x12[32][64][17][17];
  for (ap_int<32> y12 = 0; y12 < 32; ++y12) {
    for (ap_int<32> args020 = 0; args020 < 64; ++args020) {
      for (ap_int<32> args120 = 0; args120 < 17; ++args120) {
        for (ap_int<32> args220 = 0; args220 < 17; ++args220) {
          bb_output_relu_x12[y12][args020][args120][args220] = ((compute2[y12][args020][args120][args220] < 0) ? ((ap_int<32>)0) : ((ap_int<32>)compute2[y12][args020][args120][args220]));
        }
      }
    }
  }
  ap_int<32> bb_output_relu2[32][64][17][17];
  for (ap_int<32> y13 = 0; y13 < 32; ++y13) {
    for (ap_int<32> args021 = 0; args021 < 64; ++args021) {
      for (ap_int<32> args121 = 0; args121 < 17; ++args121) {
        for (ap_int<32> args221 = 0; args221 < 17; ++args221) {
          bb_output_relu2[y13][args021][args121][args221] = ((1 < bb_output_relu_x12[y13][args021][args121][args221]) ? ((ap_int<32>)1) : ((ap_int<32>)bb_output_relu_x12[y13][args021][args121][args221]));
        }
      }
    }
  }
  ap_int<32> basicblock_conv1_pad3[32][64][19][19];
  for (ap_int<32> indices8 = 0; indices8 < 32; ++indices8) {
    for (ap_int<32> not_zero8 = 0; not_zero8 < 64; ++not_zero8) {
      for (ap_int<32> index_tuple8 = 0; index_tuple8 < 19; ++index_tuple8) {
        for (ap_int<32> i11 = 0; i11 < 19; ++i11) {
          basicblock_conv1_pad3[indices8][not_zero8][index_tuple8][i11] = (((((1 <= index_tuple8) && (index_tuple8 < 18)) && (1 <= i11)) && (i11 < 18)) ? ((ap_int<32>)bb_output_relu2[((((((i11 - ((i11 + -1) % 17)) + (index_tuple8 * 17)) + (not_zero8 * 289)) + (indices8 * 18496)) + -18) / 18496)][(((((((i11 - ((i11 + -1) % 17)) + (index_tuple8 * 17)) + (not_zero8 * 289)) + (indices8 * 18496)) + -18) / 289) % 64)][(((((((i11 - ((i11 + -1) % 17)) + (index_tuple8 * 17)) + (not_zero8 * 289)) + (indices8 * 18496)) + -18) / 17) % 17)][((i11 + -1) % 17)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv13[32][64][17][17];
  for (ap_int<32> nn8 = 0; nn8 < 32; ++nn8) {
    for (ap_int<32> ff8 = 0; ff8 < 64; ++ff8) {
      for (ap_int<32> yy8 = 0; yy8 < 17; ++yy8) {
        for (ap_int<32> xx8 = 0; xx8 < 17; ++xx8) {
          ap_fixed<16, 8> sum8;
          sum8 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra24 = 0; ra24 < 64; ++ra24) {
            for (ap_int<32> ra25 = 0; ra25 < 3; ++ra25) {
              for (ap_int<32> ra26 = 0; ra26 < 3; ++ra26) {
                sum8 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv1_pad3[nn8][ra24][(yy8 + ra25)][(xx8 + ra26)]) * ((ap_int<64>)conv3_weight11[ff8][ra24][ra25][ra26]))) + ((ap_fixed<73, 65>)sum8)));
              }
            }
          }
          basicblock_conv13[nn8][ff8][yy8][xx8] = ((ap_int<32>)sum8);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn13[32][64][17][17];
  for (ap_int<32> x8 = 0; x8 < 32; ++x8) {
    for (ap_int<32> args022 = 0; args022 < 64; ++args022) {
      for (ap_int<32> args122 = 0; args122 < 17; ++args122) {
        for (ap_int<32> args222 = 0; args222 < 17; ++args222) {
          basicblock_bn13[x8][args022][args122][args222] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn3_weight11[args222]) * ((ap_int<64>)basicblock_conv13[x8][args022][args122][args222]))) + ((ap_int<65>)bn3_bias11[args222])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu_x13[32][64][17][17];
  for (ap_int<32> y14 = 0; y14 < 32; ++y14) {
    for (ap_int<32> args023 = 0; args023 < 64; ++args023) {
      for (ap_int<32> args123 = 0; args123 < 17; ++args123) {
        for (ap_int<32> args223 = 0; args223 < 17; ++args223) {
          basicblock_relu_x13[y14][args023][args123][args223] = ((ap_int<32>)((((ap_fixed<40, 32>)basicblock_bn13[y14][args023][args123][args223]) < (ap_fixed<40, 32>)0) ? (((ap_fixed<16, 8>)0)) : ((ap_fixed<16, 8>)basicblock_bn13[y14][args023][args123][args223])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu3[32][64][17][17];
  for (ap_int<32> y15 = 0; y15 < 32; ++y15) {
    for (ap_int<32> args024 = 0; args024 < 64; ++args024) {
      for (ap_int<32> args124 = 0; args124 < 17; ++args124) {
        for (ap_int<32> args224 = 0; args224 < 17; ++args224) {
          basicblock_relu3[y15][args024][args124][args224] = ((ap_int<32>)((1 < basicblock_relu_x13[y15][args024][args124][args224]) ? (((ap_fixed<40, 32>)((ap_fixed<16, 8>)1))) : (((ap_fixed<40, 32>)basicblock_relu_x13[y15][args024][args124][args224]))));
        }
      }
    }
  }
  ap_int<32> basicblock_conv2_pad3[32][64][19][19];
  for (ap_int<32> indices9 = 0; indices9 < 32; ++indices9) {
    for (ap_int<32> not_zero9 = 0; not_zero9 < 64; ++not_zero9) {
      for (ap_int<32> index_tuple9 = 0; index_tuple9 < 19; ++index_tuple9) {
        for (ap_int<32> i12 = 0; i12 < 19; ++i12) {
          basicblock_conv2_pad3[indices9][not_zero9][index_tuple9][i12] = (((((1 <= index_tuple9) && (index_tuple9 < 18)) && (1 <= i12)) && (i12 < 18)) ? ((ap_int<32>)basicblock_relu3[((((((i12 - ((i12 + -1) % 17)) + (index_tuple9 * 17)) + (not_zero9 * 289)) + (indices9 * 18496)) + -18) / 18496)][(((((((i12 - ((i12 + -1) % 17)) + (index_tuple9 * 17)) + (not_zero9 * 289)) + (indices9 * 18496)) + -18) / 289) % 64)][(((((((i12 - ((i12 + -1) % 17)) + (index_tuple9 * 17)) + (not_zero9 * 289)) + (indices9 * 18496)) + -18) / 17) % 17)][((i12 + -1) % 17)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv23[32][64][17][17];
  for (ap_int<32> nn9 = 0; nn9 < 32; ++nn9) {
    for (ap_int<32> ff9 = 0; ff9 < 64; ++ff9) {
      for (ap_int<32> yy9 = 0; yy9 < 17; ++yy9) {
        for (ap_int<32> xx9 = 0; xx9 < 17; ++xx9) {
          ap_fixed<16, 8> sum9;
          sum9 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra27 = 0; ra27 < 64; ++ra27) {
            for (ap_int<32> ra28 = 0; ra28 < 3; ++ra28) {
              for (ap_int<32> ra29 = 0; ra29 < 3; ++ra29) {
                sum9 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv2_pad3[nn9][ra27][(yy9 + ra28)][(xx9 + ra29)]) * ((ap_int<64>)conv3_weight21[ff9][ra27][ra28][ra29]))) + ((ap_fixed<73, 65>)sum9)));
              }
            }
          }
          basicblock_conv23[nn9][ff9][yy9][xx9] = ((ap_int<32>)sum9);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn23[32][64][17][17];
  for (ap_int<32> x9 = 0; x9 < 32; ++x9) {
    for (ap_int<32> args025 = 0; args025 < 64; ++args025) {
      for (ap_int<32> args125 = 0; args125 < 17; ++args125) {
        for (ap_int<32> args225 = 0; args225 < 17; ++args225) {
          basicblock_bn23[x9][args025][args125][args225] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn3_weight21[args225]) * ((ap_int<64>)basicblock_conv23[x9][args025][args125][args225]))) + ((ap_int<65>)bn3_bias21[args225])));
        }
      }
    }
  }
  ap_int<32> compute3[32][64][17][17];
  for (ap_int<32> i13 = 0; i13 < 32; ++i13) {
    for (ap_int<32> c3 = 0; c3 < 64; ++c3) {
      for (ap_int<32> h3 = 0; h3 < 17; ++h3) {
        for (ap_int<32> w3 = 0; w3 < 17; ++w3) {
          compute3[i13][c3][h3][w3] = ((ap_int<32>)(((ap_fixed<41, 33>)basicblock_bn23[i13][c3][h3][w3]) + ((ap_fixed<41, 33>)bb_output_relu2[i13][c3][h3][w3])));
        }
      }
    }
  }
  ap_int<32> bb_output_relu_x13[32][64][17][17];
  for (ap_int<32> y16 = 0; y16 < 32; ++y16) {
    for (ap_int<32> args026 = 0; args026 < 64; ++args026) {
      for (ap_int<32> args126 = 0; args126 < 17; ++args126) {
        for (ap_int<32> args226 = 0; args226 < 17; ++args226) {
          bb_output_relu_x13[y16][args026][args126][args226] = ((compute3[y16][args026][args126][args226] < 0) ? ((ap_int<32>)0) : ((ap_int<32>)compute3[y16][args026][args126][args226]));
        }
      }
    }
  }
  ap_int<32> bb_output_relu3[32][64][17][17];
  for (ap_int<32> y17 = 0; y17 < 32; ++y17) {
    for (ap_int<32> args027 = 0; args027 < 64; ++args027) {
      for (ap_int<32> args127 = 0; args127 < 17; ++args127) {
        for (ap_int<32> args227 = 0; args227 < 17; ++args227) {
          bb_output_relu3[y17][args027][args127][args227] = ((1 < bb_output_relu_x13[y17][args027][args127][args227]) ? ((ap_int<32>)1) : ((ap_int<32>)bb_output_relu_x13[y17][args027][args127][args227]));
        }
      }
    }
  }
  ap_int<32> basicblock_conv1_pad4[32][64][19][19];
  for (ap_int<32> indices10 = 0; indices10 < 32; ++indices10) {
    for (ap_int<32> not_zero10 = 0; not_zero10 < 64; ++not_zero10) {
      for (ap_int<32> index_tuple10 = 0; index_tuple10 < 19; ++index_tuple10) {
        for (ap_int<32> i14 = 0; i14 < 19; ++i14) {
          basicblock_conv1_pad4[indices10][not_zero10][index_tuple10][i14] = (((((1 <= index_tuple10) && (index_tuple10 < 18)) && (1 <= i14)) && (i14 < 18)) ? ((ap_int<32>)bb_output_relu3[((((((i14 - ((i14 + -1) % 17)) + (index_tuple10 * 17)) + (not_zero10 * 289)) + (indices10 * 18496)) + -18) / 18496)][(((((((i14 - ((i14 + -1) % 17)) + (index_tuple10 * 17)) + (not_zero10 * 289)) + (indices10 * 18496)) + -18) / 289) % 64)][(((((((i14 - ((i14 + -1) % 17)) + (index_tuple10 * 17)) + (not_zero10 * 289)) + (indices10 * 18496)) + -18) / 17) % 17)][((i14 + -1) % 17)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv14[32][64][9][9];
  for (ap_int<32> nn10 = 0; nn10 < 32; ++nn10) {
    for (ap_int<32> ff10 = 0; ff10 < 64; ++ff10) {
      for (ap_int<32> yy10 = 0; yy10 < 9; ++yy10) {
        for (ap_int<32> xx10 = 0; xx10 < 9; ++xx10) {
          ap_fixed<16, 8> sum10;
          sum10 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra30 = 0; ra30 < 64; ++ra30) {
            for (ap_int<32> ra31 = 0; ra31 < 3; ++ra31) {
              for (ap_int<32> ra32 = 0; ra32 < 3; ++ra32) {
                sum10 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv1_pad4[nn10][ra30][((yy10 * 2) + ra31)][((xx10 * 2) + ra32)]) * ((ap_int<64>)conv4_weight1[ff10][ra30][ra31][ra32]))) + ((ap_fixed<73, 65>)sum10)));
              }
            }
          }
          basicblock_conv14[nn10][ff10][yy10][xx10] = ((ap_int<32>)sum10);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn14[32][64][9][9];
  for (ap_int<32> x10 = 0; x10 < 32; ++x10) {
    for (ap_int<32> args028 = 0; args028 < 64; ++args028) {
      for (ap_int<32> args128 = 0; args128 < 9; ++args128) {
        for (ap_int<32> args228 = 0; args228 < 9; ++args228) {
          basicblock_bn14[x10][args028][args128][args228] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn4_weight1[args228]) * ((ap_int<64>)basicblock_conv14[x10][args028][args128][args228]))) + ((ap_int<65>)bn4_bias1[args228])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu_x14[32][64][9][9];
  for (ap_int<32> y18 = 0; y18 < 32; ++y18) {
    for (ap_int<32> args029 = 0; args029 < 64; ++args029) {
      for (ap_int<32> args129 = 0; args129 < 9; ++args129) {
        for (ap_int<32> args229 = 0; args229 < 9; ++args229) {
          basicblock_relu_x14[y18][args029][args129][args229] = ((ap_int<32>)((((ap_fixed<40, 32>)basicblock_bn14[y18][args029][args129][args229]) < (ap_fixed<40, 32>)0) ? (((ap_fixed<16, 8>)0)) : ((ap_fixed<16, 8>)basicblock_bn14[y18][args029][args129][args229])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu4[32][64][9][9];
  for (ap_int<32> y19 = 0; y19 < 32; ++y19) {
    for (ap_int<32> args030 = 0; args030 < 64; ++args030) {
      for (ap_int<32> args130 = 0; args130 < 9; ++args130) {
        for (ap_int<32> args230 = 0; args230 < 9; ++args230) {
          basicblock_relu4[y19][args030][args130][args230] = ((ap_int<32>)((1 < basicblock_relu_x14[y19][args030][args130][args230]) ? (((ap_fixed<40, 32>)((ap_fixed<16, 8>)1))) : (((ap_fixed<40, 32>)basicblock_relu_x14[y19][args030][args130][args230]))));
        }
      }
    }
  }
  ap_int<32> basicblock_conv2_pad4[32][64][11][11];
  for (ap_int<32> indices11 = 0; indices11 < 32; ++indices11) {
    for (ap_int<32> not_zero11 = 0; not_zero11 < 64; ++not_zero11) {
      for (ap_int<32> index_tuple11 = 0; index_tuple11 < 11; ++index_tuple11) {
        for (ap_int<32> i15 = 0; i15 < 11; ++i15) {
          basicblock_conv2_pad4[indices11][not_zero11][index_tuple11][i15] = (((((1 <= index_tuple11) && (index_tuple11 < 10)) && (1 <= i15)) && (i15 < 10)) ? ((ap_int<32>)basicblock_relu4[((((((i15 - ((i15 + -1) % 9)) + (index_tuple11 * 9)) + (not_zero11 * 81)) + (indices11 * 5184)) + -10) / 5184)][(((((((i15 - ((i15 + -1) % 9)) + (index_tuple11 * 9)) + (not_zero11 * 81)) + (indices11 * 5184)) + -10) / 81) % 64)][(((((((i15 - ((i15 + -1) % 9)) + (index_tuple11 * 9)) + (not_zero11 * 81)) + (indices11 * 5184)) + -10) / 9) % 9)][((i15 + -1) % 9)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv24[32][64][9][9];
  for (ap_int<32> nn11 = 0; nn11 < 32; ++nn11) {
    for (ap_int<32> ff11 = 0; ff11 < 64; ++ff11) {
      for (ap_int<32> yy11 = 0; yy11 < 9; ++yy11) {
        for (ap_int<32> xx11 = 0; xx11 < 9; ++xx11) {
          ap_fixed<16, 8> sum11;
          sum11 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra33 = 0; ra33 < 64; ++ra33) {
            for (ap_int<32> ra34 = 0; ra34 < 3; ++ra34) {
              for (ap_int<32> ra35 = 0; ra35 < 3; ++ra35) {
                sum11 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv2_pad4[nn11][ra33][(yy11 + ra34)][(xx11 + ra35)]) * ((ap_int<64>)conv4_weight2[ff11][ra33][ra34][ra35]))) + ((ap_fixed<73, 65>)sum11)));
              }
            }
          }
          basicblock_conv24[nn11][ff11][yy11][xx11] = ((ap_int<32>)sum11);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn24[32][64][9][9];
  for (ap_int<32> x11 = 0; x11 < 32; ++x11) {
    for (ap_int<32> args031 = 0; args031 < 64; ++args031) {
      for (ap_int<32> args131 = 0; args131 < 9; ++args131) {
        for (ap_int<32> args231 = 0; args231 < 9; ++args231) {
          basicblock_bn24[x11][args031][args131][args231] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn4_weight2[args231]) * ((ap_int<64>)basicblock_conv24[x11][args031][args131][args231]))) + ((ap_int<65>)bn4_bias2[args231])));
        }
      }
    }
  }
  ap_int<32> basicblock_conv_shortcut_pad1[32][64][19][19];
  for (ap_int<32> indices12 = 0; indices12 < 32; ++indices12) {
    for (ap_int<32> not_zero12 = 0; not_zero12 < 64; ++not_zero12) {
      for (ap_int<32> index_tuple12 = 0; index_tuple12 < 19; ++index_tuple12) {
        for (ap_int<32> i16 = 0; i16 < 19; ++i16) {
          basicblock_conv_shortcut_pad1[indices12][not_zero12][index_tuple12][i16] = (((((1 <= index_tuple12) && (index_tuple12 < 18)) && (1 <= i16)) && (i16 < 18)) ? ((ap_int<32>)bb_output_relu3[((((((i16 - ((i16 + -1) % 17)) + (index_tuple12 * 17)) + (not_zero12 * 289)) + (indices12 * 18496)) + -18) / 18496)][(((((((i16 - ((i16 + -1) % 17)) + (index_tuple12 * 17)) + (not_zero12 * 289)) + (indices12 * 18496)) + -18) / 289) % 64)][(((((((i16 - ((i16 + -1) % 17)) + (index_tuple12 * 17)) + (not_zero12 * 289)) + (indices12 * 18496)) + -18) / 17) % 17)][((i16 + -1) % 17)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv_shortcut1[32][64][10][10];
  for (ap_int<32> nn12 = 0; nn12 < 32; ++nn12) {
    for (ap_int<32> ff12 = 0; ff12 < 64; ++ff12) {
      for (ap_int<32> yy12 = 0; yy12 < 10; ++yy12) {
        for (ap_int<32> xx12 = 0; xx12 < 10; ++xx12) {
          ap_fixed<16, 8> sum12;
          sum12 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra36 = 0; ra36 < 64; ++ra36) {
            sum12 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv_shortcut_pad1[nn12][ra36][(((xx12 + (yy12 * 19)) * 2) / 19)][(((xx12 + (yy12 * 19)) * 2) % 19)]) * ((ap_int<64>)conv4_shortcut_weight[ff12][ra36][0][0]))) + ((ap_fixed<73, 65>)sum12)));
          }
          basicblock_conv_shortcut1[nn12][ff12][yy12][xx12] = ((ap_int<32>)sum12);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn_shortcut1[32][64][10][10];
  for (ap_int<32> x12 = 0; x12 < 32; ++x12) {
    for (ap_int<32> args032 = 0; args032 < 64; ++args032) {
      for (ap_int<32> args132 = 0; args132 < 10; ++args132) {
        for (ap_int<32> args232 = 0; args232 < 10; ++args232) {
          basicblock_bn_shortcut1[x12][args032][args132][args232] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn4_shortcut_weight[args232]) * ((ap_int<64>)basicblock_conv_shortcut1[x12][args032][args132][args232]))) + ((ap_int<65>)bn4_shortcut_bias[args232])));
        }
      }
    }
  }
  ap_int<32> compute4[32][64][10][10];
  for (ap_int<32> i17 = 0; i17 < 32; ++i17) {
    for (ap_int<32> c4 = 0; c4 < 64; ++c4) {
      for (ap_int<32> h4 = 0; h4 < 10; ++h4) {
        for (ap_int<32> w4 = 0; w4 < 10; ++w4) {
          compute4[i17][c4][h4][w4] = ((ap_int<32>)(((ap_fixed<17, 9>)basicblock_bn24[((((((((w4 / 9) - (((w4 / 9) + h4) % 9)) + h4) / 9) - ((((((w4 / 9) - (((w4 / 9) + h4) % 9)) + h4) / 9) + c4) % 64)) + c4) / 64) + i17)][((((((w4 / 9) - (((w4 / 9) + h4) % 9)) + h4) / 9) + c4) % 64)][(((w4 / 9) + h4) % 9)][(w4 % 9)]) + ((ap_fixed<17, 9>)basicblock_bn_shortcut1[i17][c4][h4][w4])));
        }
      }
    }
  }
  ap_int<32> bb_output_relu_x14[32][64][10][10];
  for (ap_int<32> y20 = 0; y20 < 32; ++y20) {
    for (ap_int<32> args033 = 0; args033 < 64; ++args033) {
      for (ap_int<32> args133 = 0; args133 < 10; ++args133) {
        for (ap_int<32> args233 = 0; args233 < 10; ++args233) {
          bb_output_relu_x14[y20][args033][args133][args233] = ((compute4[y20][args033][args133][args233] < 0) ? ((ap_int<32>)0) : ((ap_int<32>)compute4[y20][args033][args133][args233]));
        }
      }
    }
  }
  ap_int<32> bb_output_relu4[32][64][10][10];
  for (ap_int<32> y21 = 0; y21 < 32; ++y21) {
    for (ap_int<32> args034 = 0; args034 < 64; ++args034) {
      for (ap_int<32> args134 = 0; args134 < 10; ++args134) {
        for (ap_int<32> args234 = 0; args234 < 10; ++args234) {
          bb_output_relu4[y21][args034][args134][args234] = ((1 < bb_output_relu_x14[y21][args034][args134][args234]) ? ((ap_int<32>)1) : ((ap_int<32>)bb_output_relu_x14[y21][args034][args134][args234]));
        }
      }
    }
  }
  ap_int<32> basicblock_conv1_pad5[32][64][12][12];
  for (ap_int<32> indices13 = 0; indices13 < 32; ++indices13) {
    for (ap_int<32> not_zero13 = 0; not_zero13 < 64; ++not_zero13) {
      for (ap_int<32> index_tuple13 = 0; index_tuple13 < 12; ++index_tuple13) {
        for (ap_int<32> i18 = 0; i18 < 12; ++i18) {
          basicblock_conv1_pad5[indices13][not_zero13][index_tuple13][i18] = (((((1 <= index_tuple13) && (index_tuple13 < 11)) && (1 <= i18)) && (i18 < 11)) ? ((ap_int<32>)bb_output_relu4[((((((i18 - ((i18 + -1) % 10)) + (index_tuple13 * 10)) + (not_zero13 * 100)) + (indices13 * 6400)) + -11) / 6400)][(((((((i18 - ((i18 + -1) % 10)) + (index_tuple13 * 10)) + (not_zero13 * 100)) + (indices13 * 6400)) + -11) / 100) % 64)][(((((((i18 - ((i18 + -1) % 10)) + (index_tuple13 * 10)) + (not_zero13 * 100)) + (indices13 * 6400)) + -11) / 10) % 10)][((i18 + -1) % 10)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv15[32][64][10][10];
  for (ap_int<32> nn13 = 0; nn13 < 32; ++nn13) {
    for (ap_int<32> ff13 = 0; ff13 < 64; ++ff13) {
      for (ap_int<32> yy13 = 0; yy13 < 10; ++yy13) {
        for (ap_int<32> xx13 = 0; xx13 < 10; ++xx13) {
          ap_fixed<16, 8> sum13;
          sum13 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra39 = 0; ra39 < 64; ++ra39) {
            for (ap_int<32> ra40 = 0; ra40 < 3; ++ra40) {
              for (ap_int<32> ra41 = 0; ra41 < 3; ++ra41) {
                sum13 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv1_pad5[nn13][ra39][(yy13 + ra40)][(xx13 + ra41)]) * ((ap_int<64>)conv4_weight11[ff13][ra39][ra40][ra41]))) + ((ap_fixed<73, 65>)sum13)));
              }
            }
          }
          basicblock_conv15[nn13][ff13][yy13][xx13] = ((ap_int<32>)sum13);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn15[32][64][10][10];
  for (ap_int<32> x13 = 0; x13 < 32; ++x13) {
    for (ap_int<32> args035 = 0; args035 < 64; ++args035) {
      for (ap_int<32> args135 = 0; args135 < 10; ++args135) {
        for (ap_int<32> args235 = 0; args235 < 10; ++args235) {
          basicblock_bn15[x13][args035][args135][args235] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn4_weight11[args235]) * ((ap_int<64>)basicblock_conv15[x13][args035][args135][args235]))) + ((ap_int<65>)bn4_bias11[args235])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu_x15[32][64][10][10];
  for (ap_int<32> y22 = 0; y22 < 32; ++y22) {
    for (ap_int<32> args036 = 0; args036 < 64; ++args036) {
      for (ap_int<32> args136 = 0; args136 < 10; ++args136) {
        for (ap_int<32> args236 = 0; args236 < 10; ++args236) {
          basicblock_relu_x15[y22][args036][args136][args236] = ((ap_int<32>)((((ap_fixed<40, 32>)basicblock_bn15[y22][args036][args136][args236]) < (ap_fixed<40, 32>)0) ? (((ap_fixed<16, 8>)0)) : ((ap_fixed<16, 8>)basicblock_bn15[y22][args036][args136][args236])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu5[32][64][10][10];
  for (ap_int<32> y23 = 0; y23 < 32; ++y23) {
    for (ap_int<32> args037 = 0; args037 < 64; ++args037) {
      for (ap_int<32> args137 = 0; args137 < 10; ++args137) {
        for (ap_int<32> args237 = 0; args237 < 10; ++args237) {
          basicblock_relu5[y23][args037][args137][args237] = ((ap_int<32>)((1 < basicblock_relu_x15[y23][args037][args137][args237]) ? (((ap_fixed<40, 32>)((ap_fixed<16, 8>)1))) : (((ap_fixed<40, 32>)basicblock_relu_x15[y23][args037][args137][args237]))));
        }
      }
    }
  }
  ap_int<32> basicblock_conv2_pad5[32][64][12][12];
  for (ap_int<32> indices14 = 0; indices14 < 32; ++indices14) {
    for (ap_int<32> not_zero14 = 0; not_zero14 < 64; ++not_zero14) {
      for (ap_int<32> index_tuple14 = 0; index_tuple14 < 12; ++index_tuple14) {
        for (ap_int<32> i19 = 0; i19 < 12; ++i19) {
          basicblock_conv2_pad5[indices14][not_zero14][index_tuple14][i19] = (((((1 <= index_tuple14) && (index_tuple14 < 11)) && (1 <= i19)) && (i19 < 11)) ? ((ap_int<32>)basicblock_relu5[((((((i19 - ((i19 + -1) % 10)) + (index_tuple14 * 10)) + (not_zero14 * 100)) + (indices14 * 6400)) + -11) / 6400)][(((((((i19 - ((i19 + -1) % 10)) + (index_tuple14 * 10)) + (not_zero14 * 100)) + (indices14 * 6400)) + -11) / 100) % 64)][(((((((i19 - ((i19 + -1) % 10)) + (index_tuple14 * 10)) + (not_zero14 * 100)) + (indices14 * 6400)) + -11) / 10) % 10)][((i19 + -1) % 10)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv25[32][64][10][10];
  for (ap_int<32> nn14 = 0; nn14 < 32; ++nn14) {
    for (ap_int<32> ff14 = 0; ff14 < 64; ++ff14) {
      for (ap_int<32> yy14 = 0; yy14 < 10; ++yy14) {
        for (ap_int<32> xx14 = 0; xx14 < 10; ++xx14) {
          ap_fixed<16, 8> sum14;
          sum14 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra42 = 0; ra42 < 64; ++ra42) {
            for (ap_int<32> ra43 = 0; ra43 < 3; ++ra43) {
              for (ap_int<32> ra44 = 0; ra44 < 3; ++ra44) {
                sum14 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv2_pad5[nn14][ra42][(yy14 + ra43)][(xx14 + ra44)]) * ((ap_int<64>)conv4_weight21[ff14][ra42][ra43][ra44]))) + ((ap_fixed<73, 65>)sum14)));
              }
            }
          }
          basicblock_conv25[nn14][ff14][yy14][xx14] = ((ap_int<32>)sum14);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn25[32][64][10][10];
  for (ap_int<32> x14 = 0; x14 < 32; ++x14) {
    for (ap_int<32> args038 = 0; args038 < 64; ++args038) {
      for (ap_int<32> args138 = 0; args138 < 10; ++args138) {
        for (ap_int<32> args238 = 0; args238 < 10; ++args238) {
          basicblock_bn25[x14][args038][args138][args238] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn4_weight21[args238]) * ((ap_int<64>)basicblock_conv25[x14][args038][args138][args238]))) + ((ap_int<65>)bn4_bias21[args238])));
        }
      }
    }
  }
  ap_int<32> compute5[32][64][10][10];
  for (ap_int<32> i20 = 0; i20 < 32; ++i20) {
    for (ap_int<32> c5 = 0; c5 < 64; ++c5) {
      for (ap_int<32> h5 = 0; h5 < 10; ++h5) {
        for (ap_int<32> w5 = 0; w5 < 10; ++w5) {
          compute5[i20][c5][h5][w5] = ((ap_int<32>)(((ap_fixed<41, 33>)basicblock_bn25[i20][c5][h5][w5]) + ((ap_fixed<41, 33>)bb_output_relu4[i20][c5][h5][w5])));
        }
      }
    }
  }
  ap_int<32> bb_output_relu_x15[32][64][10][10];
  for (ap_int<32> y24 = 0; y24 < 32; ++y24) {
    for (ap_int<32> args039 = 0; args039 < 64; ++args039) {
      for (ap_int<32> args139 = 0; args139 < 10; ++args139) {
        for (ap_int<32> args239 = 0; args239 < 10; ++args239) {
          bb_output_relu_x15[y24][args039][args139][args239] = ((compute5[y24][args039][args139][args239] < 0) ? ((ap_int<32>)0) : ((ap_int<32>)compute5[y24][args039][args139][args239]));
        }
      }
    }
  }
  ap_int<32> bb_output_relu5[32][64][10][10];
  for (ap_int<32> y25 = 0; y25 < 32; ++y25) {
    for (ap_int<32> args040 = 0; args040 < 64; ++args040) {
      for (ap_int<32> args140 = 0; args140 < 10; ++args140) {
        for (ap_int<32> args240 = 0; args240 < 10; ++args240) {
          bb_output_relu5[y25][args040][args140][args240] = ((1 < bb_output_relu_x15[y25][args040][args140][args240]) ? ((ap_int<32>)1) : ((ap_int<32>)bb_output_relu_x15[y25][args040][args140][args240]));
        }
      }
    }
  }
  ap_int<32> basicblock_conv1_pad6[32][64][12][12];
  for (ap_int<32> indices15 = 0; indices15 < 32; ++indices15) {
    for (ap_int<32> not_zero15 = 0; not_zero15 < 64; ++not_zero15) {
      for (ap_int<32> index_tuple15 = 0; index_tuple15 < 12; ++index_tuple15) {
        for (ap_int<32> i21 = 0; i21 < 12; ++i21) {
          basicblock_conv1_pad6[indices15][not_zero15][index_tuple15][i21] = (((((1 <= index_tuple15) && (index_tuple15 < 11)) && (1 <= i21)) && (i21 < 11)) ? ((ap_int<32>)bb_output_relu5[((((((i21 - ((i21 + -1) % 10)) + (index_tuple15 * 10)) + (not_zero15 * 100)) + (indices15 * 6400)) + -11) / 6400)][(((((((i21 - ((i21 + -1) % 10)) + (index_tuple15 * 10)) + (not_zero15 * 100)) + (indices15 * 6400)) + -11) / 100) % 64)][(((((((i21 - ((i21 + -1) % 10)) + (index_tuple15 * 10)) + (not_zero15 * 100)) + (indices15 * 6400)) + -11) / 10) % 10)][((i21 + -1) % 10)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv16[32][64][5][5];
  for (ap_int<32> nn15 = 0; nn15 < 32; ++nn15) {
    for (ap_int<32> ff15 = 0; ff15 < 64; ++ff15) {
      for (ap_int<32> yy15 = 0; yy15 < 5; ++yy15) {
        for (ap_int<32> xx15 = 0; xx15 < 5; ++xx15) {
          ap_fixed<16, 8> sum15;
          sum15 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra45 = 0; ra45 < 64; ++ra45) {
            for (ap_int<32> ra46 = 0; ra46 < 3; ++ra46) {
              for (ap_int<32> ra47 = 0; ra47 < 3; ++ra47) {
                sum15 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv1_pad6[nn15][ra45][((yy15 * 2) + ra46)][((xx15 * 2) + ra47)]) * ((ap_int<64>)conv5_weight1[ff15][ra45][ra46][ra47]))) + ((ap_fixed<73, 65>)sum15)));
              }
            }
          }
          basicblock_conv16[nn15][ff15][yy15][xx15] = ((ap_int<32>)sum15);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn16[32][64][5][5];
  for (ap_int<32> x15 = 0; x15 < 32; ++x15) {
    for (ap_int<32> args041 = 0; args041 < 64; ++args041) {
      for (ap_int<32> args141 = 0; args141 < 5; ++args141) {
        for (ap_int<32> args241 = 0; args241 < 5; ++args241) {
          basicblock_bn16[x15][args041][args141][args241] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn5_weight1[args241]) * ((ap_int<64>)basicblock_conv16[x15][args041][args141][args241]))) + ((ap_int<65>)bn5_bias1[args241])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu_x16[32][64][5][5];
  for (ap_int<32> y26 = 0; y26 < 32; ++y26) {
    for (ap_int<32> args042 = 0; args042 < 64; ++args042) {
      for (ap_int<32> args142 = 0; args142 < 5; ++args142) {
        for (ap_int<32> args242 = 0; args242 < 5; ++args242) {
          basicblock_relu_x16[y26][args042][args142][args242] = ((ap_int<32>)((((ap_fixed<40, 32>)basicblock_bn16[y26][args042][args142][args242]) < (ap_fixed<40, 32>)0) ? (((ap_fixed<16, 8>)0)) : ((ap_fixed<16, 8>)basicblock_bn16[y26][args042][args142][args242])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu6[32][64][5][5];
  for (ap_int<32> y27 = 0; y27 < 32; ++y27) {
    for (ap_int<32> args043 = 0; args043 < 64; ++args043) {
      for (ap_int<32> args143 = 0; args143 < 5; ++args143) {
        for (ap_int<32> args243 = 0; args243 < 5; ++args243) {
          basicblock_relu6[y27][args043][args143][args243] = ((ap_int<32>)((1 < basicblock_relu_x16[y27][args043][args143][args243]) ? (((ap_fixed<40, 32>)((ap_fixed<16, 8>)1))) : (((ap_fixed<40, 32>)basicblock_relu_x16[y27][args043][args143][args243]))));
        }
      }
    }
  }
  ap_int<32> basicblock_conv2_pad6[32][64][7][7];
  for (ap_int<32> indices16 = 0; indices16 < 32; ++indices16) {
    for (ap_int<32> not_zero16 = 0; not_zero16 < 64; ++not_zero16) {
      for (ap_int<32> index_tuple16 = 0; index_tuple16 < 7; ++index_tuple16) {
        for (ap_int<32> i22 = 0; i22 < 7; ++i22) {
          basicblock_conv2_pad6[indices16][not_zero16][index_tuple16][i22] = (((((1 <= index_tuple16) && (index_tuple16 < 6)) && (1 <= i22)) && (i22 < 6)) ? ((ap_int<32>)basicblock_relu6[((((((i22 - ((i22 + -1) % 5)) + (index_tuple16 * 5)) + (not_zero16 * 25)) + (indices16 * 1600)) + -6) / 1600)][(((((((i22 - ((i22 + -1) % 5)) + (index_tuple16 * 5)) + (not_zero16 * 25)) + (indices16 * 1600)) + -6) / 25) % 64)][(((((((i22 - ((i22 + -1) % 5)) + (index_tuple16 * 5)) + (not_zero16 * 25)) + (indices16 * 1600)) + -6) / 5) % 5)][((i22 + -1) % 5)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv26[32][64][5][5];
  for (ap_int<32> nn16 = 0; nn16 < 32; ++nn16) {
    for (ap_int<32> ff16 = 0; ff16 < 64; ++ff16) {
      for (ap_int<32> yy16 = 0; yy16 < 5; ++yy16) {
        for (ap_int<32> xx16 = 0; xx16 < 5; ++xx16) {
          ap_fixed<16, 8> sum16;
          sum16 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra48 = 0; ra48 < 64; ++ra48) {
            for (ap_int<32> ra49 = 0; ra49 < 3; ++ra49) {
              for (ap_int<32> ra50 = 0; ra50 < 3; ++ra50) {
                sum16 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv2_pad6[nn16][ra48][(yy16 + ra49)][(xx16 + ra50)]) * ((ap_int<64>)conv5_weight2[ff16][ra48][ra49][ra50]))) + ((ap_fixed<73, 65>)sum16)));
              }
            }
          }
          basicblock_conv26[nn16][ff16][yy16][xx16] = ((ap_int<32>)sum16);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn26[32][64][5][5];
  for (ap_int<32> x16 = 0; x16 < 32; ++x16) {
    for (ap_int<32> args044 = 0; args044 < 64; ++args044) {
      for (ap_int<32> args144 = 0; args144 < 5; ++args144) {
        for (ap_int<32> args244 = 0; args244 < 5; ++args244) {
          basicblock_bn26[x16][args044][args144][args244] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn5_weight2[args244]) * ((ap_int<64>)basicblock_conv26[x16][args044][args144][args244]))) + ((ap_int<65>)bn5_bias2[args244])));
        }
      }
    }
  }
  ap_int<32> basicblock_conv_shortcut_pad2[32][64][12][12];
  for (ap_int<32> indices17 = 0; indices17 < 32; ++indices17) {
    for (ap_int<32> not_zero17 = 0; not_zero17 < 64; ++not_zero17) {
      for (ap_int<32> index_tuple17 = 0; index_tuple17 < 12; ++index_tuple17) {
        for (ap_int<32> i23 = 0; i23 < 12; ++i23) {
          basicblock_conv_shortcut_pad2[indices17][not_zero17][index_tuple17][i23] = (((((1 <= index_tuple17) && (index_tuple17 < 11)) && (1 <= i23)) && (i23 < 11)) ? ((ap_int<32>)bb_output_relu5[((((((i23 - ((i23 + -1) % 10)) + (index_tuple17 * 10)) + (not_zero17 * 100)) + (indices17 * 6400)) + -11) / 6400)][(((((((i23 - ((i23 + -1) % 10)) + (index_tuple17 * 10)) + (not_zero17 * 100)) + (indices17 * 6400)) + -11) / 100) % 64)][(((((((i23 - ((i23 + -1) % 10)) + (index_tuple17 * 10)) + (not_zero17 * 100)) + (indices17 * 6400)) + -11) / 10) % 10)][((i23 + -1) % 10)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv_shortcut2[32][64][6][6];
  for (ap_int<32> nn17 = 0; nn17 < 32; ++nn17) {
    for (ap_int<32> ff17 = 0; ff17 < 64; ++ff17) {
      for (ap_int<32> yy17 = 0; yy17 < 6; ++yy17) {
        for (ap_int<32> xx17 = 0; xx17 < 6; ++xx17) {
          ap_fixed<16, 8> sum17;
          sum17 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra51 = 0; ra51 < 64; ++ra51) {
            sum17 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv_shortcut_pad2[nn17][ra51][((xx17 / 6) + (yy17 * 2))][(((((xx17 + (yy17 * 12)) + (ra51 * 72)) + (nn17 * 4608)) * 2) % 12)]) * ((ap_int<64>)conv5_shortcut_weight[ff17][ra51][0][0]))) + ((ap_fixed<73, 65>)sum17)));
          }
          basicblock_conv_shortcut2[nn17][ff17][yy17][xx17] = ((ap_int<32>)sum17);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn_shortcut2[32][64][6][6];
  for (ap_int<32> x17 = 0; x17 < 32; ++x17) {
    for (ap_int<32> args045 = 0; args045 < 64; ++args045) {
      for (ap_int<32> args145 = 0; args145 < 6; ++args145) {
        for (ap_int<32> args245 = 0; args245 < 6; ++args245) {
          basicblock_bn_shortcut2[x17][args045][args145][args245] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn5_shortcut_weight[args245]) * ((ap_int<64>)basicblock_conv_shortcut2[x17][args045][args145][args245]))) + ((ap_int<65>)bn5_shortcut_bias[args245])));
        }
      }
    }
  }
  ap_int<32> compute6[32][64][6][6];
  for (ap_int<32> i24 = 0; i24 < 32; ++i24) {
    for (ap_int<32> c6 = 0; c6 < 64; ++c6) {
      for (ap_int<32> h6 = 0; h6 < 6; ++h6) {
        for (ap_int<32> w6 = 0; w6 < 6; ++w6) {
          compute6[i24][c6][h6][w6] = ((ap_int<32>)(((ap_fixed<17, 9>)basicblock_bn26[((((((((w6 / 5) - (((w6 / 5) + h6) % 5)) + h6) / 5) - ((((((w6 / 5) - (((w6 / 5) + h6) % 5)) + h6) / 5) + c6) % 64)) + c6) / 64) + i24)][((((((w6 / 5) - (((w6 / 5) + h6) % 5)) + h6) / 5) + c6) % 64)][(((w6 / 5) + h6) % 5)][(w6 % 5)]) + ((ap_fixed<17, 9>)basicblock_bn_shortcut2[i24][c6][h6][w6])));
        }
      }
    }
  }
  ap_int<32> bb_output_relu_x16[32][64][6][6];
  for (ap_int<32> y28 = 0; y28 < 32; ++y28) {
    for (ap_int<32> args046 = 0; args046 < 64; ++args046) {
      for (ap_int<32> args146 = 0; args146 < 6; ++args146) {
        for (ap_int<32> args246 = 0; args246 < 6; ++args246) {
          bb_output_relu_x16[y28][args046][args146][args246] = ((compute6[y28][args046][args146][args246] < 0) ? ((ap_int<32>)0) : ((ap_int<32>)compute6[y28][args046][args146][args246]));
        }
      }
    }
  }
  ap_int<32> bb_output_relu6[32][64][6][6];
  for (ap_int<32> y29 = 0; y29 < 32; ++y29) {
    for (ap_int<32> args047 = 0; args047 < 64; ++args047) {
      for (ap_int<32> args147 = 0; args147 < 6; ++args147) {
        for (ap_int<32> args247 = 0; args247 < 6; ++args247) {
          bb_output_relu6[y29][args047][args147][args247] = ((1 < bb_output_relu_x16[y29][args047][args147][args247]) ? ((ap_int<32>)1) : ((ap_int<32>)bb_output_relu_x16[y29][args047][args147][args247]));
        }
      }
    }
  }
  ap_int<32> basicblock_conv1_pad7[32][64][8][8];
  for (ap_int<32> indices18 = 0; indices18 < 32; ++indices18) {
    for (ap_int<32> not_zero18 = 0; not_zero18 < 64; ++not_zero18) {
      for (ap_int<32> index_tuple18 = 0; index_tuple18 < 8; ++index_tuple18) {
        for (ap_int<32> i25 = 0; i25 < 8; ++i25) {
          basicblock_conv1_pad7[indices18][not_zero18][index_tuple18][i25] = (((((1 <= index_tuple18) && (index_tuple18 < 7)) && (1 <= i25)) && (i25 < 7)) ? ((ap_int<32>)bb_output_relu6[((((((i25 - ((i25 + -1) % 6)) + (index_tuple18 * 6)) + (not_zero18 * 36)) + (indices18 * 2304)) + -7) / 2304)][(((((((i25 - ((i25 + -1) % 6)) + (index_tuple18 * 6)) + (not_zero18 * 36)) + (indices18 * 2304)) + -7) / 36) % 64)][(((((((i25 - ((i25 + -1) % 6)) + (index_tuple18 * 6)) + (not_zero18 * 36)) + (indices18 * 2304)) + -7) / 6) % 6)][((i25 + -1) % 6)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv17[32][64][6][6];
  for (ap_int<32> nn18 = 0; nn18 < 32; ++nn18) {
    for (ap_int<32> ff18 = 0; ff18 < 64; ++ff18) {
      for (ap_int<32> yy18 = 0; yy18 < 6; ++yy18) {
        for (ap_int<32> xx18 = 0; xx18 < 6; ++xx18) {
          ap_fixed<16, 8> sum18;
          sum18 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra54 = 0; ra54 < 64; ++ra54) {
            for (ap_int<32> ra55 = 0; ra55 < 3; ++ra55) {
              for (ap_int<32> ra56 = 0; ra56 < 3; ++ra56) {
                sum18 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv1_pad7[nn18][ra54][(yy18 + ra55)][(xx18 + ra56)]) * ((ap_int<64>)conv5_weight11[ff18][ra54][ra55][ra56]))) + ((ap_fixed<73, 65>)sum18)));
              }
            }
          }
          basicblock_conv17[nn18][ff18][yy18][xx18] = ((ap_int<32>)sum18);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn17[32][64][6][6];
  for (ap_int<32> x18 = 0; x18 < 32; ++x18) {
    for (ap_int<32> args048 = 0; args048 < 64; ++args048) {
      for (ap_int<32> args148 = 0; args148 < 6; ++args148) {
        for (ap_int<32> args248 = 0; args248 < 6; ++args248) {
          basicblock_bn17[x18][args048][args148][args248] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn5_weight11[args248]) * ((ap_int<64>)basicblock_conv17[x18][args048][args148][args248]))) + ((ap_int<65>)bn5_bias11[args248])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu_x17[32][64][6][6];
  for (ap_int<32> y30 = 0; y30 < 32; ++y30) {
    for (ap_int<32> args049 = 0; args049 < 64; ++args049) {
      for (ap_int<32> args149 = 0; args149 < 6; ++args149) {
        for (ap_int<32> args249 = 0; args249 < 6; ++args249) {
          basicblock_relu_x17[y30][args049][args149][args249] = ((ap_int<32>)((((ap_fixed<40, 32>)basicblock_bn17[y30][args049][args149][args249]) < (ap_fixed<40, 32>)0) ? (((ap_fixed<16, 8>)0)) : ((ap_fixed<16, 8>)basicblock_bn17[y30][args049][args149][args249])));
        }
      }
    }
  }
  ap_int<32> basicblock_relu7[32][64][6][6];
  for (ap_int<32> y31 = 0; y31 < 32; ++y31) {
    for (ap_int<32> args050 = 0; args050 < 64; ++args050) {
      for (ap_int<32> args150 = 0; args150 < 6; ++args150) {
        for (ap_int<32> args250 = 0; args250 < 6; ++args250) {
          basicblock_relu7[y31][args050][args150][args250] = ((ap_int<32>)((1 < basicblock_relu_x17[y31][args050][args150][args250]) ? (((ap_fixed<40, 32>)((ap_fixed<16, 8>)1))) : (((ap_fixed<40, 32>)basicblock_relu_x17[y31][args050][args150][args250]))));
        }
      }
    }
  }
  ap_int<32> basicblock_conv2_pad7[32][64][8][8];
  for (ap_int<32> indices19 = 0; indices19 < 32; ++indices19) {
    for (ap_int<32> not_zero19 = 0; not_zero19 < 64; ++not_zero19) {
      for (ap_int<32> index_tuple19 = 0; index_tuple19 < 8; ++index_tuple19) {
        for (ap_int<32> i26 = 0; i26 < 8; ++i26) {
          basicblock_conv2_pad7[indices19][not_zero19][index_tuple19][i26] = (((((1 <= index_tuple19) && (index_tuple19 < 7)) && (1 <= i26)) && (i26 < 7)) ? ((ap_int<32>)basicblock_relu7[((((((i26 - ((i26 + -1) % 6)) + (index_tuple19 * 6)) + (not_zero19 * 36)) + (indices19 * 2304)) + -7) / 2304)][(((((((i26 - ((i26 + -1) % 6)) + (index_tuple19 * 6)) + (not_zero19 * 36)) + (indices19 * 2304)) + -7) / 36) % 64)][(((((((i26 - ((i26 + -1) % 6)) + (index_tuple19 * 6)) + (not_zero19 * 36)) + (indices19 * 2304)) + -7) / 6) % 6)][((i26 + -1) % 6)]) : ((ap_int<32>)0));
        }
      }
    }
  }
  ap_int<32> basicblock_conv27[32][64][6][6];
  for (ap_int<32> nn19 = 0; nn19 < 32; ++nn19) {
    for (ap_int<32> ff19 = 0; ff19 < 64; ++ff19) {
      for (ap_int<32> yy19 = 0; yy19 < 6; ++yy19) {
        for (ap_int<32> xx19 = 0; xx19 < 6; ++xx19) {
          ap_fixed<16, 8> sum19;
          sum19 = ((ap_fixed<16, 8>)0);
          for (ap_int<32> ra57 = 0; ra57 < 64; ++ra57) {
            for (ap_int<32> ra58 = 0; ra58 < 3; ++ra58) {
              for (ap_int<32> ra59 = 0; ra59 < 3; ++ra59) {
                sum19 = ((ap_fixed<16, 8>)(((ap_fixed<73, 65>)(((ap_int<64>)basicblock_conv2_pad7[nn19][ra57][(yy19 + ra58)][(xx19 + ra59)]) * ((ap_int<64>)conv5_weight21[ff19][ra57][ra58][ra59]))) + ((ap_fixed<73, 65>)sum19)));
              }
            }
          }
          basicblock_conv27[nn19][ff19][yy19][xx19] = ((ap_int<32>)sum19);
        }
      }
    }
  }
  ap_fixed<16, 8> basicblock_bn27[32][64][6][6];
  for (ap_int<32> x19 = 0; x19 < 32; ++x19) {
    for (ap_int<32> args051 = 0; args051 < 64; ++args051) {
      for (ap_int<32> args151 = 0; args151 < 6; ++args151) {
        for (ap_int<32> args251 = 0; args251 < 6; ++args251) {
          basicblock_bn27[x19][args051][args151][args251] = ((ap_fixed<16, 8>)(((ap_int<65>)(((ap_int<64>)bn5_weight21[args251]) * ((ap_int<64>)basicblock_conv27[x19][args051][args151][args251]))) + ((ap_int<65>)bn5_bias21[args251])));
        }
      }
    }
  }
  ap_int<32> compute7[32][64][6][6];
  for (ap_int<32> i27 = 0; i27 < 32; ++i27) {
    for (ap_int<32> c7 = 0; c7 < 64; ++c7) {
      for (ap_int<32> h7 = 0; h7 < 6; ++h7) {
        for (ap_int<32> w7 = 0; w7 < 6; ++w7) {
          compute7[i27][c7][h7][w7] = ((ap_int<32>)(((ap_fixed<41, 33>)basicblock_bn27[i27][c7][h7][w7]) + ((ap_fixed<41, 33>)bb_output_relu6[i27][c7][h7][w7])));
        }
      }
    }
  }
  ap_int<32> bb_output_relu_x17[32][64][6][6];
  for (ap_int<32> y32 = 0; y32 < 32; ++y32) {
    for (ap_int<32> args052 = 0; args052 < 64; ++args052) {
      for (ap_int<32> args152 = 0; args152 < 6; ++args152) {
        for (ap_int<32> args252 = 0; args252 < 6; ++args252) {
          bb_output_relu_x17[y32][args052][args152][args252] = ((compute7[y32][args052][args152][args252] < 0) ? ((ap_int<32>)0) : ((ap_int<32>)compute7[y32][args052][args152][args252]));
        }
      }
    }
  }
  ap_int<32> bb_output_relu7[32][64][6][6];
  for (ap_int<32> y33 = 0; y33 < 32; ++y33) {
    for (ap_int<32> args053 = 0; args053 < 64; ++args053) {
      for (ap_int<32> args153 = 0; args153 < 6; ++args153) {
        for (ap_int<32> args253 = 0; args253 < 6; ++args253) {
          bb_output_relu7[y33][args053][args153][args253] = ((1 < bb_output_relu_x17[y33][args053][args153][args253]) ? ((ap_int<32>)1) : ((ap_int<32>)bb_output_relu_x17[y33][args053][args153][args253]));
        }
      }
    }
  }
  ap_int<32> avg_pool[32][64][1][1];
  for (ap_int<32> i28 = 0; i28 < 32; ++i28) {
    for (ap_int<32> c8 = 0; c8 < 64; ++c8) {
      ap_int<32> reducer0;
      reducer0 = 0;
      for (ap_int<32> ra60 = 0; ra60 < 6; ++ra60) {
        for (ap_int<32> ra61 = 0; ra61 < 6; ++ra61) {
          reducer0 = ((ap_int<32>)((((ap_int<33>)bb_output_relu7[i28][c8][ra60][ra61]) + ((ap_int<33>)reducer0)) / (ap_int<33>)2));
        }
      }
      avg_pool[i28][c8][0][0] = reducer0;
    }
  }
  ap_int<32> compute8[32][64];
  for (ap_int<32> i29 = 0; i29 < 32; ++i29) {
    for (ap_int<32> c9 = 0; c9 < 64; ++c9) {
      compute8[i29][c9] = avg_pool[i29][c9][0][0];
    }
  }
  for (ap_int<32> x20 = 0; x20 < 32; ++x20) {
    for (ap_int<32> y34 = 0; y34 < 64; ++y34) {
      ap_int<32> sum20;
      sum20 = 0;
      for (ap_int<32> ra62 = 0; ra62 < 64; ++ra62) {
        for (ap_int<32> ra63 = 0; ra63 < 100; ++ra63) {
          sum20 = ((ap_int<32>)(((ap_int<65>)(((ap_int<64>)compute8[((((y34 - ((y34 + ra62) % 64)) + ra62) / 64) + x20)][((y34 + ra62) % 64)]) * ((ap_int<64>)full_connection[(y34 + ra63)][x20]))) + ((ap_int<65>)sum20)));
        }
      }
      linear[x20][y34] = sum20;
    }
  }
}


