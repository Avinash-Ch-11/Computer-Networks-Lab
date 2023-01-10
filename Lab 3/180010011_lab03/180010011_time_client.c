#include<netinet/in.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<strings.h>

	int main()
	     {
		struct sockaddr_in sa, cli;
		int n, sockfd;
		int len; 
		char buff[1000];
		sockfd = socket(AF_INET, SOCK_STREAM,0);
		if (sockfd < 0)
	          {
			printf("ERROR IN SOCKET\n");
			exit(0);
		  }
		else printf("SOCKET IS OPENED\n");
	bzero(&sa, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(10000);
		if (connect(sockfd, (struct sockaddr*) &sa, sizeof(sa))<0)
			{
				printf("ERROR IN CONNECTION\n");
				exit(0);
			}
		else printf("CONNECTED SUCCESSFULLY\n");
			if (n = read(sockfd, buff, sizeof(buff))<0)
				{
					printf("ERROR IN READING\n");
					exit(0);
				}
				else{printf("MESSAGE READ\n %s", buff);} 
			    
               }

//--------------COMMENT----------------------
/*
cc 180010011_time_client.c -o client
./client
SOCKET IS OPENED
CONNECTED SUCCESSFULLY
MESSAGE READ
 Wed Feb  5 16:20:43 2020
*/
