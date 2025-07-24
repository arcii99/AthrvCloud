//FormAI DATASET v1.0 Category: Client Server Application ; Style: medieval
/* Medieval Style Chat Application */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_LENGTH 1024

int main(int argc, char *argv[])
{
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[MAX_MSG_LENGTH], server_message[MAX_MSG_LENGTH];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
        return 1;
    }

    // Prepare server sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        puts("Bind failed");
        return 1;
    }

    puts("Waiting for incoming connections...");
    listen(socket_desc, 3);

    // Accept incoming connection
    c = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
    if (client_sock < 0)
    {
        puts("Accept failed");
        return 1;
    }
    puts("Connection accepted");

    // Send and receive messages with client
    while (1)
    {
        memset(client_message, '\0', MAX_MSG_LENGTH);
        memset(server_message, '\0', MAX_MSG_LENGTH);

        // Receive a message from client
        if (recv(client_sock, client_message, MAX_MSG_LENGTH, 0) < 0)
        {
            puts("Receive failed");
            break;
        }
        printf("Client: %s\n", client_message);

        // Check for exit command
        if (strcmp(client_message, "exit") == 0)
        {
            strcpy(server_message, "Goodbye, traveler!");
            break;
        }

        // Build server message
        strcpy(server_message, "Greetings, noble traveler! You said: ");
        strcat(server_message, client_message);

        // Send message back to client
        if (send(client_sock, server_message, strlen(server_message), 0) < 0)
        {
            puts("Send failed");
            break;
        }
    }

    // Close sockets and exit
    close(client_sock);
    close(socket_desc);
    return 0;
}