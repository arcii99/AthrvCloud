//FormAI DATASET v1.0 Category: Socket programming ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000

int main(int argc, char *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char *greeting = "Hail and well met! What can I do for ye?";

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

    // Start listening for connections
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Wait for a client to connect
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Send greeting to client
    send(new_socket, greeting, strlen(greeting), 0);

    char buffer[1024] = {0};
    while (1)
    {
        // Receive message from client
        valread = read(new_socket, buffer, 1024);
        if (valread == 0)
        {
            close(new_socket);
            break;
        }
        else if (strcmp(buffer, "quit") == 0)
        {
            char *farewell = "Fare thee well!";
            send(new_socket, farewell, strlen(farewell), 0);
            close(new_socket);
            break;
        }
        else
        {
            // Respond to client's message
            char response[1024];
            sprintf(response, "Aye, %s, I hear ye loud and clear!", buffer);
            send(new_socket, response, strlen(response), 0);
        }

        // Reset buffer
        memset(buffer, 0, sizeof(buffer));
    }

    return 0;
}