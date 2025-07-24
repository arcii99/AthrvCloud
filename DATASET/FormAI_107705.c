//FormAI DATASET v1.0 Category: Simple Web Server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <pthread.h>
 
#define PORT 8080
#define BUF_SIZE 8192
 
void *client_thread(void *arg) {
    int client_sock = *(int *)arg;
    int read_size;
    char buffer[BUF_SIZE] = {0};
    char response[BUF_SIZE] = {0};
     
    read_size = recv(client_sock, buffer, BUF_SIZE, 0);
    if (read_size <= 0) {
        perror("recv");
        goto fin;
    }
 
    printf("Received Message: %s\n", buffer);
 
    snprintf(response, BUF_SIZE, "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 90\n\n<html><body><h1>Hello, World!</h1></body></html>\n\n");
 
    if (send(client_sock, response, strlen(response), 0) < 0) {
        perror("send");
        goto fin;
    }
     
fin:
    close(client_sock);
    pthread_exit(NULL);
}
 
int main(int argc, char *argv[]) {
    int server_sock, client_sock, read_size;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[BUF_SIZE] = {0};
    pthread_t tid;
     
    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
 
    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
     
    // Bind
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }
     
    // Listen
    if (listen(server_sock, 10) == -1) {
        perror("listen");
        exit(1);
    }
     
    // Loop
    while (1) {
        client_len = sizeof(struct sockaddr_in);
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len)) == -1) {
            perror("accept");
            continue;
        }
 
        if (pthread_create(&tid, NULL, client_thread, &client_sock) == -1) {
            perror("pthread_create");
            close(client_sock);
            continue;
        }
 
        pthread_detach(tid);
    }
 
    close(server_sock);
    return 0;
}