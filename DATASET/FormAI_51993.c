//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PROXY_PORT 8080
#define SERVER_PORT 80
#define BUFFER_SIZE 4096

int main() {
    int proxy_sock, server_sock, cli_len, server_len, bytes, opt = 1;
    struct sockaddr_in proxy_addr, server_addr, cli_addr;
    char buffer[BUFFER_SIZE], req_buffer[BUFFER_SIZE], resp_buffer[BUFFER_SIZE], *url_ptr, *http_ver_ptr;

    // Create the proxy socket
    if ((proxy_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Proxy socket creation failed.\n");
        exit(1);
    }

    // Set socket options
    if (setsockopt(proxy_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        fprintf(stderr, "Proxy setsockopt failed.\n");
        exit(1);
    }

    // Configure the proxy address
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(PROXY_PORT);

    // Bind the proxy socket
    if (bind(proxy_sock, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        fprintf(stderr, "Proxy bind failed.\n");
        exit(1);
    }

    // Listen for client connections
    if (listen(proxy_sock, 10) == -1) {
        fprintf(stderr, "Proxy listen failed.\n");
        exit(1);
    }

    // Accept and handle client connections
    while (1) {
        cli_len = sizeof(cli_addr);
        if ((server_sock = accept(proxy_sock, (struct sockaddr *)&cli_addr, &cli_len)) == -1) {
            fprintf(stderr, "Proxy accept failed.\n");
            continue;
        }

        // Read the client request
        memset(buffer, 0, sizeof(buffer));
        bytes = read(server_sock, buffer, sizeof(buffer));
        if (bytes <= 0) {
            fprintf(stderr, "Proxy client request read failed.\n");
            close(server_sock);
            continue;
        }

        // Parse the client request
        strncpy(req_buffer, buffer, sizeof(req_buffer));
        url_ptr = strchr(req_buffer, ' ') + 1;
        http_ver_ptr = strstr(url_ptr, "\r\n") - 8;
        *http_ver_ptr = '\0';
        printf("Proxy client request: %s\n", req_buffer);

        // Open connection to server
        if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            fprintf(stderr, "Proxy server socket creation failed.\n");
            continue;
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(SERVER_PORT);
        inet_aton(url_ptr, &server_addr.sin_addr);
        memset(&(server_addr.sin_zero), '\0', 8);

        if (!connect(server_sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr))) {
            fprintf(stderr, "Proxy server connect to %s failed.\n", url_ptr);
            continue;
        }

        // Forward the client request to the server
        write(server_sock, buffer, strlen(buffer));

        // Read the server response
        memset(resp_buffer, 0, sizeof(resp_buffer));
        bytes = read(server_sock, resp_buffer, sizeof(resp_buffer));
        if (bytes <= 0) {
            fprintf(stderr, "Proxy server response read failed.\n");
            close(server_sock);
            continue;
        }
        printf("Proxy server response: %s\n", resp_buffer);

        // Forward the server response to the client
        write(server_sock, resp_buffer, strlen(resp_buffer));

        close(server_sock);
    }

    return 0;
}