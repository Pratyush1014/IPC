#include"stdio.h"
#include"stdlib.h"
#include"sys/socket.h"
#include"netinet/in.h"
struct sockaddr_in p;
struct student 
{
	char name [20];
	char branch [10];
	int roll;
};
main()
{
	int sid;
	struct student x;
	sid = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
	p.sin_family = PF_INET;
	p.sin_port = 3500;
	p.sin_addr.s_addr = 0;
	int status;
	status = connect(sid,&p,sizeof(struct sockaddr_in));
	if(status == -1)
	{
		printf("Connection failed\n");
		exit(0);
	}
	while(1)	
	{
		printf("Enter your roll name branch \n");
		scanf("%d",&x.roll);
		scanf("%s",x.name);
		scanf("%s",x.branch);
		write(sid,&x,sizeof(struct student));
	}
}
