#include "traybuild.h"

#include <QSystemTrayIcon>
#include <QMenu>
#include <QMessageBox>
#include <QCloseEvent>
#include <QThread>
#include <QTextBrowser>

#include "worker.h"
#include "SettingsManager.h"
#include "logger.h"

TrayBuild::TrayBuild(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	Logger::logBrowser = ui.textBrowser;

	downloadManager = new DownloadManager(this);

	entityManager = new EntityManager(this);
	entityManager->setLayout(ui.EntityLayout);
	entityManager->restoreState();

	connect(entityManager, SIGNAL(downloadByRegexp(QString, QString, QString)), downloadManager, SLOT(downloadByRegexp(QString, QString, QString)));
		
	this -> initWindow();
	this -> setTrayIconActions();
	this -> showTrayIcon();
	this -> hide();

	Logger::message("Loading complete");
}

TrayBuild::~TrayBuild()
{
	delete entityManager;
}

void TrayBuild::showTrayIcon()
{
	trayIcon = new QSystemTrayIcon(this);
	QIcon trayImage(SettingsManager::ICON_PATH);
	trayIcon -> setIcon(trayImage);
	trayIcon -> setContextMenu(trayIconMenu);

	connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));

	trayIcon -> show();
}

void TrayBuild::trayActionExecute()
{
	showNormal();
}

void TrayBuild::trayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
	case QSystemTrayIcon::Trigger:
	case QSystemTrayIcon::DoubleClick:
		this -> trayActionExecute();
		break;
	default:
		break;
	}
}

void TrayBuild::setTrayIconActions()
{
	minimizeAction = new QAction("Minimize", this);
	restoreAction = new QAction("Show", this);
	quitAction = new QAction("Exit", this);

	connect (minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
	connect (restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
	connect (quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

	trayIconMenu = new QMenu(this);
	trayIconMenu -> addAction (minimizeAction);
	trayIconMenu -> addAction (restoreAction);
	trayIconMenu -> addAction (quitAction);
}

void TrayBuild::changeEvent(QEvent *event)
{
	QMainWindow::changeEvent(event);
	if (event -> type() == QEvent::WindowStateChange)
	{
		if (isMinimized())
		{
			this -> hide();
		}
	}
}

void TrayBuild::closeEvent(QCloseEvent *e)
{
	//TODO: uncomment later
	this -> hide();
	e -> ignore();
}

void TrayBuild::initWindow()
{
	QIcon *icon = new QIcon(SettingsManager::ICON_PATH);
	this->setWindowIcon(*icon);
		
	ui.targetEdit->setText(entityManager->getSettingsManager()->getTarget());

	connect(ui.pushButtonAddEntity, SIGNAL(clicked()), entityManager, SLOT(addEntity()));	
}