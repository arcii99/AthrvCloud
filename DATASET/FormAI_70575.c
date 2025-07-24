//FormAI DATASET v1.0 Category: Simple Web Server ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PORT 8080
#define WEBROOT "/var/www/html"

void handle_request(int conn_fd)
{
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    int count = read(conn_fd, buffer, sizeof(buffer) - 1);

    if(count == -1) {
        perror("read");
        return;
    }

    if(count == 0) {
        fprintf(stderr, "client disconnected\n");
        return;
    }

    printf("Received message: %s\n", buffer);

    char* method = strtok(buffer, " ");
    char* uri = strtok(NULL, " ");

    if(strcmp(uri, "/") == 0) {
        uri = "/index.html";
    }

    char filename[128];
    snprintf(filename, sizeof(filename), "%s%s", WEBROOT, uri);

    int fd = open(filename, O_RDONLY);
    if(fd == -1) {
        perror("open");
        return;
    }

    off_t size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    char headers[1024];
    snprintf(headers, sizeof(headers),
             "HTTP/1.1 200 OK\r\n"
             "Content-Type: text/html\r\n"
             "Content-Length: %ld\r\n\r\n", size);

    write(conn_fd, headers, strlen(headers));

    while(1) {
        count = read(fd, buffer, sizeof(buffer));

        if(count == -1) {
            perror("read");
            return;
        }

        if(count == 0) {
            break;
        }

        write(conn_fd, buffer, count);
    }

    close(fd);
}

int main(int argc, char** argv)
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    int reuseaddr = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr));

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY,
    };

    if(bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if(listen(server_fd, 10) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    while(1) {
        struct sockaddr_in client_addr;
        socklen_t client_addrlen = sizeof(client_addr);
        int conn_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addrlen);

        if(conn_fd == -1) {
            perror("accept");
            return EXIT_FAILURE;
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));
        printf("client connected: %s\n", client_ip);

        handle_request(conn_fd);

        close(conn_fd);
        printf("connection closed: %s\n", client_ip);
    }

    return EXIT_SUCCESS;
}