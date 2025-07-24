//FormAI DATASET v1.0 Category: Socket programming ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 8888
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, valread;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE] = {0};
    const char *hello = "Hello from client!";

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
  
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address: Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Send request to server
    send(server_fd, hello, strlen(hello), 0);
    printf("Message sent to server: %s\n", hello);

    // Wait for response from server
    valread = read(server_fd, buffer, MAX_BUFFER_SIZE);
    printf("Message received from server: %s\n", buffer);

    // Cleanup
    close(server_fd);
    return 0;
}