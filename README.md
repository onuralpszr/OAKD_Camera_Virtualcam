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