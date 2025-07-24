//FormAI DATASET v1.0 Category: Chat server ; Style: introspective
// This is a unique C chat server example program
// It uses TCP sockets to establish communication with multiple clients
// The program logs incoming messages and broadcasts them to all connected clients
// It is implemented in a modular, object-oriented style using functions and structs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_NAME_LEN 50
#define MAX_MSG_LEN 200
#define MAX_CLIENTS 10

// A client struct to store client's information
typedef struct {
    int fd;
    char name[MAX_NAME_LEN];
    struct sockaddr_in addr;
} client_t;

// An array of clients to store all connected clients
client_t clients[MAX_CLIENTS];

// A function to add a new client to the array of clients
bool add_client(int fd, const char* name, struct sockaddr_in addr) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].fd == -1) {
            clients[i].fd = fd;
            strncpy(clients[i].name, name, MAX_NAME_LEN);
            clients[i].addr = addr;
            return true;
        }
    }
    return false;
}

// A function to remove a client from the array of clients by its file descriptor
void remove_client(int fd) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].fd == fd) {
            close(clients[i].fd);
            clients[i].fd = -1;
            clients[i].name[0] = '\0';
            break;
        }
    }
}

// A function to broadcast a message to all connected clients
void broadcast(const char* msg) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].fd != -1) {
            write(clients[i].fd, msg, strlen(msg));
        }
    }
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char name[MAX_NAME_LEN];
    char msg[MAX_MSG_LEN];

    // Initialize the array of clients
    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i].fd = -1;
        clients[i].name[0] = '\0';
    }

    // Create a TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Configure the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the socket to the server address and port
    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and handle them
    while (true) {
        // Accept a new client
        if ((client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Prompt the client for a name and add it to the array of clients
        write(client_fd, "Enter your name: ", 17);
        read(client_fd, name, MAX_NAME_LEN);
        name[strcspn(name, "\r\n")] = '\0'; // Remove newline
        if (!add_client(client_fd, name, client_addr)) {
            printf("Maximum number of clients reached\n");
            close(client_fd);
            continue;
        }

        // Notify all connected clients of the new user
        sprintf(msg, "%s has joined the chat\n", name);
        broadcast(msg);

        // Receive and forward messages from the client
        while (true) {
            if (read(client_fd, msg, MAX_MSG_LEN) < 0) {
                perror("read failed");
                remove_client(client_fd);
                sprintf(msg, "%s has left the chat\n", name);
                broadcast(msg);
                break;
            }
            if (strcmp(msg, "quit\n") == 0) {
                remove_client(client_fd);
                sprintf(msg, "%s has left the chat\n", name);
                broadcast(msg);
                break;
            }
            sprintf(msg, "%s: %s", name, msg);
            broadcast(msg);
        }
    }

    return 0;
}