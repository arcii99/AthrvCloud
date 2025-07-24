//FormAI DATASET v1.0 Category: Networking ; Style: scientific
/*
 * This program demonstrates the use of sockets for inter-process communication.
 * It creates a server socket that listens for incoming connections from clients.
 * Once a client connects, the server reads the data sent by the client and writes
 * a response back. This program uses the TCP protocol for communication. 
 */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main()
{
    // Create a socket for the server to listen on
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Set the socket options
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Bind the socket to a port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    // Listen for incoming connections
    listen(server_socket, 5);

    // Accept incoming connections and handle them
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);

    // Read data from the client
    char buffer[256];
    read(client_socket, buffer, sizeof(buffer));

    // Process the data
    int input = atoi(buffer);
    int output = input * 2;

    // Write the response back to the client
    char response[256];
    sprintf(response, "%d", output);
    write(client_socket, response, strlen(response));

    // Close the sockets
    close(client_socket);
    close(server_socket);

    return 0;
}