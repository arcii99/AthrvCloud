//FormAI DATASET v1.0 Category: Client Server Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9000
#define MAX_MSG_SIZE 1024

void handle_client(int client_socket);

int main(int argc, char* argv[]) {
    struct sockaddr_in server_addr;
    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_socket, 5) < 0) {
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);
        int client_socket = accept(listen_socket,
                                  (struct sockaddr*)&client_addr,
                                  &client_addr_size);

        if (client_socket < 0) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }

        printf("Handling client at %s:%d\n", 
               inet_ntoa(client_addr.sin_addr),
               ntohs(client_addr.sin_port));

        handle_client(client_socket);
    }

    close(listen_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[MAX_MSG_SIZE];
    int bytes_received = recv(client_socket, buffer, MAX_MSG_SIZE, 0);

    if (bytes_received < 0) {
        perror("Failed to receive message from client");
        exit(EXIT_FAILURE);
    }

    printf("Received message from client: %s\n", buffer);

    const char* response = "Greetings traveler! Welcome to the kingdom of Camelot!\n";
    int bytes_sent = send(client_socket, response, strlen(response), 0);

    if (bytes_sent < 0) {
        perror("Failed to send message to client");
        exit(EXIT_FAILURE);
    }

    close(client_socket);
}