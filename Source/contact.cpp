#include "contact.h"

Contact::Contact(QString name, QObject* parent)
    : QObject(parent),
      m_name(name)
{

}

QString Contact::name() const
{
    return m_name;
}

void Contact::setName(const QString& name)
{
    m_name = name;
}
