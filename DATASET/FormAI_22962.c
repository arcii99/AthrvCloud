//FormAI DATASET v1.0 Category: Chat server ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define PORT 8888

int main(int argc, char *argv[])
{
    int server_socket, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("Could not create socket.");
        return -1;
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        printf("Could not set socket options.");
        return -1;
    }

    // Set address information
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("Could not bind socket to address.");
        return -1;
    }

    // Start listening for incoming connections
    if (listen(server_socket, 3) < 0)
    {
        printf("Could not start listening.");
        return -1;
    }

    // Wait for incoming connections
    while (1)
    {
        printf("Waiting for connection...\n");

        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            printf("Could not accept incoming connection.");
            return -1;
        }

        printf("Connection accepted from %s:%d.\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Send welcome message to client
        char *message = "Welcome to Chat Server. Type 'QUIT' to exit.\n";
        send(new_socket, message, strlen(message), 0);

        // Receive message from client
        while ((valread = read(new_socket, buffer, 1024)) > 0)
        {
            buffer[valread-1] = '\0';

            // If client wants to exit
            if (strcmp(buffer, "QUIT") == 0)
            {
                char *exit_message = "Goodbye!\n";
                send(new_socket, exit_message, strlen(exit_message), 0);
                close(new_socket);
                printf("Connection closed from %s:%d.\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                break;
            }

            // Otherwise, echo message back to client
            for (int i = 0; buffer[i]; i++)
            {
                buffer[i] = tolower(buffer[i]);
            }
            send(new_socket, buffer, strlen(buffer), 0);
        }
    }

    return 0;
}