//FormAI DATASET v1.0 Category: Simple Web Server ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#define MAXSIZE 1024 * 1024

void serve_client(int client_sockfd) {
    char request[MAXSIZE];
    read(client_sockfd, request, MAXSIZE);
    printf("Request:\n%s\n", request);

    char response[MAXSIZE] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><h1>Welcome to the Future Web Server</h1><p>This is a unique and futuristic example program!</p></html>";
    write(client_sockfd, response, strlen(response));
    close(client_sockfd);
}

int main(int argc, char *argv[]) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Bind the socket to port 8000
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8000);

    bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Listen for incoming requests
    listen(sockfd, 5);
    printf("Server listening on port 8000...\n");

    // Serve clients indefinitely
    while(1) {
        // Accept a client connection
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
        printf("Received a connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Serve the client's request
        serve_client(client_sockfd);
    }

    // Close the server socket
    close(sockfd);

    return 0;
}