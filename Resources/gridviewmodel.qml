import QtQuick 2.0
import Qt5Compat.GraphicalEffects


GridView {
    id: root
    width: parent
    height: parent
    leftMargin: 2
    rightMargin: 2
    topMargin: 2
    bottomMargin: 2
    cellHeight: 110
    cellWidth: 110

    required model

    signal clicked(msg: string)   

    delegate: Rectangle {
        id:contact
        color: "#06807e"
        radius: 5

        required property string name
        required property string image

        height: 100
        width: height
        Image {
            id: contactImage
            height: contact.height - 30
            width: height
            y: 10
            anchors.horizontalCenter: parent.horizontalCenter
            source: contact.image
            visible: false
        }
        Text {
            text: contact.name
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: contactImage.bottom
            font.pointSize: 20
            font.family: "Courier";
        }
        MouseArea {
            anchors.fill: parent
            onClicked: root.clicked (contact.name)
        }
        OpacityMask {
            anchors.fill: contactImage
            source: contactImage
            maskSource: Rectangle {
                width: contactImage.width
                height: contactImage.height
                radius: 50
                visible: false
            }
        }
    }
}


