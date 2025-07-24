//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

#define PORT_NUMBER 8080
#define BUFFER_SIZE 256

void error_handler(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    int server_fd, client_fd, val_read;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};

    // Create a socket
    if( (server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0 ) {
        error_handler("Could not create socket");
    }

    // Prepare the server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT_NUMBER);

    // Bind the socket to the IP address and port number
    if( bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0 ) {
        error_handler("Bind failed");
    }

    // Listen for incoming connections
    if( listen(server_fd, 3) < 0 ) {
        error_handler("Listen failed");
    }

    // Accept the incoming connection
    int client_address_size = sizeof(client_address);
    if( (client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&client_address_size)) < 0 ) {
        error_handler("Accept failed");
    }

    // Read data from the client
    if( (val_read = read(client_fd, buffer, BUFFER_SIZE)) < 0 ) {
        error_handler("Read failed");
    }

    printf("Received data from client: %s\n", buffer);

    // Send data to the client
    char *message = "Hello, Client! This is the server.";
    if( send(client_fd, message, strlen(message), 0) < 0 ) {
        error_handler("Send failed");
    }

    printf("Response sent to client.\n");

    // Close the sockets
    close(client_fd);
    close(server_fd);

    return 0;
}