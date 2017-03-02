
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<pwd.h>
#include<string.h>
void GetLoginName()
{
	struct passwd*pwd;
	pwd=getpwuid(getuid());
	printf("[%s@",pwd->pw_name);
}

void GetHostName()
{
	char name[100]={0};
	gethostname(name,sizeof(name)-1);
	printf("%s",name);
}

void GetDir()
{
	char pwd[100]={0};
	getcwd(pwd,sizeof(pwd)-1);
	int len=strlen(pwd);
	char*p=pwd+len;
	while(*p!='/'&&len--)
	{
		p--;
	}
	p++;
	printf(" %s]#",p);
}

int main()
{
	while(1)
	{
	//	printf("hehehehehe#");
	    GetLoginName();
		GetHostName();
		GetDir();
		fflush(stdout);
		//sleep(5);
		char cmd[128];
		ssize_t _s=read(0,cmd,sizeof(cmd)-1);
		cmd[_s-1]='\0';
		if(_s>0)
		{
			cmd[_s]='\0';
		}
		else
		{	
			perror("read");
			return 1;
		}

		char *_argv[32];
		char *start = cmd;
		_argv[0]=cmd;
		int i = 1;
		while(*start)
		{
			if(isspace(*start))
			{
				*start = '\0';
				start++;
				_argv[i]=start;
				i++;
				continue;
	//			printf("i =%d\n",i);
			}
		
				start++;
		}
	
//	printf("%d",argv);
	     	_argv[i]=NULL;
//			printf("%s\n",cmd);
			pid_t id=fork();
			if(id<0)
			{
				perror("fork");
			}
			else if(id==0)
			{
					execvp(_argv[0],_argv);
					perror("error");
			}
			else
			{	
				int status = 0;
				pid_t ret = waitpid(id,&status,0);
				if(ret>0&&WIFEXITED(status))
				{
				//	sleep(1);
					//exit(1);
				}
				else
				{
					 perror("waitpid");
				}
			//	wait(NULL);
			}
	}	
}