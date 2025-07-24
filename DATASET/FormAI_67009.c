//FormAI DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};
    char *ip_address = "";


    if (argc < 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return -1;
    } else {
        ip_address = argv[1];
    }

    // Create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <=0 ) {
        printf("Invalid address/ Address not supported\n");
        return -1;
    }

    // Create connection
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection Failed\n");
        return -1;
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter message to send: ");
        fgets(buffer, 1024, stdin);

        // Remove trailing newline character
        buffer[strcspn(buffer, "\n")] = 0;

        // Send data to server
        send(socket_fd, buffer, strlen(buffer), 0);

        // Receive data from server
        memset(buffer, 0, sizeof(buffer));
        if (recv(socket_fd, buffer, 1024, 0) <= 0) {
            printf("Server disconnected\n");
            break;
        }

        printf("Server response: %s\n", buffer);
    }

    close(socket_fd);
    return 0;
}