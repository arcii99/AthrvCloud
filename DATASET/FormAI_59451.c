//FormAI DATASET v1.0 Category: Client Server Application ; Style: real-life
// A chat client-server program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 5

int main(int argc, char const *argv[])
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char message[1024] = {0};
    char buffer[1024] = {0};

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("\nWaiting for connections...\n");

    while(1)
    {
        // Accept incoming connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Send message to client
        strcpy(buffer, "Connected to server...");
        send(new_socket, buffer, strlen(buffer), 0);
        printf("%s\n", buffer);

        // Receive messages from client
        while(1)
        {
            memset(buffer, 0, sizeof(buffer));
            read(new_socket, buffer, sizeof(buffer));

            printf("\nClient: %s\n", buffer);

            // Respond to client's message
            printf("Enter message to send to client: ");
            fgets(message, sizeof(message), stdin);
            send(new_socket, message, strlen(message), 0);
        }
    }

    return 0;
}