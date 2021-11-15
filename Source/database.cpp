#include "Header/database.h"

DataBase::DataBase()
{
    m_contacts = {
        new Contact("Item 1", "qrc:/contact.png"),
        new Contact("Item 2", "qrc:/contact.png"),
        new Contact("Item 3", "qrc:/contact.png")
    };

}

void DataBase::addNewContact(QObject *contact)
{
    m_contacts.push_back(contact);
}

QObject *DataBase::findContact(QString name)
{
    for(auto& item: m_contacts)
    {
        if(dynamic_cast<Contact*>(item)->name() == name)
            return item;
    }
    return nullptr;
}

const QList<QObject *> &DataBase::getContacts() const
{
    return m_contacts;
}
