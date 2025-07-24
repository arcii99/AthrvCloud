//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int port = 8888;
    int server_sock, client_sock, c, read_size;
    char client_message[BUFSIZE], server_response[BUFSIZE];
     
    // Create socket
    server_sock = socket(AF_INET , SOCK_STREAM , 0);
    if (server_sock == -1) {
        perror("Failed to create socket");
        return 1;
    }
     
    // Prepare the sockaddr_in structure
    struct sockaddr_in server, client;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
     
    // Bind
    if (bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to bind");
        return 1;
    }
     
    // Listen
    listen(server_sock, 3);
     
    // Accept incoming connections
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(server_sock, (struct sockaddr *)&client, (socklen_t*)&c))) {
        pid_t pid;
        pid = fork();   // Separate process for each client
        
        if (pid == -1) {
            perror("Failed to fork");
            return 1;
        }
        
        if (pid == 0) { // Child process
            close(server_sock); // Close parent's socket
            while ((read_size = recv(client_sock, client_message, BUFSIZE, 0)) > 0) {
                // Forward request to server
                int server_socket = socket(AF_INET , SOCK_STREAM , 0);
                if (server_socket == -1) {
                    perror("Failed to create server socket");
                    return 1;
                }
                struct sockaddr_in server;
                server.sin_addr.s_addr = inet_addr("127.0.0.1");
                server.sin_family = AF_INET;
                server.sin_port = htons(8080);
                if (connect(server_socket, (struct sockaddr *)&server , sizeof(server)) < 0) {
                    perror("Failed to connect to server");
                    return 1;
                }
                if (send(server_socket, client_message, strlen(client_message), 0) < 0) {
                    perror("Failed to forward request to server");
                    return 1;
                }
                // Receive response from server and send it to client
                if (recv(server_socket, server_response, BUFSIZE, 0) < 0) {
                    perror("Failed to receive server response");
                    return 1;
                }
                if (send(client_sock, server_response, strlen(server_response), 0) < 0) {
                    perror("Failed to send server response to client");
                    return 1;
                }
                close(server_socket);
                memset(client_message, '\0', sizeof(client_message));
                memset(server_response, '\0', sizeof(server_response));
            }
             
            if (read_size == 0) {
                printf("Client disconnected\n");
            } else if (read_size == -1) {
                perror("Failed to receive request from client");
                return 1;
            }
             
            close(client_sock);
            return 0;
        } else if (pid > 0) { // Parent process
            close(client_sock); // Close child's socket
        }
    }
     
    if (client_sock < 0) {
        perror("Failed to accept connection");
        return 1;
    }
     
    return 0;
}