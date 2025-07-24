//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int sendMail(const char* address){
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;

    if(sock == -1){
        perror("Socket creation failed");
        return -1;
    }

    server.sin_addr.s_addr = inet_addr(address);
    server.sin_family = AF_INET;
    server.sin_port = htons(25);

    if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0){
        perror("Connection failed");
        return -1;
    }

    char message[1024];
    char response[1024];

    recv(sock, response, 1024, 0);
    printf("%s", response);

    sprintf(message, "HELO %s\r\n", address);
    send(sock, message, strlen(message), 0);

    recv(sock, response, 1024, 0);
    printf("%s", response);

    sprintf(message, "MAIL FROM: <%s>\r\n", address);
    send(sock, message, strlen(message), 0);

    recv(sock, response, 1024, 0);
    printf("%s", response);

    sprintf(message, "RCPT TO: <%s>\r\n", address);
    send(sock, message, strlen(message), 0);

    recv(sock, response, 1024, 0);
    printf("%s", response);

    sprintf(message, "DATA\r\n");
    send(sock, message, strlen(message), 0);

    sprintf(message, "From: <%s>\r\nTo: <%s>\r\nSubject: Test\r\n\r\nHello,\r\nThis is a test email.\r\n\r\n.\r\n", address, address);
    send(sock, message, strlen(message), 0);

    recv(sock, response, 1024, 0);
    printf("%s", response);

    sprintf(message, "QUIT\r\n");
    send(sock, message, strlen(message), 0);

    recv(sock, response, 1024, 0);
    printf("%s", response);

    close(sock);
    return 0;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s [Address]\n", argv[0]);
        return -1;
    }else{
        sendMail(argv[1]);
    }

    return 0;
}