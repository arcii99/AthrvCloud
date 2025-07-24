//FormAI DATASET v1.0 Category: Networking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {

    // Initialize variables
    struct sockaddr_in serv_addr;
    int sock_fd, read_val, message_len;
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE] = "The future is now. And it's dark.";

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    // Set up TCP connection
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address\n");
        return -1;
    }

    if (connect(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection error\n");
        return -1;
    }

    // Send message
    message_len = strlen(message);
    write(sock_fd, message, message_len);

    // Receive response
    while ((read_val = read(sock_fd, buffer, BUFFER_SIZE)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    // Close connection
    close(sock_fd);
    return 0;
}