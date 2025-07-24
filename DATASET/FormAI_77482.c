//FormAI DATASET v1.0 Category: Client Server Application ; Style: authentic
// A simple client-server application in C
// The client sends a string to the server and the server reverses it and sends it back

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char reverse_buffer[1024] = {0};
    int bytes_read;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        error("Socket creation failed");
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        error("Socket setsockopt failed");
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(SERVER_IP);
    address.sin_port = htons(PORT);

    // Bind socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        error("Socket bind failed");
    }

    // Listen for incoming connections
    if (listen(server_fd, 1) < 0)
    {
        error("Socket listen failed");
    }

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0)
    {
        error("Socket accept failed");
    }

    // Receive string from the client
    bytes_read = read(new_socket, buffer, 1024);
    printf("Received string from client: %s\n", buffer);

    // Reverse the string
    int len = strlen(buffer);
    for(int i = len-1; i >= 0; i--)
    {
        reverse_buffer[len-i-1] = buffer[i];
    }

    // Send reversed string to the client
    send(new_socket, reverse_buffer, strlen(reverse_buffer), 0);
    printf("Reversed string sent to client: %s\n", reverse_buffer);

    // Close the sockets
    close(new_socket);
    close(server_fd);

    return 0;
}