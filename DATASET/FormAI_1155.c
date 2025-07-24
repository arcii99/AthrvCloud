//FormAI DATASET v1.0 Category: Networking ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

#define PORT 8000
#define MAXLINE 1024

int main(){
    int sockfd,n;
    struct sockaddr_in servaddr,cliaddr;
    char buffer[MAXLINE];

    // Creating a socket
    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd<0){
        perror("Socket Creation Failed!");
        exit(1);
    }

    // Initializing server address
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    servaddr.sin_port=htons(PORT);

    // Binding socket with server address
    if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0){
        perror("Socket Bind Failed!");
        exit(1);
    }

    printf("Server is running on PORT no: %d\n",PORT);

    // Receiving message from client
    n=recvfrom(sockfd,buffer,MAXLINE,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
    buffer[n]='\0';
    printf("Client: %s\n",buffer);

    // Sending message to client
    char *msg="Hello from Server!";
    sendto(sockfd,msg,strlen(msg),0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
    printf("Message sent to client: %s\n",msg);

    return 0;
}