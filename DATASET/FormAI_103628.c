//FormAI DATASET v1.0 Category: Networking ; Style: immersive
/* Welcome to the immersive world of networking! */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    printf("Hello there, I am a networking program!\n");

    // Creating socket file descriptor
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1)
    {
        printf("Could not create socket!");
        return 1;
    }

    printf("Socket created successfully.\n");

    // Prepare the sockaddr_in structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified IP and port
    int bind_result = bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bind_result < 0)
    {
        printf("Could not bind socket to port %d!", PORT);
        return 1;
    }

    printf("Socket binded to port %d.\n", PORT);

    // Start listening for incoming connections
    int listen_result = listen(sock_fd, 3);
    if (listen_result < 0)
    {
        printf("Could not listen on socket!");
        return 1;
    }

    printf("Waiting for incoming connections...\n");

    // Accept incoming connections
    int client_sock_fd;
    struct sockaddr_in client_addr;
    int client_addr_len = sizeof(client_addr);

    while ((client_sock_fd = accept(sock_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len)))
    {
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Send a welcome message to the client
        char *welcome_msg = "Welcome to the immersive world of networking! How can I help you today?\n";
        write(client_sock_fd, welcome_msg, strlen(welcome_msg));

        // Receive data from the client
        char client_msg[1024];
        bool exit_flag = false;
        while (read(client_sock_fd, client_msg, 1024) > 0 && !exit_flag)
        {
            printf("Received message: %s\n", client_msg);

            // Echo the message back to the client
            write(client_sock_fd, client_msg, strlen(client_msg));

            // Check if the client wants to exit
            if (strcmp(client_msg, "exit") == 0)
            {
                printf("Client has requested to exit.\n");
                exit_flag = true;
            }

            // Clear the buffer
            memset(client_msg, 0, strlen(client_msg));
        }

        // Close the client socket
        printf("Closing connection with %s:%d.\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        close(client_sock_fd);
    }

    // Clean up and exit
    printf("Exiting program.\n");
    close(sock_fd);
    return 0;
}