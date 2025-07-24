//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// function to create a socket connection and send the request
void create_socket(const char* hostname, const char* path, int port) {
    // create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Could not create socket");
        exit(EXIT_FAILURE);
    }

    // resolve the hostname to IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Error: Could not resolve hostname");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    // set IPv4 and port
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, host->h_addr, &server_address.sin_addr);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error: Could not connect to server");
        exit(EXIT_FAILURE);
    }

    // prepare the HTTP request
    char request[1024];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // send the HTTP request
    ssize_t bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent < 0) {
        perror("Error: Could not send request");
        exit(EXIT_FAILURE);
    }

    // read the response
    char response[4096];
    ssize_t bytes_received = recv(sockfd, response, sizeof(response), 0);
    if (bytes_received < 0) {
        perror("Error: Could not receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // close the socket
    close(sockfd);
}

// recursive function to parse the URL
void parse_url(char* url) {
    if (strlen(url) == 0) {
        return;
    }

    char* hostname_start = url;
    char* hostname_end = strstr(url, "/");
    if (!hostname_end) {
        hostname_end = url + strlen(url);
    }

    char* path_start = strstr(url, "/");
    if (path_start) {
        path_start[0] = '\0';
        path_start++;
    } else {
        path_start = "";
    }

    char* port_start = strstr(hostname_start, ":");
    if (port_start) {
        port_start[0] = '\0';
        port_start++;
        create_socket(hostname_start, path_start, atoi(port_start));
    } else {
        create_socket(hostname_start, path_start, 80);
    }

    parse_url(hostname_end);
}

int main() {
    printf("Enter the URL: ");
    char url[1024];
    fgets(url, sizeof(url), stdin);

    // remove newline character from the input string
    url[strcspn(url, "\n")] = 0;

    // check if the input string starts with "http://" or "https://"
    if (strncmp(url, "http://", 7) == 0) {
        parse_url(url + 7);
    } else if (strncmp(url, "https://", 8) == 0) {
        printf("Error: HTTPS not supported\n");
    } else {
        printf("Error: Invalid URL\n");
    }

    return 0;
}