//FormAI DATASET v1.0 Category: Simple Web Server ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 8080
#define BUFF_SIZE 1024

void handle_error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int sockfd, new_sockfd, status;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[BUFF_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        handle_error("Error in creating socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    status = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(status < 0) {
        handle_error("Error in binding socket");
    }

    status = listen(sockfd, 10);
    if(status < 0) {
        handle_error("Error in listening socket");
    }

    printf("Server listening on port %d\n", PORT);

    while(1) {
        addr_size = sizeof(client_addr);
        new_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &addr_size);

        if(new_sockfd < 0) {
            handle_error("Error in accepting connection");
        }

        pid_t pid = fork();
        if(pid == 0) {
            close(sockfd);

            char filename[256];
            sprintf(filename, "./public_html%s", strtok(buffer, " "));
            if(strcmp(filename, "./public_html/") == 0) {
                strcpy(filename, "./public_html/index.html");
            }

            int fd = open(filename, O_RDONLY);
            if(fd < 0) {
                char *msg = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML><html><head><title>Not Found</title></head><body><h1>404 Not Found</h1><p>The requested URL was not found on this server.</p></body></html>";
                send(new_sockfd, msg, strlen(msg), 0);
            } else {
                char buf[BUFF_SIZE] = {0};
                int nbytes = read(fd, buf, BUFF_SIZE);
                send(new_sockfd, buf, nbytes, 0);
                close(fd);
            }

            exit(0);
        } else if(pid < 0) {
            handle_error("Error in forking process");
        } else {
            close(new_sockfd);
        }
    }

    close(sockfd);
    return 0;
}