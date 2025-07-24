//FormAI DATASET v1.0 Category: Client Server Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_sockfd, client_sockfd, valread;
    struct sockaddr_in server_address, client_address;
    char buffer[1024] = {0};
    int opt = 1;
    int addrlen = sizeof(server_address);

    // Create server socket file descriptor
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server socket options
    if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set server address properties
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server socket to specified address and port
    if (bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_sockfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    if ((client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Send welcome message to client
    char *welcome_message = "Welcome to my server!\n";
    send(client_sockfd, welcome_message, strlen(welcome_message), 0);

    // Receive message from client and print to console
    valread = read(client_sockfd, buffer, 1024);
    printf("%s\n", buffer);

    // Send response message to client
    char *response_message = "Thank you for your message!";
    send(client_sockfd, response_message, strlen(response_message), 0);

    return 0;
}