//FormAI DATASET v1.0 Category: Chat server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 5050

int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        char *welcome_msg = "Welcome to the chat server!\n";
        send(new_socket, welcome_msg, strlen(welcome_msg), 0);
        printf("New client connected!\n");

        while (1)
        {
            valread = read(new_socket, buffer, 1024);
            if (valread <= 0)
            {
                printf("Client disconnected!\n");
                break;
            }
            printf("Client: %s", buffer);

            char *response_msg = "Server response: ";
            send(new_socket, response_msg, strlen(response_msg), 0);
            send(new_socket, buffer, strlen(buffer), 0);
            memset(buffer, 0, 1024); // Clear the buffer
        }

        close(new_socket);
    }

    return 0;
}