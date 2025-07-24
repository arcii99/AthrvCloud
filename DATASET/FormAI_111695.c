//FormAI DATASET v1.0 Category: Networking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main()
{
    struct sockaddr_in server_address, client_address;
    int server_fd, new_socket, client_socket, addrlen = sizeof(client_address);
    char buffer[1024] = {0};
    char message[50] = "Hello, this is a chatbot program!";

    // Creating a socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Creating server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("Error while Listening");
        exit(EXIT_FAILURE);
    }

    // Accepting incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&addrlen)) < 0)
    {
        perror("Error while accepting connection");
        exit(EXIT_FAILURE);
    }

    // Converting client address to string
    char *client_ip = inet_ntoa(client_address.sin_addr);
    printf("\n[+] New Connection from %s:%d\n", client_ip, ntohs(client_address.sin_port));

    // Sending message to the client
    send(new_socket, message, strlen(message), 0);

    // Receiving message from the client
    int valread = read(new_socket, buffer, 1024);
    printf("\nClient: %s\n", buffer);

    // Closing the connection sockets
    close(new_socket);
    close(server_fd);
    printf("\n[-] Connection closed...\n");

    return 0;
}