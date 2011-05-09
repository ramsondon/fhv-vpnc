#include "mainwindowimpl.h"
#include <QLineEdit>
#include <stdio.h>
#include <stdlib.h>

//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) : QMainWindow(parent, f) {
	
	setupUi(this);

	this->isChecked = false;
	this->configDialog = new ConfigDialogImpl(this, f);	
	
	this->connect(buttonConnect, SIGNAL(clicked()), SLOT(clickedConnect()));
	this->connect(buttonCancel, SIGNAL(clicked()), SLOT(clickedCancel()));
	this->connect(actionOpenConfigDialog, SIGNAL(triggered()), this, SLOT(clickedOpenConfig()));
	this->connect(checkBoxShowRootPwd, SIGNAL(stateChanged(int)), SLOT(changedCheckBox()));
}


void MainWindowImpl::changedCheckBox(){
	if (this->isChecked) {
		this->isChecked = false;
		this->lineEditRootPwd->setEchoMode(QLineEdit::Password);
		return;
	}
	this->lineEditRootPwd->setEchoMode(QLineEdit::Normal);
	this->isChecked = true;
}

/*
 * Function clickedConnect
 * 
 * Connects to the FHV specified VPN
 */
void MainWindowImpl::clickedConnect() {
	QString localPwd = this->lineEditRootPwd->text();
	QString connectRequest = "echo " + localPwd + " | sudo -S " + Config::CMD_START_VPNC.toAscii();
	int retCode = system(connectRequest.toAscii());
	
}

/*
 * Function clickedCancel
 * Quits the Program
 */
void MainWindowImpl::clickedCancel() {
	// close window	
	this->dispose();
}

/*
 * Function clickedOpenConfig
 * Opens the Configuration Dialog
 */
int MainWindowImpl::clickedOpenConfig() {
	return this->configDialog->triggerShowAction();
}

/*
 * Exits Program and Cleans up all resources
 */
void MainWindowImpl::dispose() {
	if (this->isVisible()) {
		this->close();
	}
	// dispose all Child Windows	
	this->configDialog->dispose();
	this->destroy();
}
//
