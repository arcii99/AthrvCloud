//FormAI DATASET v1.0 Category: Client Server Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

void error(const char *message){
    perror(message);
    exit(1);
}

int main(){
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        error("Socket creation failed");
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt))){
        error("setsockopt failed");
    }

    // Set address values
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        error("Binding failed");
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0){
        error("Listening failed");
    }

    // Wait for and accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0){
        error("Accepting failed");
    }
    
    // Read data from client
    valread = read(new_socket, buffer, MAX_BUFFER_SIZE);
    printf("Client: %s\n", buffer);
    
    // Send response to client
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    return 0;
}