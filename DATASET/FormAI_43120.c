//FormAI DATASET v1.0 Category: Client Server Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sockfd, new_sockfd, backlog_limit = 5, num_bytes_rcvd, num_bytes_sent;
    socklen_t client_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[256];

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: creating socket");
        return EXIT_FAILURE;
    }

    // Setting up server information
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding socket to port
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error: binding socket to port");
        return EXIT_FAILURE;
    }

    // Listening for connections
    listen(sockfd, backlog_limit);
    printf("Server is now listening on port %d...\n", PORT);

    // Accepting client connections
    client_len = sizeof(client_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
    if (new_sockfd < 0) {
        perror("Error: accepting client connection");
        return EXIT_FAILURE;
    }
    printf("Connection established with client %s:%d\n", 
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Receiving data from client
    bzero(buffer, sizeof(buffer));
    num_bytes_rcvd = recv(new_sockfd, buffer, sizeof(buffer)-1, 0);
    if (num_bytes_rcvd < 0) {
        perror("Error: receiving data from client");
        return EXIT_FAILURE;
    }
    printf("Received data from client: %s", buffer);

    // Sending data back to client
    num_bytes_sent = send(new_sockfd, "Message received!\n", 18, 0);
    if (num_bytes_sent < 0) {
        perror("Error: sending data to client");
        return EXIT_FAILURE;
    }
    printf("Sent data back to client.\n");

    // Closing connections
    close(new_sockfd);
    close(sockfd);
    return EXIT_SUCCESS;
}