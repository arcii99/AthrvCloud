//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_REQUEST_SIZE 1024

char* get_request_hostname(char* request) {
    char* host_start = strstr(request, "Host: ") + strlen("Host: ");
    char* host_end = strchr(host_start, '\r');
  
    int host_len = host_end - host_start;

    char* hostname = malloc(host_len + 1);
    memcpy(hostname, host_start, host_len);
    hostname[host_len] = '\0';

    return hostname;
}

void handle_proxy_client(int client_sock) {
    char request[MAX_REQUEST_SIZE];
    memset(request, 0, MAX_REQUEST_SIZE);

    recv(client_sock, request, MAX_REQUEST_SIZE, 0);

    char* hostname = get_request_hostname(request);

    int proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
  
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    connect(proxy_sock, (struct sockaddr*) &server_addr, sizeof(server_addr));

    send(proxy_sock, request, strlen(request), 0);

    char response_buffer[4096];
    memset(response_buffer, 0, sizeof(response_buffer));

    int bytes_received = 0;

    while ((bytes_received = recv(proxy_sock, response_buffer, sizeof(response_buffer), 0)) > 0) {
        send(client_sock, response_buffer, bytes_received, 0);
        memset(response_buffer, 0, sizeof(response_buffer));
    }

    close(proxy_sock);
    close(client_sock);
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (struct sockaddr*) &server_addr, sizeof(server_addr));
    listen(server_sock, 10);

    while (1) {
        int client_sock = accept(server_sock, NULL, NULL);
        handle_proxy_client(client_sock);
    }

    return 0;
}