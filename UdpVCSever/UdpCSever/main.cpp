#include "stdio.h"  
#include "iostream"  
#include "Thread.h"
#include "Udp.h"

using namespace std;

int main(int argc, char* argv[])
{
	//启动线程
	CreateThread(NULL, 0, ThreadReceive, NULL, 0, NULL);		//Model线程

	while (1)
	{
		//显示在主线程等待
		printf("main waitting...............\n");

		if (udpSever.RecvLen > 0)
		{
			//显示接收数据
			printf("Receive length is %d\n", udpSever.RecvLen);
			printf("Receive data is %f\n", udpSever.RecvOutput);
			udpSever.RecvLen = 0;

			//发送浮点数
			float cSendData = -11.11111;
			dataPack.PackPoint(cSendData);
			printf("Send Data: %f\n", cSendData);

			//数据打包
			dataPack.PackPoint3(0.22, 0.33, -0.44); //3个点
			dataPack.PackPoint6(-11.1, -12.2,-13.3, -14.4, -15.5, -16.6); //6个点
			//数据发送
			udpSever.SendData(dataPack.Data, dataPack.Length);
			dataPack.Length = 0;
		}
		Sleep(400);
	}

	udpSever.Close();

	//暂停下等待用户查看结果
	system("pause");

	return 0;
}