//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[4096];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // server IP address and port
    char* server_ip = "127.0.0.1";
    portno = 5000;

    // set server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, server_ip, &serv_addr.sin_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server");
    }

    // send HTTP GET request
    char* request = "GET /index.html HTTP/1.1\r\nHost: localhost:5000\r\n\r\n";
    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        error("Error writing to socket");
    }

    // receive HTTP response
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        error("Error reading from socket");
    }

    // print HTTP response
    printf("%s\n", buffer);

    // close socket
    close(sockfd);

    return 0;
}