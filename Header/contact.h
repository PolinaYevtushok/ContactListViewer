#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>

class Contact : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    Contact(QString name, QObject* parent = nullptr);
    QString name() const;
    void setName(const QString& name);

signals:
    void nameChanged();

private:
    QString m_name;
};

#endif // CONTACT_H
