//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: synchronous
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <arpa/inet.h>

#define MY_PORT     9999 
#define IP_ADDRESS  "127.0.0.1" 
#define BACK_LOG    10 
#define BUF_SIZE    1024 

void client_handler(int client_socket) { 
    char buffer[BUF_SIZE]; 
    int byte_count; 

    while ((byte_count = recv(client_socket, buffer, BUF_SIZE, 0)) > 0) { 
        if (send(client_socket, buffer, byte_count, 0) < 0) { 
            perror("Error sending to client"); 
            exit(EXIT_FAILURE); 
        } 
        memset(buffer, '\0', BUF_SIZE); 
    } 

    if (byte_count < 0) { 
        perror("Error receiving from server"); 
        exit(EXIT_FAILURE); 
    } 

    close(client_socket); 
} 

int main() { 
    int server_socket, client_socket; 
    struct sockaddr_in server_addr, client_addr; 
    socklen_t client_addr_len; 

    memset(&server_addr, '\0', sizeof(server_addr)); 

    server_addr.sin_family = AF_INET; 
    server_addr.sin_port = htons(MY_PORT); 
    server_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS); 

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
        perror("Error creating socket"); 
        exit(EXIT_FAILURE); 
    } 

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) { 
        perror("Error binding socket"); 
        exit(EXIT_FAILURE); 
    } 

    if (listen(server_socket, BACK_LOG) < 0) { 
        perror("Error listening for connections"); 
        exit(EXIT_FAILURE); 
    } 

    printf("Proxy Server listening on %s:%d\n", IP_ADDRESS, MY_PORT); 

    while(1) { 
        client_addr_len = sizeof(client_addr); 

        if ((client_socket = accept(server_socket, (struct sockaddr  *)&client_addr, &client_addr_len)) < 0) { 
            perror("Error accepting client connection"); 
            exit(EXIT_FAILURE); 
        } 

        printf("Connection received from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port)); 

        client_handler(client_socket); 
        printf("Connection closed from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port)); 
    } 

    close(server_socket); 
    return 0; 
}