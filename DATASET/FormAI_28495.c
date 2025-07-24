//FormAI DATASET v1.0 Category: Client Server Application ; Style: portable
// This is a C client-server application example program for transferring files over sockets.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int server_socket, client_socket, file_desc, read_size;
    struct sockaddr_in server_address, client_address;
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
        error("ERROR: failed to create socket.");

    // Set server address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
        error("ERROR: failed to bind socket.");

    // Listen for connections
    listen(server_socket, 5);
    printf("Server is listening on port %d...\n", PORT);

    // Accept incoming connections
    socklen_t client_length = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_length);
    if (client_socket < 0)
        error("ERROR: failed to accept connection.");

    char filename[MAX_BUFFER_SIZE];
    bzero(buffer, MAX_BUFFER_SIZE);

    // Receive file name from client
    read(client_socket, buffer, MAX_BUFFER_SIZE);
    strcpy(filename, buffer);
    printf("Received file name: %s\n", filename);

    // Open file to write
    file_desc = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (file_desc < 0)
        error("ERROR: failed to open file.");

    // Read data from client and write to file
    bzero(buffer, MAX_BUFFER_SIZE);
    while ((read_size = read(client_socket, buffer, MAX_BUFFER_SIZE)) > 0)
        write(file_desc, buffer, read_size);

    if (read_size < 0)
        error("ERROR: failed to read data from socket.");

    printf("File transfer complete!\n");

    close(server_socket);
    close(client_socket);
    close(file_desc);

    return 0;
}