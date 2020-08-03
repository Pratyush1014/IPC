#include"stdio.h"
#include"sys/socket.h"
#include"netinet/in.h"
struct sockaddr_in p;
main()
{
	char x[100];
	int sid,status ;
	sid = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
		p.sin_family = PF_INET;
		p.sin_port = 2000;
		p.sin_addr.s_addr = 0;
	status = connect(sid,&p,sizeof(struct sockaddr_in));
	if (status == -1){
		printf("connection failed \n");exit(0);}
	else
	{
		printf("Enter data to send : \n");
		scanf("%s",x);
		write(sid,x,100);
	}
}
