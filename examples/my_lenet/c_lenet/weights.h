#ifndef _WEIGHTS_H_
#define _WEIGHTS_H_

#include <ap_fixed.h>

static float w_0[6][1][5][5] = {
#include "/home1/yangqr/CNN-Acceleration/weights/lenet/batchsize2.pth_dat/layer0.dat"
};
static float w_1[6] = {
#include "/home1/yangqr/CNN-Acceleration/weights/lenet/batchsize2.pth_dat/layer1.dat"
};
static float w_2[16][6][5][5] = {
#include "/home1/yangqr/CNN-Acceleration/weights/lenet/batchsize2.pth_dat/layer2.dat"
};
static float w_3[16] = {
#include "/home1/yangqr/CNN-Acceleration/weights/lenet/batchsize2.pth_dat/layer3.dat"
};
static float w_4[16][6][5][5] = {
#include "/home1/yangqr/CNN-Acceleration/weights/lenet/batchsize2.pth_dat/layer4.dat"
};
static float w_5[16] = {
#include "/home1/yangqr/CNN-Acceleration/weights/lenet/batchsize2.pth_dat/layer5.dat"
};
static float w_6[120][16][5][5] = {
#include "/home1/yangqr/CNN-Acceleration/weights/lenet/batchsize2.pth_dat/layer6.dat"
};
static float w_7[120] = {
#include "/home1/yangqr/CNN-Acceleration/weights/lenet/batchsize2.pth_dat/layer7.dat"
};
static float w_8[84][120] = {
#include "/home1/yangqr/CNN-Acceleration/weights/lenet/batchsize2.pth_dat/layer8.dat"
};
static float w_9[84] = {
#include "/home1/yangqr/CNN-Acceleration/weights/lenet/batchsize2.pth_dat/layer9.dat"
};
static float w_10[10][84] = {
#include "/home1/yangqr/CNN-Acceleration/weights/lenet/batchsize2.pth_dat/layer10.dat"
};
static float w_11[10] = {
#include "/home1/yangqr/CNN-Acceleration/weights/lenet/batchsize2.pth_dat/layer11.dat"
};

#endif // _WEIGHTS_H_

// The comment below help you to include weights fast
// w_0, w_1, w_2, w_3, w_4, w_5, w_6, w_7, w_8, w_9, w_10, w_11