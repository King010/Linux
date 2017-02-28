#include"comm.h"

int main()
{
    int msgid=getMsgQueue();
	printf("msgid:%d\n",msgid);
	char buf[SIZE];
	while(1)
	{
			//send->recv
		printf("please Enter$");
		fflush(stdout);
		ssize_t s=read(0,buf,sizeof(buf)-1);
		if(s>0)
		{
			buf[s-1]='\0';
			sendMsg(msgid,CLIENT_TYPE,buf);
		}
        recvMsg(msgid,SERVER_TYPE,buf);
		printf("server# %s\n",buf);
	}
	return 0;
}