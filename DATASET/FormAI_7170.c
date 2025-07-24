//FormAI DATASET v1.0 Category: Networking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    int bytes_sent, bytes_received, optval, client_addr_length;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        return 1;
    }

    // Set socket options
    optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    // Listen for connections
    listen(sockfd, 5);
    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connections
        client_addr_length = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_length);
        if (newsockfd < 0) {
            printf("Error accepting connection\n");
            continue;
        }

        // Receive message from client
        memset(buffer, '\0', sizeof(buffer));
        bytes_received = recv(newsockfd, buffer, sizeof(buffer), 0);
        if (bytes_received < 0) {
            printf("Error receiving message\n");
            close(newsockfd);
            continue;
        }

        printf("Received message from client: %s\n", buffer);

        // Send message to client
        char response[] = "Hi there, client! I'm your cheerful server! :)";
        bytes_sent = send(newsockfd, response, sizeof(response), 0);
        if (bytes_sent < 0) {
            printf("Error sending message\n");
            close(newsockfd);
            continue;
        }

        printf("Sent message to client: %s\n", response);

        // Close connection
        close(newsockfd);
    }

    // Close socket
    close(sockfd);

    return 0;
}