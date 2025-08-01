//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

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
        perror("ERROR opening socket");

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
        perror("ERROR connecting");

    printf("Welcome to my SMTP client program!\n");
    printf("Please enter your email address: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0)
         perror("ERROR writing to socket");

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0)
         perror("ERROR reading from socket");
    printf("%s\n",buffer);

    printf("Please enter the recipient's email address: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0)
         perror("ERROR writing to socket");

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0)
         perror("ERROR reading from socket");
    printf("%s\n",buffer);

    printf("Please enter the subject of your message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0)
         perror("ERROR writing to socket");

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0)
         perror("ERROR reading from socket");
    printf("%s\n",buffer);

    printf("Please enter your message:\n");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0)
         perror("ERROR writing to socket");

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0)
         perror("ERROR reading from socket");
    printf("%s\n",buffer);

    close(sockfd);
    return 0;
}