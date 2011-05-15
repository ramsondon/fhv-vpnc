#include "config.h"

const QString Config::CONFIG_FILE = "/etc/vpnc/fhv-vpn.conf";

const QString Config::USERNAME_DEFAULT = "";
const QString Config::USER_PWD_DEFAULT = "";
const QString Config::LOCAL_PORT_DEFAULT = "0";
const QString Config::GATEWAY_DEFAULT = "fhv.vpn.at";		
const QString Config::GROUP_ID_DEFAULT = "fhv-vpn";
const QString Config::GROUP_PWD_DEFAULT = "vpnipsec";
const int Config::AUTHMODE_DEFAULT = 0;
const QString Config::ROOT_PWD_DEFAULT = "";

const QString Config::AUTHMODE_VALUES[] = {"psk","hybrid"};
const int Config::NR_OF_AUTHMODE_VALUES = 2;
const QString Config::CMD_START_VPNC = "fhv-vpn";


Config* Config::pInstance = NULL;	

Config::Config() {

	this->USE_DEFAULT_SETTINGS = false;
}

Config* Config::Instance(){
	if (pInstance == NULL) {
		pInstance = new Config();
	}
	return pInstance;
}