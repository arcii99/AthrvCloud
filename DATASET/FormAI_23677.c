//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 9000

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientLen;
    char buffer[1024];
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    
    // Set options for the socket
    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval , sizeof(int));
    
    // Configure the server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);
    
    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }
    
    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Error listening");
        exit(1);
    }
    
    printf("Server is running and listening on port %d\n", PORT);
    
    while (1) {
        // Accept incoming connections
        clientLen = sizeof(clientAddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&clientAddr, &clientLen);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            exit(1);
        }
        
        printf("Accepted a connection from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
        
        // Receive data from the client
        int len = read(newsockfd, buffer, sizeof(buffer) - 1);
        if (len < 0) {
            perror("Error reading from socket");
            exit(1);
        }
        
        buffer[len] = '\0';
        printf("Received data from the client: %s\n", buffer);
        
        // Send a response back to the client
        char *response = "Hello from the server!";
        len = write(newsockfd, response, strlen(response));
        if (len < 0) {
            perror("Error writing to socket");
            exit(1);
        }
        
        printf("Sent a response back to the client: %s\n", response);
        
        // Close the connection
        close(newsockfd);
    }
    
    // Close the socket
    close(sockfd);
    
    return 0;
}