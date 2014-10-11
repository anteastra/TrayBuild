#include "entitywidget.h"

EntityWidget::EntityWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	id = -1;
	name = QString("");
	regexp = QString("");
	location = QString("");
}

EntityWidget::~EntityWidget()
{

}

void EntityWidget::on_pushButtonDelete_clicked()
{
	emit remove(id);
}

void EntityWidget::on_lineEditName_textChanged(const QString & text)
{
	name = text;
}

void EntityWidget::on_lineEditRegexp_textChanged(const QString & text)
{
	regexp = text;
}

void EntityWidget::on_lineEditLocation_textChanged(const QString & text)
{
	location = text;
}

void EntityWidget::on_pushButtonApply_clicked()
{
	emit save(id);
}

