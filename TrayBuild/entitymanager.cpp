#include "entitymanager.h"

EntityManager::EntityManager(QObject *parent)
	: QObject(parent)
{
	SettingsManager* settingsManager = new SettingsManager(this);
}

EntityManager::~EntityManager()
{
	delete settingsManager;
}


SettingsManager* EntityManager::getSettingsManager()
{
	return settingsManager;
}