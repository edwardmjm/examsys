import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    TabView {
        id: tabView
        anchors.topMargin: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.fill: parent
        currentIndex: 6

        Tab {
            title : qsTr("试题维护")
        }
        Tab {
            title : qsTr("生成试卷")
        }
        Tab {
            title : qsTr("题目呈现")
        }
        Tab {
            title : qsTr("考试")
        }
        Tab {
            title : qsTr("评分")
        }
        Tab {
            title : qsTr("成绩")
        }

        Tab {
            id: probInput
            title : qsTr("试题录入")

            SplitView {
                id: splitView1
                x: 0
                y: 24
                width: 640
                height: 456
                orientation: Qt.Vertical

                Label {
                    id: label1
                    text: qsTr("试题")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }

                TextArea {
                    id: textArea1
                }

                Label {
                    id: label2
                    text: qsTr("答案一")
                }

                TextField {
                    id: textField1
                    placeholderText: qsTr("Text Field")
                }

                Label {
                    id: label3
                    text: qsTr("答案二")
                }

                TextField {
                    id: textField2
                    placeholderText: qsTr("Text Field")
                }
            }
        }
    }
}
