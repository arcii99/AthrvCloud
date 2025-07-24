//FormAI DATASET v1.0 Category: Socket programming ; Style: Linus Torvalds
/* 
 * A simple client-server chat program using TCP/IP socket programming in C
 * By [Your Name] in the style of Linux Torvalds
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, n;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
        error("ERROR on binding");
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    printf("Waiting for client connection...\n");
    newsockfd = accept(sockfd, 
                (struct sockaddr *) &cli_addr, 
                &clilen);
    if (newsockfd < 0) 
        error("ERROR on accept");

    printf("Connected to client!\n");

    while(1) {
        bzero(buffer,256);
        n = read(newsockfd,buffer,255);
        if (n < 0) error("ERROR reading from socket");
        printf("Client: %s\n",buffer);
        bzero(buffer,256);
        fgets(buffer,255,stdin);
        n = write(newsockfd,buffer,strlen(buffer));
        if (n < 0) error("ERROR writing to socket");
        if (strncmp(buffer, "Bye", 3) == 0) {
            printf("Connection closed.\n");
            break;
        }
    }
    close(newsockfd);
    close(sockfd);
    return 0; 
}