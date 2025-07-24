//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: energetic
/* Welcome to my TCP/IP Programming example! */

#include <stdio.h> // This is the standard input/output library
#include <stdlib.h> // This is the standard library
#include <netinet/in.h> // This is the Internet address family library
#include <string.h> // This is the string library
#include <sys/socket.h> // This is the socket library
#include <arpa/inet.h> // This is the Internet operations library

int main () {
    printf("Welcome to my TCP/IP Programming example!\n");

    // First, we need to create a socket using the socket() function
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in server_address;
    memset(&server_address, '\0', sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080); // We will be using port 8080

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Start listening for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("ERROR on listening");
        exit(1);
    }

    // Accept a connection
    printf("Waiting for a client to connect...\n");

    struct sockaddr_in client_address;
    socklen_t client_length = sizeof(client_address);

    int newsockfd = accept(sockfd, (struct sockaddr *) &client_address, &client_length);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    printf("Client connected!\n");

    // Send a message to the client
    char buffer[256];
    memset(buffer, '\0', sizeof(buffer));

    sprintf(buffer, "Welcome to my TCP/IP Programming example!");

    if (write(newsockfd, buffer, sizeof(buffer)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    close(newsockfd);
    close(sockfd);

    printf("Goodbye!\n");
    
    return 0;
}