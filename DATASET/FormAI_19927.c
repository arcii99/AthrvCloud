//FormAI DATASET v1.0 Category: Simple Web Server ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_REQUEST_LENGTH 1024
#define SERVER_PORT 8000

int main(void) {
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[MAX_REQUEST_LENGTH];

    // Prepare the server socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Error: Could not create socket\n");
        exit(EXIT_FAILURE);
    }
    printf("Server socket created\n");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(SERVER_PORT);

    // Bind the socket to the server address and port
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: Bind failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Bind done\n");

    // Listen for incoming connections
    listen(socket_desc, 5);
    printf("Waiting for incoming connections...\n");

    c = sizeof(struct sockaddr_in);

    // Accept an incoming connection
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
    if (client_sock < 0) {
        printf("Error: Accept failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Connection accepted\n");

    // Receive the request message from the client
    memset(client_message, '\0', MAX_REQUEST_LENGTH);
    if ((read_size = recv(client_sock, client_message, MAX_REQUEST_LENGTH, 0)) < 0) {
        printf("Error: Receive failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Request received: %s\n", client_message);

    // Send the response message to the client
    char *response_message = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Welcome to my curious web server!</h1><p>I hope you enjoy your stay...</p></body></html>";
    if (send(client_sock, response_message, strlen(response_message), 0) < 0) {
        printf("Error: Send failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Response sent\n");

    close(client_sock);
    close(socket_desc);
    return 0;
}