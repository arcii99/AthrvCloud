//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    // Create socket file descriptor
    int sockfd = 0;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt error");
        return EXIT_FAILURE;
    }

    // Configure server address
    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Bind error");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("Listen error");
        return EXIT_FAILURE;
    }

    int new_socket = 0;
    struct sockaddr_in client_addr = {0};
    int addrlen = sizeof(client_addr);
    char buffer[1024] = {0};

    while (1) {

        // Accept incoming connection
        if ((new_socket = accept(sockfd, (struct sockaddr*) &client_addr, (socklen_t*) &addrlen)) < 0) {
            perror("Accept error");
            return EXIT_FAILURE;
        }

        // Print client address and port
        printf("Connection accepted - %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Read incoming message
        int bytes_read = read(new_socket, buffer, 1024);

        // Print incoming message
        printf("Message received - %s\n", buffer);

        // Send response message
        char response[] = "Hello client, message received!";
        send(new_socket, response, strlen(response), 0);

        // Close client socket
        close(new_socket);

    }

    // Close server socket
    close(sockfd);

    return EXIT_SUCCESS;

}