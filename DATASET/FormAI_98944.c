//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error opening socket");
        exit(1);
    }
    
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);
    
    if (bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }
    
    if (listen(sock_fd, 1) < 0) {
        perror("Error listening on socket");
        exit(1);
    }
    
    printf("Server is listening on port %d\n", ntohs(serv_addr.sin_port));
    
    struct sockaddr_in client_addr;
    socklen_t addrlen = sizeof(client_addr);
    
    int client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &addrlen);
    if (client_fd < 0) {
        perror("Error accepting connection");
        exit(1);
    }
    
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    
    int bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("Error receiving data");
        exit(1);
    }
    
    printf("Received message from client: %s\n", buffer);
    
    char *reply_message = "Hello client, I am your curious server!";
    
    if (send(client_fd, reply_message, strlen(reply_message), 0) < 0) {
        perror("Error sending data");
        exit(1);
    }
    
    close(client_fd);
    close(sock_fd);
    
    return 0;
}