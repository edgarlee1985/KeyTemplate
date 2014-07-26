#include "stdafx.h"
#include "KeyTemplateBuilder.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CKeyTemplateBuilder w;
	w.show();
	return a.exec();
}
