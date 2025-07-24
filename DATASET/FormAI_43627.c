//FormAI DATASET v1.0 Category: Chat server ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, n;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5000; // arbitrarily chosen port number
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    listen(sockfd, 5); // listen to incoming connections
    clilen = sizeof(cli_addr);
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        printf("Incoming connection from %s\n", inet_ntoa(cli_addr.sin_addr));
        pid_t pid = fork(); // fork a new process to handle incoming connection
        if (pid < 0) {
            perror("ERROR on fork");
            exit(1);
        }
        if (pid == 0) { // child process
            close(sockfd); // close original socket in child process
            while (1) {
                bzero(buffer, 256); // clear buffer
                n = read(newsockfd, buffer, 255); // read from socket
                if (n < 0) {
                    perror("ERROR reading from socket");
                    exit(1);
                }
                if (n == 0) { // client closed the connection
                    printf("Connection closed by client\n");
                    break;
                }
                printf("Received message from %s: %s\n", inet_ntoa(cli_addr.sin_addr), buffer);
                n = write(newsockfd, "I got your message", 18); // send response
                if (n < 0) {
                    perror("ERROR writing to socket");
                    exit(1);
                }
            }
            close(newsockfd); // close socket in child process
            exit(0); // exit child process
        } else { // parent process
            close(newsockfd); // close socket in parent process
        }
    }
    close(sockfd); // close original socket
    return 0;
}