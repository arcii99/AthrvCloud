//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8888

int main() {
    int server_socket;
    struct sockaddr_in server_address;
    
    // create TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error: socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // set server settings
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // bind socket
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error: socket binding failed");
        exit(EXIT_FAILURE);
    }
    
    // listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Error: listening failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server is listening on port %d...\n", PORT);
    
    while (1) {
        int client_socket;
        struct sockaddr_in client_address;
        char buffer[1024] = {0};
        char reply[] = "Hello from the server!";
        int read_size;
        
        // accept incoming connections
        int address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&address_length);
        if (client_socket < 0) {
            perror("Error: accepting connection failed");
            exit(EXIT_FAILURE);
        }
        
        printf("Client %s:%d connected.\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // receive data from client
        read_size = recv(client_socket, buffer, 1024, 0);
        if (read_size < 0) {
            perror("Error: receiving data failed");
            exit(EXIT_FAILURE);
        }
        
        printf("Received message from client: %s\n", buffer);
        
        // send reply to client
        if (send(client_socket, reply, strlen(reply), 0) < 0) {
            perror("Error: sending data failed");
            exit(EXIT_FAILURE);
        }
        
        printf("Reply sent to client.\n");
        
        close(client_socket);
        printf("Client %s:%d disconnected.\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    }
    
    close(server_socket);
    
    return 0;
}