#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <mqtt_led_speaker.h>
#include <QQmlContext>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Mqtt_led_speaker m;
    m.connectHost();

    qmlRegisterType<Mqtt_led_speaker>("Mqtt_led_speaker", 1, 0, "Mqtt_led_speaker");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl)
    {
        if (!obj && url == objUrl)
        {
            QCoreApplication::exit(-1);
        }
    }, Qt::QueuedConnection);

    engine.load(url);
    engine.rootContext()->setContextProperty("ryu", &m);

    return app.exec();

}
