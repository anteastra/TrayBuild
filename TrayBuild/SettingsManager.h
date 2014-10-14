#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>

#include "entitywidget.h"

class SettingsManager : public QObject
{
	Q_OBJECT 

public:
	SettingsManager(QObject *parent);
	~SettingsManager();

	static const QString APP_NAME;
	static const QString ORG_NAME;
	static const QString ICON_PATH;

	static const int MAX_ENTITIES;

	bool isExist(int id);
		
	QString getTarget();
	void setTarget(const QString & value);
	QString getCount();
	void setCount(int value);

public slots:
	void saveEntityState(EntityWidget* widget);
	void removeEntityState(EntityWidget* widget);
	void restoreEntityState(EntityWidget* widget, int id);

private:
	QSettings *settings;

};

#endif // SETTINGS_H
