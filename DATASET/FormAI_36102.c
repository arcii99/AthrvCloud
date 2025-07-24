//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: post-apocalyptic
// Post-Apocalyptic Simple HTTP Proxy

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 4096
#define PORT 8000

int main(int argc, char *argv[]) {
    int server_sock, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[BUFSIZE], remote_message[BUFSIZE];
    char *remote_host = "127.0.0.1";
    int remote_port = 80;

    // Socket creation
    server_sock = socket(AF_INET , SOCK_STREAM , 0);
    if (server_sock == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket to a specific address and port
    if (bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(server_sock, 3);
    c = sizeof(struct sockaddr_in);

    while (true) {
        // Accept connection from client
        client_sock = accept(server_sock, (struct sockaddr *)&client, (socklen_t*)&c);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        // Read the incoming request from the client
        bzero(client_message, BUFSIZE);
        read_size = recv(client_sock, client_message, BUFSIZE, 0);
        if (read_size < 0) {
            perror("recv failed");
            continue;
        }

        // Create a new connection to the remote server
        int remote_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_sock < 0) {
            perror("socket creation failed");
            continue;
        }

        // Prepare the sockaddr_in structure
        struct sockaddr_in remote;
        remote.sin_family = AF_INET;
        remote.sin_addr.s_addr = inet_addr(remote_host);
        remote.sin_port = htons(remote_port);

        // Establish connection with remote server
        if (connect(remote_sock, (struct sockaddr *)&remote, sizeof(remote)) < 0) {
            perror("connect failed");
            close(remote_sock);
            continue;
        }

        // Send the request to the remote server
        if (send(remote_sock, client_message, strlen(client_message), 0) < 0) {
            perror("send failed");
            close(remote_sock);
            continue;
        }

        // Receive the response from the remote server
        bzero(remote_message, BUFSIZE);
        read_size = recv(remote_sock, remote_message, BUFSIZE, 0);
        if (read_size < 0) {
            perror("recv failed");
            close(remote_sock);
            continue;
        }

        // Send the response back to the client
        if (send(client_sock, remote_message, strlen(remote_message), 0) < 0) {
            perror("send failed");
            close(remote_sock);
            continue;
        }

        // Close the remote socket
        close(remote_sock);

        // Close the client socket
        close(client_sock);
    }

    return 0;
}