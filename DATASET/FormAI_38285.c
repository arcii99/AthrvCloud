//FormAI DATASET v1.0 Category: Socket programming ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 50
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread, opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *welcome_message = "Welcome to my chat server!\n";
    int client_fds[MAX_CLIENTS] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)   // Set maximum amount of connections to 3
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connections...\n");

    while (1)
    {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        // Add client socket to list
        int i;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_fds[i] == 0) {
                client_fds[i] = new_socket;
                break;
            }
        }

        // Send welcome message to client
        send(new_socket, welcome_message, strlen(welcome_message), 0);
        
        printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        while (1)
        {
            valread = read(new_socket, buffer, BUFFER_SIZE);

            if (valread <= 0)
            {
                // Remove client socket from list
                for (i = 0; i < MAX_CLIENTS; i++) {
                    if (client_fds[i] == new_socket) {
                        client_fds[i] = 0;
                        break;
                    }
                }

                printf("Client disconnected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                close(new_socket);
                break;
            }
            else
            {
                // Broadcast message to all connected clients
                for (i = 0; i < MAX_CLIENTS; i++) {
                    if (client_fds[i] > 0 && client_fds[i] != new_socket) {
                        send(client_fds[i], buffer, valread, 0);
                    }
                }
            }

            memset(buffer, 0, BUFFER_SIZE);
        }
    }

    return 0;
}