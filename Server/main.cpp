
#include <QtCore/QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	//ȷ��ֻ����һ��
	QSystemSemaphore sema("ChatServerKey", 1, QSystemSemaphore::Open);
	//���ٽ������������ڴ�
	sema.acquire();
	QSharedMemory mem("ChatServerObject");

	// ���ȫ�ֶ����Դ������˳�
	if (!mem.create(1))
	{
		qDebug() << "A server has already been running.";
		sema.release();
		return 0;
	}
	sema.release();
	Server server(NULL);

	return a.exec();
}
