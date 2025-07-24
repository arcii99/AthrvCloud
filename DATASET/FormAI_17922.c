//FormAI DATASET v1.0 Category: Socket programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 6200  // Port for connection
#define MAX_SIZE 1024 // Maximum message size

int main() {
    int sock = 0, valread;
    struct sockaddr_in server_address;
    char buffer[MAX_SIZE] = {0};
    char message[MAX_SIZE] = {0};
    char response[MAX_SIZE] = {0};

    // Cyberpunk-style introduction
    printf("==============================================\n");
    printf("             WELCOME TO THE MATRIX            \n");
    printf("==============================================\n");
    printf("Connecting to server...\n");

    // Create socket for connection
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    // Fill server address details and connect
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr)<=0) {
        printf("Invalid address\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Connection error\n");
        return -1;
    }

    // Connected!
    printf("Connection established!\n");
    printf("Type 'quit' or 'exit' to close the connection.\n");

    while(1) {
        printf("Enter message: ");
        fgets(message, MAX_SIZE, stdin);

        // Remove newline character
        message[strcspn(message, "\n")] = '\0';

        // Check for exit condition
        if (strcmp(message, "quit") == 0 || strcmp(message, "exit") == 0) {
            printf("Disconnecting from server...\n");
            break;
        }

        // Send message to server
        send(sock, message, strlen(message), 0);
        printf("Message sent!\n");

        // Receive response from server
        valread = read(sock, response, MAX_SIZE);
        printf("Server response: %s\n", response);

        // Clear buffer
        memset(response, '\0', sizeof(response));
    }

    // Close socket and exit
    close(sock);
    printf("Disconnected from server. Goodbye!\n");

    return 0;
}