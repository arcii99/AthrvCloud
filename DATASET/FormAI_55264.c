//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

char *host = "www.google.com";
char *path = "/";
char *user_agent = "HTTPClient/1.0";
int port = 80;

char *build_request() {
    char *request = malloc(sizeof(char) * 512);
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n", path, host, user_agent);
    return request;
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Could not create socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("216.58.194.174"); // Google IP address
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: Could not connect to server");
        return 1;
    }

    char *request = build_request();
    send(sock, request, strlen(request), 0);

    char *response = malloc(sizeof(char) * 1024);
    memset(response, 0, sizeof(char) * 1024);
    recv(sock, response, 1024, 0);

    printf("%s", response);

    close(sock);
    free(request);
    free(response);
    return 0;
}