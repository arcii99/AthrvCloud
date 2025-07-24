//FormAI DATASET v1.0 Category: Socket programming ; Style: all-encompassing
#include <stdio.h>      /* for printf, strerror */
#include <stdlib.h>     /* for exit */
#include <string.h>     /* for memset */
#include <errno.h>      /* for errno */
#include <sys/types.h>  /* for socket */
#include <sys/socket.h> /* for socket, bind, listen, accept */
#include <netinet/in.h> /* for INADDR_ANY, struct sockaddr_in */
#include <unistd.h>     /* for write */

#define PORT 8080
#define MAX_PENDING_CONNECTIONS 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int server_fd, new_socket, val_read;
    struct sockaddr_in server_address;
    int opt = 1;
    int address_len = sizeof(server_address);
    char buffer[BUFFER_SIZE] = {0};
    char *message = "Hello from server";
     
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Error setsockopt");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons( PORT );
     
    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address))<0) {
        perror("Error bind");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, MAX_PENDING_CONNECTIONS) < 0) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }
    
    while(1) {
        // Accept the incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&server_address, (socklen_t*)&address_len))<0) {
            perror("Error accept");
            exit(EXIT_FAILURE);
        }
        
        // Send welcome message to client
        if (send(new_socket, message, strlen(message), 0) != strlen(message)) {
            perror("Error send");
        }
        
        // Receive message from client
        val_read = read( new_socket , buffer, BUFFER_SIZE);
        printf("%s\n",buffer );
        memset(buffer, 0, sizeof(buffer));

        // Close the connection
        close(new_socket);
    }
    
    return 0;
}