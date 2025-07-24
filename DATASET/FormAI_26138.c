//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 4096

void forward_client_request(int client_socket, struct sockaddr_in server_address);
void forward_server_response(int client_socket, int server_socket);

int main(int argc, char *argv[]) {

    // Create and initialize server address structure
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(80); // Default to HTTP port

    // Create server socket
    int server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if(server_socket < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // Bind server socket to address and port
    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        return 1;
    }

    // Start listening for incoming client connections
    if(listen(server_socket, SOMAXCONN) < 0) {
        perror("Failed to listen for connections");
        return 1;
    }

    // Accept incoming client connections and forward requests to server
    while(1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if(client_socket < 0) {
            perror("Failed to accept client connection");
            continue;
        }
        printf("Accepted client connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        forward_client_request(client_socket, server_address);
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}

void forward_client_request(int client_socket, struct sockaddr_in server_address) {

    char buffer[BUFFER_SIZE];

    // Receive request from client
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if(bytes_received < 0) {
        perror("Failed to receive request from client");
        return;
    }
    printf("Received request from client:\n%s", buffer);

    // Create socket for communicating with server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0) {
        perror("Failed to create socket for server");
        return;
    }

    // Connect to server
    if(connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        return;
    }

    // Forward request to server
    int bytes_sent = send(server_socket, buffer, bytes_received, 0);
    if(bytes_sent < 0) {
        perror("Failed to send request to server");
        return;
    }

    // Receive response from server and forward to client
    forward_server_response(client_socket, server_socket);

    // Close server socket
    close(server_socket);

}

void forward_server_response(int client_socket, int server_socket) {

    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive response from server
    do {
        bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);
        if(bytes_received < 0) {
            perror("Failed to receive response from server");
            break;
        }
        if(bytes_received > 0) {
            // Forward response to client
            int bytes_sent = send(client_socket, buffer, bytes_received, 0);
            if(bytes_sent < 0) {
                perror("Failed to send response to client");
                break;
            }
        }
    } while(bytes_received > 0);

    printf("Forwarded server response to client\n");

}