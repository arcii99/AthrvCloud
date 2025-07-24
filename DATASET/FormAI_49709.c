//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER "mail.example.com"
#define PORT 25

int main() {
    int socket_fd;
    struct sockaddr_in server_addr;
    char buf[1024];

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER, &server_addr.sin_addr) < 1) {
        perror("inet_pton");
        exit(1);
    }
    if (connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Read the welcome message from the server
    if (recv(socket_fd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buf);

    // Send the HELO command to the server
    sprintf(buf, "HELO localhost\r\n");
    if (send(socket_fd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Read the response from the server
    if (recv(socket_fd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buf);

    // Send the MAIL FROM command to the server
    sprintf(buf, "MAIL FROM:<user@example.com>\r\n");
    if (send(socket_fd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Read the response from the server
    if (recv(socket_fd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buf);

    // Send the RCPT TO command to the server
    sprintf(buf, "RCPT TO:<recipient@example.com>\r\n");
    if (send(socket_fd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Read the response from the server
    if (recv(socket_fd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buf);

    // Send the DATA command to the server
    sprintf(buf, "DATA\r\n");
    if (send(socket_fd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Read the response from the server
    if (recv(socket_fd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buf);

    // Send the message body to the server
    sprintf(buf, "From: <user@example.com>\r\nTo: <recipient@example.com>\r\nSubject: Hello, World!\r\n\r\nHello, World!\r\n.\r\n");
    if (send(socket_fd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Read the response from the server
    if (recv(socket_fd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buf);

    // Send the QUIT command to the server
    sprintf(buf, "QUIT\r\n");
    if (send(socket_fd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Read the response from the server
    if (recv(socket_fd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buf);

    // Close the connection
    close(socket_fd);

    return 0;
}