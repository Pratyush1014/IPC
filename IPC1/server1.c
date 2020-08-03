#include"stdio.h"
#include"sys/socket.h"
#include"netinet/in.h"
struct sockaddr_in p;
struct student 
{
	char name [20];
	char branch [10];
	int roll ;
};
main()
{
	int sid,nid;
	struct student x;
	sid = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
		p.sin_family = PF_INET ;
		p.sin_port = 3500;
		p.sin_addr.s_addr = 0;
	int len = sizeof(struct sockaddr_in);
	int l = sizeof(struct student);
	bind(sid,(void *)&p,sizeof(struct sockaddr_in));
	listen(sid,1);
	while(1)
	{
		nid = accept(sid,(void *)&p,(void *)&len);
		read(nid,&x,l);
		printf("%d %s %s\n",x.roll,x.name,x.branch);
	}
}
