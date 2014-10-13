#include "worker.h"

#include <QFile>
#include <QDir>

#include "logger.h"

Worker::Worker(): QObject()
{

}

Worker::~Worker()
{

}

void Worker::process()
{
	QString lastFile = getLastFileName(source, regexp);
	if (lastFile == NULL) 
	{
		Logger::message("there is no file to load by regex : '" + regexp + "'");
		return;
	}
	QDir dir(location);
	if (!dir.exists()) {
		Logger::message("directory not found: '" + location + "'");
		Logger::message("creating directory: '" + location + "'");
		dir.mkpath(".");
	}
	if (dir.exists(lastFile)) {
		Logger::message("newest file is already exist: '" + lastFile + "'");
		return;
	}


	Logger::message("starting download '" + lastFile + "'");
	if (QFile::copy(QString(source + QDir::separator() + lastFile), QString(location + QDir::separator() + lastFile)))
	{
		Logger::message("download finished '" + lastFile + "'");
	}	
}

QString Worker::getLastFileName(QString source, QString regexp)
{	
	QDir dir(source);	
	if (!dir.exists())
	{
		Logger::message("source directory not exists '" + source + "'");
		return NULL;
	}
	dir.setFilter(QDir::Files);
	dir.setSorting(QDir::Time);
	QFileInfoList list = dir.entryInfoList();
	QRegExp rx(regexp);
	foreach (QFileInfo fileInfo, list)
	{
		if (rx.indexIn(fileInfo.fileName()) >= 0)
			return fileInfo.fileName();
	}
	
	return NULL;
}