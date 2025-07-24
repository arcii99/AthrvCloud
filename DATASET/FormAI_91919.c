//FormAI DATASET v1.0 Category: Simple Web Server ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 8080 // Change this to your desired port number
#define MAXLINE 4096

int main(int argc, char *argv[]) {
    int listenfd;
    int connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];

    // Create socket for listening incoming requests
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error creating socket.\n");
        exit(1);
    }

    // Prepare server socket address struct
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(DEFAULT_PORT);

    // Bind server socket to specified port
    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        fprintf(stderr, "Error binding socket.\n");
        exit(1);
    }

    // Start listening for incoming requests
    if (listen(listenfd, 10) == -1) {
        fprintf(stderr, "Error listening for incoming requests.\n");
        exit(1);
    }

    // Service loop, runs forever serving incoming requests
    while(1) {
        printf("Waiting for request...\n");

        // Accept incoming requests
        if ((connfd = accept(listenfd, (struct sockaddr *) NULL, NULL)) == -1) {
            fprintf(stderr, "Error accepting incoming request.\n");
            continue;
        }

        printf("Request accepted.\n");

        // Read request message
        ssize_t n;
        if ((n = read(connfd, buff, MAXLINE)) == -1) {
            fprintf(stderr, "Error reading request message.\n");
            close(connfd);
            continue;
        }

        // Null terminate buffer for printing
        buff[n] = '\0';

        printf("Request message: %s\n", buff);

        // Send response message
        const char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\r\n\r\nHello, World!";
        if (write(connfd, response, strlen(response)) == -1) {
            fprintf(stderr, "Error sending response message.\n");
            close(connfd);
            continue;
        }

        printf("Response sent.\n");

        close(connfd);
    }

    return 0;
}