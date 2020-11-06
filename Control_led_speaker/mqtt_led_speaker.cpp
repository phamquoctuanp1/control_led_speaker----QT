#include "mqtt_led_speaker.h"

Mqtt_led_speaker::Mqtt_led_speaker()
{
    mqttClient.setHostname("10.0.50.68");
    mqttClient.setPort(1883);

    connect(&mqttClient, &QMqttClient::stateChanged,
            this, &Mqtt_led_speaker::onStateChanged);
    connect(&mqttClient, &QMqttClient::connected,
            this, &Mqtt_led_speaker::onConnected);
    connect(&mqttClient, &QMqttClient::messageReceived,
            this, &Mqtt_led_speaker::onMessageReceived);

    connect(this, &Mqtt_led_speaker::goidien,
            this, &Mqtt_led_speaker::onGoidien);
}

void Mqtt_led_speaker::connectHost()
{
    // error
    mqttClient.connectToHost();
}

void Mqtt_led_speaker::kichHoat(QString message)
{
    emit goidien(message);

}

void Mqtt_led_speaker::onStateChanged(QMqttClient::ClientState state)
{
    log << state;
}
void Mqtt_led_speaker::onConnected()
{


    mqttClient.publish(QMqttTopicName("led"), "{\"speaker\":1}");
    log << "connected";
    //   QMqttSubscription *m  = mqttClient.subscribe(QMqttTopicFilter("led"));
    //   connect(m,&QMqttSubscription::stateChanged,this,&Mqtt_led_speaker::updateStatus);

}

void Mqtt_led_speaker::onGoidien(QString message)
{
    log << message;
}

void Mqtt_led_speaker::onMessageReceived(const QByteArray &message, const QMqttTopicName &topic)
{
    log << message;
    log << topic;
}

void Mqtt_led_speaker::updateStatus(QMqttSubscription::SubscriptionState state)
{
    log << state<<"subscribe";
}
void Mqtt_led_speaker::on_off_led()
{
    qint32 trave;

    trave = mqttClient.publish(QMqttTopicName("led"),"{led:1}");

    log << trave<<"b";


    // QMqttSubscription *m  = mqttClient.subscribe(QMqttTopicFilter("led"));log << "c";
    //connect(m,&QMqttSubscription::stateChanged,this,&Mqtt_led_speaker::updateStatus);log << "d";

}
void Mqtt_led_speaker::on_off_speaker()
{

    log << __LINE__<<__PRETTY_FUNCTION__;
    mqttClient.publish(QMqttTopicName("led"),"{\"speaker\":1}");

    //QMqttSubscription *m  = mqttClient.subscribe(QMqttTopicFilter("led"));
    //connect(m,&QMqttSubscription::stateChanged,this,&Mqtt_led_speaker::updateStatus);

}

void Mqtt_led_speaker::testled()
{
    log << "..testled...";

    try
    {
        log << "1";
        on_off_led();
        log << "3";
    }
    catch (...)
    {
        log << "..error1...";
    }

}
void Mqtt_led_speaker::testspeaker()
{
    log << "..testspesker...";

    try
    {
        on_off_speaker();
    }
    catch (...)
    {
        log << "..error2...";
    }

}
