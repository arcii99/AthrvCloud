//FormAI DATASET v1.0 Category: Networking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {

    printf("Hello there! I am a curious chatbot and I want to learn more about networking. Let's create a simple TCP client-server program together!\n\n");

    // Step 1: Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Step 2: Specify the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Step 3: Connect to the server
    if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
    printf("Connected to server\n\n");

    while (1) {
        // Step 4: Send a message to the server
        printf("Enter a message to send to the server: ");
        char message[255];
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0; // remove new line character

        if (strcmp(message, "quit") == 0) {
            printf("Exiting program...\n");
            break;
        }

        send(sock, message, strlen(message), 0);

        // Step 5: Receive a message from the server
        char buffer[255] = {0};
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received < 0) {
            perror("Failed to receive message from server");
            exit(EXIT_FAILURE);
        }
        printf("\nServer response: %s\n\n", buffer);
    }

    // Step 6: Close the socket
    close(sock);

    return 0;
}