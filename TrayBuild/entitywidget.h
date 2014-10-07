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

	int getId() const { return id; }
	void setId(int val) { id = val; }

private:
	Ui::EntityWidget ui;
	int id;	
};

#endif // ENTITYWIDGET_H
