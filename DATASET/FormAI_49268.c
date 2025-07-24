//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    // First, we need to create a server socket
    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket_fd < 0)
        error("Uh oh! Something went wrong while creating the server socket!");

    // Then we need to set up the server address
    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    int port_number = 9001;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);

    // Now, let's bind the server socket to the address and port number
    if (bind(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
        error("Dagnabbit! We couldn't bind the socket to the server address and port number!");

    // Time to listen for connections
    listen(server_socket_fd, 5);

    // Let's accept some connections
    struct sockaddr_in client_address;
    socklen_t client_size = sizeof(client_address);
    int client_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_address, &client_size);

    if (client_socket_fd < 0)
        error("Oh no! We couldn't accept the client connection!");

    // Now, we read from the client socket and print the message
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    int n = read(client_socket_fd, buffer, sizeof(buffer) - 1);

    if (n < 0)
        error("Son of a biscuit! We couldn't read from the client socket!");

    printf("Received message from client: %s\n", buffer);

    // Finally, we respond to the client
    const char* message = "Why did the programmer quit his job? He didn't get arrays.\n";
    n = write(client_socket_fd, message, strlen(message));

    if (n < 0)
        error("Oh boy, we couldn't respond to the client! They'll think we're rude!");

    // Time to close the sockets and exit gracefully
    close(client_socket_fd);
    close(server_socket_fd);

    return 0;
}