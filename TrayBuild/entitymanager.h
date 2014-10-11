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

	void restoreState();

public slots:
	void addEntity();
	void addEntity(EntityWidget* widget);
	void removeEntity(int id);
	void saveEntity(int id);	

private:

	int getNextId();
	EntityWidget* findWidgetByID(int id);

	SettingsManager *settingsManager;
	int maxEntityNumber;
	QList<EntityWidget*> entities;
	QLayout *layout;


};

#endif // ENTITYMANAGER_H
