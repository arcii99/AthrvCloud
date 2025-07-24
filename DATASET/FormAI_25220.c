//FormAI DATASET v1.0 Category: Client Server Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char *argv[]) {
    int socket_desc, new_socket, c;
    struct sockaddr_in server, client;
    char *message;
    char buffer[1024] = {0};
    
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    
    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    
    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return -1;
    }
    
    // Listen
    listen(socket_desc, 3);
    printf("Waiting for incoming connections...\n");
    
    c = sizeof(struct sockaddr_in);
    while ((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c))) {
        printf("Connection accepted from %s:%d\n",
               inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        
        // Send message to client
        message = "Welcome to my romantic server application\n";
        write(new_socket, message, strlen(message));
        
        // Receive message from client
        read(new_socket, buffer, 1024);
        printf("Client sent the following message:\n%s\n", buffer);
    }
    
    if (new_socket < 0) {
        perror("Accept failed");
        return -1;
    }
    
    return 0;
}