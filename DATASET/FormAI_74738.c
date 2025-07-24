//FormAI DATASET v1.0 Category: Networking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_SIZE 256
#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock_fd;
    struct sockaddr_in server_addr;
    char message[MAX_MSG_SIZE] = {0};

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }

    // Set server address parameters
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        return EXIT_FAILURE;
    }

    // Connect to server
    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return EXIT_FAILURE;
    }

    // Send message to server
    printf("Enter message: ");
    fgets(message, MAX_MSG_SIZE, stdin);
    if (write(sock_fd, message, strlen(message)) < 0) {
        perror("Failed to send message");
        return EXIT_FAILURE;
    }

    // Receive message from server
    int msg_size;
    char server_reply[MAX_MSG_SIZE] = {0};
    if ((msg_size = recv(sock_fd, server_reply, MAX_MSG_SIZE, 0)) < 0) {
        perror("No message received from server");
        return EXIT_FAILURE;
    }
    printf("Server reply: %.*s\n", msg_size, server_reply);

    close(sock_fd);
    return EXIT_SUCCESS;
}