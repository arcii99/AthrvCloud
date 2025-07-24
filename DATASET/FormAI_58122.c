//FormAI DATASET v1.0 Category: Networking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    printf("Welcome to my chatbot's networking demo program!\n");
    printf("In this program, you will learn how to send and receive data over a network using C.\n");
    printf("Let's get started!\n\n");

    // create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // configure the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, 3) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // accept an incoming connection
    int client_fd = accept(server_fd, NULL, NULL);
    if (client_fd == -1) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Server accepted a new connection from the client.\n");

    // send a message to the client
    char *message = "Hello, client!";
    if (send(client_fd, message, strlen(message), 0) == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
    printf("Server sent the message \"%s\" to the client.\n", message);

    // receive a message from the client
    char buffer[1024] = {0};
    int bytes_received = recv(client_fd, buffer, 1024, 0);
    if (bytes_received == -1) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Server received the message \"%s\" from the client.\n", buffer);

    printf("Networking demo program has completed successfully.\n");

    // cleanup
    close(client_fd);
    close(server_fd);
    return 0;
}