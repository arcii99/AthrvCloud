//FormAI DATASET v1.0 Category: Networking ; Style: enthusiastic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

#define PORT 8080

int main() {

    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    // Create a socket file descriptor using SOCK_STREAM for TCP
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating the socket...\n");
        exit(0);
    }
    else {
        printf("Socket successfully created..\n");
    }

    // Initialize the socket with the server address and port number
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost
    servaddr.sin_port = htons(PORT);

    // Connect to the server using the socket
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Failed to connect with the server...\n");
        exit(0);
    }
    else {
        printf("Connected to the server successfully..\n");
    }

    // Send a message to the server
    char msg[100];
    printf("Enter a message to send to the server: ");
    fgets(msg, 100, stdin);
    write(sockfd, msg, sizeof(msg));

    // Read the server's response
    char buffer[100];
    read(sockfd, buffer, sizeof(buffer));
    printf("Server responded with: %s", buffer);

    // Close the socket
    close(sockfd);
    return 0;
}