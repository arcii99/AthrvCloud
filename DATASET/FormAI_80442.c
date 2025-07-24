//FormAI DATASET v1.0 Category: Simple Web Server ; Style: artistic
//Welcome to the Simple Web Server!

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main()
{
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int server_fd, client_fd, valread;
    int opt = 1;
    int addrlen = sizeof(server_addr);

    //Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    //Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Setsockopt error");
        exit(EXIT_FAILURE);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    //Attaching socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
     {
        perror("Bind failed");
        exit(EXIT_FAILURE);
     }

    //Listening for incoming requests
    if (listen(server_fd, MAX_CLIENTS) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    //Accepting connection from client
    if ((client_fd = accept(server_fd, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen)) < 0)
    {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    //Sending response to the client
    char response_message[] = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 13\n\nHello, World!";
    send(client_fd, response_message, strlen(response_message), 0);

    return 0;
}