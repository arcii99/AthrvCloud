//FormAI DATASET v1.0 Category: Chat server ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080

void *client_handler(void *);

int main()
{
    int server_fd, new_socket, c;
    struct sockaddr_in server, client;
    char *message;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Could not create socket");
        return 1;
    }
    puts("Socket created");

    // Prepare sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Bind failed");
        return 1;
    }
    puts("Bind done");

    // Listen for incoming connections
    listen(server_fd, 3);

    puts("Waiting for incoming connections...");

    c = sizeof(struct sockaddr_in);

    // Accept incoming connections
    while ((new_socket = accept(server_fd, (struct sockaddr *)&client, (socklen_t *)&c)))
    {
        printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Send welcome message to client
        message = "Welcome to the chat server, type 'exit' to quit\n";
        write(new_socket, message, strlen(message));

        // Create a thread for the client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, client_handler, (void *)&new_socket) < 0)
        {
            perror("Could not create thread");
            return 1;
        }
    }

    if (new_socket < 0)
    {
        perror("Accept failed");
        return 1;
    }

    return 0;
}

void *client_handler(void *socket)
{
    int new_socket = *(int *)socket;
    int read_size;
    char *message, client_message[2000];

    // Receive messages from client
    while ((read_size = recv(new_socket, client_message, 2000, 0)) > 0)
    {
        // Set string terminating null byte on the end of the data read
        client_message[read_size] = '\0';

        // Exit if client sends "exit"
        if (strcmp(client_message, "exit\n") == 0 || strcmp(client_message, "exit\r\n") == 0)
        {
            close(new_socket);
            puts("Client disconnected");
            pthread_exit(NULL);
        }

        // Send message to all other clients
        message = client_message;
        write(new_socket, message, strlen(message));

        printf("Message from %d: %s", new_socket, message);
    }

    if (read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if (read_size == -1)
    {
        perror("Recv failed");
    }

    // Free the socket pointer
    free(socket);
    pthread_exit(NULL);
}