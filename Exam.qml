import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    id: root
    width: 538
    height: 405

    function refresh() {
        cb.model = call.comboBoxModel();
    }

    Component.onCompleted: {
        tabView.handleRefresh.connect(root.refresh)
    }

    SplitView {
        id: spv1
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: parent.width / 3
        anchors.rightMargin: parent.width / 3
        orientation: Qt.Vertical

        Label {
            text: qsTr("选择试卷")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        ComboBox {
            id: cb
            model: call.comboBoxModel()
        }

        Button {
            text: qsTr("进入考试")
            onClicked: {
                //TODO
            }
        }
    }
}
