//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE 2048
#define SERVER_PORT 8000
#define BACKLOG 10
#define PROXY_PORT 8888

int main(int argc, char **argv){
    int sockfd, clientfd, proxyfd, listenfd;
    char read_buf[MAX_LINE];
    char write_buf[MAX_LINE];
    struct sockaddr_in server_addr, client_addr, proxy_addr, listen_addr;
    socklen_t client_len, proxy_len, listen_len;
    int nread, nwrite, proxy_flag, listen_flag;
    char *proxy_ip = "127.0.0.1";
    int proxy_port = PROXY_PORT;

    // Set proxy address
    bzero(&proxy_addr, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(proxy_port);
    proxy_flag = inet_pton(AF_INET, proxy_ip, &proxy_addr.sin_addr);

    // Set server address
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    // Set listen address
    bzero(&listen_addr, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    listen_addr.sin_port = htons(PROXY_PORT);

    // Create listen socket
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create listening socket");
        exit(1);
    }

    // Bind listen socket to listen address
    if (bind(listenfd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("Failed to bind listening socket");
        exit(1);
    }

    // Listen on listen socket
    if (listen(listenfd, BACKLOG) == -1) {
        perror("Failed to listen on socket");
        exit(1);
    }

    // Accept incoming connections and handle them using child processes
    while(1) {
        client_len = sizeof(client_addr);
        if ((clientfd = accept(listenfd, (struct sockaddr *)&client_addr, &client_len)) == -1) {
            perror("Failed to accept client connection");
            continue;
        }

        if (proxy_flag) {
            proxy_len = sizeof(proxy_addr);
            if ((proxyfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                perror("Failed to create proxy socket");
                exit(1);
            }

            if (connect(proxyfd, (struct sockaddr *)&proxy_addr, proxy_len) == -1) {
                perror("Failed to connect to proxy");
                exit(1);
            }
        }

        if (!fork()) {
            // Child process
            close(listenfd);

            while(1){
                nread = read(clientfd, read_buf, MAX_LINE);
                if (nread == -1) {
                    perror("Failed to read from client socket");
                    exit(1);
                }

                if (nread == 0) {
                    close(clientfd);
                    close(proxyfd);
                    exit(0);
                }

                // Forward data to proxy if applicable
                if (proxy_flag) {
                    nwrite = write(proxyfd, read_buf, nread);
                    if (nwrite == -1) {
                        perror("Failed to write to proxy socket");
                        exit(1);
                    }
                }

                // Forward data to client
                nwrite = write(clientfd, read_buf, nread);
                if (nwrite == -1) {
                    perror("Failed to write to client socket");
                    exit(1);
                }

                if (proxy_flag) {
                    nread = read(proxyfd, write_buf, MAX_LINE);
                    if (nread == -1) {
                        perror("Failed to read from proxy socket");
                        exit(1);
                    }

                    // Forward data to client
                    nwrite = write(clientfd, write_buf, nread);
                    if (nwrite == -1) {
                        perror("Failed to write to client socket");
                        exit(1);
                    }
                }
            }
        }
        close(clientfd);
    }
    return 0;
}