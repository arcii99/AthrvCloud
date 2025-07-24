//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s server_address username password\n", argv[0]);
        exit(1);
    }

    // Create a socket for connecting to the server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Failed to create socket");
        exit(2);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(143);

    // Connect to the server
    if (connect(sock, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("Failed to connect to server");
        exit(3);
    }

    // Receive initial server response
    char buffer[BUFFER_SIZE];
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive initial server response");
        exit(4);
    }

    // Login to the server
    char login_command[BUFFER_SIZE];
    sprintf(login_command, "1 LOGIN %s %s\r\n", argv[2], argv[3]);
    if (send(sock, login_command, strlen(login_command), 0) == -1) {
        perror("Failed to send login command");
        exit(5);
    }

    // Receive login response
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive login response");
        exit(6);
    }

    // Check if login was successful
    if (buffer[2] != 'O' || buffer[3] != 'K') {
        printf("Failed to login: %s", buffer);
        exit(7);
    }

    // Select a mailbox
    char select_command[BUFFER_SIZE];
    sprintf(select_command, "1 SELECT INBOX\r\n");
    if (send(sock, select_command, strlen(select_command), 0) == -1) {
        perror("Failed to send select command");
        exit(8);
    }

    // Receive select response
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive select response");
        exit(9);
    }

    // Check if select was successful
    if (buffer[2] != 'O' || buffer[3] != 'K') {
        printf("Failed to select mailbox: %s", buffer);
        exit(10);
    }

    // Retrieve messages from the mailbox
    char fetch_command[BUFFER_SIZE];
    sprintf(fetch_command, "1 FETCH 1:* BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)]\r\n");
    if (send(sock, fetch_command, strlen(fetch_command), 0) == -1) {
        perror("Failed to send fetch command");
        exit(11);
    }

    // Receive message headers
    int message_count = 0;
    while (1) {
        if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
            perror("Failed to receive message headers");
            exit(12);
        }

        // Check for end of response
        if (buffer[0] == '*' && buffer[1] == ' ') {
            if (strstr(buffer, " FETCH ")) {
                message_count++;
                printf("Message %d:\n", message_count);

                // Parse message headers
                char *from = strstr(buffer, "From:");
                char *to = strstr(buffer, "To:");
                char *subject = strstr(buffer, "Subject:");
                char *date = strstr(buffer, "Date:");

                if (from && to && subject && date) {
                    printf("From: %s\n", from + 6);
                    printf("To: %s\n", to + 4);
                    printf("Subject: %s\n", subject + 9);
                    printf("Date: %s\n", date + 6);
                }
                printf("\n");
            }
        } else if (buffer[0] == '1' && buffer[1] == ' ' && buffer[2] == 'O' && buffer[3] == 'K') {
            break;
        }
    }

    // Logout from the server
    char logout_command[BUFFER_SIZE];
    sprintf(logout_command, "1 LOGOUT\r\n");
    if (send(sock, logout_command, strlen(logout_command), 0) == -1) {
        perror("Failed to send logout command");
        exit(13);
    }

    // Receive logout response
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive logout response");
        exit(14);
    }

    // Close the socket
    close(sock);

    return 0;
}