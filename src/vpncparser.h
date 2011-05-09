#ifndef __VPNCPARSER_H__
#define __VPNCPARSER_H__

#include <QString>

class VpncParser {

protected:
	QString m_gateway;
	QString m_groupId;
	QString m_groupSec;
	QString m_authmode;
	QString m_localPort;
	QString m_xauthUser;
	QString m_xauthPwd;
	
public:
	void parseLine(QString line);
	QString getGateway();
	QString getGroupId();
	QString getGroupSecret();
	QString getAuthmode();
	QString getLocalPort();
	QString getXauthUser();
	QString getXauthPwd();
};

#endif // __VPNCPARSER_H__
