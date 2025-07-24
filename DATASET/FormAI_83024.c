//FormAI DATASET v1.0 Category: Simple Web Server ; Style: modular
// A modular C Simple Web Server example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8888
#define MAX_CONNECTIONS 50
#define MAX_REQUEST_LENGTH 2048
#define RESPONSE_TEMPLATE "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n%s"

void handle_request(int client_socket, char *request)
{
    char *response;
    char *html = "<html><head><title>Welcome to My Web Server</title></head><body><h1>Hello World!</h1></body></html>";

    response = malloc(strlen(html) + strlen(RESPONSE_TEMPLATE));
    sprintf(response, RESPONSE_TEMPLATE, strlen(html), html);
    write(client_socket, response, strlen(response));
    free(response);
}

int main()
{
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    char request[MAX_REQUEST_LENGTH];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket\n");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        perror("Failed to listen\n");
        exit(1);
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket == -1) {
            perror("Failed to accept\n");
            exit(1);
        }

        int bytes_read = read(client_socket, request, MAX_REQUEST_LENGTH);
        if (bytes_read == -1) {
            perror("Failed to read from socket\n");
            exit(1);
        }

        handle_request(client_socket, request);
        close(client_socket);
    }

    close(server_socket);

    return 0;
}