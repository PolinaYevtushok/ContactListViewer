#include "Header/contactlistprovider.h"
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include "Header/contact.h"

ContactListProvider::ContactListProvider(const std::shared_ptr<DataBase>& data_base, QWidget* parent)
    : QWidget(parent),
      m_data_base(data_base)
{

    QQuickView* view = new QQuickView();
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->setInitialProperties({{ "model", QVariant::fromValue(m_data_base->getContacts()) }});
    view->setSource(QUrl("qrc:/viewmodel.qml"));
    QObject* item = view->rootObject();
    auto connection_mouse_event = QObject::connect(item, SIGNAL(clicked(QString)), this, SLOT(call(QString)));
    //Q_ASSERT_X(connection_mouse_event, "ContactListProvider", "Connection failed!");
    view->show();

}

void ContactListProvider::call(QString id)
{
    (dynamic_cast<Contact*>(m_data_base->findContact(id)))->calling();
}
