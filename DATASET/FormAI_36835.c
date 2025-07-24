//FormAI DATASET v1.0 Category: Client Server Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define MAX_LINE_SIZE 1024

int main(int argc, char const *argv[]) {

    struct sockaddr_in address;
    int socket_fd, new_socket, read_size; 
    char buffer[MAX_LINE_SIZE] = {0}; 
    const char *message = "Server is up and running.\n";

    // Open a socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    // Wait for a client to connect
    if (listen(socket_fd, 3) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }
    printf("Server is listening on port %d...\n", PORT);

    while(1) {

        // Accept client connection
        if ((new_socket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&address)) < 0) {
            perror("Accept error");
            exit(EXIT_FAILURE);
        }

        // Send a welcome message to client
        send(new_socket, message, strlen(message), 0);

        // Receive incoming messages from client
        while ((read_size = recv(new_socket, buffer, MAX_LINE_SIZE, 0)) > 0) {
            // Send message back to client
            send(new_socket , buffer , strlen(buffer) , 0 );
            memset(buffer, 0, MAX_LINE_SIZE);
        }

        if (read_size == 0) {
            puts("Client disconnected");
            fflush(stdout);
        }
        else if(read_size == -1) {
            perror("Receive error");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}