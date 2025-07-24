//FormAI DATASET v1.0 Category: Simple Web Server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void handle_request(int client_socket) {
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    printf("Request: %s\n", buffer);

    char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";
    write(client_socket, response, strlen(response));
    close(client_socket);
}

int main(int argc, char const *argv[]) {
    int server_socket = 0, client_socket = 0;
    struct sockaddr_in server_address;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Could not create socket.");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Bind failed.");
        return -1;
    }

    if (listen(server_socket, 5) < 0) {
        printf("Could not listen on socket.");
        return -1;
    }

    printf("Server is listening on port %d.\n", PORT);

    while (1) {
        client_socket = accept(server_socket, NULL, NULL);
        handle_request(client_socket);
    }

    return 0;
}