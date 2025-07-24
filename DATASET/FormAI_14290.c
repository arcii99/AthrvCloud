//FormAI DATASET v1.0 Category: Socket programming ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CONNECTIONS 3

int main(int argc, char const *argv[]) 
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
       
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Accept from any IP address
    address.sin_port = htons( PORT );
       
    // Binding socket to address
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }
    // Listen to connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }
    int connections_count = 0;
    while(connections_count < MAX_CONNECTIONS) {
        // Accept the connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                           (socklen_t*)&addrlen)) < 0) {
            perror("Accepting connection failed");
            exit(EXIT_FAILURE);
        }
        connections_count++;
        // Send data to the client
        send(new_socket , hello , strlen(hello) , 0 );
        printf("Hello message sent to client %d\n", connections_count);
        // Receive data from the client
        valread = read( new_socket , buffer, 1024);
        printf("Client %d sent a message: %s\n", connections_count, buffer);
        close(new_socket); // Close the connection
    }
    return 0;
}