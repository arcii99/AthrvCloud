//FormAI DATASET v1.0 Category: Networking ; Style: satisfied
// A satisfied-style Networking example program 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int sock_fd, new_sock_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    int opt = 1;

    // Creating socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to port 
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
     
    // Bind the socket to the server address 
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }
  
    if (listen(sock_fd, 3) < 0) {
        perror("Failed to listen to incoming requests");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections on port %d...\n", PORT);
    int addr_len, read_val;
    
    while (1) {
        addr_len = sizeof(client_addr);
        if ((new_sock_fd = accept(sock_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len)) < 0) {
            perror("Failed to accept new connection");
            exit(EXIT_FAILURE);
        }

        char* client_ip = inet_ntoa(client_addr.sin_addr);
        printf("New Connection from %s:%d\n", client_ip, ntohs(client_addr.sin_port));
        
        // Read data from client
        read_val = read(new_sock_fd, buffer, 1024);
        printf("Client says: %s\n", buffer);

        // Send message to client
        char* message = "Connected Successfully!";
        send(new_sock_fd, message, strlen(message), 0);
        printf("Message sent to client\n");

        // Close the connection
        close(new_sock_fd);
    }
    return 0;
}