//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define LISTEN_PORT 8888
#define MAX_BUFF_SIZE 1024

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {0};
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(LISTEN_PORT);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, 5) < 0) {
        perror("Failed to listen");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in client_addr = {0};
    int client_sock, addr_size = sizeof(client_addr);
    char buffer[MAX_BUFF_SIZE] = {0};
    bool is_valid_request = false;
    while(true) {
        memset(buffer, 0, sizeof(buffer));
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, (socklen_t*)&addr_size);
        if (client_sock < 0) {
            perror("Failed to accept connection");
            continue;
        }

        int rcv_size = recv(client_sock, buffer, sizeof(buffer), 0);
        if (rcv_size < 0) {
            perror("Failed to receive data from client");
            continue;
        }

        char* request_end = strstr(buffer, "\r\n");
        if (request_end != NULL) {
            is_valid_request = true;
            *request_end = '\0';
        }

        printf("Received request: %s\n", buffer);

        if (!is_valid_request) {
            send(client_sock, "Invalid Request", strlen("Invalid Request"), 0);
        } else {
            char* request_method = strtok(buffer, " ");
            char* request_uri = strtok(NULL, " ");
            strtok(NULL, " "); // Skip HTTP version

            // Forward the request to the target server
            int target_sock = socket(AF_INET, SOCK_STREAM, 0);
            if (target_sock == -1) {
                perror("Failed to create target socket");
                close(client_sock);
                continue;
            }

            struct sockaddr_in target_addr = {0};
            target_addr.sin_addr.s_addr = inet_addr(request_uri);
            target_addr.sin_family = AF_INET;
            target_addr.sin_port = htons(80);

            if (connect(target_sock, (struct sockaddr*)&target_addr, sizeof(target_addr)) < 0) {
                perror("Failed to connect to target server");
                close(client_sock);
                close(target_sock);
                continue;
            }

            // Forward the request
            send(target_sock, buffer, strlen(buffer), 0);

            // Forward the response from target server
            while((rcv_size = recv(target_sock, buffer, sizeof(buffer), 0)) > 0) {
                send(client_sock, buffer, rcv_size, 0);
            }

            close(target_sock);
        }

        close(client_sock);
        is_valid_request = false;
    }

    close(server_sock);
    return 0;
}