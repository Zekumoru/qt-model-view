import QtQuick
import QtQuick.Controls.Fusion
import QtQuick.Controls

import "components"

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("ModelView")

    IntegerListView {
        anchors.fill: parent
    }
}
