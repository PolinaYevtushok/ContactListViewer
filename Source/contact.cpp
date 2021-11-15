#include "Header/contact.h"
#include <QMessageBox>

Contact::Contact(QString name, QString image, QObject* parent)
    : QObject(parent),
      m_name(name),
      m_image(image)
{

}

const QString &Contact::name() const
{
    return m_name;
}

void Contact::setName(const QString& newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

const QString &Contact::image() const
{
    return m_image;
}

void Contact::setImage(const QString &newImage)
{
    if (m_image == newImage)
        return;
    m_image = newImage;
    emit imageChanged();
}

void Contact::calling()
{
    QMessageBox::information(0, "Calling", "Calling " + m_name + " ...") ;
}
