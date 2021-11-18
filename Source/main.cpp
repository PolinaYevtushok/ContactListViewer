#include <QApplication>
#include "Header/database.h"
#include "Header/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto p_data_base = std::make_shared<DataBase>();
    MainWindow w(p_data_base);
    w.show();
    return a.exec();
}
