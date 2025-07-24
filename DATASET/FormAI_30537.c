//FormAI DATASET v1.0 Category: Email Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 5000
#define MAX_BUFFER_SIZE 1024

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(SERVER_IP);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Could not connect to server");
        exit(1);
    }

    char username[MAX_BUFFER_SIZE];
    char password[MAX_BUFFER_SIZE];

    printf("Username: ");
    fgets(username, MAX_BUFFER_SIZE, stdin);
    strtok(username, "\n");

    printf("Password: ");
    fgets(password, MAX_BUFFER_SIZE, stdin);
    strtok(password, "\n");

    char auth_message[MAX_BUFFER_SIZE];
    snprintf(auth_message, MAX_BUFFER_SIZE, "AUTH %s:%s\n", username, password);

    if (send(sock, auth_message, strlen(auth_message), 0) < 0) {
        printf("Could not send authentication message");
        exit(1);
    }

    char response[MAX_BUFFER_SIZE];
    if (recv(sock, response, MAX_BUFFER_SIZE, 0) < 0) {
        printf("Could not receive response from server");
        exit(1);
    }

    printf("Server response: %s\n", response);

    char email_from[MAX_BUFFER_SIZE];
    char email_to[MAX_BUFFER_SIZE];
    char email_subject[MAX_BUFFER_SIZE];
    char email_body[MAX_BUFFER_SIZE];

    printf("From: ");
    fgets(email_from, MAX_BUFFER_SIZE, stdin);
    strtok(email_from, "\n");

    printf("To: ");
    fgets(email_to, MAX_BUFFER_SIZE, stdin);
    strtok(email_to, "\n");

    printf("Subject: ");
    fgets(email_subject, MAX_BUFFER_SIZE, stdin);
    strtok(email_subject, "\n");

    printf("Body: ");
    fgets(email_body, MAX_BUFFER_SIZE, stdin);
    strtok(email_body, "\n");

    char email_message[MAX_BUFFER_SIZE];
    snprintf(email_message, MAX_BUFFER_SIZE, "FROM:%s\nTO:%s\nSUBJECT:%s\n%s\n", email_from, email_to, email_subject, email_body);

    if (send(sock, email_message, strlen(email_message), 0) < 0) {
        printf("Could not send email");
        exit(1);
    }

    printf("Email sent successfully");

    close(sock);

    return 0;
}