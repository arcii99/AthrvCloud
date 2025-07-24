//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

bool is_connected = false;

int connect_server(const char *server_address, const char *username, const char *password) {
    int sock_fd = -1;
    struct sockaddr_in server;
    char buf[MAX_BUF_SIZE];

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        return -1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(993); // IMAP port
    inet_pton(AF_INET, server_address, &server.sin_addr);

    if (connect(sock_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connect failed");
        return -1;
    }

    // Receive server response
    int bytes_read = recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    if (bytes_read < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%.*s", bytes_read, buf);

    // Send login credentials
    sprintf(buf, "a001 LOGIN %s %s\r\n", username, password);
    if (send(sock_fd, buf, strlen(buf), 0) < 0) {
        perror("Error sending message to server");
        return -1;
    }

    // Receive server response
    bytes_read = recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    if (bytes_read < 0) {
        perror("Error receiving message from server");
        return -1;
    }
    printf("%.*s", bytes_read, buf);

    if (strstr(buf, "OK") != NULL) {
        is_connected = true;
        printf("Connection successful\n");
    } else {
        printf("Connection failed\n");
    }

    return sock_fd;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server address> <username> <password>\n", argv[0]);
        return -1;
    }

    // Connect to server
    int sock_fd = connect_server(argv[1], argv[2], argv[3]);
    if (sock_fd < 0) {
        return -1;
    }

    // Start listening for user input
    while (is_connected) {
        printf("Enter a command: ");
        char input[MAX_BUF_SIZE];
        fgets(input, MAX_BUF_SIZE, stdin);

        // Send command to server
        if (send(sock_fd, input, strlen(input), 0) < 0) {
            perror("Error sending message to server");
            break;
        }

        // Receive server response
        char buf[MAX_BUF_SIZE];
        int bytes_read = recv(sock_fd, buf, MAX_BUF_SIZE, 0);
        if (bytes_read < 0) {
            perror("Error receiving message from server");
            break;
        }

        printf("%.*s\n", bytes_read, buf);
    }

    // Close socket
    close(sock_fd);

    return 0;
}