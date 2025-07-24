//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 255
#define MAX_RESPONSE_LENGTH 1024
#define PORT 21

void print_response(char* response) {
    char* token = strtok(response, "\n");
    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, "\n");
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("Error creating socket");
        exit(1);
    }
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if(connect(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int bytesRead;
    printf("Connected to server. Enter commands: \n");

    while(1) {
        memset(command, 0, MAX_COMMAND_LENGTH);
        memset(response, 0, MAX_RESPONSE_LENGTH);
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        if(strlen(command) > 0 && command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }

        if(strcmp(command, "quit") == 0) {
            printf("Exiting FTP client...\n");
            break;
        }

        if(send(sock, command, strlen(command), 0) < 0) {
            perror("Error sending command to server");
            exit(1);
        }

        bytesRead = recv(sock, response, MAX_RESPONSE_LENGTH, 0);
        if(bytesRead < 0) {
            perror("Error receiving response from server");
            exit(1);
        }
        print_response(response);
    }
    close(sock);
    return 0;
}