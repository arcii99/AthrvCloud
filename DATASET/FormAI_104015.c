//FormAI DATASET v1.0 Category: Client Server Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, socket_fd;
    struct sockaddr_in server_address, client_address;
    int addrlen = sizeof(server_address);
    char buffer[1024] = {0};
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Setting up the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // Attaching socket to the port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Starting to listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Listening on port %d...\n", PORT);
    
    int num_connections = 0;
    while (num_connections < 3) {
        // Accepting incoming connection
        if ((socket_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        printf("Incoming connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // Receiving data from client
        int valread = read(socket_fd, buffer, 1024);
        printf("Received message: %s\n", buffer);
        
        // Sending message back to client
        char *message = "Hello from server!";
        send(socket_fd, message, strlen(message), 0);
        printf("Message sent: %s\n", message);
        
        num_connections++;
        close(socket_fd);
    }
    
    return 0;
}