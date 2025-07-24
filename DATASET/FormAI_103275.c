//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 1024

/* Main Function */
int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE];
    
    // Checks if user provided the necessary arguments
    if (argc < 3) {
        fprintf(stderr,"ERROR, usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Creates a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Checks if socket creation failed
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    // Sets server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    // Connects to the server
    if (connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR connecting\n");
        exit(1);
    }

    // Reads from socket and sends what is read to standard output
    while ((n = read(sockfd, buffer, BUFSIZE-1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    // Closes socket
    close(sockfd);

    return 0;
}