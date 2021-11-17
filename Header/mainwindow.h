#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include<QMenuBar>
#include <QToolBar>
#include "contactlistprovider.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(const std::shared_ptr<DataBase>& data_base, QWidget *parent = nullptr);
    void createMenu();
    void createToolBar();

signals:
private:
    ContactListProvider* m_provider;
    QMenuBar* m_menu_bar;
    QToolBar* m_tool_bar;
};

#endif // MAINWINDOW_H
