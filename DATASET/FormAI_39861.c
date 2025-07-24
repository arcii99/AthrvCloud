//FormAI DATASET v1.0 Category: Networking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sockfd, new_socket;
    struct sockaddr_in servaddr, clientaddr;
    socklen_t len;
    char buffer[1024];
    char *message = "Welcome to my server!";

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Bind the socket to port
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    if ((bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr))) != 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for incoming connections
    if ((listen(sockfd, 5)) != 0) {
        printf("Error listening for incoming connections\n");
        exit(1);
    }

    printf("Server is running at port %d\n", PORT);

    while (1) {
        len = sizeof(clientaddr);
        new_socket = accept(sockfd, (struct sockaddr *) &clientaddr, &len);
        if (new_socket < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        // Send welcome message to client
        write(new_socket, message, strlen(message));

        // Receive data from client
        read(new_socket, buffer, sizeof(buffer));

        printf("Received message from client: %s\n", buffer);

        // Send response to client
        write(new_socket, "Message received", sizeof("Message received"));

        close(new_socket);
    }

    close(sockfd);
    return 0;
}