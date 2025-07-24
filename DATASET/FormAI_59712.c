//FormAI DATASET v1.0 Category: Client Server Application ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000

int main()
{
    // server setup
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 1) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("The server is ready to roll!\n");

    // client setup
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Got a client! Let's make them feel special.\n");

    // sending a message to the client
    char msg[] = "Hello client! You are cute, just like this code.";
    if (send(client_fd, msg, sizeof(msg), 0) < 0)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    printf("Message sent! The client is swooning over us already.\n");

    // receiving a message from the client
    char buffer[1024];
    ssize_t n = recv(client_fd, buffer, sizeof(buffer), 0);
    if (n < 0)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("The client says: %s\n", buffer);
    printf("Aww, they're even funnier than this code!\n");

    // closing the connection
    close(client_fd);
    close(server_fd);

    return 0;
}