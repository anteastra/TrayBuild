#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QString>

class Worker : public QObject
{
	Q_OBJECT

public:
	Worker();
	~Worker();

	QString getSource() const { return source; }
	void setSource(QString val) { source = val; }
	QString getDestination() const { return location; }
	void setDestination(QString val) { location = val; }
	QString getRegexp() const { return regexp; }
	void setRegexp(QString val) { regexp = val; }

public slots:
	void process();

private:
	QString source;	
	QString location;	
	QString regexp;

	QString getLastFileName(QString source, QString regexp);
	
signals:
	void finished();
	void error(QString err);
};

#endif // WORKER_H
