//FormAI DATASET v1.0 Category: Chat server ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of clients
#define MAX_CLIENTS 10

int main()
{
    // Create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Initialize the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);

    // Bind the socket to the server address
    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    // Listen for incoming connections
    listen(server_socket, MAX_CLIENTS);

    // Initialize the client sockets
    int client_sockets[MAX_CLIENTS];
    memset(client_sockets, 0, sizeof(client_sockets));

    // Initialize the client addresses
    struct sockaddr_in client_addresses[MAX_CLIENTS];
    memset(client_addresses, 0, sizeof(client_addresses));

    // Wait for incoming connections
    while (1)
    {
        // Initialize the file descriptor set
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(server_socket, &fds);
        int max_fd = server_socket;

        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            if (client_sockets[i] > 0)
            {
                FD_SET(client_sockets[i], &fds);
                if (client_sockets[i] > max_fd)
                {
                    max_fd = client_sockets[i];
                }
            }
        }

        // Wait for incoming activity
        int activity = select(max_fd + 1, &fds, NULL, NULL, NULL);

        // Handle incoming activity
        if (activity < 0)
        {
            printf("Error: select failed.\n");
            continue;
        }

        // Handle incoming connection
        if (FD_ISSET(server_socket, &fds))
        {
            // Accept the incoming connection
            struct sockaddr_in client_address;
            socklen_t client_address_len = sizeof(client_address);
            int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);

            // Register the client socket
            for (int i = 0; i < MAX_CLIENTS; i++)
            {
                if (client_sockets[i] == 0)
                {
                    client_sockets[i] = client_socket;
                    client_addresses[i] = client_address;
                    printf("New connection: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    break;
                }
            }
        }

        // Handle incoming data
        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            int client_socket = client_sockets[i];
            if (FD_ISSET(client_socket, &fds))
            {
                // Read the incoming data
                char buffer[1024] = {0};
                if (read(client_socket, buffer, sizeof(buffer)) == 0)
                {
                    // Close the connection
                    close(client_socket);
                    client_sockets[i] = 0;
                    printf("Connection closed: %s:%d\n", inet_ntoa(client_addresses[i].sin_addr), ntohs(client_addresses[i].sin_port));
                }
                else
                {
                    // Print the incoming data
                    printf("Incoming data from %s:%d: %s\n", inet_ntoa(client_addresses[i].sin_addr), ntohs(client_addresses[i].sin_port), buffer);

                    // Echo back the incoming data
                    send(client_socket, buffer, strlen(buffer), 0);
                }
            }
        }
    }

    // Close the server socket
    close(server_socket);

    return 0;
}