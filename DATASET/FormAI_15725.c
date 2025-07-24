//FormAI DATASET v1.0 Category: Client Server Application ; Style: systematic
/* This is a sample C Client-Server application that allows the client to connect to the server using sockets and send a message to the server. The server then converts the message to uppercase and sends it back to the client. */

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

#define PORT 8888
#define BUFF_SIZE 1024

int main()
{
    int server_socket, new_socket, valread;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFF_SIZE] = {0};
    int opt = 1;
    int addrlen = sizeof(server_address);

    // Create socket file descriptor
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == 0)
    {
        perror("Cannot create socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    if ((new_socket = accept(server_socket, (struct sockaddr *)&server_address, (socklen_t*)&addrlen)) < 0)
    {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Read message from client
    valread = read(new_socket, buffer, BUFF_SIZE);

    // Convert message to uppercase
    for (int i = 0; buffer[i]; i++)
    {
        buffer[i] = toupper(buffer[i]);
    }

    // Send message back to client
    send(new_socket, buffer, strlen(buffer), 0);
    printf("Message sent\n");

    // Close socket
    close(new_socket);
    close(server_socket);

    return 0;
}