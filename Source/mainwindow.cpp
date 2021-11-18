#include "Header/mainwindow.h"

MainWindow::MainWindow(const std::shared_ptr<DataBase>& data_base, QWidget *parent)
    : QMainWindow(parent)
{
    resize(400, 600);

    m_provider = new ContactListProvider(data_base, this); 
    setCentralWidget(m_provider);
    createMenu();
    createToolBar();
}

void MainWindow::createMenu()
{
    m_menu_bar = new QMenuBar(this);
    QMenu* view = new QMenu("View", m_menu_bar);

    view->addAction("List View", m_provider, SLOT(setListView()));
    view->addAction("Grid View", m_provider, SLOT(setGridView()));

    m_menu_bar->addMenu(view);
}

void MainWindow::createToolBar()
{
    m_tool_bar = new QToolBar(this);

    QAction* show_favorites = new QAction(QIcon(":/favorite_star_active.png"), "Show Mode", this);
    m_tool_bar->addAction(show_favorites);
    connect(show_favorites, SIGNAL(triggered()), m_provider, SLOT(toggleFavoriteShowMode()));

    QAction* get_chunk = new QAction(QIcon(":/chunk.png"), "Chunking", this);
    m_tool_bar->addAction(get_chunk);
    connect(get_chunk, SIGNAL(triggered()), m_provider, SLOT(toggleChunkShowMode()));

    addToolBar(m_tool_bar);
}
