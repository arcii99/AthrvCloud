//FormAI DATASET v1.0 Category: Socket programming ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8888

int main(int argc, char **argv) {
    struct sockaddr_in server;
    char *msg = "Hello Server!";
    char buffer[1024] = {0};
    int client_fd;
    int bytes_sent;
    int bytes_rcvd;

    // Create socket
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation failed.\n");
        return -1;
    }

    // Fill address info
    memset(&server, '0', sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0) {
        printf("Invalid address.\n");
        return -1;
    }

    // Connect to server
    if (connect(client_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed.\n");
        return -1;
    }

    // Send message to server
    bytes_sent = send(client_fd, msg, strlen(msg) + 1, 0);
    printf("Message sent to server: %s\n", msg);

    // Receive message from server
    bytes_rcvd = recv(client_fd, buffer, sizeof(buffer), 0);
    printf("Message received from server: %s\n", buffer);

    // Close socket
    close(client_fd);

    return 0;
}