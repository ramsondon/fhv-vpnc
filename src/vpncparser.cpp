#include "vpncparser.h"
#include "configcreator.h"


void VpncParser::parseLine(QString line) {

	// IPSec -> Gateway
	if (line.startsWith(ConfigCreator::PRE_IPSEC_GATEWAY)) {
		m_gateway = line.right(ConfigCreator::PRE_IPSEC_GATEWAY.size());
	// IPSec Group Id		
	} else if (line.startsWith(ConfigCreator::PRE_IPSEC_GROUP_ID)){
		m_groupId = line.right(ConfigCreator::PRE_IPSEC_GROUP_ID.size());
	// Group Password
	} else if (line.startsWith(ConfigCreator::PRE_IPSEC_GROUP_SECRET)){
		m_groupSec = line.right(ConfigCreator::PRE_IPSEC_GROUP_SECRET.size());
	// IKE Authmode
	} else if (line.startsWith(ConfigCreator::PRE_IKE_AUTHMODE)) {
		m_authmode = line.right(ConfigCreator::PRE_IKE_AUTHMODE.size());
	// Local Port
	} else if (line.startsWith(ConfigCreator::PRE_LOCAL_PORT)){
		m_localPort = line.right(ConfigCreator::PRE_LOCAL_PORT.size());
	// Xauth username
	} else if (line.startsWith(ConfigCreator::PRE_XAUTH_USERNAME)){
		m_xauthUser = line.right(ConfigCreator::PRE_XAUTH_USERNAME.size());
	// Xauth password
	} else if (line.startsWith(ConfigCreator::PRE_XAUTH_PASSWORD)){
		m_xauthPwd = line.right(ConfigCreator::PRE_XAUTH_PASSWORD.size());
	}
}


QString VpncParser::getGateway(){
	return m_gateway;
}
QString VpncParser::getGroupId(){
	return m_groupId;
}
QString VpncParser::getGroupSecret(){
	return m_groupSec;
}
QString VpncParser::getAuthmode() {
	return m_authmode;
}
QString VpncParser::getLocalPort(){
	return m_localPort;
}
QString VpncParser::getXauthUser(){
	return m_xauthUser;
}
QString VpncParser::getXauthPwd(){
	return m_xauthPwd;
}