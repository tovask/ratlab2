import QtQuick 2.3
import QtQuick.Controls 1.2

// https://github.com/blazovics/RATLAB_QT/wiki/09-Labor

ApplicationWindow {
    visible: true
    width: 1400
    height: 750
    title: qsTr("Ratlab2 09 SDE06")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    PathView {
        id: pathView
        anchors.fill: parent
        property real centerX: width / 2
        property real vertOff: height / 2
        delegate: MyDelegate {}
        model: MyModell {}
        path: CoverFlowPath {
            pathView: pathView
        }
        focus: true
        Keys.onLeftPressed: decrementCurrentIndex()
        Keys.onRightPressed: incrementCurrentIndex()
    }
}
