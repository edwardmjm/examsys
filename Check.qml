import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    id: root
    width: 538
    height: 405

    property int step: 1

    function refresh() {
        cb.model = call.resultComboBoxModel();
        spv1.visible = step === 1 && tabView.examMode === 0
        spv2.visible = step === 2 && tabView.examMode === 0
        p0.text = call.checkProb()[0]
        p1.text = call.checkProb()[1]
        p2.text = call.checkProb()[2]
        p3.text = call.checkProb()[3]
        p4.text = call.checkProb()[4]
        p5.text = call.checkProb()[5]
        p6.text = call.checkProb()[6]
        pageInfo.text = call.checkProbPageNumber()
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
        visible: root.step === 1 && tabView.examMode === 0

        ComboBox {
            id: cb
            model: call.resultComboBoxModel()
        }

        Button {
            text: qsTr("查看")
            onClicked: {
                call.setCheckId(cb.currentIndex)
                root.step = 2
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
        visible: root.step === 2 && tabView.examMode === 0

        Label {
            text: qsTr("试题")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        TextArea {
            id: p0
            text: call.checkProb()[0]
        }

        Label {
            text: qsTr("A")
        }

        TextField {
            id: p1
            text: call.checkProb()[1]
        }

        Label {
            text: qsTr("B")
        }

        TextField {
            id: p2
            text: call.checkProb()[2]
        }


        Label {
            text: qsTr("C")
        }

        TextField {
            id: p3
            text: call.checkProb()[3]
        }


        Label {
            text: qsTr("D")
        }

        TextField {
            id: p4
            text: call.checkProb()[4]
        }


        CheckBox {
            id: p5
            text: qsTr("是否判断题(如果是，则只有AB选项有作用)")
            checked: call.checkProb()[5]
        }

        Label {
            text: qsTr("考生答案")
        }

        TextField {
            id: p6
            text: call.checkProb()[6]
        }

        SplitView {
            orientation: Qt.Horizontal
            Button {
                text: qsTr("前一题")
                width: parent.width / 3

                onClicked: {
                    call.checkProbPrev()
                    root.refresh()
                }
            }

            Label {
                id: pageInfo
                text: call.checkProbPageNumber()
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                width: parent.width / 3

            }

            Button {
                text: qsTr("后一题")
                width: parent.width / 3
                onClicked: {
                    call.checkProbNext()
                    root.refresh()
                }
            }
        }

        Button {
            text: qsTr("返回")
            onClicked: {
                root.step = 1
                root.refresh()
            }
        }
    }

}

