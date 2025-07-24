//FormAI DATASET v1.0 Category: Chat server ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 3000
#define MAX_CONNECTIONS 10
#define MESSAGE_SIZE 200

int main()
{
    int server_socket, new_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t address_length = sizeof(server_address);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server address and port
    memset(&server_address, '0', address_length);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket with the server address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, address_length) < 0)
    {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0)
    {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d ...\n", PORT);

    // Accept incoming connections
    while (1)
    {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_address, &address_length)) < 0)
        {
            perror("Accept error");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Send welcome message to the client
        char *welcome_message = "Welcome to the chat!\n";
        send(new_socket, welcome_message, strlen(welcome_message), 0);

        // Receive messages from the client until they disconnect or send "exit"
        char message[MESSAGE_SIZE];
        int message_length;
        while ((message_length = recv(new_socket, message, MESSAGE_SIZE, 0)) > 0)
        {
            message[message_length] = '\0';
            printf("Received message from %s:%d: %s\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), message);

            // Check if the client wants to exit the chat
            if (strcmp(message, "exit") == 0)
            {
                printf("Client %s:%d has left the chat\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                close(new_socket);
                break;
            }

            // Broadcast the message to all clients connected to the chat
            for (int i = 0; i <= MAX_CONNECTIONS; i++)
            {
                if (i != server_socket && i != new_socket)
                {
                    send(i, message, strlen(message), 0);
                }
            }

            memset(message, '\0', MESSAGE_SIZE);
        }
    }

    close(server_socket);

    return 0;
}