//FormAI DATASET v1.0 Category: Client Server Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CONNECTIONS 3
#define BUFFER_SIZE 1024

/* Define a function to handle errors */
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    int n, i;

    /* Create a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    /* Set server address structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    /* Bind socket to server address */
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error binding socket");
    }

    /* Listen for connections */
    listen(sockfd, MAX_CONNECTIONS);

    /* Loop to handle connections */
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("Error accepting connection");
        }

        /* Fork a child process to handle the connection */
        int pid = fork();
        if (pid < 0) {
            error("Error forking child process");
        } else if (pid == 0) {
            /* Child process */
            close(sockfd);   /* Close parent socket */

            /* Process client requests */
            while (1) {
                /* Read from client socket */
                bzero(buffer, BUFFER_SIZE);
                n = read(newsockfd, buffer, BUFFER_SIZE);
                if (n < 0) {
                    error("Error reading from socket");
                }
                printf("Received message from client: %s\n", buffer);

                /* Send reply to client */
                n = write(newsockfd, "Message received", 16);
                if (n < 0) {
                    error("Error writing to socket");
                }
            }
            close(newsockfd);   /* Close child socket */
            exit(0);
        } else {
            /* Parent process */
            close(newsockfd);   /* Close child socket */
        }
    }
    close(sockfd);   /* Close parent socket */
    return 0;
}