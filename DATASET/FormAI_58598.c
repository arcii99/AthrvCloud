//FormAI DATASET v1.0 Category: Networking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MESSAGE_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char message[MESSAGE_SIZE], server_reply[MESSAGE_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket.");
        return 1;
    }

    // Setup server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost
    server_addr.sin_port = htons(8000);

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Could not connect to server.");
        return 1;
    }

    printf("Connected to server.\n");

    // Communication with server
    while (1) {
        printf("Enter message (Type 'exit' to quit): ");
        fgets(message, MESSAGE_SIZE, stdin);

        // Remove newline character
        message[strcspn(message, "\n")] = 0;

        // Send data to server
        if (send(sock, message, strlen(message), 0) < 0) {
            printf("Error: Could not send message to server.");
            return 1;
        }

        // Quit if input is "exit"
        if (strcmp(message, "exit") == 0) {
            break;
        }

        // Receive server reply
        if (recv(sock, server_reply, MESSAGE_SIZE, 0) < 0) {
            printf("Error: Could not receive message from server.");
            return 1;
        }

        printf("Server reply: %s\n", server_reply);
    }

    // Close socket
    close(sock);
    printf("Connection closed.\n");

    return 0;
}