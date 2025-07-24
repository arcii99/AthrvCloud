//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 4096 /*Maximum buffer size*/

void proxy(int client_sockfd, struct sockaddr_in serv_addr);

int main(int argc, char **argv) {
    int listenfd, client_sockfd;
    struct sockaddr_in client_addr, serv_addr;
    socklen_t client_len = sizeof(client_addr);

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) { /*Creating socket*/
        perror("Socket error");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr)); /*Setting values to zero*/
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(8080); /*Setting server port*/

    if (bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { /*Binding socket*/
        perror("Bind error");
        exit(1);
    }

    if (listen(listenfd , 10) < 0) { /*Listening for incoming connections*/
        perror("Listen error");
        exit(1);
    }

    printf("Proxy server started on port 8080\n");

    while (1) {
        if ((client_sockfd = accept(listenfd, (struct sockaddr *)&client_addr, &client_len)) < 0) { /*Accepting connections*/
            perror("Accept error");
            exit(1);
        }
        printf("Handling client %s\n", inet_ntoa(client_addr.sin_addr));
        proxy(client_sockfd, serv_addr);
    }

    close(listenfd); /*Closing socket*/
    return 0;
}

void proxy(int client_sockfd, struct sockaddr_in serv_addr) {
    char buffer[MAXLINE], method[MAXLINE], url[MAXLINE], protocol[MAXLINE];
    char *host, *http_version, *path;
    int port = 80, serv_sockfd, n;
    struct sockaddr_in serv_addr_new;
    socklen_t serv_len = sizeof(serv_addr_new);
    bzero(&serv_addr_new, serv_len);

    /*Reading request from client*/
    n = read(client_sockfd, buffer, MAXLINE);

    if ( n < 0 ) {
        perror( "Read error" );
        exit( 1 );
    }

    /*Parsing request method, URL and protocol*/
    sscanf(buffer, "%s %s %s", method, url, protocol);
    printf("Request method: %s\n", method);
    printf("Request URL: %s\n", url);
    printf("Request protocol: %s\n", protocol);

    /*Parsing URL to get host and path*/
    http_version = strstr(url, "://");
    if (http_version != NULL) {
        host = strstr(url, "://") + 3;
    } else {
        host = url;
    }
    path = strchr(host, '/');
    if (path != NULL) {
        *path = '\0';
        path++;
    }
    /*Checking if URL has port specified*/
    char* port_ptr = strstr(host, ":");
    if (port_ptr != NULL) {
        *port_ptr = '\0';
        sscanf(port_ptr + 1, "%d", &port);
    }

    printf("Host: %s\n", host);
    printf("Port: %d\n", port);
    printf("Path: %s\n", path);

    /*Creating new socket for server*/
    if ((serv_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket error");
        exit(1);
    }

    serv_addr_new.sin_family = AF_INET;
    serv_addr_new.sin_port = htons(port);

    if (inet_pton(AF_INET, host, &serv_addr_new.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        exit(1);
    }

    /*Connecting to server*/
    if (connect(serv_sockfd, (struct sockaddr *)&serv_addr_new, serv_len) < 0) {
        perror("Connect error");
        exit(1);
    }

    /*Building request*/
    sprintf(buffer, "%s /%s %s\r\n", method, path, "HTTP/1.1");
    memcpy(buffer + strlen(buffer), "Host: ", 6);
    memcpy(buffer + strlen(buffer), host, strlen(host));
    memcpy(buffer + strlen(buffer), "\r\n", 2);
    memcpy(buffer + strlen(buffer), "Connection: close\r\n", 20);
    memcpy(buffer + strlen(buffer), "\r\n", 2);

    /*Writing request to server*/
    n = write(serv_sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("Error writing to server");
        exit(1);
    }

    /*Reading response from server*/
    bzero(buffer, MAXLINE);
    while ((n = read(serv_sockfd, buffer, MAXLINE)) > 0) {
        if ( write(client_sockfd, buffer, n) < 0 ) {
            perror("Error writing response to client");
            exit(1);
        }
        bzero(buffer, MAXLINE);
    }

    if (n < 0) {
        perror("Error reading response from server");
        exit(1);
    }

    /*Closing sockets*/
    close(serv_sockfd);
    close(client_sockfd);
}