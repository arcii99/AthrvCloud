//FormAI DATASET v1.0 Category: Client Server Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int client_socket = 0, valread;
    struct sockaddr_in server_address;
    char buffer[1024] = {0};
    char *hello = "Hello from client";

    // Create socket file descriptor
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        printf("Invalid address/ Not supported\n");
        return -1;
    }

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Connection failed\n");
        return -1;
    }

    // Send message to server
    send(client_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // Receive response from server
    valread = read(client_socket, buffer, 1024);
    printf("%s\n", buffer);
    return 0;
}