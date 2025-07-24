//FormAI DATASET v1.0 Category: Socket programming ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int server_fd, client_fd, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    char message[1024];

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(9000);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 9000\n");

    socklen_t client_len = sizeof(client_addr);
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Connection established with client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
    while(1) {
        memset(message, 0, sizeof(message));
        int message_len = read(client_fd, message, 1024);
        
        if (message_len < 0) {
            perror("read failed");
            break;
        }
        if (message_len == 0) {
            printf("Client disconnected\n");
            break;
        } 
        printf("Received message from client: %s\n", message);
        strcat(message, " from server");
        if (write(client_fd, message, strlen(message)) < 0) {
            perror("write failed");
            break;
        }
    }

    close(client_fd);
    close(server_fd);

    return 0;
}