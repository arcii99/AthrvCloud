//FormAI DATASET v1.0 Category: Networking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int client_sock_fd;
    struct sockaddr_in server_addr;
    char message[1024] = {0};

    // Create TCP socket
    if ((client_sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(client_sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Send message to server
    strcpy(message, "Hello from client!");
    send(client_sock_fd, message, strlen(message), 0);
    printf("Client message sent: %s\n", message);

    // Receive message from server
    memset(message, 0, sizeof(message));
    recv(client_sock_fd, message, sizeof(message), 0);
    printf("Server message received: %s\n", message);

    // Close socket
    close(client_sock_fd);

    return 0;
}