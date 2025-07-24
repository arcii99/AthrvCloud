//FormAI DATASET v1.0 Category: Client Server Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT_NUM 9090
#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[MAX_BUFFER];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = PORT_NUM;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to bind socket");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("Failed to accept connection");
        exit(1);
    }

    printf("Connected to client\n");

    bzero(buffer, MAX_BUFFER);

    // Prompt user for password
    printf("Please enter password: ");
    fgets(buffer, MAX_BUFFER, stdin);

    // Send password to client
    n = write(newsockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Failed to write to socket");
        exit(1);
    }

    // Wait for response from client
    bzero(buffer, MAX_BUFFER);

    n = read(newsockfd, buffer, MAX_BUFFER);
    if (n < 0) {
        perror("Failed to read from socket");
        exit(1);
    }

    // Check if client's response matches password
    if (strcmp(buffer, "paranoid_password123") == 0) {
        // Authentication successful
        printf("Authentication successful\n");

        // Send secret message to client
        n = write(newsockfd, "The eagle has landed", 20);
        if (n < 0) {
            perror("Failed to write to socket");
            exit(1);
        }
    } else {
        // Authentication failed
        printf("Authentication failed\n");

        // Send error message to client
        n = write(newsockfd, "Sorry, access denied", 20);
        if (n < 0) {
            perror("Failed to write to socket");
            exit(1);
        }
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}