#include <stdio.h>
#include <stdlib.h>
#include "weights.h"
#include "buffer.h"
using namespace std;

// MENTION：Should enable c++17
// int main()
// {
//     string input_dir = "../../../dat_input/lenet";

//     int acc = 0;
//     int tot = 0;

//     // for (int i = 0; i < batch_num; i++)
//     for (int i = 0; i < 1000; i++) // use fewer batches to accelerate cosim time
//     {
//         string input_path = "../../../dat_input/lenet/input_batch" + to_string(i) + ".dat";
//         string label_path = "../../../dat_input/lenet/label_batch" + to_string(i) + ".dat";
//         const int dim1 = 2;
//         const int dim2 = 1;
//         const int dim3 = 32;
//         const int dim4 = 32;
//         const int out_dim = 10;
//         // ap_fixed<10, 4> input_image[dim1][dim2][dim3][dim4];
//         float input_image[dim1][dim2][dim3][dim4];
//         int label_image[dim1];
//         ifstream ifile(input_path);
//         ifstream lfile(label_path);
//         string line;
//         std::getline(ifile, line);
//         std::stringstream si(line);

//         if (!ifile.is_open() || !lfile.is_open())
//         {
//             std::cerr << "Failed to open file!" << std::endl;
//             return 1;
//         }

//         float value;
//         float label;
//         char comma;
//         for (int i = 0; i < dim1; i++)
//         {
//             for (int j = 0; j < dim2; j++)
//             {
//                 for (int k = 0; k < dim3; k++)
//                 {
//                     for (int l = 0; l < dim4; l++)
//                     {
//                         if (si >> value)
//                         {
//                             // input_image[i][j][k][l] = (ap_fixed<10, 4>)value;
//                             input_image[i][j][k][l] = (float)value;
//                             // 跳过逗号
//                             if (si.peek() == ',')
//                             {
//                                 si.ignore();
//                             }
//                         }
//                     }
//                 }
//             }
//         }

//         std::getline(lfile, line);
//         std::stringstream sl(line);
//         for (int i = 0; i < dim1; i++)
//         {
//             if (sl >> label)
//             {
//                 label_image[i] = (int)label;
//                 // 跳过逗号
//                 if (sl.peek() == ',')
//                 {
//                     sl.ignore();
//                 }
//             }
//         }

//         ifile.close();
//         lfile.close();

//         // ap_fixed<10, 4> out[dim1][10];
//         float out[dim1][out_dim];
//         top(input_image, w_0, w_1, w_2, w_3, w_4, w_5, w_6, w_7, w_8, w_9, w_10, w_11, out);
//         for (int i = 0; i < dim1; i++)
//         {
//             for (int j = 0; j < out_dim; j++)
//             {
//                 cout << out[i][j] << " ";
//             }
//             cout << endl;
//         }

//         int top1_label[dim1];
//         for (int i = 0; i < dim1; i++)
//         {
//             // ap_fixed<10, 4> _max = 0;
//             float _max = -INFINITY;
//             for (int j = 0; j < out_dim; j++)
//             {
//                 if (out[i][j] > _max)
//                 {
//                     top1_label[i] = j;
//                     _max = out[i][j];
//                 }
//             }
//         }

//         for (int i = 0; i < dim1; i++)
//         {
//             cout << "Expected:" << label_image[i] << ", Get:" << top1_label[i] << endl;
//             if (label_image[i] == top1_label[i])
//             {
//                 acc += 1;
//             }
//             tot += 1;
//         }
//     }
//     double accuracy = (double)acc / (double)tot;
//     cout << "Test Accuracy: " << accuracy << endl;
//     return 0;
// }

int main()
{

    int acc = 0;
    int tot = 0;

    const int dim1 = 2;
    const int dim2 = 1;
    const int dim3 = 32;
    const int dim4 = 32;
    const int out_dim = 10;

    static float input_image[dim1][dim2][dim3][dim4];

    for (int i = 0; i < 1; i++)
    {
        printf("Batch %d \n", i);
        char input_path[256];
        char label_path[256];
        snprintf(input_path, sizeof(input_path), "/home1/yangqr/CNN-Acceleration/dat_input/lenet/input_batch%d.dat", i);
        snprintf(label_path, sizeof(label_path), "/home1/yangqr/CNN-Acceleration/dat_input/lenet/label_batch%d.dat", i);
        printf("Path create success.\n");

        int label_image[dim1];

        FILE *ifile = fopen(input_path, "r");
        FILE *lfile = fopen(label_path, "r");

        if (!ifile)
        {
            char err_msg[256];
            snprintf(err_msg, sizeof(err_msg), "Failed to open file! %s", input_path);
            perror(err_msg);
            return 1;
        }
        if (!lfile)
        {
            char err_msg[256];
            snprintf(err_msg, sizeof(err_msg), "Failed to open file! %s", label_path);
            perror(err_msg);
            return 1;
        }
        printf("File load success.\n");

        float value;
        float label;
        for (int i = 0; i < dim1; i++)
        {
            for (int j = 0; j < dim2; j++)
            {
                for (int k = 0; k < dim3; k++)
                {
                    for (int l = 0; l < dim4; l++)
                    {
                        if (fscanf(ifile, "%f,", &value) == 1)
                        {
                            input_image[i][j][k][l] = value;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < dim1; i++)
        {
            if (fscanf(lfile, "%f,", &label) == 1)
            {
                label_image[i] = (int)label;
            }
        }

        fclose(ifile);
        fclose(lfile);

        float out[dim1][out_dim];
        top(input_image, w_0, w_1, w_2, w_3, w_4, w_5, w_6, w_7, w_8, w_9, w_10, w_11, out);

        // for (int i = 0; i < dim1; i++)
        // {
        //     for (int j = 0; j < out_dim; j++)
        //     {
        //         printf("%f ", out[i][j]);
        //     }
        //     printf("\n");
        // }

        int top1_label[dim1];
        for (int i = 0; i < dim1; i++)
        {
            float _max = -INFINITY;
            for (int j = 0; j < out_dim; j++)
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
            printf("Expected: %d, Get: %d\n", label_image[i], top1_label[i]);
            if (label_image[i] == top1_label[i])
            {
                acc += 1;
            }
            tot += 1;
        }
    }
    double accuracy = (double)acc / (double)tot;
    printf("Test Accuracy: %f\n", accuracy);
    return 0;
}
