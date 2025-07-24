//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: distributed
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8010

int main() {
    int sock_fd, client_fd;
    struct sockaddr_in serv_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[1024];

    // create server socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Server socket creation error");
        exit(EXIT_FAILURE);
    }

    // set server address and port
    memset(&serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    // bind server socket to address and port
    if (bind(sock_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Server socket binding error");
        exit(EXIT_FAILURE);
    }

    // listen for clients
    if (listen(sock_fd, 5) < 0) {
        perror("Server socket listening error");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // accept incoming client connections
        if ((client_fd = accept(sock_fd, (struct sockaddr*) &client_addr, &client_len)) < 0) {
            perror("Unable to accept client connection");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // fork a new process to handle the client connection
        if (fork() == 0) {
            // close server socket
            close(sock_fd);

            // read data from client
            ssize_t bytes_read;
            while ((bytes_read = read(client_fd, buffer, sizeof(buffer))) > 0) {
                // send data back to client
                write(client_fd, buffer, bytes_read);
            }

            // close client socket
            close(client_fd);

            // exit child process
            exit(0);
        }

        // close client socket in parent process
        close(client_fd);
    }

    return 0;
}