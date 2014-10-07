#ifndef ENTITYWIDGET_H
#define ENTITYWIDGET_H

#include <QWidget>
#include "ui_entitywidget.h"

class EntityWidget : public QWidget
{
	Q_OBJECT

public:
	EntityWidget(QWidget *parent = 0);
	~EntityWidget();

private:
	Ui::EntityWidget ui;
};

#endif // ENTITYWIDGET_H
