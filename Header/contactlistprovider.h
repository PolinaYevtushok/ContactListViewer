#ifndef CONTACTLISTPROVIDER_H
#define CONTACTLISTPROVIDER_H

#include <QWidget>

class ContactListProvider : public QWidget
{
    Q_OBJECT

public:
    ContactListProvider(QWidget* parent = nullptr);
private:
    QList<QObject*> m_contacts;
};

#endif // CONTACTLISTPROVIDER_H
