//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LENGTH 1024

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_LENGTH];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    char *http_request = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: keep-alive\r\n\r\n";
    n = sprintf(buffer, http_request, argv[1]);

    n = send(sockfd,buffer,n,0);
    if (n <= 0) 
        error("ERROR writing to socket");

    bzero(buffer,MAX_LENGTH);

    while((n = recv(sockfd, buffer, MAX_LENGTH-1, 0)) > 0) {
        printf("%s", buffer);
        bzero(buffer, MAX_LENGTH);
    }

    if (n < 0) 
        error("ERROR reading from socket");

    close(sockfd);
    return 0;
}