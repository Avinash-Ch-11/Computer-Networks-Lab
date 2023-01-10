#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/wait.h>
#define MYPORT 2122



	void error(char *msg)
	{
    		perror(msg);
   	 	exit(1);
	}

		int main(int argc, char *argv[])
		{
     			int sockfd, newsockfd, portno, clilen;
     			char buffer[256];
     			struct sockaddr_in serv_addr, cli_addr;
     		int n;
    
     		sockfd = socket(AF_INET, SOCK_STREAM, 0);
     			if (sockfd < 0) 
        			error("ERROR opening socket");
     				bzero((char *) &serv_addr, sizeof(serv_addr));

     				portno = MYPORT;

     				serv_addr.sin_family = AF_INET;
     				serv_addr.sin_addr.s_addr = INADDR_ANY;
     				serv_addr.sin_port = htons(portno);

     				if (bind(sockfd, (struct sockaddr *) &serv_addr,
              			sizeof(serv_addr)) < 0) 
              			error("ERROR on binding");
     				listen(sockfd,5);


   			while(1)
				{
     					clilen = sizeof(cli_addr);
     					newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     			if (newsockfd < 0) 
          		error("ERROR on accept");

     				if(!fork())
				{
     				bzero(buffer,256);
    				n = read(newsockfd,buffer,255);

     					if (n < 0) error("ERROR reading from socket");
  					int words = 0, sentences = 0, characters;
					for(int m = 0; m < strlen(buffer); m++)
						{
							if(buffer[m] == '.')
								{
									sentences++;
								}
								if(buffer[m] == ' ' || buffer[m] == ' ' || buffer[m] == '\t')
									{
										words++;
									}
						}
	
					words++;
				sleep(strlen(buffer)/10);
				characters = strlen(buffer);
				printf("Message Received\n");
				bzero(buffer, 256);

					strcpy(buffer, "No. of Sentences : ");
					char numtos[255], s[20];
					snprintf(numtos, 255, "%d", sentences);
					strcpy(s, numtos);
					strcat(buffer, s);
					strcat(buffer, "\n");

						strcat(buffer, "No. of Words : ");
						snprintf(numtos, 255, "%d", words);
						strcpy(s, numtos);
						strcat(buffer, s);
						strcat(buffer, "\n");

							strcat(buffer, "No. of Characters : ");
							snprintf(numtos, 255, "%d", characters);
							strcpy(s, numtos);
							strcat(buffer, s);
							strcat(buffer, "\n");

				n = write(newsockfd, buffer, strlen(buffer));
				printf("Characteristics sent\n");

					if(n < 0)
						{
							perror("Writing");
						}
				}
				close(newsockfd);
        			while(waitpid(-1,NULL,WNOHANG) > 0);
				}
				close(sockfd);
				return 0;
		}



/*OUTPUT-----------------------------
gcc 180010011_2_server.c -o server
./server
Message Received
Characteristics sent
Message Received
Characteristics sent
*/



     
