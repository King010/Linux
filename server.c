
#include"comm.h"

int main()
{
    int msgid=creatMsgQueue();
	printf("msgid: %d\n",msgid);
	char buf[SIZE];
	while(1)
	{
        recvMsg(msgid,CLIENT_TYPE,buf);
		printf("client# %s\n",buf);

		fflush(stdout);
		ssize_t s=read(0,buf,sizeof(buf)-1);
		if(s>0)
		{
			buf[s-1]='\0';
			sendMsg(msgid,SERVER_TYPE,buf);
		}
	}
	deseoryMsgQueue(msgid);
	return 0;
}