//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd;
    int new_socket;
    int opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from server";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
            &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
 
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
     
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
         
        pid_t pid;
        pid = fork();
        if (pid<0) exit(EXIT_FAILURE);

        if (pid==0) {
            close(server_fd);

            while(1) {
                int msg_size = read(new_socket, buffer, BUFFER_SIZE);
                if (msg_size==0) break;
                if (msg_size<0) perror("read");

                printf("Client says: %s\n", buffer);
                send(new_socket, hello, strlen(hello), 0);

                memset(buffer, 0, BUFFER_SIZE);
            }

            exit(EXIT_SUCCESS);
        }
        else {
            close(new_socket);
        }
    }

    return 0;
}