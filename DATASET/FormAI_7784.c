//FormAI DATASET v1.0 Category: Networking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int sock_fd = 0, conn_fd = 0;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE] = {0};
    char *message = "Hello there! I am a networking chatbot. What can I do for you today?\n";

    // Step 1: Create a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Socket creation failed.\n");
        return -1;
    }

    // Step 2: Initialize the server address structure
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported.\n");
        return -1;
    }

    // Step 3: Connect to the server
    if (connect(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed.\n");
        return -1;
    }

    // Step 4: Send a message to the server
    if (send(sock_fd, message, strlen(message), 0) < 0) {
        perror("Message transmission failed.\n");
        return -1;
    }

    printf("Message sent: \"%s\"\n", message);

    // Step 5: Receive a reply from the server
    if (read(sock_fd, buffer, MAX_BUFFER_SIZE) < 0) {
        perror("Message reception failed.\n");
        return -1;
    }

    printf("Server reply: \"%s\"\n", buffer);

    close(sock_fd);

    return 0;
}