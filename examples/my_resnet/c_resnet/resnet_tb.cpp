#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "weights.h"
#include "demo.h"
using namespace std;

// MENTION：Should enable c++17
int main()
{
    string input_dir = "../../../dat_input/resnet18";

    int acc = 0;
    int tot = 0;

    // for (int i = 0; i < batch_num; i++)
    for (int i = 0; i < 50; i++) // use fewer batches to accelerate cosim time
    {
        string input_path = "../../../dat_input/resnet18/input_batch" + to_string(i) + ".dat";
        string label_path = "../../../dat_input/resnet18/label_batch" + to_string(i) + ".dat";
        ifstream input_file(input_path);
        const int dim1 = 2;
        const int dim2 = 3;
        const int dim3 = 32;
        const int dim4 = 32;
        ap_fixed<10, 4> input_image[dim1][dim2][dim3][dim4];
        int label_image[dim1];
        ifstream ifile(input_path);
        ifstream lfile(label_path);

        if (!ifile.is_open() || !lfile.is_open())
        {
            std::cerr << "Failed to open file!" << std::endl;
            return 1;
        }

        float value;
        int label;
        char comma;
        for (int i = 0; i < dim1; i++)
        {
            for (int j = 0; j < dim2; j++)
            {
                for (int k = 0; k < dim3; k++)
                {
                    for (int l = 0; l < dim4; l++)
                    {
                        if (!(ifile >> value >> comma))
                        {
                            std::cerr << "Failed to read value!" << std::endl;
                            return 1;
                        }
                        input_image[i][j][k][l] = (ap_fixed<10, 4>)value;
                    }
                }
            }
            if (!(lfile >> label >> comma))
            {
                std::cerr << "Failed to read label!" << std::endl;
                return 1;
            }
            label_image[i] = (int)label;
        }

        ifile.close();
        lfile.close();

        ap_fixed<10, 4> out[dim1][100];
        top(input_image, w_0, w_1, w_2, w_3, w_4, w_5, w_6, w_7, w_8, w_9, w_10, w_11, w_12, w_13, w_14, w_15, w_16, w_17, w_18, w_19, w_20, w_21, w_22, w_23, w_24, w_25, w_26, w_27, w_28, w_29, w_30, w_31, w_32, w_33, w_34, w_35, w_36, w_37, w_38, w_39, w_40, w_41, w_42, w_43, w_44, w_45, w_46, w_47, w_48, w_49, w_50, w_51, w_52, w_53, w_54, w_55, w_56, w_57, w_58, w_59, w_60, w_61, w_62, w_63, w_64, w_65, w_66, w_67, w_68, w_69, w_70, w_71, w_72, w_73, w_74, w_75, w_76, w_77, w_78, w_79, w_80, w_81, w_82, w_83, w_84, w_85, w_86, w_87, w_88, w_89, w_90, w_91, w_92, w_93, w_94, w_95, w_96, w_97, w_98, w_99, w_100, w_101, out);

        int top1_label[dim1];
        for (int i = 0; i < dim1; i++)
        {
            ap_fixed<10, 4> _max = 0;
            for (int j = 0; j < 100; j++)
            {
                if (out[i][j] > _max)
                {
                    top1_label[i] = j;
                    _max = out[i][j];
                }
            }
        }

        for (int i = 0; i < dim1; i++)
        {
            cout << label_image[i] << " " << top1_label[i] << endl;
            if (label_image[i] == top1_label[i])
            {
                acc += 1;
            }
            tot += 1;
        }
    }
    cout << "Test Accuracy: " << (float)(acc / tot) << endl;
}