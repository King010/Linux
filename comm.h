#ifndef _COMM_H_
#define _COMM_H_
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>
#define PATHNAME "."
#define PROJ_ID 0x6666
#define SERVER_TYPE 1
#define CLIENT_TYPE 2 
#define SIZE 128

struct msgbuf{
long mtype;
char mtext[SIZE];
};
int creatMsgQueue();
int getMsgQueue();
int sendMsg(int msgid,long type,const char*_info);
int recvMsg(int msgid,long type,char out[]);

int destoryMsgQueue(int);


#endif
