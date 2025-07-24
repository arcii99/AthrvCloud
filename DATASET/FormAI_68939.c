//FormAI DATASET v1.0 Category: Chat server ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CONNECTIONS 5
#define MAX_BUFFER_SIZE 1024

int main()
{
    int server_socket_fd, new_socket_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    char buffer[MAX_BUFFER_SIZE];
    int option = 1;

    // Creating socket file descriptor
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &option, sizeof(option))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the given port and address
    if (bind(server_socket_fd, (struct sockaddr *)&server_address,
             sizeof(server_address)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket_fd, MAX_CONNECTIONS) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started at port %d\n", PORT);

    while (1) {
        // Accept incoming connection
        new_socket_fd = accept(server_socket_fd,
                               (struct sockaddr *)&client_address,
                               &client_address_len);
        if (new_socket_fd == -1) {
            perror("accept failed");
            continue;
        }

        printf("New client connected from %s:%d\n",
               inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Fork a process to handle the incoming client
        pid_t child_pid = fork();
        if (child_pid == -1) {
            perror("fork failed");
            continue;
        }
        if (child_pid == 0) {
            // Child process
            close(server_socket_fd);

            while (1) {
                memset(&buffer, 0, sizeof(buffer));
                int bytes_received = recv(new_socket_fd, buffer, MAX_BUFFER_SIZE, 0);
                if (bytes_received == -1) {
                    perror("recv failed");
                    break;
                }
                if (bytes_received == 0) {
                    printf("Client disconnected from %s:%d\n",
                           inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    break;
                }

                printf("Received from %s:%d: %s",
                       inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);

                // Send message back to the client
                int bytes_sent = send(new_socket_fd, buffer, strlen(buffer), 0);
                if (bytes_sent == -1) {
                    perror("send failed");
                    break;
                }
            }

            close(new_socket_fd);
            printf("Child process exit\n");
            exit(EXIT_SUCCESS);
        } else {
            // Parent process
            close(new_socket_fd);
        }
    }

    close(server_socket_fd);
    return 0;
}