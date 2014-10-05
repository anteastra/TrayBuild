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

	void init();
	QString getSource();
	QString getTarget();

private:
	QSettings *settings;

	void createSettingsFile();

};

#endif // SETTINGS_H
