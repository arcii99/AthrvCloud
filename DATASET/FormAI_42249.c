//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define PORT 110

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char username[BUFF_SIZE], password[BUFF_SIZE], command[BUFF_SIZE], response[BUFF_SIZE];

    // Input user's username and password
    printf("POP3 Server Login\n");
    printf("Username: ");
    fgets(username, BUFF_SIZE, stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline character
    printf("Password: ");
    fgets(password, BUFF_SIZE, stdin);
    password[strcspn(password, "\n")] = 0;

    // Create TCP socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Could not create socket.\n");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connect failed.\n");
        exit(EXIT_FAILURE);
    }

    // Receive greeting message from server
    memset(response, 0, sizeof(response));
    if (recv(sock, response, BUFF_SIZE, 0) < 0) {
        printf("Receive failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", response);

    // Send login information to server
    sprintf(command, "USER %s\r\n", username);
    if (send(sock, command, strlen(command), 0) < 0) {
        printf("Send failed.\n");
        exit(EXIT_FAILURE);
    }
    memset(response, 0, sizeof(response));
    if (recv(sock, response, BUFF_SIZE, 0) < 0) {
        printf("Receive failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", response);

    sprintf(command, "PASS %s\r\n", password);
    if (send(sock, command, strlen(command), 0) < 0) {
        printf("Send failed.\n");
        exit(EXIT_FAILURE);
    }
    memset(response, 0, sizeof(response));
    if (recv(sock, response, BUFF_SIZE, 0) < 0) {
        printf("Receive failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", response);

    // List all emails
    printf("Listing all emails:\n");
    sprintf(command, "LIST\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        printf("Send failed.\n");
        exit(EXIT_FAILURE);
    }
    while (1) {
        memset(response, 0, sizeof(response));
        if (recv(sock, response, BUFF_SIZE, 0) < 0) {
            printf("Receive failed.\n");
            exit(EXIT_FAILURE);
        }
        if (strcmp(response, ".\r\n") == 0) break; // End of email list
        printf("%s", response);
    }

    // Retrieve email with ID 1
    printf("Retrieving email with ID 1\n");
    sprintf(command, "RETR 1\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        printf("Send failed.\n");
        exit(EXIT_FAILURE);
    }
    while (1) {
        memset(response, 0, sizeof(response));
        if (recv(sock, response, BUFF_SIZE, 0) < 0) {
            printf("Receive failed.\n");
            exit(EXIT_FAILURE);
        }
        if (strcmp(response, ".\r\n") == 0) break; // End of email
        printf("%s", response);
    }

    // Delete email with ID 1
    printf("Deleting email with ID 1\n");
    sprintf(command, "DELE 1\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        printf("Send failed.\n");
        exit(EXIT_FAILURE);
    }
    memset(response, 0, sizeof(response));
    if (recv(sock, response, BUFF_SIZE, 0) < 0) {
        printf("Receive failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", response);

    // Logout
    printf("Closing connection.\n");
    sprintf(command, "QUIT\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        printf("Send failed.\n");
        exit(EXIT_FAILURE);
    }
    memset(response, 0, sizeof(response));
    if (recv(sock, response, BUFF_SIZE, 0) < 0) {
        printf("Receive failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", response);

    close(sock);
    return 0;
}