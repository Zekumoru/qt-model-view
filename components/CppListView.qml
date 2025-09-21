import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../utils/model.js" as Model

Frame {
    ColumnLayout {
        anchors.fill: parent
        spacing: 16

        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true

            clip: true

            model: 100

            delegate: RowLayout {
                width: if (parent) parent.width

                CheckBox { }

                TextField {
                    Layout.fillWidth: true
                }
            }
        }

        Button {
            text: "Show model data"

            onClicked: console.log("No model yet")
        }
    }
}
