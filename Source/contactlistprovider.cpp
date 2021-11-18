#include "Header/contactlistprovider.h"
#include "Header/contact.h"
#include <QLayout>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>
#include <QSpinBox>
#include <QFormLayout>

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

void ContactListProvider::toggleChunkShowMode()
{
    m_is_chunk_show_mode = !m_is_chunk_show_mode;
    if(m_is_chunk_show_mode)
    {
        QDialog dialog(this);
        QFormLayout form(&dialog);
        form.addRow(new QLabel("Parameters:"));

        QString index = QString("Index: ");
        QSpinBox *spinbox_index = new QSpinBox(&dialog);
        form.addRow(index, spinbox_index);

        QString size = QString("Size: ");
        QSpinBox *spinbox_size = new QSpinBox(&dialog);
        form.addRow(size, spinbox_size);

        QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
            Qt::Horizontal, &dialog);
        form.addRow(&buttonBox);
        QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
        QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

        if (dialog.exec() == QDialog::Accepted)
        {
            QList<QObject*> chunking_contacts;
            m_data_base->getChunkingContacts(chunking_contacts, spinbox_index->value(), spinbox_size->value());
            view->setInitialProperties({{ "model", QVariant::fromValue(chunking_contacts)}});
        }
    }
    else
        view->setInitialProperties({{ "model", QVariant::fromValue(m_data_base->getContacts()) }});
    updateView();
}
