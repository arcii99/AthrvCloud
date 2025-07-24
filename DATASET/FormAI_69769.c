//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    char *host = argv[1];
    char *path = argv[2];
    char *method = "GET";
    char *port = "80";
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(host);
    server.sin_port = htons(atoi(port));
    server.sin_family = AF_INET;
    printf("Connecting to %s:%s...\n", host, port);
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed!");
        exit(EXIT_FAILURE);
    }
    printf("Connected!\n");
    char *request_buffer = malloc(strlen(method) + strlen(path) + 12);
    sprintf(request_buffer, "%s %s HTTP/1.1\r\n", method, path);
    strcat(request_buffer, "Host: ");
    strcat(request_buffer, host);
    strcat(request_buffer, "\r\n\r\n");
    if (send(sock, request_buffer, strlen(request_buffer), 0) < 0) {
        perror("Request failed!");
        exit(EXIT_FAILURE);
    }
    printf("Request sent!\n");
    char response_buffer[1024];
    int bytes_received = 0;
    while ((bytes_received = recv(sock, response_buffer, sizeof(response_buffer) - 1, 0)) > 0) {
        response_buffer[bytes_received] = '\0';
        printf("%s", response_buffer);
    }
    printf("Connection closed!\n");
    close(sock);
    free(request_buffer);
    return EXIT_SUCCESS;
}