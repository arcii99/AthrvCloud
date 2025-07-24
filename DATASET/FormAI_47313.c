//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define SERVER_PORT 25

int main() {

    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[1024];

    sockfd=socket(AF_INET,SOCK_STREAM,0);

    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    servaddr.sin_port=htons(SERVER_PORT);

    connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

    n=read(sockfd,buffer,sizeof(buffer)-1);
    buffer[n]='\0';
    printf("%s",buffer);

    sprintf(buffer,"HELO localhost\r\n");
    write(sockfd,buffer,strlen(buffer));

    n=read(sockfd,buffer,sizeof(buffer)-1);
    buffer[n]='\0';
    printf("%s",buffer);

    sprintf(buffer,"MAIL FROM:<sender@example.com>\r\n");
    write(sockfd,buffer,strlen(buffer));

    n=read(sockfd,buffer,sizeof(buffer)-1);
    buffer[n]='\0';
    printf("%s",buffer);

    sprintf(buffer,"RCPT TO:<receiver@example.com>\r\n");
    write(sockfd,buffer,strlen(buffer));

    n=read(sockfd,buffer,sizeof(buffer)-1);
    buffer[n]='\0';
    printf("%s",buffer);

    sprintf(buffer,"DATA\r\n");
    write(sockfd,buffer,strlen(buffer));

    n=read(sockfd,buffer,sizeof(buffer)-1);
    buffer[n]='\0';
    printf("%s",buffer);

    sprintf(buffer,"From: <sender@example.com>\r\nTo: <receiver@example.com>\r\nSubject: SMTP Client Example\r\n\r\nThis is an example program of SMTP Client built in C.\r\n.\r\n");
    write(sockfd,buffer,strlen(buffer));

    n=read(sockfd,buffer,sizeof(buffer)-1);
    buffer[n]='\0';
    printf("%s",buffer);

    sprintf(buffer,"QUIT\r\n");
    write(sockfd,buffer,strlen(buffer));

    n=read(sockfd,buffer,sizeof(buffer)-1);
    buffer[n]='\0';
    printf("%s",buffer);

    close(sockfd);

    return 0;
}