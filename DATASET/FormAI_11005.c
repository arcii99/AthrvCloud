//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21

int main(int argc, char const *argv[]) {
    int client_socket, valread;
    struct sockaddr_in server_address;
    char buffer[1024] = {0}, user_input[256];

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nSocket creation error\n");
        return -1;
    }

    memset(&server_address, '0', sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        printf("\nInvalid address. Address not supported\n");
        return -1;
    }

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("\nConnection Failed\n");
        return -1;
    }

    char* msg = NULL;
    char* reply_msg = NULL;

    valread = read(client_socket, buffer, 1024);
    printf("%s", buffer);

    while (1) {
        printf("[Enter the command]: ");
        fgets(user_input, 256, stdin);
        user_input[strcspn(user_input, "\n")] = 0;

        if (user_input[0] == 'q' && strlen(user_input) == 1) {
            printf("Closing connection...\n");
            break;
        }

        if (strcmp(user_input, "user") == 0) {
            printf("[username]: ");
            fgets(user_input, 256, stdin);
            user_input[strcspn(user_input, "\n")] = 0;
            msg = calloc(strlen(user_input)+6, sizeof(char));
            strncpy(msg, "USER ", 5);
            strcat(msg, user_input);
            strcat(msg, "\r\n");
        }

        if (strcmp(user_input, "pass") == 0) {
            printf("[password]: ");
            fgets(user_input, 256, stdin);
            user_input[strcspn(user_input, "\n")] = 0;
            msg = calloc(strlen(user_input)+6, sizeof(char));
            strncpy(msg, "PASS ", 5);
            strcat(msg, user_input);
            strcat(msg, "\r\n");
        }

        if (strcmp(user_input, "pwd") == 0) {
            msg = calloc(6, sizeof(char));
            strncpy(msg, "PWD\r\n", 5);
        }

        if (strcmp(user_input, "cwd") == 0) {
            printf("[directory]: ");
            fgets(user_input, 256, stdin);
            user_input[strcspn(user_input, "\n")] = 0;
            msg = calloc(strlen(user_input)+6, sizeof(char));
            strncpy(msg, "CWD ", 4);
            strcat(msg, user_input);
            strcat(msg, "\r\n");
        }

        if (strcmp(user_input, "ls") == 0) {
            msg = calloc(7, sizeof(char));
            strncpy(msg, "LIST\r\n", 6);
        }

        if (msg != NULL) {
            printf("sending message: %s", msg);
            send(client_socket, msg, strlen(msg), 0);
            valread = read(client_socket, buffer, 1024);
            reply_msg = malloc(valread*sizeof(char));
            printf("%s", buffer);
        }

        msg = NULL;
        reply_msg = NULL;

        memset(buffer, 0, sizeof(buffer));
    }
    close(client_socket);
    return 0;
}