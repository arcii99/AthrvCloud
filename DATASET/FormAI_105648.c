//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int listenfd = 0, client_sockfd = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    int port = 8080; // Default port for proxy server
    char *address = NULL; // Address of the server
    struct sockaddr_in cli_addr; // Client address

    if (argc != 2) { // Incorrect number of arguments
        printf("Usage: %s <address>", argv[0]);
        return 0;
    }

    address = argv[1]; // Get address from command line arguments

    // Create socket for listening to incoming requests
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(buffer, '0', sizeof(buffer));

    // Configure server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    // Bind socket to server address and port
    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    // Listen for incoming requests
    listen(listenfd, 10);

    while(1) {
        socklen_t len = sizeof(cli_addr);

        // Accept incoming requests
        client_sockfd = accept(listenfd, (struct sockaddr*)&cli_addr, &len);

        int n = read(client_sockfd, buffer, sizeof(buffer));

        // Parse the request to get URL
        char *token = strtok(buffer, " ");
        token = strtok(NULL, " ");
        char *url = strstr(token, "://") + 3;

        // Get the hostname and path from URL
        char *hostname = strtok(url, "/");
        char *path = strstr(url, "/");

        if(path == NULL) path = "/"; // If no path is specified, use root path

        // Create socket for server connection
        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server_address;

        // Configure server address
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(80);
        server_address.sin_addr.s_addr = inet_addr(hostname);

        // Connect to the server
        connect(server_sockfd, (struct sockaddr*)&server_address, sizeof(server_address));

        // Prepare HTTP request
        char request[1024];
        sprintf(request, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);

        // Send the request to the server
        write(server_sockfd, request, strlen(request));

        // Receive the response from server and send to client
        while((n = read(server_sockfd, buffer, sizeof(buffer))) > 0) {
            write(client_sockfd, buffer, n);
        }

        // Close server socket
        close(server_sockfd);

        // Close client socket
        close(client_sockfd);
    }

    return 0;
}