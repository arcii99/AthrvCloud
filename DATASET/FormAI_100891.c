//FormAI DATASET v1.0 Category: Client Server Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void handle_client(int sockfd) {
    char buffer[1024] = {0};
    int read_val;

    // Keep receiving data from the client until client closes the connection
    while((read_val = read(sockfd, buffer, 1024)) > 0) {
        printf("Received from client: %s", buffer);
        send(sockfd, buffer, strlen(buffer), 0);
        memset(buffer, 0, 1024);
    }

    // If client closes the connection, print message and close socket
    printf("Client disconnected\n");
    close(sockfd);
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;

    // Create a socket for the server
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Could not set socket options\n");
        exit(EXIT_FAILURE);
    }

    // Set server address properties
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if(bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not bind socket\n");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if(listen(server_fd, 3) < 0) {
        perror("Error while listening\n");
        exit(EXIT_FAILURE);
    }

    // Accept client connections and handle requests
    while(1) {
        printf("Waiting for connections...\n");
        int client_len = sizeof(client_addr);
        if((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, (socklen_t*)&client_len)) < 0) {
            perror("Error while accepting connection\n");
            exit(EXIT_FAILURE);
        }
        printf("Connection accepted\n");
        handle_client(client_fd);
    }

    return 0;
}