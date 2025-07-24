//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char const *argv[])
{
    struct sockaddr_in server_address, client_address;
    int server_socket, client_socket;
    int client_address_length = sizeof(client_address);
    char buffer[BUFFER_SIZE];
    char *response_message = "HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\n\r\n<!DOCTYPE html><html><body><h1>Hello, World!</h1></body></html>";

    // Create the server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        error("Error creating server socket.");
    }

    // Set server address to 0 and bind the socket to the server address
    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        error("Error binding socket to server address.");
    }

    // Listen for incoming connections from clients
    listen(server_socket, 5);

    // Accept incoming connections from clients and serve the response message
    while (1)
    {
        printf("\nWaiting for incoming connections...");
        fflush(stdout);

        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_length)) < 0)
        {
            error("Error accepting client connection.");
        }

        bzero(buffer, BUFFER_SIZE);

        int n = read(client_socket, buffer, BUFFER_SIZE);
        if (n < 0)
        {
            error("Error reading from socket.");
        }

        printf("\nReceived request from client:");
        printf("\n%s", buffer);

        n = write(client_socket, response_message, strlen(response_message));
        if (n < 0)
        {
            error("Error writing to socket.");
        }

        close(client_socket);
        printf("\nClosed client socket.");
        fflush(stdout);
    }

    return 0;
}