//FormAI DATASET v1.0 Category: Simple Web Server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(char *message);

char *get_extension(char *filename);
void send_file(FILE *file, int client_socket, char *extension);

void handle_request(int client_socket);

int main(int argc, char const *argv[]) {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("Socket creation failed.");
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        error("Setsockopt failed.");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error("Bind failed.");
    }

    if (listen(server_fd, 3) < 0) {
        error("Listen failed.");
    }

    printf("Server is listening on port %d.\n", PORT);

    while (1) {
        int client_socket;
        struct sockaddr_in client_address;

        if ((client_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&addrlen)) < 0) {
            error("Accept failed.");
        }

        handle_request(client_socket);

        close(client_socket);
    }

    return 0;
}

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    read(client_socket, buffer, BUFFER_SIZE);

    printf("Request: %s\n", buffer);

    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");

    if (method == NULL || path == NULL) {
        error("Invalid request.");
    }

    if (strcmp(method, "GET") != 0) {
        error("Invalid method.");
    }

    char *filename = malloc(strlen(path) + 2);
    sprintf(filename, ".%s", path);
    if (filename[strlen(filename) - 1] == '/') {
        strcat(filename, "index.html");
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        error("File not found.");
    }

    char *extension = get_extension(filename);

    send_file(file, client_socket, extension);

    fclose(file);
    free(filename);
}

void send_file(FILE *file, int client_socket, char *extension) {
    char buffer[BUFFER_SIZE] = {0};
    long filesize;

    fseek(file, 0, SEEK_END);
    filesize = ftell(file);
    rewind(file);

    sprintf(buffer, "HTTP/1.1 200 OK\nContent-Type: %s\nContent-Length: %ld\n\n", extension, filesize);
    write(client_socket, buffer, strlen(buffer));

    while (fgets(buffer, BUFFER_SIZE, file)) {
        write(client_socket, buffer, strlen(buffer));
    }
}

char *get_extension(char *filename) {
    char *dot = strrchr(filename, '.');
    if (dot == NULL) {
        return strdup("");
    }
    return strdup(dot + 1);
}

void error(char *message) {
    char buffer[BUFFER_SIZE] = {0};
    sprintf(buffer, "HTTP/1.1 500 Internal Server Error\nContent-Type: text/plain\nContent-Length: %ld\n\n%s", strlen(message), message);
    write(STDERR_FILENO, buffer, strlen(buffer));
    exit(EXIT_FAILURE);
}