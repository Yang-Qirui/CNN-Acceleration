import os
import sys
import argparse
root_dir = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.append(root_dir)
from utils.functions import gen_input, gen_weights_cpp_header, save_weights_dat
import torchvision.transforms as transforms
from lenet_model import lenet
from torchvision.datasets.mnist import MNIST

def gen_input_dat():
    mnist_test = MNIST('../../dataset/mnist',
                  train=False,
                  download=True,
                  transform=transforms.Compose([
                      transforms.Resize((32, 32)),
                      transforms.ToTensor()]))
    gen_input(mnist_test, "../../dat_input/lenet", 2)

def gen_weight_dat():
    dat_dir = "../../weights/lenet/batchsize2.pth_dat/"
    if not os.path.exists(dat_dir):
        save_weights_dat("../../weights/lenet/batchsize2.pth")
    gen_weights_cpp_header(lenet, dat_dir, "./c_lenet/weights.h")

if __name__ == "__main__":
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument("--input", help="Generate input .dat files", action="store_true", default=False)
    arg_parser.add_argument("--weight", help="Generate weight .dat files", action="store_true", default=False)
    
    args = arg_parser.parse_args()

    if args.input:
        gen_input_dat()
    if args.weight:
        gen_weight_dat()
