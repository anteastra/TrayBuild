#include "downloadmanager.h"

#include <QThread>

#include "worker.h"

DownloadManager::DownloadManager(QObject *parent)
	: QObject(parent)
{

}

DownloadManager::~DownloadManager()
{

}


void DownloadManager::downloadByRegexp(QString source, QString destination, QString regexp)
{
	/*
	DownloadItem* item = new DownloadItem(this);
	item->setSource(source);
	item->setDestination(destination);
	item->setRegexp(regexp);
	downloadList.append(item);*/

	QThread* thread = new QThread;
	Worker* worker = new Worker();

	worker->setDestination(destination);
	worker->setSource(source);
	worker->setRegexp(regexp);

	worker->moveToThread(thread);
	connect(thread, SIGNAL(started()), worker, SLOT(process()));
	connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
	connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

	thread->start();
}