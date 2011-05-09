#include "configcreator.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include "config.h"
#include "vpncparser.h"
#include "configdialogimpl.h"
//#include <QMessageBox>

const QString ConfigCreator::PRE_IPSEC_GATEWAY = "IPSec gateway";
const QString ConfigCreator::PRE_IPSEC_GROUP_ID = "IPSec ID";
const QString ConfigCreator::PRE_IPSEC_GROUP_SECRET = "IPSec secret";
const QString ConfigCreator::PRE_IKE_AUTHMODE = "IKE Authmode";
const QString ConfigCreator::PRE_LOCAL_PORT = "Local Port";
const QString ConfigCreator::PRE_XAUTH_USERNAME = "Xauth username";
const QString ConfigCreator::PRE_XAUTH_PASSWORD = "Xauth password";

ConfigCreator::ConfigCreator(){
}

QString ConfigCreator::generateVpncConfigString() {
	
	QString configString = PRE_IPSEC_GATEWAY + " " + Config::Instance()->GATEWAY + "\n";
	configString.append(PRE_IPSEC_GROUP_ID + " " + Config::Instance()->GROUP_ID + "\n");
	configString.append(PRE_IPSEC_GROUP_SECRET + " " + Config::Instance()->GROUP_PWD + "\n");
	configString.append(PRE_IKE_AUTHMODE + " " + Config::Instance()->AUTHMODE + "\n");
	configString.append(PRE_LOCAL_PORT + " " + Config::Instance()->LOCAL_PORT + "\n");
	configString.append(PRE_XAUTH_USERNAME + " " + Config::Instance()->USERNAME + "\n");
	configString.append(PRE_XAUTH_PASSWORD + " " + Config::Instance()->USER_PWD);
	return configString;
}


void ConfigCreator::createVpncConfig() {
	
	
	QFile file(Config::Instance()->CONFIG_FILE);
	
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;

	QTextStream out(&file);
	QString cs = generateVpncConfigString(); 
	out << cs.toLatin1();
	if (file.isOpen())
		file.close();
}

bool ConfigCreator::readVpncConfig() {
	
	QFile file(Config::Instance()->CONFIG_FILE);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		
		// config file does not exist yet - use default values
		Config::Instance()->USERNAME = Config::USERNAME_DEFAULT;
		Config::Instance()->USER_PWD = Config::USER_PWD_DEFAULT;
		Config::Instance()->GATEWAY = Config::GATEWAY_DEFAULT;
		Config::Instance()->GROUP_ID = Config::GROUP_ID_DEFAULT;
		Config::Instance()->GROUP_PWD = Config::GROUP_PWD_DEFAULT;
		Config::Instance()->LOCAL_PORT = Config::LOCAL_PORT_DEFAULT;
		Config::Instance()->AUTHMODE = Config::AUTHMODE_DEFAULT;
		Config::Instance()->ROOT_PWD = Config::ROOT_PWD_DEFAULT;
		return false;
	}
	
	int lineCount = 0;
	QTextStream in(&file);
	QString line = in.readLine();
	while (!line.isNull()) {
		m_parser.parseLine(line);
		line = in.readLine();
		lineCount++;
		//QMessageBox::about(NULL,"CLine", line);
	}
	this->configure();
	return true;
}

void ConfigCreator::configure() {
	
	Config::Instance()->GATEWAY = m_parser.getGateway(); 	
	Config::Instance()->GROUP_ID = m_parser.getGroupId();	
	Config::Instance()->GROUP_PWD = m_parser.getGroupSecret();	
	Config::Instance()->LOCAL_PORT = m_parser.getLocalPort();	
	Config::Instance()->USERNAME = m_parser.getXauthUser();	
	Config::Instance()->USER_PWD = m_parser.getXauthPwd();
	
	int authmode = 0;
	for (int i = 0; i < Config::NR_OF_AUTHMODE_VALUES; i++) {
		if (m_parser.getAuthmode().compare(Config::AUTHMODE_VALUES[i])) {
			authmode = i;
			break;
		}
	}
	Config::Instance()->AUTHMODE = authmode;
}
