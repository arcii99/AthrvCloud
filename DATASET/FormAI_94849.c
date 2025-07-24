//FormAI DATASET v1.0 Category: Firewall ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024
#define PORT_NUM 8080

void handle_connection(int fd) {
    char buffer[MAX_BUFFER_SIZE];
    int read_bytes;

    while ((read_bytes = read(fd, buffer, MAX_BUFFER_SIZE)) > 0) {
        buffer[read_bytes] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "hack") != NULL || strstr(buffer, "attack") != NULL) {
            close(fd);
            printf("Blocked an attempt to hack the server!\n");
            return;
        }
        write(fd, buffer, strlen(buffer));
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }

    if (read_bytes == 0) {
        printf("Connection closed by client.\n");
    } else {
        printf("Error: %s\n", strerror(errno));
    }

    close(fd);
}

int main() {
    int fd, new_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_NUM);

    // Bind to the port
    if (bind(fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding to port");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(fd, 1) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Firewall online. Listening on port %d.\n", PORT_NUM);

    while (1) {
        client_addr_len = sizeof(client_addr);
        new_fd = accept(fd, (struct sockaddr*)&client_addr, &client_addr_len);

        if (new_fd < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
        printf("Incoming connection from %s:%d.\n", client_ip, ntohs(client_addr.sin_port));

        if (strcmp(client_ip, "127.0.0.1") == 0) {
            close(new_fd);
            printf("Blocked loopback connection from %s.\n", client_ip);
            continue;
        }

        handle_connection(new_fd);
    }

    close(fd);
    return 0;
}