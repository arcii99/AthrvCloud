//FormAI DATASET v1.0 Category: Client Server Application ; Style: genious
// A Unique Client Server Application Example Program

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 4000

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);

    printf("Server is up and running\n");
    printf("Waiting for connection...\n");

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) NULL, NULL);
        if (newsockfd < 0)
            error("ERROR on accept");

        printf("Connection established\n");

        pid_t pid = fork();

        if (pid < 0)
            error("ERROR on fork");

        if (pid == 0) {

            close(sockfd);

            while (1) {
                bzero(buffer, sizeof(buffer));
                n = read(newsockfd, buffer, sizeof(buffer));
                if (n < 0)
                    error("ERROR on read");

                if (strncmp(buffer, "exit", 4) == 0)
                    break;
                
                printf("Client: %s\n", buffer);

                bzero(buffer, sizeof(buffer));
                fgets(buffer, sizeof(buffer), stdin);
                n = write(newsockfd, buffer, sizeof(buffer));
                if (n < 0)
                    error("ERROR on write");
            }

            printf("Connection closed\n");
            close(newsockfd);
            exit(0);
        }
        else {
            close(newsockfd);
        }
    }

    close(sockfd);
    return 0;
}