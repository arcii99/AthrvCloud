//FormAI DATASET v1.0 Category: Simple Web Server ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    /* Creating socket file descriptor */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    /* Assign IP address and port */
    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    /* Binding socket with the server address */
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to bind socket with the server address");
        exit(EXIT_FAILURE);
    }

    /* Listening for incoming connections */
    if (listen(sockfd, 5) < 0) {
        perror("Failed to listen");
        exit(EXIT_FAILURE);
    }

    /* Accepting incoming connections */
    int connfd;
    struct sockaddr_in client_addr;
    int addrlen = sizeof(client_addr);
    char buffer[BUFFER_SIZE] = { 0 };
    while (1) {
        if ((connfd = accept(sockfd, (struct sockaddr *) &client_addr, &addrlen)) < 0) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        /* Reading data from client */
        int num_bytes = read(connfd, buffer, BUFFER_SIZE);
        if (num_bytes < 0) {
            perror("Failed to read data from client");
            exit(EXIT_FAILURE);
        }

        /* Sending response back to client */
        const char *message = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
        write(connfd, message, strlen(message));

        /* Closing connection */
        close(connfd);
    }

    return 0;
}