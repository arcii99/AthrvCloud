//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21 //FTP port

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    char msg[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(sockfd < 0)
    {
        perror("socket() error");
        exit(-1);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect() error");
        exit(-1);
    }

    // Log in to FTP server
    strcpy(msg, "USER username\r\n");
    send(sockfd, msg, strlen(msg), 0);
    recv(sockfd, msg, sizeof(msg), 0);

    strcpy(msg, "PASS password\r\n");
    send(sockfd, msg, strlen(msg), 0);
    recv(sockfd, msg, sizeof(msg), 0);

    // Change directory on FTP server
    strcpy(msg, "CWD /example/directory\r\n");
    send(sockfd, msg, strlen(msg), 0);
    recv(sockfd, msg, sizeof(msg), 0);

    // Download file from FTP server
    strcpy(msg, "RETR file.txt\r\n");
    send(sockfd, msg, strlen(msg), 0);
    recv(sockfd, msg, sizeof(msg), 0);

    // Create and write to local file
    FILE* fp = fopen("file.txt", "w");

    if(fp == NULL)
    {
        perror("fopen() error");
        exit(-1);
    }

    fwrite(msg, sizeof(char), strlen(msg), fp);
    fclose(fp);

    // Logout
    strcpy(msg, "QUIT\r\n");
    send(sockfd, msg, strlen(msg), 0);
    recv(sockfd, msg, sizeof(msg), 0);
    close(sockfd);

    return 0;
}