#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>

class Contact : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString image READ image WRITE setImage NOTIFY imageChanged)

public:
    Contact(QString name, QString image, QObject* parent = nullptr);
    const QString &name() const;
    void setName(const QString& newName);

    const QString &image() const;
    void setImage(const QString &newImage);
    void calling();
signals:
    void nameChanged();
    void imageChanged();

private:
    QString m_name;
    QString m_image;
};

#endif // CONTACT_H
