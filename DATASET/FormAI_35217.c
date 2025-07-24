//FormAI DATASET v1.0 Category: Client Server Application ; Style: multivariable
/* This is a multivariable style C Client-Server application example program.
 * It is a basic file transfer program where the client sends a file to the server.
 * The program uses TCP sockets to establish a connection between the client and server.
 * The server will listen and accept connections from clients.
 * The client sends a file to the server and the server saves the file in the server's file system.
 * The server sends a response to the client with the status of the file transfer.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 256
#define PORT 8080

int main(int argc, char *argv[]) {
    int sock_fd, client_fd, read_size;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE] = {0};
    char filename[BUF_SIZE] = {0};
    int opt = 1;
    socklen_t addrlen = sizeof(server_addr);
    FILE *fp;

    // Create a socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept incoming connections
        if ((client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Clear buffer and filename
        memset(buffer, 0, sizeof(buffer));
        memset(filename, 0, sizeof(filename));

        // Receive filename
        if ((read_size = recv(client_fd, filename, BUF_SIZE, 0)) < 0) {
            perror("recv filename failed");
            exit(EXIT_FAILURE);
        }

        // Open file to write
        fp = fopen(filename, "wb");
        if (fp == NULL) {
            perror("file open failed");
            exit(EXIT_FAILURE);
        }

        // Receive file contents and write to file
        while ((read_size = recv(client_fd, buffer, BUF_SIZE, 0)) > 0) {
            fwrite(buffer, 1, read_size, fp);
            memset(buffer, 0, sizeof(buffer));
        }

        // Close file
        fclose(fp);

        // Send response to client
        if (read_size == 0) {
            send(client_fd, "success", strlen("success"), 0);
        } else {
            send(client_fd, "failure", strlen("failure"), 0);
        }

        // Close client socket
        close(client_fd);
    }

    // Close server socket
    close(sock_fd);

    return 0;
}