#ifndef TODOMODEL_H
#define TODOMODEL_H

#include <QAbstractListModel>

// [TTRL] 6. Register this type in the type system using
//    the newest type registration with QML_ELEMENT
#include <QtQml/qqmlregistration.h>

// [TTRL-2] 14. Include the TodoList to let the model use it
#include <entities/TodoList.h>

class TodoModel : public QAbstractListModel
{
    Q_OBJECT

    // [TTRL] 7. Register type
    QML_ELEMENT

    // [TTRL-2] 15. Create a Q_PROPERTY to expose this model's TodoList
    //              then click on Q_PROPERTY and do Alt + Enter
    //              (or Option + Enter on Mac) and select GENERATE missing properties.
    Q_PROPERTY(TodoList *list READ list WRITE setlist NOTIFY listChanged FINAL)

public:
    explicit TodoModel(QObject *parent = nullptr);

    // [TTRL] 1. Define roles using enum
    enum Roles {
        DoneRole = Qt::UserRole + 1,
        DescriptionRole
    };

    Q_ENUM(Roles)

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    // [TTRL] 2. Declare roleNames (TODO: explain this)
    virtual QHash<int, QByteArray> roleNames() const override;

    TodoList *list() const;
    void setlist(TodoList *newList);

signals:
    void listChanged();

private:
    TodoList *m_list = nullptr;
};

#endif // TODOMODEL_H
