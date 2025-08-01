//FormAI DATASET v1.0 Category: Networking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    if (argc < 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0); //create a new TCP socket
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]); //get the server's IP address
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    //initialize the serv_addr structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    //connect to the server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Please enter the message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin); //read user input
    n = write(sockfd, buffer, strlen(buffer)); //send message to server
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255); //read server response
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    close(sockfd); //close the socket
    return 0;
}