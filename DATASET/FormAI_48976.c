//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAXLINE 8192 /* max text line length */
#define SERV_PORT 80 /* port number */
#define LISTENQ 1024 /* maximum number of client connections */

/* Error Handling wrapper function */
void error(char *msg) {
    perror(msg);
    exit(1);
}

/* Read and process HTTP request headers */
int read_requesthdrs(int sockfd) {
    char buf[MAXLINE];

    /* Read and parse headers */
    while (read(sockfd, buf, MAXLINE) > 0) {
        if (strcmp(buf, "\r\n") == 0) {
            break; /* End of headers */
        }
        printf("%s", buf); /* Print headers */
    }
    return 0;
}

/* Forward HTTP request to the server and relay response back to the client */
int client_handler(int connfd) {
    int serverfd;
    ssize_t n;
    char buf[MAXLINE];
    char method[MAXLINE], uri[MAXLINE], version[MAXLINE];
    char hostname[MAXLINE], port[MAXLINE];
    char request[MAXLINE], response[MAXLINE];
    char *ptr;

    /* Read request line */
    if (read(connfd, buf, MAXLINE) <= 0) {
        return -1;
    }
    printf("%s", buf);
    
    /* Parse request line */
    sscanf(buf, "%s %s %s", method, uri, version);

    /* Parse hostname and port from URI */
    ptr = strstr(uri, "//");
    if (ptr == NULL) {
        error("Invalid URI");
    }
    ptr += 2;
    sscanf(ptr, "%[^:/]:%[^/]/", hostname, port);

    /* Construct HTTP request to server */
    sprintf(request, "%s /%s %s\r\nHost: %s:%s\r\nConnection: close\r\n\r\n", method, uri, version, hostname, port);

    /* Connect to server and send request */
    if ((serverfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }
    struct hostent *he = gethostbyname(hostname);
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(port));
    memcpy(&serveraddr.sin_addr, he->h_addr_list[0], he->h_length);
    connect(serverfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    write(serverfd, request, strlen(request));

    /* Read response from server and forward to client */
    while ((n = read(serverfd, response, MAXLINE)) > 0) {
        write(connfd, response, n);
    }

    /* Close server and client connections */
    close(serverfd);
    close(connfd);
    return 0;
}

/* Main function that listens for client connections and spawns handler threads */
int main(int argc, char **argv) {
    int listenfd, connfd;
    pid_t pid;
    socklen_t clientlen;
    struct sockaddr_in clientaddr;
    char client_hostname[MAXLINE], client_port[MAXLINE];

    /* Create socket and bind to port */
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket Error");
    }
    int optval = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(SERV_PORT);
    if (bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        error("Bind Error");
    }

    /* Listen for client connections */
    if (listen(listenfd, LISTENQ) < 0) {
        error("Listen Error");
    }
    printf("Proxy listening on port %d...\n", SERV_PORT);

    /* Loop forever to accept and handle client connections */
    while (1) {
        clientlen = sizeof(clientaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen)) < 0) {
            error("Accept Error");
        }

        /* Print client information */
        if (getnameinfo((struct sockaddr *)&clientaddr, clientlen, client_hostname, MAXLINE, client_port, MAXLINE, 0) == 0) {
            printf("Accepted connection from %s:%s\n", client_hostname, client_port);
        } else {
            printf("Accepted connection from unknown client\n");
        }

        /* Fork a child process to handle the connection */
        if ((pid = fork()) == 0) { /* Child process */
            close(listenfd);
            client_handler(connfd);
            exit(0);
        } else { /* Parent process */
            close(connfd);
        }
    }
    return 0; /* not reached */
}