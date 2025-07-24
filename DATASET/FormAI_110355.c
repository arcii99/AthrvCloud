//FormAI DATASET v1.0 Category: Chat server ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_PENDING 5
#define MAX_DATA_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_DATA_SIZE] = {0};
    char welcome_message[] = "Welcome to the Genius Chatroom!\n";

    // Create a new socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to a port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_PENDING) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for incoming connections...\n");
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        printf("Connection established from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        send(new_socket, welcome_message, strlen(welcome_message), 0);

        // Handle communication with the client
        while (1) {
            int bytes_received = recv(new_socket, buffer, MAX_DATA_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                close(new_socket);
                break;
            }
            printf("Message received from %s:%d: ", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            printf("%s\n", buffer);
            memset(buffer, 0, MAX_DATA_SIZE);
        }
    }
    return 0;
}