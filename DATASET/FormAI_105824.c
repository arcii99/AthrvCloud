//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char recv_buffer[MAX_SIZE], send_buffer[MAX_SIZE];

    // create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return EXIT_FAILURE;
    }

    // initialize server address and port
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(110);

    // connect to POP3 server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connection failed");
        return EXIT_FAILURE;
    }
    
    // receive server greeting
    memset(recv_buffer, 0, MAX_SIZE);
    if (read(sock, recv_buffer, MAX_SIZE) < 0) {
        perror("read failed");
        return EXIT_FAILURE;
    }
    printf("%s", recv_buffer);

    // send user command
    memset(send_buffer, 0, MAX_SIZE);
    printf("Username: ");
    fgets(send_buffer, MAX_SIZE - 1, stdin);
    send_buffer[strlen(send_buffer) - 1] = '\0'; // remove newline character
    strcat(send_buffer, "\r\n");
    write(sock, send_buffer, strlen(send_buffer));
    
    // receive user OK response
    memset(recv_buffer, 0, MAX_SIZE);
    if (read(sock, recv_buffer, MAX_SIZE) < 0) {
        perror("read failed");
        return EXIT_FAILURE;
    }
    printf("%s", recv_buffer);

    // send password command
    memset(send_buffer, 0, MAX_SIZE);
    printf("Password: ");
    fgets(send_buffer, MAX_SIZE - 1, stdin);
    send_buffer[strlen(send_buffer) - 1] = '\0'; // remove newline character
    strcat(send_buffer, "\r\n");
    write(sock, send_buffer, strlen(send_buffer));
    
    // receive password OK response
    memset(recv_buffer, 0, MAX_SIZE);
    if (read(sock, recv_buffer, MAX_SIZE) < 0) {
        perror("read failed");
        return EXIT_FAILURE;
    }
    printf("%s", recv_buffer);

    // send list command
    write(sock, "LIST\r\n", strlen("LIST\r\n"));
    
    // receive list response
    memset(recv_buffer, 0, MAX_SIZE);
    if (read(sock, recv_buffer, MAX_SIZE) < 0) {
        perror("read failed");
        return EXIT_FAILURE;
    }
    printf("%s", recv_buffer);

    // close socket
    close(sock);

    return EXIT_SUCCESS;
}