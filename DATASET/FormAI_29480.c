//FormAI DATASET v1.0 Category: Socket programming ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8888

int main(int argc, char *argv[]) {
    int socketfd, new_socket, valread;
    struct sockaddr_in server_address;
    char *response = "Hello from server";

    // Create socket
    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket
    if (bind(socketfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(socketfd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port %d\n", PORT);

    // Accept incoming connections
    int addr_len = sizeof(server_address);
    if ((new_socket = accept(socketfd, (struct sockaddr *) &server_address, (socklen_t *) &addr_len)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    printf("New connection accepted\n");

    // Send response to client
    send(new_socket, response, strlen(response), 0);
    printf("Response sent\n");

    return 0;
}