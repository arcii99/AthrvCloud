//FormAI DATASET v1.0 Category: Simple Web Server ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 256
#define RESPONSE_SIZE 1024

char* get_response(char* request) {
    char* response = (char*) malloc(RESPONSE_SIZE * sizeof(char));
    memset(response, 0, RESPONSE_SIZE);

    if(strncmp(request, "GET / HTTP/1.1", 14) == 0) {
        sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Welcome to the Simple Web Server!</h1></body></html>");
    }
    else if(strncmp(request, "GET /about HTTP/1.1", 19) == 0) {
        sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>About page</h1><p>This is a simple web server created in C!</p></body></html>");
    }
    else {
        sprintf(response, "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n<html><body><h1>404 Not Found</h1><p>The page you requested cannot be found!</p></body></html>");
    }

    return response;
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char* response = NULL;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening for connections on port %d...\n", PORT);

    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        read(new_socket, buffer, BUFFER_SIZE);

        printf("Received request:\n%s\n", buffer);

        response = get_response(buffer);

        send(new_socket, response, strlen(response), 0);

        close(new_socket);

        free(response);
    }

    return 0;
}