//FormAI DATASET v1.0 Category: Simple Web Server ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8888
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create server socket
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error in socket creation");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error in setting socket options");
        exit(EXIT_FAILURE);
    }

    // Set server address properties
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind server socket to address
    if(bind(server_socket, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Error in binding server socket");
        exit(EXIT_FAILURE);
    }

    // Start listening for client connections
    if(listen(server_socket, 5) < 0) {
        perror("Error in listening for clients");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    // Accept incoming client connection
    if((new_socket = accept(server_socket, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Error in accepting client connection");
        exit(EXIT_FAILURE);
    }

    printf("New client connection accepted from: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    // Loop to receive and send messages to client
    while(1) {
        memset(buffer, 0, sizeof(buffer));
        // Read client message
        if((valread = read(new_socket, buffer, BUFFER_SIZE)) == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Received message from client: %s\n", buffer);

        // Send response to client
        char* response = "Hello from server!";
        if(send(new_socket, response, strlen(response), 0) != strlen(response)) {
            perror("Error in sending response");
            exit(EXIT_FAILURE);
        }
    }

    // Close server and client sockets
    close(server_socket);
    close(new_socket);
    return 0;
}