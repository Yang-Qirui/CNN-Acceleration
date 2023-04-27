#ifndef _WEIGHTS_H_
#define _WEIGHTS_H_

const float conv1[6][1][5][5] = #include"../../weights/lenet/batchsize2.pth_dat/layer0.dat";
const float bias1[6] = #include"../../weights/lenet/batchsize2.pth_dat/layer1.dat";
const float conv2_1[16][6][5][5] = #include"../../weights/lenet/batchsize2.pth_dat/layer2.dat";
const float bias2_1[16] = #include"../../weights/lenet/batchsize2.pth_dat/layer3.dat";
const float conv2_2[16][6][5][5] = #include"../../weights/lenet/batchsize2.pth_dat/layer4.dat";
const float bias2_2[16] = #include"../../weights/lenet/batchsize2.pth_dat/layer5.dat";
const float conv3[120][16][5][5] = #include"../../weights/lenet/batchsize2.pth_dat/layer6.dat";
const float bias3[120] = #include"../../weights/lenet/batchsize2.pth_dat/layer7.dat";
const float fc_weight1[84][120] = #include"../../weights/lenet/batchsize2.pth_dat/layer8.dat";
const float fc_bias1[84] = #include"../../weights/lenet/batchsize2.pth_dat/layer9.dat";
const float fc_weight2[10][84] = #include"../../weights/lenet/batchsize2.pth_dat/layer10.dat";
const float fc_bias2[10] = #include"../../weights/lenet/batchsize2.pth_dat/layer11.dat";

#endif // _WEIGHTS_H_
