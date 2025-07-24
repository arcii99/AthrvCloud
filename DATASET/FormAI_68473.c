//FormAI DATASET v1.0 Category: Chat server ; Style: satisfied
/* Welcome to the satisfied style Chat Server example program! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    // Initialize variables
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome = "Welcome to the satisfied style Chat Server!\n";
      
    // Create a socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
      
    // Bind the socket to the given address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Send welcome message to the client
    send(new_socket, welcome, strlen(welcome), 0);
    while (1) {
        valread = read( new_socket , buffer, 1024);
        if(strcmp(buffer, "exit\n") == 0){
            break;
        }
        // Print the received message
        printf("Client: %s", buffer);
        memset(buffer, 0, sizeof(buffer));
        printf("Server: ");
        fgets(buffer, 1024, stdin);
        // Send the message back to the client
        send(new_socket, buffer, strlen(buffer), 0);
    }
    // Close the connection with the client
    close(new_socket);
    return 0;
}