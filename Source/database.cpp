#include "Header/database.h"

DataBase::DataBase()
{
    for(int i = 1; i <= 50; ++i)
    {
        QString str = "Item" + QString::number(i);
        m_contacts.push_back(new Contact(str, "qrc:/contact.png"));
    }

}

void DataBase::addNewContact(QObject *contact)
{
    m_contacts.push_back(contact);
}

QObject *DataBase::findContact(QString name)
{
    for (auto& item: m_contacts)
    {
        if (dynamic_cast<Contact*>(item)->name() == name)
            return item;
    }
    return nullptr;
}

const QList<QObject *> &DataBase::getContacts() const
{
    return m_contacts;
}

void DataBase::getFavoriteContacts(QList<QObject*>& favorite_contacts) const
{
    for (auto* contact : m_contacts)
    {
        if (dynamic_cast<Contact*>(contact)->isFavorite())
            favorite_contacts.push_back(contact);
    }
}

void DataBase::getChunkingContacts(QList<QObject *> &chunking_contacts, int index, int size) const
{
    QVector<QObject*> contacts_vector = m_contacts.toVector();

    for(int i = index, j = 0;j < size && i != contacts_vector.size(); ++i, ++j)
        chunking_contacts.push_back(contacts_vector[i - 1]);
}
