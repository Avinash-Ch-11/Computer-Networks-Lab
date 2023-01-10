#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include <arpa/inet.h>

#define MAX 2000
#define PORT 5009
#define SA struct sockaddr

int smtp();
int info();
int sub_options();
char username[100],buffer[MAX];

int main()
{
info();
return 0;
}

int info()
{
	char password[100];
 
	printf("Enter the username: ");
	scanf("%s",username);
 
	printf("Enter the password: ");
	scanf("%s",password);

	strcat(username," ");
	strcat(username,password);
	strcat(username,"\n");

	FILE *fptr;
	fptr = fopen("user.txt","r");
	char usercheck[100];
	int flag =0;
	while(fgets(usercheck,100,fptr)!=NULL){
		int z = strcmp(username,usercheck);
		if(z ==0){
			sub_options();
			flag =1;
			break;
		}
		else{
			flag =2;
		}
	}

	if(flag == 2){
		printf("Incorrect user or passweord\n");
		info();
	}


}

int sub_options(){
	int num;
	printf("1)Manage Mail\n");
	printf("2)Send Mail\n");
	printf("3)Quit\n");
	printf("enter your option:");
	scanf("%d",&num);

	if(num == 2){
		smtp();
	}
}

int smtp(){
int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "Hello from client"; 

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

		printf("Write in the below format\n");
		printf("From:\nTo:\nSubject:\nEnter your body endind with a dot in the next line\n");

	char from[100],to[100],subject[100],body[1000],dot[100],tosend[100];
	char az[100];

		fgets(az,100,stdin);
		fgets(from,100,stdin);
		fgets(to,100,stdin);

		char z;
		int q=0;
			while(to[2]==':')
				{
					if(to[3+q] == '\n'
						{
							break;
						}
							tosend[q] = to[3+q];
							q++;
				}

	fgets(subject,100,stdin);
	fgets(body,100,stdin);
	fgets(dot,100,stdin);
	bzero(buffer,MAX);
	strcat(buffer,from);
	strcat(buffer,to);
	strcat(buffer,subject);
	strcat(buffer,body);
	strcat(buffer,dot);
	send(sock,tosend,100,0);
	send(sock,buffer,MAX,0);
	
	

}























