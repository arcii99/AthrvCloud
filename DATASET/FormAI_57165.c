//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE] = {0};

    if (argc < 3) {
        printf("Usage: %s server_address port\n", argv[0]);
        return -1;
    }

    // Create the socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Could not create socket\n");
        return -1;
    }

    // Set up the server address and port
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        printf("Error: Invalid server address\n");
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Connection failed\n");
        return -1;
    }

    // Receive the greeting message from the server
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: Failed to receive greeting message\n");
        return -1;
    }
    printf("%s", buffer);

    // Send the login command
    const char *username = "example_username";
    const char *password = "example_password";
    sprintf(buffer, ". login %s %s\r\n", username, password);
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Failed to send login command\n");
        return -1;
    }

    // Receive the server's response to the login command
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: Failed to receive response\n");
        return -1;
    }
    printf("%s", buffer);

    // Send the select command for the INBOX folder
    sprintf(buffer, ". select INBOX\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Failed to send select command\n");
        return -1;
    }

    // Receive the server's response to the select command
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: Failed to receive response\n");
        return -1;
    }
    printf("%s", buffer);

    // Send the search command to find all unread emails
    sprintf(buffer, ". search UNSEEN\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Failed to send search command\n");
        return -1;
    }

    // Receive the server's response to the search command
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: Failed to receive response\n");
        return -1;
    }
    printf("%s", buffer);

    // Send the logout command
    sprintf(buffer, ". logout\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        printf("Error: Failed to send logout command\n");
        return -1;
    }

    // Receive the server's response to the logout command
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: Failed to receive response\n");
        return -1;
    }
    printf("%s", buffer);

    // Close the socket
    close(sock);

    return 0;
}