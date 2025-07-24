//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define LOCALPORT 8080
#define REMOTEPORT 80

void handle_connection(int connfd);

int main() {
    int sockfd, connfd, clilen;
    struct sockaddr_in cli_addr, serv_addr;

    /* create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    /* bind to local port */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(LOCALPORT);

    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }

    /* wait for incoming connections */
    listen(sockfd, 5);

    while(1) {
        clilen = sizeof(cli_addr);
        connfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        
        if(connfd < 0) {
            perror("ERROR on accept");
            exit(EXIT_FAILURE);
        }

        /* handle incoming connection */
        handle_connection(connfd);
    }

    exit(EXIT_SUCCESS);
}

void handle_connection(int connfd) {
    int sockfd, n;
    char buffer[1024];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* read client request */
    bzero(buffer, 1024);
    n = read(connfd, buffer, 1023);
    if(n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("Request from client:\n");
    printf("%s\n", buffer);

    /* extract remote host and path */
    char *host_begin = strstr(buffer, "Host: ") + 6;
    char *host_end = strstr(host_begin, "\r\n");
    int host_len = host_end - host_begin;
    char remote_host[host_len + 1];
    strncpy(remote_host, host_begin, host_len);
    remote_host[host_len] = '\0';

    char *path_begin = strstr(buffer, " ") + 1;
    char *path_end = strstr(path_begin, " HTTP/");
    int path_len = path_end - path_begin;
    char remote_path[path_len + 1];
    strncpy(remote_path, path_begin, path_len);
    remote_path[path_len] = '\0';

    printf("Remote host: %s\n", remote_host);
    printf("Remote path: %s\n", remote_path);

    /* create socket for remote server */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    /* lookup remote server */
    server = gethostbyname(remote_host);
    if(server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    /* connect to remote server */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(REMOTEPORT);

    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    /* forward client request to remote server */
    n = write(sockfd, buffer, strlen(buffer));
    if(n < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    /* read response from remote server */
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if(n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("Response from server:\n");
    printf("%s\n", buffer);

    /* forward response to client */
    n = write(connfd, buffer, strlen(buffer));
    if(n < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    close(connfd);
    close(sockfd);
}