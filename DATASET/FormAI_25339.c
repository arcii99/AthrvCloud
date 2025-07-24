//FormAI DATASET v1.0 Category: Networking ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 5555
#define MAX_BUFFER_SIZE 1024

struct message {
    char id[10];
    char content[MAX_BUFFER_SIZE];
};

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create server socket");
        return -1;
    }

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind server socket");
        return -1;
    }

    if (listen(server_socket, 1) < 0) {
        perror("Failed to listen on server socket");
        return -1;
    }

    printf("Waiting for client connection on port %d...\n", PORT);

    while (1) {
        int client_address_length = sizeof(client_address);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_length)) < 0) {
            perror("Failed to accept client connection");
            return -1;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        struct message msg;
        memset(&msg, 0, sizeof(msg));
        if (recv(client_socket, (void *)&msg, sizeof(msg), 0) < 0) {
            perror("Failed to receive message from client");
            close(client_socket);
            continue;
        }

        printf("Received message from client %s: %s\n", msg.id, msg.content);

        // Some futuristic processing on the message content
        for (int i = 0; i < strlen(msg.content); i++) {
            if (msg.content[i] == ' ') {
                msg.content[i] = '-';
            } else {
                msg.content[i] += 1;
            }
        }

        if (send(client_socket, (void *)&msg, sizeof(msg), 0) < 0) {
            perror("Failed to send message to client");
        } else {
            printf("Sent processed message to client: %s\n", msg.content);
        }

        close(client_socket);
    }

    close(server_socket);

    return 0;
}