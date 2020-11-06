#ifndef MQTT_LED_SPEAKER_H
#define MQTT_LED_SPEAKER_H
#include <QMqttClient>
#include <QObject>
#include <QMqttSubscription>
#include <QMqttTopicFilter>
#include <qmqtttopicname.h>

#include <QDebug>

#define log qDebug() << __LINE__ << Q_FUNC_INFO

class Mqtt_led_speaker : public QObject
{
    Q_OBJECT
    QMqttClient mqttClient;
public:
    Mqtt_led_speaker();
    void connectHost();
    void kichHoat(QString message);
    void on_off_led();
    void on_off_speaker();

//    explicit Mqtt_led_speaker (QObject* parent = 0) : QObject(parent) {}
//        Q_INVOKABLE int reken_tijden_uit(){
//        return 1;

//    }
    Q_INVOKABLE void testled();
    Q_INVOKABLE void testspeaker();


public slots:
    void onStateChanged(QMqttClient::ClientState state);
    void updateStatus(QMqttSubscription::SubscriptionState state);
    void onConnected();
    void onGoidien(QString message);
    void onMessageReceived(const QByteArray &message, const QMqttTopicName &topic);
signals:
    void goidien(QString message="hello");

};

#endif // MQTT_LED_SPEAKER_H
