//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_REQUEST_SIZE 4096
#define MAX_RESPONSE_SIZE 65536

// function to create a socket and connect to the server
int connect_to_server(char *host, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// function to send the HTTP request to the server
void send_http_request(int sockfd, char *request) {
    int bytes_sent = 0;
    int total_bytes_sent = 0;
    int request_size = strlen(request);

    while (total_bytes_sent < request_size) {
        bytes_sent = send(sockfd, request + total_bytes_sent, request_size - total_bytes_sent, 0);
        if (bytes_sent < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }
        total_bytes_sent += bytes_sent;
    }
}

// function to receive the HTTP response from the server
char *receive_http_response(int sockfd) {
    char *response = malloc(MAX_RESPONSE_SIZE);
    int bytes_received = 0;
    int total_bytes_received = 0;

    while (true) {
        bytes_received = recv(sockfd, response + total_bytes_received, MAX_RESPONSE_SIZE - total_bytes_received, 0);
        if (bytes_received < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        if (bytes_received == 0) {
            break;
        }

        total_bytes_received += bytes_received;
        if (total_bytes_received >= MAX_RESPONSE_SIZE) {
            fprintf(stderr, "ERROR: Response size exceeds the maximum buffer limit!\n");
            exit(EXIT_FAILURE);
        }
    }

    response[total_bytes_received] = '\0';

    return response;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char request[MAX_REQUEST_SIZE] = "";
    strcat(request, "GET / HTTP/1.1\r\n");
    strcat(request, "Host: ");
    strcat(request, argv[1]);
    strcat(request, "\r\n");
    strcat(request, "Connection: close\r\n");
    strcat(request, "\r\n");

    int sockfd = connect_to_server(argv[1], atoi(argv[2]));
    send_http_request(sockfd, request);

    char *response = receive_http_response(sockfd);
    printf("%s", response);

    free(response);
    close(sockfd);

    return 0;
}