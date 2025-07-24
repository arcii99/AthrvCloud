//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

int proxy(int client) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    int server;

    // clear the buffer
    memset(buffer, 0, BUFFER_SIZE);

    // get the request from the client
    recv(client, buffer, BUFFER_SIZE, 0);

    // connect to the server
    server = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // port 80 for HTTP
    inet_pton(AF_INET, "google.com", &(server_addr.sin_addr)); // IP address of server
    connect(server, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // send the request to the server
    send(server, buffer, strlen(buffer), 0);

    // clear the buffer again
    memset(buffer, 0, BUFFER_SIZE);

    // receive the response from the server
    recv(server, buffer, BUFFER_SIZE, 0);

    // send the response back to the client
    send(client, buffer, strlen(buffer), 0);

    // close both sockets
    close(client);
    close(server);

    // return 0 for success
    return 0;
}

int main(int argc, char** argv) {
    int server, client;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    // create the socket
    server = socket(AF_INET, SOCK_STREAM, 0);
    if (server < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // set socket options
    int opt = 1;
    setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // bind the socket to an address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080); // port 8080 for proxy
    if (bind(server, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // listen for incoming connections
    if (listen(server, 50) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    // accept incoming connections and handle them in the proxy function
    while (1) {
        client_len = sizeof(client_addr);
        client = accept(server, (struct sockaddr*)&client_addr, &client_len);
        if (client < 0) {
            perror("Error accepting connection");
            continue;
        }
        proxy(client);
    }

    // should never reach here
    exit(0);
}