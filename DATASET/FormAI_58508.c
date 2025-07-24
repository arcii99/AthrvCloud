//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_NUM 5000
#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    int sockfd, connfd, read_size, write_size;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT_NUM);

    // bind socket to server address
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket to server address");
        exit(EXIT_FAILURE);
    }

    // listen for connections
    if (listen(sockfd, 5) == -1) {
        perror("Error while listening for connections");
        exit(EXIT_FAILURE);
    }

    // accept incoming connections
    if ((connfd = accept(sockfd, (struct sockaddr*)NULL, NULL)) == -1) {
        perror("Error while accepting incoming connection");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // read data from client
        read_size = recv(connfd, &buffer, BUFFER_SIZE, 0);
        if (read_size == -1) {
            perror("Error while reading data from client");
            exit(EXIT_FAILURE);
        } else if (read_size == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Client says: %s\n", buffer);

        // write data back to client
        write_size = send(connfd, &buffer, read_size, 0);
        if (write_size == -1) {
            perror("Error while writing data to client");
            exit(EXIT_FAILURE);
        }
    }

    // close connection and socket
    close(connfd);
    close(sockfd);

    return 0;
}