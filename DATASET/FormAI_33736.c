//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // check command line arguments
    if (argc != 2) {
        fprintf(stderr, "usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *url = argv[1];

    // parse hostname and port from url
    char *hostname = url;
    char *port = "80";
    char *path = "/";
    char *colon = strchr(url, ':');
    char *slash = strchr(url, '/');

    if (colon != NULL) {
        hostname = url;
        port = colon + 1;
        *colon = '\0';
    }

    if (slash != NULL) {
        path = slash;
        *slash = '\0';
    }

    printf("hostname: %s\n", hostname);
    printf("port: %s\n", port);
    printf("path: %s\n", path);

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // resolve hostname
    struct hostent *host = gethostbyname(hostname);

    if (host == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // connect to server
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(atoi(port)),
        .sin_addr = *((struct in_addr *) host->h_addr)
    };

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // send HTTP request
    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s:%s\r\nConnection: close\r\n\r\n", path, hostname, port);
    size_t request_size = strlen(buffer);
    ssize_t bytes_sent = send(sockfd, buffer, request_size, 0);

    if (bytes_sent == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // receive HTTP response
    char response[BUFFER_SIZE];
    ssize_t bytes_received = recv(sockfd, response, BUFFER_SIZE, 0);

    if (bytes_received == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("%.*s", (int) bytes_received, response);

    // cleanup
    close(sockfd);

    return 0;
}