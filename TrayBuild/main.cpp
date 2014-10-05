#include "traybuild.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TrayBuild w;
	w.show();
	return a.exec();
}
