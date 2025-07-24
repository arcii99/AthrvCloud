//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_RESPONSE_SIZE 1024
#define HTTP_PORT 80

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_RESPONSE_SIZE];
    char *request = "GET / HTTP/1.0\r\n\r\n"; // sending a HTTP GET request
    char *ip = "example.com";
   
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(HTTP_PORT);

    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        error("ERROR invalid IP address");
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    bzero(buffer, MAX_RESPONSE_SIZE);
    n = read(sockfd, buffer, MAX_RESPONSE_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer); // print the response
    close(sockfd);

    return 0;
}