//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>


#define BUF_SIZE 1024 // Buffer size for sending and receiving data
 
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
 
    char buffer[BUF_SIZE];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
 
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
 
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
 
    server = gethostbyname(argv[1]);
 
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
 
    bzero((char *) &serv_addr, sizeof(serv_addr));
 
    serv_addr.sin_family = AF_INET;
 
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
 
    serv_addr.sin_port = htons(portno);
 
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Enter the file name: ");
    bzero(buffer, BUF_SIZE);
    fgets(buffer, BUF_SIZE, stdin);
    
    char sendMessage[strlen(buffer)-1];
    strncpy(sendMessage, buffer, strlen(buffer)-1);
    
    n = write(sockfd, sendMessage, strlen(sendMessage));
 
    if (n < 0) {
        error("ERROR writing to socket");
    }
 
    bzero(buffer, BUF_SIZE);
 
    n = read(sockfd, buffer, BUF_SIZE);
 
    if (n < 0) {
        error("ERROR reading from socket");
    }
 
    printf("File contents: \n%s", buffer);

    close(sockfd);

    return 0;
}