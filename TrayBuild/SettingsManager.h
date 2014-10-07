#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>

class SettingsManager : public QObject
{
	Q_OBJECT 

public:
	SettingsManager(QObject *parent);
	~SettingsManager();

	static const QString APP_NAME;
	static const QString ORG_NAME;
	static const QString ICON_PATH;
		
	QString getSource();
	QString getTarget();

private:
	QSettings *settings;
	void init();
	void createSettings();

};

#endif // SETTINGS_H
