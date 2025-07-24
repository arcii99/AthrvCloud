//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE];
    const char *hello = "Hello from the server!";
    int opt = 1;
    int addrlen = sizeof(address);

    // create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // set address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", ntohs(address.sin_port));

    while (1) {
        // accept new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t*)&addrlen))<0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected from %s:%d\n",
               inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // send greeting message to client
        send(new_socket, hello, strlen(hello), 0);

        // receive message from client
        memset(buffer, 0, BUFFER_SIZE);
        valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread <= 0) {
            printf("Client disconnected from %s:%d\n",
                   inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            close(new_socket);
            continue;
        }

        printf("Received message from client (%s:%d): %s\n",
               inet_ntoa(address.sin_addr), ntohs(address.sin_port), buffer);

        // send response to client
        char response[BUFFER_SIZE];
        sprintf(response, "Hello %s, I am the server!", buffer);
        send(new_socket, response, strlen(response), 0);
    }

    return 0;
}