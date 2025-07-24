//FormAI DATASET v1.0 Category: Networking ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error: Unable to create socket!");
        exit(1);
    }

    // Set up server address and port number
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address and port number
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: Unable to bind the socket to server address and port number!");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Error: Unable to listen for incoming connections!");
        exit(1);
    }

    printf("Server is listening for incoming connections...\n");

    // Accept incoming connections
    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);

    int newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len);

    if (newsockfd < 0) {
        perror("Error: Unable to accept incoming connections!");
        exit(1);
    }

    // Receive data from the client and send back a response
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);

    int n = read(newsockfd, buffer, MAX_BUFFER_SIZE);

    if (n < 0) {
        perror("Error: Unable to read data from the client!");
        exit(1);
    }

    printf("Received message from client: %s\n", buffer);

    char response[] = "Hello, client!";

    n = write(newsockfd, response, strlen(response));

    if (n < 0) {
        perror("Error: Unable to send response to the client!");
        exit(1);
    }

    printf("Sent response to client: %s\n", response);

    // Close the sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}