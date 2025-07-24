//FormAI DATASET v1.0 Category: Chat server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 30

int clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast(char *message, int sender_fd) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] > 0 && clients[i] != sender_fd) {
            send(clients[i], message, strlen(message), 0);
        }
    }
}

void handle_client(int client_fd) {
    char buffer[1024] = { 0 };
    while (true) {
        int bytes = recv(client_fd, buffer, sizeof(buffer), 0);
        if (bytes < 0) {
            printf("Error receiving message from client\n");
            break;
        }
        if (bytes == 0) {
            printf("Client disconnected\n");
            break;
        }
        buffer[bytes] = '\0';
        printf("Received message from client: %s\n", buffer);
        broadcast(buffer, client_fd);
    }
    close(client_fd);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i] = -1;
    }

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        if (num_clients < MAX_CLIENTS) {
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i] == -1) {
                    clients[i] = new_socket;
                    num_clients++;
                    break;
                }
            }
            
            char *welcome_msg = "Welcome to the chat!\n";
            send(new_socket, welcome_msg, strlen(welcome_msg), 0);

            handle_client(new_socket);
        } else {
            char *full_msg = "Sorry, server is full\n";
            send(new_socket, full_msg, strlen(full_msg), 0);
            close(new_socket);
        }
    }

    return 0;
}