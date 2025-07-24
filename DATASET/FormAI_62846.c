//FormAI DATASET v1.0 Category: Socket programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        perror("Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect the client socket to server socket
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    int n;
    while (1) {
        printf("Enter a message to send to server: ");
        fgets(buffer, MAXLINE, stdin);

        if (strncmp(buffer, "exit", 4) == 0) {
            printf("Exiting...\n");
            break;
        }

        // Send the message to server
        send(sockfd, buffer, strlen(buffer), 0);

        // Receive the response from server
        memset(buffer, 0, MAXLINE);
        n = recv(sockfd, buffer, MAXLINE, 0);
        if (n <= 0) {
            perror("Receive failed");
            break;
        }

        printf("Response from server: %s\n", buffer);
    }

    // Close the socket
    close(sockfd);
    return 0;
}