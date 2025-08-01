//FormAI DATASET v1.0 Category: Networking ; Style: realistic
#include <stdio.h> // Standard Input/Output Library
#include <stdlib.h> // Standard Library
#include <string.h> // String Library 
#include <unistd.h> // UNIX Standard Library
#include <sys/types.h> // System Types Library
#include <sys/socket.h> // Socket Library
#include <netinet/in.h> // IPv4/IPv6 Library
#include <arpa/inet.h> // IP Address Manipulation Library

#define PORT 8080 // Port Number

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server!";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the specified IP address and port number
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accepting incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Reading incoming messages
    valread = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);

    // Sending a message to the client
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    return 0;
}