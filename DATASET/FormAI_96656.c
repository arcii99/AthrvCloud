//FormAI DATASET v1.0 Category: Simple Web Server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>

#define PORT 8080
#define MAXLINE 1024

void send_file(int sockfd, char* filename) {
    char filebuf[MAXLINE];
    ssize_t n;
    int filefd;

    filefd = open(filename, O_RDONLY);

    if (filefd == -1) {
        char* error_msg = "HTTP/1.1 404 Not Found\r\n"
                          "Content-Type: text/html; charset=utf-8\r\n\r\n";
        write(sockfd, error_msg, strlen(error_msg));
        return;
    }

    char* content_type = strrchr(filename, '.') + 1;
    if (strcmp(content_type, "html") == 0) {
        char* header_msg = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: text/html; charset=utf-8\r\n\r\n";
        write(sockfd, header_msg, strlen(header_msg));
    }
    else if (strcmp(content_type, "jpg") == 0) {
        char* header_msg = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: image/jpeg\r\n\r\n";
        write(sockfd, header_msg, strlen(header_msg));
    }
    else if (strcmp(content_type, "png") == 0) {
        char* header_msg = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: image/png\r\n\r\n";
        write(sockfd, header_msg, strlen(header_msg));
    }
    else if (strcmp(content_type, "css") == 0) {
        char* header_msg = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: text/css; charset=utf-8\r\n\r\n";
        write(sockfd, header_msg, strlen(header_msg));
    }
    else if (strcmp(content_type, "js") == 0) {
        char* header_msg = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: text/javascript; charset=utf-8\r\n\r\n";
        write(sockfd, header_msg, strlen(header_msg));
    }
    else {
        char* header_msg = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: application/octet-stream\r\n\r\n";
        write(sockfd, header_msg, strlen(header_msg));
    }

    while ((n = read(filefd, filebuf, MAXLINE)) > 0) {
        write(sockfd, filebuf, n);
    }

    close(filefd);
}

void handle_http_request(int sockfd) {
    char buffer[MAXLINE];
    char method[MAXLINE];
    char uri[MAXLINE];
    char version[MAXLINE];
    char filename[MAXLINE];

    read(sockfd, buffer, MAXLINE);
    sscanf(buffer, "%s %s %s", method, uri, version);

    if (strcasecmp(method, "GET") == 0) {
        sprintf(filename, "./public%s", uri);
        send_file(sockfd, filename);
    }
    else {
        char* error_msg = "HTTP/1.1 501 Not Implemented\r\n"
                          "Content-Type: text/html; charset=utf-8\r\n\r\n";
        write(sockfd, error_msg, strlen(error_msg));
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 32) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        handle_http_request(new_socket);

        shutdown(new_socket, SHUT_WR);
        close(new_socket);
    }

    return 0;
}