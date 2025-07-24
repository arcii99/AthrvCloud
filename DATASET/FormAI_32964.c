//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: distributed
// A distributed Intrusion Detection System example program in C

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include<errno.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/time.h>

#define PORT 8080
#define BACKLOG 5
#define MAXLINE 1024

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAXLINE];
    pid_t childpid;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        error("Socket creation failed");

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if ((bind(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr))) != 0)
        error("Socket binding failed");

    if ((listen(sockfd, BACKLOG)) != 0)
        error("Listen failed");

    while (1) {
        len = sizeof(cliaddr);
        connfd = accept(sockfd, (struct sockaddr*) &cliaddr, &len);
        if (connfd < 0)
            error("Server accept failed");

        if ((childpid = fork()) == 0) {
            close(sockfd);
            unsigned char buffer[MAXLINE];
            ssize_t received = recv(connfd, buffer, MAXLINE, 0);

            if (received < 0)
                error("Recieve failed");

            if (received) {
                for (int i = 0; i< received; i++) {
                    printf("%x ", buffer[i]);
                }
            }
            close(connfd);
            exit(EXIT_SUCCESS);
        }
    close(connfd);
    }
    return 0;
}