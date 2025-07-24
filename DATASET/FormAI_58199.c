//FormAI DATASET v1.0 Category: Simple Web Server ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 8080
#define MAX_BUFFER_SIZE 1024

void handle_request(int client_sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytes_received = recv(client_sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Failed to receive data from client");
        return;
    }

    printf("Received:\n%s", buffer);

    // Send a response back to the client
    char response[MAX_BUFFER_SIZE];
    sprintf(response, "HTTP/1.1 200 OK\n\n<html><h1>Hello, World!</h1></html>");
    ssize_t bytes_sent = send(client_sockfd, response, strlen(response), 0);
    if (bytes_sent < 0) {
        perror("Failed to send data to client");
        return;
    }

    close(client_sockfd);
}

int main(int argc, char *argv[]) {
    int opt;
    int port = DEFAULT_PORT;

    // Parse command line arguments
    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
            case 'p':
                port = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s [-p port_number]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE); 
    }

    // Bind the socket to a network address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(server_addr.sin_zero), 0, 8);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) < 0) {
        perror("Failed to bind to network address");
        exit(EXIT_FAILURE); 
    }

    // Listen for incoming connections
    if (listen(sockfd, 10) < 0) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE); 
    }

    printf("Server is listening on %s:%d\n", inet_ntoa(server_addr.sin_addr), port);

    while (1) {
        // Accept a client connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(struct sockaddr_in);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);

        if (client_sockfd < 0) {
            perror("Failed to accept client connection");
            continue;
        }

        printf("Accepted a client connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle the client request
        handle_request(client_sockfd);
    }

    close(sockfd);
    return 0;
}