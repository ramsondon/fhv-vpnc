#include "configdialogimpl.h"
#include "config.h"
#include "configcreator.h"
//#include <QMessageBox>
//
ConfigDialogImpl::ConfigDialogImpl( QWidget * parent, Qt::WFlags f) : QDialog(parent, f) {
	
	setupUi(this);
	
	init();	
	
	this->connect(buttonSave, SIGNAL(clicked()), SLOT(clickedSaveConfig()));
	this->connect(buttonCancel, SIGNAL(clicked()), SLOT(clickedCancel()));
}

void ConfigDialogImpl::init(){
	
	comboBoxAuthmode->addItem(Config::AUTHMODE_VALUES[0]);
	comboBoxAuthmode->addItem(Config::AUTHMODE_VALUES[1]);
	ConfigCreator* creator = new ConfigCreator();
	if (!creator->readVpncConfig()) {
		//QMessageBox::about(this, "Configuration File",
		// "Could not Open VPNC Configuration File\nLoading default Values");
		this->loadDefaultValues();		
	}
	
	this->refresh();
};

void ConfigDialogImpl::loadDefaultValues() {
	this->lineEditUsername->insert(Config::USERNAME_DEFAULT);
	this->lineEditPassword->insert(Config::USER_PWD_DEFAULT);
	this->lineEditGroupId->insert(Config::GROUP_ID_DEFAULT);
	this->lineEditGroupPwd->insert(Config::GROUP_PWD_DEFAULT);
	this->lineEditGateway->insert(Config::GATEWAY_DEFAULT);
	this->lineEditLocalPort->insert(Config::LOCAL_PORT_DEFAULT);
	this->comboBoxAuthmode->setModelColumn(0);
}

/*
 * Function clickedSaveConfig
 * 
 * Saves the configuration file
 */
void ConfigDialogImpl::clickedSaveConfig() {

	// save state
	this->saveState();
	
	// close window
	this->close();	
}

/*
 * Function clickedCancel
 * 
 * Cancels the Save Option
 */
void ConfigDialogImpl::clickedCancel() {
	
	// Undo Changes
	this->undoChanges();	
	
	// close window
	this->close();		
}

/*
 * Triggers the Show Action of this Dialog
 */
int ConfigDialogImpl::triggerShowAction() {
	this->show();
	return this->exec();
}

/*
 * Closes this Dialog and cleans up all Resources
 */
void ConfigDialogImpl::dispose() {
	if (this->isVisible()) {
		this->close();
	}
	this->destroy();
}

/*
 * Forces Reload of persistent Values
 */
void ConfigDialogImpl::undoChanges() {
	this->refresh();
}

void ConfigDialogImpl::saveState() {
	
	Config::Instance()->USERNAME = this->lineEditUsername->text();
	Config::Instance()->USER_PWD = this->lineEditPassword->text();
	Config::Instance()->GROUP_ID = this->lineEditGroupId->text();
	Config::Instance()->GROUP_PWD = this->lineEditGroupPwd->text();
	Config::Instance()->GATEWAY = this->lineEditGateway->text();
	Config::Instance()->LOCAL_PORT = this->lineEditLocalPort->text();
	Config::Instance()->AUTHMODE = this->comboBoxAuthmode->currentIndex();
	
	
	// save config file
	ConfigCreator creator;
	creator.createVpncConfig();	
}

void ConfigDialogImpl::refresh() {
	this->lineEditUsername->insert(Config::Instance()->USERNAME);
	this->lineEditPassword->insert(Config::Instance()->USER_PWD);
	this->lineEditGroupId->insert(Config::Instance()->GROUP_ID);
	this->lineEditGroupPwd->insert(Config::Instance()->GROUP_PWD);
	this->lineEditGateway->insert(Config::Instance()->GATEWAY);
	this->lineEditLocalPort->insert(Config::Instance()->LOCAL_PORT);
	this->comboBoxAuthmode->setModelColumn(Config::Instance()->AUTHMODE);
}



//

