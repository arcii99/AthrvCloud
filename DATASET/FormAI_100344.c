//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define HTTP_PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 0;
    }

    char *hostname = argv[1];

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(struct sockaddr_in));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(HTTP_PORT);
    if (inet_pton(AF_INET, hostname, &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return 0;
    }

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Failed to create socket");
        return 0;
    }

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        return 0;
    }

    printf("Connected to %s:%d\n", hostname, HTTP_PORT);
    printf("Requesting resource...\n");

    char *path = "/index.html";
    char request[BUFFER_SIZE];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36\r\n\r\n", path, hostname);

    if (write(client_socket, request, strlen(request)) < 0) {
        perror("Failed to send request");
        return 0;
    }

    char response[BUFFER_SIZE];
    ssize_t n = read(client_socket, response, BUFFER_SIZE);
    if (n < 0) {
        perror("Failed to read response");
        return 0;
    }

    printf("Response received:\n\n");
    write(STDOUT_FILENO, response, n);

    close(client_socket);

    return 0;
}