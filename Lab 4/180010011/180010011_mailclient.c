#include <stdio.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX 2000
#define PORT 5009
#define SA struct sockaddr

    char buffer[MAX]; 
	int main()
	{
		time_t tick;
		char str[1000];

		int server_fd, new_socket, valread; 
    	struct sockaddr_in address; 

    	int opt = 1; 
    	int addrlen = sizeof(address); 

    	char *hello = "Hello from server"; 
       
    		// Creating socket file descriptor 
   			 if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    		{ 
       			perror("socket failed"); 
        		exit(EXIT_FAILURE); 
    		} 
       
    		// Forcefully attaching socket to the port 8080 
    		if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    			{ 
       				perror("setsockopt"); 
        			exit(EXIT_FAILURE); 
    			} 

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    		// Forcefully attaching socket to the port 8080 
    		if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    		{ 
        		perror("bind failed"); 
        		exit(EXIT_FAILURE); 
   			} 

    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    else{
		printf("Connected\n");
	}
	bzero(buffer,MAX);
	char touser[100];
	recv(new_socket,touser,100,0);
	bzero(buffer,MAX);
	recv(new_socket,buffer,MAX,0);
	tick = time(NULL);
	snprintf(str, sizeof(str), "%s", ctime(&tick));
	strcat(touser,"MyMailBox.txt");
	strcat(buffer,str);

	FILE *fptr;
	fptr=fopen(touser,"a");
	if(fptr == NULL){printf("unable to open\n");}
	fprintf(fptr,"%s",buffer);
	

}















