//FormAI DATASET v1.0 Category: Client Server Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char** argv) {
    int connfd, sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8000);

    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    if ((listen(sockfd, 5)) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((connfd = accept(sockfd, (struct sockaddr*)NULL, NULL)) < 0) {
            perror("Accept error");
            exit(EXIT_FAILURE);
        }

        pid_t childpid;

        if ((childpid = fork()) == 0) {
            close(sockfd);

            while(1){
                memset(buffer, 0, MAXLINE);

                if (read(connfd, buffer, MAXLINE) == 0) {
                    printf("The client has closed the connection.");
                    break;
                }

                printf("Received message from the client : %s", buffer);
                write(connfd, buffer, strlen(buffer));
            }

            exit(0);
        }
        close(connfd);
    }

    return 0;
}