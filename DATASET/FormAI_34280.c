//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PROXY_PORT 8888
#define BUFFER_SIZE 1024

void start_proxy_server() {

    int proxy_server_socket, client_socket, addr_len, bytes_received, port;
    char buffer[BUFFER_SIZE], request_buffer[BUFFER_SIZE], response_buffer[BUFFER_SIZE];
    struct sockaddr_in proxy_server_addr, client_addr;
    struct hostent *web_server_host;
    struct in_addr **addr_list;
    fd_set read_fds;
    struct timeval timeout;

    proxy_server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_server_socket == -1) {
        perror("Unable to create proxy server socket");
        exit(1);
    }

    memset(&proxy_server_addr, 0, sizeof(proxy_server_addr));
    proxy_server_addr.sin_family = AF_INET;
    proxy_server_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_server_addr.sin_port = htons(PROXY_PORT);

    if (bind(proxy_server_socket, (struct sockaddr *)&proxy_server_addr, sizeof(proxy_server_addr)) < 0) {
        perror("Unable to bind proxy server socket");
        exit(1);
    }

    listen(proxy_server_socket, 10);
    printf("Proxy listening on port %d\n", PROXY_PORT);

    while(1) {

        addr_len = sizeof(client_addr);
        client_socket = accept(proxy_server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len);

        if (client_socket < 0) {
            perror("Error accepting client connection");
            continue;
        }

        memset(buffer, '\0', BUFFER_SIZE);
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received < 0) {
            perror("Error reading request from client");
            continue;
        }

        if (strstr(buffer, "GET") != NULL || strstr(buffer, "POST") != NULL) {

            strcpy(request_buffer, buffer);

            char *tok = strtok(buffer, "\n");
            char *line = tok;
            char *url, *host;

            while (line != NULL) {

                if (strstr(line, "Host: ") != NULL) {
                    host = line + strlen("Host: ");
                    host[strcspn(host, "\r\n")] = '\0'; 
                } else if (strstr(line, "GET ") != NULL || strstr(line, "POST ") != NULL) {
                    url = strtok(line + 4, " ");
                    url[strcspn(url, "\r\n")] = '\0'; 
                }

                line = strtok(NULL, "\n");

            }

            if (*url == '/') {
                url++;
            }

            memset(response_buffer, '\0', BUFFER_SIZE);

            web_server_host = gethostbyname(host);

            if (web_server_host == NULL) {
                fprintf(stderr, "Error resolving host %s\n", host);
                continue;
            }

            addr_list = (struct in_addr **)web_server_host -> h_addr_list;

            if (addr_list[0] == NULL) {
                fprintf(stderr, "Error resolving host %s\n", host);
                continue;
            }

            char *web_server_ip = inet_ntoa(*addr_list[0]);

            struct sockaddr_in web_server_addr;
            int web_server_socket = socket(AF_INET, SOCK_STREAM, 0);

            if (web_server_socket < 0) {
                perror("Error creating web server socket");
                continue;
            }

            memset(&web_server_addr, 0, sizeof(web_server_addr));
            web_server_addr.sin_family = AF_INET;
            web_server_addr.sin_addr.s_addr = inet_addr(web_server_ip);
            web_server_addr.sin_port = htons(80);

            if (connect(web_server_socket, (struct sockaddr *)&web_server_addr, sizeof(web_server_addr)) < 0) {
                perror("Error connecting to web server");
                continue;
            }

            if (write(web_server_socket, request_buffer, strlen(request_buffer)) < 0) {
                perror("Error sending request to web server");
                continue;
            }

            FD_ZERO(&read_fds);
            FD_SET(web_server_socket, &read_fds);

            timeout.tv_sec = 5;
            timeout.tv_usec = 0;

            if (select(web_server_socket + 1, &read_fds, NULL, NULL, &timeout) == 1) {

                if (read(web_server_socket, response_buffer, BUFFER_SIZE) < 0) {
                    perror("Error reading response from web server");
                    continue;
                }

                if (write(client_socket, response_buffer, strlen(response_buffer)) < 0) {
                    perror("Error sending response to client");
                }

            } else {

                fprintf(stderr, "Timeout while reading response from web server %s\n", host);

            }

            close(web_server_socket);

        }

        close(client_socket);

    }

}

int main() {

    start_proxy_server();
    return 0;

}