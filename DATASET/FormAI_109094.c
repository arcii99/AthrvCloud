//FormAI DATASET v1.0 Category: Client Server Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 256
#define PORT 8888

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;
    char message[BUF_SIZE];
    
    // Create server socket
    serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1) {
        perror("Server socket creation error");
        exit(1);
    }
    
    // Set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);
    
    // Assign address to server socket
    if (bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("Server bind error");
        exit(1);
    }
    
    // Listen for incoming connections
    if (listen(serv_sock, 5) == -1) {
        perror("Server listen error");
        exit(1);
    }
    
    printf("Waiting for clients...\n");
    
    while (1) {
        // Accept client connection
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr*) &clnt_addr, &clnt_addr_size);
        if (clnt_sock == -1) {
            perror("Server accept error");
            exit(1);
        }
        
        printf("Client connected\n");
        
        // Receive and print message from client
        if (recv(clnt_sock, message, BUF_SIZE, 0) == -1) {
            perror("Server receive error");
            exit(1);
        }
        
        printf("Client message: %s\n", message);
        
        // Send response to client
        if (send(clnt_sock, "I received your message", strlen("I received your message"), 0) == -1) {
            perror("Server send error");
            exit(1);
        }
        
        // Close client socket
        close(clnt_sock);
    }
    
    // Close server socket
    close(serv_sock);
    
    return 0;
}