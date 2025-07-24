//FormAI DATASET v1.0 Category: Email Client ; Style: energetic
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define SERVER_PORT 25

void send_mail(int socket) {
    char buffer[1024];
    bzero(buffer, 1024);

    read(socket, buffer, 1024);
    printf("%s\n", buffer);

    memset(buffer, 0, 1024);
    sprintf(buffer, "HELO example.com\r\n");
    send(socket, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    read(socket, buffer, 1024);
    printf("%s\n", buffer);

    memset(buffer, 0, 1024);
    sprintf(buffer, "MAIL FROM: <sender@example.com>\r\n");
    send(socket, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    read(socket, buffer, 1024);
    printf("%s\n", buffer);

    memset(buffer, 0, 1024);
    sprintf(buffer, "RCPT TO: <receiver@example.com>\r\n");
    send(socket, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    read(socket, buffer, 1024);
    printf("%s\n", buffer);

    memset(buffer, 0, 1024);
    sprintf(buffer, "DATA\r\n");
    send(socket, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    read(socket, buffer, 1024);
    printf("%s\n", buffer);

    memset(buffer, 0, 1024);
    sprintf(buffer, "Subject: Sending email using C language\r\n\r\nHello World!\r\n.\r\n");
    send(socket, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    read(socket, buffer, 1024);
    printf("%s\n", buffer);

    memset(buffer, 0, 1024);
    sprintf(buffer, "QUIT\r\n");
    send(socket, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    read(socket, buffer, 1024);
    printf("%s\n", buffer);
}

int main() {
    int socket_desc;
    struct sockaddr_in server;

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    connect(socket_desc, (struct sockaddr *)&server, sizeof(server));
    printf("Connected to email server...\n");

    send_mail(socket_desc);

    close(socket_desc);
    return 0;
}