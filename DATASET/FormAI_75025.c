//FormAI DATASET v1.0 Category: Simple Web Server ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(){
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char response[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Peaceful C Simple Web Server</h1></body></html>";

    // Create a socket
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address
    if(bind(server_fd, (struct sockaddr *)&address, addrlen) < 0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(server_fd, 5) < 0){
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d\n", PORT);

    while(1){
        // Accept incoming connection
        if((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0){
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Read client request
        read(new_socket, buffer, BUFFER_SIZE);

        // Send response
        send(new_socket, response, strlen(response), 0);

        // Close socket
        close(new_socket);
    }

    return 0;
}