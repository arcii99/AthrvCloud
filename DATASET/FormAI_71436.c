//FormAI DATASET v1.0 Category: Simple Web Server ; Style: systematic
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>

#define PORT_NUM 8080
#define BUF_SIZE 1024

void handle_error(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    char response[] = "HTTP/1.1 200 OK\r\n\r\n<html><head><title>C Web Server</title></head><body><h1>Welcome to the C Web Server</h1></body></html>\r\n";
    int sockfd, connfd, len;
    struct sockaddr_in serv_addr, client_addr;
    char buffer[BUF_SIZE + 1];
    int optval = 1;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        handle_error("Socket creation failed");
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &optval, sizeof(optval)) == -1) {
        handle_error("setsockopt");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    // Filling server information
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT_NUM);

    // Binding the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        handle_error("Bind failed");
    }

    // Listening for client requests
    if (listen(sockfd, 5) == -1) {
        handle_error("Listen failed");
    }

    printf("Server listening on port %d...\n", PORT_NUM);

    while (1) {
        len = sizeof(client_addr);

        // Accepting client connection
        if ((connfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&len)) == -1) {
            handle_error("Accept failed");
        }

        memset(buffer, 0, BUF_SIZE);

        // Reading client request
        if (read(connfd, buffer, BUF_SIZE) == -1) {
            handle_error("Read failed");
        }

        printf("Request received:\n%s\n", buffer);

        // Sending response to client
        if (write(connfd, response, sizeof(response) - 1) == -1) {
            handle_error("Write failed");
        }

        printf("Response sent.\n");

        close(connfd);
    }

    close(sockfd);

    return 0;
}