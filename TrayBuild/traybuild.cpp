#include "traybuild.h"

#include <QSystemTrayIcon>
#include <QMenu>
#include <QMessageBox>
#include <QCloseEvent>
#include <QThread>

#include "worker.h"
#include "SettingsManager.h"

TrayBuild::TrayBuild(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	entityManager = new EntityManager(this);
	
	this -> initWindow();
	this -> setTrayIconActions();
	this -> showTrayIcon();
	this -> hide();

	this -> initWorker();
}

TrayBuild::~TrayBuild()
{
	delete entityManager;
}

void TrayBuild::showTrayIcon()
{
	// Создаём экземпляр класса и задаём его свойства...
	trayIcon = new QSystemTrayIcon(this);
	QIcon trayImage(SettingsManager::ICON_PATH);
	trayIcon -> setIcon(trayImage);
	trayIcon -> setContextMenu(trayIconMenu);

	// Подключаем обработчик клика по иконке...
	connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));

	// Выводим значок...
	trayIcon -> show();
}

void TrayBuild::trayActionExecute()
{
	//QMessageBox::information(this, "TrayIcon", "Тестовое сообщение. Замените вызов этого сообщения своим кодом.");
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
	// Setting actions...
	minimizeAction = new QAction("Minimize", this);
	restoreAction = new QAction("Show", this);
	quitAction = new QAction("Exit", this);

	// Connecting actions to slots...
	connect (minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
	connect (restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
	connect (quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

	// Setting system tray's icon menu...
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
	//this -> hide();
	//e -> ignore();
}

void TrayBuild::initWindow()
{
	QIcon *icon = new QIcon(SettingsManager::ICON_PATH);
	this->setWindowIcon(*icon);

	ui.sourceEdit->setText(entityManager->getSettingsManager()->getSource());
	ui.targetEdit->setText(entityManager->getSettingsManager()->getTarget());
}

void TrayBuild::initWorker()
{
	QThread* thread = new QThread;
	Worker* worker = new Worker();
}