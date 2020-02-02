import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: root
    visible: true
    width: 640
    height: 640
    title: qsTr("Qt Soft Keyboard")

    Column {
        spacing: 10
        anchors.fill: parent

        Row {
            width: root.width
            Label {
                text: qsTr("预选框")
                anchors.verticalCenter: parent.verticalCenter
            }

            ComboBox {
                width: root.width/2
                model: [qsTr("该控件的目的是使得输入框失去焦点")]
            }
        }

        Row {
            width: root.width
            Label {
                text: qsTr("输入框")
                anchors.verticalCenter: parent.verticalCenter
            }

            TextField {
                id: textField
            }
        }

        Keyboard {
            anchors.horizontalCenter: parent.horizontalCenter
            visible: textField.activeFocus
        }
    }
}
