#include "ImageWriter.h"

ImageWriter::ImageWriter(QQuickItem *parent) : QQuickPaintedItem(parent) {
    setRenderTarget(QQuickPaintedItem::FramebufferObject);
    setProperty("parent", QVariant::fromValue<QObject*>(parent));
}

void ImageWriter::paint(QPainter *painter) {
    painter->drawImage(0, 0, mFrame);
}

void ImageWriter::setFrame(const QImage &image) {
    if (mFrame != image) {
        mFrame = image;
        emit frameChanged();
        update();
    }
}

QImage ImageWriter::getFrame() const {
    return mFrame;
}
