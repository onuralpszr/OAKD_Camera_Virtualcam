#ifndef DEPTHAIWEBCAM_IMAGEWRITER_H
#define DEPTHAIWEBCAM_IMAGEWRITER_H

#include <QQuickPaintedItem>
#include <QImage>
#include <QPainter>

class ImageWriter : public QQuickPaintedItem {
Q_OBJECT
    Q_PROPERTY(QImage frame READ getFrame WRITE setFrame NOTIFY frameChanged)

public:
    explicit ImageWriter(QQuickItem* parent = nullptr);

    [[nodiscard]] QImage getFrame() const;

public slots:
    void setFrame(const QImage& image);

signals:
    void frameChanged();

protected:
    void paint(QPainter* painter) override;

private:
    QImage mFrame;
};

#endif //DEPTHAIWEBCAM_IMAGEWRITER_H
