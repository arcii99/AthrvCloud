//FormAI DATASET v1.0 Category: Simple Web Server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFSIZE 1024

int main() {
    int sockfd, new_sockfd, client_len, bytes_read;
    char buffer[BUFSIZE];
    struct sockaddr_in server_address, client_address;

    // Create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address settings
    memset((char *)&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to server address
    if (bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);
    printf("Server started on port %d\n", PORT);

    // Accept incoming connections
    while (1) {
        client_len = sizeof(client_address);
        new_sockfd = accept(sockfd, (struct sockaddr *)&client_address, &client_len);
        if (new_sockfd < 0) {
            printf("Error accepting incoming connection\n");
            continue;
        } else {
            printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        }

        // Read incoming data from client
        memset(buffer, 0, BUFSIZE);
        bytes_read = read(new_sockfd, buffer, BUFSIZE);
        if (bytes_read < 0) {
            printf("Error reading data\n");
            close(new_sockfd);
            continue;
        }

        // Print incoming data to console
        printf("Received data:\n%s", buffer);

        // Write response back to client
        char response[BUFSIZE] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello World!</h1></body></html>";
        if (write(new_sockfd, response, strlen(response)) < 0) {
            printf("Error writing data\n");
        }

        // Close connection
        close(new_sockfd);
    }

    // Close socket
    close(sockfd);

    return 0;
}