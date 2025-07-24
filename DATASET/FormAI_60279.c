//FormAI DATASET v1.0 Category: Simple Web Server ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main()
{
    int server_fd, client_fd, read_val;
    struct sockaddr_in server_addr, client_addr;
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Welcome to my server!</h1></body></html>";
    char buffer[1024] = {0};

    // create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        printf("Error creating socket\n");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind socket to specified port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Error binding socket\n");
        return -1;
    }

    // listen for incoming connections
    if (listen(server_fd, 10) < 0)
    {
        printf("Error listening for connections\n");
        return -1;
    }

    while (1)
    {
        printf("Listening for incoming connections...\n");

        // accept incoming connection
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr);

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // read client request
        read_val = read(client_fd, buffer, 1024);

        printf("Client request:\n%s\n", buffer);

        // send response to client
        send(client_fd, response, strlen(response), 0);

        printf("Response sent!\n");

        // close connection with client
        close(client_fd);
    }

    return 0;
}