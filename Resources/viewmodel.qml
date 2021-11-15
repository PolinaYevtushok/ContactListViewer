import QtQuick 2.0


ListView {
    id: root
    width: 400; height: 600
    required model
    signal clicked(msg: string)

    delegate: Rectangle {
        id:contact
        color: "lightgreen"
        border.width: 1
        border.color: "black"
        radius: 5

        required property string name
        required property string image

        height: 50
        width: parent.width
        Text {
            text: parent.name
            anchors.centerIn: parent
        }
        Image {
            anchors.left: parent.left
            anchors.leftMargin: 4
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height - 10
            width: height
            source: parent.image
        }
        MouseArea {
            anchors.fill: parent
            onClicked: root.clicked(contact.name)
        }
    }
}

