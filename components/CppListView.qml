import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

// [TTRL] 9. Import module where the C++ model lives
//           (Which in this case is the same module as the main one)
import ModelView

Frame {
    ColumnLayout {
        anchors.fill: parent
        spacing: 16

        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true

            clip: true

            // [TTRL] 10. Use the model
            model: TodoModel { id: todoModel }

            delegate: RowLayout {
                // [TTRL] 11. Set the properties to use
                //            (There's no intellisense unfortunately on
                //             `model` or `modelData`, but rather, they're given
                //             by these required properties.)
                required property bool done
                required property string description

                width: if (parent) parent.width

                CheckBox {
                    checked: done
                    onClicked: done = checked
                }

                TextField {
                    Layout.fillWidth: true
                    text: description
                    onTextEdited: description = text
                }
            }
        }

        Button {
            text: "Show model data"

            onClicked: {
                const data = []
                for (let i = 0 ; i < todoModel.rowCount(); i++) {
                    const index = todoModel.index(i, 0)
                    data.push({
                        done: todoModel.data(index, TodoModel.DoneRole),
                        description: todoModel.data(index, TodoModel.DescriptionRole),
                    })
                }
                console.log(JSON.stringify(data, null, 2))
            }
        }
    }
}
