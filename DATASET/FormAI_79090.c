//FormAI DATASET v1.0 Category: Client Server Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *arg);

int main(int argc, char const *argv[])
{
    int server_fd, client_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set server socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind server socket to port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // start listening for incoming connections
    if (listen(server_fd, 10) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // accept new client connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // create new thread to handle client
        pthread_t t;
        if (pthread_create(&t, NULL, handle_client, (void *)&client_fd) < 0)
        {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

void *handle_client(void *arg)
{
    char buffer[BUFFER_SIZE] = {0};
    int client_fd = *(int *)arg;

    // read client message
    int read_size;
    while ((read_size = read(client_fd, buffer, sizeof(buffer))) > 0)
    {
        printf("client message: %s", buffer);

        // send server response
        if (write(client_fd, buffer, strlen(buffer)) < 0)
        {
            perror("write failed");
            exit(EXIT_FAILURE);
        }

        // clear buffer
        memset(buffer, 0, sizeof(buffer));
    }

    // close client socket
    close(client_fd);

    return NULL;
}