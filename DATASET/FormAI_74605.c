//FormAI DATASET v1.0 Category: Socket programming ; Style: lively
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // Creating a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Failed to create socket");
        return -1;
    }

    puts("Socket created successfully");

    // Setting up the sockaddr_in structure
    struct sockaddr_in server_address, client_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8000);

    // Binding the socket to the port
    if (bind(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Bind failed");
        return -1;
    }

    puts("Bind successfull");

    listen(sock, 3);

    puts("Waiting for incoming client connection");

    int client_sock, c = sizeof(client_address);

    while ((client_sock = accept(sock, (struct sockaddr *)&client_address, (socklen_t *)&c)))
    {
        puts("Connection accepted");

        // Message to be sent to the client
        char *message = "Hello from the server!";
        write(client_sock, message, strlen(message));

        // Receiving data from the client
        char client_message[2000];
        read(client_sock, client_message, 2000);
        printf("Client's message: %s\n", client_message);
    }

    if (client_sock < 0)
    {
        perror("Accept failed");
        return -1;
    }

    close(sock);

    return 0;
}