//FormAI DATASET v1.0 Category: Simple Web Server ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int socket_fd, connection_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the socket with the server address
    if (bind(socket_fd, (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen to incoming connections
    if (listen(socket_fd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    int addr_len = sizeof(client_addr);
    if ((connection_fd = accept(socket_fd, (struct sockaddr *)&client_addr,
                                (socklen_t *)&addr_len)) < 0)
    {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Read incoming request from client
    long valread = read(connection_fd, buffer, 1024);
    printf("%s\n", buffer);

    // Write server response to client
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";
    send(connection_fd, response, strlen(response), 0);

    // Close the connection
    close(connection_fd);
    close(socket_fd);

    return 0;
}