//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PROXY_PORT 8888

int main(int argc, char *argv[]) {
    int proxy_socket, client_socket, rcv_len;
    struct sockaddr_in proxy_addr, client_addr;
    char buffer[4096];

    proxy_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (proxy_socket < 0) {
        perror("Failed to create proxy socket");
        return 1;
    }

    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PROXY_PORT);

    if (bind(proxy_socket, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Failed to bind proxy socket");
        return 1;
    }

    listen(proxy_socket, 10);

    printf("Proxy server is running at port %d\n", PROXY_PORT);

    while (1) {
        int addr_len = sizeof(client_addr);
        printf("Waiting for a client...\n");
        client_socket = accept(proxy_socket, (struct sockaddr *) &client_addr, (socklen_t*)&addr_len);

        if (client_socket < 0) {
            perror("Failed to accept client socket");
            continue;
        }

        printf("Accepted a client connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        rcv_len = recv(client_socket , buffer, 4096, 0);
        if (rcv_len < 0) {
            perror("Failed to receive data from client");
            continue;
        }

        // Modify the request here (e.g. change the URL)

        printf("Request from the client:\n%s\n", buffer);

        // Forward the modified request to the target server
        int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (server_socket < 0) {
            perror("Failed to create server socket");
            continue;
        }

        // Set up the target server's address and port
        struct sockaddr_in server_addr;
        memset(&server_addr, 0 , sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        // Connect to the target server
        if (connect(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
            perror("Failed to connect to server");
            continue;
        }

        // Forward the request to the target server
        if (send(server_socket, buffer, rcv_len, 0) < 0) {
            perror("Failed to send data to server");
            continue;
        }

        // Receive the response from the target server and forward it to the client
        while ((rcv_len = recv(server_socket, buffer, 4096, 0)) > 0) {
            if (send(client_socket, buffer, rcv_len, 0) < 0) {
                perror("Failed to send data to client");
                break;
            }
        }

        printf("Response from the server:\n%s\n", buffer);
    }

    return 0;
}