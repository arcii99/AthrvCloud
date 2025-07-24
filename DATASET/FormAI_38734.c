//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>

#define MAXLINE 1024

int main(int argc,char *argv[])
{
    int sockfd;
    char recvline[MAXLINE];
    struct sockaddr_in servaddr;

    if(argc!=2)
    {
        printf("Usage: ./a.out <IP address>\n");
        exit(1);
    }

    if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
    {
        printf("Socket Creation Error.\n");
        exit(1);
    }

    memset(&servaddr,0,sizeof(servaddr));

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(80);
    inet_pton(AF_INET,argv[1],&servaddr.sin_addr);

    if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
    {
        printf("Connect Error.\n");
        exit(1);
    }

    char *http_request="GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
    if(write(sockfd,http_request,strlen(http_request)+1)<0)
    {
        printf("Write Error.\n");
        exit(1);
    }

    int n;
    while((n=read(sockfd,recvline,MAXLINE-1))>0)
    {
        recvline[n]='\0';
        printf("%s",recvline);
    }

    if(n<0)
    {
        printf("Read Error.\n");
        exit(1);
    }

    close(sockfd);

    return 0;
}