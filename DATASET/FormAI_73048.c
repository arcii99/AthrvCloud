//FormAI DATASET v1.0 Category: Simple Web Server ; Style: introspective
// I am a simple web server written in C. 
// I will listen on a specific port and serve files from a specific directory.
// Whenever a GET request is received, I will read the requested file and send it back in the response body.
// If the requested file is not found, I will send a 404 error.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BACKLOG 10
#define BUFSIZE 1024

int main() {

    // I will create a socket and bind it to a specific address and port.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval , sizeof(int));

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // I will listen for incoming connections
    if (listen(sockfd, BACKLOG) < 0) {
        perror("Error listening on socket");
        exit(1);
    }

    printf("Server started listening on port %d...\n", PORT);

    while (1) {
        // I will accept incoming connections
        int client_sockfd = accept(sockfd, NULL, NULL);
        if (client_sockfd < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        // I will handle incoming requests
        char buf[BUFSIZE];
        ssize_t nread = read(client_sockfd, buf, BUFSIZE - 1);
        if (nread < 0) {
            perror("Error reading from socket");
            exit(1);
        }

        // I will parse the incoming request to extract the file path
        char method[10], path[100], protocol[10];
        sscanf(buf, "%s %s %s", method, path, protocol);

        printf("Client requested %s\n", path);

        // I will build the response based on the requested file
        char filepath[110];
        sprintf(filepath, "./files%s", path);

        struct stat st;
        if (stat(filepath, &st) < 0) {
            // The file does not exist, send a 404 error
            char response[BUFSIZE];
            sprintf(response, "HTTP/1.1 404 Not Found\nContent-Length: 13\n\n404 Not Found\n");
            write(client_sockfd, response, strlen(response));
        } else {
            // The file exists, send the response body
            int filefd = open(filepath, O_RDONLY);
            if (filefd < 0) {
                perror("Error opening file");
                exit(1);
            }

            char response[BUFSIZE];
            sprintf(response, "HTTP/1.1 200 OK\nContent-Length: %d\n\n", (int)st.st_size);
            write(client_sockfd, response, strlen(response));

            char filebuf[BUFSIZE];
            ssize_t nread;
            while ((nread = read(filefd, filebuf, BUFSIZE)) > 0) {
                write(client_sockfd, filebuf, nread);
            }
            close(filefd);
        }

        close(client_sockfd);
    }

    return 0;
}