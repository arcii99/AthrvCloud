//FormAI DATASET v1.0 Category: Networking ; Style: Alan Touring
// This is a program that creates a client-server chatroom application using sockets in C
// By Alan Turing
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
 
#define PORT 8080
 
int main() {
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(server_addr);
     
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
     
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
     
    // Bind the socket to a specific address and port
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket binding error");
        exit(EXIT_FAILURE);
    }
     
    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("Socket listening error");
        exit(EXIT_FAILURE);
    }
     
    // Accept a new connection from a client
    new_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, (socklen_t*)&addrlen);
    if (new_sockfd < 0) {
        perror("Socket accept error");
        exit(EXIT_FAILURE);
    }
     
    // After accepting the client, create a child process to handle the chat communication
    if (fork() == 0) {
        while (1) {
            char buffer[1024] = {0};
            int read_size = read(new_sockfd, buffer, sizeof(buffer));
             
            if (read_size == 0) {
                printf("Client disconnected\n");
                break;
            }
             
            printf("Client: %s\n", buffer);
             
            char response[1024] = {0};
            printf("Server: ");
            fgets(response, sizeof(response), stdin);
             
            if (strcmp(response, "exit\n") == 0) {
                printf("Closing chatroom...\n");
                break;
            }
             
            write(new_sockfd, response, strlen(response));
        }
         
        close(new_sockfd);
        exit(EXIT_SUCCESS);
    }
 
    close(sockfd);
    return 0;
}