//FormAI DATASET v1.0 Category: Networking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    
    int sockfd, newsockfd, clilen, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Clear serv_addr
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // Configure serv_addr with host IP and port number
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket to the serv_addr
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    printf("Listening on port %d...\n", PORT);

    // Accept incoming connections
    newsockfd = accept(sockfd,
                       (struct sockaddr *) &cli_addr,
                       &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    printf("Connected to client!\n");

    // Read data from client
    bzero(buffer, BUFFER_SIZE);
    n = read(newsockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Client: %s\n", buffer);

    // Write data back to client
    n = write(newsockfd, "Server received your message", 28);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    printf("Message sent to client!\n");

    // Close the sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}