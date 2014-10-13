#ifndef DOWNLOADITEM_H
#define DOWNLOADITEM_H

#include <QObject>
#include <QString>

class DownloadItem : public QObject
{
	Q_OBJECT

public:
	DownloadItem(QObject *parent);
	~DownloadItem();

	QString getSource() const { return source; }
	void setSource(QString val) { source = val; }
	QString getDestination() const { return destination; }
	void setDestination(QString val) { destination = val; }
	QString getRegexp() const { return regexp; }
	void setRegexp(QString val) { regexp = val; }

private:
	QString source;	
	QString destination;	
	QString regexp;	
};

#endif // DOWNLOADITEM_H
