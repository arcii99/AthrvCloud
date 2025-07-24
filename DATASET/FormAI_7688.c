//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BACKLOG 10
#define MAX_BUFF 4096
#define PROXY_PORT 8000
#define SERVER_IP "172.217.166.238"

int main(int argc, char *argv[]) {
    int sockfd, newfd;
    int yes = 1;
    struct sockaddr_in addr_proxy, addr_client, addr_server;
    socklen_t sin_size = sizeof(struct sockaddr_in);
    char client_buff[MAX_BUFF], server_buff[MAX_BUFF];

    // create a socket to listen for connections on the proxy port
    if ((sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("socket creating error");
        exit(1);
    }

    // set socket options to reuse the address
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt error");
        exit(1);
    }

    // set the address to listen on
    addr_proxy.sin_family = AF_INET;
    addr_proxy.sin_port = htons(PROXY_PORT);
    addr_proxy.sin_addr.s_addr = INADDR_ANY;
    memset(addr_proxy.sin_zero, '\0', sizeof(addr_proxy.sin_zero));

    // bind socket to the address
    if (bind(sockfd, (struct sockaddr *)&addr_proxy, sizeof(struct sockaddr)) == -1) {
        perror("bind error");
        exit(1);
    }

    // start listening on the socket
    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen error");
        exit(1);
    }

    printf("Proxy server is listening on port %d ...\n", PROXY_PORT);

    while(1) {
        // accept a new connection from the client
        if ((newfd = accept(sockfd, (struct sockaddr *)&addr_client, &sin_size)) == -1) {
            perror("accept error");
            continue;
        }

        printf("Received a new request from %s:%d ...\n", inet_ntoa(addr_client.sin_addr), ntohs(addr_client.sin_port));

        // create a new socket to communicate with the server
        if ((sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
            perror("socket creating error");
            exit(1);
        }

        // set the address to connect to the server
        addr_server.sin_family = AF_INET;
        addr_server.sin_port = htons(80);
        addr_server.sin_addr.s_addr = inet_addr(SERVER_IP);
        memset(addr_server.sin_zero, '\0', sizeof(addr_server.sin_zero));

        // connect to the server
        if (connect(sockfd, (struct sockaddr *)&addr_server, sizeof(struct sockaddr)) == -1) {
            perror("connect error");
            exit(1);
        }

        // receive the request from the client
        if (recv(newfd, client_buff, MAX_BUFF - 1, 0) == -1) {
            perror("recv error");
            exit(1);
        }

        // send the request to the server
        if (send(sockfd, client_buff, strlen(client_buff), 0) == -1) {
            perror("send error");
            exit(1);
        }

        // receive the response from the server
        while(recv(sockfd, server_buff, MAX_BUFF - 1, 0) > 0) {
            // send the response to the client
            if (send(newfd, server_buff, strlen(server_buff), 0) == -1) {
                perror("send error");
                exit(1);
            }

            memset(server_buff, '\0', sizeof(server_buff));
        }

        // close the sockets
        close(newfd);
        close(sockfd);
    }

    return 0;
}