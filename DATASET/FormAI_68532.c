//FormAI DATASET v1.0 Category: Networking ; Style: shocked
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from the other side! :O";

    // Creating TCP Socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket Creation Error");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt Error");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    
    // Bind the socket to a port number
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    }
    
    // Start Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen Error");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection and establish the connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("Accept Error");
        exit(EXIT_FAILURE);
    }
    
    // Read a message from the client
    valread = read(new_socket, buffer, 1024);
    
    // Display the message received from client
    printf("Client Message : %s\n", buffer);
    
    // Send a message to the client
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent to client successfully!\n");
    
    // End the connection
    close(new_socket);
    return 0;
}