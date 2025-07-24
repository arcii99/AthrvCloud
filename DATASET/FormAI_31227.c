//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER 1024
#define POP3_PORT 110

// Function to receive message from POP3 server
void receiveMessage(int sock, char *message) {
    memset(message, 0, MAX_BUFFER);
    recv(sock, message, MAX_BUFFER, 0);
    printf("%s", message);
}

// Function to send message to POP3 server
void sendMessage(int sock, char *message) {
    send(sock, message, strlen(message), 0);
}

int main() {
    // Define variables
    int sock;
    struct sockaddr_in server;
    char message[MAX_BUFFER];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error: socket creation failed");
        exit(1);
    }

    // Set up server address structure
    server.sin_addr.s_addr = inet_addr("localhost");
    server.sin_family = AF_INET;
    server.sin_port = htons(POP3_PORT);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error: connection failed");
        exit(1);
    }

    // Receive greeting message
    receiveMessage(sock, message);

    // Send USER command
    sendMessage(sock, "USER example_username\r\n");
    receiveMessage(sock, message);

    // Send PASS command
    sendMessage(sock, "PASS example_password\r\n");
    receiveMessage(sock, message);

    // Send LIST command
    sendMessage(sock, "LIST\r\n");
    receiveMessage(sock, message);

    // Send RETR command for first email
    sendMessage(sock, "RETR 1\r\n");
    receiveMessage(sock, message);

    // Close connection
    sendMessage(sock, "QUIT\r\n");
    receiveMessage(sock, message);
    close(sock);

    return 0;
}