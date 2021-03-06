#pragma once

#include "contact.h"

class DataBase
{
public:
    DataBase();
    void addNewContact(QObject* contact);
    QObject* findContact(QString name);
    const QList<QObject*>& getContacts() const;
    void getFavoriteContacts(QList<QObject*>& favorite_contacts) const;
    void getChunkingContacts(QList<QObject*>& chunking_contacts, int index, int size) const;
private:
    QList<QObject*> m_contacts;
};
