//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void proxy(int client_fd)
{
    // Declare variables
    int server_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int recv_size;

    // Create socket for server connection
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return;
    }

    // Set server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Set server IP address
    server_addr.sin_port = htons(80); // Set server port (HTTP port)

    // Connect to server
    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return;
    }

    // Receive client's request and send it to server
    memset(buffer, 0, BUFFER_SIZE);
    recv_size = recv(client_fd, buffer, BUFFER_SIZE, 0);
    if(recv_size == -1){
        perror("recv");
        return;
    }
    if (send(server_fd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return;
    }

    // Receive server's response and send it to client
    memset(buffer, 0, BUFFER_SIZE);
    while ((recv_size = recv(server_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        if (send(client_fd, buffer, recv_size, 0) == -1) {
            perror("send");
            return;
        }
        memset(buffer, 0, BUFFER_SIZE);
    }
    if(recv_size == -1){
        perror("recv");
        return;
    }
}

int main(int argc, char *argv[])
{
    // Declare variables
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create socket for server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    // Set server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Set server IP address
    server_addr.sin_port = htons(8888); // Set server port (can be any unused port)

    // Bind server address to socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Start listening for incoming connections
    if (listen(server_fd, 5) == -1) {
        perror("listen");
        return 1;
    }

    // Loop to handle incoming connections
    while(1) {
        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) == -1) {
            perror("accept");
            continue; // Go back to listening for incoming connections
        }

        // Fork a new process to handle the connection
        if (fork() == 0) {
            close(server_fd); // Child process doesn't need the server socket
            proxy(client_fd); // Handle the connection
            close(client_fd); // Close the client socket
            exit(0); // Exit the child process
        } else {
            close(client_fd); // Parent process doesn't need the client socket
        }
    }

    return 0;
}