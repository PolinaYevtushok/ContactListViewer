import QtQuick 2.0


ListView {
    width: 200; height: 200
    required model

    delegate: Rectangle {
        color: "lightgreen"
        border.width: 1
        border.color: "black"

        required property string name

        height: 25
        width: parent.width
        Text { text: parent.name }
    }
}

