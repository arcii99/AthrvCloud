//FormAI DATASET v1.0 Category: Networking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) 
{ 
    int server_socket, new_socket; 
    struct sockaddr_in serv_addr, client_addr; 
    int opt = 1; 
    int addrlen = sizeof(serv_addr);

    // Create socket file descriptor 
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("Failed to create socket"); 
        exit(EXIT_FAILURE); 
    } 

    // Forcefully attaching socket to the PORT 
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("Failed to set socket options"); 
        exit(EXIT_FAILURE); 
    } 

    // Set server address parameters 
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_addr.s_addr = INADDR_ANY; 
    serv_addr.sin_port = htons(PORT); 

    // Bind the socket to the assigned port 
    if (bind(server_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        perror("Failed to bind socket to the specified port"); 
        exit(EXIT_FAILURE); 
    } 

    // Listen for client connections 
    if (listen(server_socket, 3) < 0) 
    { 
        perror("Failed to start listening for connections"); 
        exit(EXIT_FAILURE); 
    } 

    // Accept incoming client connections 
    if ((new_socket = accept(server_socket, (struct sockaddr *)&serv_addr, (socklen_t*)&addrlen))<0) 
    { 
        perror("Failed to accept incoming connection request"); 
        exit(EXIT_FAILURE); 
    } 

    // Create buffer to receive data from the client 
    char buffer[BUFFER_SIZE] = {0}; 

    int read_size = 0;
    while(1) 
    { 
        read_size = recv(new_socket, buffer, BUFFER_SIZE, 0);
        if(read_size == 0)
        {
            printf("Client disconnected\n");
            break; 
        }
        else if(read_size == -1) 
        {
            perror("Failed to receive data");
            exit(EXIT_FAILURE);     
        }

        printf("Received message from client: %s\n", buffer);

        // Send a response back to the client 
        char *response = "Server received your message"; 
        if(send(new_socket, response, strlen(response), 0) == -1)
        {
            perror("Failed to send response to client"); 
            exit(EXIT_FAILURE); 
        }
    } 

    close(server_socket); 
    return 0; 
}