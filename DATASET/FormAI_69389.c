//FormAI DATASET v1.0 Category: Chat server ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000
#define MAX_CLIENTS 20

int main() {
    // Initialize server socket
    int server_fd;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server configuration
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind server socket to port
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", PORT);
    
    // Server loop
    while(1) {
        // Accept new connection
        int new_socket;
        struct sockaddr_in client_addr;
        socklen_t client_addrlen = sizeof(client_addr);
        if ((new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &client_addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        
        // Log new connection
        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        
        // Spawn child process to handle client
        pid_t child_pid;
        if ((child_pid = fork()) == 0) {
            // Child process
            close(server_fd);

            while(1) {
                // Read message from client
                char buffer[1024] = {0};
                int num_bytes;
                if ((num_bytes = read(new_socket, buffer, 1024)) < 0) {
                    perror("read failed");
                    exit(EXIT_FAILURE);
                } else if (num_bytes == 0) {
                    // Client disconnected
                    printf("Client %s:%d disconnected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                    break;
                }

                // Log client message
                printf("Received message from %s:%d: %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);
                
                // Send message back to client
                if (send(new_socket, buffer, strlen(buffer), 0) != strlen(buffer)) {
                    perror("send failed");
                    exit(EXIT_FAILURE);
                }
            }

            // Clean up child process
            close(new_socket);
            exit(EXIT_SUCCESS);
        } else if (child_pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }

        // Parent process
        close(new_socket);
    }

    // Clean up server socket
    close(server_fd);
    return 0;
}