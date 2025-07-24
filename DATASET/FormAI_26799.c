//FormAI DATASET v1.0 Category: Socket programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char **argv) {

    int sockfd;
    struct sockaddr_in server_addr;
    char message[1024];

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // bind socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server has started, listening on port 8080...\n");

    // accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int clientfd;
    if ((clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len)) == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // send greeting message to client
    char *greeting = "Welcome to my server!";
    if (send(clientfd, greeting, strlen(greeting), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // receive message from client
        memset(message, '\0', sizeof(message));
        if (recv(clientfd, message, sizeof(message), 0) == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        printf("Received message from client: %s\n", message);

        // send response message back to client
        char *response = "Got your message!";
        if (send(clientfd, response, strlen(response), 0) == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        }
    }

    // close sockets
    close(clientfd);
    close(sockfd);

    return 0;
}