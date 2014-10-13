#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QTextBrowser>
#include <QString>

class Logger
{
public:
	Logger();
	~Logger();

	static void message(QString msg);		
	static QTextBrowser* logBrowser;
	static int logBrowserSize;
	
};

#endif // LOGGER_H
