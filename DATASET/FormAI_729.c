//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>

// Constants
#define MAX_CLIENTS 10
#define MAX_MSG_LEN 256
#define SHELL_PROMPT "myshell> "

// Function prototypes
void handle_client(int client_fd);
void broadcast_message(int sender_fd, char* message);
void handle_signal(int sig_num);

// Global variables
int client_fds[MAX_CLIENTS];
int num_clients = 0;

int main(int argc, char *argv[]) {
    // Set up signal handling
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    // Set up server socket
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t clilen = sizeof(client_addr);
    char client_addr_str[INET_ADDRSTRLEN];
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(9001);

    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)  {
        perror("ERROR on binding");
        exit(1);
    }

    listen(server_fd, MAX_CLIENTS);
    printf("Shell server started on port 9001.\n");

    // Main server loop
    while (1) {
        client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &clilen);
        if (client_fd < 0) {
            perror("ERROR on accept");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            printf("Maximum number of clients reached. Rejecting new connection from %s.\n",
                   inet_ntop(AF_INET, &(client_addr.sin_addr), client_addr_str, INET_ADDRSTRLEN));
            close(client_fd);
            continue;
        }

        client_fds[num_clients] = client_fd;
        num_clients++;
        printf("New client connected from %s! Total clients: %d\n",
               inet_ntop(AF_INET, &(client_addr.sin_addr), client_addr_str, INET_ADDRSTRLEN), num_clients);

        // Fork a new process to handle the client
        pid_t pid = fork();
        if (pid < 0) {
            perror("ERROR on fork");
            close(client_fd);
            continue;
        }
        else if (pid == 0) {
            // Child process
            handle_client(client_fd);
            exit(0);
        }
        else {
            // Parent process
            close(client_fd);
        }
    }

    return 0;
}

// Handler for individual client sessions
void handle_client(int client_fd) {
    // Set up input/output streams for the shell
    char input_buffer[MAX_MSG_LEN];
    char output_buffer[MAX_MSG_LEN];
    int input_len, output_len;

    while (1) {
        // Read input from client
        memset(input_buffer, 0, sizeof(input_buffer));
        input_len = read(client_fd, input_buffer, sizeof(input_buffer)-1);
        if (input_len < 0) {
            perror("ERROR reading from socket");
            break;
        }
        else if (input_len == 0) {
            // End of stream
            printf("Client disconnected.\n");
            break;
        }

        // Handle input
        input_buffer[input_len] = '\0';

        if (input_buffer[0] == '/') {
            // This is a command for the server, not the shell
            if (strncmp(input_buffer, "/quit", 5) == 0) {
                // Client wants to quit
                printf("Client requested to quit.\n");
                break;
            }
            else if (strncmp(input_buffer, "/broadcast", 10) == 0) {
                // Client wants to send a message to all other clients
                broadcast_message(client_fd, input_buffer+11);
                continue;
            }
            else if (strncmp(input_buffer, "/file", 5) == 0) {
                // Client wants to send a file to another client
                // TODO: Implement file sharing
                continue;
            }
            else {
                snprintf(output_buffer, MAX_MSG_LEN, "Unknown command: %s", input_buffer);
            }
        }
        else {
            // This is a command for the shell
            // TODO: Implement shell commands
            continue;
        }

        // Send output message to client
        output_len = strlen(output_buffer);
        write(client_fd, output_buffer, output_len);
    }

    // Clean up client resources
    close(client_fd);
}

// Broadcast a message to all clients, except the sender
void broadcast_message(int sender_fd, char* message) {
    char output_buffer[MAX_MSG_LEN];
    int output_len;

    for (int i = 0; i < num_clients; i++) {
        if (client_fds[i] != sender_fd) {
            snprintf(output_buffer, MAX_MSG_LEN, "Broadcast from client %d: %s", sender_fd, message);
            output_len = strlen(output_buffer);
            write(client_fds[i], output_buffer, output_len);
        }
    }
}

// Handler for SIGINT and SIGTERM signals
void handle_signal(int sig_num) {
    printf("Received signal %d. Shutting down server.\n", sig_num);
    exit(0);
}