//FormAI DATASET v1.0 Category: Simple Web Server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define PORT 8080
#define BUFSIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[BUFSIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    int fd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("ERROR on accept");
        }

        bzero(buffer, BUFSIZE);
        n = read(newsockfd, buffer, BUFSIZE);

        if (n < 0) {
            error("ERROR reading from socket");
        }

        char *token;
        token = strtok(buffer, " ");
        if (strcmp(token, "GET") == 0) {
            token = strtok(NULL, " ");
            printf("Request for file: %s\n", token);

            if (strcmp(token, "/") == 0) {
                token = "/index.html";
            }

            token++;
            fd = open(token, O_RDONLY);

            if (fd < 0) {
                error("ERROR opening file");
            }

            struct stat fileinfo;
            stat(token, &fileinfo);

            char contentlength[1000], contenttype[1000];
            bzero(contentlength, 1000);
            bzero(contenttype, 1000);

            sprintf(contentlength, "%ld", fileinfo.st_size);
            if (strstr(token, ".html")) {
                strcpy(contenttype, "Content-Type: text/html");
            } else if (strstr(token, ".jpg")) {
                strcpy(contenttype, "Content-Type: image/jpeg");
            } else if (strstr(token, ".css")) {
                strcpy(contenttype, "Content-Type: text/css");
            } else if (strstr(token, ".js")) {
                strcpy(contenttype, "Content-Type: application/javascript");
            }

            n = write(newsockfd, "HTTP/1.1 200 OK\r\n", 17);
            n = write(newsockfd, "Server: Simple Web Server\r\n", 27);
            n = write(newsockfd, contenttype, strlen(contenttype));
            n = write(newsockfd, "\r\n", 2);
            n = write(newsockfd, "Content-Length: ", 16);
            n = write(newsockfd, contentlength, strlen(contentlength));
            n = write(newsockfd, "\r\n", 2);
            n = write(newsockfd, "Connection: keep-alive\r\n", 24);

            n = write(newsockfd, "\r\n", 2);

            while ((n = read(fd, buffer, BUFSIZE)) > 0) {
                write(newsockfd, buffer, n);
            }

            close(fd);
        } else {
            n = write(newsockfd, "HTTP/1.1 400 Bad Request\r\n", 26);
            n = write(newsockfd, "Server: Simple Web Server\r\n", 27);
            n = write(newsockfd, "Content-Type: text/html\r\n", 25);
            n = write(newsockfd, "\r\n", 2);
            n = write(newsockfd, "<html>400 Bad Request</html>", 28);
        }
        close(newsockfd);
    }
    close(sockfd);
    return 0;
}