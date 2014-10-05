#ifndef WATCHFOLDER_H
#define WATCHFOLDER_H

#include <QObject>

class WatchFolder : public QObject
{
	Q_OBJECT

public:
	WatchFolder(QObject *parent);
	~WatchFolder();

private:
	
};

#endif // WATCHFOLDER_H
