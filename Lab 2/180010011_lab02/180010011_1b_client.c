#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<unistd.h> 
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#define MYPORT 2122

			void error(char *msg)
				{
    					perror(msg);
    					exit(0);
				}

		int main(int argc, char *argv[])
			{
    				int sockfd, portno, n;
    				struct sockaddr_in serv_addr;
    				struct hostent *server;
    				char buffer[256];

    			if (argc < 2) 
				{
       					fprintf(stderr,"usage %s hostname port\n", argv[0]);
       					exit(0);
    				}
   			portno = MYPORT;
   			sockfd = socket(AF_INET, SOCK_STREAM, 0);

    				if (sockfd < 0) 
      				error("ERROR opening socket");
    				server = gethostbyname(argv[1]);

   					if (server == NULL) 
						{
        						fprintf(stderr,"ERROR, no such host\n");
        						exit(0);
    						}

    				bzero((char *) &serv_addr, sizeof(serv_addr));
    				serv_addr.sin_family = AF_INET;
    				bcopy((char *)server->h_addr, 
         			(char *)&serv_addr.sin_addr.s_addr,
        			server->h_length);
    				serv_addr.sin_port = htons(portno);

    					if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        					error("ERROR connecting");
						printf("Enter Text: ");
						bzero(buffer, 256);
						fgets(buffer, 256, stdin);
						n = write(sockfd, buffer, strlen(buffer));

							if(n < 0)
								{
									perror("Writing");
									exit(1);
								}

							bzero(buffer, 256);
						n = read(sockfd, buffer, 256);

								if(n < 0)
									{
										perror("Reading");
										exit(1);
									}
					printf("%s\n", buffer);
					close(sockfd);

					return 0;
			}



/*OUTPUT---------------------------
gcc 180010011_1b_client.c -o client
./client 127.0.0.1
Enter Text: 
No. of Sentences : 
No. of Words : 
No. of Characters : 
*/
