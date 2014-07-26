#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

#include <QtGui/QMainWindow>
#include "ui_templateclass.h"
#include "KeyTemplate.h"

class CKeyTemplateBuilder : public QMainWindow
{
	Q_OBJECT

public:
	CKeyTemplateBuilder(QWidget *parent = 0, Qt::WFlags flags = 0);
	~CKeyTemplateBuilder();

private:
	Ui::TemplateClassClass ui;
	MultiDerivedClass m_kMultiDerived;
	SingleDerivedClass m_kSingleDerived;
};

#endif // TEMPLATECLASS_H
