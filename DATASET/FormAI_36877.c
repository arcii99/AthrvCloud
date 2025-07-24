//FormAI DATASET v1.0 Category: Simple Web Server ; Style: unmistakable
#include <stdio.h>  
#include <stdlib.h>  
#include <netinet/in.h>  
#include <string.h>  
#include <unistd.h>  
#define BUFF_SIZE 1024  

void error(const char *msg) {  
    perror(msg);  
    exit(1);  
}  

int main(int argc, char *argv[]) {  
    int sockfd, newsockfd, portno, clientlen;  
    char buffer[BUFF_SIZE];  
    struct sockaddr_in serv_addr, cli_addr;  
    int n;  

    if (argc < 2) {  
        fprintf(stderr,"ERROR, no port provided\n");  
        exit(1);  
    }  

    // create socket  
    sockfd = socket(AF_INET, SOCK_STREAM, 0);  
    if (sockfd < 0)  
        error("ERROR opening socket");  

    // set server address  
    bzero((char *) &serv_addr, sizeof(serv_addr));  
    portno = atoi(argv[1]);  
    serv_addr.sin_family = AF_INET;  
    serv_addr.sin_addr.s_addr = INADDR_ANY;  
    serv_addr.sin_port = htons(portno);  

    // bind socket to address  
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)  
        error("ERROR on binding");  

    // listen to incoming connections  
    listen(sockfd, 1);  
    clientlen = sizeof(cli_addr);  

    // accept incoming connections  
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clientlen);  
    if (newsockfd < 0)  
        error("ERROR on accept");  

    // read data from client and print it  
    bzero(buffer, BUFF_SIZE);  
    n = read(newsockfd, buffer, BUFF_SIZE - 1);  
    if (n < 0)  
        error("ERROR reading from socket");  

    printf("Here is the message:\n%s\n", buffer);  

    // send message back to client  
    n = write(newsockfd, "I got your message", 18);  
    if (n < 0)  
        error("ERROR writing to socket");  

    close(newsockfd);  
    close(sockfd);  
    return 0;  
}