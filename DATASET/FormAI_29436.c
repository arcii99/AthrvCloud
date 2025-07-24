//FormAI DATASET v1.0 Category: Socket programming ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    
    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    
    // set server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 1337;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    // bind socket to address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    
    // listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    
    printf("Waiting for incoming connections...\n");
    
    // accept incoming connection
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    
    printf("Accepted connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
    
    // read message from client
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    
    printf("Received message: %s\n", buffer);
    
    // send response to client
    n = write(newsockfd, "Message received, over and out.", 31);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    
    printf("Sent response.\n");
    
    // close sockets
    close(newsockfd);
    close(sockfd);
    return 0;
}