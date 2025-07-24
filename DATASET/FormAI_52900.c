//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    char *username, *password;
    char *server_address;
    int socket_desc;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE] = {0};

    if (argc < 4) {
        printf("Usage: %s username password server_address\n", argv[0]);
        return 1;
    }

    username = argv[1];
    password = argv[2];
    server_address = argv[3];

    // create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        perror("Error creating socket");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(POP3_PORT);

    // connect to the server
    if (connect(socket_desc, (struct sockaddr *)&server , sizeof(server)) == -1) {
        perror("Error connecting to server");
        return 1;
    }

    printf("Connected to the server\n");

    // receive greeting message
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving greeting message");
        return 1;
    }

    printf("Greeting message received: %s\n", buffer);

    // send username
    sprintf(buffer, "USER %s\r\n", username);
    if (send(socket_desc, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending username");
        return 1;
    }

    // receive response to username
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response to username");
        return 1;
    }

    printf("Response to username received: %s\n", buffer);

    // send password
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(socket_desc, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending password");
        return 1;
    }

    // receive response to password
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response to password");
        return 1;
    }

    printf("Response to password received: %s\n", buffer);

    // send command to list all messages
    sprintf(buffer, "LIST\r\n");
    if (send(socket_desc, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending LIST command");
        return 1;
    }

    // receive response to LIST command
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response to LIST command");
        return 1;
    }

    printf("Response to LIST command received: %s\n", buffer);

    // send command to retrieve message
    sprintf(buffer, "RETR 1\r\n");
    if (send(socket_desc, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending RETR command");
        return 1;
    }

    // receive response to RETR command
    if (recv(socket_desc, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response to RETR command");
        return 1;
    }

    printf("Response to RETR command received: %s\n", buffer);

    close(socket_desc);

    return 0;
}