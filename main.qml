import QtQuick 2.0
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("exam system")

    TabView {
        id: tabView
        anchors.fill: parent
        currentIndex: 0

        signal handleRefresh();

        onCurrentIndexChanged: {
            tabView.handleRefresh()
        }

        Tab {
            id: tab1
            anchors.fill: parent
            title : qsTr("试题录入")
            ProbSubmit {
                anchors.fill: parent
                anchors.topMargin: 5
                anchors.leftMargin: 50
                anchors.rightMargin: 50
                anchors.bottomMargin: 50
            }
        }

        Tab {
            id: tab2
            anchors.fill: parent
            title : qsTr("试题维护")

            ProbShow {
                anchors.fill: parent
                anchors.topMargin: 5
                anchors.leftMargin: 50
                anchors.rightMargin: 50
                anchors.bottomMargin: 50
            }
        }

        Tab {
            id: tab3
            title : qsTr("生成试卷")
            anchors.fill: parent
            GenPaper {
                anchors.fill: parent
                anchors.topMargin: 5
                anchors.leftMargin: 50
                anchors.rightMargin: 50
                anchors.bottomMargin: 50
            }
        }

        Tab {
            title : qsTr("考试")
            anchors.fill: parent
            Exam {
                id: exam
                anchors.fill: parent
                anchors.topMargin: 5
                anchors.leftMargin: 50
                anchors.rightMargin: 50
                anchors.bottomMargin: 50
            }
        }
        Tab {
            title : qsTr("评分")
        }
        Tab {
            title : qsTr("成绩")
        }

        Tab {
            title : qsTr("保存/读取")
            SaveLoad {
                id: saveload
                anchors.fill: parent
                anchors.topMargin: 5
                anchors.leftMargin: 50
                anchors.rightMargin: 50
                anchors.bottomMargin: 50
            }
        }
    }
}
