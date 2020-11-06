import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import Mqtt_led_speaker 1.0

Window {
    width: 200
    height: 100
    visible: true
    title: qsTr("control")

    Mqtt_led_speaker {
        id: test
    }

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.margins: appWindow.margin
        GroupBox {
            id: rowBox
            title: "control"
            Layout.fillWidth: true

            RowLayout {
                id: rowLayout
                anchors.fill: parent

                Button {
                    id: button
                    text: "led"
                    onClicked: {
                        console.log("test led")
                        console.log(test.testled())
                       }
                }
                Button {
                    id: button1
                    text: "speaker"
                    onClicked: {
                        console.log("test speaker")
                        console.log(test.testspeaker())
                       }
                }
            }
        }
    }
}
