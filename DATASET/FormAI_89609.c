//FormAI DATASET v1.0 Category: Client Server Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char const *argv[]) {
    int server_socket, client_socket, val_read;
    struct sockaddr_in server_address, client_address;
    char buffer[MAX_BUFFER_SIZE] = {0};
    
    // create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        error("Error creating server socket");
    
    // set server properties
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // bind server socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
        error("Error binding socket to address");
    
    // listen for incoming connections
    if (listen(server_socket, 5) < 0)
        error("Error listening for incoming connections");
    
    // accept incoming connections
    socklen_t client_address_len = sizeof(client_address);
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len)) < 0)
        error("Error accepting incoming connection");
    
    // communicate with client
    while(1) {
        memset(buffer, 0, sizeof(buffer));
        val_read = read(client_socket, buffer, MAX_BUFFER_SIZE);
        if (val_read < 0)
            error("Error reading from client");
        printf("Client: %s\n", buffer);
        printf("Server: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        if (send(client_socket, buffer, strlen(buffer), 0) < 0)
            error("Error sending to client");
        if (strcmp(buffer, "bye\n") == 0)
            break;
    }
    
    // close sockets
    close(client_socket);
    close(server_socket);
    
    return 0;
}