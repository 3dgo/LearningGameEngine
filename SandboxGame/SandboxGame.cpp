#include <QtWidgets\QApplication>
#include <QtWidgets\QLabel>
#include "MyGlWindow.h"

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);

	MyGlWindow myWidget;
	if (!myWidget.initialize())
		return -1;

	myWidget.show();
	
	int errorCode = application.exec();
	if (!myWidget.shutdown())
		errorCode |= 1;

	return errorCode;
}