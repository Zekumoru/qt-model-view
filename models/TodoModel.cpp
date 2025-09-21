#include "TodoModel.h"

TodoModel::TodoModel(QObject *parent)
    : QAbstractListModel(parent)
{}

int TodoModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // [TTRL] 4. Create 100 stub todos for testing purposes
    return 100;
}

QVariant TodoModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // [TTRL] 5. Add dummy content for testing purposes for each role
    switch (role) {
    case DoneRole:
        return QVariant(false);
    case DescriptionRole:
        return QVariant(QStringLiteral("Test Description"));
    }

    return QVariant();
}

bool TodoModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags TodoModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; // FIXME: Implement me!
}

// [TTRL] 3. Define roleNames
QHash<int, QByteArray> TodoModel::roleNames() const
{
    return {
        { DoneRole, "done" },
        { DescriptionRole, "description" }
    };
}
