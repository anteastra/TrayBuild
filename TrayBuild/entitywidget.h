#ifndef ENTITYWIDGET_H
#define ENTITYWIDGET_H

#include <QWidget>
#include <QString>
#include "ui_entitywidget.h"


class EntityWidget : public QWidget
{
	Q_OBJECT

public:
	EntityWidget(QWidget *parent = 0);
	~EntityWidget();

	int getId() const { return id; }
	void setId(int val) { id = val;	ui.lineEditName->setPlaceholderText(QString ("Id: %1 (Enter name here)").arg(id)); }
	QString getName() const { return name; }
	void setName(QString val) { name = val; ui.lineEditName->setText(name); }
	QString getRegexp() const { return regexp; }
	void setRegexp(QString val) { regexp = val; ui.lineEditRegexp->setText(regexp); }
	QString getLocation() const { return location; }
	void setLocation(QString val) { location = val; ui.lineEditLocation->setText(location); }

private slots:
	void on_pushButtonDelete_clicked();
	void on_pushButtonApply_clicked();
	void on_lineEditName_textChanged(const QString & value);
	void on_lineEditRegexp_textChanged(const QString & value);
	void on_lineEditLocation_textChanged(const QString & value);

private:
	Ui::EntityWidget ui;
	int id;	
	QString name;
	QString regexp;
	QString location;
	
signals:
	void remove(int id);
	void save(int id);

};

#endif // ENTITYWIDGET_H
