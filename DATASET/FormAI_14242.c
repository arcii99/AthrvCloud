//FormAI DATASET v1.0 Category: Networking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    int socket_fd, n;
    char buffer[BUFFER_SIZE];

    struct sockaddr_in server_address, client_address;

    // creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));

    // set up the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // binding the socket to the given address and port
    if ((bind(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address))) != 0 ) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // listening for connections
    if ((listen(socket_fd, 5)) != 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int client_address_len = sizeof(client_address);

        // accepting incoming connections
        int new_socket_fd = accept(socket_fd, (struct sockaddr*)&client_address, (socklen_t*)&client_address_len);
        
        char* welcome_message = "Welcome to my server!\n";
        send(new_socket_fd, welcome_message, strlen(welcome_message), 0);

        while (1) {

            // receiving data from the client
            memset(buffer, 0, BUFFER_SIZE);

            n = recv(new_socket_fd, buffer, BUFFER_SIZE, 0);

            if(n <= 0) {
                perror("Error reading from socket");
                break;
            }

            printf("Received message: %s", buffer);

            char* response = "Server says Hi!\n";

            // sending response to the client
            send(new_socket_fd, response, strlen(response), 0);
        }

        close(new_socket_fd);
    }

    close(socket_fd);

    return 0;
}