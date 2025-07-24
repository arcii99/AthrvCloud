//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_COMMAND_SIZE 512

int connectToServer(char* serverAddress, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;

    server.sin_addr.s_addr = inet_addr(serverAddress);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Unable to connect to server");
        exit(1);
    }

    return sock;
}

int readResponse(int socket, char* response) {
    int responseLength = 0;
    char buffer[MAX_BUFFER_SIZE] = {0};

    while (1) {
        int readBytes = recv(socket, buffer, sizeof(buffer), 0);

        if (readBytes <= 0) {
            break;
        }

        memcpy(response + responseLength, buffer, readBytes);
        responseLength += readBytes;

        if (responseLength >= MAX_BUFFER_SIZE) {
            break;
        }

        if (response[responseLength - 1] == '\n') {
            break;
        }
    }

    return responseLength;
}

void sendCommand(int socket, const char* command) {
    int commandLength = strlen(command);
    send(socket, command, commandLength, 0);
}

int main() {
    char serverAddress[] = "mail.example.com";
    int port = 143;
    int sock = connectToServer(serverAddress, port);

    char response[MAX_BUFFER_SIZE] = "";
    readResponse(sock, response);

    printf("%s", response);

    sendCommand(sock, "A001 LOGIN username password\n");
    readResponse(sock, response);
    printf("%s", response);

    sendCommand(sock, "A002 SELECT INBOX\n");
    readResponse(sock, response);
    printf("%s", response);

    sendCommand(sock, "A003 FETCH 1 BODY[HEADER]\n");
    readResponse(sock, response);
    printf("%s", response);

    sendCommand(sock, "A004 LOGOUT\n");
    readResponse(sock, response);
    printf("%s", response);

    close(sock);

    return 0;
}