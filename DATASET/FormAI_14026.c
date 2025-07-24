//FormAI DATASET v1.0 Category: Socket programming ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int server_socket, client_socket, read_length, total_length;
    struct sockaddr_in server_address, client_address;
    char server_response[1024], client_request[1024], server_message[1024];
    socklen_t address_length = sizeof(server_address);

    // Creating socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting up server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY; // Accept any incoming address
    server_address.sin_port = htons(8888); // Listening port

    // Binding socket to address and port number
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, 10) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening for incoming connections\n");

    // Accept incoming connection
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&address_length)) < 0)
    {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from client: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    while (1)
    {
        // Empty the buffer
        memset(client_request, 0, sizeof(client_request));
        memset(server_message, 0, sizeof(server_message));

        // Read the message from client
        if ((read_length = read(client_socket, client_request, 1024)) == 0)
            break;

        total_length += read_length;

        printf("Client request: %s\n", client_request);

        // Reply to client
        strcpy(server_message, "Server received message: ");
        strcat(server_message, client_request);
        strcat(server_message, "\n");
        strcpy(server_response, server_message);

        write(client_socket, server_response, strlen(server_response));
    }

    printf("Total bytes received: %d\n", total_length);

    close(server_socket);
    close(client_socket);

    return 0;
}