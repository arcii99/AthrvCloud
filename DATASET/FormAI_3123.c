//FormAI DATASET v1.0 Category: Socket programming ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080
#define MAX_BUFFER 1024

int main(int argc, char const *argv[])
{
    int client_fd, valread;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER] = {0};
    char *hello = "Hello from client";

    // create socket file descriptor
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // assign values to server_address structure
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // convert IP address from text to binary format
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) 
    {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // connect to the server socket
    if (connect(client_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // send message to server
    send(client_fd, hello, strlen(hello), 0);
    printf("Message sent to server.\n");

    // receive message from server
    valread = read(client_fd, buffer, MAX_BUFFER);
    printf("Message received from server: %s\n", buffer);

    // close the client socket
    close(client_fd);
    return 0;
}