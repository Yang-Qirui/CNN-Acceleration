import os
import sys
import argparse
root_dir = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.append(root_dir)
from utils.functions import gen_input, CIFAR100_TEST_MEAN, CIFAR100_TEST_STD, gen_weights_cpp_header, save_weights_dat
import torchvision
import torchvision.transforms as transforms
from torch.utils.data import DataLoader
from resnet_model import nn_resnet18

def gen_input_dat():
    transform_test = transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize(CIFAR100_TEST_MEAN, CIFAR100_TEST_STD)
    ])
    cifar100_test = torchvision.datasets.CIFAR100(root='../../dataset', train=False, download=False, transform=transform_test)
    gen_input(cifar100_test, "../../dat_input/resnet18", 2)

def gen_weight_dat():
    dat_dir = "../../weights/resnet18/batchsize2.pth_dat/"
    if not os.path.exists(dat_dir):
        save_weights_dat("../../weights/resnet18/batchsize2.pth")
    gen_weights_cpp_header(nn_resnet18, dat_dir, "./c_resnet/weights.h")

if __name__ == "__main__":
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument("--input", help="Generate input .dat files", action="store_true", default=False)
    arg_parser.add_argument("--weight", help="Generate weight .dat files", action="store_true", default=False)
    
    args = arg_parser.parse_args()

    if args.input:
        gen_input_dat()
    if args.weight:
        gen_weight_dat()
