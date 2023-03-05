// #include "resnet18.h"
#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>
#include <resnet18.h>

using namespace Json;
using namespace std;

Reader reader;
Value root;

ifstream is;
int layer_num = 0;

string get_weight_path(int i)
{
    return "../../../weights/resnet18-weights-json/layer" + to_string(i) + ".json";
}

void converter4d(float ****output)
{
    cout << layer_num << endl;
    auto path = get_weight_path(layer_num);
    is.open(path, ios::binary);
    if (reader.parse(is, root))
    {
        Value input = root[to_string(layer_num)];

        int batch = input.size();
        int channel = input[0].size();
        int height = input[0][0].size();
        int width = input[0][0][0].size();
        for (int b = 0; b < batch; b++)
            for (int c = 0; c < channel; c++)
                for (int h = 0; h < height; h++)
                    for (int w = 0; w < width; w++)
                    {
                        *((float *)output + b * channel * height * width + c * height * width + h * width + w) = input[b][c][h][w].asFloat();
                        cout << input[b][c][h][w] << endl;
                    }
    }
    else
        cout << "ERROR 4d" << layer_num << endl;
    layer_num += 1;
}

void converter1d(float *output)
{
    cout << layer_num << endl;
    auto path = get_weight_path(layer_num);
    is.open(path, ios::binary);
    if (reader.parse(is, root))
    {
        Value input = root[to_string(layer_num)];
        int batch = input.size();
        for (int b = 0; b < batch; b++)
        {
            output[b] = input[b].asFloat();
            cout << input[b] << endl;
        }
    }
    else
        cout << "ERROR 1d" << layer_num << endl;
    layer_num += 1;
}

void converter2d(float **output)
{
    cout << layer_num << endl;
    auto path = get_weight_path(layer_num);
    is.open(path, ios::binary);
    if (reader.parse(is, root))
    {
        Value input = root[to_string(layer_num)];
        int batch = input.size();
        int channel = input[0].size();
        for (int b = 0; b < batch; b++)
            for (int c = 0; c < channel; c++)
            {
                *((float *)output + b * channel) = input[b][c].asFloat();
                cout << input[b][c] << endl;
            }
    }
    else
        cout << "ERROR 2d" << layer_num << endl;
    layer_num += 1;
}

int main()
{
    float conv1_weight[64][3][3][3];
    float bn1_weight[64];
    float bn1_bias[64];

    float conv2_weight1[64][64][3][3];
    float bn2_weight1[64];
    float bn2_bias1[64];

    float conv2_weight2[64][64][3][3];
    float bn2_weight2[64];
    float bn2_bias2[64];

    float conv2_weight11[64][64][3][3];
    float bn2_weight11[64];
    float bn2_bias11[64];

    float conv2_weight21[64][64][3][3];
    float bn2_weight21[64];
    float bn2_bias21[64];

    float conv3_weight1[128][64][3][3];
    float bn3_weight1[128];
    float bn3_bias1[128];

    float conv3_weight2[128][128][3][3];
    float bn3_weight2[128];
    float bn3_bias2[128];

    float conv3_shortcut_weight[128][64][1][1];
    float bn3_shortcut_weight[128];
    float bn3_shortcut_bias[128];

    float conv3_weight11[128][128][3][3];
    float bn3_weight11[128];
    float bn3_bias11[128];

    float conv3_weight21[128][128][3][3];
    float bn3_weight21[128];
    float bn3_bias21[128];

    float conv4_weight1[256][128][3][3];
    float bn4_weight1[256];
    float bn4_bias1[256];

    float conv4_weight2[256][256][3][3];
    float bn4_weight2[256];
    float bn4_bias2[256];

    float conv4_shortcut_weight[256][128][1][1];
    float bn4_shortcut_weight[256];
    float bn4_shortcut_bias[256];

    float conv4_weight11[256][256][3][3];
    float bn4_weight11[256];
    float bn4_bias11[256];

    float conv4_weight21[256][256][3][3];
    float bn4_weight21[256];
    float bn4_bias21[256];

    float conv5_weight1[512][256][3][3];
    float bn5_weight1[512];
    float bn5_bias1[512];

    float conv5_weight2[512][512][3][3];
    float bn5_weight2[512];
    float bn5_bias2[512];

    float conv5_shortcut_weight[512][256][1][1];
    float bn5_shortcut_weight[512];
    float bn5_shortcut_bias[512];

    float conv5_weight11[512][512][3][3];
    float bn5_weight11[512];
    float bn5_bias11[512];

    float conv5_weight21[512][512][3][3];
    float bn5_weight21[512];
    float bn5_bias21[512];

    float fc_weight[100][512];
    float fc_bias[100];

    float linear[32][100];
    converter4d((float ****)conv1_weight);
    converter1d(bn1_weight);
    converter1d(bn1_bias);

    converter4d((float ****)conv2_weight1);
    converter1d(bn2_weight1);
    converter1d(bn2_bias1);

    converter4d((float ****)conv2_weight2);
    converter1d(bn2_weight2);
    converter1d(bn2_bias2);

    converter4d((float ****)conv2_weight11);
    converter1d(bn2_weight11);
    converter1d(bn2_bias11);

    converter4d((float ****)conv2_weight21);
    converter1d(bn2_weight21);
    converter1d(bn2_bias21);

    converter4d((float ****)conv3_weight1);
    converter1d(bn3_weight1);
    converter1d(bn3_bias1);
    converter4d((float ****)conv3_weight2);
    converter1d(bn3_weight2);
    converter1d(bn3_bias2);
    converter4d((float ****)conv3_shortcut_weight);
    converter1d(bn3_shortcut_weight);
    converter1d(bn3_shortcut_bias);
    converter4d((float ****)conv3_weight11);
    converter1d(bn3_weight11);
    converter1d(bn3_bias11);
    converter4d((float ****)conv3_weight21);
    converter1d(bn3_weight21);
    converter1d(bn3_bias21);

    converter4d((float ****)conv4_weight1);
    converter1d(bn4_weight1);
    converter1d(bn4_bias1);
    converter4d((float ****)conv4_weight2);
    converter1d(bn4_weight2);
    converter1d(bn4_bias2);
    converter4d((float ****)conv4_shortcut_weight);
    converter1d(bn4_shortcut_weight);
    converter1d(bn4_shortcut_bias);
    converter4d((float ****)conv4_weight11);
    converter1d(bn4_weight11);
    converter1d(bn4_bias11);
    converter4d((float ****)conv4_weight21);
    converter1d(bn4_weight21);
    converter1d(bn4_bias21);

    converter4d((float ****)conv5_weight1);
    converter1d(bn5_weight1);
    converter1d(bn5_bias1);
    converter4d((float ****)conv5_weight2);
    converter1d(bn5_weight2);
    converter1d(bn5_bias2);
    converter4d((float ****)conv5_shortcut_weight);
    converter1d(bn5_shortcut_weight);
    converter1d(bn5_shortcut_bias);
    converter4d((float ****)conv5_weight11);
    converter1d(bn5_weight11);
    converter1d(bn5_bias11);
    converter4d((float ****)conv5_weight21);
    converter1d(bn5_weight21);
    converter1d(bn5_bias21);

    converter2d((float **)fc_weight);
    converter1d(fc_bias);

    int tot = 0;
    int acc = 0;
    for (int i = 0; i < 312; i++)
    {
        string path = "../../../dataset/cifar-100-json/batch" + to_string(i) + ".json";
        is.open(path, ios::binary);
        if (reader.parse(is, root))
        {
            auto img = root[to_string(i)][0];
            int batch = img.size();
            int channel = img[0].size();
            int height = img[0][0].size();
            int width = img[0][0][0].size();
            float img_tensor[batch][channel][height][width];
            for (int b = 0; b < batch; b++)
                for (int c = 0; c < channel; c++)
                    for (int h = 0; h < height; h++)
                        for (int w = 0; w < width; w++)
                        {
                            img_tensor[b][c][h][w] = img[b][c][h][w].asFloat();
                        }
            default_function(img_tensor, conv1_weight, bn1_weight, bn1_bias, conv2_weight1, bn2_weight1, bn2_bias1, conv2_weight2, bn2_weight2, bn2_bias2, conv2_weight11, bn2_weight11, bn2_bias11, conv2_weight21, bn2_weight21, bn2_bias21, conv3_weight1, bn3_weight1, bn3_bias1, conv3_weight2, bn3_weight2, bn3_bias2, conv3_shortcut_weight, bn3_shortcut_weight, bn3_shortcut_bias, conv3_weight11, bn3_weight11, bn3_bias11, conv3_weight21, bn3_weight21, bn3_bias21, conv4_weight1, bn4_weight1, bn4_bias1, conv4_weight2, bn4_weight2, bn4_bias2, conv4_shortcut_weight, bn4_shortcut_weight, bn4_shortcut_bias, conv4_weight11, bn4_weight11, bn4_bias11, conv4_weight21, bn4_weight21, bn4_bias21, conv5_weight1, bn5_weight1, bn5_bias1, conv5_weight2, bn5_weight2, bn5_bias2, conv5_shortcut_weight, bn5_shortcut_weight, bn5_shortcut_bias, conv5_weight11, bn5_weight11, bn5_bias11, conv5_weight21, bn5_weight21, bn5_bias21, fc_weight, fc_bias, linear);
            int top1_label[32];
            for (int i = 0; i < 32; i++)
            {
                float _max = -1;
                for (int j = 0; j < 100;j++){
                    if(linear[i][j] > _max){
                        top1_label[i] = j;
                        _max  =linear[i][j];
                    }
                }
            }
            auto label_tensor = root[to_string(i)][1];

            for (int i = 0;i < 32;i ++){
                cout << label_tensor[i] << " " << top1_label[i] << endl;
                if (label_tensor[i] == top1_label[i]){
                    acc += 1;
                }
            }
            // auto img_tensor = img_convert_json_list(img);
        }
        is.close();
        tot += 1;
    }
    return 0;
}
