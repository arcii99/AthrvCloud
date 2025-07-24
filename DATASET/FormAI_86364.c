//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void handle_request(int);

int main(int argc, char *argv[]) {
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cliaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error: socket creation failed!");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("Error: socket binding failed!");
        exit(1);
    }

    if (listen(sockfd, 5) == -1) {
        perror("Error: listen failed!");
        exit(1);
    }

    printf("Listening on port %d\n", 8080);

    while (1) {
        len = sizeof(cliaddr);
        connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
        
        if (connfd == -1) {
            perror("Error: accept failed!");
            exit(1);
        }

        if (fork() == 0) {
            close(sockfd);
            handle_request(connfd);
            close(connfd);
            exit(0);
        }

        close(connfd);
    }

    close(sockfd);
    return 0;
}

void handle_request(int sockfd) {
    int n, i;
    char buffer[1024], out[1024];
    char *host, *path, *port;
    struct sockaddr_in servaddr;
    int sock_fd;

    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));

    printf("Request Received:\n%s\n", buffer);

    host = strstr(buffer, "Host: ");
    path = strchr(buffer, ' ') + 1;
    path = strchr(path, '/') + 1;
    path = strchr(path, '/') + 1;
    path = strchr(path, '/') - 1;

    if (host != NULL) {
        host = strtok(host + 6, "\r\n");
        port = strstr(host, ":");
        if (port != NULL) {
            *port++ = '\0';
        } else {
            port = "80";
        }
    } else {
        host = "localhost";
        port = "80";
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(port));

    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        printf("inet_pton error: %s\n", host);
        exit(1);
    }

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return;
    }

    if (connect(sock_fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Connection Failed\n");
        return;
    }

    sprintf(out, "GET /%s HTTP/1.0\r\nHost: %s:%s\r\n\r\n", path, host, port);

    printf("Request Forwarded:\n%s\n", out);

    write(sock_fd, out, strlen(out));

    bzero(buffer, sizeof(buffer));

    while (read(sock_fd, buffer, sizeof(buffer)) > 0) {
        write(sockfd, buffer, sizeof(buffer));
        bzero(buffer, sizeof(buffer));
    }

    close(sock_fd);
}