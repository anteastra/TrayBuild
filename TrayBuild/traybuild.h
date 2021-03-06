#ifndef TRAYBUILD_H
#define TRAYBUILD_H

#include <QtGui/QMainWindow>
#include <QSystemTrayIcon>
#include <QString>

#include "ui_traybuild.h"
#include "entitymanager.h"
#include "downloadmanager.h"

class TrayBuild : public QMainWindow
{
	Q_OBJECT

public:
	TrayBuild(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TrayBuild();

	Ui::TrayBuildClass ui;

protected:
	void closeEvent(QCloseEvent *e);

private slots:
	void changeEvent(QEvent*);
	void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
	void trayActionExecute();
	void setTrayIconActions();
	void showTrayIcon();
	void on_targetEdit_textChanged(const QString & value);

private:
	void initWindow();
	void initWorker();

	
	QMenu *trayIconMenu;
	QAction *minimizeAction;
	QAction *restoreAction;
	QAction *quitAction;
	QSystemTrayIcon *trayIcon;
	EntityManager *entityManager;
	DownloadManager *downloadManager;
};

#endif // TRAYBUILD_H
