//FormAI DATASET v1.0 Category: Simple Web Server ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    printf("Starting c-silly-server\n");

    // Step 1: Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    // Step 2: Bind socket to port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        printf("Error binding socket\n");
        close(server_fd);
        return -1;
    }

    // Step 3: Listen for incoming connections
    if (listen(server_fd, 5) == -1) {
        printf("Error listening on socket\n");
        close(server_fd);
        return -1;
    }

    printf("Server Ready! Listening on port: %d\n", PORT);

    // Step 4: Handle incoming connections
    struct sockaddr_in client_addr;
    int client_fd;
    char buffer[BUFFER_SIZE];
    char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Welcome to c-silly-server</h1></body></html>";

    while (1) {
        socklen_t client_addrlen = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addrlen);

        if (client_fd == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Incoming connection from client: %s\n", inet_ntoa(client_addr.sin_addr));
        if (recv(client_fd, buffer, BUFFER_SIZE, 0) == -1) {
            printf("Error receiving request from client\n");
            continue;
        }

        printf("Client sent the following request: \n%s\n", buffer);

        // So here's the fun part
        printf("Generating random response...\n");

        char *headers[] = {
            "HTTP/1.1 200 OK\r\n",
            "Content-Type: text/html\r\n",
            "Server: c-silly-server\r\n",
            "X-Powered-By: C-language\r\n",
            "Connection: close\r\n\r\n"
        };
        char *body = "<html><body><h1>This is a silly server</h1><img src='https://media.giphy.com/media/jSKJHWC3qL0ju/giphy.gif'></body></html>";
        int headers_len = sizeof(headers)/sizeof(char *);
        char response[BUFFER_SIZE];
        strcpy(response, headers[rand() % headers_len]);
        strcat(response, body);

        printf("Sending random response...\n");
        if (send(client_fd, response, strlen(response), 0) == -1) {
            printf("Error sending response to client\n");
            continue;
        }

        // Close the client socket
        close(client_fd);
        printf("Response sent to client. Closing connection.\n");
    }

    close(server_fd);
    return 0;
}