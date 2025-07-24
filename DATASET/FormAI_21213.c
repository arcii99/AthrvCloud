//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define IMAP_PORT 993

void error_handler(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server_ip> <username> <password>\n", argv[0]);
        exit(1);
    }

    char *server_ip = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error_handler("Failed to create socket");
    }

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        error_handler("Invalid IP address");
    }

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error_handler("Failed to connect to server");
    }

    char buf[BUF_SIZE];
    int n = read(sock, buf, BUF_SIZE);
    if (n < 0) {
        error_handler("Failed to read from server");
    }
    printf("%.*s", n, buf);

    // send login command
    snprintf(buf, BUF_SIZE, "A1 LOGIN %s %s\n", username, password);
    n = write(sock, buf, strlen(buf));
    if (n < 0) {
        error_handler("Failed to write to server");
    }

    n = read(sock, buf, BUF_SIZE);
    if (n < 0) {
        error_handler("Failed to read from server");
    }
    printf("%.*s", n, buf);

    // send select inbox command
    snprintf(buf, BUF_SIZE, "A2 SELECT INBOX\n");
    n = write(sock, buf, strlen(buf));
    if (n < 0) {
        error_handler("Failed to write to server");
    }

    n = read(sock, buf, BUF_SIZE);
    if (n < 0) {
        error_handler("Failed to read from server");
    }
    printf("%.*s", n, buf);

    // send fetch command to retrieve emails
    snprintf(buf, BUF_SIZE, "A3 FETCH 1:* BODY[]\n");
    n = write(sock, buf, strlen(buf));
    if (n < 0) {
        error_handler("Failed to write to server");
    }

    // print email contents
    while ((n = read(sock, buf, BUF_SIZE)) > 0) {
        printf("%.*s", n, buf);
    }
    if (n < 0) {
        error_handler("Failed to read from server");
    }

    // send logout command
    snprintf(buf, BUF_SIZE, "A4 LOGOUT\n");
    n = write(sock, buf, strlen(buf));
    if (n < 0) {
        error_handler("Failed to write to server");
    }

    n = read(sock, buf, BUF_SIZE);
    if (n < 0) {
        error_handler("Failed to read from server");
    }
    printf("%.*s", n, buf);

    close(sock);
    return 0;
}