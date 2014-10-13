#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QObject>
#include <QList>
#include "downloaditem.h"

class DownloadManager : public QObject
{
	Q_OBJECT

public:
	DownloadManager(QObject *parent);
	~DownloadManager();

public slots:
	void downloadByRegexp(QString source, QString destination, QString regexp);

private:
	QList<DownloadItem*> downloadList;
};

#endif // DOWNLOADMANAGER_H
