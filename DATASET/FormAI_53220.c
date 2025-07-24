//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Dennis Ritchie
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

const int PORT = 8080;
const int MAX_BUF_SIZE = 1024;

void handle_request(int client_socket) {
    char buffer[MAX_BUF_SIZE];
    int valread = read(client_socket, buffer, MAX_BUF_SIZE);
    printf("%s\n", buffer);
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
}

int main() {
    struct sockaddr_in server_address, client_address;
    int server_socket, client_socket, address_len = sizeof(client_address);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0 ) {
        perror("Failed to bind socket");
        return -1;
    }

    if (listen(server_socket, 3) < 0) {
        perror("Failed to listen on socket");
        return -1;
    }
    printf("Server started and listening on port %d\n", PORT);

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&address_len)) < 0) {
            perror("Failed to accept incoming connection");
            return -1;
        }
        handle_request(client_socket);
    }

    close(server_socket);
    return 0;
}