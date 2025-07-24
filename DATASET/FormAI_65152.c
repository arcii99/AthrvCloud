//FormAI DATASET v1.0 Category: Chat server ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 256

int clients_count = 0;
int clients[MAX_CLIENTS];

void process_message(int sender, char* message) {
    for (int i = 0; i < clients_count; i++) {
        if (clients[i] != sender) {
            send(clients[i], message, strlen(message), 0);
        }
    }
}

void handle_connection(int client_sock, struct sockaddr_in client_addr) {
    clients[clients_count] = client_sock;
    clients_count++;

    printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    char message[MAX_MESSAGE_LENGTH];

    while (recv(client_sock, message, MAX_MESSAGE_LENGTH, 0) > 0) {
        printf("%s:%d: %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), message);
        process_message(client_sock, message);

        memset(message, 0, sizeof(message));
    }

    for (int i = 0; i < clients_count; i++) {
        if (clients[i] == client_sock) {
            clients[i] = clients[clients_count - 1];
            clients_count--;
        }
    }

    printf("Client disconnected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    close(client_sock);
}

int main(int argc, char* argv[]) {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket to port");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, 1) < 0) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", ntohs(server_addr.sin_port));

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_len);

        if (client_sock < 0) {
            perror("Failed to accept connection");
            continue;
        }

        handle_connection(client_sock, client_addr);
    }

    close(server_sock);
    return 0;
}