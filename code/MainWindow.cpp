#include "MainWindow.h"
#include "MainWidget.h"
#include "AboutDialog.h"
#include <QDebug>
#include <QMenuBar>

MainWindow::MainWindow()
{
	initialize();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initialize()
{
	setCentralWidget(new MainWidget);
	setGeometry(0,0, 800, 600);
	initializeMenu();
}

void MainWindow::initializeMenu()
{
	auto menu = menuBar();
	initializeFileMenu(menu);
	initializeSortMenu(menu);
	initializeHelpMenu(menu);
}

void MainWindow::initializeFileMenu(QMenuBar* bar)
{
	auto menu = bar->addMenu("&File");
	auto action = menu->addAction("E&xit");
	connect(action, &QAction::triggered, this, &QMainWindow::close);	
}

void MainWindow::initializeSortMenu(QMenuBar* bar)
{
	auto menu = bar->addMenu("&Algorithm Sort");
	auto action = menu->addAction("Bubble Sort");
	action = menu->addAction("Quick Sort");
	action = menu->addAction("Heap Sort");
}

void MainWindow::initializeHelpMenu(QMenuBar* bar)
{
	auto menu = bar->addMenu("&Help");
	auto action = menu->addAction("&About");
	connect(action, &QAction::triggered, this, &MainWindow::onAbout);
}

void MainWindow::onAbout()
{
	AboutDialog dialog(this);
	dialog.exec();
}
