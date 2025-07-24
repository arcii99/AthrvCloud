//FormAI DATASET v1.0 Category: Socket programming ; Style: Linus Torvalds
/* Linux Torvalds style C Socket Programming example */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int sockfd, newsockfd;
    socklen_t cli_len;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    while (1) {
        cli_len = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len);
        if (newsockfd < 0) {
            perror("Failed to accept client connection");
            exit(EXIT_FAILURE);
        }

        pid_t pid = fork();
        if (pid < 0) {
            perror("Failed to create new process");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) {
            /* Child process */
            close(sockfd);
            int bytes_read;
            while ((bytes_read = read(newsockfd, buffer, BUFFER_SIZE)) > 0) {
                printf("Client sent: %s", buffer);
                if (write(newsockfd, buffer, bytes_read) < 0) {
                    perror("Failed to write to socket");
                    exit(EXIT_FAILURE);
                }
            }
            close(newsockfd);
            exit(EXIT_SUCCESS);
        }
        else {
            /* Parent process */
            close(newsockfd);
        }
    }
    return 0;
}