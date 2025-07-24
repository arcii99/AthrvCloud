//FormAI DATASET v1.0 Category: Client Server Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>

#define PORT 8080

void *connection_handler(void *);

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, i;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    pthread_t threads[4];

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening on the socket
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Handle incoming connections
    for (i = 0; i < 4; i++) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        if (pthread_create(&threads[i], NULL, connection_handler, (void *)&new_socket) < 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }

        printf("Thread %d created to handle connection.\n", i+1);
    }

    for (i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *connection_handler(void *socket_desc) {
    int sock = *(int*)socket_desc;
    char *message, buffer[1024];
    int read_len;

    message = "Connection accepted\n";
    write(sock, message, strlen(message));

    while ((read_len = recv(sock, buffer, 1024, 0)) > 0) {
        buffer[read_len] = '\0';
        printf("Client message: %s\n", buffer);
        write(sock, buffer, strlen(buffer));
    }

    if (read_len == 0) {
        printf("Client disconnected\n");
    }
    else if (read_len == -1) {
        perror("Recv failed");
    }

    close(sock);
    pthread_exit(NULL);
}