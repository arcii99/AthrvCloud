//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 4096
#define LISTENQ 1024
#define SERV_PORT 8080
#define WEB_PORT 80

void doit(int connfd);

int main(int argc, char **argv){
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in servaddr, cliaddr;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    
    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(listenfd, LISTENQ);

    printf("Proxy server started listening on port %d...\n", SERV_PORT);

    for (;;) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
        if ((childpid = fork()) == 0) {
            close(listenfd);
            doit(connfd);
            close(connfd);
            exit(0);
        }
        close(connfd);
        while(waitpid(-1, NULL, WNOHANG) > 0);
    }
}

void doit(int connfd){
    char buffer[MAXLINE];
    int n, i, port = WEB_PORT, flag = 0, j;
    struct sockaddr_in servaddr;
    char method[10], host[MAXLINE], uri[MAXLINE], protocol[MAXLINE], req[MAXLINE], resp[MAXLINE];
    char *temp, *token;
    char *server_url, *server_host, *server_path;
    int server_fd, content_length;

    n = read(connfd, buffer, MAXLINE);
    strncpy(req, buffer, n);
    printf("-----------------Request------------------\n%s", req);

    // parsing request
    token = strtok(buffer, "\r\n");
    sscanf(token, "%s %s %s", method, uri, protocol);
    i = strlen(method) + strlen(uri) + strlen(protocol) + 3;
    memcpy(buffer, buffer+i, n-i);
    while(token != NULL){
        if(strncasecmp(token, "host", 4) == 0){
            sscanf(token, "%*s %s", host);
            temp = strstr(host, ":");
            if(temp != NULL){
                *temp++ = '\0';
                sscanf(temp, "%d", &port);
            }
            flag = 1;
        }
        if(strncasecmp(token, "content-length", 14) == 0){
            sscanf(token, "%*s %d", &content_length);
        }
        token = strtok(NULL, "\r\n");
    }

    if(flag == 0){
        printf("no host found in the request header\n");
        return;
    }

    if(strncasecmp(method, "connect", 7) == 0){
        printf("connect method not supported\n");
        return;
    }

    server_host = host;
    server_url = uri + 7;
    temp = strchr(server_url, '/');
    if(temp == NULL){
        server_path = "/";
    }
    else{
        server_path = temp;
        *temp = '\0';
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, server_host, &servaddr.sin_addr);

    if(connect(server_fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        printf("connection failed: %s\n", strerror(errno));
        return;
    }

    sprintf(buffer, "%s %s %s\r\n", method, server_path, protocol);
    write(server_fd, buffer, strlen(buffer));

    while((n = read(connfd, buffer, MAXLINE)) > 0){
        write(server_fd, buffer, n);
        if(n < MAXLINE){
            buffer[n] = '\0';
            break;
        }
    }
    printf("----------------Request Body----------------\n%s", buffer);

    memset(buffer, 0, MAXLINE);

    while((n = read(server_fd, buffer, MAXLINE)) > 0){
        write(connfd, buffer, n);
        if(n < MAXLINE){
            buffer[n] = '\0';
            break;
        }
    }
    printf("----------------Response-----------------\n%s", buffer);
    close(server_fd);
}