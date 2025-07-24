//FormAI DATASET v1.0 Category: Network Ping Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define PACKET_SIZE 64 // in bytes 

/*
Ping function which sends ICMP echo request to destination address
and prints the ping response along with RTT.
*/

double ping(char *ip_addr, int ttl)
{
    // create socket descriptor
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    // TTL option for socket
    setsockopt(sockfd, SOL_IP, IP_TTL, &ttl, sizeof(ttl));
    
    struct sockaddr_in target;
    bzero(&target,sizeof(target));
    target.sin_family = AF_INET;
    inet_pton(AF_INET, ip_addr, &(target.sin_addr));

    struct timeval start, end;
    double time_taken;

    // calculate message buffer size
    int msg_size = PACKET_SIZE + sizeof(struct timeval);
    char msg[msg_size];
    memset(msg, 0, sizeof(msg));

    // prepare the message
    struct timeval *tval = (struct timeval *) (msg + sizeof(struct timeval));
    gettimeofday(tval, NULL);

    // send the message
    if (sendto(sockfd, msg, PACKET_SIZE, 0, (struct sockaddr *) &target, sizeof(target)) < 0) {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    // start the timer
    gettimeofday(&start, NULL);

    // receive the response
    struct sockaddr_in response_addr;
    socklen_t len = sizeof(response_addr);
    char response[PACKET_SIZE];
    if (recvfrom(sockfd, response, PACKET_SIZE, 0, (struct sockaddr *)&response_addr, &len) < 0) {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // stop the timer
    gettimeofday(&end, NULL);
    time_taken = (end.tv_sec - start.tv_sec) * 1000.0; 
    time_taken += (end.tv_usec - start.tv_usec) / 1000.0;
    
    // print the response
    printf("%d bytes from %s: icmp_seq=1 ttl=%d time=%f ms\n", PACKET_SIZE, ip_addr, ttl, time_taken);

    close(sockfd);
    return time_taken;
}

// main function
int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *ip_addr = argv[1];

    int ttl;
    for (ttl = 1; ttl <= 30; ttl++) {
        double time_taken = ping(ip_addr, ttl);
        if (time_taken < 0) {
            printf("PING Error.\n");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}