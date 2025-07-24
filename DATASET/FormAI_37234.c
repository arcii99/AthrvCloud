//FormAI DATASET v1.0 Category: Networking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

void handle_connection(int client_socket) {
    char buffer[BUFFER_SIZE];
    bool connected = true;
    while (connected) {
        memset(buffer, 0, BUFFER_SIZE);
        int read_size = read(client_socket, buffer, BUFFER_SIZE);
        if (read_size == -1) {
            perror("read");
            break;
        } else if (read_size == 0) {
            printf("Client disconnected\n");
            break;
        } else {
            printf("Received message: %s\n", buffer);
            if (strcmp(buffer, "quit") == 0) {
                printf("Client requested shutdown\n");
                break;
            } else {
                write(client_socket, buffer, strlen(buffer));
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in address;
    
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Listening on port %d\n", PORT);
    
    while (true) {
        socklen_t addr_size = sizeof(address);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&address, &addr_size)) == -1) {
            perror("accept");
            continue;
        }
        
        printf("Connection accepted from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        
        handle_connection(client_socket);
        
        close(client_socket);
    }
    
    return EXIT_SUCCESS;
}