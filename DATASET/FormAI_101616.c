//FormAI DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_request(int sock) {
    char buffer[BUFFER_SIZE];
    int valread = read(sock, buffer, BUFFER_SIZE);
    buffer[valread] = '\0';

    // extract the requested file name
    char filename[100];
    sscanf(buffer, "GET /%s", filename);

    // check for security issues
    if (strstr(filename, "..") != NULL) {
        char* response = "HTTP/1.1 403 Forbidden\n\n";
        write(sock, response, strlen(response));
        return;
    }
    if (strlen(filename) < 1) {
        char* response = "HTTP/1.1 404 Not Found\n\n";
        write(sock, response, strlen(response));
        return;
    }

    // open requested file
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        char* response = "HTTP/1.1 404 Not Found\n\n";
        write(sock, response, strlen(response));
        return;
    }

    // construct HTTP response header
    char response[BUFFER_SIZE];
    sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\n\n", strlen(filename));

    // send response header
    write(sock, response, strlen(response));

    // send requested file
    while (!feof(file)) {
        int bytesRead = fread(buffer, 1, BUFFER_SIZE, file);
        write(sock, buffer, bytesRead);
    }

    fclose(file);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // setup address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind socket to address
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d\n", PORT);

    // loop to accept incoming connections
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // handle request
        handle_request(new_socket);

        // close socket
        close(new_socket);
    }

    return 0;
}