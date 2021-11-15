#ifndef CONTACTLISTPROVIDER_H
#define CONTACTLISTPROVIDER_H

#include <QWidget>
#include <QVariant>
#include "database.h"

class ContactListProvider : public QWidget
{
    Q_OBJECT

public:
    ContactListProvider(const std::shared_ptr<DataBase>& data_base, QWidget* parent = nullptr);
public slots:
    void call(QString id);
private:
    std::shared_ptr<DataBase> m_data_base;
};

#endif // CONTACTLISTPROVIDER_H
