//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDR "mail.example.com"
#define SERVER_PORT 25
#define MAX_BUFFER 1024

int main() {
    struct sockaddr_in server;
    char buffer[MAX_BUFFER];

    // Create a TCP socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the server address structure
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_ADDR, &server.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("connect");
        exit(1);
    }

    // Receive the server's welcome message
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send the HELO message
    sprintf(buffer, "HELO example.com\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive the server's response
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send the MAIL FROM message
    sprintf(buffer, "MAIL FROM: <user@example.com>\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive the server's response
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send the RCPT TO message
    sprintf(buffer, "RCPT TO: <recipient@example.com>\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive the server's response
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send the DATA message
    sprintf(buffer, "DATA\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive the server's response
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send the message body
    sprintf(buffer, "From: <user@example.com>\r\nTo: <recipient@example.com>\r\nSubject: Test\r\n\r\nHello, World!\r\n.\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive the server's response
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Send the QUIT message
    sprintf(buffer, "QUIT\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive the server's response
    recv(sock, buffer, MAX_BUFFER, 0);
    printf("%s", buffer);

    // Close the socket
    close(sock);

    return 0;
}