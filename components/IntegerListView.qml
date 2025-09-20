import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Frame {
    ListView {
        anchors.fill: parent
        anchors.margins: 16
        clip: true

        model: ListModel {
            ListElement {
                done: true
                description: "Wash the dishes"
            }

            ListElement {
                done: false
                description: "Fix the sink"
            }
        }

        delegate: RowLayout {
            width: if (parent) parent.width

            CheckBox {
                checked: model.done
                onClicked: model.done = checked
            }

            TextField {
                Layout.fillWidth: true
                text: model.description
                onEditingFinished: model.description = text
            }
        }
    }
}
