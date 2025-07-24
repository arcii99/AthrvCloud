//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: automated
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "mail.domain.com"
#define BUF_SIZE 1024

int send_socket_ssl(char* message);

int main(void) {
    char message[BUF_SIZE] = {0};
    sprintf(message, "EHLO %s\r\n", "localhost");

    if (send_socket_ssl(message) == 0) {
        sprintf(message, "MAIL FROM:<%s>\r\n", "sender@domain.com");
        send_socket_ssl(message);

        sprintf(message, "RCPT TO:<%s>\r\n", "receiver@domain.com");
        send_socket_ssl(message);

        sprintf(message, "DATA\r\n");
        send_socket_ssl(message);

        sprintf(
            message,
            "Subject:%s\r\nFrom:%s\r\nTo:%s\r\n\r\n%s",
            "Test Subject",
            "sender@domain.com",
            "receiver@domain.com",
            "This is a test email message."
        );
        send_socket_ssl(message);

        sprintf(message, "\r\n.\r\n");
        send_socket_ssl(message);

        sprintf(message, "QUIT\r\n");
        send_socket_ssl(message);
    }

    return 0;
}

int send_socket_ssl(char* message) {
    struct sockaddr_in destination;
    int socket_desc;
    char server_reply[BUF_SIZE];
    char response_code[BUF_SIZE] = {0};

    if ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        return -1;
    }

    destination.sin_addr.s_addr = inet_addr(SERVER);
    destination.sin_family = AF_INET;
    destination.sin_port = htons(25);

    if (connect(socket_desc, (struct sockaddr*)&destination, sizeof(destination)) < 0) {
        perror("Failed to connect to mail server");
        return -1;
    }

    if (recv(socket_desc, server_reply, BUF_SIZE, 0) == -1) {
        perror("Failed to receive from mail server");
        return -1;
    }

    strncpy(response_code, server_reply, 3);
    if (strcmp(response_code, "220") != 0) {
        perror("Failed to connect to mail server");
        return -1;
    }

    if (send(socket_desc, message, strlen(message), 0) == -1) {
        perror("Failed to send message to server");
        return -1;
    }

    if (recv(socket_desc, server_reply, BUF_SIZE, 0) == -1) {
        perror("Failed to receive from mail server");
        return -1;
    }

    strncpy(response_code, server_reply, 3);
    if (strcmp(response_code, "250") != 0 && strcmp(response_code, "354") != 0) {
        perror("Server responded with error");
        return -1;
    }

    close(socket_desc);

    return 0;
}