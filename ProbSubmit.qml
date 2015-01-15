import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    id: root
    width: 538
    height: 405

    function refresh() {
        splitView1.visible = tabView.examMode === 0
    }

    Component.onCompleted: {
        tabView.handleRefresh.connect(root.refresh)
    }

    SplitView {
        id: splitView1
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        visible: tabView.examMode === 0
        orientation: Qt.Vertical

        Label {
            id: submitProbLabel1
            text: qsTr("试题")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        TextArea {
            id: submitProbTextArea1
        }

        Label {
            id: submitProbLabel2
            text: qsTr("A")
        }

        TextField {
            id: submitProbTextField1

        }

        Label {
            id: submitProbLabel3
            text: qsTr("B")
        }

        TextField {
            id: submitProbTextField2
        }

        Label {
            id: submitProbLabel4
            text: qsTr("C")
        }

        TextField {
            id: submitProbTextField3
        }

        Label {
            id: submitProbLabel5
            text: qsTr("D")
        }

        TextField {
            id: submitProbTextField4
        }

        CheckBox {
            id: submitProbCheckBox
            text: qsTr("是否判断题(打钩后ABCD框内填的内容不生效)")
        }

        Button {
            id: submitProbButton
            text: qsTr("提交试题")
            onClicked: {
                call.submitProblem(
                             submitProbTextArea1.text,
                             submitProbTextField1.text,
                             submitProbTextField2.text,
                             submitProbTextField3.text,
                             submitProbTextField4.text,
                             submitProbCheckBox.checked)
            }
        }
    }
}
