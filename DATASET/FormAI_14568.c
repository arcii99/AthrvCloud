//FormAI DATASET v1.0 Category: Client Server Application ; Style: future-proof
/* This is a C client-server application example program.
 * The client sends a message to the server and the
 * server responds with a response message.
 * This program uses future-proof style.
 * Version: 1.0
 * Author: John Doe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFF_SIZE 1024

int main() {
    int sockfd, new_sockfd, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addrlen = sizeof(client_addr);
    char buffer[BUFF_SIZE] = {0};
    char resp_buffer[BUFF_SIZE] = {0};

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to server address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    // Accept incoming connections
    if ((new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("New client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Receive message from client
    if (recv(new_sockfd, buffer, BUFF_SIZE, 0) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", buffer);

    // Create response message
    snprintf(resp_buffer, BUFF_SIZE, "Hello from server, you sent: %s", buffer);

    // Send response to client
    if (send(new_sockfd, resp_buffer, strlen(resp_buffer), 0) != strlen(resp_buffer)) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    printf("Response sent to client: %s\n", resp_buffer);

    // Close sockets
    close(new_sockfd);
    close(sockfd);

    return 0;
}