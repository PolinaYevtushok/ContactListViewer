import QtQuick 2.0
import Qt5Compat.GraphicalEffects


ListView {
    id: root
    width: parent
    height: parent
    spacing: 2
    leftMargin: 2
    rightMargin: 2
    topMargin: 2
    bottomMargin: 2

    required model

    signal clicked(msg: string)
    signal clickedFavorite(msg: string)

    delegate: Rectangle {
        id:contact
        color: "#06807e"
        radius: 5
        height: 50
        width: root.width

        required property string name
        required property string image_photo
        required property string image_favorite

        Text {
            text: parent.name
            anchors.centerIn: parent
            font.pointSize: 20
            font.family: "Courier";
        }
        Image {
            id: contactImage
            anchors.left: parent.left
            anchors.leftMargin: 4
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height - 10
            width: height
            source: parent.image_photo
            visible: false
        }
        Image {
            id: favoriteImage
            anchors.right: parent.right
            anchors.rightMargin: 4
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height - 20
            width: height
            source: parent.image_favorite

        }
        MouseArea {
            anchors.fill: parent
            onClicked: root.clicked(contact.name)
        }
        MouseArea {
            anchors.fill: favoriteImage
            onClicked: root.clickedFavorite(contact.name)
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


