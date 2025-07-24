//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>

#define SERVER_PORT 8080            // Default server port
#define CLIENT_TIMEOUT 10           // Timeout for reading data from client
#define TICK_INTERVAL 1             // Determines how often we check the QoS
#define MAX_CLIENTS 10              // Maximum number of clients we can handle at once

// Structure for storing client connection data
typedef struct {
    int sockfd;                     // Socket file descriptor
    char ip[INET_ADDRSTRLEN];       // Client IP address
    time_t last_heartbeat;          // Time of last successful client heartbeat
} ClientConnection;

// Function for setting up server socket
int setup_server_socket(int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to our address and port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function for handling client connections
void handle_client(int sockfd) {
    printf("Accepted new connection on socket %d\n", sockfd);

    // Read client IP address
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    getpeername(sockfd, (struct sockaddr *)&client_address, &client_address_len);
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_address.sin_addr, ip, INET_ADDRSTRLEN);

    // Create and initialize a new client connection struct
    ClientConnection *connection = calloc(1, sizeof(ClientConnection));
    connection->sockfd = sockfd;
    strcpy(connection->ip, ip);
    time(&connection->last_heartbeat);

    // Handle client requests
    char buffer[1024];
    int bytes_read;
    while ((bytes_read = read(sockfd, buffer, 1024)) > 0) {
        // Update last heartbeat time for this connection
        time(&connection->last_heartbeat);

        // Do something with client data here (e.g., parse QoS data)

        // Write response to client
        write(sockfd, "OK", 2);
    }

    // Close socket and free connection struct
    close(sockfd);
    free(connection);

    printf("Closed connection on socket %d\n", sockfd);
}

// Function for cleaning up idle client connections
void cleanup_connections(ClientConnection **connections, int *num_connections) {
    int i;
    time_t now;
    time(&now);

    for (i = 0; i < *num_connections; i++) {
        // Check for idle connection (no heartbeat received within CLIENT_TIMEOUT seconds)
        if ((now - connections[i]->last_heartbeat) >= CLIENT_TIMEOUT) {
            printf("Cleaning up idle connection on socket %d (IP: %s)\n", connections[i]->sockfd, connections[i]->ip);

            close(connections[i]->sockfd);
            free(connections[i]);

            // Shift remaining connections down in array
            if (i < (*num_connections - 1)) {
                memmove(&connections[i], &connections[i+1], (*num_connections - i - 1) * sizeof(ClientConnection *));
            }

            // Decrement number of connections
            (*num_connections)--;
            i--;                    // We might have shifted down multiple connections, so we need to decrement the index to stay on the same connection
        }
    }
}

// Function for handling SIGINT signals (e.g., when user presses Ctrl+C)
void handle_sigint(int sig) {
    printf("Caught SIGINT signal -- shutting down server\n");
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
    // Set up SIGINT signal handler
    signal(SIGINT, handle_sigint);

    // Set up server socket and listen for incoming client connections
    int server_sockfd = setup_server_socket(SERVER_PORT);
    printf("Server listening on port %d...\n", SERVER_PORT);

    // Allocate memory for client connection array
    ClientConnection **connections = calloc(MAX_CLIENTS, sizeof(ClientConnection *));
    int num_connections = 0;

    // Start main loop for monitoring QoS and handling client connections
    while (1) {
        // Check for incoming connections
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(server_sockfd, &readfds);
        int max_fd = server_sockfd;
        int i;
        for (i = 0; i < num_connections; i++) {
            FD_SET(connections[i]->sockfd, &readfds);
            if (connections[i]->sockfd > max_fd) {
                max_fd = connections[i]->sockfd;
            }
        }

        // Check for ready sockets and handle I/O
        int num_ready = select(max_fd + 1, &readfds, NULL, NULL, &(struct timeval){TICK_INTERVAL, 0});
        if (num_ready < 0) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }

        if (num_ready) {
            // Handle incoming connections
            if (FD_ISSET(server_sockfd, &readfds)) {
                // Accept new client connection
                int client_sockfd = accept(server_sockfd, NULL, NULL);
                if (client_sockfd < 0) {
                    perror("Accept failed");
                    exit(EXIT_FAILURE);
                }

                // Add connection to our list
                connections[num_connections] = calloc(1, sizeof(ClientConnection));
                connections[num_connections]->sockfd = client_sockfd;
                time(&connections[num_connections]->last_heartbeat);
                num_connections++;
            }

            // Handle client I/O
            for (i = 0; i < num_connections; i++) {
                if (FD_ISSET(connections[i]->sockfd, &readfds)) {
                    int client_sockfd = connections[i]->sockfd;
                    handle_client(client_sockfd);
                }
            }
        }

        // Clean up idle client connections
        cleanup_connections(connections, &num_connections);
    }

    return 0;
}