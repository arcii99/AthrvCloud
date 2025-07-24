//FormAI DATASET v1.0 Category: Simple Web Server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

const char* response = "HTTP/1.1 200 OK\r\n"
                       "Content-Type: text/html\r\n"
                       "\r\n"
                       "<!DOCTYPE html>\r\n"
                       "<html>\r\n"
                       "<head>\r\n"
                       "<title>C Simple Web Server</title>\r\n"
                       "</head>\r\n"
                       "<body>\r\n"
                       "<h1>Hello World!</h1>\r\n"
                       "<p>This is a simple web server.</p>\r\n"
                       "</body>\r\n"
                       "</html>\r\n";

int main(int argc, char *argv[]) {
    int sockfd, connfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    socklen_t clilen = sizeof(cli_addr);

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // set server address
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(SERVER_PORT);

    // bind socket to address
    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // listen for connections
    if (listen(sockfd, 5) < 0) {
        perror("ERROR on listening");
        exit(1);
    }

    printf("Server running on port %d...\n", SERVER_PORT);

    // wait for incoming connections
    while (1) {
        // accept connection
        connfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
        if (connfd < 0) {
            perror("ERROR on accepting");
            continue;
        }

        // read request
        bzero(buffer, BUFFER_SIZE);
        n = read(connfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            perror("ERROR reading from socket");
            continue;
        }

        // send response
        n = write(connfd, response, strlen(response));
        if (n < 0) {
            perror("ERROR writing to socket");
        }

        // close connection
        close(connfd);
    }

    // close socket
    close(sockfd);

    return 0;
}