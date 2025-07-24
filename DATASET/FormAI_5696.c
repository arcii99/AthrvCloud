//FormAI DATASET v1.0 Category: Socket programming ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *client_handler(void *);

int main(int argc, char *argv[])
{
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    int opt = 1;
    int address_length = sizeof(server_address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set server address details
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind server address to socket file descriptor
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port: %d\n", ntohs(server_address.sin_port));

    while (1)
    {
        // Wait for client connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&address_length)) < 0)
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Create a new thread to handle client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, client_handler, (void *)&client_fd) < 0)
        {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }

        // Detach thread to allow it to run independently
        pthread_detach(thread_id);
    }
}

void *client_handler(void *socket_fd)
{
    int fd = *(int *)socket_fd;
    char buffer[BUFFER_SIZE] = {0};

    while (1)
    {
        // Receive data from client
        int length = read(fd, buffer, BUFFER_SIZE);
        if (length == 0)
        {
            printf("Client disconnected\n");
            fflush(stdout);
            break;
        }
        else if (length < 0)
        {
            perror("read failed");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("Received message from client: %s\n", buffer);

            // Echo response back to client
            if (write(fd, buffer, strlen(buffer)) < 0)
            {
                perror("write failed");
                exit(EXIT_FAILURE);
            }
        }
    }

    // Close client socket file descriptor
    close(fd);

    return NULL;
}