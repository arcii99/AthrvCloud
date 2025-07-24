//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

/* Function to send an HTTP request and print the response */
void send_http_request(char *host, char *path) {
    int sockfd, n;
    char sendline[MAXLINE], recvline[MAXLINE];
    struct sockaddr_in servaddr;

    /* Create the socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    /* Fill in the server address structure */
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    /* Construct the HTTP request */
    sprintf(sendline, "GET /%s HTTP/1.1\r\n", path);
    sprintf(sendline, "%shost: %s\r\n", sendline, host);
    sprintf(sendline, "%sConnection: close\r\n\r\n", sendline);

    /* Send the HTTP request */
    write(sockfd, sendline, strlen(sendline));

    /* Receive and print the HTTP response */
    while ((n = read(sockfd, recvline, MAXLINE-1)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
    }

    /* Close the socket */
    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <host> <path>\n", argv[0]);
        exit(1);
    }

    /* Send the HTTP request and print the response */
    send_http_request(argv[1], argv[2]);

    return 0;
}