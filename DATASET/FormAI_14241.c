//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 1024

void error(char *msg){
    perror(msg);
    exit(1);    
}

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    int sockfd, portno, n, len;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
        error("Error opening socket!");
    server = gethostbyname(argv[1]);
    if(server == NULL){
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);
    if(connect(sockfd, (struct sockaddr *) &serv_addr,
               sizeof(serv_addr)) < 0)
        error("Connection failed!");
    printf("Please enter the message to be sent:");
    bzero(buffer, sizeof(buffer));
    fgets(buffer, sizeof(buffer) - 1, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if(n < 0)
        error("Error writing to socket!");
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if(n < 0)
        error("Error reading from socket!");
    printf("Server response: %s\n", buffer);
    close(sockfd);
    return 0;
}