//FormAI DATASET v1.0 Category: Client Server Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8888    // Port number to use for the server
#define MAXMSGLEN 1024  // Maximum message length

int main() {
    int sockfd, newsockfd, n;
    char buffer[MAXMSGLEN];
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    // Create a socket for the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Initialize server address values
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    printf("Server is listening...\n");

    while (1) {
        clilen = sizeof(cli_addr);

        // Accept a new connection
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("New client connected\n");

        // Read incoming messages from the client
        bzero(buffer, MAXMSGLEN);
        n = read(newsockfd, buffer, MAXMSGLEN - 1);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Received message: %s\n", buffer);

        // Create a response message
        char response[MAXMSGLEN];
        sprintf(response, "Greetings noble stranger! You said: %s", buffer);

        // Send the response message back to the client
        n = write(newsockfd, response, strlen(response));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        printf("Response message sent\n");

        // Close the socket for this client
        close(newsockfd);
        printf("Client disconnected\n");
    }

    return 0;
}