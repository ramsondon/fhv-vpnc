#include "vpncparser.h"
#include "configcreator.h"


void VpncParser::parseLine(QString line) {

	// IPSec -> Gateway
	if (line.startsWith(ConfigCreator::PRE_IPSEC_GATEWAY)) {
		m_gateway = line.right(line.size() - ConfigCreator::PRE_IPSEC_GATEWAY.size()-1);
	// IPSec Group Id		
	} else if (line.startsWith(ConfigCreator::PRE_IPSEC_GROUP_ID)){
		m_groupId = line.right(line.size() - ConfigCreator::PRE_IPSEC_GROUP_ID.size()-1);
	// Group Password
	} else if (line.startsWith(ConfigCreator::PRE_IPSEC_GROUP_SECRET)){
		m_groupSec = line.right(line.size() - ConfigCreator::PRE_IPSEC_GROUP_SECRET.size()-1);
	// IKE Authmode
	} else if (line.startsWith(ConfigCreator::PRE_IKE_AUTHMODE)) {
		m_authmode = line.right(line.size() - ConfigCreator::PRE_IKE_AUTHMODE.size()-1);
	// Local Port
	} else if (line.startsWith(ConfigCreator::PRE_LOCAL_PORT)){
		m_localPort = line.right(line.size() - ConfigCreator::PRE_LOCAL_PORT.size()-1);
	// Xauth username
	} else if (line.startsWith(ConfigCreator::PRE_XAUTH_USERNAME)){
		m_xauthUser = line.right(line.size() - ConfigCreator::PRE_XAUTH_USERNAME.size()-1);
	// Xauth password
	} else if (line.startsWith(ConfigCreator::PRE_XAUTH_PASSWORD)){
		m_xauthPwd = line.right(line.size() - ConfigCreator::PRE_XAUTH_PASSWORD.size()-1);
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