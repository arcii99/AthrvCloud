//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8080
#define MAXLINE 1024

int main(int argc, char *argv[])
{
    int listenfd, clientfd;
    struct sockaddr_in proxy_addr, client_addr, server_addr;
    char buffer[MAXLINE];
    int len, n;

    // Create socket
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set proxy address and port
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(listenfd, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(listenfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("HTTP Proxy listening on port %d...\n", PORT);

    while(1) {
        // Accept client connection
        len = sizeof(client_addr);
        clientfd = accept(listenfd, (struct sockaddr*)&client_addr, &len);
        if (clientfd < 0) {
            perror("accept");
            continue;
        }

        printf("\nNew client connection accepted.\n");

        // Get request from client
        memset(buffer, 0, MAXLINE);
        n = recv(clientfd, buffer, MAXLINE, 0);
        if (n < 0) {
            perror("recv");
            close(clientfd);
            continue;
        }

        printf("Request:\n%s", buffer);

        // Parse request to get URL
        char *url;
        url = strstr(buffer, "http://");
        if (url == NULL) {
            printf("Invalid request.\n");
            close(clientfd);
            continue;
        }
        url += 7;

        // Get hostname and path from URL
        char *hostname, *path;
        hostname = url;
        path = strchr(hostname, '/');
        if (path == NULL) {
            printf("Invalid request.\n");
            close(clientfd);
            continue;
        }
        *path = '\0';
        path++;

        // Resolve hostname to IP address
        struct hostent *he;
        struct in_addr **addr_list;
        if ((he = gethostbyname(hostname)) == NULL) {
            perror("gethostbyname");
            close(clientfd);
            continue;
        }
        addr_list = (struct in_addr**)he->h_addr_list;
        if (addr_list[0] == NULL) {
            printf("Invalid IP address.\n");
            close(clientfd);
            continue;
        }
        char *ip = inet_ntoa(*addr_list[0]);

        printf("Resolved host: %s -> %s\n", hostname, ip);

        // Create socket to connect to server
        int serverfd = socket(AF_INET, SOCK_STREAM, 0);
        if (serverfd == -1) {
            perror("socket");
            close(clientfd);
            continue;
        }

        // Set server address and port
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(ip);
        server_addr.sin_port = htons(80);

        // Connect to server
        if (connect(serverfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            perror("connect");
            close(clientfd);
            close(serverfd);
            continue;
        }

        printf("Connected to server.\n");

        // Forward request to server
        n = send(serverfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            perror("send");
            close(clientfd);
            close(serverfd);
            continue;
        }

        printf("Request forwarded to server.\n");

        // Get response from server
        memset(buffer, 0, MAXLINE);
        n = recv(serverfd, buffer, MAXLINE, 0);
        if (n < 0) {
            perror("recv");
            close(clientfd);
            close(serverfd);
            continue;
        }

        printf("Response:\n%s", buffer);

        // Forward response to client
        n = send(clientfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            perror("send");
            close(clientfd);
            close(serverfd);
            continue;
        }

        printf("Response forwarded to client.\n");

        // Close client and server connections
        close(clientfd);
        close(serverfd);
    }

    return 0;
}