//
// Created by astrapel on 3/22/23.
//

#include "CameraWorker.h"

CameraWorker::CameraWorker(){
    this->mColorCam = this->mPipelineManager.create<dai::node::ColorCamera>();
    this->mXlinkOutColor = this->mPipelineManager.create<dai::node::XLinkOut>();
    this->mColorCam->setColorOrder(dai::ColorCameraProperties::ColorOrder::RGB);
    this->mPipelineManager.create<dai::node::StereoDepth>();
    //this->mColorCam->setResolution(dai::ColorCameraProperties::SensorResolution::THE_4_K);
    this->mColorCam->setPreviewSize(848,480);

    // Mono Camera Properties
    this->mMonoLeft->setResolution(dai::MonoCameraProperties::SensorResolution::THE_480_P);
    this->mMonoLeft->setBoardSocket(dai::CameraBoardSocket::LEFT);
    this->mMonoRight->setResolution(dai::MonoCameraProperties::SensorResolution::THE_480_P);
    this->mMonoRight->setBoardSocket(dai::CameraBoardSocket::RIGHT);


    this->mXlinkOutColor->setStreamName("ColorCamera");
    this->mColorCam->setInterleaved(true);
    this->mColorCam->preview.link(this->mXlinkOutColor->input);
    this->mColorCam->setFps(60);




};

void CameraWorker::run() {

}

void CameraWorker::terminate() {
}

void CameraWorker::shouldRun() {

}

void CameraWorker::onShowFrame(cv::Mat frame) {

}
