//FormAI DATASET v1.0 Category: Socket programming ; Style: expert-level
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <arpa/inet.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

#define PORT 8080 
#define SA struct sockaddr 

void error(char *msg) 
{ 
    perror(msg); 
    exit(EXIT_FAILURE); 
} 

int main() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 

    // Create socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        error("Socket creation failed..."); 
    } 
    else {
        printf("Socket successfully created...\n"); 
    }
    bzero(&servaddr, sizeof(servaddr)); 

    // Assign IP and port number
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 

    // Bind the socket
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        error("Socket bind failed..."); 
    } 
    else {
        printf("Socket successfully binded...\n"); 
    }

    // Listen for client connections
    if ((listen(sockfd, 5)) != 0) { 
        error("Socket listen failed..."); 
    } 
    else {
        printf("Listening for client connections...\n"); 
    }

    socklen_t len = sizeof(cli); 

    // Accept client connection
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        error("Client connection acceptance failed..."); 
    } 
    else {
        printf("Client connection accepted...\n"); 
    }

    char buffer[1024]; 
    int n = 0;
    bzero(buffer, sizeof(buffer)); 

    // Recieve data from client
    n = read(connfd, buffer, sizeof(buffer)); 
    if (n < 0) { 
        error("Error reading from socket"); 
    }
    else {
        printf("Message received from client: %s\n", buffer);
    }

    // Send data to client
    char *message = "Message received successfully..."; 
    n = write(connfd, message, strlen(message)); 
    if (n < 0) { 
        error("Error writing to socket"); 
    }
    else {
        printf("Message sent to client...\n"); 
    }

    // Close socket connections
    close(connfd); 
    close(sockfd); 
    return 0;
}