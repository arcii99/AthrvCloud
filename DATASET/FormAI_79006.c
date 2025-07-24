//FormAI DATASET v1.0 Category: Client Server Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    int server_fd, client_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize address structure
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen on socket for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Wait for incoming connections
    if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected: %s\n", inet_ntoa(address.sin_addr));

    while (1)
    {
        char buffer[BUFFER_SIZE] = {0};

        // Read data from client
        if (read(client_fd, buffer, BUFFER_SIZE) < 0)
        {
            perror("read failed");
            exit(EXIT_FAILURE);
        }

        // Print message from client
        printf("Client message: %s\n", buffer);

        // Send response back to client
        if (send(client_fd, buffer, strlen(buffer), 0) < 0)
        {
            perror("send failed");
            exit(EXIT_FAILURE);
        }

        // Clear buffer
        memset(buffer, 0, BUFFER_SIZE);
    }

    return 0;
}