
#include <QApplication>
#include "Header/contactlistprovider.h"
#include "Header/database.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto p_data_base = std::make_shared<DataBase>();
    ContactListProvider provider(p_data_base);
    return a.exec();
}
