#include "entitymanager.h"

#include <QDir>
#include "logger.h"

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
	if (entities.count() >= SettingsManager::MAX_ENTITIES) return;
	EntityWidget *widget = new EntityWidget();
	widget->setId(getNextId());	
	addEntity(widget);
}

void EntityManager::addEntity(EntityWidget* widget)
{	
	connect(widget, SIGNAL(remove(int)), this, SLOT(removeEntity(int)));
	connect(widget, SIGNAL(save(int)), this, SLOT(saveEntity(int)));
	connect(widget, SIGNAL(download(int)), this, SLOT(downloadEntity(int)));
	entities.append(widget);
	layout->addWidget(widget);

	settingsManager->setCount(entities.count());
	settingsManager->saveEntityState(widget);
}

void EntityManager::removeEntity(int id)
{
	EntityWidget* widget = findWidgetByID(id);;
	int index = -1;
	for( int i=0; i<entities.count(); ++i )
	{ 
		if (entities.at(i) == widget)
		{			
			index = i;
		}
	}

	entities.removeAt(index);
	settingsManager->setCount(entities.count());
	settingsManager->removeEntityState(widget);
	layout->removeWidget(widget);
	delete widget;
}


void EntityManager::saveEntity(int id)
{
	EntityWidget* widget = findWidgetByID(id);
	settingsManager->saveEntityState(widget);	
}

void EntityManager::downloadEntity(int id)
{
	EntityWidget* widget = findWidgetByID(id);
	Logger::message(QString("project '" + widget->getName() + "' is checking for new file"));
	emit downloadByRegexp(widget->getLocation(), QString(getSettingsManager()->getTarget() + QDir::separator() + widget->getName()), widget->getRegexp());
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

EntityWidget* EntityManager::findWidgetByID(int id)
{	
	for( int i=0; i<entities.count(); ++i )
	{ 
		if (entities.at(i)->getId() == id)
		{
			return entities.at(i);
		}
	}
	return NULL;
}

void EntityManager::restoreState()
{
	int id = 0;
	while (id < SettingsManager::MAX_ENTITIES)
	{
		id++;
		if (settingsManager->isExist(id)) 
		{
			EntityWidget* widget = new EntityWidget();			
			settingsManager->restoreEntityState(widget, id);
			addEntity(widget);
		}
	}
}