# Model View Architecture

**Objective:** To understand how to properly create C++ models and use them in QML.

## Description

Model view architecture is a very important and fundamental concept in Qt. It centralizes handling data in C++ and avoids other headaches that come along using QML as models.

To expound more about the benefits of using the model-view architecture, let's see some of them.

### 1 | Qt documentation's advice

The Qt documentation suggests that we use the `required` keyword when specifying or using the properties of a model.

For example:

```qml
component MyDelegate : Text {
    required property string type
    required property int age
    text: type + ", " + age
}
```

To quote from the docs:

> _"In most cases you should use **required properties** to pass model data into your delegates. If a delegate contains required properties, the QML engine will check if the name of a required property matches that of a model role. If so, that property will be bound to the corresponding value from the model."_ ([Models, Models and Views in Qt Quick](https://doc.qt.io/qt-6/qtquick-modelviewsdata-modelview.html#models))

Do note, however, that using `required` properties mean not relying on the QML context anymore for any _"hidden"_ properties from the parent. You can find out more about it in ([Models, Models and Views in Qt Quick](https://doc.qt.io/qt-6/qtquick-modelviewsdata-modelview.html#models)).

### 2 | Editable models

Working with editable models, meaning being able to modify a model's data, is a pain to work with if we use JavaScript objects directly since they are inherently unmodifiable when used as models.

To quote from the docs:

> _"To change model data, you can assign updated values to the `model` properties. The QML `ListModel` is editable by default whereas C++ models must implement `setData()` to become editable. **Integer and JavaScript array models are read-only.**"_ ([Changing Model Data, Models and Views in Qt Quick](https://doc.qt.io/qt-6/qtquick-modelviewsdata-modelview.html#changing-model-data))

This would mean to use QML's `ListModel` and `ListElement` components if we ever want to implement modifiability. However, this has two caveats: (1) The model is in QML meaning we'd need extra work or double the work if we need to pass the data of the model to C++, and (2) we lose autocomplete.

### 3 | Autocomplete

_To be verified._

If I remember correctly, using models in C++ also enable us to have autocompletion.

## Creating A C++ Model

To start creating a C++ model, right click on the left pane where you have your files and select _"Add new..."_, a dialog will pop up, select **Qt** and then choose **Qt Item Model**.

On the definition dialog, type the class name and select as base `QAbstractListModel`. Unselect **Customize header row** (because that's for Qt Widgets) and select **Items are editable** for Qt to generate methods for us to enable modifying our C++ models. And then select **Continue** to create the files.

Follow the `[TTRL]` tags (TTRL means TuToRiaL) in the code to know the steps to create a working model. (As of currently, the model **is not modifiable yet**. Check the other git branches since this is more of a snapshot.)
