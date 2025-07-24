//FormAI DATASET v1.0 Category: Chat server ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int server_fd, new_socket, valread;
    struct sockaddr_in server_addr;
    int opt = 1;
    int addrlen = sizeof(server_addr);
    char buffer[BUFFER_SIZE] = {0};
 
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
     
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
     
    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
 
    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
     
    // Wait for incoming connections and handle them
    while (1) {
        printf("Waiting for a client to connect...\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        printf("Connection established!\n");
     
        // Receive messages from the client
        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            valread = read(new_socket, buffer, BUFFER_SIZE);
            if (valread < 0) {
                perror("read failed");
                break;
            }
            printf("Client says: %s\n", buffer);
     
            // Send response to the client
            if (strncmp(buffer, "QUIT", strlen("QUIT")) == 0) {
                printf("Client disconnected...\n\n");
                break;
            } else {
                char response[BUFFER_SIZE] = "Server says: ";
                strcat(response, buffer);
                if (send(new_socket, response, strlen(response), 0) < 0) {
                    perror("send failed");
                    break;
                }
            }
        }
     
        // Close the connection
        close(new_socket);
    }
 
    return 0;
}