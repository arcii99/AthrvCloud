//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0)
        error("Could not create socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Could not bind socket");

    if (listen(sock_fd, 5) < 0)
        error("Error in listening");

    while (1) {

        struct sockaddr_in client_addr;
        int client_fd, client_len = sizeof(client_addr);

        client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0)
            error("Error in accepting");

        printf("Connection established with %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[BUFFER_SIZE];
        int n = read(client_fd, buffer, sizeof(buffer));
        if (n < 0)
            error("Error in reading");

        buffer[n] = '\0';
        printf("Received message: %s", buffer);

        if (write(client_fd, "ACK", strlen("ACK")) < 0)
            error("Error in writing");

        close(client_fd);

    }

    close(sock_fd);
    return 0;
}