//FormAI DATASET v1.0 Category: Networking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 7777
#define MAX_MSG_SIZE 1024

int main() {

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failure");
        exit(EXIT_FAILURE);
    }

    // set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failure");
        exit(EXIT_FAILURE);
    }

    // bind socket to port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failure");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("listen failure");
        exit(EXIT_FAILURE);
    }

    // accept incoming connections
    int addrlen = sizeof(address);
    int new_socket = accept(sockfd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (new_socket < 0) {
        perror("accept failure");
        exit(EXIT_FAILURE);
    }

    // read and write to client
    char buffer[MAX_MSG_SIZE] = {0};
    while (true) {
        int valread = read(new_socket, buffer, MAX_MSG_SIZE);
        if (valread > 0) {
            printf("client: %s\n", buffer);
            memset(buffer, 0, MAX_MSG_SIZE);
        } else {
            break;
        }

        fgets(buffer, MAX_MSG_SIZE, stdin);
        send(new_socket, buffer, strlen(buffer), 0);
        memset(buffer, 0, MAX_MSG_SIZE);
    }

    // close sockets
    close(new_socket);
    close(sockfd);

    return 0;
}