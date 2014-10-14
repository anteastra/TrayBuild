#include "SettingsManager.h"

#include "QFile"
#include <QStringList>
#include <QVariant>

const QString SettingsManager::APP_NAME = "TrayBuild";
const QString SettingsManager::ORG_NAME = "anteastra";
const QString SettingsManager::ICON_PATH = ":/images/Resources/icon.ico";

const int SettingsManager::MAX_ENTITIES = 5;


SettingsManager::SettingsManager(QObject *parent)
	: QObject(parent)
{
	settings = new QSettings(SettingsManager::ORG_NAME, SettingsManager::APP_NAME);
}

SettingsManager::~SettingsManager()
{
	delete settings;
}

bool SettingsManager::isExist(int id)
{
	QString key = QString("entity%1name").arg(id);
	return settings->contains(key);
}

QString SettingsManager::getTarget()
{
	return settings->value("output").toString();
}

void SettingsManager::setTarget(const QString & value)
{
	settings->setValue("output",value);
}

QString SettingsManager::getCount()
{
	return settings->value("count").toString();
}

void SettingsManager::setCount(int value)
{
	settings->setValue("count",value);
}

void SettingsManager::saveEntityState(EntityWidget* widget)
{
	QString key = QString("entity%1name").arg(widget->getId());
	settings->setValue(key, widget->getName());

	key = QString("entity%1regexp").arg(widget->getId());
	settings->setValue(key, widget->getRegexp());

	key = QString("entity%1location").arg(widget->getId());
	settings->setValue(key, widget->getLocation());
}

void SettingsManager::removeEntityState(EntityWidget* widget)
{
	QString key = QString("entity%1name").arg(widget->getId());	
	settings->remove(key);

	key = QString("entity%1regexp").arg(widget->getId());
	settings->remove(key);

	key = QString("entity%1location").arg(widget->getId());
	settings->remove(key);
}

void SettingsManager::restoreEntityState(EntityWidget* widget, int id)
{
	widget->setId(id);
	QString key = QString("entity%1name").arg(id);	
	widget->setName(settings->value(key, QString("")).toString());

	key = QString("entity%1regexp").arg(id);	
	widget->setRegexp(settings->value(key, QString("")).toString());

	key = QString("entity%1location").arg(id);	
	widget->setLocation(settings->value(key, QString("")).toString());
}