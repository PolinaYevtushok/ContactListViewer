#include "Header/mainwindow.h"

MainWindow::MainWindow(const std::shared_ptr<DataBase>& data_base, QWidget *parent)
    : QMainWindow(parent)
{
    resize(400, 600);
    m_provider = new ContactListProvider(data_base, this);
    m_menu_bar = new QMenuBar(this);
    QMenu* view = new QMenu("View", m_menu_bar);
    view->addAction("List View", m_provider, SLOT(setListView()));
    view->addAction("Grid View", m_provider, SLOT(setGridView()));
    m_menu_bar->addMenu(view);
    setCentralWidget(m_provider);
}
