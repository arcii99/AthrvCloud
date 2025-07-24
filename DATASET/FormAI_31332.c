//FormAI DATASET v1.0 Category: Chat server ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

void myFunction(char *str) {
    printf("I am a function that does something crazy with %s!\n", str);
}

int main() {
    int sockfd, newsockfd, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    printf("Welcome to the Surrealist Chat Server!\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("ERROR on binding\n");
        exit(1);
    }

    listen(sockfd, 5);

    printf("The server is listening on port %d...\n", PORT);

    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0) {
            printf("ERROR on accept\n");
            exit(1);
        }

        bzero(buffer, 256);

        n = read(newsockfd, buffer, 255);
        if (n < 0) {
            printf("ERROR reading from socket\n");
            exit(1);
        }

        printf("Client: %s\n", buffer);

        myFunction(buffer);

        n = write(newsockfd, "I heard you loud and clear!", 27);

        if (n < 0) {
            printf("ERROR writing to socket\n");
            exit(1);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}