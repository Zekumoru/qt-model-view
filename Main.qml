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

        ColumnLayout {
            Layout.fillHeight: true
            Layout.preferredHeight: 1

            Label {
                text: "ListView using C++ model (QAbstractListModel)"
            }

            CppListView {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }

        ColumnLayout {
            Layout.fillHeight: true
            Layout.preferredHeight: 1

            Label {
                text: "ListView using QML model (ListModel)"
            }

            QmlListView {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }
    }
}
