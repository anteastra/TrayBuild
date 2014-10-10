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

public slots:
	void removeEntity(int id);

private:

	int getNextId();

	SettingsManager *settingsManager;
	int maxEntityNumber;
	QList<EntityWidget*> entities;
	QLayout *layout;


};

#endif // ENTITYMANAGER_H
