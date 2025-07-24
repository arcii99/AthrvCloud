//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024 

/* A function to print error messages */
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    
    /* Create a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    /* Setup the server address structure */
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5001);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    /* Connect to the server */
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    /* Setup TCP_NODELAY option for QoS monitoring */
    int one = 1;
    if (setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, &one, sizeof(one)) == -1)
        error("ERROR setting TCP_NODELAY");

    /* Start QoS monitoring */
    int bytes_sent = 0;
    int bytes_received = 0;
    while (1) {
        /* Send data to the server */
        strcpy(buffer, "Hello, world!\n");
        int n = write(sockfd, buffer, strlen(buffer));
        if (n < 0)
            error("ERROR writing to socket");
        bytes_sent += n;

        /* Receive data from the server */
        bzero(buffer, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE);
        if (n < 0)
            error("ERROR reading from socket");
        bytes_received += n;

        /* Print QoS statistics */
        printf("==============================\n");
        printf("Bytes sent: %d\nBytes received: %d\n", bytes_sent, bytes_received);
        printf("Send rate: %.2f bytes/second\n", (double) bytes_sent / (double) (1));
        printf("Receive rate: %.2f bytes/second\n", (double) bytes_received / (double) (1));
        printf("==============================\n");

        /* Sleep for 1 second before sending/receiving more data */
        sleep(1);
    }

    /* Close the socket */
    close(sockfd);

    return 0;
}