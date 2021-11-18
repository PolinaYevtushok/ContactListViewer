#ifndef CONTACTLISTPROVIDER_H
#define CONTACTLISTPROVIDER_H

#include <QWidget>
#include <QVariant>
#include <QMap>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include "database.h"

enum class EViewMode
{
    List,
    Grid
};

class ContactListProvider : public QWidget
{
    Q_OBJECT

public:
    ContactListProvider(const std::shared_ptr<DataBase>& data_base, QWidget* parent = nullptr);
public slots:
    void call(QString id);
    void onClickedFavorite(QString id);
    void updateView();
    void setListView();
    void setGridView();
    void toggleFavoriteShowMode();
    void toggleChunkShowMode();
    void setViewMode(EViewMode new_view_mode);
signals:
    void viewModeChanged();
private:
    std::shared_ptr<DataBase> m_data_base;
    QQuickView* view;
    bool m_is_favorite_show_mode = false;
    bool m_is_chunk_show_mode = false;
    EViewMode m_view_mode = EViewMode::List;
    static QMap<EViewMode, QString> qml_path_by_view_mode;
};

#endif // CONTACTLISTPROVIDER_H
