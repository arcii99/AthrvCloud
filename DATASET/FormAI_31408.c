//FormAI DATASET v1.0 Category: Simple Web Server ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 2048
#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[BUFFER_SIZE] = {0}; 

    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Forcefully attaching socket to the given port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 

    // Binding socket to the given port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Listening on socket
    if (listen(server_fd, 3) < 0) { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 

    while(1) {
        printf("Waiting for a connection...\n");

        // Accepting incoming client connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) { 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        } 

        printf("Client connected.\n");

        // Reading client request from socket
        int bytesReceived = recv(new_socket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        // Printing client request
        printf("Client Request:\n%s", buffer); 

        // Preparing server response
        char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";

        // Sending server response to client
        send(new_socket, response, strlen(response), 0); 

        printf("Response sent.\n");

        close(new_socket);
        printf("Connection closed.\n");
    }

    return 0; 
}