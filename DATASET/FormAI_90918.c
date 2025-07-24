//FormAI DATASET v1.0 Category: Socket programming ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_fd, new_socket, val_read;
    struct sockaddr_in server_address;
    char *hello = "Hello from server";
    char buffer[1024] = {0};
    
    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Setting server address information
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // Binding the socket to the address
    if ((bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address))) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listening for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    // Accepting incoming connection and creating a new socket for communication
    if ((new_socket = accept(socket_fd, (struct sockaddr *)&server_address, (socklen_t*)&server_address)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    
    // Receiving message from client
    val_read = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);
    
    // Sending message to client
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    
    // Closing the sockets
    close(new_socket);
    close(socket_fd);
    
    return 0;
}