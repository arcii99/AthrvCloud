//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#define PORT 993
#define HOST "mail.example.com"
#define USER "username@example.com"
#define PASSWORD "password123"

#define BUFFERSIZE 1024

int main() {
    int sock_fd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUFFERSIZE];
    char response[BUFFERSIZE];
    char encoded_userpass[BUFFERSIZE];
    int bytes_read;
    
    // Set up socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Get server IP address
    server = gethostbyname(HOST);
    if (server == NULL) {
        perror("Error getting server address");
        exit(EXIT_FAILURE);
    }

    // Set up server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Read welcome message from server
    bytes_read = read(sock_fd, response, BUFFERSIZE - 1);
    if (bytes_read < 0) {
        perror("Error reading server response");
        exit(EXIT_FAILURE);
    }
    response[bytes_read] = '\0';
    printf("%s", response);

    // Send login command
    snprintf(buffer, BUFFERSIZE, "LOGIN %s %s\r\n", USER, PASSWORD);
    if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending LOGIN command");
        exit(EXIT_FAILURE);
    }

    // Read response to login command
    bytes_read = read(sock_fd, response, BUFFERSIZE - 1);
    if (bytes_read < 0) {
        perror("Error reading server response");
        exit(EXIT_FAILURE);
    }
    response[bytes_read] = '\0';
    printf("%s", response);

    // Encode username and password for later use
    snprintf(buffer, BUFFERSIZE, "%s:%s", USER, PASSWORD);
    base64_encode(encoded_userpass, buffer, strlen(buffer));

    // Send SELECT command to choose inbox
    snprintf(buffer, BUFFERSIZE, "SELECT INBOX\r\n");
    if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending SELECT command");
        exit(EXIT_FAILURE);
    }

    // Read response to SELECT command
    bytes_read = read(sock_fd, response, BUFFERSIZE - 1);
    if (bytes_read < 0) {
        perror("Error reading server response");
        exit(EXIT_FAILURE);
    }
    response[bytes_read] = '\0';
    printf("%s", response);

    // Send FETCH command to retrieve first message
    snprintf(buffer, BUFFERSIZE, "FETCH 1 BODY[]\r\n");
    if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending FETCH command");
        exit(EXIT_FAILURE);
    }

    // Read response to FETCH command
    bytes_read = read(sock_fd, response, BUFFERSIZE - 1);
    if (bytes_read < 0) {
        perror("Error reading server response");
        exit(EXIT_FAILURE);
    }
    response[bytes_read] = '\0';
    printf("%s", response);

    // Send LOGOUT command to end session
    snprintf(buffer, BUFFERSIZE, "LOGOUT\r\n");
    if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending LOGOUT command");
        exit(EXIT_FAILURE);
    }

    // Read response to LOGOUT command
    bytes_read = read(sock_fd, response, BUFFERSIZE - 1);
    if (bytes_read < 0) {
        perror("Error reading server response");
        exit(EXIT_FAILURE);
    }
    response[bytes_read] = '\0';
    printf("%s", response);

    // Close socket
    close(sock_fd);

    return 0;
}

// Base64 encoder - taken from https://stackoverflow.com/a/36566052/1415810
static const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void base64_encode(char *output, const char *input, size_t input_len) {
    size_t i, j;
    for (i = 0, j = 0; i < input_len; i += 3, j += 4) {
        uint32_t octet_a = i < input_len ? (unsigned char)input[i] : 0;
        uint32_t octet_b = i + 1 < input_len ? (unsigned char)input[i + 1] : 0;
        uint32_t octet_c = i + 2 < input_len ? (unsigned char)input[i + 2] : 0;
        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;
        output[j + 0] = base64_table[(triple >> 3 * 6) & 0x3F];
        output[j + 1] = base64_table[(triple >> 2 * 6) & 0x3F];
        output[j + 2] = base64_table[(triple >> 1 * 6) & 0x3F];
        output[j + 3] = base64_table[(triple >> 0 * 6) & 0x3F];
    }
    for (i = 0; i < 3 - input_len % 3; i++) output[strlen(output)] = '=';
    output[strlen(output)] = '\0';
}