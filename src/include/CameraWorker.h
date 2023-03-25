
#ifndef DEPTHAIWEBCAM_CAMERAWORKER_H
#define DEPTHAIWEBCAM_CAMERAWORKER_H

#include <QRunnable>
#include <QObject>
#include <QString>

#include <vector>
#include <depthai/depthai.hpp>
#include <opencv2/opencv.hpp>


class CameraWorker : public QObject, public QRunnable
{
    Q_OBJECT

public:
    explicit CameraWorker();
    void run() override;
    void terminate();
    void shouldRun();
    void onShowFrame(cv::Mat frame);



private:
    std::vector<QString> mPreviews = {};
    QString mSelectedColor;
    // DepthAI Camera Variables
    dai::Pipeline mPipelineManager;
    // Color Camera
    std::shared_ptr<dai::node::ColorCamera> mColorCam;
    // Mono Left and Right Cameras
    std::shared_ptr<dai::node::MonoCamera> mMonoLeft;
    std::shared_ptr<dai::node::MonoCamera> mMonoRight;
    // Xlink Color,Left and Right Cameras
    std::shared_ptr<dai::node::XLinkOut> mXlinkOutColor;
    std::shared_ptr<dai::node::XLinkOut> mXLinkOutLeft;
    std::shared_ptr<dai::node::XLinkOut> mXLinkOutRight;



};

#endif //DEPTHAIWEBCAM_CAMERAWORKER_H
