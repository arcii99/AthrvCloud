//FormAI DATASET v1.0 Category: Client Server Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc,char *argv[])
{
    int client_socket = socket(AF_INET, SOCK_STREAM, 0); // create client socket
    struct sockaddr_in server_address;

    // set server address
    server_address.sin_family = AF_INET; // IPv4
    server_address.sin_port = htons(8080); // port number
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr); // IP address

    // connect to server
    if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Connection failed\n");
        return -1;
    }

    printf("Connected to server\n");

    char *message = "Hello from client"; // message to be sent

    // send message to server
    if(send(client_socket, message, strlen(message), 0) < 0)
    {
        printf("Send failed\n");
        return -1;
    }

    printf("Message sent to server\n");

    char buffer[1024] = {0};

    // receive message from server
    if(recv(client_socket, buffer, 1024, 0) < 0)
    {
        printf("Receive failed\n");
        return -1;
    }

    printf("Message received from server: %s\n", buffer);

    close(client_socket); // close client socket

    return 0;
}