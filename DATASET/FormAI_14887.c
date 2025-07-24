//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: distributed
/*
    Distributes a text file among multiple clients using TCP/IP sockets
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXQUEUE 5
#define MAXSIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting options and binding socket to port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
      
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening to incoming connections
    if (listen(server_fd, MAXQUEUE) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accepting and serving multiple clients
    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Sending file to client
        FILE* fp;
        char buffer[MAXSIZE];
        fp = fopen("example.txt", "r");
        if (fp == NULL) {
            perror("File read error");
            exit(EXIT_FAILURE);
        }
        int bytes_read = fread(buffer, sizeof(char), MAXSIZE, fp);
        send(new_socket, buffer, bytes_read, 0);
        fclose(fp);

        // Closing connection
        close(new_socket);
    }

    return 0;
}