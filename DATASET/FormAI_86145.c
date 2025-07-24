//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, value_read;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char* message = "Hello from the server!";
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }
    
    // Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("Setting socket options failed!");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Binding socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0) {
        perror("Binding socket failed!");
        exit(EXIT_FAILURE);
    }
    
    // Listening for incoming connection requests
    if (listen(server_fd, 3) < 0) {
        perror("Listening failed!");
        exit(EXIT_FAILURE);
    }
    
    // Accepting incoming connection request
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen))<0) {
        perror("Accepting connection request failed!");
        exit(EXIT_FAILURE);
    }
    
    // Reading message from client
    value_read = read(new_socket, buffer, BUFFER_SIZE);
    printf("Client says: %s\n", buffer);
    
    // Sending message to client
    write(new_socket, message, strlen(message));
    printf("Hello message sent to client!\n");
    
    close(new_socket);
    close(server_fd);
    
    return 0;
}