//FormAI DATASET v1.0 Category: Client Server Application ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080 // Port number for the socket connection

int main()
{
    // Create a socket file descriptor
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        printf("Error creating socket!\n");
        return -1;
    }

    // Set socket options to reuse addresses already in use
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        printf("Error setting socket options!\n");
        return -1;
    }

    // Set the server address structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket file descriptor to the server address
    if (bind(server_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error binding socket to address!\n");
        return -1;
    }

    // Start listening
    if (listen(server_fd, 3) < 0)
    {
        printf("Error starting to listen!\n");
        return -1;
    }

    while (1)
    {
        // Accept incoming connections
        int new_socket = accept(server_fd, (struct sockaddr*)NULL, NULL);

        // Read request from the client
        char buffer[1024] = {0};
        read(new_socket, buffer, 1024);

        // Send response to the client
        char* response = "Hello from the server!";
        send(new_socket, response, strlen(response), 0);

        // Close the connection to the client
        close(new_socket);
    }

    // Close the server socket file descriptor
    close(server_fd);

    return 0;
}