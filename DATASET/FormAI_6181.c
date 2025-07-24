//FormAI DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

void handle_client(int sock) {
    char buffer[BUFFER_SIZE];
    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, &buffer, BUFFER_SIZE, 0);
        if(bytes_received < 0) {
            printf("Error receiving data from client.\n");
            break;
        }
        if(bytes_received == 0) {
            printf("Client disconnected.\n");
            break;
        }
        printf("Received message: %s\n", buffer);
        int bytes_sent = send(sock, buffer, bytes_received, 0);
        if(bytes_sent < 0) {
            printf("Error sending data to client.\n");
            break;
        }
    }
    close(sock);
}

int main() {
    // Create TCP socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0) {
        printf("Error creating socket.\n");
        return 1;
    }

    // Bind socket to port and address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(8888);
    
    if(bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf("Error binding socket to port.\n");
        return 1;
    }

    // Listen for incoming connections
    if(listen(server_socket, MAX_CONNECTIONS) < 0) {
        printf("Error listening for incoming connections.\n");
        return 1;
    }

    // Accept incoming connections and handle each one in a separate thread
    while(1) {
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_size);
        if(client_socket < 0) {
            printf("Error accepting incoming connection.\n");
            continue;
        }
        printf("Accepted incoming connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        handle_client(client_socket);
    }

    return 0;
}