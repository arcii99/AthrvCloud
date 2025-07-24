//FormAI DATASET v1.0 Category: Browser Plugin ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
#define BUF_SIZE 1024

int main(int argc, char* argv[]) {
    const char* host = "example.com";
    const char* path = "/";
    char buffer[BUF_SIZE];

    if (argc > 1) {
        host = argv[1];
    }
    if (argc > 2) {
        path = argv[2];
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    snprintf(buffer, sizeof(buffer), "GET %s HTTP/1.1\r\nHost:%s\r\n\r\n", path, host);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        ssize_t n = read(sockfd, buffer, sizeof(buffer) - 1);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        if (n == 0) {
            break;
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    exit(0);
}