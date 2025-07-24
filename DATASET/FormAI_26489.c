//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

void *communication_handler(void *arg){
    int new_socket = *((int *) arg);
    char buffer[BUFFER_SIZE] = {0};

    // Send welcome message to client
    char *welcome_message = "Welcome to the TCP/IP server!\n";
    send(new_socket, welcome_message, strlen(welcome_message), 0);

    // Receive messages from client
    while (1){
        memset(buffer, 0, BUFFER_SIZE);
        int read_val = read(new_socket, buffer, BUFFER_SIZE);
        if (read_val <= 0){
            printf("Client disconnected!\n");
            break;
        }

        printf("Received message: %s", buffer);

        // Echo message back to client
        send(new_socket, buffer, strlen(buffer), 0);
    }

    close(new_socket);
    pthread_exit(NULL);
}

int main(int argc, char **argv){
    int server_fd;
    struct sockaddr_in address;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket failed!");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                               &opt, sizeof(opt))){
        perror("Setsockopt failed!");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("Bind failed!");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0){
        perror("Listen failed!");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d...\n", PORT);

    // Accept incoming connections
    struct sockaddr_in client_address;
    int addr_len = sizeof(client_address);
    int new_socket;
    pthread_t thread_id;

    while (1){
        if ((new_socket = accept(server_fd,
                                 (struct sockaddr *)&client_address,
                                 (socklen_t*)&addr_len)) < 0){
            perror("Accept failed!");
            exit(EXIT_FAILURE);
        }

        printf("New client connected!\n");

        if (pthread_create(&thread_id, NULL, communication_handler, 
                                        (void *)&new_socket) != 0){
            perror("Thread creation failed!");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}