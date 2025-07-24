//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;

    // Create a socket for the proxy server
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set up the address and port of the proxy server
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    // Bind the proxy server to the specified address and port
    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Listen for incoming connections
    listen(listenfd, 10);

    printf("Proxy server running on port %d\n", ntohs(servaddr.sin_port));

    while (1) {
        socklen_t clilen = sizeof(cliaddr);

        // Accept incoming connections from client
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);

        printf("Connection received from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        // Read client's HTTP request
        char buf[MAXLINE];
        bzero(buf, sizeof(buf));
        read(connfd, buf, sizeof(buf));
        printf("%s", buf);

        // Parse the HTTP request to extract the destination host and port
        char host[MAXLINE], port[MAXLINE];
        sscanf(buf, "GET http://%[^/]/%s", host, port);

        if (!strcmp(port, "")) strcpy(port, "80");

        printf("Host: %s Port: %s\n", host, port);

        // Resolve the destination host IP address
        struct hostent *h = gethostbyname(host);
        if (h == NULL) {
            printf("%s: unknown host\n", host);
            continue;
        }

        // Create a socket for the destination server
        int destfd = socket(AF_INET, SOCK_STREAM, 0);

        // Set up the address and port of the destination server
        struct sockaddr_in destaddr;
        bzero(&destaddr, sizeof(destaddr));
        destaddr.sin_family = AF_INET;
        destaddr.sin_port = htons(atoi(port));
        destaddr.sin_addr = *((struct in_addr *)h->h_addr);

        // Connect to the destination server
        if (connect(destfd, (struct sockaddr *)&destaddr, sizeof(destaddr)) == -1) {
            perror("connection failed");
            continue;
        }

        // Forward the HTTP request to the destination server
        write(destfd, buf, strlen(buf));

        // Read the HTTP response from the destination server
        bzero(buf, sizeof(buf));
        int n;
        while ((n = read(destfd, buf, sizeof(buf))) > 0) {
            // Forward the HTTP response to the client
            write(connfd, buf, n);
            bzero(buf, sizeof(buf));
        }

        // Close the client and destination server sockets
        close(connfd);
        close(destfd);
    }

    return 0;
}