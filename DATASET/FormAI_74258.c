//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 25     //SMTP port number
#define MAX_BUF 1024    //max buffer size

int main(int argc, char *argv[]) {
    int clientSock;
    struct sockaddr_in serverAddr;
    char buffer[MAX_BUF];

    if(argc < 2) {
        printf("Usage: %s <Server IP>\n", argv[0]);
        exit(1);
    }

    if((clientSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
    serverAddr.sin_port = htons(PORT);

    if(connect(clientSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    printf("Connected to server\n");

    memset(buffer, 0, MAX_BUF);
    recv(clientSock, buffer, MAX_BUF, 0);
    printf("%s", buffer);    //server greeting

    //HELO command
    memset(buffer, 0, MAX_BUF);
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    if(send(clientSock, buffer, strlen(buffer), 0) < 0) {
        perror("HELO command send failed");
        exit(1);
    }

    printf("HELO command sent\n");

    //response to HELO command
    memset(buffer, 0, MAX_BUF);
    recv(clientSock, buffer, MAX_BUF, 0);
    printf("%s", buffer);

    //MAIL FROM command
    memset(buffer, 0, MAX_BUF);
    sprintf(buffer, "MAIL FROM:<user1@mydomain.com>\r\n");
    if(send(clientSock, buffer, strlen(buffer), 0) < 0) {
        perror("MAIL FROM command send failed");
        exit(1);
    }

    printf("MAIL FROM command sent\n");

    //response to MAIL FROM command
    memset(buffer, 0, MAX_BUF);
    recv(clientSock, buffer, MAX_BUF, 0);
    printf("%s", buffer);

    //RCPT TO command
    memset(buffer, 0, MAX_BUF);
    sprintf(buffer, "RCPT TO:<user2@mydomain.com>\r\n");
    if(send(clientSock, buffer, strlen(buffer), 0) < 0) {
        perror("RCPT TO command send failed");
        exit(1);
    }

    printf("RCPT TO command sent\n");

    //response to RCPT TO command
    memset(buffer, 0, MAX_BUF);
    recv(clientSock, buffer, MAX_BUF, 0);
    printf("%s", buffer);

    //DATA command
    memset(buffer, 0, MAX_BUF);
    sprintf(buffer, "DATA\r\n");
    if(send(clientSock, buffer, strlen(buffer), 0) < 0) {
        perror("DATA command send failed");
        exit(1);
    }

    printf("DATA command sent\n");

    //response to DATA command
    memset(buffer, 0, MAX_BUF);
    recv(clientSock, buffer, MAX_BUF, 0);
    printf("%s", buffer);

    //Message body
    memset(buffer, 0, MAX_BUF);
    sprintf(buffer, "From: user1@mydomain.com\r\nTo: user2@mydomain.com\r\nSubject: SMTP client example\r\n\r\nThis is a test message\r\n.\r\n");
    if(send(clientSock, buffer, strlen(buffer), 0) < 0) {
        perror("Message body send failed");
        exit(1);
    }

    printf("Message sent\n");

    //response to message body
    memset(buffer, 0, MAX_BUF);
    recv(clientSock, buffer, MAX_BUF, 0);
    printf("%s", buffer);

    //QUIT command
    memset(buffer, 0, MAX_BUF);
    sprintf(buffer, "QUIT\r\n");
    if(send(clientSock, buffer, strlen(buffer), 0) < 0) {
        perror("QUIT command send failed");
        exit(1);
    }

    printf("QUIT command sent\n");

    //response to QUIT command
    memset(buffer, 0, MAX_BUF);
    recv(clientSock, buffer, MAX_BUF, 0);
    printf("%s", buffer);

    close(clientSock);
    return 0;
}