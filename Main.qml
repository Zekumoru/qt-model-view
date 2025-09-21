import QtQuick
import QtQuick.Controls.Fusion
import QtQuick.Controls
import QtQuick.Layouts

import "components"

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("ModelView")

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 16
        spacing: 16

        Label {
            text: "IntegerListView"
        }

        IntegerListView {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Label {
            text: "CppListView"
        }

        CppListView {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
