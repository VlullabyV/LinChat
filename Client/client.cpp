#include "client.h"
#include <QMessageBox>
#include <QScrollBar>

Client::Client(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.textEdit_Send->setFocusPolicy(Qt::StrongFocus);
	ui.textBrowser_Display->setFocusPolicy(Qt::NoFocus);

	port = 7750;
	QHostAddress addr("192.168.10.119");

	Socket = new QTcpSocket;
	Socket->connectToHost(addr, port);
	connect(Socket, SIGNAL(connected()), this, SLOT(processConnection()));
}

Client::~Client()
{

}

void Client::processConnection()
{
	startTimer(1000);
}

void Client::timerEvent(QTimerEvent *t)
{
	QByteArray datagram;
	QDataStream iStream(&datagram, QIODevice::WriteOnly);
	iStream << Heartbeat;
	Socket->write(datagram);
}

void Client::sendMessage(MessageType type, QString serverAddress)
{

}

void Client::on_Send_clicked()
{
	sendMessage(Message);
}
void Client::on_Close_clicked()
{
	this->destroy();
}

QString Client::getIP()  //��ȡip��ַ
{
	QList<QHostAddress> list = QNetworkInterface::allAddresses();
	foreach(QHostAddress address, list)
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol) //����ʹ��IPv4��ַ
			return address.toString();
	}
	return 0;
}


QString Client::getUserName()
{
	QStringList envVariables;
	envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
		<< "HOSTNAME.*" << "DOMAINNAME.*";
	QStringList environment = QProcess::systemEnvironment();
	foreach(QString string, envVariables)
	{
		int index = environment.indexOf(QRegExp(string));
		if (index != -1)
		{
			QStringList stringList = environment.at(index).split('=');
			if (stringList.size() == 2)
			{
				return stringList.at(1);
				break;
			}
		}
	}
	return false;
}


QString Client::getMessage()  //���Ҫ���͵���Ϣ
{
	QString msg = ui.textEdit_Send->toHtml();

	ui.textEdit_Send->clear();
	ui.textEdit_Send->setFocus();
	return msg;
}