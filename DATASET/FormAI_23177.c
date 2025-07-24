//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "imap.example.com" // replace with your desired server
#define PORT 993 // IMAP4 over SSL port number

#define BUF_SIZE 1024 // Maximum buffer size

int main() {
    // Create a socket for TCP connection to IMAP server
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // Setup address to connect to server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER, &server_addr.sin_addr) != 1) {
        perror("Failed to convert server address");
        return 1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        return 1;
    }

    // Read initial server greeting message
    char buf[BUF_SIZE];
    ssize_t num_bytes = read(sock, buf, sizeof(buf)-1);
    if (num_bytes < 0) {
        perror("Failed to read from server");
        return 1;
    }
    buf[num_bytes] = '\0';
    printf("Server greeting: %s\n", buf);

    // Send login command to server
    const char* username = "username"; // replace with your username
    const char* password = "password"; // replace with your password
    snprintf(buf, sizeof(buf), "login %s %s\r\n", username, password);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("Failed to send login command to server");
        return 1;
    }

    // Read server response to login command
    num_bytes = read(sock, buf, sizeof(buf)-1);
    if (num_bytes < 0) {
        perror("Failed to read from server");
        return 1;
    }
    buf[num_bytes] = '\0';
    printf("Login response: %s\n", buf);

    // Send select command to select mailbox
    const char* mailbox = "INBOX"; // replace with your desired mailbox name
    snprintf(buf, sizeof(buf), "select %s\r\n", mailbox);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("Failed to send select command to server");
        return 1;
    }

    // Read server response to select command
    num_bytes = read(sock, buf, sizeof(buf)-1);
    if (num_bytes < 0) {
        perror("Failed to read from server");
        return 1;
    }
    buf[num_bytes] = '\0';
    printf("Select response: %s\n", buf);

    // Send fetch command to retrieve a message
    const char* message_num = "1"; // replace with desired message number
    snprintf(buf, sizeof(buf), "fetch %s body[header.fields (subject from to)]\r\n", message_num);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("Failed to send fetch command to server");
        return 1;
    }

    // Read server response to fetch command
    num_bytes = read(sock, buf, sizeof(buf)-1);
    if (num_bytes < 0) {
        perror("Failed to read from server");
        return 1;
    }
    buf[num_bytes] = '\0';
    printf("Fetch response: %s\n", buf);

    // Send logout command to server
    if (send(sock, "logout\r\n", 8, 0) < 0) {
        perror("Failed to send logout command to server");
        return 1;
    }

    // Read server response to logout command
    num_bytes = read(sock, buf, sizeof(buf)-1);
    if (num_bytes < 0) {
        perror("Failed to read from server");
        return 1;
    }
    buf[num_bytes] = '\0';
    printf("Logout response: %s\n", buf);

    // Close socket
    if (close(sock) < 0) {
        perror("Failed to close socket");
        return 1;
    }

    return 0;
}