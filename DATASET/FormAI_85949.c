//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define PROXY_PORT 8000
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_sock, c_sock, proxy_sock;
    struct sockaddr_in server_addr, client_addr, proxy_addr;
    char buffer[BUFFER_SIZE];

    // create server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    // prepare server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    // bind server socket to server address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket");
        exit(1);
    }

    // listen for incoming connections
    if (listen(server_sock, 5) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    // create proxy socket
    proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sock < 0) {
        perror("Error creating proxy socket");
        exit(1);
    }

    // prepare proxy address struct
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PROXY_PORT);

    // bind proxy socket to proxy address
    if (bind(proxy_sock, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Error binding proxy socket");
        exit(1);
    }

    // listen for incoming connections
    if (listen(proxy_sock, 5) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    printf("Proxy server running on port %d...\n", PROXY_PORT);

    while(1) {
        // accept incoming client connection
        int client_size = sizeof(client_addr);
        c_sock = accept(proxy_sock, (struct sockaddr*)&client_addr, (socklen_t*)&client_size);
        if (c_sock < 0) {
            perror("Error accepting client connection");
            exit(1);
        }

        printf("New client connection accepted.\n");

        int pid = fork(); //start new fork process for each new connection
        if (pid < 0) {
            perror("Error creating child process for new connection");
            exit(1);
        }
        if (pid == 0) {
            // client process
            close(proxy_sock);
            printf("Handling client connection...\n");

            // create server socket
            server_sock = socket(AF_INET, SOCK_STREAM, 0);
            if (server_sock < 0) {
                perror("Error creating server socket");
                exit(1);
            }

            // connect to server
            if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                perror("Error connecting to server");
                exit(1);
            }

            while (1) {
                memset(buffer, 0, sizeof(buffer));
                int read_size = recv(c_sock, buffer, BUFFER_SIZE, 0);
                if (read_size <= 0) {
                    printf("Client closed connection.\n");
                    break;
                }

                // forward HTTP request to server
                send(server_sock, buffer, read_size, 0);

                memset(buffer, 0, sizeof(buffer));
                int recv_size = recv(server_sock, buffer, BUFFER_SIZE, 0);
                if (recv_size <= 0) {
                    printf("Server closed connection.\n");  
                    break;
                }

                // forward HTTP response to client
                send(c_sock, buffer, recv_size, 0);
            }

            close(c_sock);
            exit(0);
        } else {
            // parent process
            close(c_sock);
        }
    }

    close(proxy_sock);
    return 0;
}