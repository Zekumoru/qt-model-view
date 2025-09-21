#ifndef TODOMODEL_H
#define TODOMODEL_H

#include <QAbstractListModel>

// [TTRL] 6. Register this type in the type system using
//    the newest type registration with QML_ELEMENT
#include <QtQml/qqmlregistration.h>

class TodoModel : public QAbstractListModel
{
    Q_OBJECT

    // [TTRL] 7. Register type
    QML_ELEMENT

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

private:
};

#endif // TODOMODEL_H
