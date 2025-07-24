//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int client_socket;
    struct sockaddr_in server_address;
    char message[BUFFER_SIZE], server_response[BUFFER_SIZE];

    if(argc < 2)
    {
        printf("Usage: %s <ipaddress>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // creating a client socket
    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // setting up server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);

    // converting IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }

    // connecting to server
    if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        printf("Enter message: ");
        fgets(message, BUFFER_SIZE, stdin);

        // send message to server
        send(client_socket, message, strlen(message), 0);

        // receive response from server
        if(recv(client_socket, server_response, BUFFER_SIZE, 0) <= 0)
        {
            printf("Connection closed\n");
            break;
        }

        printf("Server response: %s", server_response);
    }

    // closing the client socket
    close(client_socket);

    return 0;
}