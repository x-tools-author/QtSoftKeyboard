import QtQuick 2.12
import QtQuick.Controls 2.12

import CustomKeyboard 1.0

Rectangle {
    id: root
    width: 108*3
    height: 108*4
    border.width: 1
    border.color: "#DDDDDD"

    property var keys: controller.keys

    KeyboardBackend {
        id: controller
    }

    Grid {       
        columns: 3
        spacing: 0
        Repeater {
            id: keysRepeater
            model: keys
            Rectangle {
                width: 108
                height: 108
                border.width: 1
                border.color: "#DDDDDD"

                Label {
                    text: modelData
                    color: button.pressed ?  "#FF0000" : "#4A4A4A"
                    font.pixelSize: 32
                    anchors.centerIn: parent
                }

                MouseArea {
                    id: button
                    anchors.fill: parent

                    onClicked: {
                        controller.postEvent(index)
                    }
                }
            }
        }
    }
}
