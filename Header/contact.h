#pragma once

#include <QObject>

class Contact : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString image_photo READ imagePhoto WRITE setImagePhoto NOTIFY imagePhotoChanged)
    Q_PROPERTY(QString image_favorite READ imageFavorite NOTIFY imageFavoriteChanged)

public:
    Contact(QString name, QString image_photo, QObject* parent = nullptr);

    const QString &name() const;
    void setName(const QString& newName);
    const QString &imagePhoto() const;
    void setImagePhoto(const QString &newImage);
    const QString &imageFavorite() const;

    void calling();
    void toggleFavorite();
    bool isFavorite() const;

signals:
    void nameChanged();
    void imagePhotoChanged();

    void imageFavoriteChanged();

private:
    QString m_name;
    QString m_image_photo;
    QString m_image_favorite_active;
    QString m_image_favorite_deactive;
    bool m_is_favorite = false;
};

