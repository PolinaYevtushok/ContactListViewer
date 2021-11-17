#include "Header/contact.h"
#include <QMessageBox>

Contact::Contact(QString name, QString image_photo, QObject* parent)
    : QObject(parent),
      m_name(name),
      m_image_photo(image_photo)
{
    m_image_favorite_active = "qrc:/favorite_star_active.png";
    m_image_favorite_deactive = "qrc:/favorite_star_deactive.png";
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

const QString &Contact::imagePhoto() const
{
    return m_image_photo;
}

void Contact::setImagePhoto(const QString &newImage)
{
    if (m_image_photo == newImage)
        return;
    m_image_photo = newImage;
    emit imagePhotoChanged();
}

void Contact::calling()
{
    QMessageBox::information(0, "Calling", "Calling " + m_name + " ...") ;
}

void Contact::toggleFavorite()
{
    m_is_favorite = !m_is_favorite;
    emit imageFavoriteChanged();
}

const QString &Contact::imageFavorite() const
{
    return m_is_favorite ? m_image_favorite_active : m_image_favorite_deactive;
}

void Contact::setImageFavorite(const QString &newImage_favorite)
{
//    if (m_image_favorite == newImage_favorite)
//        return;
//    m_image_favorite = newImage_favorite;
    emit imageFavoriteChanged();
}
