//FormAI DATASET v1.0 Category: Socket programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MESSAGE_SIZE 1024

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(){

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_MESSAGE_SIZE] = {0};
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        error("Socket creation failed");
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        error("setsockopt failed");
    }
    
    // Set address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind socket with address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        error("bind failed");
    }
    
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        error("listen failed");
    }
    
    printf("Waiting for client connection...\n");
    
    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
    {
        error("accept failed");
    }

    printf("Client connected!\n");
    
    // Main loop to communicate with client
    while(1){
        
        // Clear the buffer
        memset(buffer, 0, MAX_MESSAGE_SIZE);
        
        // Read message from client
        valread = read(new_socket, buffer, MAX_MESSAGE_SIZE);
        
        // Check if client has disconnected
        if(valread == 0){
            printf("Client has disconnected...\n");
            break;
        }
        
        // Print the message received from client
        printf("Received message: %s\n", buffer);
        
        // Cyberpunk style reply
        char* reply = "I am the ghost in the machine, speaking to you in code... 01010111 01100101 00100000 01101110 01100101 01100101 01100100 00100000 01111001 01101111 01110101 00101100 00100000 01100111 01110010 01100001 01110011 01110011 01101000 01101111 01110000 01110000 01100101 01110010... End message.";
        
        // Send reply to client
        send(new_socket, reply, strlen(reply), 0);
    }
    
    close(new_socket);
    close(server_fd);
        
    return 0;
}