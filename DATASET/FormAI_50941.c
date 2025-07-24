//FormAI DATASET v1.0 Category: Chat server ; Style: automated
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 5555

int main(int argc, char *argv[])
{
    int sockfd, newsockfd;
    socklen_t clilen;

    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    char buffer[256];
    int bytesRead;

    printf("Waiting for client connection\n");

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    printf("Connected to client\n");

    while(1) {
        memset(buffer, 0, sizeof(buffer));
        bytesRead = read(newsockfd, buffer, sizeof(buffer) - 1);

        if (bytesRead == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Client: %s", buffer);

        if (strncmp(buffer, "bye", 3) == 0) {
            printf("Exiting\n");
            break;
        }

        printf("Enter reply: ");
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer) - 1, stdin);
        write(newsockfd, buffer, strlen(buffer));
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}