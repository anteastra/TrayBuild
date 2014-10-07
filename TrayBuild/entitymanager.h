#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <QObject>

#include "SettingsManager.h"

class EntityManager : public QObject
{
	Q_OBJECT

public:
	EntityManager(QObject *parent);
	~EntityManager();

	SettingsManager* getSettingsManager();

private:
	SettingsManager *settingsManager;
};

#endif // ENTITYMANAGER_H
