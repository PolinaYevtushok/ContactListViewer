#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include<QMenuBar>
#include "contactlistprovider.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(const std::shared_ptr<DataBase>& data_base, QWidget *parent = nullptr);

signals:
private:
    ContactListProvider* m_provider;
    QMenuBar* m_menu_bar;
};

#endif // MAINWINDOW_H
