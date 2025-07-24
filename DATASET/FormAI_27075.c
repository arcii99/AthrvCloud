//FormAI DATASET v1.0 Category: Socket programming ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    int socket_fd, new_socket, valread;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE] = {0};
    const char *welcome_message = "Welcome to my server!";

    // create socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set server address structure
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // bind socket to the server address
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(socket_fd, 3) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // accept incoming connections and send welcome message
    while (1)
    {
        struct sockaddr_in client_address;
        int client_address_length = sizeof(client_address);
        if ((new_socket = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t *)&client_address_length)) < 0)
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        send(new_socket, welcome_message, strlen(welcome_message), 0);

        // receive data from client and send it back
        while ((valread = read(new_socket, buffer, BUFFER_SIZE)) > 0)
        {
            printf("Client sent: %s", buffer);
            send(new_socket, buffer, strlen(buffer), 0);
            memset(buffer, 0, sizeof(buffer));
        }
    }

    return 0;
}