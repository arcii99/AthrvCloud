//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define BUFFER_SIZE 8192
#define PORT 8080

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./proxy <hostname> <resource>\n");
        exit(1);
    }

    char *proxy_host = "localhost";
    int proxy_port = 8888;

    int sockfd, errnum;
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((errnum = getaddrinfo(proxy_host, NULL, &hints, &res)) != 0) {
        printf("getaddrinfo error: %s\n", gai_strerror(errnum));
        exit(1);
    }

    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(proxy_port);
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr))) {
        perror("bind error");
        exit(1);
    }

    if (listen(sockfd, 10) == -1) {
        perror("listen error");
        exit(1);
    }

    while(1) {
        int clientfd;
        struct sockaddr_in clientaddr;
        socklen_t addrlen = sizeof(clientaddr);
        clientfd = accept(sockfd, (struct sockaddr *)&clientaddr, &addrlen);
        if (clientfd < 0) {
            perror("accept error");
            exit(1);
        }

        pid_t pid = fork();
        if (pid < 0) {
            printf("fork error\n");
            exit(1);
        } else if (pid == 0) { // child process
            close(sockfd);

            // read incoming request
            char buffer[BUFFER_SIZE];
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(clientfd, buffer, BUFFER_SIZE - 1, 0) > 0) {

                // parse the URL into host, port, and path
                char *url = strtok(buffer + 4, " ");
                url[strcspn(url, "\r\n")] = '\0';
                char *host = strstr(url, "://") ? strstr(url, "://") + 3 : url;
                char *port_str = strchr(host, ':');
                int port = port_str != NULL ? atoi(port_str + 1) : 80;
                char *path = strchr(host, '/');
                path = path != NULL ? path : "";

                // print request
                printf("Request: %s %d %s\n", host, port, path);

                // create socket to server
                int serverfd;
                struct addrinfo server_hints, *server_res;

                memset(&server_hints, 0, sizeof server_hints);
                server_hints.ai_family = AF_UNSPEC;
                server_hints.ai_socktype = SOCK_STREAM;

                if ((errnum = getaddrinfo(host, NULL, &server_hints, &server_res)) != 0) {
                    printf("getaddrinfo error: %s\n", gai_strerror(errnum));
                    exit(1);
                }

                struct sockaddr_in server_addr;
                server_addr.sin_family = AF_INET;
                server_addr.sin_port = htons(port);
                server_addr.sin_addr.s_addr = ((struct sockaddr_in *)server_res->ai_addr)->sin_addr.s_addr;

                serverfd = socket(AF_INET, SOCK_STREAM, 0);
                if (serverfd < 0) {
                    perror("socket error");
                    exit(1);
                }

                if (connect(serverfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
                    perror("connect error");
                    exit(1);
                }

                // forward request to server
                char request[BUFFER_SIZE];
                snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
                if (send(serverfd, request, strlen(request), 0) == -1) {
                    perror("send error");
                    exit(1);
                }

                // read response from server and forward to client
                char response[BUFFER_SIZE];
                int bytes_received;
                while ((bytes_received = recv(serverfd, response, BUFFER_SIZE - 1, 0)) > 0) {
                    response[bytes_received] = '\0';

                    if (send(clientfd, response, bytes_received, 0) == -1) {
                        perror("send error");
                        exit(1);
                    }

                    memset(response, 0, BUFFER_SIZE);
                }

                if (bytes_received < 0) {
                    perror("recv error");
                    exit(1);
                }
            }

            close(clientfd);
            exit(0);
        }

        close(clientfd);
    }

    close(sockfd);
    return 0;
}