import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    id: root
    width: 538
    height: 405

    function refresh() {
        spv1.visible = (call.genPaperStep() === 1 && tabView.examMode === 0)
        spv2.visible = (call.genPaperStep() === 2 && tabView.examMode === 0)
        spv3.visible = (call.genPaperStep() === 3 && tabView.examMode === 0)
        showProbTextArea1.text = call.genPaperProb()[0]
        showProbTextField1.text = call.genPaperProb()[1]
        showProbTextField2.text = call.genPaperProb()[2]
        showProbTextField3.text = call.genPaperProb()[3]
        showProbTextField4.text = call.genPaperProb()[4]
        showProbCheckBox.checked = call.genPaperProb()[5]
        showProbPageLabel.text = call.genPaperPageNumber()
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
        visible: call.genPaperStep() === 1 && tabView.examMode === 0

        Label {
            text: qsTr("试卷名称")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        TextField {
            id: paperName
        }

        Button {
            text: qsTr("选择试题")
            onClicked: {
                call.genPaperChooseProblem(paperName.text)
                root.refresh()
            }
        }
    }

    SplitView {
        id: spv2
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        orientation: Qt.Vertical
        visible: call.genPaperStep() === 2 && tabView.examMode === 0

        Label {
            text: qsTr("试题")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        TextArea {
            id: showProbTextArea1
            text: call.genPaperProb()[0]
            readOnly: true
        }

        Label {
            id: showProbLabel2
            text: qsTr("A")
        }

        TextField {
            id: showProbTextField1
            text: call.genPaperProb()[1]
            readOnly: true
        }

        Label {
            id: showProbLabel3
            text: qsTr("B")
        }

        TextField {
            id: showProbTextField2
            text: call.genPaperProb()[2]
            readOnly: true
        }

        Label {
            id: showProbLabel4
            text: qsTr("C")
        }

        TextField {
            id: showProbTextField3
            text: call.genPaperProb()[3]
            readOnly: true
        }

        Label {
            id: showProbLabel5
            text: qsTr("D")
        }

        TextField {
            id: showProbTextField4
            text: call.genPaperProb()[4]
            readOnly: true
        }

        CheckBox {
            id: showProbCheckBox
            width: parent.width / 2
            text: qsTr("是否判断题(如果是，则只有AB选项有作用)")
            checked: call.genPaperProb()[5]
            onClicked: {
                checked = call.genPaperProb()[5]
            }
        }

        SplitView {
            orientation: Qt.Horizontal
            Button {
                id: showProbPrevButton
                text: qsTr("前一题")
                width: parent.width / 3
                onClicked: {
                    call.genPaperPrev()
                    root.refresh()
                }
            }

            Label {
                id: showProbPageLabel
                text: call.genPaperPageNumber()
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                width: parent.width / 3

            }

            Button {
                id: showProbNextButton
                text: qsTr("后一题")
                width: parent.width / 3
                onClicked: {
                    call.genPaperNext()
                    root.refresh()
                }
            }
        }

        SplitView {
            orientation: Qt.Horizontal

            Button {
                text: qsTr("添加到试卷")
                width: parent.width / 2
                onClicked: {
                    call.genPaperAddToPaper()
                    root.refresh()
                }
            }

            Button {
                text: qsTr("试题选择结束")
                width: parent.width / 2
                onClicked: {
                    call.genPaperFinish()
                    root.refresh()
                }
            }
        }
    }

    SplitView {
        id: spv3
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: parent.width / 3
        anchors.rightMargin: parent.width / 3
        orientation: Qt.Vertical
        visible: call.genPaperStep() === 3 && tabView.examMode === 0

        Label {
            text: qsTr("添加试卷成功")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Button {
            text: qsTr("继续添加")
            onClicked: {
                call.genPaperSetTitle()
                root.refresh()
            }
        }
    }
}
