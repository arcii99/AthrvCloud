//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define MAX_LENGTH 1024

void error(char *msg)
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

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Begin IMAP client interaction
    bzero(buffer,MAX_LENGTH);
    n = read(sockfd,buffer,MAX_LENGTH-1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);

    bzero(buffer,MAX_LENGTH);
    printf("Please enter the IDLE command: ");
    fgets(buffer,MAX_LENGTH-1,stdin);

    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    bzero(buffer,MAX_LENGTH);
    n = read(sockfd,buffer,MAX_LENGTH-1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);

    printf("Connection closed.");

    close(sockfd);

    return 0;
}