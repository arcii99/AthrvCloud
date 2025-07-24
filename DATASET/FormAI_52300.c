//FormAI DATASET v1.0 Category: Socket programming ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    // create a socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("Error creating socket: ");
        exit(EXIT_FAILURE);
    }
    
    // set up the server address
    socklen_t addr_len;
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(42069);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    
    // bind the socket to the address
    if (bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("Error binding socket: ");
        exit(EXIT_FAILURE);
    }
    
    // listen for connections
    if (listen(sock_fd, 5) == -1) {
        perror("Error listening: ");
        exit(EXIT_FAILURE);
    }
    
    // accept connections and send messages
    while (1) {
        int client_fd = accept(sock_fd, (struct sockaddr *)NULL, NULL);
        if (client_fd == -1) {
            perror("Error accepting connection: ");
            exit(EXIT_FAILURE);
        }
        
        send(client_fd, "Hello client, I'm a funny server!", 34, 0);
        
        // receive a message from the client
        char buffer[1024];
        recv(client_fd, buffer, 1024, 0);
        printf("Client says: %s\n", buffer);
        
        close(client_fd);
    }
    
    close(sock_fd);
    return 0;
}