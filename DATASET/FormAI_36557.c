//FormAI DATASET v1.0 Category: Simple Web Server ; Style: retro
// Retro Style C Simple Web Server example program
// by Chatbot

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 5

void handle_request(int client_socket) {
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    printf("%s\n", buffer);
    char* response = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello, World!";
    write(client_socket, response, strlen(response));
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in address = {0};

    // create server socket
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // setup server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind the socket to the specified address and port
    if(bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // start listening for incoming connections
    if(listen(server_socket, BACKLOG) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // handle incoming connections
    printf("Listening on port %d...\n", PORT);
    while(1) {
        int addrlen = sizeof(address);
        if((client_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        handle_request(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}