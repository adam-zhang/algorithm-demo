#ifndef __ABOUTDIALOG__H
#define __ABOUTDIALOG__H
#include <QDialog>

class AboutDialog : public QDialog
{
	Q_OBJECT
public:
	explicit AboutDialog(QWidget*);
	~AboutDialog();
private:
	void initialize();
	QWidget* createPicture();
	QLayout* createInformation();
};
#endif//__ABOUTDIALOG__H
