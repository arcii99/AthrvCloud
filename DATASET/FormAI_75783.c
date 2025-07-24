//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 2048

void proxy(int client_sock)
{
    char buffer[MAX_SIZE];
    int read_size;
    struct sockaddr_in server_addr;
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        fprintf(stderr, "Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("216.58.194.174");

    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, MAX_SIZE);
    while ((read_size = recv(client_sock, buffer, MAX_SIZE, 0)) > 0) {
        if (write(server_sock, buffer, read_size) < 0) {
            fprintf(stderr, "Could not write to server\n");
            exit(EXIT_FAILURE);
        }
        memset(buffer, 0, MAX_SIZE);
    }

    if (read_size < 0) {
        fprintf(stderr, "Could not read from client\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, MAX_SIZE);
    while ((read_size = recv(server_sock, buffer, MAX_SIZE, 0)) > 0) {
        if (write(client_sock, buffer, read_size) < 0) {
            fprintf(stderr, "Could not write to client\n");
            exit(EXIT_FAILURE);
        }
        memset(buffer, 0, MAX_SIZE);
    }

    if (read_size < 0) {
        fprintf(stderr, "Could not read from server\n");
        exit(EXIT_FAILURE);
    }

    close(server_sock);
    close(client_sock);
}

int main(int argc, char const *argv[])
{
    int server_sock, client_sock, c;
    struct sockaddr_in server, client;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        fprintf(stderr, "Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8080 );

    if (bind(server_sock,(struct sockaddr *)&server , sizeof(server)) < 0) {
        fprintf(stderr, "Could not bind to socket\n");
        exit(EXIT_FAILURE);
    }

    listen(server_sock, 3);

    printf("Waiting for connections...\n");

    while (1) {
        c = sizeof(struct sockaddr_in);
        client_sock = accept(server_sock, (struct sockaddr *)&client, (socklen_t*)&c);
        if (client_sock < 0) {
            fprintf(stderr, "Could not accept connection\n");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        pid_t process_id = fork();
        if (process_id == 0) {
            close(server_sock);
            proxy(client_sock);
            exit(EXIT_SUCCESS);
        } else if (process_id > 0) {
            close(client_sock);
        } else {
            fprintf(stderr, "Could not fork a new process\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}