//FormAI DATASET v1.0 Category: Socket programming ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int sockfd, new_sockfd, size;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    char response[] = "Hello from the server!";

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific IP and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed.\n");
        exit(EXIT_FAILURE);
    }

    // Start listening for client connections
    if (listen(sockfd, 3) < 0)
    {
        perror("Listen failed.\n");
        exit(EXIT_FAILURE);
    }

    size = sizeof(client_addr);

    // Block until a new client connects
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&size);
    if (new_sockfd < 0)
    {
        perror("Accept failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("New client connected from: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Synchronously receive message from the client
    bzero(buffer, 1024);
    if (read(new_sockfd, buffer, 1024) < 0)
    {
        perror("Read failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Message from client: %s\n", buffer);

    // Synchronously send response to the client
    if (write(new_sockfd, response, strlen(response)) < 0)
    {
        perror("Write failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Response sent to client: %s\n", response);

    // Close the socket connection
    close(new_sockfd);
    close(sockfd);

    return 0;
}