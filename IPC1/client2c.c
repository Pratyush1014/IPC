#include"stdio.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"stdlib.h"
struct student
{
	int roll;
	char name[20];
	char branch[10];
};
struct sockaddr_in p;
main()
{
	int sid ;
	struct student x;
	sid = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
	p.sin_family = PF_INET;
	p.sin_port = 2000;
	p.sin_addr.s_addr = 0;
	int status;
	int len = sizeof(struct sockaddr_in);
	status = connect(sid,&p,sizeof(struct sockaddr_in));
	if (status == -1)
	{
		printf("Connection failed");exit(0);
	}
	char ch[4];
	while(1)
	{
		printf("Enter roll name branch\n");
		scanf("%d %s %s",&x.roll,x.name,x.branch);
		write(sid,&x,sizeof(struct student));
		printf("do you wanna continue\n");
		scanf("%s",ch);
		if(strcmp(ch,"no")==0){exit(0);}
		memset(&x,0,sizeof(struct student));
	}
}
