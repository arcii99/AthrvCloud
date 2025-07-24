//FormAI DATASET v1.0 Category: Firewall ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define PACKET_SIZE 65536

int main(int argc, char *argv[]) {

    int sockfd, n;

    struct sockaddr_in servaddr,cliaddr;
    socklen_t len;

    pid_t pid;

    char mesg[PACKET_SIZE];

    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(1234);

    if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    len = sizeof(cliaddr);

    while(1) {

        memset(mesg, 0, PACKET_SIZE);

        n = recvfrom(sockfd, (char *)mesg, PACKET_SIZE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
        if (n < 0) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        pid = fork();

        if (pid == -1) {
            perror("fork() error");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {

            struct in_addr inaddr;
            char ipaddr[INET_ADDRSTRLEN];

            inet_aton(argv[1], &inaddr);
            inet_ntop(AF_INET, &inaddr, ipaddr, INET_ADDRSTRLEN);

            if(strstr(mesg, ipaddr) == NULL) {

              printf("Blocked packet from IP %s\n", inet_ntoa(cliaddr.sin_addr));
              exit(EXIT_SUCCESS);
            }

            sendto(sockfd, (const char *)mesg, strlen(mesg), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);

            exit(EXIT_SUCCESS);

        } else {
            signal(SIGCHLD, SIG_IGN); // avoid zombie processes
        }

    }

    return 0;
}