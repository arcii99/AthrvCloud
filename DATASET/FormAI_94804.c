//FormAI DATASET v1.0 Category: Chat server ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int server_fd, client_fds[MAX_CLIENTS];
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {'\0'};
    int opt = 1, addrlen = sizeof(server_address);

    // create server socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set server socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // assign server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // bind server socket
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    int num_clients = 0;

    while (1) {
        // accept incoming connection
        int new_socket;
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // add new client socket descriptor to array
        client_fds[num_clients++] = new_socket;

        // send welcome message to client
        char message[] = "Welcome to the chat server!\n";
        send(new_socket, message, strlen(message), 0);

        // fork a child process to handle client messages
        if (fork() == 0) {
            while (1) {
                // receive message from client
                int num_bytes_recv = recv(new_socket, buffer, BUFFER_SIZE, 0);
                if (num_bytes_recv <= 0) {
                    break;
                }

                // send message to every connected client (except sender)
                for (int i = 0; i < num_clients; i++) {
                    if (client_fds[i] == new_socket) {
                        continue;   // skip the sender
                    }

                    send(client_fds[i], buffer, num_bytes_recv, 0);
                }
            }

            // remove client socket descriptor from array
            for (int i = 0; i < num_clients; i++) {
                if (client_fds[i] == new_socket) {
                    while (i < num_clients-1) {
                        client_fds[i] = client_fds[i+1];
                        i++;
                    }

                    num_clients--;
                    break;
                }
            }

            close(new_socket);
            exit(0);
        }

        close(new_socket);
    }

    return 0;
}