//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to display error messages
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[4096];
    char *host, *path;

    // Ensure correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(1);
    }

    // Set host and path variables
    host = argv[1];
    path = argv[2];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Set server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 80;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        error("ERROR invalid server address");
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Send HTTP request
    snprintf(buffer, sizeof(buffer), "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read server response
    bzero(buffer, sizeof(buffer));
    while ((n = read(sockfd, buffer, sizeof(buffer)-1)) > 0) {
        printf("%s", buffer);
        bzero(buffer, sizeof(buffer));
    }

    // Check for read error
    if (n < 0) {
        error("ERROR reading from socket");
    }

    // Close socket
    close(sockfd);

    return 0;
}