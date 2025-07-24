//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFF_SIZE 2048

// Set up an IMAP command
void setup_command(char *buff, const char *command, const char *arg1, const char *arg2) {
    if (arg1 == NULL && arg2 == NULL) {
        sprintf(buff, "%s\r\n", command);
    } else if (arg2 == NULL) {
        sprintf(buff, "%s %s\r\n", command, arg1);
    } else {
        sprintf(buff, "%s %s %s\r\n", command, arg1, arg2);
    }
}

int main() {
    // Connect to an IMAP server
    int sock;
    struct sockaddr_in server;
    char response[BUFF_SIZE];
    char command[BUFF_SIZE];
    char username[BUFF_SIZE];
    char password[BUFF_SIZE];
    memset(&server, 0, sizeof(server));
    memset(response, 0, sizeof(response));
    memset(command, 0, sizeof(command));
    memset(username, 0, sizeof(username));
    memset(password, 0, sizeof(password));
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(993);
    server.sin_addr.s_addr = inet_addr("192.0.2.1");
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    // Receive server introduction
    if (recv(sock, response, BUFF_SIZE, 0) < 0) {
        perror("Failed to receive server introduction");
        close(sock);
        exit(1);
    }
    printf("%s", response);

    // Login to the server
    printf("Enter your username: ");
    fgets(username, BUFF_SIZE, stdin);
    username[strcspn(username, "\n")] = '\0';
    printf("Enter your password: ");
    fgets(password, BUFF_SIZE, stdin);
    password[strcspn(password, "\n")] = '\0';
    setup_command(command, "LOGIN", username, password);
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Failed to send LOGIN command");
        close(sock);
        exit(1);
    }
    if (recv(sock, response, BUFF_SIZE, 0) < 0) {
        perror("Failed to receive LOGIN response");
        close(sock);
        exit(1);
    }
    printf("%s", response);

    // Select a mailbox
    setup_command(command, "SELECT", "INBOX", NULL);
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Failed to send SELECT command");
        close(sock);
        exit(1);
    }
    if (recv(sock, response, BUFF_SIZE, 0) < 0) {
        perror("Failed to receive SELECT response");
        close(sock);
        exit(1);
    }
    printf("%s", response);

    // Fetch messages
    setup_command(command, "FETCH", "1:*", "BODY[HEADER.FIELDS (FROM SUBJECT)]");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Failed to send FETCH command");
        close(sock);
        exit(1);
    }
    if (recv(sock, response, BUFF_SIZE, 0) < 0) {
        perror("Failed to receive FETCH response");
        close(sock);
        exit(1);
    }
    printf("%s", response);

    // Logout from the server
    setup_command(command, "LOGOUT", NULL, NULL);
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("Failed to send LOGOUT command");
        close(sock);
        exit(1);
    }
    if (recv(sock, response, BUFF_SIZE, 0) < 0) {
        perror("Failed to receive LOGOUT response");
        close(sock);
        exit(1);
    }
    printf("%s", response);

    // Close the socket
    close(sock);
    return 0;
}