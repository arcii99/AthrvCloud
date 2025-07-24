//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_LENGTH 1024

int main(int argc, char *argv[]) {
    int sock = 0, bytes_sent = 0, bytes_recv = 0;
    struct sockaddr_in server_addr;
    char message[MAX_MSG_LENGTH] = {0};
    char buffer[MAX_MSG_LENGTH] = {0};

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket.\n");
        return -1;
    }

    // Initialize server address structure parameters
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(587); // SMTP uses port 587
    server_addr.sin_addr.s_addr = inet_addr("0.0.0.0"); // Replace with actual server IP address

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server.\n");
        return -1;
    }

    // Receive initial server response message
    bytes_recv = read(sock, buffer, MAX_MSG_LENGTH - 1);
    if (bytes_recv < 0) {
        printf("Error receiving server response message.\n");
        return -1;
    }
    buffer[bytes_recv] = '\0';
    printf("Server response: %s", buffer);

    // Send HELO command to server
    strcpy(message, "HELO example.com\r\n");
    bytes_sent = send(sock, message, strlen(message), 0);
    if (bytes_sent < 0) {
        printf("Error sending HELO command to server.\n");
        return -1;
    }

    // Receive server response message
    bytes_recv = read(sock, buffer, MAX_MSG_LENGTH - 1);
    if (bytes_recv < 0) {
        printf("Error receiving server response message.\n");
        return -1;
    }
    buffer[bytes_recv] = '\0';
    printf("Server response: %s", buffer);

    // Send MAIL FROM command to server
    strcpy(message, "MAIL FROM:<sender@example.com>\r\n");
    bytes_sent = send(sock, message, strlen(message), 0);
    if (bytes_sent < 0) {
        printf("Error sending MAIL FROM command to server.\n");
        return -1;
    }

    // Receive server response message
    bytes_recv = read(sock, buffer, MAX_MSG_LENGTH - 1);
    if (bytes_recv < 0) {
        printf("Error receiving server response message.\n");
        return -1;
    }
    buffer[bytes_recv] = '\0';
    printf("Server response: %s", buffer);

    // Send RCPT TO command to server
    strcpy(message, "RCPT TO:<recipient@example.com>\r\n");
    bytes_sent = send(sock, message, strlen(message), 0);
    if (bytes_sent < 0) {
        printf("Error sending RCPT TO command to server.\n");
        return -1;
    }

    // Receive server response message
    bytes_recv = read(sock, buffer, MAX_MSG_LENGTH - 1);
    if (bytes_recv < 0) {
        printf("Error receiving server response message.\n");
        return -1;
    }
    buffer[bytes_recv] = '\0';
    printf("Server response: %s", buffer);

    // Send DATA command to server
    strcpy(message, "DATA\r\n");
    bytes_sent = send(sock, message, strlen(message), 0);
    if (bytes_sent < 0) {
        printf("Error sending DATA command to server.\n");
        return -1;
    }

    // Receive server response message
    bytes_recv = read(sock, buffer, MAX_MSG_LENGTH - 1);
    if (bytes_recv < 0) {
        printf("Error receiving server response message.\n");
        return -1;
    }
    buffer[bytes_recv] = '\0';
    printf("Server response: %s", buffer);

    // Send message subject and body to server
    strcpy(message, "Subject: SMTP Client Example\r\n");
    strcat(message, "From: sender@example.com\r\n");
    strcat(message, "To: recipient@example.com\r\n");
    strcat(message, "This is an example message sent via SMTP client program.\r\n");
    strcat(message, ".\r\n"); // End of message
    bytes_sent = send(sock, message, strlen(message), 0);
    if (bytes_sent < 0) {
        printf("Error sending message to server.\n");
        return -1;
    }

    // Receive server response message
    bytes_recv = read(sock, buffer, MAX_MSG_LENGTH - 1);
    if (bytes_recv < 0) {
        printf("Error receiving server response message.\n");
        return -1;
    }
    buffer[bytes_recv] = '\0';
    printf("Server response: %s", buffer);

    // Send QUIT command to server
    strcpy(message, "QUIT\r\n");
    bytes_sent = send(sock, message, strlen(message), 0);
    if (bytes_sent < 0) {
        printf("Error sending QUIT command to server.\n");
        return -1;
    }

    // Receive final server response message
    bytes_recv = read(sock, buffer, MAX_MSG_LENGTH - 1);
    if (bytes_recv < 0) {
        printf("Error receiving server response message.\n");
        return -1;
    }
    buffer[bytes_recv] = '\0';
    printf("Server response: %s", buffer);

    // Close socket
    close(sock);

    return 0;
}