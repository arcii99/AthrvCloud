//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFSIZE 4096

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} connection_t;

typedef struct {
    char *host;
    int port;
    char *path;
} request_t;

// create a socket connection
connection_t connect_to_server(char *server_ip, int server_port) {
    connection_t conn;
    conn.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (conn.sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&conn.addr, 0, sizeof(conn.addr));
    conn.addr.sin_family = AF_INET;
    conn.addr.sin_addr.s_addr = inet_addr(server_ip);
    conn.addr.sin_port = htons(server_port);

    if (connect(conn.sockfd, (struct sockaddr *)&conn.addr, sizeof(conn.addr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    return conn;
}

// parse the request from the client
request_t parse_request(char *request_msg) {
    request_t req;
    char *token = strtok(request_msg, "\r\n");
    sscanf(token, "GET http://%[^/]/%s", req.host, req.path);
    char *port_str = strchr(req.host, ':');
    if (port_str) {
        sscanf(port_str, ":%d", &req.port);
        *port_str = '\0';
    } else {
        req.port = PORT;
    }

    return req;
}

// send the request to the server
void send_request(connection_t conn, request_t req) {
    char request_buf[BUFSIZE];
    snprintf(request_buf, BUFSIZE, "GET /%s HTTP/1.0\r\nHost: %s\r\nConnection: close\r\n\r\n", req.path, req.host);
    write(conn.sockfd, request_buf, strlen(request_buf));
}

// get the response from the server and send it back to the client
void send_response(int client_sockfd, connection_t conn) {
    char response_buf[BUFSIZE];
    ssize_t n = 0;

    while((n = read(conn.sockfd, response_buf, BUFSIZE)) > 0) {
        write(client_sockfd, response_buf, n);
    }
}

int main(int argc, char *argv[]) {
    int sockfd, client_sockfd;
    struct sockaddr_in addr;
    int opt = 1;
    char buf[BUFSIZE];
    char client_addr[INET_ADDRSTRLEN];
    socklen_t addr_len = sizeof(addr);

    // create a socket for the proxy server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // bind the socket to a port
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(sockfd, 10) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Simple HTTP Proxy listening on port %d\n", PORT);

    // handle incoming connections
    while(1) {
        client_sockfd = accept(sockfd, (struct sockaddr *)&addr, &addr_len);
        if (client_sockfd == -1) {
            perror("Error accepting connection");
            continue;
        }

        inet_ntop(AF_INET, &addr.sin_addr, client_addr, INET_ADDRSTRLEN);
        printf("Connection from %s\n", client_addr);

        memset(buf, 0, BUFSIZE);
        ssize_t n = read(client_sockfd, buf, BUFSIZE);
        if (n == -1) {
            perror("Error reading from client");
            close(client_sockfd);
            continue;
        }

        request_t req = parse_request(buf);
        connection_t conn = connect_to_server(req.host, req.port);
        send_request(conn, req);
        send_response(client_sockfd, conn);

        close(conn.sockfd);
        close(client_sockfd);
    }

    close(sockfd);

    return 0;
}