//FormAI DATASET v1.0 Category: Simple Web Server ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CONNECTIONS 10
#define PORT 8080

void send_file(int client_socket, const char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error opening file: %s not found\n", filename);
        exit(1);
    }
    char buffer[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        if (write(client_socket, buffer, bytes_read) == -1) {
            fprintf(stderr, "Error sending file %s\n", filename);
            exit(1);
        }
    }
    close(fd);
}

int main() {
    struct sockaddr_in server_address, client_address;
    int server_socket, client_socket, opt = 1;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(1);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt error");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket to address");
        exit(1);
    }

    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("Failed to listen to socket");
        exit(1);
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        socklen_t client_address_size = sizeof(client_address);
        if ((client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_size)) < 0) {
            perror("Failed to accept incoming connection");
            exit(1);
        }

        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        read(client_socket, buffer, sizeof(buffer));

        char* request = strtok(buffer, " ");
        if (!strcmp(request, "GET")) {
            char* filename = strtok(NULL, " ");
            if (!strcmp(filename, "/")) {
                filename = "/index.html";
            }
            send_file(client_socket, filename);
        } else {
            fprintf(stderr, "Invalid request\n");
            exit(1);
        }

        close(client_socket);
    }

    return 0;
}