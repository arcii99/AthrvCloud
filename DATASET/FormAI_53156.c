//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) 
{
    if (argc != 4) {
        printf("Usage: %s <IMAP server> <username> <password>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(993);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Receive initial greeting message from server
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send login command to server
    sprintf(buffer, "1 LOGIN %s %s\r\n", username, password);
    if (send(sock, buffer, strlen(buffer), 0) != strlen(buffer)) {
        perror("Error sending command to server");
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);

    // Receive OK message from server
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send select command to server to choose inbox folder
    sprintf(buffer, "2 SELECT INBOX\r\n");
    if (send(sock, buffer, strlen(buffer), 0) != strlen(buffer)) {
        perror("Error sending command to server");
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);

    // Receive OK message from server
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send list command to server to get list of emails in inbox
    sprintf(buffer, "3 UID SEARCH ALL\r\n");
    if (send(sock, buffer, strlen(buffer), 0) != strlen(buffer)) {
        perror("Error sending command to server");
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);

    // Receive list of emails from server
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send logout command to server
    sprintf(buffer, "4 LOGOUT\r\n");
    if (send(sock, buffer, strlen(buffer), 0) != strlen(buffer)) {
        perror("Error sending command to server");
        return 1;
    }

    return 0;
}