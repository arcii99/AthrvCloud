//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_LENGTH 1024

// function prototypes
void usage();
void error(const char *message);
int send_http_request(int sock_fd, char *host, char *path, char *query_params);

int main(int argc, char *argv[]) {
    int sock_fd;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_LENGTH];

    // output usage info if arguments are invalid
    if (argc < 3) {
        usage();
        exit(1);
    }

    // create a socket using TCP protocol
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        error("Unable to create a socket.");
    }

    // set up server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);

    // resolve IP address of the host
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        error("Invalid IP address or hostname.");
    }

    // connect to the server
    if (connect(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("Unable to connect to the server.");
    }

    // send HTTP request
    send_http_request(sock_fd, argv[1], argv[2], argc > 3 ? argv[3] : "");

    // read response from the server
    int bytes_received = 0;
    while ((bytes_received = read(sock_fd, buffer, MAX_BUFFER_LENGTH - 1)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock_fd);
    return 0;
}

/**
 * Function to output usage information.
 */
void usage() {
    printf("Usage: ./http_client <ip_address/hostname> <path> [query_params]\n");
}

/**
 * Function to output error message and exit.
 */
void error(const char *message) {
    perror(message);
    exit(1);
}

/**
 * Function to send HTTP request to the server.
 */
int send_http_request(int sock_fd, char *host, char *path, char *query_params) {
    char request[MAX_BUFFER_LENGTH];
    sprintf(request, "GET %s?%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0\r\nConnection: close\r\n\r\n", path, query_params, host);
    return write(sock_fd, request, strlen(request));
}