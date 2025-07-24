//FormAI DATASET v1.0 Category: Client Server Application ; Style: single-threaded
/* This is a simple example of a C client server application using TCP sockets, where the server sends a welcome message to the client and the client responds with a message containing the client's name. The program is implemented in a single-threaded style. */

#include <stdio.h>      /* For printf() */
#include <stdlib.h>     /* For exit() */
#include <string.h>     /* For memset() */
#include <sys/socket.h> /* For socket(), bind(), and connect() */
#include <netinet/in.h> /* For sockaddr_in */
#include <arpa/inet.h>  /* For htons() */
#include <unistd.h>     /* For close() */

#define MAX_MSG_SIZE 1024
#define PORT 8080

int main(int argc, char *argv[])
{
    int server_fd, client_fd, read_size;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_MSG_SIZE] = {0};
    char client_name[MAX_MSG_SIZE] = "";

    // Create a socket for the server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 1) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept the client connection
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr)) < 0)
    {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Send the welcome message to the client
    char *welcome_msg = "Welcome to my server!";
    send(client_fd, welcome_msg, strlen(welcome_msg), 0);

    // Receive the client's name
    read_size = recv(client_fd, buffer, MAX_MSG_SIZE, 0);
    strcpy(client_name, buffer);

    // Print the client's name
    printf("Client name: %s\n", client_name);

    // Close the socket
    close(server_fd);

    return 0;
}