//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 4096

void handle_connection(int client_sockfd, struct sockaddr_in client_addr, int server_sockfd, struct sockaddr_in server_addr) {
    int maxfd;
    fd_set rset;
    char buf[BUF_SIZE];
    ssize_t nread_client, nread_server;

    if (connect(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(client_sockfd);
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    maxfd = (client_sockfd > server_sockfd ? client_sockfd : server_sockfd) + 1;
    while (1) {
        FD_ZERO(&rset);
        FD_SET(client_sockfd, &rset);
        FD_SET(server_sockfd, &rset);

        if (select(maxfd, &rset, NULL, NULL, NULL) == -1) {
            perror("select");
            close(client_sockfd);
            close(server_sockfd);
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(client_sockfd, &rset)) {
            nread_client = read(client_sockfd, buf, BUF_SIZE);
            if (nread_client == -1) {
                perror("read client");
                close(client_sockfd);
                close(server_sockfd);
                exit(EXIT_FAILURE);
            } else if (nread_client == 0) {
                break;
            }

            nread_server = write(server_sockfd, buf, nread_client);
            if (nread_server == -1) {
                perror("write server");
                close(client_sockfd);
                close(server_sockfd);
                exit(EXIT_FAILURE);
            }
        }

        if (FD_ISSET(server_sockfd, &rset)) {
            nread_server = read(server_sockfd, buf, BUF_SIZE);
            if (nread_server == -1) {
                perror("read server");
                close(client_sockfd);
                close(server_sockfd);
                exit(EXIT_FAILURE);
            } else if (nread_server == 0) {
                break;
            }

            nread_client = write(client_sockfd, buf, nread_server);
            if (nread_client == -1) {
                perror("write client");
                close(client_sockfd);
                close(server_sockfd);
                exit(EXIT_FAILURE);
            }
        }
    }

    close(client_sockfd);
    close(server_sockfd);
}

int main(int argc, char *argv[]) {
    int sockfd, client_sockfd, server_sockfd;
    int optval = 1;
    struct sockaddr_in proxy_addr, client_addr, server_addr;
    socklen_t addrlen;
    char *port = "8888";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) == -1) {
        perror("setsockopt");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons((uint16_t) atoi(port));

    if (bind(sockfd, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("bind");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, SOMAXCONN) == -1) {
        perror("listen");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("proxy listening on port %s...\n", port);

    while (1) {
        addrlen = sizeof(client_addr);
        client_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &addrlen);
        if (client_sockfd == -1) {
            perror("accept client");
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        printf("accepted connection from %s:%d...\n", inet_ntoa(client_addr.sin_addr),
               ntohs(client_addr.sin_port));

        server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd == -1) {
            perror("socket");
            close(client_sockfd);
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        server_addr.sin_addr = ((struct in_addr *) gethostbyname(argv[1])->h_addr_list[0])[0];

        handle_connection(client_sockfd, client_addr, server_sockfd, server_addr);
    }

    return 0;
}