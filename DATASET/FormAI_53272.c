//FormAI DATASET v1.0 Category: Chat server ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error occurred while creating socket.\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    int addrlen = sizeof(address);

    memset(&address, '0', sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Error occurred while binding.\n");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 5) < 0) {
        printf("Error occurred while listening.\n");
        exit(EXIT_FAILURE);
    }

    int client_sock = accept(sock, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (client_sock < 0) {
        printf("Error occurred while accepting client connection.\n");
        exit(EXIT_FAILURE);
    }

    char *greet = "Welcome to the chat server!";
    send(client_sock, greet, strlen(greet), 0);

    printf("Connected to client.\n");

    while(1) {

        char message[1024] = {0};
        int valread = read(client_sock, message, 1024);

        if(valread == 0) {
            printf("Client disconnected.\n");
            close(client_sock);
            exit(EXIT_SUCCESS);
        }

        printf("Client: %s\n", message);

        if(strcmp(message, "exit") == 0) {
            printf("Client has closed connection.\n");
            close(client_sock);
            exit(EXIT_SUCCESS);
        }

        char reply[1024];
        printf("Enter your reply: ");
        scanf("%s", reply);

        if(strcmp(reply, "exit") == 0) {
            printf("Closing connection.\n");
            close(client_sock);
            exit(EXIT_SUCCESS);
        }

        send(client_sock, reply, strlen(reply), 0);

    }

    return 0;
}