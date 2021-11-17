#include "Header/contactlistprovider.h"
#include "Header/contact.h"
#include <QLayout>

ContactListProvider::ContactListProvider(const std::shared_ptr<DataBase>& data_base, QWidget* parent)
    : QWidget(parent),
      m_data_base(data_base)
{
    QLayout* layout = new QVBoxLayout(this);

    view = new QQuickView();
    QWidget* container = QWidget::createWindowContainer(view, this);
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->setInitialProperties({{ "model", QVariant::fromValue(m_data_base->getContacts()) }});
    setListView();

    layout->addWidget(container);

}

void ContactListProvider::call(QString id)
{
    (dynamic_cast<Contact*>(m_data_base->findContact(id)))->calling();
}

void ContactListProvider::setListView()
{
    view->setSource(QUrl("qrc:/listviewmodel.qml"));
    QObject* item = view->rootObject();
    auto connection_mouse_event = QObject::connect(item, SIGNAL(clicked(QString)), this, SLOT(call(QString)));
}

void ContactListProvider::setGridView()
{
    view->setSource(QUrl("qrc:/gridviewmodel.qml"));
    QObject* item = view->rootObject();
    auto connection_mouse_event = QObject::connect(item, SIGNAL(clicked(QString)), this, SLOT(call(QString)));
}
