//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define CLIENT_COUNT 3

// Function that runs inside each thread to send and receive messages
void monitor_thread(int client_socket) {

    while(1) {
        // Receive data from the client
        char buffer[256] = { 0 };
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received < 0) {
            perror("recv error");
            return;
        }

        // Send data to the client
        int bytes_sent = send(client_socket, buffer, bytes_received, 0);
        if (bytes_sent < 0) {
            perror("send error");
            return;
        }

        // Print out the data that was received and sent
        printf("Received message: %s\n", buffer);
        printf("Sent message: %s\n", buffer);
    }
}

// Function that creates a socket and listens for incoming connections
void start_server() {

    // Create a socket file descriptor
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    int optval = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind the socket to a port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(8000);

    int bind_status = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (bind_status < 0) {
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    int listen_status = listen(server_socket, CLIENT_COUNT);
    if (listen_status < 0) {
        perror("listen error");
        exit(EXIT_FAILURE);
    }

    printf("Server is running...\n");

    while(1) {
        // Accept a new client connection
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket < 0) {
            perror("accept error");
            exit(EXIT_FAILURE);
        }

        printf("New client connected...\n");

        // Spawn a new thread to handle the client connection
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            monitor_thread(client_socket);
            exit(EXIT_SUCCESS);
        }
        else if (pid < 0) {
            perror("fork error");
            exit(EXIT_FAILURE);
        }
        else {
            // Parent process
            close(client_socket);
        }
    }
}

int main() {
    start_server();
    return 0;
}