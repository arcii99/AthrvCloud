//FormAI DATASET v1.0 Category: Networking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void udp_server() {
    struct sockaddr_in servaddr, cliaddr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8000);
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind() failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    char buffer[1024];
    while (1) {
        socklen_t len = sizeof(cliaddr);
        ssize_t n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
        if (n < 0) {
            perror("recvfrom() failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        printf("Received message: %s", buffer);
        if (sendto(sockfd, buffer, n, 0, (const struct sockaddr *)&cliaddr, len) < 0) {
            perror("sendto() failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
    }
}

void tcp_server() {
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8001);
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind() failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    if (listen(sockfd, 5) < 0) {
        perror("listen() failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    int connfd;
    struct sockaddr_in cliaddr;
    socklen_t clilen = sizeof(cliaddr);
    while (1) {
        connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        if (connfd < 0) {
            perror("accept() failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        char buffer[1024];
        ssize_t n = recv(connfd, buffer, sizeof(buffer), 0);
        if (n < 0) {
            perror("recv() failed");
            close(connfd);
            continue;
        } else if (n == 0) {
            printf("Connection closed by client.\n");
            close(connfd);
            continue;
        }
        printf("Received message: %s", buffer);
        if (send(connfd, buffer, n, 0) < 0) {
            perror("send() failed");
            close(connfd);
            continue;
        }
    }
}

int main() {
    char input[50];
    printf("Enter mode: ");
    fgets(input, sizeof(input), stdin);
    if (strcasecmp(input, "udp\n") == 0) {
        udp_server();
    } else if (strcasecmp(input, "tcp\n") == 0) {
        tcp_server();
    } else {
        printf("Invalid mode.\n");
        return 1;
    }
    return 0;
}