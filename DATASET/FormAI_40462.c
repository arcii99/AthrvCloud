//FormAI DATASET v1.0 Category: Client Server Application ; Style: rigorous
// This is a C Client-Server Application example program
// It demonstrates a simple messaging system between a client and a server
// The client sends a message to the server, which sends it back with "Server:" added to the beginning
// The server then sends the modified message back to the client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MESSAGE_SIZE 1024
#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_desc, client_sock, valread;
    struct sockaddr_in server_addr, client_addr;
    char message[MESSAGE_SIZE] = {0};

    // Create socket
    if ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Specify server address settings
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(socket_desc, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Wait for and accept incoming connection
    socklen_t client_addr_len = sizeof(client_addr);
    if ((client_sock = accept(socket_desc, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Receive message from client
    valread = read(client_sock, message, MESSAGE_SIZE);
    if (valread < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Add "Server:" to beginning of message
    char modified_message[MESSAGE_SIZE] = {0};
    strcat(modified_message, "Server: ");
    strcat(modified_message, message);

    // Send modified message back to client
    if (send(client_sock, modified_message, strlen(modified_message), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    return 0;
}