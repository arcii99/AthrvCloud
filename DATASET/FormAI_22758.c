//FormAI DATASET v1.0 Category: Socket programming ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void) {
    // create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // setup server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);
    
    // bind socket to server address
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Socket bind failed");
        exit(EXIT_FAILURE);
    }
    
    // listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    // accept incoming connection
    struct sockaddr_in client_addr;
    socklen_t client_addrlen = sizeof(client_addr);
    int clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addrlen);
    if (clientfd == -1) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    
    // communicate with client
    char buffer[1024] = {0};
    int bytes_received = read(clientfd, buffer, sizeof(buffer));
    printf("Client says: %s\n", buffer);
    send(clientfd, "Hello from server", strlen("Hello from server"), 0);
    
    // close sockets
    close(clientfd);
    close(sockfd);
    
    return 0;
}