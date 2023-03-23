#ifndef DEPTHAIWEBCAM_APPBRIDGE_H
#define DEPTHAIWEBCAM_APPBRIDGE_H

#include <QObject>
#include <QVariant>
#include <QMetaObject>
#include <QDebug>
#include <QString>
#include <depthai/depthai.hpp>

class AppBridge : public QObject
{
Q_OBJECT

public:
    explicit AppBridge(QObject* parent = nullptr);
    void setInstance(QObject* obj);

public slots:
    void changeSelected(QString state);
    void toggleLeftRightCheck(bool state);
    void setDisparityConfidenceThreshold(int value);
    void setMedianFilter(QString state);

private:
    QObject* instance{};
};


#endif //DEPTHAIWEBCAM_APPBRIDGE_H
