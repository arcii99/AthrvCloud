//FormAI DATASET v1.0 Category: Networking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Socket successfully created!\n");

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        perror("Socket bind failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Socket successfully binded!\n");

    if ((listen(sockfd, 5)) != 0) {
        perror("Listen failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port 8080...\n");

    int len = sizeof(cli);
    connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
    if (connfd < 0) {
        perror("Server accept failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Server accepted the connection.\n");

    char msg[] = "Hello from server!";
    write(connfd, msg, sizeof(msg));
    printf("Message sent to client.\n");

    close(sockfd);
    return 0;
}