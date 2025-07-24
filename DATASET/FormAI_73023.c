//FormAI DATASET v1.0 Category: Networking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Socket creation failed.\n");
        return -1;
    }

    // Attach socket to port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Socket attachment to port failed.\n");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Socket binding failed.\n");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        printf("Listening for incoming connections failed.\n");
        return -1;
    }

    printf("Server is waiting for incoming connections on port %d...\n", PORT);

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        printf("Error in accepting incoming connection.\n");
        return -1;
    }

    printf("Connection established with client %s:%d\n",
           inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    // Read the message from client
    valread = read( new_socket , buffer, 1024);
    printf("Client sent: %s\n",buffer );

    // Send back a message to client
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent to %s:%d\n",
           inet_ntoa(address.sin_addr), ntohs(address.sin_port));
    return 0;
}