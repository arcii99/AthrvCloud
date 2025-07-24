//FormAI DATASET v1.0 Category: Simple Web Server ; Style: realistic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10    // how many pending connections queue will hold

int main(int argc, char *argv[]) {

    int server_fd; // server file descriptor
    int new_socket; // new socket accepted from client
    struct sockaddr_in address; // server address
    int addrlen = sizeof(address);

    // create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, BACKLOG) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // accept and handle connections
    while (1) {
        printf("waiting for connections...\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                                 (socklen_t*)&addrlen))<0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("connection accepted from %s:%d\n", 
               inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        char buffer[1024] = {0};
        FILE *file;
        int bytes_read;

        // read HTTP request
        read(new_socket, buffer, 1024);
        printf("%s\n", buffer);

        // check if request is for root
        if (strncmp(buffer, "GET / HTTP/1.1", 14) == 0) {
            file = fopen("index.html", "r");
        } else {
            file = fopen("404.html", "r");
        }

        // send HTTP response
        char response[1024];
        memset(response, 0, sizeof(response));
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");

        send(new_socket, response, strlen(response), 0);

        while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
            send(new_socket, buffer, bytes_read, 0);
        }

        fclose(file);
        printf("response sent.\n");
        close(new_socket);
    }

    return 0;
}