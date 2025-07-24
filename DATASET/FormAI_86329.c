//FormAI DATASET v1.0 Category: Client Server Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

// function to handle client requests
void handle_client_request(int client_socket) {
    char buffer[MAX_BUFFER_SIZE];
    int read_len;

    while ((read_len = read(client_socket, buffer, MAX_BUFFER_SIZE)) > 0) {
        buffer[read_len] = '\0';

        // print the client request
        printf("Client Request: %s\n", buffer);

        // send a response message to the client
        char response[MAX_BUFFER_SIZE] = "Message received successfully.\n";
        write(client_socket, response, strlen(response));
    }

    // close the client socket
    close(client_socket);
}

int main(int argc, char const *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int addrlen = sizeof(server_address);

    // create a TCP socket for the server
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create server socket.");
        exit(1);
    }

    // set server parameters
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // bind the server socket to the given IP address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind server socket.");
        exit(1);
    }

    // start listening for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Failed to listen for incoming connections.");
        exit(1);
    }

    printf("Server is listening on port %d...\n", PORT);

    // handle incoming connections
    while (1) {
        // accept a new connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&addrlen)) < 0) {
            perror("Failed to accept connection.");
            exit(1);
        }

        // print client IP address and port number
        printf("New client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // create a new thread to handle client requests
        pid_t pid;
        if ((pid = fork()) == 0) {
            // child process
            close(server_socket);
            handle_client_request(client_socket);
            exit(0);
        } else {
            // parent process
            close(client_socket);
        }
    }

    // close the server socket
    close(server_socket);

    return 0;
}