//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024
#define SERVER_PORT 21

int main(int argc , char *argv[])
{
    char username[MAX_SIZE], password[MAX_SIZE], cmd[MAX_SIZE], buffer[MAX_SIZE];
    struct sockaddr_in server;
    int sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }
    printf("FTP Client online\n");

    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }
    printf("Connection established...\n");

    bzero(buffer, MAX_SIZE);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    printf("Username: ");
    fgets(username, MAX_SIZE, stdin);
    sprintf(cmd, "USER %s", strtok(username, "\n"));
    send(sock, cmd, strlen(cmd), 0);

    bzero(buffer, MAX_SIZE);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    printf("Password: ");
    fgets(password, MAX_SIZE, stdin);
    sprintf(cmd, "PASS %s", strtok(password, "\n"));
    send(sock, cmd, strlen(cmd), 0);

    bzero(buffer, MAX_SIZE);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    printf("Logged in...\n");

    while (1) {
        printf("$ ");
        fgets(cmd, MAX_SIZE, stdin);
        cmd[strcspn(cmd, "\n")] = '\0';
        send(sock, cmd, strlen(cmd), 0);

        bzero(buffer, MAX_SIZE);
        recv(sock, buffer, sizeof(buffer), 0);
        printf("%s", buffer);

        if (strcmp(cmd, "QUIT") == 0) {
            close(sock);
            break;
        }
    }

    return 0;
}