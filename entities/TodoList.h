#ifndef TODOLIST_H
#define TODOLIST_H

#include <QObject>
#include <QQmlEngine>

// [TTRL-2] 2. Add include for QVector
#include <QVector>

// [TTRL-2] 1. Create a struct for our model data
struct Todo {
    bool done;
    QString description;
};

class TodoList : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit TodoList(QObject *parent = nullptr);

    // [TTRL-2] 7. Provide this getter for the model to use
    QVector<Todo> items() const;

    // [TTRL-2] 4. Declare the action method to allow the
    //             model, i.e. `TodoModel`, to modify the data
    bool setItemAt(int index, const Todo &item);

// [TTRL-2] 6. Add the following pre- and post- signals
//             which the model expects of what happens to
//             the data before and after something about to happen.
signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

// [TTRL-2] 5. Add the following slots
public slots:
    void appendItem();
    void removeCompletedItems();

// [TTRL-2] 3. Create a private QVector member to hold the todos
private:
    QVector<Todo> m_items;
};

#endif // TODOLIST_H
