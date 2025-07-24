//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_COMMAND_SIZE 100
#define MAX_MESSAGE_SIZE 2048
#define SERVER_ADDRESS "localhost"
#define SERVER_PORT 21

char buffer[MAX_MESSAGE_SIZE];
char response[MAX_MESSAGE_SIZE];

void readResponse(int sock) {
    memset(response, 0, sizeof(response));
    recv(sock, response, MAX_MESSAGE_SIZE, 0);
    printf("%s", response);
}

void sendCommand(int sock, char* command) {
    sprintf(buffer, "%s\r\n", command);
    send(sock, buffer, strlen(buffer), 0);
}

int main() {
    struct sockaddr_in server;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        return -1;
    }

    server.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    if (connect(sock, (struct sockaddr*) &server, sizeof(server)) < 0) {
        perror("Failed to connect");
        return -1;
    }

    readResponse(sock); // Welcome message
    sendCommand(sock, "USER anonymous");
    readResponse(sock); // Ask for password
    sendCommand(sock, "PASS ");
    readResponse(sock); // Login successful

    while (1) {
        printf("ftp> ");
        fgets(buffer, MAX_COMMAND_SIZE, stdin);
        if (strlen(buffer) <= 1) {
            continue;
        }
        if (strcmp(buffer, "quit\n") == 0) {
            sendCommand(sock, "QUIT");
            readResponse(sock);
            break;
        }
        sendCommand(sock, buffer);
        readResponse(sock);
    }

    close(sock);
    return 0;
}