//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, port = 25;
    char *smtp_server = "smtp.gmail.com";
    struct sockaddr_in server;
    char message[BUF_SIZE], response[BUF_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Fill server details
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if(inet_pton(AF_INET, smtp_server, &server.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    // Send initial message to server
    read(sock, response, BUF_SIZE);
    printf("%s", response);
    memset(message, 0, BUF_SIZE);
    sprintf(message, "HELO %s\r\n", "localhost");
    write(sock, message, strlen(message));

    // Receive response and print
    read(sock, response, BUF_SIZE);
    printf("%s", response);

    // Send login details
    memset(message, 0, BUF_SIZE);
    sprintf(message, "AUTH LOGIN\r\n");
    write(sock, message, strlen(message));

    read(sock, response, BUF_SIZE);
    printf("%s", response);

    memset(message, 0, BUF_SIZE);
    sprintf(message, "%s\r\n", "your_username");
    write(sock, message, strlen(message));

    read(sock, response, BUF_SIZE);
    printf("%s", response);

    memset(message, 0, BUF_SIZE);
    sprintf(message, "%s\r\n", "your_password");
    write(sock, message, strlen(message));

    read(sock, response, BUF_SIZE);
    printf("%s", response);

    // Send email details
    memset(message, 0, BUF_SIZE);
    sprintf(message, "MAIL FROM:<%s>\r\n", "sender@example.com");
    write(sock, message, strlen(message));

    read(sock, response, BUF_SIZE);
    printf("%s", response);

    memset(message, 0, BUF_SIZE);
    sprintf(message, "RCPT TO:<%s>\r\n", "recipient@example.com");
    write(sock, message, strlen(message));

    read(sock, response, BUF_SIZE);
    printf("%s", response);

    // Send email body
    memset(message, 0, BUF_SIZE);
    sprintf(message, "DATA\r\n");
    write(sock, message, strlen(message));

    read(sock, response, BUF_SIZE);
    printf("%s", response);

    memset(message, 0, BUF_SIZE);
    sprintf(message, "Subject: SMTP Test\r\nFrom: sender@example.com\r\nTo: recipient@example.com\r\n\r\nHello, this is a test email.\r\n.\r\n");
    write(sock, message, strlen(message));

    read(sock, response, BUF_SIZE);
    printf("%s", response);

    // Quit server
    memset(message, 0, BUF_SIZE);
    sprintf(message, "QUIT\r\n");
    write(sock, message, strlen(message));

    read(sock, response, BUF_SIZE);
    printf("%s", response);

    // Close socket
    close(sock);

    return 0;
}