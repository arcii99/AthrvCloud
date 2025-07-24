//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8021
#define MAXLINE 1024

int main() {

    int sockfd;
    socklen_t socklen;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAXLINE];
    int signal_strength;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Wi-Fi Signal Strength Analyzer is up and running...\n");

    while (1) {
        socklen = sizeof(cliaddr);
        memset(&buffer, 0, sizeof(buffer));
        if (recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &socklen) < 0) {
            perror("recvfrom failed");
            exit(EXIT_FAILURE);
        }

        signal_strength = abs((int)buffer[0]);

        printf("Received signal strength: %d dBm\n", signal_strength);

        if (signal_strength >= -50) {
            printf("Signal strength is excellent\n");
        } else if (signal_strength >= -60 && signal_strength < -50) {
            printf("Signal strength is good\n");
        } else if (signal_strength >= -70 && signal_strength < -60) {
            printf("Signal strength is fair\n");
        } else if (signal_strength >= -80 && signal_strength < -70) {
            printf("Signal strength is poor\n");
        } else {
            printf("Signal strength is very poor\n");
        }
    }
    close(sockfd);
    return 0;
}