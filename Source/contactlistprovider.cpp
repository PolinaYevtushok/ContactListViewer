#include "Header/contactlistprovider.h"
#include "Header/contact.h"
#include <QLayout>

QMap<EViewMode, QString> ContactListProvider::qml_path_by_view_mode = {
    {EViewMode::List, "qrc:/listviewmodel.qml"},
    {EViewMode::Grid, "qrc:/gridviewmodel.qml"}
};

ContactListProvider::ContactListProvider(const std::shared_ptr<DataBase>& data_base, QWidget* parent)
    : QWidget(parent),
      m_data_base(data_base)
{
    QLayout* layout = new QVBoxLayout(this);

    connect(this, SIGNAL(viewModeChanged()), this, SLOT(updateView()));

    view = new QQuickView();
    QWidget* container = QWidget::createWindowContainer(view, this);
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->setInitialProperties({{ "model", QVariant::fromValue(m_data_base->getContacts()) }});
    setViewMode(EViewMode::List);

    layout->addWidget(container);


}

void ContactListProvider::call(QString id)
{
    (dynamic_cast<Contact*>(m_data_base->findContact(id)))->calling();
}

void ContactListProvider::onClickedFavorite(QString id)
{
    (dynamic_cast<Contact*>(m_data_base->findContact(id)))->toggleFavorite();
}

void ContactListProvider::setViewMode(EViewMode new_view_mode)
{
    m_view_mode = new_view_mode;
    emit viewModeChanged();
}

void ContactListProvider::updateView()
{
    QString qml_path = qml_path_by_view_mode[m_view_mode];
    view->setSource(QUrl(qml_path));
    QObject* item = view->rootObject();

    switch (m_view_mode)
    {
        case EViewMode::List:
            connect(item, SIGNAL(clicked(QString)), this, SLOT(call(QString)));
            connect(item, SIGNAL(clickedFavorite(QString)), this, SLOT(onClickedFavorite(QString)));
            break;
        case EViewMode::Grid:
            connect(item, SIGNAL(clicked(QString)), this, SLOT(call(QString)));
            break;
        default:
            break;
    }
}

void ContactListProvider::setListView()
{
    setViewMode(EViewMode::List);
}

void ContactListProvider::setGridView()
{
    setViewMode(EViewMode::Grid);
}

void ContactListProvider::toggleFavoriteShowMode()
{
    m_is_favorite_show_mode = !m_is_favorite_show_mode;
    if (m_is_favorite_show_mode)
    {
       QList<QObject*> favorite_contacts;
       m_data_base->getFavoriteContacts(favorite_contacts);
       view->setInitialProperties({{ "model", QVariant::fromValue(favorite_contacts)}});
    }
    else
        view->setInitialProperties({{ "model", QVariant::fromValue(m_data_base->getContacts()) }});
    updateView();
}
