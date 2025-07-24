//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8000

// Function to handle client connections
void handle_client(int sockfd) {
    char buffer[256];
    int n;
    
    // Loop to receive messages from client
    while (1) {
        bzero(buffer, 256);
        n = read(sockfd, buffer, 255);
        if (n < 0) {
            perror("Error reading from socket");
            exit(EXIT_FAILURE);
        }
        printf("Message from client: %s", buffer);
        
        // Send response to client
        n = write(sockfd, "Server received message", 23);
        if (n < 0) {
            perror("Error writing to socket");
            exit(EXIT_FAILURE);
        }
    }
}

int main() {
    int sockfd, newsockfd, client_len;
    struct sockaddr_in serv_addr, client_addr;
    
    // Create socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }
    
    // Configure server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    
    // Bind socket to server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    listen(sockfd, 5);
    
    // Loop to accept incoming connections
    while (1) {
        client_len = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }
        
        // Handle client connection in a child process
        pid_t pid = fork();
        if (pid < 0) {
            perror("Error creating child process");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            close(sockfd);
            handle_client(newsockfd);
            exit(EXIT_SUCCESS);
        } else {
            close(newsockfd);
        }
    }
    
    // Close socket file descriptor
    close(sockfd);
    
    return EXIT_SUCCESS;
}