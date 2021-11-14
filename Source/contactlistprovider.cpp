#include "contactlistprovider.h"
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include "contact.h"

ContactListProvider::ContactListProvider(QWidget* parent)
    : QWidget(parent)
{
    m_contacts = {
        new Contact("Item 1"),
        new Contact("Item 2"),
        new Contact("Item 3")
    };

    QQuickView* view = new QQuickView();
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->setInitialProperties({{ "model", QVariant::fromValue(m_contacts) }});
    view->setSource(QUrl("qrc:/viewmodel.qml"));
    view->show();
}
