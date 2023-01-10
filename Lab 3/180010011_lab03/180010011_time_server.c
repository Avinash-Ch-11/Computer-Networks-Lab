#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

	int main()
	{
		struct sockaddr_in sa;
		struct sockaddr_in cli;
		int sockfd, conntfd;
		int len, ch;
		char str[1000];
		time_t tick;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		{
			printf("ERROR IN SOCKET\n");
			exit(0);
		}
	else printf("SOCKET OPENED\n");

		bzero(&sa, sizeof(sa));
		sa.sin_port = htons(10000);
		sa.sin_addr.s_addr = htonl(0);
		
		if (bind(sockfd, (struct sockaddr*)&sa, sizeof(sa))<0)
			{
				printf("ERROR IN BINDING\n");
			}
		else printf("BINDED SUCCESSFULLY\n");
		listen(sockfd, 50);
	for(;;)
		{
			len = sizeof(ch);
			conntfd = accept(sockfd, (struct sockaddr*)&cli, &len);
			printf("ACCEPTED\n");
			tick = time(NULL);
			snprintf(str, sizeof(str), "%s", ctime(&tick));
			printf("%s", str);
			write(conntfd, str, 1000);
		}

		
	}

//--------------COMMENT----------------------
/*
cc 180010011_time_server.c -o server
./server
SOCKET OPENED
BINDED SUCCESSFULLY
ACCEPTED
Wed Feb  5 16:20:43 2020
*/
