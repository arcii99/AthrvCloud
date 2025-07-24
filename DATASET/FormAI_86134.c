//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 2048

void error(const char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error creating socket");
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(993);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("Could not connect to server");
    }

    // Receive greeting from server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        error("Error receiving message from server");
    }

    // Send login information
    char *login = "LOGIN username password\r\n";
    if (send(sockfd, login, strlen(login), 0) < 0) {
        error("Error sending login information");
    }

    // Receive response from server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        error("Error receiving message from server");
    }

    // Check if login was successful
    if (strstr(buffer, "OK") == NULL) {
        error("Login failed");
    }

    // Send command to fetch all messages from INBOX
    char *fetch = "FETCH 1:* BODY[]\r\n";
    if (send(sockfd, fetch, strlen(fetch), 0) < 0) {
        error("Error sending fetch command");
    }

    // Receive response from server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        error("Error receiving message from server");
    }

    // Print messages
    printf("Messages:\n%s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}