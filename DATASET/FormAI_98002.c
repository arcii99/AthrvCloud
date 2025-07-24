//FormAI DATASET v1.0 Category: Client Server Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_fd, valread;
    struct sockaddr_in server_addr;
    char message[1024] = {0}, buffer[1024] = {0};
    bool connected = false;

    // Create a socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Set server address and the port number
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported\n");
        return 1;
    }

    // Connect to the server
    while (!connected) {
        printf("Connecting to server...\n");
        if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Connection Failed. Retrying...");
            sleep(1);
            continue;
        }
        connected = true;
    }

    printf("Connected to server. Type 'exit' to quit.\n");

    // Send messages to the server
    while (true) {
        printf("> ");
        fgets(message, 1024, stdin);

        if (strcmp(message, "exit\n") == 0) {
            break;
        }

        send(socket_fd, message, strlen(message), 0);
        printf("Message sent to server.\n");

        // Receive response from the server
        valread = read(socket_fd, buffer, 1024);
        printf("Server's response: %s", buffer);

        // Reset the buffer
        bzero(buffer, sizeof(buffer));
    }

    close(socket_fd);
    printf("Disconnected from server.\n");

    return 0;
}