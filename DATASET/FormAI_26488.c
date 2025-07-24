//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXSIZE 4096

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    char buffer[MAXSIZE], user[MAXSIZE], pass[MAXSIZE];
    memset(buffer, 0, MAXSIZE);
    memset(user, 0, MAXSIZE);
    memset(pass, 0, MAXSIZE);
    strcat(buffer, "USER ");
    printf("Enter your username:");
    scanf("%s", user);
    strcat(buffer, user);
    strcat(buffer, "\r\n");
    printf("Enter your password:");
    scanf("%s", pass);
    strcat(buffer, "PASS ");
    strcat(buffer, pass);
    strcat(buffer, "\r\n");
    server.sin_family = AF_INET;
    server.sin_port = htons(110);
    server.sin_addr.s_addr = inet_addr("pop3.server.com");
    if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0){
        perror("Connection Error");
        exit(1);
    }
    recv(sock, buffer, MAXSIZE, 0);
    printf("%s", buffer);
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, MAXSIZE);
    recv(sock, buffer, MAXSIZE, 0);
    printf("%s", buffer);
    memset(buffer, 0, MAXSIZE);
    send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    recv(sock, buffer, MAXSIZE, 0);
    printf("%s", buffer);
    close(sock);
    return 0;
}