//FormAI DATASET v1.0 Category: System administration ; Style: Romeo and Juliet
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
    int sockfd,newsockfd;
    socklen_t len;
    struct sockaddr_in client_addr,serv_addr;
    char buf[1024];
    int port=8080;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        perror("socket");
        exit(-1);
    }
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_addr.sin_port=htons(port);
    if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
    {
        perror("bind");
        exit(-1);
    }
    if(listen(sockfd,5)<0)
    {
        perror("listen");
        exit(-1);
    }
    printf("\nserver is waiting for connection on port %d\n",port);
    while(1)
    {
        len=sizeof(client_addr);
        if((newsockfd=accept(sockfd,(struct sockaddr *)&client_addr,&len))<0)
        {
            perror("accept");
            exit(-1);
        }
        printf("server get connection from: %s\n",inet_ntoa(client_addr.sin_addr));
        printf("port: %d\n",ntohs(client_addr.sin_port));
        memset(buf,0,sizeof(buf));
        recv(newsockfd,buf,sizeof(buf),0);
        printf("recv:%s\n",buf);
        if(!strcmp(buf,"quit\n"))
        {
            printf("server will exit!\n");
            break;
        }
        send(newsockfd,buf,strlen(buf),0);
        close(newsockfd);
    }
    close(sockfd);
    return 0;
}