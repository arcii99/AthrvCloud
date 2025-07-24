//FormAI DATASET v1.0 Category: Socket programming ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_NUM 3000
#define MAX_QUEUE_LEN 5
#define MAX_LINE_LEN 256

void handle_client(int client_fd, struct sockaddr_in client_addr) {
    char line[MAX_LINE_LEN];
    ssize_t n_read;

    printf("Client connected from %s\n", inet_ntoa(client_addr.sin_addr));

    while ((n_read = read(client_fd, line, MAX_LINE_LEN)) > 0) {
        line[n_read-1] = '\0';

        if (strcmp(line, "exit") == 0) {
            printf("Client closed connection.\n");
            break;
        }

        printf("Received message from client: %s\n", line);

        if (write(client_fd, line, strlen(line) + 1) < 0) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    close(client_fd);
}

int main(void) {
    int server_fd;
    struct sockaddr_in server_addr;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT_NUM);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_QUEUE_LEN) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT_NUM);

    while (1) {
        int client_fd;
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        handle_client(client_fd, client_addr);
    }

    return 0;
}