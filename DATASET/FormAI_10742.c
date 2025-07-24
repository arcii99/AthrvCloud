//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 8192
#define ERR -1
#define OK 0

void error(char *msg) {
    perror(msg);
    exit(ERR);
}

void proxy(int cli_fd) {
    char buf[BUF_SIZE], method[BUF_SIZE], uri[BUF_SIZE], version[BUF_SIZE];
    struct sockaddr_in srv_addr;
    int srv_fd, n;

    memset(buf, 0, sizeof(buf));
    n = read(cli_fd, buf, sizeof(buf) - 1);
    if (n < 0) {
        error("Error reading from client.");
    }
    sscanf(buf, "%s %s %s", method, uri, version);
    if (strcmp(method, "GET") != 0) {
        error("Method not supported.");
    }
    char *host_start = strstr(buf, "Host:");
    if (host_start == NULL) {
        error("Invalid request.");
    }
    sscanf(host_start, "Host: %s", buf);
    printf("Host: %s\n", buf);

    /* Open connection to server */
    srv_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (srv_fd == ERR) {
        error("Error opening server socket.");
    }

    /* Connect to server */
    memset(&srv_addr, 0, sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(80); /* HTTP server port */
    if (inet_pton(AF_INET, buf, &srv_addr.sin_addr) < 1) {
        error("Error invalid server IP address.");
    }
    if (connect(srv_fd, (struct sockaddr *) &srv_addr, sizeof(srv_addr)) < 0) {
        error("Error connecting to server.");
    }

    /* Forward request to server */
    if (write(srv_fd, buf, strlen(buf)) < 0) {
        error("Error writing to server.");
    }

    /* Forward response to client */
    while ((n = read(srv_fd, buf, BUF_SIZE)) > 0) {
        if (write(cli_fd, buf, n) < 0) {
            error("Error writing to client.");
        }
    }

    /* Close sockets */
    close(cli_fd);
    close(srv_fd);
}

int main(int argc, char *argv[]) {
    int cli_fd, srv_fd;
    struct sockaddr_in cli_addr, srv_addr;
    int cli_len;

    /* Create listening socket */
    srv_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (srv_fd == ERR) {
        error("Error creating server socket.");
    }

    /* Bind to local address */
    memset(&srv_addr, 0, sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(8080); /* Proxy server port */
    srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(srv_fd, (struct sockaddr *) &srv_addr, sizeof(srv_addr)) == ERR) {
        error("Error binding server socket.");
    }

    /* Listen for incoming connections */
    if (listen(srv_fd, 5) == ERR) {
        error("Error listening on server socket.");
    }

    /* Main loop */
    while (1) {
        cli_len = sizeof(cli_addr);
        cli_fd = accept(srv_fd, (struct sockaddr *) &cli_addr, &cli_len);
        if (cli_fd == ERR) {
            error("Error accepting client connection.");
        }
        proxy(cli_fd);
    }

    return OK;
}