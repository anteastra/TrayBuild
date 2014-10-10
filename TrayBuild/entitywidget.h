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
	void setId(int val) { id = val;	ui.lineEditName->setPlaceholderText(QString ("Id: %1 (Enter name here)").arg(id)); }


private slots:
	void on_pushButtonDelete_clicked();

private:
	Ui::EntityWidget ui;
	int id;	

signals:
	void remove(int id);

};

#endif // ENTITYWIDGET_H
