//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024
#define METHOD "GET"
#define PATH "/"

int main(int argc, char *argv[]) {

    // Check for valid arguments
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address and port number
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // http port
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Prepare HTTP request
    char buf[BUFSIZE];
    snprintf(buf, BUFSIZE, "%s %s HTTP/1.1\r\nHost: %s\r\n\r\n", METHOD, PATH, argv[1]);

    // Send HTTP request
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("Error sending HTTP request");
        exit(EXIT_FAILURE);
    }

    // Receive HTTP response
    char response[BUFSIZE];
    memset(response, 0, BUFSIZE);
    if (recv(sockfd, response, BUFSIZE, 0) < 0) {
        perror("Error receiving HTTP response");
        exit(EXIT_FAILURE);
    }

    // Print HTTP response
    printf("%s", response);

    // Close socket
    close(sockfd);

    return 0;
}