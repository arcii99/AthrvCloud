//FormAI DATASET v1.0 Category: Networking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

void *client_handler(void *arg) {
    int sockfd = *(int*)arg;
    char buffer[1024] = {0};
    int valread;

    while ((valread = read(sockfd, buffer, 1024)) > 0) {
        printf("Message from client: %s\n", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    return NULL;
}

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char *hello = "Hello from server";
    pthread_t client_thread;

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options for server socket
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind server socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection and create new socket for client
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Connection established with client %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    // Create new thread to handle incoming data from client
    if (pthread_create(&client_thread, NULL, client_handler, (void*)&new_socket) < 0) {
        perror("thread create");
        exit(EXIT_FAILURE);
    }

    // Send message to client
    send(new_socket, hello, strlen(hello), 0);
    printf("Message sent to client\n");

    // Wait for thread to finish
    if (pthread_join(client_thread, NULL) < 0) {
        perror("thread join");
        exit(EXIT_FAILURE);
    }

    // Close server socket
    close(server_fd);

    return 0;
}