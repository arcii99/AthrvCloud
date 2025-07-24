//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: high level of detail
// This is a TCP/IP Programming example program.
// The client sends a message to the server, the server converts it to uppercase and sends it back to the client.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char message[1024] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    printf("Enter the message: ");
    fgets(message, 1024, stdin);

    // Send message to the server
    send(sock, message, strlen(message), 0);

    // Receive message from the server
    char buffer[1024] = {0};
    read(sock, buffer, 1024);
    printf("Server reply: %s\n", buffer);

    return 0;
}