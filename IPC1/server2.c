#include"stdio.h"
#include"netinet/in.h"
#include"sys/socket.h"
#include"string.h"
struct student 
{
	char name[20];
	char branch[10];
	int roll;
};
struct sockaddr_in p;
main()
{
	struct student x;
	int len =sizeof(struct sockaddr_in);
	int l = sizeof(struct student);
	int sid,nid ;
	sid = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
		p.sin_family = PF_INET;
		p.sin_port = 2000;
		p.sin_addr.s_addr=0;
	bind(sid,&p,sizeof(struct sockaddr_in));
	listen(sid,3);
	while(1)
	{
		nid = accept(sid,&p,&len);
		printf("Connetion from : %s\n",inet_ntoa(p.sin_addr.s_addr));
		read(nid,&x,l);
		printf("%d %s %s \n",x.roll,x.name,x.branch);
		memset(&x,0,sizeof(struct student));
	}
}
