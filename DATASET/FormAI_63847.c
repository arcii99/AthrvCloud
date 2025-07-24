//FormAI DATASET v1.0 Category: Simple Web Server ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sockfd, newsockfd, opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to port
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("Socket listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    if ((newsockfd = accept(sockfd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Socket accept failed");
        exit(EXIT_FAILURE);
    }

    // Receive request
    if (read(newsockfd, buffer, 1024) < 0) {
        perror("Socket receive failed");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    // Send response
    if (send(newsockfd, response, strlen(response), 0) < 0) {
        perror("Socket send failed");
        exit(EXIT_FAILURE);
    }

    printf("Response sent");

    close(newsockfd);
    close(sockfd);
    return 0;
}