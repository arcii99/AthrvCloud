//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 2048

// Function to validate server response and return its status code
int get_response_code(char *response) {
    char code[4];
    memcpy(code, response, 3);
    code[3] = '\0';
    return atoi(code);
}

int main() {
    // Connect to IMAP server
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(993);
    server_address.sin_addr.s_addr = inet_addr("imap.example.com");
    connect(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address));

    // Receive server greeting
    char buffer[BUFFER_SIZE] = {0};
    recv(sock_fd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Perform IMAP login
    char username[] = "exampleuser";
    char password[] = "examplepass";
    char login_command[BUFFER_SIZE] = {0};
    sprintf(login_command, "LOGIN %s %s\r\n", username, password);
    send(sock_fd, login_command, strlen(login_command), 0);
    recv(sock_fd, buffer, BUFFER_SIZE, 0);
    int response_code = get_response_code(buffer);
    if (response_code != 0) {
        printf("Error: Login failed. Server returned code %d\n", response_code);
        exit(1);
    }
    printf("Successful login\n");

    // Display inbox messages
    char inbox_command[] = "SELECT INBOX\r\n";
    send(sock_fd, inbox_command, strlen(inbox_command), 0);
    recv(sock_fd, buffer, BUFFER_SIZE, 0);
    response_code = get_response_code(buffer);
    if (response_code != 0) {
        printf("Error: Failed to select inbox. Server returned code %d\n", response_code);
        exit(1);
    }
    printf("Successfully selected inbox\n");

    char fetch_command[] = "FETCH 1:* (BODY[HEADER.FIELDS (FROM SUBJECT DATE)])\r\n";
    send(sock_fd, fetch_command, strlen(fetch_command), 0);
    while (true) {
        recv(sock_fd, buffer, BUFFER_SIZE, 0);
        response_code = get_response_code(buffer);
        if (response_code == 1) {
            break;
        }
        printf("%s", buffer);
    }

    // Logout and close connection
    char logout_command[] = "LOGOUT\r\n";
    send(sock_fd, logout_command, strlen(logout_command), 0);
    recv(sock_fd, buffer, BUFFER_SIZE, 0);
    response_code = get_response_code(buffer);
    if (response_code != 0) {
        printf("Error: Logout failed. Server returned code %d\n", response_code);
        exit(1);
    }
    printf("Successful logout\n");

    close(sock_fd);

    return 0;
}