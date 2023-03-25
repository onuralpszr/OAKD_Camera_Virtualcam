#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "include/ImageWriter.h"
#include "include/AppBridge.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<ImageWriter>("dai.gui", 1, 0, "ImageWriter"); // Register the ImageWriter class
    qmlRegisterType<AppBridge>("dai.gui", 1, 0, "ImageWriter"); // Register the AppWrite class

    const QUrl url(QStringLiteral("qrc:ui/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
