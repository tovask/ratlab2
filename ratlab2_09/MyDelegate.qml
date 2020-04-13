import QtQuick 2.0

Item {
    id: root

    width: 200
    height: width
    z: PathView.zOrder

    transform: [
            Rotation {
                angle: root.PathView.rotateY
                origin.x: delegate.width / 2
                origin.y: delegate.height * 0.3
                axis.x: 0
                axis.y: 1
                axis.z: 0
            },
            Scale {
                xScale: 1.0
                yScale: root.PathView.scale
                origin.x: delegate.width / 2
                origin.y: delegate.height * 0.4
            }
        ]

    Image{
        id: delegate
        anchors.fill: parent
        source: imageName
        Rectangle{
            anchors.fill: parent
            color: "lightGrey"
            z: -1
        }
    }
    Rectangle {
        color: "#55d6d2d0"
        Text {
            text: teamName
            font.pixelSize: 32
            width: parent.width
            horizontalAlignment: Text.AlignHCenter
        }
        y: delegate.height + 50
        width: childrenRect.width
        height: childrenRect.height
        anchors.horizontalCenter: delegate.horizontalCenter
        z: 200
    }

    ShaderEffectSource {
        id: reflection
        sourceItem: delegate
        y: sourceItem.height
        width: sourceItem.width
        height: sourceItem.height

        transform: [
            Rotation {
                origin.x: reflection.width / 2
                origin.y: reflection.height / 2
                axis.x: 1
                axis.y: 0
                axis.z: 0
                angle: 180
            }
        ]

        Rectangle {
            anchors.fill: reflection
            gradient: Gradient {
                    GradientStop { position: 0.0; color: "#ffd6d2d0" }
                    GradientStop { position: 1.0; color: "#aad6d2d0" }
                }
        }
    }
}
