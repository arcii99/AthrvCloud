//FormAI DATASET v1.0 Category: Chat server ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *handle_client(void *arg) {
    int socket_fd = *(int*)arg;
    char buffer[BUFFER_SIZE];
    int read_bytes;

    while(1) {
        read_bytes = recv(socket_fd, buffer, BUFFER_SIZE, 0);
        if(read_bytes < 0) {
            printf("Error reading from client %d, closing connection.\n", socket_fd);
            close(socket_fd);
            return NULL;
        }
        if(read_bytes == 0) {
            printf("Client %d disconnected.\n", socket_fd);
            close(socket_fd);
            return NULL;
        }

        printf("Received message from client %d: %s", socket_fd, buffer);
        strcpy(buffer, "Thanks for your message!");
        send(socket_fd, buffer, strlen(buffer), 0);
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_address, client_address;
    int addrlen = sizeof(server_address);

    // Create socket file descriptor
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int option = 1;
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) < 0) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if(bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if(listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while(1) {
        // Accept incoming connection
        if((new_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Connection established with client %d.\n", new_socket);

        // Create a new thread to handle the client
        pthread_t thread_id;
        if(pthread_create(&thread_id, NULL, handle_client, (void*)&new_socket) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}