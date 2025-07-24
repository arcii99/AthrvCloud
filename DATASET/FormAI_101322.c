//FormAI DATASET v1.0 Category: Networking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
    int server_socket, client_socket, addr_size;
    char buffer[1024];
    struct sockaddr_in local_address, remote_address;
    
    // Create socket file descriptor
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0){
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    // Bind socket to IP address and port
    local_address.sin_family = AF_INET;
    local_address.sin_addr.s_addr = INADDR_ANY;
    local_address.sin_port = htons(8080);
    
    if(bind(server_socket, (struct sockaddr *)&local_address, sizeof(local_address)) < 0){
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if(listen(server_socket, 10) < 0){
        perror("Error listening");
        exit(EXIT_FAILURE);
    }
    
    printf("Server running on port 8080...\n");
    
    // Accept incoming connections
    addr_size = sizeof(remote_address);
    client_socket = accept(server_socket, (struct sockaddr *)&remote_address, (socklen_t *)&addr_size);
    if(client_socket < 0){
        perror("Error accepting client");
        exit(EXIT_FAILURE);
    }
    
    printf("Incoming connection accepted...\n");
    
    // Receive data from client and send response
    while(1){
        bzero(buffer, 1024);
        recv(client_socket, buffer, 1024, 0);
        printf("Client: %s\n", buffer);
        send(client_socket, "Server received message", strlen("Server received message"), 0);
    }
    
    // Close sockets and exit
    close(server_socket);
    close(client_socket);
    return 0;
}