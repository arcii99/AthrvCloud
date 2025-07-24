//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define SERVER_PORT 8080

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd;
    int n;
    socklen_t client_length;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *host;
    char buffer[4096];
    char request_buffer[4096];
    char url[512];
    char *pch;
    char temp[20];
    int remote_fd;
    int i, sent, total = 0, count = 0;

    if (argc < 2)
        error("Usage: proxy <url>");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("Error opening socket");

    bzero((char *) &server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("Error on binding");

    listen(sockfd, 5);

    client_length = sizeof(client_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_length);

        if (newsockfd < 0)
            error("Error on accept");

        bzero(buffer, 4096);
        n = read(newsockfd, buffer, 4096);

        if (n < 0)
            error("Error reading from socket");

        printf("Got request from client:\n%s\n", buffer);

        bzero(request_buffer, 4096);
        strcpy(request_buffer, buffer);
        pch = strstr(request_buffer, "\r\n");

        if (pch != NULL) {
            strncpy(temp, request_buffer, pch - request_buffer);
            temp[pch - request_buffer] = '\0';

            if (sscanf(temp, "GET http://%s HTTP/1.1", url) == 1)
                printf("Requested URL: %s\n", url);
        }

        host = gethostbyname(url);

        if (host == NULL)
            error("Error getting host");

        remote_fd = socket(AF_INET, SOCK_STREAM, 0);

        if (remote_fd < 0)
            error("Error creating socket");

        bzero((char *) &server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        bcopy((char *) host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
        server_addr.sin_port = htons(80);

        if (connect(remote_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
            error("Error connecting");

        printf("Connected to remote server\n");

        n = write(remote_fd, buffer, strlen(buffer));

        if (n < 0)
            error("Error writing to remote server");

        bzero(buffer, 4096);

        while ((n = read(remote_fd, buffer, 2048)) > 0) {
            sent = 0;

            while (sent < n) {
                total = write(newsockfd, buffer + sent, n - sent);

                if (total < 0)
                    error("Error writing to socket");

                sent += total;
            }
        }

        if (n < 0)
            error("Error reading from remote server");

        close(newsockfd);
        close(remote_fd);
    }

    close(sockfd);
    return 0;
}