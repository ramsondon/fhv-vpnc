#ifndef __CONFIGCREATOR_H__
#define __CONFIGCREATOR_H__


#include "configdialogimpl.h"
#include "vpncparser.h"
#include <QString>

class ConfigCreator {

public:
	static const QString PRE_IPSEC_GATEWAY;
	static const QString PRE_IPSEC_GROUP_ID;
	static const QString PRE_IPSEC_GROUP_SECRET;
	static const QString PRE_IKE_AUTHMODE;
	static const QString PRE_LOCAL_PORT;
	static const QString PRE_XAUTH_USERNAME;
	static const QString PRE_XAUTH_PASSWORD;

protected:
	VpncParser m_parser;

	QString generateVpncConfigString();	
	void configure();
	
public:
	ConfigCreator();
	void createVpncConfig();
	bool readVpncConfig();
	
};

#endif // __CONFIGCREATOR_H__
