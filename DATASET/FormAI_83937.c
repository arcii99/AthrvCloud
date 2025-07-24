//FormAI DATASET v1.0 Category: Client Server Application ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
    int sockfd, newsockfd, clilen, n;
    char buffer[256];

    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error on binding\n");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0) {
        printf("Error on accept\n");
        exit(1);
    }

    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);

    if (n < 0) {
        printf("Error reading from socket\n");
        exit(1);
    }

    printf("Message received from client: %s\n", buffer);

    n = write(newsockfd, "Message received by Server", 26);

    if (n < 0) {
        printf("Error writing to socket\n");
        exit(1);
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}