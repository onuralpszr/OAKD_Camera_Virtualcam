# OAK-D Webcam Project (Linux Only)

![GitHub](https://img.shields.io/github/license/onuralpszr/OAKD_Camera_Virtualcam?color=blue)
[![Open issue](https://img.shields.io/github/issues/onuralpszr/OAKD_Camera_Virtualcam)](https://github.com/onuralpszr/OAKD_Camera_Virtualcam/issues)
[![Closed issue](https://img.shields.io/github/issues-closed/onuralpszr/OAKD_Camera_Virtualcam)](https://github.com/onuralpszr/OAKD_Camera_Virtualcam/issues)
![GitHub pull requests](https://img.shields.io/github/issues-pr-raw/onuralpszr/OAKD_Camera_Virtualcam)
![cpp](https://img.shields.io/badge/C++20-Project-blue.svg?style=flat&logo=c%2B%2B)
[![Conventional Commits](https://img.shields.io/badge/Conventional%20Commits-1.0.0-%23FE5196?logo=conventionalcommits&logoColor=white)](https://conventionalcommits.org)


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

- DepthAi-Core
- OpenCV / OpenCV-devel
- v4l2loopback

## Installing Prerequisites

### Fedora 

v4l2loopback can install after add RPMFusion repository (https://rpmfusion.org/Configuration)

```
dnf install -y opencv opencv-devel v4l2loopback akmod-v4l2loopback libusb1
```

## Building

Configure and build
```
mkdir -p build && cd build
cmake ..
cmake --build . --parallel
```

## Create Virtual Webcam with v4l2loopback

```
sudo modprobe -r v4l2loopback && sudo modprobe v4l2loopback devices=1 video_nr=10 card_label="Virtual OAK-D" exclusive_caps=1 max_buffers=2
```
## Running

To run the example application 'DepthAiWebcam', navigate to build directory and run 'DepthAiWebcam' executable
```
./DepthAiWebcam
```

