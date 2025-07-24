//FormAI DATASET v1.0 Category: Simple Web Server ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFSIZE 1024

void handle_request(int sock) {
    char buf[BUFSIZE];
    char msg[] = "HTTP/1.1 200 OK\n"
                 "Content-Type: text/html\n"
                 "\n"
                 "<html><body><h1>Hello, world!</h1></body></html>\n";

    memset(buf, 0, BUFSIZE);

    if (recv(sock, buf, BUFSIZE, 0) < 0) {
        perror("recv");
        return;
    }

    printf("%s\n", buf);

    if (send(sock, msg, strlen(msg), 0) < 0) {
        perror("send");
        return;
    }

    close(sock);
}

int main(int argc, char const *argv[]) {
    struct sockaddr_in server_addr, client_addr;
    int server_fd, client_fd, opt = 1;
    socklen_t addrlen = sizeof(client_addr);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return -1;
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen");
        return -1;
    }

    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen)) < 0) {
            perror("accept");
            return -1;
        }

        handle_request(client_fd);
    }

    return 0;
}