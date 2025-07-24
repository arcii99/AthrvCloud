//FormAI DATASET v1.0 Category: Networking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 5050
#define MAX_BUFFER_SIZE 1024

void error_message(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void *connection_handler(void *sock_ptr) {
    int sock = *(int*)sock_ptr;
    struct sockaddr_in client_addr;
    char buffer[MAX_BUFFER_SIZE];
    memset(&client_addr, 0, sizeof(client_addr));
    memset(buffer, 0, MAX_BUFFER_SIZE);
    socklen_t client_addr_len = sizeof(client_addr);
    if (getpeername(sock, (struct sockaddr*)&client_addr, &client_addr_len) == -1)
        error_message("getpeername() error");
    printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    while (1) {
        ssize_t recv_size = recv(sock, buffer, MAX_BUFFER_SIZE, 0);
        if (recv_size == -1)
            error_message("recv() error");
        else if (recv_size == 0)
            break;
        write(sock, buffer, strlen(buffer));
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }
    close(sock);
    printf("Connection closed from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    pthread_exit(NULL);
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));
    pthread_t tid;
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        error_message("socket() error");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
        error_message("bind() error");
    if (listen(server_sock, 5) == -1)
        error_message("listen() error");
    printf("Server listening on port %d\n", PORT);
    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);
        if ((client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_len)) == -1)
            error_message("accept() error");
        pthread_create(&tid, NULL, connection_handler, (void*)&client_sock);
        pthread_detach(tid); // detach the thread and do not join to avoid memory leak
    }
    close(server_sock);
    return EXIT_SUCCESS;
}