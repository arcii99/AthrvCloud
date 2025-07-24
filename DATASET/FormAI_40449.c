//FormAI DATASET v1.0 Category: Simple Web Server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 8080

void error_handler(const char *msg) {
        fprintf(stderr, "ERROR: %s\n", msg);
        exit(1);
}

int main(int argc, char *argv[]) {
        int sockfd, newfd, portno, clilen, n;
        char buffer[1024];
        struct sockaddr_in serv_addr, cli_addr;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
                error_handler("Failed to open socket.");
        }

        memset((char *)&serv_addr, 0, sizeof(serv_addr));
        portno = DEFAULT_PORT;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        serv_addr.sin_port = htons(portno);

        if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
                error_handler("Failed to bind socket.");
        }

        listen(sockfd, 5);
        clilen = sizeof(cli_addr);

        while (1) {
                newfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
                if (newfd < 0) {
                        error_handler("Failed to accept connection.");
                }

                memset(buffer, 0, 1024);
                n = read(newfd, buffer, 1024);
                if (n < 0) {
                        error_handler("Failed to read from socket.");
                }

                printf("HTTP Request message received from client:\n%s\n", buffer);

                char *response = "HTTP/1.1 200 OK\nContent-Length: 12\nContent-Type: text/plain\n\nHello World!";
                n = write(newfd, response, strlen(response));
                if (n < 0) {
                        error_handler("Failed to write to socket.");
                }

                close(newfd);
        }

        return 0;
}