//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024 // Maximum message size
#define MAX_CLIENTS 10 // Maximum number of clients supported
#define PORT 9000 // Port number for server

int main()
{
    int server_fd, new_socket, valread, sd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};
    char message[MAX_BUFFER_SIZE];

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        perror("Socket failed");

    // Attach socket to port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
        perror("Setsockopt failed");

    // Configure address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
        perror("Bind failed");

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0)
        perror("Listen failed");

    // Accept incoming connections and handle clients
    while (1)
    {
        // Accept connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0)
            perror("Accept failed");

        printf("New client connected\n");

        // Receive and send data
        while ((valread = read(new_socket, buffer, MAX_BUFFER_SIZE)) > 0)
        {
            printf("Received message: %s\n", buffer);
            sprintf(message, "ACK: %s", buffer);
            send(new_socket, message, strlen(message), 0);
            memset(buffer, 0, MAX_BUFFER_SIZE);
            memset(message, 0, MAX_BUFFER_SIZE);
        }

        // Client disconnected
        printf("Client disconnected\n");
    }

    return 0;
}