//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 25

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(SERVER_IP);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    char buffer[1024];
    if (recv(sock, buffer, 1024, 0) < 0) {
        perror("Failed to receive message from server");
        exit(1);
    }
    printf("%s\n", buffer);

    char *ehlo = "EHLO example.com\r\n";
    if (send(sock, ehlo, strlen(ehlo), 0) < 0) {
        perror("Failed to send message to server");
        exit(1);
    }
    if (recv(sock, buffer, 1024, 0) < 0) {
        perror("Failed to receive message from server");
        exit(1);
    }
    printf("%s\n", buffer);

    char *mail_from = "MAIL FROM: <example@example.com>\r\n";
    if (send(sock, mail_from, strlen(mail_from), 0) < 0) {
        perror("Failed to send message to server");
        exit(1);
    }
    if (recv(sock, buffer, 1024, 0) < 0) {
        perror("Failed to receive message from server");
        exit(1);
    }
    printf("%s\n", buffer);

    char *rcpt_to = "RCPT TO: <example@example.com>\r\n";
    if (send(sock, rcpt_to, strlen(rcpt_to), 0) < 0) {
        perror("Failed to send message to server");
        exit(1);
    }
    if (recv(sock, buffer, 1024, 0) < 0) {
        perror("Failed to receive message from server");
        exit(1);
    }
    printf("%s\n", buffer);

    char *data = "DATA\r\n";
    if (send(sock, data, strlen(data), 0) < 0) {
        perror("Failed to send message to server");
        exit(1);
    }
    if (recv(sock, buffer, 1024, 0) < 0) {
        perror("Failed to receive message from server");
        exit(1);
    }
    printf("%s\n", buffer);

    char *message = "Subject: Test message\r\nThis is a test message\r\n.\r\n";
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("Failed to send message to server");
        exit(1);
    }
    if (recv(sock, buffer, 1024, 0) < 0) {
        perror("Failed to receive message from server");
        exit(1);
    }
    printf("%s\n", buffer);

    char *quit = "QUIT\r\n";
    if (send(sock, quit, strlen(quit), 0) < 0) {
        perror("Failed to send message to server");
        exit(1);
    }
    if (recv(sock, buffer, 1024, 0) < 0) {
        perror("Failed to receive message from server");
        exit(1);
    }
    printf("%s\n", buffer);

    close(sock);
    return 0;
}