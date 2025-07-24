//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 55555
#define MAX_CONNECTIONS 10

int main(int argc, char *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char *message = "Wireless network scanner activated!\n";
    char buffer[1024] = {0};
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Attaching socket to the port
    if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("%s", message);
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
            (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        pid_t pid = fork(); // Creating a new process for each client connected
        if (pid == 0) {
            close(server_fd);
            while ((valread = read(new_socket , buffer, 1024)) > 0) {
                printf("Message from client: %s\n", buffer);
                memset(buffer, 0, 1024);
            }
        } else if (pid < 0) {
            perror("Error creating child process");
            exit(EXIT_FAILURE);
        } else {
            close(new_socket);
            printf("New client connected!\n");
        }
    }
    return 0;
}