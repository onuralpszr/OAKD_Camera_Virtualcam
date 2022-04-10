#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>

// include depthai library
#include <depthai/depthai.hpp>

// include opencv library
#include <opencv2/opencv.hpp>


#define VID_WIDTH  1200
#define VID_HEIGHT 720
#define VIDEO_OUT "/dev/video10"


int main(){

    dai::Pipeline pipeline;
    std::shared_ptr<dai::node::ColorCamera> colorCam = pipeline.create<dai::node::ColorCamera>();
    std::shared_ptr<dai::node::XLinkOut> xlinkOut = pipeline.create<dai::node::XLinkOut>();
    colorCam->setColorOrder(dai::ColorCameraProperties::ColorOrder::RGB);
    colorCam->setResolution(dai::ColorCameraProperties::SensorResolution::THE_4_K);
    colorCam->setPreviewSize(VID_WIDTH,VID_HEIGHT);

    xlinkOut->setStreamName("Camera");
    colorCam->setInterleaved(true);
    colorCam->preview.link(xlinkOut->input);
    colorCam->setFps(60);

    // open output device
    int output = open(VIDEO_OUT, O_RDWR);
    if(output < 0) {
        std::cerr << "ERROR: could not open output device!\n" << strerror(errno);
        return -2;
    }


    // Configure parameters for output device
    struct v4l2_format vid_format;
    memset(&vid_format, 0, sizeof(vid_format));
    vid_format.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;


    if (ioctl(output, VIDIOC_G_FMT, &vid_format) < 0) {
        std::cerr << "ERROR: unable to get video format!\n" << strerror(errno);
        return -1;
    }

    size_t frameSize = VID_WIDTH * VID_HEIGHT * 3;
    vid_format.fmt.pix.width = VID_WIDTH;
    vid_format.fmt.pix.height = VID_HEIGHT;
    vid_format.fmt.pix.pixelformat = V4L2_PIX_FMT_RGB24;
    vid_format.fmt.pix.sizeimage = frameSize;
    vid_format.fmt.pix.field = V4L2_FIELD_NONE;



    if (ioctl(output, VIDIOC_S_FMT, &vid_format) < 0) {
        std::cerr << "ERROR: unable to set video format!\n" << strerror(errno);
        return -1;
    }

    try {
        // Try connecting to device and start the pipeline
        dai::Device device(pipeline);
        // Get output queue
        std::shared_ptr<dai::DataOutputQueue> preview = device.getOutputQueue("Camera");

        while (true) {

            // Receive frame from device
            std::shared_ptr<dai::ImgFrame> imgFrame = preview->get<dai::ImgFrame>();
            cv::Mat frameResult = cv::Mat(imgFrame->getHeight(), imgFrame->getWidth(), CV_8UC3, imgFrame->getData().data());

            // Write frame to output device
            size_t written = write(output, frameResult.data, frameSize);
            if (written < 0) {
                std::cerr << "ERROR: could not write to output device!\n";
                close(output);
                break;
            }
            // Wait and check if 'q' pressed
            if (cv::waitKey(1) == 'q') return 0;

        }
    } catch (const std::runtime_error& err) {
        std::cout << err.what() << std::endl;
    }

    // End stream
    if(ioctl(output, VIDIOC_STREAMOFF, &vid_format) < 0){
        std::cout << "Could not end streaming, VIDIOC_STREAMOFF" << std::endl;
        return 1;
    }

    close(output);
    return 0;
}