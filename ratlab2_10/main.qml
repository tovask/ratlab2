import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 1280
    height: 720
    title: qsTr("Ratlab2 10 SDE06")

    TextInput {
        id: qparam
        x: 10
        y: 10
        width: 200
        text: qsTr("paprika")
        font.pixelSize: 24
        focus: true
        onAccepted: {
            mouseArea.download(qparam.text);
        }
    }

    MouseArea {
        id: mouseArea
        objectName: "mouseArea"
        x: 275
        y: 10
        width: 75
        height: 35

        Text {
            text: "Search...";
            font.pixelSize: 20;
            color: "blue";
            anchors.centerIn: parent
        }

        signal download(variant qparam)

        onClicked: {
            download(qparam.text)
        }
    }

    ListView {
        anchors.top: mouseArea.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        clip: true
        model: recipeModel
        delegate: Rectangle {
            id: wrapper
            width: parent.width
            height: 100
            color: "transparent"
            clip: true
            Rectangle {
                anchors.fill: parent
                anchors.margins: 5
                color: index % 2 == 0 ? "lightsteelblue" : "lightskyblue"

                Row {
                    spacing: 10
                    Image {
                        source: thumbnail
                    }
                    Column {
                        spacing: 5
                        Label {
                            text: index
                        }
                        Label {
                            text: title
                        }
                        Label {
                            text: href
                        }
                        Label {
                            text: ingredients
                        }
                    }
                }
            }
        }
        highlight: Rectangle { color: "gray"; radius: 5 }
        focus: true
    }
}
