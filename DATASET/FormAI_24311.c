//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Alan Touring
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main() {
    int sock;
    struct sockaddr_in server;
    char message[1024], response[1024];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr("your.smtp.server.ip.address");
    server.sin_family = AF_INET;
    server.sin_port = htons(SMTP_PORT);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection error");
        return 1;
    }

    // Receive banner
    memset(response, 0, sizeof(response));
    if (recv(sock, response, sizeof(response), 0) < 0) {
        printf("Failed to read banner");
        return 1;
    }

    printf("%s", response);

    // Send EHLO message
    sprintf(message, "EHLO client.example.com\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Failed to send EHLO message");
        return 1;
    }

    // Receive EHLO response
    memset(response, 0, sizeof(response));
    if (recv(sock, response, sizeof(response), 0) < 0) {
        printf("Failed to read EHLO response");
        return 1;
    }

    printf("%s", response);

    // Send MAIL FROM message
    sprintf(message, "MAIL FROM:<sender@example.com>\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Failed to send MAIL FROM message");
        return 1;
    }

    // Receive MAIL FROM response
    memset(response, 0, sizeof(response));
    if (recv(sock, response, sizeof(response), 0) < 0) {
        printf("Failed to read MAIL FROM response");
        return 1;
    }

    printf("%s", response);

    // Send RCPT TO message
    sprintf(message, "RCPT TO:<recipient@example.com>\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Failed to send RCPT TO message");
        return 1;
    }

    // Receive RCPT TO response
    memset(response, 0, sizeof(response));
    if (recv(sock, response, sizeof(response), 0) < 0) {
        printf("Failed to read RCPT TO response");
        return 1;
    }

    printf("%s", response);

    // Send DATA message
    sprintf(message, "DATA\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Failed to send DATA message");
        return 1;
    }

    // Receive DATA response
    memset(response, 0, sizeof(response));
    if (recv(sock, response, sizeof(response), 0) < 0) {
        printf("Failed to read DATA response");
        return 1;
    }

    printf("%s", response);

    // Send message body
    sprintf(message, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test mail\r\n\r\nThis is a test message.\r\n.\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Failed to send message body");
        return 1;
    }

    // Receive message sent confirmation
    memset(response, 0, sizeof(response));
    if (recv(sock, response, sizeof(response), 0) < 0) {
        printf("Failed to read message sent confirmation");
        return 1;
    }

    printf("%s", response);

    // Quit
    sprintf(message, "QUIT\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Failed to send QUIT message");
        return 1;
    }

    close(sock);

    return 0;
}