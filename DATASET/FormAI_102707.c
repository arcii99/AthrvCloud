//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 100
#define MAX_REQUEST_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, n;
    socklen_t clilen;
    char buffer[MAX_REQUEST_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int yes = 1;
    char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE html><html><head><title>Ada Lovelace Style Web Server in C</title></head><body><h1>Congratulations, you have successfully accessed the Ada Lovelace Style Web Server in C!</h1></body></html>\r\n";

    /* Set up the socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Unable to open socket");
    }

    /* Allow reuse of the address */
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        error("Unable to set socket options");
    }

    /* Initialize the server address structure */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    /* Bind the socket to the address */
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Unable to bind socket");
    }

    /* Listen for incoming connections */
    listen(sockfd, MAX_CONNECTIONS);
    clilen = sizeof(cli_addr);
    while (1) {
        /* Accept an incoming connection */
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("Unable to accept connection");
        }

        /* Receive the HTTP request from the client */
        memset(buffer, 0, MAX_REQUEST_SIZE);
        n = read(newsockfd, buffer, MAX_REQUEST_SIZE - 1);
        if (n < 0) {
            error("Unable to read from socket");
        }

        /* Send the HTTP response to the client */
        n = write(newsockfd, response, strlen(response));
        if (n < 0) {
            error("Unable to write to socket");
        }

        /* Close the connection */
        close(newsockfd);
    }
    close(sockfd);
    return 0;
}