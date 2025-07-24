//FormAI DATASET v1.0 Category: Socket programming ; Style: authentic
// This is a simple client-server program using sockets in C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int client_socket = 0, valread;
    struct sockaddr_in server_address;
    char message[1024] = {0};
    char *hello = "Hello from client";

    // create client socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error: Socket creation failed \n");
        return -1;
    }

    // specify server address and port number
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    
    // convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0)
    {
        printf("\nError: Invalid address/ Address not supported \n");
        return -1;
    }

    // connect the client socket to server socket
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("\nError: Connection Failed \n");
        return -1;
    }

    // send message to server
    send(client_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // receive response from server
    valread = read(client_socket, message, 1024);
    printf("%s\n", message);
    
    return 0;
}