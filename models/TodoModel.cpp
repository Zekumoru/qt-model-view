#include "TodoModel.h"

TodoModel::TodoModel(QObject *parent)
    : QAbstractListModel(parent)
    // [TTRL-2] 16. Set m_list to nullptr
    , m_list(nullptr)
{
}

int TodoModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    // [TTRL-2] 20. Add a null guard checking that the list is not null.
    if (parent.isValid() || !m_list)
        return 0;

    // [TTRL] 4. Create 100 stub todos for testing purposes (superseded by TTRL-2)
    // return 100;

    // [TTRL-2] 21. Return the correct amount of items in the TodoList.
    return m_list->items().size();
}

QVariant TodoModel::data(const QModelIndex &index, int role) const
{
    // [TTRL-2] 22. Add a null guard checking that the list is not null.
    if (!index.isValid() || !m_list)
        return QVariant();

    // [TTRL] 5. Add dummy content for testing purposes for each role (superseded by TTRL-2)
    // switch (role) {
    // case DoneRole:
    //     return QVariant(false);
    // case DescriptionRole:
    //     return QVariant(QStringLiteral("Test Description"));
    // }

    // [TTRL-2] 23. Return the correct current item model data's properties.
    const Todo item = m_list->items().at(index.row());
    switch (role) {
    case DoneRole:
        return QVariant(item.done);
    case DescriptionRole:
        return QVariant(item.description);
    }

    return QVariant();
}

bool TodoModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    // [TTRL-2] 24. Add a null guard checking that the list is not null.
    if (!m_list)
        return false;

    // [TTRL-2] 25. Store a local copy of the item and check which
    //              role is modified and update it.
    Todo item = m_list->items().at(index.row());
    switch (role) {
    case DoneRole:
        item.done = value.toBool();
        break;
    case DescriptionRole:
        item.description = value.toString();
        break;
    }

    // [TTRL-2] 26. Save the local copy in the TodoList and if
    //              something changed, emit it.
    if (m_list->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, { role });
        return true;
    }

    return false;
}

Qt::ItemFlags TodoModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    // [TTRL-2] 27. Tell Qt that this model can be editable by
    //              returning Qt::ItemIsEditable
    return Qt::ItemIsEditable;
}

// [TTRL] 3. Define roleNames
QHash<int, QByteArray> TodoModel::roleNames() const
{
    return {
        { DoneRole, "done" },
        { DescriptionRole, "description" }
    };
}

TodoList *TodoModel::list() const
{
    return m_list;
}

void TodoModel::setlist(TodoList *newList)
{
    if (m_list == newList)
        return;

    // [TTRL-2] 17. Call beginResetModel and disconnect
    //              before setting a new list.
    beginResetModel();
    if (m_list) m_list->disconnect(this);

    m_list = newList;
    emit listChanged();

    // [TTRL-2] 18. If list exists, then connect the appropriate slots
    //              to the signals of TodoList which will tell the model
    //              to update depending on the action done by the TodoList,
    //              which could be appending or removing an item.
    if (m_list) {
        connect(m_list, &TodoList::preItemAppended, this, [=]() {
            const int index = m_list->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });

        connect(m_list, &TodoList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(m_list, &TodoList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });

        connect(m_list, &TodoList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    // [TTRL-2] 19. Finally, tell Qt that the model has finished setting up.
    endResetModel();
}
