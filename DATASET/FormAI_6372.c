//FormAI DATASET v1.0 Category: Networking ; Style: satisfied
/* 
This C Networking program demonstrates a simple chat server and client communication over TCP protocol.
The server can handle multiple clients and broadcasts messages to all clients.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8080
#define BUFFERSIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFERSIZE] = {0};
    char message[BUFFERSIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connections...\n");

    // Accept incoming connections and create new socket for each client
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen))) {

        printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Fork new process for each client
        pid_t child_pid = fork();
        if (child_pid == -1) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) { // child process handles client

            // Close server socket in child process
            close(server_fd);

            // Send welcome message to client
            strcpy(message, "Welcome to the chat server!\n");
            if (send(new_socket, message, strlen(message), 0) < 0) {
                perror("send failed");
                exit(EXIT_FAILURE);
            }

            // Read incoming messages from client
            while ((valread = read(new_socket, buffer, BUFFERSIZE)) > 0) {
                printf("%s:%d - %s\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port), buffer);

                // Broadcast message to all clients
                for (int i = 0; i < addrlen; i++) {
                    if (i != server_fd && i != new_socket) {
                        if (send(i, buffer, strlen(buffer), 0) < 0) {
                            perror("send failed");
                            exit(EXIT_FAILURE);
                        }
                    }
                }

                memset(buffer, 0, BUFFERSIZE);
                memset(message, 0, BUFFERSIZE);
            }

            // Client disconnected
            printf("%s:%d disconnected\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            close(new_socket);
            exit(EXIT_SUCCESS);

        } else { // parent process continues to listen for connections

            // Close client socket in parent process
            close(new_socket);

        }

    }

    return 0;
}