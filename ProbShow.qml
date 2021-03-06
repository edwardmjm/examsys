import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    id: root
    width: 538
    height: 405

    function refresh() {
        showProbSplitView.visible = tabView.examMode === 0
        showProbTextArea1.text = call.showProb()[0]
        showProbTextField1.text = call.showProb()[1]
        showProbTextField2.text = call.showProb()[2]
        showProbTextField3.text = call.showProb()[3]
        showProbTextField4.text = call.showProb()[4]
        showProbCheckBox.checked = call.showProb()[5]
        showProbPageLabel.text = call.showProbPageNumber()
    }

    Component.onCompleted: {
        tabView.handleRefresh.connect(root.refresh)
    }

    SplitView {
        id: showProbSplitView
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        orientation: Qt.Vertical
        visible: tabView.examMode === 0

        Label {
            text: qsTr("试题")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        TextArea {
            id: showProbTextArea1
            text: call.showProb()[0]
        }

        Label {
            id: showProbLabel2
            text: qsTr("A")
        }

        TextField {
            id: showProbTextField1
            text: call.showProb()[1]
        }

        Label {
            id: showProbLabel3
            text: qsTr("B")
        }

        TextField {
            id: showProbTextField2
            text: call.showProb()[2]
        }

        Label {
            id: showProbLabel4
            text: qsTr("C")
        }

        TextField {
            id: showProbTextField3
            text: call.showProb()[3]
        }

        Label {
            id: showProbLabel5
            text: qsTr("D")
        }

        TextField {
            id: showProbTextField4
            text: call.showProb()[4]
        }

        CheckBox {
            id: showProbCheckBox
            text: qsTr("是否判断题(如果是，则只有AB选项有作用)")
            checked: call.showProb()[5]
        }

        SplitView {
            orientation: Qt.Horizontal
            Button {
                id: showProbPrevButton
                text: qsTr("前一题")
                width: parent.width / 3

                onClicked: {
                    call.showProbPrev()
                    root.refresh()
                }
            }

            Label {
                id: showProbPageLabel
                text: call.showProbPageNumber()
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                width: parent.width / 3

            }

            Button {
                id: showProbNextButton
                text: qsTr("后一题")
                width: parent.width / 3
                onClicked: {
                    call.showProbNext()
                    root.refresh()
                }
            }
        }

        SplitView {
            orientation: Qt.Horizontal

            Button {
                text: qsTr("更新题目")
                width: parent.width / 2
                onClicked: {
                    call.editProblem(
                                showProbTextArea1.text,
                                showProbTextField1.text,
                                showProbTextField2.text,
                                showProbTextField3.text,
                                showProbTextField4.text,
                                showProbCheckBox.checked)
                    root.refresh()
                }
            }

            Button {
                text: qsTr("删除题目")
                width: parent.width / 2
                onClicked: {
                    call.removeProblem()
                    root.refresh()
                }
            }
        }
    }
}
