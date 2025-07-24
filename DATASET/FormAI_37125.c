//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

#define MAXBUF 1024 /* max size of buffer for requests and responses */
#define PORT 80 /* default port number for HTTP */
#define MAXCLIENTS 50 /* max number of clients that can be handled */

/* structure to hold client information */
struct Client {
    int sock_fd; /* socket file descriptor */
    char buffer[MAXBUF]; /* buffer to hold client request */
    int buffer_len; /* length of data in buffer */
};

/* function to handle a client's request */
void handle_client(struct Client *client) {
    /* parse the request to get the URL */
    char *url = strstr(client->buffer, "http://");
    if (url == NULL) {
        /* if the URL is not specified, send a bad request response */
        snprintf(client->buffer, MAXBUF, "HTTP/1.1 400 Bad Request\r\n\r\n");
        write(client->sock_fd, client->buffer, strlen(client->buffer));
        return;
    }

    /* remove the "http://" from the URL */
    url += strlen("http://");

    /* find the first '/' after "http://" to get the hostname */
    char *hostname = strchr(url, '/');
    if (hostname == NULL) {
        /* if the hostname is not specified, send a bad request response */
        snprintf(client->buffer, MAXBUF, "HTTP/1.1 400 Bad Request\r\n\r\n");
        write(client->sock_fd, client->buffer, strlen(client->buffer));
        return;
    }
    *hostname++ = '\0'; /* null-terminate the hostname */

    /* open a socket to the hostname and port */
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        /* if the hostname cannot be resolved, send a not found response */
        snprintf(client->buffer, MAXBUF, "HTTP/1.1 404 Not Found\r\n\r\n");
        write(client->sock_fd, client->buffer, strlen(client->buffer));
        return;
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        /* if the socket cannot be created, send an internal server error response */
        snprintf(client->buffer, MAXBUF, "HTTP/1.1 500 Internal Server Error\r\n\r\n");
        write(client->sock_fd, client->buffer, strlen(client->buffer));
        return;
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr = *((struct in_addr*)host->h_addr)
    };

    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        /* if cannot connect to the server, send a gateway timeout response */
        snprintf(client->buffer, MAXBUF, "HTTP/1.1 504 Gateway Timeout\r\n\r\n");
        write(client->sock_fd, client->buffer, strlen(client->buffer));
        close(sock_fd);
        return;
    }

    /* send the client request to the server */
    write(sock_fd, client->buffer, client->buffer_len);

    /* forward the server's response to the client */
    ssize_t nread;
    while ((nread = read(sock_fd, client->buffer, MAXBUF)) > 0) {
        write(client->sock_fd, client->buffer, nread);
    }

    /* close the socket to the server */
    close(sock_fd);
}

int main() {
    /* create a socket to listen for client connections */
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        exit(1);
    }

    /* allow the socket to be reused */
    int yes = 1;
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    /* bind the socket to a port */
    struct sockaddr_in listen_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };
    if (bind(listen_fd, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    /* listen for client connections */
    if (listen(listen_fd, MAXCLIENTS) == -1) {
        perror("listen");
        exit(1);
    }
    printf("Listening on port %d...\n", PORT);

    /* initialize an array of clients */
    struct Client clients[MAXCLIENTS];
    int nclients = 0;

    while (1) {
        /* wait for a client connection */
        int client_fd = accept(listen_fd, NULL, NULL);

        /* if max number of clients has been reached, send a service unavailable response */
        if (nclients == MAXCLIENTS) {
            char buffer[MAXBUF];
            snprintf(buffer, MAXBUF, "HTTP/1.1 503 Service Unavailable\r\n\r\n");
            write(client_fd, buffer, strlen(buffer));
            close(client_fd);
            continue;
        }

        /* add the client to the array */
        clients[nclients].sock_fd = client_fd;
        clients[nclients].buffer_len = read(client_fd, clients[nclients].buffer, MAXBUF);
        nclients++;

        /* handle the client's request in a separate process */
        if (fork() == 0) {
            handle_client(&clients[nclients-1]);
            close(client_fd);
            exit(0);
        }
    }

    return 0;
}