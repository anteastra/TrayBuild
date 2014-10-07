#include "SettingsManager.h"

#include "QFile"
#include <QStringList>
#include <QVariant>

const QString SettingsManager::APP_NAME = "TrayBuild";
const QString SettingsManager::ORG_NAME = "anteastra";
const QString SettingsManager::ICON_PATH = ":/images/Resources/icon.ico";


SettingsManager::SettingsManager(QObject *parent)
	: QObject(parent)
{
	settings = new QSettings(SettingsManager::ORG_NAME, SettingsManager::APP_NAME);	
	init();
}

SettingsManager::~SettingsManager()
{
	delete settings;
}

void SettingsManager::init()
{	
	if (!settings->childGroups().contains("input")) {
		createSettings();		
	}
}

void SettingsManager::createSettings()
{
	QString input = "d:\\study\\qt\\tray-input2";
	QString output = "d:\\study\\qt\\tray-output";
	settings->setValue("input",input);
	settings->setValue("output",output);
	settings->sync();
}

QString SettingsManager::getSource()
{
	settings->value("input");
	return settings->value("input").toString();
}

QString SettingsManager::getTarget()
{
	return settings->value("output").toString();
}