#ifndef __MESSAGEHANDLER_H__
#define __MESSAGEHANDLER_H__



class MessageHandler {
	

	
public:
	static MessageHandler* Instance();	
	
private:
	static MessageHandler* pInstance;
	//QMap<(QString) *func(void)> m_callbacks;
	
};
#endif // __MESSAGEHANDLER_H__
