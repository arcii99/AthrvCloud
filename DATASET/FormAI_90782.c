//FormAI DATASET v1.0 Category: Simple Web Server ; Style: configurable
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 8000
#define MAX_PENDING 5
#define BUFFER_SIZE 1024
#define ROOT_DIR "www"

int main() {
    int sockfd, connfd;
    struct sockaddr_in server, client;
    char buffer[BUFFER_SIZE];
    char status_line[128] = "HTTP/1.1 200 OK\r\n";
    char content_type_header[128] = "Content-Type: text/html\r\n";
    char *http_response_header;
    ssize_t bytes_read;
    int filefd;
    struct stat file_stat;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Set the server address struct
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (struct sockaddr*) &server, sizeof(server)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_PENDING) < 0) {
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }

    // Server loop
    while (1) {
        // Accept connection
        socklen_t client_len = sizeof(client);
        connfd = accept(sockfd, (struct sockaddr*) &client, &client_len);
        if (connfd < 0) {
            perror("accept() failed");
            continue;
        }

        // Read client request
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = read(connfd, buffer, BUFFER_SIZE-1);
        if (bytes_read < 0) {
            perror("read() from client failed");
            close(connfd);
            continue;
        }

        // Parse the HTTP request to get the filename
        char filename[128];
        sscanf(buffer, "GET /%s HTTP/1.1\r\n", filename);

        // Open the file
        char filepath[128];
        memset(filepath, 0, sizeof(filepath));
        strcpy(filepath, ROOT_DIR);
        strcat(filepath, "/");
        strcat(filepath, filename);
        filefd = open(filepath, O_RDONLY);
        if (filefd < 0) {
            // File not found
            sprintf(status_line, "HTTP/1.1 404 Not Found\r\n");
            http_response_header = strcat(status_line, content_type_header);
            write(connfd, http_response_header, strlen(http_response_header));
        } else {
            // File found, read and send contents
            fstat(filefd, &file_stat);
            sprintf(content_type_header, "Content-Type: %s\r\n", "text/html");
            sprintf(status_line, "HTTP/1.1 200 OK\r\nContent-Length: %zd\r\n", file_stat.st_size);
            http_response_header = strcat(status_line, content_type_header);
            write(connfd, http_response_header, strlen(http_response_header));
            while ((bytes_read = read(filefd, buffer, BUFFER_SIZE)) > 0) {
                write(connfd, buffer, bytes_read);
            }
            close(filefd);
        }

        close(connfd);
    }

    return 0;
}