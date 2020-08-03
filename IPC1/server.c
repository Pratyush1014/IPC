#include"stdio.h"
#include"sys/socket.h"
#include"netinet/in.h"
struct sockaddr_in p;
main()
{
	int sid,nid ;
	sid = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
		p.sin_family = PF_INET;
		p.sin_port = 2000;
		p.sin_addr.s_addr = 0;
	char x[100];
	int len = sizeof(struct sockaddr_in);
	bind(sid,&p,len);
	listen(sid,1);
	while(1)
	{
		nid = accept(sid,&p,&len);
		read(nid,x,100);
		printf("%s\n",x);
	}	
}
