#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct in_addr
{
	unsigned long s_addr;
};

struct sockaddr_in {
	short int sin_family;
	unsigned short int sin_port;
	struct in_addr sin_addr;
	unsigned char sin_zero[8];
};

int main(){
	struct sockaddr_in my_addr;
		my_addr.sin_family = PF_INET;
		my_addr.sin_port = htons(MYPORT);
		memset(&(my_addr. sin_zero ) , ’\0’, 8);
		net_aton(LOCALHOST, &(my_addr.sin_addr )); 
	int sock=socket(PF_INET, SOCK_STREAM,0);
	int bon=bind(sock, &my_addr, sizeof(struct sockaddr_in))
	printf("%d\n%d\n",sock,bon );




};