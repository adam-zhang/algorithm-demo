#ifndef __MAINWINDOW__H
#define __MAINWINDOW__H
#include <QMainWindow>

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow();
	~MainWindow();
private:
	void initialize();
	void initializeMenu();
	void initializeFileMenu(QMenuBar*);
	void initializeSortMenu(QMenuBar*);
	void initializeHelpMenu(QMenuBar*);
private slots:
	void onAbout();
};
#endif//__MAINWINDOW__H
