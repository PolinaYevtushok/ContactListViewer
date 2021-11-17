#ifndef DATABASE_H
#define DATABASE_H
#include "contact.h"

class DataBase
{
public:
    DataBase();
    void addNewContact(QObject* contact);
    QObject* findContact(QString name);
    const QList<QObject*>& getContacts() const;
    void getFavoriteContacts(QList<QObject*>& favorite_contacts) const;
private:
    QList<QObject*> m_contacts;
};

#endif // DATABASE_H
