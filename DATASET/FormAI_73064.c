//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CONN 3

int main(int argc, char** argv) {
    int server_fd, client_fd, valread;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    int opt = 1, addrlen = sizeof(server_addr);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        perror("Socket initialization failed.");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Set Socket Options failed.");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed.");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CONN) < 0) {
        perror("Listening failed.");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Listening for incoming connections...\n");
        if ((client_fd = accept(server_fd, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen)) < 0) {
            perror("Accepting connection failed.");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted...\n");

        if (fork() == 0) {
            close(server_fd);
            while ((valread = read(client_fd, buffer, 1024)) > 0) {
                printf("%s\n", buffer);
                send(client_fd, buffer, strlen(buffer), 0);
                bzero(buffer, 1024);
            }
            close(client_fd);
            exit(0);
        }
        close(client_fd);
    }
    return 0;
}