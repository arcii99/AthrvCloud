//FormAI DATASET v1.0 Category: Chat server ; Style: statistical
// Statistical Chat Server Program
// April 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int active_clients[FD_SETSIZE];   // list of active clients
fd_set read_fds;                  // set of socket file descriptors for input
int main_socket_fd;               // socket file descriptor for the main socket
int client_fd;                    // file descriptor for client connections
int max_fd;                       // maximum file descriptor number

// Function to handle new client connections
void handle_new_connection() {
    struct sockaddr_in client_addr;
    socklen_t client_len;
    int client_fd = accept(main_socket_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("New client connected\n");
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (active_clients[i] == -1) {
            active_clients[i] = client_fd;
            break;
        }
    }
    FD_SET(client_fd, &read_fds);
    if (client_fd > max_fd) {
        max_fd = client_fd;
    }
}

// Function to handle data received from a client
void handle_client_data(int client_index, char *buffer) {
    // Process statistical data
    int length = strlen(buffer);
    int num_spaces = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] == ' ') {
            num_spaces++;
        }
    }
    float avg_word_length = (float)(length - num_spaces) / (float)num_spaces;
    int num_letters = 0;
    for (int i = 0; i < length; i++) {
        if ((buffer[i] >= 65 && buffer[i] <= 90) || (buffer[i] >= 97 && buffer[i] <= 122)) {
            num_letters++;
        }
    }
    float letter_percent = (float)num_letters / (float)length * 100.0;
    printf("Client %d: Avg word length=%.2f Letter percentage=%.2f%%\n", client_index, avg_word_length, letter_percent);

    // Echo received message back to client
    send(active_clients[client_index], buffer, strlen(buffer) + 1, 0);
}

// Main function
int main(int argc, char *argv[]) {
    // Initialize active clients list
    for (int i = 0; i < FD_SETSIZE; i++) {
        active_clients[i] = -1;
    }

    // Create main socket
    main_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (main_socket_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind main socket to port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(main_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(main_socket_fd, 10) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Initialize file descriptor set
    FD_ZERO(&read_fds);
    FD_SET(main_socket_fd, &read_fds);
    max_fd = main_socket_fd;

    // Loop to handle incoming connections and data
    while (1) {
        // Wait for input on socket file descriptors
        fd_set temp_fds = read_fds;
        if (select(max_fd + 1, &temp_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        // Check for new connections
        if (FD_ISSET(main_socket_fd, &temp_fds)) {
            handle_new_connection();
        }

        // Check for data from clients
        for (int i = 0; i < FD_SETSIZE; i++) {
            if (active_clients[i] != -1 && FD_ISSET(active_clients[i], &temp_fds)) {
                char buffer[1024];
                int num_bytes = recv(active_clients[i], buffer, sizeof(buffer), 0);
                if (num_bytes <= 0) {
                    // Client connection closed
                    close(active_clients[i]);
                    FD_CLR(active_clients[i], &read_fds);
                    active_clients[i] = -1;
                } else {
                    handle_client_data(i, buffer);
                }
            }
        }
    }

    return 0;
}