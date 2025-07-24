//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFSIZE 1024

int main(int argc, char *argv[]) {

    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[BUFSIZE], recvline[BUFSIZE];
    struct timeval start, end;
    double elapsedTime;

    // check for correct number of arguments
    if (argc != 2) {
        printf("Usage: ./speedtest <server_ip>\n");
        exit(1);
    }

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);   
    }

    // set server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);   
    }

    // start timer
    gettimeofday(&start, NULL);

    // send message to server
    snprintf(sendline, BUFSIZE, "test");
    if (write(sockfd, sendline, strlen(sendline)) < 0) {
        perror("write");
        exit(1);   
    }

    // receive message from server
    if ((n = read(sockfd, recvline, BUFSIZE)) < 0) {
        perror("read");
        exit(1);   
    }

    // stop timer
    gettimeofday(&end, NULL);

    // calculate elapsed time
    elapsedTime = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec)/1000000.0);

    // calculate speed
    double speed = BUFSIZE / elapsedTime;

    // print results
    printf("Speed: %.2f Bytes/Second\n", speed);

    // close socket
    close(sockfd);

    return 0;
}