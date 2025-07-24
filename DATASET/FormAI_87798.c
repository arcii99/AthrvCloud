//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char **argv)
{
    int sockfd = 0;
    struct sockaddr_in serv_addr;
    char input[1024];
    char recvBuff[1024];
    memset(recvBuff, '0',sizeof(recvBuff));
    if(argc != 2)
    {
        printf("\n Usage: %s <ip of server> \n",argv[0]);
        return 1;
    }
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return 1;
    }
    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\n Error : Connect Failed \n");
        return 1;
    }
    printf("Connected to server\n");
    printf("Enter HTTP request (Example: GET / HTTP/1.0): ");
    fgets(input, sizeof(input), stdin);
    if(send(sockfd, input, strlen(input), 0) < 0)
    {
        printf("\n Error : Send Failed \n");
        return 1;
    }
    printf("HTTP request sent\n");
    int n;
    while((n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
        recvBuff[n] = 0;
        printf("%s",recvBuff);
    }
    if(n < 0)
    {
        printf("\n Read error \n");
    }
    return 0;
}