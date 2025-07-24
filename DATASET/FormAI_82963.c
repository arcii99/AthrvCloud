//FormAI DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 5

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Ken Thompson style Chat Server";
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for clients
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    // Accept incoming client connections
    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        char client_address[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(address.sin_addr), client_address, INET_ADDRSTRLEN);

        printf("Connection established with client %s:%d\n", client_address, ntohs(address.sin_port));

        // Start Chatting
        while(1) {
            // Read incoming messages from clients
            valread = read( new_socket , buffer, 1024);
            printf("Client: %s\n", buffer );

            // Check if client disconnects
            if (valread == 0) {
                printf("Client %s:%d has disconnected.\n", client_address, ntohs(address.sin_port));
                close(new_socket);
                break;
            }
            else {
                // Send message to clients
                send(new_socket , hello , strlen(hello) , 0 );
                printf("Server: %s\n", hello);
                memset(buffer, 0, sizeof(buffer));
            }
        }
    }
    
    return 0;
}