//FormAI DATASET v1.0 Category: Chat server ; Style: high level of detail
// This is a basic chat server program example written in C
// The server listens to client connections, creates child processes for each client request
// and allows clients to communicate with each other via the server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define MAX_CLIENTS 10 // Maximum number of clients that can be connected at once

int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Setting socket address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Binding socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for client connections
    if (listen(server_fd, MAX_CLIENTS) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Chat server is running. Waiting for clients to connect...\n");

    // Accepting client connections
    while (1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Forking child process for each client
        if (fork() == 0)
        {
            printf("New client connected\n");

            // Reading client messages and broadcasting to other clients
            while (1)
            {
                valread = read(new_socket, buffer, 1024);
                if (valread == 0)
                {
                    printf("Client disconnected\n");
                    close(new_socket);
                    exit(EXIT_SUCCESS);
                }
                printf("Client: %s", buffer);

                // Broadcasting message to other clients
                for (int i = 0; i < MAX_CLIENTS; i++)
                {
                    if (i != new_socket)
                    {
                        write(i, buffer, strlen(buffer));
                    }
                }
                memset(buffer, 0, sizeof(buffer));
            }
        }
        else
        {
            close(new_socket);
        }
    }

    return 0;
}