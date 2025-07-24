//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: multiplayer
/*
SMTP Client Example Program

This program allows multiple users to send emails through a SMTP server in a chatroom-style environment.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 25
#define MAX_USERS 10
#define MAX_MSG_LEN 1024

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char msg[MAX_MSG_LEN];
    char username[20];
    char email[MAX_MSG_LEN];

    // Establish connection to server
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Request username from user
    printf("Enter your username: ");
    fgets(username, 20, stdin);
    strtok(username, "\n");

    // Enter chatroom
    printf("\nWelcome to the chatroom, %s! You can start sending emails.\n", username);
    while (1) {
        // Request email message from user
        printf("\nEnter email message: ");
        fgets(msg, MAX_MSG_LEN, stdin);
        strtok(msg, "\n");

        // Format email with sender and message
        sprintf(email, "From: %s\n\n%s", username, msg);

        // Send email to server
        if (send(sock, email, strlen(email), 0) == -1) {
            printf("Error sending email\n");
            close(sock);
            exit(EXIT_FAILURE);
        }

        // Wait for response from server
        if (recv(sock, msg, MAX_MSG_LEN, 0) == -1) {
            printf("Error receiving response\n");
            close(sock);
            exit(EXIT_FAILURE);
        }

        // Display server response
        printf("Server Response: %s\n", msg);
    }

    close(sock);
    return 0;
}