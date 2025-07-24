//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

const char* server_address = "imap.gmail.com";
const int server_port = 993;
char recv_buffer[2048] = {0};

int main(int argc, char *argv[]) {
    int sock = 0, i = 0, j = 0;
    struct sockaddr_in server;
    char username[100] = {0};
    char password[100] = {0};
    char command[200] = {0};
    char email_data[1000] = {0};
    char *result = NULL;
    char *ptr = NULL;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    memset(&server, '0', sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_address, &server.sin_addr) <= 0) {
        printf("Invalid address or address not supported.\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed.\n");
        exit(EXIT_FAILURE);
    }

    // Receive server greeting
    read(sock, recv_buffer, sizeof(recv_buffer));
    printf("%s", recv_buffer);

    // Send login command
    printf("Enter your email address: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    snprintf(command, sizeof(command), "LOGIN %s %s\r\n", username, password);
    send(sock, command, strlen(command), 0);

    // Receive login result
    read(sock, recv_buffer, sizeof(recv_buffer));
    result = strtok_r(recv_buffer, " \r\n", &ptr);
    if (strcmp(result, "*") == 0) {
        result = strtok_r(NULL, " \r\n", &ptr);
        if (strcmp(result, "OK") == 0) {
            printf("Login successful.\n");
        } else {
            printf("Login failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Send select inbox command
    snprintf(command, sizeof(command), "SELECT INBOX\r\n");
    send(sock, command, strlen(command), 0);

    // Receive select inbox result
    read(sock, recv_buffer, sizeof(recv_buffer));
    printf("%s", recv_buffer);

    // Send fetch command
    snprintf(command, sizeof(command), "FETCH 1 FULL\r\n");
    send(sock, command, strlen(command), 0);

    // Receive fetch result
    while (1) {
        memset(recv_buffer, 0, sizeof(recv_buffer));
        i = read(sock, recv_buffer, sizeof(recv_buffer));
        if (i <= 0) {
            break;
        }
        strcat(email_data, recv_buffer);
    }
    printf("%s", email_data);

    // Close socket
    close(sock);

    return 0;
}