import QtQuick 2.0
import QtQuick.Controls 1.2


Rectangle {
    id: root
    width: 538
    height: 405

    SplitView {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: parent.width / 3
        anchors.rightMargin: parent.width / 3
        orientation: Qt.Vertical
        Button {
            text: qsTr("保存")
            onClicked: {
                call.save()
            }
        }
        Button {
            text: qsTr("读取")
            onClicked: {
                call.load()
            }
        }
    }
}

