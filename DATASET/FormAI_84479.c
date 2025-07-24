//FormAI DATASET v1.0 Category: Simple Web Server ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_LEN 1024

void serve(int sockfd)
{
    char buffer[MAX_LEN];
    int n;

    /* read HTTP request from client */
    bzero(buffer, MAX_LEN);
    n = read(sockfd, buffer, MAX_LEN);
    if (n < 0)
        perror("ERROR reading from socket");

    /* print HTTP request to console */
    printf("HTTP request:\n%s\n", buffer);

    /* send HTTP response to client */
    char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    n = write(sockfd, response, strlen(response));
    if (n < 0)
        perror("ERROR writing to socket");
    char body[] = "<html><body><h1>Welcome to my web server!</h1></body></html>";
    n = write(sockfd, body, strlen(body));
    if (n < 0)
        perror("ERROR writing to socket");
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    /* create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        perror("ERROR opening socket");

    /* configure server address */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 8080;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* bind socket to address */
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        perror("ERROR on binding");

    /* listen for client connections */
    listen(sockfd, 5);

    printf("Web server listening on port %d...\n", portno);

    while (1) {
        /* accept client connection */
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            perror("ERROR on accept");

        /* handle client request */
        serve(newsockfd);

        /* close client connection */
        close(newsockfd);
    }

    /* close server socket */
    close(sockfd);

    return 0;
}