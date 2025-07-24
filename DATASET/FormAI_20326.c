//FormAI DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define PORT 5555
#define BUFFER_SIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(void)
{
    int sock_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    char buffer[BUFFER_SIZE];

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("ERROR: Failed to create socket");

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("ERROR: Failed to bind socket");

    if (listen(sock_fd, 5) < 0)
        error("ERROR: Failed to listen on socket");

    printf("Server is listening on port %d\n", PORT);

    while (1)
    {
        client_len = sizeof(client_addr);
        int client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_len);

        if (client_fd < 0)
            error("ERROR: Failed to accept client connection");

        printf("New client connected!\n");

        int n;
        while ((n = recv(client_fd, buffer, BUFFER_SIZE, 0)) > 0)
        {
            printf("Client: %s\n", buffer);

            if (send(client_fd, buffer, n, 0) < 0)
                error("ERROR: Failed to send message to client");

            memset(buffer, 0, BUFFER_SIZE);
        }

        if (n == 0)
        {
            printf("Client disconnected\n");
        }
        else
        {
            printf("ERROR: Failed to receive message from client");
        }

        close(client_fd);
    }

    close(sock_fd);
    return 0;
}