//FormAI DATASET v1.0 Category: Networking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    memset(&server_address, '0', sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);

    if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    char *message = "Hello Server";
    send(client_socket, message, strlen(message), 0);

    printf("Message sent to Server.\n");

    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    printf("Response from Server: %s\n",buffer );

    return 0;
}