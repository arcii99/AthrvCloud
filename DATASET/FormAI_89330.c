//FormAI DATASET v1.0 Category: Simple Web Server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

#define BUFSIZE 1024
#define SERVER_PORT 8080

void error_handler(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        error_handler("socket()");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
        error_handler("bind()");

    if (listen(server_socket, 1024) == -1)
        error_handler("listen()");
    
    printf("Web server started and listening on port %d...\n", SERVER_PORT);

    while (1) {
        char request[BUFSIZE] = {0};
        char response[BUFSIZE] = {0};
        char file_path[BUFSIZE] = {0};
        ssize_t bytes_recv, bytes_sent;
        int fd, flags;
        time_t now;
        struct tm *tm;

        socklen_t client_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket == -1)
            error_handler("accept()");

        bytes_recv = recv(client_socket, request, sizeof(request), 0);
        if (bytes_recv == -1)
            error_handler("recv()");

        printf("Received request from %s:%d:\n%s\n", 
            inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), request);

        sscanf(request, "GET %s HTTP/1.%*[01]\r\n", file_path);
        if (strcmp(file_path, "/") == 0)
            strcpy(file_path, "index.html");

        fd = open(file_path, O_RDONLY);
        if (fd == -1) {
            sprintf(response, "HTTP/1.1 404 Not Found\r\n\r\n");
            bytes_sent = send(client_socket, response, strlen(response), 0);
            if (bytes_sent == -1)
                error_handler("send()");
            printf("Sent response:\n%s\n", response);
        } else {
            flags = fcntl(fd, F_GETFL);
            fcntl(fd, F_SETFL, flags | O_NONBLOCK);
            sprintf(response, "HTTP/1.1 200 OK\r\n");
            tm = localtime(&now);
            strftime(response + strlen(response), BUFSIZE - strlen(response), "Date: %a, %d %b %Y %H:%M:%S %Z\r\n", tm);
            struct stat filestat;
            stat(file_path, &filestat);
            sprintf(response + strlen(response), "Content-Length: %ld\r\n", filestat.st_size);
            sprintf(response + strlen(response), "Content-Type: text/html\r\n\r\n");
            printf("Sent response headers:\n%s\n", response);
            bytes_sent = send(client_socket, response, strlen(response), 0);
            if (bytes_sent == -1)
                error_handler("send()");

            int bytes_read;
            while ((bytes_read = read(fd, response, BUFSIZE)) > 0) {
                response[bytes_read] = '\0';
                bytes_sent = send(client_socket, response, bytes_read, 0);
                if (bytes_sent == -1)
                    error_handler("send()");
                printf("Sent file data:\n%s\n", response);
            }
            
            close(fd);
        }

        close(client_socket);
    }

    close(server_socket);

    return 0;
}