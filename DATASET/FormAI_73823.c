//FormAI DATASET v1.0 Category: Simple Web Server ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 2048

void send_response(int client_socket, char *response) {
    char buffer[MAX_REQUEST_SIZE];
    memset(buffer, 0, MAX_REQUEST_SIZE);
    sprintf(buffer, "HTTP/1.1 200 OK\nContent-Length: %ld\n\n%s", strlen(response), response);
    write(client_socket, buffer, strlen(buffer));
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    int bind_result = bind(server_socket, (struct sockaddr *)&address, sizeof(address));
    if (bind_result == -1) {
        printf("Error binding socket\n");
        exit(EXIT_FAILURE);
    }

    int listen_result = listen(server_socket, 10);
    if (listen_result == -1) {
        printf("Error listening on socket\n");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(EXIT_FAILURE);
        }

        char request[MAX_REQUEST_SIZE];
        memset(request, 0, MAX_REQUEST_SIZE);
        read(client_socket, request, MAX_REQUEST_SIZE);

        printf("Request: %s\n", request);

        char *response = "Hello, World!";
        send_response(client_socket, response);

        close(client_socket);
    }

    close(server_socket);
    return 0;
}