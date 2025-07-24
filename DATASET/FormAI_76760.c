//FormAI DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void recursive_chat(int sock)
{
    char buffer[1024] = {0};
    char response[1024] = {0};
    int valread;

    // Read from client
    valread = read(sock, buffer, 1024);

    // If client disconnected
    if (valread == 0)
    {
        printf("Client disconnected\n");
        close(sock);
        return;
    }
    
    // Print client message
    printf("Client: %s\n", buffer);
    
    // Prepare server response
    strcat(response, "Server: ");
    strcat(response, buffer);
    strcat(response, " (");

    char sock_str[5];
    sprintf(sock_str, "%d", sock);
    strcat(response, sock_str);
    strcat(response, ")");

    // Send server response to client
    send(sock, response, strlen(response), 0);

    // Recursive call
    recursive_chat(sock);
}

int main(int argc, char const *argv[])
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket option
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connections...\n");

    // Accept connections recursively
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) > 0)
    {
        printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        recursive_chat(new_socket);

        printf("Connection closed\n");
    }

    return 0;
}