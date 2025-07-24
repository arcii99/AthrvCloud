//FormAI DATASET v1.0 Category: Networking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Oops! Something went wrong while creating socket!\n");
        return -1;
    }
    printf("Socket created successfully!\n");

    // Server's address and port
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Oops! Something went wrong while connecting to server!\n");
        return -1;
    }
    printf("Connected to server successfully!\n");

    // Send a message to the server
    char message[1000];
    printf("Enter a message to send to the server: ");
    fgets(message, 1000, stdin);
    send(sock, message, strlen(message), 0);
    printf("Message sent to server successfully!\n");

    // Receive a message from the server
    char buffer[1000] = {0};
    read(sock, buffer, 1000);
    printf("Message received from server: %s\n", buffer);

    // Close the socket
    close(sock);
    printf("Socket closed successfully!\n");

    return 0;
}