#include "entitymanager.h"

EntityManager::EntityManager(QObject *parent)
	: QObject(parent)
{
	settingsManager = new SettingsManager(this);
	totalEntityNumber = 0;
}

EntityManager::~EntityManager()
{
	delete settingsManager;
}


SettingsManager* EntityManager::getSettingsManager()
{
	return settingsManager;
}

void EntityManager::addEntity()
{	
	EntityWidget *widget = new EntityWidget();
	layout->addWidget(widget);
	totalEntityNumber++;
}