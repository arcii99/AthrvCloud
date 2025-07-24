//FormAI DATASET v1.0 Category: Socket programming ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_fd, valread;
    struct sockaddr_in server_address;
    char hello_msg[] = "Hello from client";

    // Create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Set up server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr)<=0) {
        perror("Invalid address or address not supported");
        return -1;
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        return -1;
    }

    // Send hello message to server
    if (write(socket_fd, hello_msg, strlen(hello_msg)) < 0) {
        perror("Message send failed");
        return -1;
    }

    // Wait for server response
    char buffer[1024] = {0};
    if ((valread = read(socket_fd, buffer, 1024)) < 0) {
        perror("Read failed");
        return -1;
    }

    printf("Server response: %s\n", buffer);

    // Close socket
    close(socket_fd);
    return 0;
}