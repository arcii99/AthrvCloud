//FormAI DATASET v1.0 Category: Socket programming ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888
#define BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char* message = "Hello from server!";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8888
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
      
    // Binding socket to the specified address and port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address))<0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening on the socket for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d...\n", PORT);
      
    // Accepting and handling incoming connections
    while(1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen))<0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New connection, IP address: %s, port: %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Sending welcome message to the client
        send(new_socket, message, strlen(message), 0);
        printf("Welcome message sent\n");

        // Receiving data from the client
        valread = read(new_socket, buffer, BUFFER_SIZE);
        printf("Message from client: %s\n", buffer);
        memset(buffer, 0, BUFFER_SIZE);
          
        // Closing the connection with client
        close(new_socket);
        printf("Connection closed\n");
    }

    return 0;
}