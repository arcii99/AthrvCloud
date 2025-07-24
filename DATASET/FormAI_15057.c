//FormAI DATASET v1.0 Category: Simple Web Server ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <netdb.h>
#include <ctype.h>

#define MAXLINE 1024
#define SERV_PORT 8080
#define LISTENQ 1024

int main(int argc, char **argv) {
    struct sockaddr_in cliaddr, servaddr;
    int listenfd, connfd;
    char buf[MAXLINE];
    char message[MAXLINE];
    char *root = getenv("PWD");

    signal(SIGPIPE, SIG_IGN);

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind error");
        exit(1);
    }

    if (listen(listenfd, LISTENQ) == -1) {
        perror("listen error");
        exit(1);
    }

    printf("Server running on http://localhost:%d/ (Press CTRL+C to quit)\n", SERV_PORT);

    while (1) {
        socklen_t clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
        printf("Connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        if (fork() == 0) {
            close(listenfd);

            int n;
            int fd;
            char *method;
            char *uri;
            char *protocol;
            char path[MAXLINE];

            memset(buf, 0, MAXLINE);
            n = read(connfd, buf, MAXLINE);
            buf[n] = '\0';
            printf("Request: %s", buf);

            method = strtok(buf, " ");
            uri = strtok(NULL, " ");
            protocol = strtok(NULL, "\r\n");
            while (uri != NULL && uri[0] == '/') uri++;

            sscanf(uri, "%[^?]?%s", path, message);

            if (strcmp(path, "") == 0)
                strcpy(path, "index.html");
            sprintf(path, "%s/%s", root, path);

            if (access(path, F_OK) == -1) {
                printf("File not found: %s\n", path);
                n = sprintf(buf, "HTTP/1.1 404 Not Found\r\n\r\n");
                write(connfd, buf, n);
            } else {
                printf("Serving file: %s\n", path);
                char *ext = strrchr(path, '.');
                if (ext && strcmp(ext, ".html") == 0)
                    n = sprintf(buf, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
                else if (ext && strcmp(ext, ".css") == 0)
                    n = sprintf(buf, "HTTP/1.1 200 OK\r\nContent-Type: text/css\r\n\r\n");
                else if (ext && strcmp(ext, ".js") == 0)
                    n = sprintf(buf, "HTTP/1.1 200 OK\r\nContent-Type: application/javascript\r\n\r\n");
                else
                    n = sprintf(buf, "HTTP/1.1 200 OK\r\n\r\n");
                write(connfd, buf, n);

                if ((fd = open(path, O_RDONLY)) != -1) {
                    while ((n = read(fd, buf, MAXLINE)) > 0) {
                        write(connfd, buf, n);
                    }
                    close(fd);
                }
            }

            exit(0);
        }

        close(connfd);
    }

    return 0;
}