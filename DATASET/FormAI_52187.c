//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Romeo and Juliet
/* Romeo and Juliet Simple Web Server */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[BUFSIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);;
    if (sockfd < 0) {
        printf("Alas! Socket creation failed.\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = 1234;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("O woe! Binding failed.\n");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            printf("Alack! Error accepting new connection.\n");
            continue;
        }

        memset(buffer, 0, BUFSIZE);
        n = read(newsockfd, buffer, BUFSIZE);
        if (n < 0) {
            printf("Help! Error reading from socket.\n");
            continue;
        }

        printf("Juliet: Oh Romeo Romeo! Wherefore art thou Romeo?\n");
        printf("Romeo: Here, what can I do for thee?\n");

        n = write(newsockfd, "HTTP/1.1 200 OK\n\n <html><head><title>Romeo and Juliet WebServer</title></head><body><h1>Romeo and Juliet Simple WebServer is running fine</h1></body></html>", strlen("HTTP/1.1 200 OK\n\n <html><head><title>Romeo and Juliet WebServer</title></head><body><h1>Romeo and Juliet Simple WebServer is running fine</h1></body></html>"));
        if (n < 0) {
            printf("Alas! Error writing to socket.\n");
            continue;
        }

        close(newsockfd);       
    }

    close(sockfd);
    return 0;
}