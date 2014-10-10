#include "entitymanager.h"

EntityManager::EntityManager(QObject *parent)
	: QObject(parent)
{
	settingsManager = new SettingsManager(this);
	maxEntityNumber = 0;
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
	widget->setId(getNextId());	
	connect(widget, SIGNAL(remove(int)), this, SLOT(removeEntity(int)));
	entities.append(widget);
	layout->addWidget(widget);
}

void EntityManager::removeEntity(int id)
{
	EntityWidget* widget;
	int index = -1;

	for( int i=0; i<entities.count(); ++i )
	{ 
		if (entities.at(i)->getId() == id)
		{
			widget = entities.at(i);
			index = i;
		}
	}

	entities.removeAt(index);
	layout->removeWidget(widget);
	delete widget;
}

int EntityManager::getNextId()
{
	if (entities.count() == maxEntityNumber) 
	{
		maxEntityNumber++;
		return maxEntityNumber;
	}
	int nextId = 0;

	foreach(EntityWidget* widget, entities) 
	{
		int current = widget->getId();
		nextId++;
		if (nextId != current) 
		{
			bool isUsed = false;
			foreach(EntityWidget* checkWidget, entities)
			{
				if (checkWidget->getId() == nextId)
					isUsed = true;
			}
			if (!isUsed)
				return nextId;
		}
	}

	return entities.count()+1;
}