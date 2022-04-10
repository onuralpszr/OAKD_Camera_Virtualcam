# OAK-D Webcam Project 

This project shows how to run oak-d camera as virtualcam in linux with depthai-core

## Depthai library dependencies
- cmake >= 3.10
- libusb1 development package
- C/C++14 compiler
 

## Submodules
Make sure submodules are initialized and updated 
```
git submodule update --init --recursive
```

## Prerequisites 

- DepthAi-Core
- OpenCV
- v4l2loopback

## Installing Prerequisites

### Fedora 

v4l2loopback can be install after add RPMFusion repository (https://rpmfusion.org/Configuration)

```
dnf install -y opencv v4l2loopback akmod-v4l2loopback libusb1
```

## Building

Configure and build
```
mkdir -p build && cd build
cmake ..
cmake --build . --parallel
```

## Running

To run the example application 'DepthAiWebcam', navigate to build directory and run 'DepthAiWebcam' executable
```
./DepthAiWebcam
```

## Create Virtual Webcam with v4l2loopback

```
sudo modprobe -r v4l2loopback && sudo modprobe v4l2loopback devices=1 video_nr=10 card_label="Virtual OAK-D" exclusive_caps=1 max_buffers=2
```
