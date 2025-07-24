//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, sent_bytes, received_bytes, i;
    char buffer[BUFSIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }
    printf("Please enter the message: ");
    bzero(buffer, BUFSIZE);
    fgets(buffer, BUFSIZE, stdin);
    sent_bytes = write(sockfd, buffer, strlen(buffer));
    if (sent_bytes < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    bzero(buffer, BUFSIZE);
    received_bytes = read(sockfd, buffer, BUFSIZE);
    if (received_bytes < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("Response from server: %s\n", buffer);
    close(sockfd);
    return 0;
}