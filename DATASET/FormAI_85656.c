//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
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

    char* request = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    char* host = argv[1];
    int request_len = strlen(host)+strlen(request);
    char* buffer_c = (char*)malloc(request_len);
    sprintf(buffer_c, request, host);

    bzero(buffer,256);        
    n = write(sockfd,buffer_c,strlen(buffer_c));
    if (n < 0) 
         error("ERROR writing to socket");
    else printf("Request sent to %s\n", host);

    bzero(buffer,256);       
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    else printf("%s\n",buffer);

    close(sockfd);
    return 0;
}