//FormAI DATASET v1.0 Category: Simple Web Server ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void process_request(int client_socket)
{
    char buffer[BUFFER_SIZE] = {0};
    int read_bytes = read(client_socket, buffer, BUFFER_SIZE);

    if (read_bytes <= 0)
    {
        return;
    }

    printf("Received request from client:\n%s\n", buffer);

    char *content = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Welcome to the post-apocalyptic web server</h1><p>This is a bleak and desolate wasteland, but at least you've made it to our website.</p></body></html>";

    send(client_socket, content, strlen(content), 0);

    close(client_socket);
}

int main()
{
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    int addrlen = sizeof(address);
   
    memset(&address, '0', addrlen);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&address, addrlen) < 0)
    {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0)
    {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d\n", PORT);

    while (1)
    {
        int client_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen);

        if (client_socket < 0)
        {
            perror("Error accepting client connection");
            continue;
        }

        process_request(client_socket);
    }

    close(server_socket);

    return 0;
}