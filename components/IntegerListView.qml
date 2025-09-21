import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../utils/model.js" as Model

Frame {
    ListModel {
        id: todoModel

        ListElement {
            done: true
            description: "Wash the dishes"
        }

        ListElement {
            done: false
            description: "Fix the sink"
        }
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 16

        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true

            clip: true

            model: todoModel

            delegate: RowLayout {
                width: if (parent) parent.width

                CheckBox {
                    checked: model.done
                    onClicked: model.done = checked
                }

                TextField {
                    Layout.fillWidth: true
                    text: model.description
                    onTextEdited: model.description = text
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 16

            Item {
                Layout.fillWidth: true
                Layout.preferredWidth: 1
            }

            Item {
                Layout.fillWidth: true
                Layout.preferredWidth: 1
            }

            Button {
                Layout.fillWidth: true
                Layout.preferredWidth: 1

                text: "Show model data"

                onClicked: console.log(Model.stringify(todoModel))
            }
        }
    }
}
