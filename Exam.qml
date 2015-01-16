import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    id: root
    width: 538
    height: 405

    property int step: 1

    function refresh() {
        cb.model = call.comboBoxModel();
        spv1.visible = step === 1
        spv2.visible = step === 2
        p0.text = call.examProb()[0]
        p1.text = call.examProb()[1]
        p2.text = call.examProb()[2]
        p3.text = call.examProb()[3]
        p4.text = call.examProb()[4]
        p5.checked = call.examProb()[5]
        pageInfo.text = call.examProbPageNumber()
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
        visible: root.step === 1

        Label {
            text: qsTr("选择试卷")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        ComboBox {
            id: cb
            model: call.comboBoxModel()
        }

        Label {
            text: qsTr("学号")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        TextField {
            id: studentId
        }

        Button {
            text: qsTr("进入考试")
            onClicked: {
                tabView.examMode = 1
                root.step = 2
                call.enterExamMode(studentId.text, cb.currentIndex)
                root.refresh()
            }
        }
    }

    SplitView {
        id: spv2
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        orientation: Qt.Vertical
        visible: step === 2

        Label {
            text: qsTr("试题")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        TextArea {
            id: p0
            text: call.examProb()[0]
            readOnly: true
        }

        Label {
            text: qsTr("A")
        }

        TextField {
            id: p1
            text: call.examProb()[1]
            readOnly: true
        }

        Label {
            id: showProbLabel3
            text: qsTr("B")
        }

        TextField {
            id: p2
            text: call.examProb()[2]
            readOnly: true
        }

        Label {
            text: qsTr("C")
        }

        TextField {
            id: p3
            text: call.examProb()[3]
            readOnly: true
        }

        Label {
            text: qsTr("D")
        }

        TextField {
            id: p4
            text: call.examProb()[4]
            readOnly: true
        }

        CheckBox {
            id: p5
            text: qsTr("是否判断题(如果是，则只有AB选项有作用)")
            checked: call.examProb()[5]
            onClicked: {
                checked = call.examProb()[5]
            }
        }

        Label {
            text: qsTr("你的答案(输入0~3分别表示选择第几个答案)")
        }

        TextField {
            id: answer
        }

        SplitView {
            orientation: Qt.Horizontal
            Button {
                text: qsTr("前一题")
                width: parent.width / 3

                onClicked: {
                    call.examAddRecord(answer.text)
                    call.examProbPrev()
                    root.refresh()
                }
            }

            Label {
                id: pageInfo
                text: call.examProbPageNumber()
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                width: parent.width / 3

            }

            Button {
                text: qsTr("后一题")
                width: parent.width / 3
                onClicked: {
                    call.examAddRecord(answer.text)
                    call.examProbNext()
                    root.refresh()
                }
            }
        }
        Button {
            text: qsTr("交卷")
            onClicked: {
                call.examAddRecord(answer.text)
                call.submitSolution()
                root.step = 1
                tabView.examMode = 0
                root.refresh()
            }
        }
    }
}
