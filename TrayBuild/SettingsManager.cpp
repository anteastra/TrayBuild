#include "SettingsManager.h"

#include "QFile"

const QString SettingsManager::APP_NAME = "TrayBuild";
const QString SettingsManager::ORG_NAME = "anteastra";
const QString SettingsManager::ICON_PATH = ":/images/Resources/icon.ico";


SettingsManager::SettingsManager(QObject *parent)
	: QObject(parent)
{
	settings = new QSettings(SettingsManager::ORG_NAME, SettingsManager::APP_NAME);
}

SettingsManager::~SettingsManager()
{
	delete settings;
}

void SettingsManager::init()
{	
	QFile file(settings->fileName());
	if (!file.exists()) {
		createSettingsFile();
	}
}

void SettingsManager::createSettingsFile()
{
	QString input = "d:\\study\\qt\\tray-input";
	QString output = "d:\\study\\qt\\tray-output";
	settings->setValue("input",input);
	settings->setValue("output",output);
}

QString SettingsManager::getSource()
{
	return settings->value("input").toString();
}

QString SettingsManager::getTarget()
{
	return settings->value("output").toString();
}