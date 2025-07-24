//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Donald Knuth
/* A TCP/IP programming example in Donald Knuth's style.
 *
 * The program uses sockets to establish a connection between a client and a server.
 * It then sends and receives messages between the two endpoints.
 *
 * Written by [Your Name], [Date]
 *
 * Inspired by the works of Donald Knuth
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main() {
    // Create socket file descriptor
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        printf("Error creating socket");
        exit(1);
    }

    // Initialize server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Bind socket to server address
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock_fd, 5) == -1) {
        printf("Error listening for connections");
        exit(1);
    }

    // Accept incoming connection
    struct sockaddr_in client_addr;
    int client_addr_len = sizeof(client_addr);
    int client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len);
    if (client_fd == -1) {
        printf("Error connecting to client");
        exit(1);
    }

    // Send message to client
    char message[] = "Hello client!";
    if (send(client_fd, message, strlen(message), 0) == -1) {
        printf("Error sending message to client");
        exit(1);
    }

    // Receive message from client
    char buffer[1024] = {0};
    if (recv(client_fd, buffer, 1024, 0) == -1) {
        printf("Error receiving message from client");
        exit(1);
    }
    printf("Message from client: %s\n", buffer);

    // Close sockets and end program
    close(client_fd);
    close(sock_fd);
    return 0;
}