//FormAI DATASET v1.0 Category: Chat server ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 9000
#define MAX_CLIENTS 5 // Maximum number of clients to be allowed

int server_fd, client_fds[MAX_CLIENTS];
struct sockaddr_in server_address;
int num_clients = 0;

void handle_interruption(int sig);
void initialize_server();

int main() {
    signal(SIGINT, handle_interruption);

    initialize_server();

    while(1) {
        // Wait for client connections
        int client_fd = accept(server_fd, NULL, NULL);
        if(client_fd < 0) {
            perror("Cannot accept client connection");
            continue;
        }

        // Reject client connection if max limit reached
        if(num_clients >= MAX_CLIENTS) {
            printf("Max clients limit reached. Connection rejected.\n");
            close(client_fd);
            continue;
        }

        // Add client to list
        client_fds[num_clients] = client_fd;
        num_clients++;

        printf("Client %d connected\n", num_clients);

        // Create a separate process for each client
        int pid = fork();
        if(pid < 0) {
            perror("Cannot create a new process for client");
            continue;
        }
        else if(pid == 0) { // Child process
            close(server_fd);
            char message[1024];
            int client_id = num_clients;

            while(1) {
                // Read message from client
                memset(message, '\0', sizeof(message));
                int bytes_read = read(client_fd, message, sizeof(message));
                if(bytes_read < 0) {
                    perror("Cannot read message from client");
                    break;
                }
                else if(bytes_read == 0) {
                    printf("Client %d disconnected\n", client_id);
                    break;
                }

                // Print message received from client
                printf("Client %d: %s", client_id, message);

                // Broadcast message to all other clients
                for(int i = 0; i < num_clients; i++) {
                    if(i != (client_id - 1)) { // Do not broadcast to self
                        int bytes_sent = write(client_fds[i], message, strlen(message));
                        if(bytes_sent < 0) {
                            perror("Cannot send message to client");
                        }
                    }
                }
            }

            // Remove client from list and close socket
            for(int i = 0; i < num_clients; i++) {
                if(client_fds[i] == client_fd) {
                    for(int j = i; j < (num_clients - 1); j++) {
                        client_fds[j] = client_fds[j+1];
                    }
                    num_clients--;
                    break;
                }
            }
            close(client_fd);
        }
        else { // Parent process
            close(client_fd);
        }
    }

    return 0;
}

void handle_interruption(int sig) {
    printf("\nShutting down server...\n");
    for(int i = 0; i < num_clients; i++) {
        close(client_fds[i]);
    }
    close(server_fd);
    exit(0);
}

void initialize_server() {
    // Initialize server address struct
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Create TCP socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0) {
        perror("Cannot create socket");
        exit(1);
    }

    // Bind socket to port
    if(bind(server_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Cannot bind socket to port");
        exit(1);
    }

    // Start listening for client connections
    if(listen(server_fd, 1) < 0) {
        perror("Cannot start listening for client connections");
        exit(1);
    }

    printf("Server started on port %d\n", PORT);
}