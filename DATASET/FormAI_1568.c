//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define SERVER_PORT 8888
#define MAX_LINE 2048

void *packet_monitor(void *arg){
    char *message = (char*) arg;
    printf("Monitoring thread starting with message: %s\n", message);

    int sockfd;
    struct sockaddr_in servaddr;
    char buf[MAX_LINE];
    int nbytes;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERVER_PORT);

    bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    while (1) {
        bzero(buf, MAX_LINE);
        nbytes = recvfrom(sockfd, buf, MAX_LINE, 0, NULL, NULL);
        printf("Received packet: %s\n", buf);
    }
}

int main(int argc, char **argv) {
    pthread_t tid;
    char *monitor_msg = "Packet monitoring thread";
    int err;

    err = pthread_create(&tid, NULL, &packet_monitor, monitor_msg);
    if (err != 0) {
        printf("Error creating thread: %s\n", strerror(err));
        exit(EXIT_FAILURE);
    }

    while(1){
        // Main program continues to run indefinitely
        printf("Main program running...\n");
        sleep(1);
    }

    pthread_join(tid, NULL);
    return 0;
}