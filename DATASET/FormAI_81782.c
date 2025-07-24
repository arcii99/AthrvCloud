//FormAI DATASET v1.0 Category: Simple Web Server ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

char *ROOT_DIRECTORY = ".";

void handle_request(int client_sockfd) {
    char buffer[BUFFER_SIZE];
    int n = read(client_sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    if (strncmp(buffer, "GET /", 5) == 0) {
        char file_path[BUFFER_SIZE];
        sscanf(buffer, "GET /%s ", file_path);
        if (strlen(file_path) == 0) {
            strcpy(file_path, "index.html");
        }
        char full_path[BUFFER_SIZE];
        sprintf(full_path, "%s/%s", ROOT_DIRECTORY, file_path);
        FILE *fp = fopen(full_path, "rb");
        if (fp == NULL) {
            char response[BUFFER_SIZE];
            sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<html><head><title>404 Not Found</title></head><body><h1>404 Not Found</h1></body></html>");
            write(client_sockfd, response, strlen(response));
            return;
        }
        char response[BUFFER_SIZE];
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
        write(client_sockfd, response, strlen(response));
        while ((n = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
            write(client_sockfd, buffer, n);
        }
        fclose(fp);
    } else {
        char response[BUFFER_SIZE];
        sprintf(response, "HTTP/1.1 400 Bad Request\r\nContent-Type: text/html\r\n\r\n<html><head><title>400 Bad Request</title></head><body><h1>400 Bad Request</h1></body></html>");
        write(client_sockfd, response, strlen(response));
    }
}

int main(int argc, char *argv[]) {
    int server_sockfd, client_sockfd;
    socklen_t client_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s <root_directory>\n", argv[0]);
        exit(1);
    }
    ROOT_DIRECTORY = argv[1];

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding to socket");
        exit(1);
    }

    listen(server_sockfd, 5);
    client_len = sizeof(client_addr);

    while (1) {
        client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (client_sockfd < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        handle_request(client_sockfd);

        close(client_sockfd);
    }

    close(server_sockfd);
    return 0;
}