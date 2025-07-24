//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Helper function to validate HTTP response status code
bool is_response_successful(char* response) {
    char status_code[4];
    strncpy(status_code, response + 9, 3);
    status_code[3] = '\0';
    int code = atoi(status_code);
    return code >= 200 && code < 300;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    // Parse URL to extract host and port
    char* url = argv[1];
    char* host_start = strstr(url, "//") + 2;
    char* host_end = strstr(host_start, "/");
    int host_len = host_end - host_start;
    char* host = malloc(host_len + 1);
    strncpy(host, host_start, host_len);
    host[host_len] = '\0';
    int port = 80;
    char* port_start = strstr(host, ":");
    if (port_start) {
        port = atoi(port_start + 1);
    }

    // Initialize socket
    struct hostent* he = gethostbyname(host);
    struct in_addr ipv4_addr;
    char* ip = inet_ntoa(*(struct in_addr*) he->h_addr_list[0]);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(ip);

    // Connect to server
    int result = connect(sock, (struct sockaddr*) &address, sizeof(address));
    if (result < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send GET request
    char* request = malloc(BUFFER_SIZE);
    snprintf(request, BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", host_end, host);
    result = send(sock, request, strlen(request), 0);
    if (result < 0) {
        printf("Error sending GET request\n");
        exit(1);
    }

    // Receive response
    char* response = malloc(BUFFER_SIZE);
    char* response_start = response;
    while (strstr(response, "\r\n\r\n") == NULL) {
        result = recv(sock, response, 1, 0);
        if (result < 0) {
            printf("Error receiving response\n");
            exit(1);
        }
        response += result;
    }
    response += 4;

    // Print response header and body
    if (is_response_successful(response_start)) {
        printf("%s", response);
    } else {
        printf("Error: response status code is not successful\n");
    }

    // Clean up resources
    free(host);
    free(request);
    free(response_start);
    close(sock);

    return 0;
}