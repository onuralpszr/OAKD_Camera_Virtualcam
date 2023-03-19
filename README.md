# OAK-D Webcam Project (Linux Only)

![GitHub](https://img.shields.io/github/license/onuralpszr/OAKD_Camera_Virtualcam?color=blue)
[![Open issue](https://img.shields.io/github/issues/onuralpszr/OAKD_Camera_Virtualcam)](https://github.com/onuralpszr/OAKD_Camera_Virtualcam/issues)
[![Closed issue](https://img.shields.io/github/issues-closed/onuralpszr/OAKD_Camera_Virtualcam)](https://github.com/onuralpszr/OAKD_Camera_Virtualcam/issues)
![GitHub pull requests](https://img.shields.io/github/issues-pr-raw/onuralpszr/OAKD_Camera_Virtualcam)
![cpp](https://img.shields.io/badge/C++20-Project-blue.svg?style=flat&logo=c%2B%2B)
[![Conventional Commits](https://img.shields.io/badge/Conventional%20Commits-1.0.0-%23FE5196?logo=conventionalcommits&logoColor=white)](https://conventionalcommits.org)
[![Fedora-37 CI Build](https://github.com/onuralpszr/OAKD_Camera_Virtualcam/actions/workflows/fedora-ci.yml/badge.svg)](https://github.com/onuralpszr/OAKD_Camera_Virtualcam/actions/workflows/fedora-ci.yml)
[![Ubuntu CI Build](https://github.com/onuralpszr/OAKD_Camera_Virtualcam/actions/workflows/ubuntu-ci.yml/badge.svg)](https://github.com/onuralpszr/OAKD_Camera_Virtualcam/actions/workflows/ubuntu-ci.yml)
[![Fedora](https://img.shields.io/badge/Fedora-51A2DA.svg?logo=fedora&logoColor=white)](https://getfedora.org/)
[![Ubuntu](https://img.shields.io/badge/Ubuntu-FE7A16.svg?logo=Ubuntu&logoColor=white)](https://ubuntu.com/)

The goal of this project is to use the OAK-D camera, a special AI camera, as a webcam in Linux systems. The project will utilize the depthai-core library and v4l2loopback to create a virtual video device that can be accessed by any application that uses a webcam.

The depthai-core library provides an easy-to-use interface for accessing the OAK-D camera's features, such as depth and color data. By integrating this library with v4l2loopback, we can create a virtual webcam device that emulates the OAK-D camera's output, making it compatible with any application that uses a webcam.

The project will involve setting up the OAK-D camera and installing the necessary software packages, including the depthai-core library and v4l2loopback. Then, we will use a compiled DepthAiWebcam executable that initializes the camera, configures the camera's output format, and starts streaming data to the virtual webcam device.

Finally, we will test the virtual webcam device with various applications, such as video conferencing software, streaming software, and web browsers, to ensure compatibility and functionality.


## Depthai library dependencies
- cmake >= 3.10
- libusb1 development package
- C/C++14 or above
 

## Submodules
Make sure submodules are initialized and updated 
```
git submodule update --init --recursive
```

## Prerequisites

To use the OAK-D camera as a webcam with v4l2loopback in Linux, you will need to have the following packages installed:

- OpenCV (version 4 or higher)
- v4l2loopback
- depthai-core
- OpenCV development package (opencv-devel/libopencv-dev)
- GCC (version 10 or higher)
- CMake (version 3.16 or higher)
- CLI11 (version 1.9.1 or higher)
- libusb1 (version 1.0 or higher)

## Installing Prerequisites

You can install these packages on Ubuntu or Debian-based systems using the following command:

### Ubuntu 
[![Ubuntu](https://img.shields.io/badge/Ubuntu-FE7A16.svg?logo=Ubuntu&logoColor=white)](https://ubuntu.com/)

```sh
sudo apt-get install libopencv-dev v4l2loopback-dkms build-essential cmake libcli11-dev libusb-1.0-0-dev libusb-1.0-0
```

### Fedora 
[![Fedora](https://img.shields.io/badge/Fedora-51A2DA.svg?logo=fedora&logoColor=white)](https://getfedora.org/)

For Fedora, you can use the following commands to install the required packages:

```sh
sudo dnf install https://download1.rpmfusion.org/free/fedora/rpmfusion-free-release-$(rpm -E %fedora).noarch.rpm
sudo dnf install https://download1.rpmfusion.org/nonfree/fedora/rpmfusion-nonfree-release-$(rpm -E %fedora).noarch.rpm
sudo dnf install akmod-v4l2loopback opencv-devel gcc gcc-c++ cmake cli11-devel opencv libusb1 libusb1-devel
```

Additionally, you will need to have the OAK-D camera and the necessary drivers installed on your system. Please refer to the OAK-D documentation for instructions on how to set up the camera.

Note: Make sure to have the latest versions of all the packages installed to avoid compatibility issues.

## Building

Configure and build
```sh
mkdir -p build && cd build
cmake ..
cmake --build . --parallel $(($(nproc) - 1))
```

## Create Virtual Webcam with v4l2loopback

```sh
sudo modprobe -r v4l2loopback && sudo modprobe v4l2loopback devices=1 video_nr=10 card_label="Virtual OAK-D" exclusive_caps=1 max_buffers=2
```
## Running

To run the example application 'DepthAiWebcam', navigate to build directory and run 'DepthAiWebcam' executable
```sh
./DepthAiWebcam
```

