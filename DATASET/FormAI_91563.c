//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 4096
#define SERVER_PORT 8080
#define SERVER_BACKLOG 20
#define PROXY_PORT 8888

typedef struct {
    int fd;
    struct sockaddr_in client_addr;
} Connection;

void error(char *msg) {
    perror(msg);
    exit(1);
}

void establish_connection(Connection *con, int server_fd) {
    socklen_t len = sizeof(con->client_addr);
    con->fd = accept(server_fd, (struct sockaddr *)&con->client_addr, &len);
    if(con->fd < 0) error("Error accepting connection");
}

void forward_request(Connection *browser_con, Connection *server_con) {
    char buffer[BUFSIZE];
    int n = read(browser_con->fd, buffer, BUFSIZE);
    if(n < 0) error("Error reading from browser");
    n = write(server_con->fd, buffer, n);
    if(n < 0) error("Error writing to server");
}

void forward_response(Connection *browser_con, Connection *server_con) {
    char buffer[BUFSIZE];
    int n = read(server_con->fd, buffer, BUFSIZE);
    if(n < 0) error("Error reading from server");
    n = write(browser_con->fd, buffer, n);
    if(n < 0) error("Error writing to browser");
}

void close_connection(Connection *con) {
    close(con->fd);
}

int main(int argc, char **argv) {
    // Initialize server socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0) error("Error opening server socket");

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = htonl(INADDR_ANY),
        .sin_port = htons(SERVER_PORT)
    };

    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Error binding server socket");

    if(listen(server_fd, SERVER_BACKLOG) < 0)
        error("Error listening on server socket");

    // Initialize proxy socket
    int proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(proxy_fd < 0) error("Error opening proxy socket");

    struct sockaddr_in proxy_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = htonl(INADDR_ANY),
        .sin_port = htons(PROXY_PORT)
    };

    if(bind(proxy_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0)
        error("Error binding proxy socket");

    if(listen(proxy_fd, SERVER_BACKLOG) < 0)
        error("Error listening on proxy socket");

    // Main loop
    while(1) {
        // Accept connections from browser
        Connection browser_con;
        establish_connection(&browser_con, proxy_fd);

        // Connect to server
        Connection server_con;
        server_con.fd = socket(AF_INET, SOCK_STREAM, 0);
        if(server_con.fd < 0) error("Error opening server socket");

        server_con.client_addr.sin_family = AF_INET;
        server_con.client_addr.sin_port = htons(SERVER_PORT);

        char server_ip[16];
        printf("Enter server IP: ");
        scanf("%s", server_ip);
        if(inet_pton(AF_INET, server_ip, &server_con.client_addr.sin_addr) <= 0)
            error("Error converting server IP");

        if(connect(server_con.fd, (struct sockaddr *)&server_con.client_addr, sizeof(server_con.client_addr)) < 0)
            error("Error connecting to server");

        // Forward request to server and response to browser
        forward_request(&browser_con, &server_con);
        forward_response(&browser_con, &server_con);

        // Close connections
        close_connection(&browser_con);
        close_connection(&server_con);
    }

    // Close sockets
    close(server_fd);
    close(proxy_fd);

    return 0;
}