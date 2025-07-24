//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUF_SIZE 1024
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    int client_sock, server_sock, len;
    char buf[MAX_BUF_SIZE];
    struct sockaddr_in server_addr, client_addr;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Failed to create socket.");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket.");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, 1) == -1) {
        perror("Failed to listen on socket.");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int client_len = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, (socklen_t *)&client_len);
        if (client_sock == -1) {
            perror("Failed to accept connection.");
            exit(EXIT_FAILURE);
        }

        if (fork() == 0) { // child process
            close(server_sock);
            memset(buf, 0, MAX_BUF_SIZE);
            len = recv(client_sock, buf, MAX_BUF_SIZE, 0);
            if (len == -1) {
                perror("Failed to receive data from client.");
                exit(EXIT_FAILURE);
            } else if (len == 0) {
                printf("Client disconnected.\n");
                exit(EXIT_SUCCESS);
            }

            printf("Received from client: %s\n", buf);

            // Forward the request to the real server
            int server_sock = socket(AF_INET, SOCK_STREAM, 0);
            if (server_sock == -1) {
                perror("Failed to create socket.");
                exit(EXIT_FAILURE);
            }

            if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
                perror("Failed to connect to server.");
                exit(EXIT_FAILURE);
            }

            if (send(server_sock, buf, strlen(buf), 0) == -1) {
                perror("Failed to send data to server.");
                exit(EXIT_FAILURE);
            }

            // Receive the response from the real server and forward it to the client
            memset(buf, 0, MAX_BUF_SIZE);
            len = recv(server_sock, buf, MAX_BUF_SIZE, 0);
            if (len == -1) {
                perror("Failed to receive data from server.");
                exit(EXIT_FAILURE);
            } else if (len == 0) {
                printf("Server disconnected.\n");
                exit(EXIT_SUCCESS);
            }

            printf("Received from server: %s\n", buf);

            if (send(client_sock, buf, strlen(buf), 0) == -1) {
                perror("Failed to send data to client.");
                exit(EXIT_FAILURE);
            }

            close(client_sock);
            close(server_sock);
            exit(EXIT_SUCCESS);
        } else {
            close(client_sock);
        }
    }

    close(server_sock);
    return 0;
}