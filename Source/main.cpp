
#include <QApplication>
#include "Header/contactlistprovider.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ContactListProvider provider;
    return a.exec();
}
