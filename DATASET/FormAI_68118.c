//FormAI DATASET v1.0 Category: Simple Web Server ; Style: synchronous
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PORT 8080
#define BUFSIZE 1024

void handle_client(int client_sockfd);
char* read_file(char *filename);

int main()
{
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_address, client_address;
    socklen_t address_length = sizeof(struct sockaddr_in);

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sockfd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(struct sockaddr_in));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    if (bind(server_sockfd, (struct sockaddr *) &server_address, address_length) == -1) {
        perror("Failed to bind socket to address");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sockfd, 5) == -1) {
        perror("Failed to start listening");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d\n", PORT);

    while (1) {
        client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, &address_length);

        if (client_sockfd == -1) {
            perror("Failed to accept incoming connection");
            continue;
        }

        handle_client(client_sockfd);
    }

    return EXIT_SUCCESS;
}

void handle_client(int client_sockfd)
{
    char request[BUFSIZE];
    char response[BUFSIZE];
    char *filename = NULL;

    memset(request, 0, BUFSIZE);
    memset(response, 0, BUFSIZE);

    if (recv(client_sockfd, request, BUFSIZE, 0) == -1) {
        perror("Failed to receive request from client");
        close(client_sockfd);
        return;
    }

    if (strncmp(request, "GET ", 4) != 0) {
        sprintf(response, "HTTP/1.1 400 Bad Request\r\nContent-Length: %d\r\nConnection: close\r\n\r\nInvalid Request", strlen("Invalid Request"));
        send(client_sockfd, response, strlen(response), 0);
        close(client_sockfd);
        return;
    }

    filename = strtok(request + 4, " ");

    if (!filename) {
        sprintf(response, "HTTP/1.1 400 Bad Request\r\nContent-Length: %d\r\nConnection: close\r\n\r\nInvalid File Name", strlen("Invalid File Name"));
        send(client_sockfd, response, strlen(response), 0);
        close(client_sockfd);
        return;
    }

    char *file_content = read_file(filename);

    if (!file_content) {
        sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Length: %d\r\nConnection: close\r\n\r\nFile Not Found", strlen("File Not Found"));
        send(client_sockfd, response, strlen(response), 0);
        close(client_sockfd);
        return;
    }

    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\nConnection: close\r\n\r\n%s", strlen(file_content), file_content);

    send(client_sockfd, response, strlen(response), 0);
    close(client_sockfd);
}

char* read_file(char *filename)
{
    FILE *file_ptr = fopen(filename, "rb");

    if (!file_ptr) {
        return NULL;
    }

    fseek(file_ptr, 0, SEEK_END);
    long fsize = ftell(file_ptr);
    fseek(file_ptr, 0, SEEK_SET);

    char *file_content = malloc(fsize + 1);
    fread(file_content, 1, fsize, file_ptr);
    fclose(file_ptr);

    file_content[fsize] = 0;
    return file_content;
}