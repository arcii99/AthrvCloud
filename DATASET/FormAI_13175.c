//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 2048

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <server_address> <username> <password>\n", argv[0]);
        exit(1);
    }

    // Connect to the IMAP server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(143);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("Failed to parse server address");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    // Log in as the user
    char username_buf[MAX_BUF_SIZE];
    char password_buf[MAX_BUF_SIZE];
    snprintf(username_buf, MAX_BUF_SIZE, "LOGIN %s ", argv[2]);
    snprintf(password_buf, MAX_BUF_SIZE, "%s\r\n", argv[3]);
    char login_buf[MAX_BUF_SIZE];
    strcpy(login_buf, username_buf);
    strcat(login_buf, password_buf);

    if (send(sock, login_buf, strlen(login_buf), 0) < 0) {
        perror("Failed to send login data to server");
        exit(1);
    }

    char response_buf[MAX_BUF_SIZE];
    ssize_t response_len = recv(sock, response_buf, MAX_BUF_SIZE, 0);
    if (response_len < 0) {
        perror("Failed to receive login response from server");
        exit(1);
    }

    printf("Server response: %.*s", (int)response_len, response_buf);

    // Fetch the list of available mailboxes
    char list_buf[MAX_BUF_SIZE];
    strcpy(list_buf, "LIST \"\" \"*\"\r\n");

    if (send(sock, list_buf, strlen(list_buf), 0) < 0) {
        perror("Failed to send list command to server");
        exit(1);
    }

    response_len = recv(sock, response_buf, MAX_BUF_SIZE, 0);
    if (response_len < 0) {
        perror("Failed to receive list response from server");
        exit(1);
    }

    printf("Server response: %.*s", (int)response_len, response_buf);

    // Fetch the total number of messages in the INBOX
    char status_buf[MAX_BUF_SIZE];
    strcpy(status_buf, "STATUS INBOX (messages)\r\n");

    if (send(sock, status_buf, strlen(status_buf), 0) < 0) {
        perror("Failed to send status command to server");
        exit(1);
    }

    response_len = recv(sock, response_buf, MAX_BUF_SIZE, 0);
    if (response_len < 0) {
        perror("Failed to receive status response from server");
        exit(1);
    }

    printf("Server response: %.*s", (int)response_len, response_buf);

    close(sock);

    return 0;
}