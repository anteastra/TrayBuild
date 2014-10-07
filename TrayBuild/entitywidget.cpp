#include "entitywidget.h"

EntityWidget::EntityWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	id = -1;
}

EntityWidget::~EntityWidget()
{

}



