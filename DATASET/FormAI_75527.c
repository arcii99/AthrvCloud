//FormAI DATASET v1.0 Category: Chat server ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define Variables
#define PORT 8080
#define MAX_CLIENTS 10

int main(int argc, char const *argv[])
{
    int server_fd, client_fds[MAX_CLIENTS], max_fd, activity, val_read, new_socket;
    struct sockaddr_in address;
    char buffer[1024] = {0};

    // Create Server Socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Configure Server Address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind Server Socket to Address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for Client Connections
    if (listen(server_fd, MAX_CLIENTS) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Initialize Client Sockets array
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        client_fds[i] = 0;
    }

    // Set max_fd to Server Socket
    max_fd = server_fd;

    while (1)
    {
        fd_set read_fds;

        // Clear Set
        FD_ZERO(&read_fds);

        // Add Server Socket to Set
        FD_SET(server_fd, &read_fds);

        // Add Client Sockets to Set
        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            int client_fd = client_fds[i];

            if (client_fd > 0)
            {
                FD_SET(client_fd, &read_fds);
            }

            // Update max_fd if needed
            if (client_fd > max_fd)
            {
                max_fd = client_fd;
            }
        }

        // Wait for Activity on Sockets
        activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);

        if (activity < 0)
        {
            perror("select failed");
            exit(EXIT_FAILURE);
        }

        // Handle Activity on Server Socket
        if (FD_ISSET(server_fd, &read_fds))
        {
            // Accept New Client Connection
            int addrlen = sizeof(address);

            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
            {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }

            // Add New Client Socket to Array
            for (int i = 0; i < MAX_CLIENTS; i++)
            {
                if (client_fds[i] == 0)
                {
                    client_fds[i] = new_socket;
                    break;
                }
            }
        }

        // Handle Activity on Client Sockets
        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            int client_fd = client_fds[i];

            if (FD_ISSET(client_fd, &read_fds))
            {
                // Read Data from Client
                val_read = read(client_fd, buffer, 1024);

                if (val_read == 0)
                {
                    // Client Disconnected
                    close(client_fd);
                    client_fds[i] = 0;
                }
                else
                {
                    // Print Received Data
                    printf("Message from Client %d: %s\n", client_fd, buffer);
                }
            }
        }
    }

    return 0;
}