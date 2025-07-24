//FormAI DATASET v1.0 Category: Simple Web Server ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock == -1) {
        perror("Failed to open server socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(8080)
    };

    if(bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind to port 8080");
        return EXIT_FAILURE;
    }

    if(listen(server_sock, 10) == -1) {
        perror("Failed to listen for connections");
        return EXIT_FAILURE;
    }

    char response[] = "HTTP/1.1 200 OK\r\n"
                      "Content-Type: text/html\r\n"
                      "\r\n"
                      "<html><body><h1>Hello World</h1><p>Welcome to our surrealist web server!</p></body></html>";

    printf("Surrealist web server started on port 8080\n");

    while(1) {

        int client_sock = accept(server_sock, NULL, NULL);
        if(client_sock == -1) {
            perror("Failed to accept connection");
            return EXIT_FAILURE;
        }

        char request[BUF_SIZE];

        ssize_t num_recv = recv(client_sock, request, BUF_SIZE, 0);
        if(num_recv == -1) {
            perror("Failed to receive data from client");
            return EXIT_FAILURE;
        }

        char *req_lines[3];
        req_lines[0] = strtok(request, "\r\n");
        for(int i = 1; i < 3; i++) {
            req_lines[i] = strtok(NULL, "\r\n");
        }

        printf("Request received:\n%s\n%s\n%s\n", req_lines[0], req_lines[1], req_lines[2]);

        ssize_t num_sent = send(client_sock, response, sizeof(response), 0);
        if(num_sent == -1) {
            perror("Failed to send response to client");
            return EXIT_FAILURE;
        }

        close(client_sock);
    }

    close(server_sock);
    return EXIT_SUCCESS;
}