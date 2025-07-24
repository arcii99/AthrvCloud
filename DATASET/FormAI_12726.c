//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char const *argv[]) {
    char* host = "pop.example.com"; // replace with your POP3 server
    char* username = "username"; // replace with your username
    char* password = "password"; // replace with your password

    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("error creating socket");
        exit(EXIT_FAILURE);
    }

    // create server address struct
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        perror("error converting server address");
        exit(EXIT_FAILURE);
    }

    // connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("error connecting to server");
        exit(EXIT_FAILURE);
    }

    // read welcome message from server
    char buffer[BUFFER_SIZE];
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("error receiving message");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    // send login information to server
    char login_str[BUFFER_SIZE];
    sprintf(login_str, "USER %s\r\n", username);
    if (send(sock, login_str, strlen(login_str), 0) == -1) {
        perror("error sending message");
        exit(EXIT_FAILURE);
    }
    printf("Client: %s", login_str);

    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("error receiving message");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    sprintf(login_str, "PASS %s\r\n", password);
    if (send(sock, login_str, strlen(login_str), 0) == -1) {
        perror("error sending message");
        exit(EXIT_FAILURE);
    }
    printf("Client: %s", login_str);

    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("error receiving message");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    // get mailbox status
    if (send(sock, "STAT\r\n", strlen("STAT\r\n"), 0) == -1) {
        perror("error sending message");
        exit(EXIT_FAILURE);
    }
    printf("Client: STAT\r\n");

    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("error receiving message");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    // fetch email headers
    if (send(sock, "TOP 1 0\r\n", strlen("TOP 1 0\r\n"), 0) == -1) {
        perror("error sending message");
        exit(EXIT_FAILURE);
    }

    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("error receiving message");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    // close connection
    if (send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0) == -1) {
        perror("error sending message");
        exit(EXIT_FAILURE);
    }

    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("error receiving message");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    if (close(sock) == -1) {
        perror("error closing socket");
        exit(EXIT_FAILURE);
    }

    return 0;
}