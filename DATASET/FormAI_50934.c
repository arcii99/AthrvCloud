//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server-ip> <username>\n", argv[0]);
        return 1;
    }
    char *server_ip = argv[1];
    char *username = argv[2];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket");
        return 1;
    }

    // Create a server address struct
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) != 1) {
        printf("Invalid server IP address");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("Failed to connect to server");
        return 1;
    }

    // Get the welcome message from the server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Failed to receive welcome message");
        return 1;
    }
    printf("%s", buffer);

    // Send the username to the server
    char user_request[BUFFER_SIZE];
    sprintf(user_request, "USER %s\r\n", username);
    if (send(sock, user_request, strlen(user_request), 0) == -1) {
        printf("Failed to send username");
        return 1;
    }

    // Get the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Failed to receive response for username");
        return 1;
    }
    printf("%s", buffer);

    // Prompt for password
    char password[BUFFER_SIZE];
    printf("Enter password: ");
    fgets(password, BUFFER_SIZE, stdin);
    char *newline = strchr(password, '\n');
    if (newline) {
        *newline = '\0';
    }

    // Send the password to the server
    char password_request[BUFFER_SIZE];
    sprintf(password_request, "PASS %s\r\n", password);
    if (send(sock, password_request, strlen(password_request), 0) == -1) {
        printf("Failed to send password");
        return 1;
    }

    // Get the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Failed to receive response for password");
        return 1;
    }
    printf("%s", buffer);

    // Send the quit command to the server
    char quit_request[BUFFER_SIZE];
    sprintf(quit_request, "QUIT\r\n");
    if (send(sock, quit_request, strlen(quit_request), 0) == -1) {
        printf("Failed to send quit command");
        return 1;
    }

    // Get the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        printf("Failed to receive response for quit command");
        return 1;
    }
    printf("%s", buffer);

    // Close the socket
    if (close(sock) == -1) {
        printf("Failed to close socket");
        return 1;
    }

    return 0;
}