//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define SERVER_PORT 25
#define SERVER_ADDR "smtp.gmail.com"

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char message[1024];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    // Fill server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    // Receive greeting message from server
    recv(client_socket, message, 1024, 0);
    printf("Server: %s", message);

    // Send HELO greeting to server
    strcpy(message, "HELO alice\r\n");
    send(client_socket, message, strlen(message), 0);

    // Receive response from server
    recv(client_socket, message, 1024, 0);
    printf("Server: %s", message);

    // Send MAIL FROM command to server
    strcpy(message, "MAIL FROM:<alice@gmail.com>\r\n");
    send(client_socket, message, strlen(message), 0);

    // Receive response from server
    recv(client_socket, message, 1024, 0);
    printf("Server: %s", message);

    // Send RCPT TO command to server
    strcpy(message, "RCPT TO:<bob@yahoo.com>\r\n");
    send(client_socket, message, strlen(message), 0);

    // Receive response from server
    recv(client_socket, message, 1024, 0);
    printf("Server: %s", message);

    // Send DATA command to server
    strcpy(message, "DATA\r\n");
    send(client_socket, message, strlen(message), 0);

    // Receive response from server
    recv(client_socket, message, 1024, 0);
    printf("Server: %s", message);

    // Send message data to server
    strcpy(message, "Subject: Test email\r\n\r\nThis is a test email.\r\n.\r\n");
    send(client_socket, message, strlen(message), 0);

    // Receive response from server
    recv(client_socket, message, 1024, 0);
    printf("Server: %s", message);

    // Send QUIT command to server
    strcpy(message, "QUIT\r\n");
    send(client_socket, message, strlen(message), 0);

    // Receive response from server
    recv(client_socket, message, 1024, 0);
    printf("Server: %s", message);

    // Close the socket
    close(client_socket);

    return 0;
}