import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

// [TTRL] 9. Import module where the C++ model lives
//           (Which in this case is the same module as the main one)
import ModelView

Frame {
    // [TTRL-2] 28. Create a TodoList (this can be instantiated anywhere,
    //              I just choose it to be here, what's important is to
    //              be able to pass it then to the model).
    TodoList { id: todoList }

    ColumnLayout {
        anchors.fill: parent
        spacing: 16

        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true

            clip: true

            // [TTRL] 10. Use the model
            model: TodoModel {
                id: todoModel

                // [TTRL-2] 29. Pass the todo list into the model.
                list: todoList
            }

            delegate: RowLayout {
                // [TTRL] 11. Set the properties to use
                //            (There's no intellisense unfortunately on
                //             `model` or `modelData`, but rather, they're given
                //             by these required properties.)
                required property bool done
                required property string description

                // [TTRL-2] 30. Provide the `model` property to be able to
                //              set data into the model.
                // See: https://doc.qt.io/qt-6/qtquick-modelviewsdata-modelview.html#models
                // Unfortunately, this is a Qt thing where you expose the properties like
                // above and if you want to write to these properties, you use the `model`.
                required property var model

                width: if (parent) parent.width

                CheckBox {
                    checked: done
                    // [TTRL-2] 31. Use `model` to be able to set data
                    onClicked: model.done = checked
                }

                TextField {
                    Layout.fillWidth: true
                    text: description
                    // [TTRL-2] 32. Use `model` to be able to set data
                    onTextEdited: model.description = text
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
