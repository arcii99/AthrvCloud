//FormAI DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// function to handle signal interrupt
void handle_signal(int signum) {
    printf("\nExiting...\n");
    exit(signum);
}

int main() {
    signal(SIGINT, handle_signal); // register signal handler

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // bind address to socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d...\n", PORT);

    while (1) {
        // accept new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        char* ip_address = inet_ntoa(address.sin_addr);
        printf("New client connected from %s:%d\n", ip_address, ntohs(address.sin_port));

        // fork new process to handle client
        if (fork() == 0) {
            // child process
            close(server_fd);

            // receive messages from client
            while (1) {
                memset(buffer, 0, BUFFER_SIZE);
                if (recv(new_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                    printf("%s:%d disconnected\n", ip_address, ntohs(address.sin_port));
                    break;
                }
                printf("%s:%d > %s", ip_address, ntohs(address.sin_port), buffer);
            }

            close(new_socket);
            exit(EXIT_SUCCESS);
        } else {
            // parent process
            close(new_socket);
        }
    }

    return 0;
}