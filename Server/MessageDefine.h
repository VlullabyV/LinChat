#ifndef _MESSAGEDEFINE_H
#define  _MESSAGEDEFINE_H

enum MessageType
{
	CS_Heartbeat,
	CS_Login,
	CS_Logout,
	CS_Chat_text = 50,
	CS_Chat_voice,
	CS_Chat_img,

	/*�ͻ��˷��͸�����˵������ϢID*/
	Max_CS_MSG,


	SC_Heartbeat=500,
	SC_Login,
	SC_Logout,
	SC_Chat_text=550,
	SC_Chat_voice,
	SC_Chat_img,

	/*����˷��͸��ͻ��˵������ϢID*/
	Max_SC_MSG
};

#endif //#ifndef _MESSAGEDEFINE_H