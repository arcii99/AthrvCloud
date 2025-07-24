//FormAI DATASET v1.0 Category: Networking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MSG_LEN 1024

struct sockaddr_in server_addr, client_addr;
int server_fd, client_fd, addr_len = sizeof(client_addr);

int main(int argc, char const *argv[])
{
    char message[MAX_MSG_LEN] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to server address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len)) < 0)
        {
            perror("Accept error");
            exit(EXIT_FAILURE);
        }

        // Print client information
        printf("Connection accepted from: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1)
        {
            // Receive message from client
            if (recv(client_fd, message, MAX_MSG_LEN, 0) < 0)
            {
                perror("Receive error");
                exit(EXIT_FAILURE);
            }

            // Print received message
            printf("Received message: %s\n", message);

            // Check for exit command
            if (strcmp(message, "exit") == 0)
            {
                printf("Client disconnected\n");
                break;
            }

            // Echo message back to client
            if (send(client_fd, message, strlen(message), 0) < 0)
            {
                perror("Send error");
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}