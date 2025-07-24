//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {

    char *server_address = "pop.example.com";
    int server_port = 110;

    // Create a TCP socket
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Set up server address structure
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(server_port);

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    char buffer[MAX_LENGTH];
    memset(buffer, 0, MAX_LENGTH);

    // Receive server response
    if (recv(socket_desc, buffer, MAX_LENGTH, 0) < 0) {
        printf("recv failed");
        return 1;
    }

    printf("%s", buffer);

    // Send username
    char *username = "username";
    memset(buffer, 0, MAX_LENGTH);
    sprintf(buffer, "USER %s\r\n", username);

    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("send failed");
        return 1;
    }

    memset(buffer, 0, MAX_LENGTH);

    // Receive server response
    if (recv(socket_desc, buffer, MAX_LENGTH, 0) < 0) {
        printf("recv failed");
        return 1;
    }

    printf("%s", buffer);

    // Send password
    char *password = "password";
    memset(buffer, 0, MAX_LENGTH);
    sprintf(buffer, "PASS %s\r\n", password);

    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("send failed");
        return 1;
    }

    memset(buffer, 0, MAX_LENGTH);

    // Receive server response
    if (recv(socket_desc, buffer, MAX_LENGTH, 0) < 0) {
        printf("recv failed");
        return 1;
    }

    printf("%s", buffer);

    // Send command to list all messages
    memset(buffer, 0, MAX_LENGTH);
    sprintf(buffer, "LIST\r\n");

    if (send(socket_desc, buffer, strlen(buffer), 0) < 0) {
        printf("send failed");
        return 1;
    }

    memset(buffer, 0, MAX_LENGTH);

    // Receive server response
    if (recv(socket_desc, buffer, MAX_LENGTH, 0) < 0) {
        printf("recv failed");
        return 1;
    }

    printf("%s", buffer);

    // Close socket and exit
    close(socket_desc);
    return 0;
}