//FormAI DATASET v1.0 Category: Client Server Application ; Style: standalone
// A unique C Client Server Application example program in a standalone style
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr)); // clear serv_addr memory
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");

    printf("Client connected\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer)); // clear buffer memory
        n = read(newsockfd, buffer, sizeof(buffer)); // read from socket

        if (n < 0) // check for errors
            error("ERROR reading from socket");

        if (strcmp(buffer, "exit\n") == 0) // check for exit
            break;

        printf("Client: %s", buffer);

        printf("Server: ");
        memset(buffer, 0, sizeof(buffer)); // clear buffer memory
        fgets(buffer, sizeof(buffer), stdin); // get input from user

        n = write(newsockfd, buffer, sizeof(buffer)); // write to socket

        if (n < 0) // check for errors
            error("ERROR writing to socket");
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}