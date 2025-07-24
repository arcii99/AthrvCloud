//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT_NUM 8000
#define BUFFER_SIZE 512

void handle_error(char *msg);

int main() {

    int socket_fd, new_socket_fd;
    socklen_t client_len;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0)
        handle_error("Error opening socket");

    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_NUM);

    if(bind(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        handle_error("Error on binding");

    listen(socket_fd, 5);

    client_len = sizeof(client_addr);

    while(1) {

        new_socket_fd = accept(socket_fd, (struct sockaddr *) &client_addr, &client_len);
        if(new_socket_fd < 0)
            handle_error("Error on accepting connection");

        memset(buffer, 0, BUFFER_SIZE);
        
        int n = read(new_socket_fd, buffer, BUFFER_SIZE);
        if(n < 0)
            handle_error("Error reading from socket");

        printf("Received message from client: %s\n", buffer);

        n = write(new_socket_fd, "Message received", 16);
        if(n < 0)
            handle_error("Error writing to socket");

        close(new_socket_fd);
    }

    close(socket_fd);

    return 0;
}

void handle_error(char *msg) {
    perror(msg);
    exit(1);
}