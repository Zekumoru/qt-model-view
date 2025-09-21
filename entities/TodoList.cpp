#include "TodoList.h"

TodoList::TodoList(QObject *parent)
    : QObject{parent}
{
    // [TTRL-2] 12. Populate list with dummy items
    m_items.append({ true, QStringLiteral("Wash the dishes") });
    m_items.append({ false, QStringLiteral("Fix the sink") });
}

// [TTRL-2] 8. Define the items() getter
QVector<Todo> TodoList::items() const
{
    return m_items;
}

// [TTRL-2] 9. Define the setItemAt() method
bool TodoList::setItemAt(int index, const Todo &item)
{
    // Check if the index is valid
    if (index < 0 || index >= m_items.size())
        return false;

    // Check if the data has really changed comparing
    // the old item against the new item
    const Todo &oldItem = m_items.at(index);
    if (item.done == oldItem.done && item.description == oldItem.description)
        return false;

    // Save the changed data and return true
    // that it has been modified
    m_items[index] = item;
    return true;
}

// [TTRL-2] 10. Define the appendItem() method
void TodoList::appendItem()
{
    emit preItemAppended();

    Todo item;
    item.done = false;
    m_items.append(item);

    emit postItemAppended();
}

// [TTRL-2] 11. Define the removeCompletedItems() method
void TodoList::removeCompletedItems()
{
    // Remove the item if it is completed
    for (int i = m_items.size() - 1; i >= 0; i--) {
        if (!m_items.at(i).done)
            continue;

        emit preItemRemoved(i);
        m_items.removeAt(i);
        emit postItemRemoved();
    }
}
