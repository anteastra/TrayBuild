#include "logger.h"
#include <QtGui\QTextCursor>
#include <QtCore\QLocale>
#include <QTime>
#include <QTextBlock>

QTextBrowser* Logger::logBrowser = NULL;
int Logger::logBrowserSize = 3;

void Logger::message(QString msg)
{
	QTime time = QTime::currentTime();
	QString timeString = time.toString();

	logBrowser->append(timeString + "\t" + msg);
	/*
	if (logBrowser->document()->blockCount() > logBrowserSize)
	{
		QTextBlock block = logBrowser->document()->begin();
		while (block.isValid()) {
			QTextCursor cursor(block);
			block = block.next();
			cursor.select(QTextCursor::BlockUnderCursor);
			cursor.removeSelectedText();			
		}

		logBrowser->append(timeString + "\t" + msg);
	} else
	{
		logBrowser->append(timeString + "\t" + msg);
	}	*/
}

