#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <QObject>
#include <QList>
#include <QLayout>
#include <QVBoxLayout>

#include "SettingsManager.h"
#include "entitywidget.h"


class EntityManager : public QObject
{
	Q_OBJECT

public:
	EntityManager(QObject *parent);
	~EntityManager();

	SettingsManager* getSettingsManager();	
	QLayout * getLayout() const { return layout; }
	void setLayout(QLayout * val) { layout = val; }

	public slots:
	void addEntity();

private:
	SettingsManager *settingsManager;
	int totalEntityNumber;
	QList<EntityWidget> entities;
	QLayout *layout;


};

#endif // ENTITYMANAGER_H
