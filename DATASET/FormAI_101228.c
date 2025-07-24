//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Sherlock Holmes
// It was a chilly morning in London when the well-known detective, Mr. Sherlock Holmes, decided to create a simple web server. 
//He knew that no detail could be overlooked in this task, so he carefully planned his code and analyzed every line. 
//Thus, he came up with the following example program: 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        error("ERROR on accept");
    }

    bzero(buffer, 1024);
    n = read(newsockfd, buffer, 1023);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("Here is the message: %s\n",buffer);

    n = write(newsockfd,"I detect that you have called me. How may I assist you?",56);
    if (n < 0) {
        error("ERROR writing to socket");
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}