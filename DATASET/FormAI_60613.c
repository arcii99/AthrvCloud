//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF 1024 // maximum buffer size for HTTP response

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Error converting IP address");
        exit(1);
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // construct HTTP request
    char *request = "GET / HTTP/1.1\r\n"
                    "Host: localhost\r\n"
                    "Connection: close\r\n\r\n";

    // send HTTP request to server
    if (send(sockfd, request, strlen(request), 0) != strlen(request)) {
        perror("Error sending request");
        exit(1);
    }

    // receive HTTP response from server
    char response[MAX_BUF];
    memset(response, 0, sizeof(response));
    int num_bytes;
    while ((num_bytes = recv(sockfd, response, MAX_BUF - 1, 0)) > 0) {
        printf("%s", response);
        memset(response, 0, sizeof(response));
    }
    if (num_bytes < 0) {
        perror("Error receiving response");
        exit(1);
    }

    // close socket
    if (close(sockfd) < 0) {
        perror("Error closing socket");
        exit(1);
    }

    return 0;
}