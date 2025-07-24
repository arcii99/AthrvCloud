//FormAI DATASET v1.0 Category: Simple Web Server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#define PORT 8080 // Port number for the server
#define BACKLOG 5 // Max number of pending connections

// Handle a client connection
void handle_connection(int client_socket) {
    char buffer[1024] = {0};
    ssize_t num_bytes;
    // Receive request from client
    if ((num_bytes = recv(client_socket, buffer, sizeof(buffer), 0)) == -1) {
        perror("recv");
        return;
    }
    // Parse HTTP request
    char method[32], path[256];
    sscanf(buffer, "%s %s", method, path);
    // Only accept GET requests
    if (strcmp(method, "GET") != 0) {
        char* message = "HTTP/1.0 501 Not Implemented\r\nContent-Type: text/plain\r\n\r\n501 Not Implemented\n";
        send(client_socket, message, strlen(message), 0);
        return;
    }
    // Open file
    char full_path[256];
    sprintf(full_path, "./www%s", path);
    int fd = open(full_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        char* message = "HTTP/1.0 404 Not Found\r\nContent-Type: text/plain\r\n\r\n404 Not Found\n";
        send(client_socket, message, strlen(message), 0);
        return;
    }
    // Read file
    struct stat st;
    fstat(fd, &st);
    char* data = (char*) malloc(st.st_size);
    read(fd, data, st.st_size);
    // Send response
    char* message = "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n";
    send(client_socket, message, strlen(message), 0);
    send(client_socket, data, strlen(data), 0);
    // Clean up
    free(data);
    close(fd);
}

// Handle a SIGCHLD signal
void handle_sigchld(int sig) {
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

int main() {
    // Set up signal handler for SIGCHLD
    struct sigaction sa;
    sa.sa_handler = &handle_sigchld;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_NOCLDSTOP;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
    // Create server socket
    int server_socket;
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    // Bind server socket
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }
    // Listen for connections
    if (listen(server_socket, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }
    printf("Server is listening on port %d...\n", PORT);
    // Accept connections and handle them
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*) &client_addr, &client_addr_size);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }
        printf("Received connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        // Fork a new process to handle the client
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // Child process - handle client connection and exit
            handle_connection(client_socket);
            close(server_socket);
            exit(0);
        }
        // Parent process - continue listening for connections
        close(client_socket);
    }
    return 0;
}