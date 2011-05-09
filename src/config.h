#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <QString>
#include <QList>

class Config {

public:

	static const QString CONFIG_FILE;

	/*
	 * DEFAULT VALUES
 	 */	
	
	// Main Window
	static const QString ROOT_PWD_DEFAULT;
	
	// Config Dialog
	static const QString USERNAME_DEFAULT;
	static const QString USER_PWD_DEFAULT;
	static const QString LOCAL_PORT_DEFAULT;
	static const QString GATEWAY_DEFAULT;		
	static const QString GROUP_ID_DEFAULT;
	static const QString GROUP_PWD_DEFAULT;
	static const int AUTHMODE_DEFAULT;
	
	static const QString AUTHMODE_VALUES[];
	static const int NR_OF_AUTHMODE_VALUES;
	
	
	static const QString CMD_START_VPNC;
	/*
	 * RUNNING VALUES
 	 */	
public: 

	bool USE_DEFAULT_SETTINGS;
	 
 	// Main Window
	QString ROOT_PWD;
	
	// Config Dialog
	QString USERNAME;
	QString USER_PWD;
	QString LOCAL_PORT;
	QString GATEWAY;		
	QString GROUP_ID;
	QString GROUP_PWD;
	int AUTHMODE;
	
public:
	static Config* Instance();	
	
protected:
	
	Config();

private:
	static Config* pInstance;
};
#endif // __CONFIG_H__
