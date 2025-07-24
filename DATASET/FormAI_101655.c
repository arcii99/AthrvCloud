//FormAI DATASET v1.0 Category: Simple Web Server ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 8080
#define BUFSIZE 1024

int main() {
    int server_fd, new_socket, valread, file_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFSIZE] = {0};
    char *response = NULL;
    char *http_header = "HTTP/1.1 200 OK\r\n\n";
    char *file_path = "./index.html";

    // Create a socket and bind it to a port
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Read HTTP request from client
        valread = read(new_socket, buffer, BUFSIZE);
        if (valread < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }

        // Check if request is for index.html
        if (strstr(buffer, "GET / HTTP/1.1")) {
            file_path = "./index.html";
        } else if (strstr(buffer, "GET /about HTTP/1.1")) {
            file_path = "./about.html";
        } else if (strstr(buffer, "GET /contact HTTP/1.1")) {
            file_path = "./contact.html";
        } else {
            file_path = "./404.html";
        }

        // Open and read requested file
        if ((file_fd = open(file_path, O_RDONLY)) < 0) {
            perror("open failed");
            exit(EXIT_FAILURE);
        }
        response = (char *) malloc(strlen(http_header) + BUFSIZE);
        strcpy(response, http_header);
        while ((valread = read(file_fd, buffer, BUFSIZE)) > 0) {
            strcat(response, buffer);
        }
        close(file_fd);

        // Send response to client
        if (send(new_socket, response, strlen(response), 0) < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }
        close(new_socket);
        printf("Response sent for %s\n", file_path);
    }

    return 0;
}