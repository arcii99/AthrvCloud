//FormAI DATASET v1.0 Category: Simple Web Server ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

char* response_html = "<html><head><title>The Socktopus</title></head>"
"<body><h1>Welcome to the Socktopus</h1><p>Our servers are powered by the majestic socktopus. Please enjoy your stay.</p></body></html>";

void handle_client(int sockfd) {
    char buf[1024];
    read(sockfd, buf, 1024);
    printf("Request: %s\n", buf);

    char* response_status = "HTTP/1.1 200 OK\r\n";
    char* response_content_type = "Content-Type: text/html; charset=UTF-8\r\n";
    char response_headers[1024];
    sprintf(response_headers, "%s%sContent-Length: %ld\r\n\r\n", response_status, response_content_type, strlen(response_html));
    write(sockfd, response_headers, strlen(response_headers));
    write(sockfd, response_html, strlen(response_html));
    close(sockfd);
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    int port = 8000;
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY,
    };
    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) == -1) {
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }

    printf("The socktopus is listening on port %d\n", port);
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        int client_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
        if (client_sockfd == -1) {
            perror("Failed to accept client connection");
            continue;
        }

        handle_client(client_sockfd);
    }
    return 0;
}