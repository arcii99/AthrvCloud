//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sock_desc, conn_desc, cli_len;
    struct sockaddr_in server, client;
    char message[] = "Hello, World!";

    // Create socket
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_desc == -1)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    // Bind socket to server address
    if (bind(sock_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(sock_desc, 1) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for incoming connections...\n");

    while (1)
    {
        // Accept connection
        cli_len = sizeof(client);
        conn_desc = accept(sock_desc, (struct sockaddr *)&client, (socklen_t *)&cli_len);
        if (conn_desc < 0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Incoming connection from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Send message to client
        if (send(conn_desc, message, strlen(message), 0) < 0)
        {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        printf("Message sent successfully!\n");

        // Close connection
        close(conn_desc);

        printf("Connection closed.\n");
    }

    // Close socket
    close(sock_desc);

    return 0;
}