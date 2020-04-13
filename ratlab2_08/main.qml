import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("ratlab_08_KL")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            /*MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }*/
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Text {
        text: qsTr("")//Hello World")
        anchors.centerIn: parent
    }

    PanelMeter {
        id: temperatureMeter
        x: 10
        y: 10
        objectName: "TemperatureMeter"
    }

    PanelMeter {
        id: tiltMeter
        x: 310
        y: 10
        objectName: "TiltMeter"
    }
}
