//FormAI DATASET v1.0 Category: Simple Web Server ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/stat.h>

#define WEB_ROOT "./webroot"
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

void handle_request(int);
void serve_file(int, char*);
void send_error(int, int, char*);
void exit_with_error(const char*);
void set_non_blocking(int);

int main(int argc, char **argv)
{
    int server_fd, client_fd, opt = 1, port = 8080;
    struct sockaddr_in server_address, client_address;
    socklen_t address_len = sizeof(client_address);
    char buffer[BUFFER_SIZE] = {0};
    long valread;

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        exit_with_error("Failed to create socket.");
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0)
    {
        exit_with_error("Failed to set socket options.");
    }

    // Bind server socket to a port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
    {
        exit_with_error("Failed to bind socket to port.");
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0)
    {
        exit_with_error("Failed to listen for incoming connections.");
    }

    printf("Server started at port %d, awaiting connections...\n", port);

    // Accept incoming connections
    while (1)
    {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, &address_len)) < 0)
        {
            exit_with_error("Failed to accept incoming connection.");
        }

        set_non_blocking(client_fd);

        printf("Connection accepted from %s:%d\n",
               inet_ntoa(((struct sockaddr_in *)&client_address)->sin_addr),
               ntohs(((struct sockaddr_in *)&client_address)->sin_port));

        handle_request(client_fd);
        close(client_fd);
    }

    close(server_fd);
    return 0;
}

void handle_request(int client_fd)
{
    char buffer[BUFFER_SIZE] = {0};
    char *request_type, *path, *http_version;
    long valread;

    if ((valread = read(client_fd, buffer, BUFFER_SIZE)) < 0)
    {
        exit_with_error("Failed to read request.");
    }

    buffer[valread] = '\0';

    request_type = strtok(buffer, " \t\r\n");
    path = strtok(NULL, " \t\r\n");
    http_version = strtok(NULL, " \t\r\n");

    if (!path || !http_version || strcasecmp(http_version, "HTTP/1.0") != 0 && strcasecmp(http_version, "HTTP/1.1") != 0)
    {
        send_error(client_fd, 400, "Bad Request");
        return;
    }

    while ((valread = read(client_fd, buffer, BUFFER_SIZE)) > 0);

    if (strcasecmp(request_type, "GET") == 0)
    {
        if (strcmp(path, "/") == 0)
        {
            path = "/index.html";
        }
        char file_path[100] = {0};
        strcat(file_path, WEB_ROOT);
        strcat(file_path, path);
        serve_file(client_fd, file_path);
    }
    else
    {
        send_error(client_fd, 501, "Not Implemented");
    }
}

void serve_file(int client_fd, char *file_path)
{
    int fd, bytes_read;
    char buffer[BUFFER_SIZE] = {0};
    struct stat file_stat;

    if ((fd = open(file_path, O_RDONLY)) < 0)
    {
        send_error(client_fd, 404, "Not Found");
        return;
    }

    if (fstat(fd, &file_stat) < 0)
    {
        send_error(client_fd, 500, "Internal Server Error");
        return;
    }

    sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %ld\r\n\r\n", file_stat.st_size);
    send(client_fd, buffer, strlen(buffer), 0);

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        send(client_fd, buffer, bytes_read, 0);
    }

    close(fd);
}

void send_error(int client_fd, int error_code, char *msg)
{
    char buffer[BUFFER_SIZE] = {0};
    sprintf(buffer, "HTTP/1.1 %d %s\r\nContent-Length: 0\r\n\r\n", error_code, msg);
    send(client_fd, buffer, strlen(buffer), 0);
}

void exit_with_error(const char *msg)
{
    perror(msg);
    exit(1);
}

void set_non_blocking(int fd)
{
    int flags;

    flags = fcntl(fd, F_GETFL, 0);
    if (flags < 0)
    {
        exit_with_error("Failed to get socket flags.");
    }

    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) < 0)
    {
        exit_with_error("Failed to set socket to non-blocking.");
    }
}