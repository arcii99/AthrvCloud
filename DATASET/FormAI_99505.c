//FormAI DATASET v1.0 Category: Chat server ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#define PORT 8080
int main()
{
    int server_fd,new_socket,valread;
    struct sockaddr_in address;
    int opt=1;
    int addrlen=sizeof(address);
    char buffer[1024]={0};
    char *hello="Hello from server";
    if((server_fd=socket(AF_INET,SOCK_STREAM,0))==0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    if(setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT,&opt,sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family=AF_INET;
    address.sin_addr.s_addr=INADDR_ANY;
    address.sin_port=htons(PORT);
    if(bind(server_fd,(struct sockaddr *)&address,sizeof(address))<0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    if(listen(server_fd,3)<0)
    {
        perror("Listen");
        exit(EXIT_FAILURE);
    }
    if((new_socket=accept(server_fd,(struct sockaddr *)&address,(socklen_t*)&addrlen))<0)
    {
        perror("Accept");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        valread=read(new_socket,buffer,1024);
        if(valread<=0)
        {
            break;
        }
        printf("Received request from client: %s\n",buffer);
        send(new_socket,hello,strlen(hello),0);
    }
    return 0;
}