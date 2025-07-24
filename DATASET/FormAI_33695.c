//FormAI DATASET v1.0 Category: Socket programming ; Style: immersive
/* You find yourself amidst a dark and stormy night, with nothing but your trusty computer and a burning desire to learn C Socket programming. The rain comes down in sheets outside, and lightning illuminates the room in brief flashes. You take a deep breath and begin typing... */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    int sock_fd, client_fd, len;
    char buffer[1024];
    struct sockaddr_in server_addr, client_addr;

    // Create a socket for the server
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a specific IP address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock_fd, 5) != 0) {
        perror("Error listening on socket");
        exit(1);
    }

    // Accept incoming connections from clients
    len = sizeof(client_addr);
    client_fd = accept(sock_fd, (struct sockaddr*)&client_addr, &len);
    if (client_fd < 0) {
        perror("Error accepting incoming connection");
        exit(1);
    }
    
    // Communicate with the client
    printf("Connection established with client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    memset(buffer, 0, sizeof(buffer));
    read(client_fd, buffer, sizeof(buffer));
    printf("Client sent message: %s\n", buffer);

    // Send a response to the client
    strcpy(buffer, "Hello from the server");
    write(client_fd, buffer, strlen(buffer));

    // Close the connection with the client
    close(client_fd);
    printf("Connection with client %s:%d closed\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Close the socket
    close(sock_fd);
    printf("Socket closed\n");

    return 0;
}