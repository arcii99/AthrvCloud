//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main() {
    int sock_fd, n;
    struct sockaddr_in server_addr;
    socklen_t server_len = sizeof(server_addr);
    char buff[MAXLINE];

    // Create a socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(25);

    // Connect to the server
    if (connect(sock_fd, (struct sockaddr*) &server_addr, server_len) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Read the greeting message from the server
    recv(sock_fd, buff, MAXLINE, 0);
    printf("%s", buff);

    // Send EHLO command to the server
    sprintf(buff, "EHLO client\r\n");
    send(sock_fd, buff, strlen(buff), 0);
    recv(sock_fd, buff, MAXLINE, 0);
    printf("%s", buff);

    // Send MAIL FROM command to the server
    sprintf(buff, "MAIL FROM:<sender@example.com>\r\n");
    send(sock_fd, buff, strlen(buff), 0);
    recv(sock_fd, buff, MAXLINE, 0);
    printf("%s", buff);

    // Send RCPT TO command to the server
    sprintf(buff, "RCPT TO:<recipient@example.com>\r\n");
    send(sock_fd, buff, strlen(buff), 0);
    recv(sock_fd, buff, MAXLINE, 0);
    printf("%s", buff);

    // Send DATA command to the server
    sprintf(buff, "DATA\r\n");
    send(sock_fd, buff, strlen(buff), 0);
    recv(sock_fd, buff, MAXLINE, 0);
    printf("%s", buff);

    // Send the email message to the server
    sprintf(buff, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test Email\r\n\r\nThis is a test email.\r\n.\r\n");
    send(sock_fd, buff, strlen(buff), 0);
    recv(sock_fd, buff, MAXLINE, 0);
    printf("%s", buff);

    // Send QUIT command to the server
    sprintf(buff, "QUIT\r\n");
    send(sock_fd, buff, strlen(buff), 0);
    recv(sock_fd, buff, MAXLINE, 0);
    printf("%s", buff);

    // Close the socket
    close(sock_fd);

    return 0;
}