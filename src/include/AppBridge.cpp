// AppBridge.cpp
#include "AppBridge.h"
#include <QVariant>

AppBridge::AppBridge(QObject *parent)
        : QObject(parent) {

    mPipelineManager

}

void AppBridge::setInstance(QObject *obj) {
    instance = obj;
}

void AppBridge::changeSelected(QString state) {
    instance->setProperty("selected", state);
}

void AppBridge::toggleLeftRightCheck(bool state) {
    instance->setProperty("leftRightCheck", state);
}

void AppBridge::setDisparityConfidenceThreshold(int value) {
    instance->setProperty("disparityConfidenceThreshold", value);
}

void AppBridge::setMedianFilter(QString state) {
    instance->setProperty("medianFilter", QVariant(state).toInt());
}