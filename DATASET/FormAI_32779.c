//FormAI DATASET v1.0 Category: Simple Web Server ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 8080
#define RESPONSE_SIZE 50000

int main(int argc, char const *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    char response[RESPONSE_SIZE] = {0};
    char buffer[1024] = {0};
    char http_ok[] = "HTTP/1.1 200 OK\r\n\n";
    char http_not_found[] = "HTTP/1.1 404 Not Found\r\n\n";
    char page_not_found[] = "<html><body><h1>404 Page Not Found</h1></body></html>";

    // create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // bind the socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    // accept incoming connections
    while ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
        printf("Connection established with %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // read request from client
        read(client_fd, buffer, 1024);

        // extract filename from request
        strtok(buffer, " ");
        char *filename = strtok(NULL, " ");
        printf("Requested file: %s\n", filename);

        char filepath[1024];
        sprintf(filepath, "./www%s", filename);

        // open and read the requested file
        int fd = open(filepath, O_RDONLY);
        if (fd == -1) {
            strcat(response, http_not_found);
            strcat(response, page_not_found);
        } else {
            strcat(response, http_ok);

            int bytes_read;
            while ((bytes_read = read(fd, buffer, 1024)) > 0) {
                strncat(response, buffer, bytes_read);
            }
        }

        // write response to client
        write(client_fd, response, strlen(response));

        // close connection
        close(client_fd);

        // reset response and buffer
        memset(response, 0, RESPONSE_SIZE);
        memset(buffer, 0, 1024);
    }

    return 0;
}