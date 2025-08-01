//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

void error(const char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUF_SIZE];

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such host \n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server");
    }

    printf("Enter HTTP request: ");
    memset(buffer, 0, BUF_SIZE);
    scanf("%[^\n]s", buffer);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("Error writing to socket");
    }

    memset(buffer, 0, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);
    if (n < 0) {
        error("Error reading from socket");
    }

    printf("\nHTTP Response:\n%s\n", buffer);

    close(sockfd);
    return 0;
}