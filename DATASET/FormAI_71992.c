//FormAI DATASET v1.0 Category: Chat server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *message = "Welcome to the Chat Server!\n";

    // Creating server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port %d...\n", PORT);

    // Accept incoming connections and handle incoming messages
    while (1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Welcome message for new client
        send(new_socket, message, strlen(message), 0);
        printf("New client connected\n");

        while (1)
        {
            // Read message from client
            valread = read(new_socket, buffer, BUFFER_SIZE);
            if (valread <= 0)
            {
                printf("Client disconnected\n");
                break;
            }
            printf("Received: %s", buffer);

            // Send message to all connected clients except the sender
            for (int i = 3; i < 10; i++) {
                if (i != new_socket) {
                    send(i, buffer, strlen(buffer), 0);
                }
            } 
            memset(buffer, 0, BUFFER_SIZE);
        }
        close(new_socket);
    }

    return 0;
}