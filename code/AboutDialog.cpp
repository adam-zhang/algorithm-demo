#include "AboutDialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QDebug>

AboutDialog::AboutDialog(QWidget* parent)
	: QDialog(parent)
{
	initialize();
}

AboutDialog::~AboutDialog()
{
}

void AboutDialog::initialize()
{
	auto layout = new QHBoxLayout(this);
	layout->addWidget(createPicture());
	layout->addLayout(createInformation());
}

QWidget* AboutDialog::createPicture()
{
	auto label = new QLabel;
	QPixmap image(":images/me.png");
	label->setPixmap(image);
	return label;
}


QLabel* createLinkLabel(const QString& s)
{
	auto label = new QLabel(s);
	label->setOpenExternalLinks(true);
	return label;
}

QLabel* createHyperLinkLabel(const QString& link)
{
	QString s = QString("<a href='%1'>%1</a>").arg(link);
	return createLinkLabel(s);
}

QLabel* createMailLabel(const QString& address)
{
	QString s = QString("<a href='mailto:%1'>%1</a>").arg(address);
	return createLinkLabel(s);
}

QLayout* AboutDialog::createInformation()
{
	auto grid = new QGridLayout;
	grid->addWidget(new QLabel("Author:"), 0, 0);
	grid->addWidget(new QLabel("Mingping Zhang"), 0 ,1);
	grid->addWidget(new QLabel("Email:"), 1, 0);
	grid->addWidget(createMailLabel("mingpingzhang@163.com"));
	grid->addWidget(new QLabel("github:"), 2, 0);
	grid->addWidget(createHyperLinkLabel("http://www.github.com/adam-zhang"));
	auto layout = new QVBoxLayout;
	layout->addLayout(grid);
	layout->addStretch();
	QDialogButtonBox* box = new QDialogButtonBox;
	box->addButton(QDialogButtonBox::Ok);
	connect(box, &QDialogButtonBox::accepted, this, &QDialog::accept);
	layout->addWidget(box);
	return layout;
}
