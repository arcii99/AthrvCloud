//FormAI DATASET v1.0 Category: Simple Web Server ; Style: calm
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define RESPONSE "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nHello World!"

int main(int argc, char const *argv[]) {
    // create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    // bind socket to port 8080
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == -1) {
        printf("Failed to bind socket to port 8080\n");
        return 1;
    }

    // listen for connections
    if (listen(server_fd, 10) == -1) {
        printf("Failed to listen on socket\n");
        return 1;
    }

    printf("Listening on port 8080...\n");

    struct sockaddr_in client_address;
    int client_address_length = sizeof(client_address);
    int client_fd = accept(server_fd, (struct sockaddr*)&client_address, (socklen_t*)&client_address_length);

    // receive and print request
    char buffer[30000] = {0};
    if (read(client_fd, buffer, 30000) == -1) {
        printf("Failed to read request\n");
        return 1;
    }
    printf("%s\n", buffer);

    // send response
    if (write(client_fd, RESPONSE, strlen(RESPONSE)) == -1) {
        printf("Failed to send response\n");
        return 1;
    }

    printf("HTTP response sent!\n");

    // close sockets
    close(client_fd);
    close(server_fd);

    return 0;
}