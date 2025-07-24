//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>

int main(int argc, char*argv[])
{
    int sock_desc,new_sock,c;
    struct sockaddr_in server,client;
    char*message="Hello from server!\n";
    
    //Create socket
    sock_desc=socket(AF_INET,SOCK_STREAM,0);
    if(sock_desc==-1)
    {
       printf("Could not create socket");
    }
    puts("Socket created");
    
    //Prepare the sockaddr_in structure
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port=htons(8888);
    
    //Bind
    if(bind(sock_desc,(struct sockaddr*)&server,sizeof(server))<0)
    {
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
    
    //Listen
    listen(sock_desc,3);
    
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    new_sock = accept(sock_desc,(struct sockaddr*)&client,(socklen_t*)&c);
    if(new_sock<0)
    {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");
    
    //Reply to client
    write(new_sock,message,strlen(message));
    
    return 0;
}