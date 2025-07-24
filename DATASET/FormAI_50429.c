//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <signal.h>

#define PORT 8080
#define MAXLINE 1024

volatile sig_atomic_t flag = 0;

void sigint_handler(int sig)
{
    flag = 1;
    printf("\nSignal received!\n");
}

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("=============================\n");
    printf("Listening for incoming UDP packets...\n");

    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = sigint_handler;
    sigaction(SIGINT, &act, NULL);

    while (!flag) {
        struct sockaddr_in cliaddr;
        socklen_t len = sizeof(cliaddr);
        int n;
        n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
        printf("Packet received!\n");

        char* ip = inet_ntoa(cliaddr.sin_addr);
        double rssi = strtod(buffer, NULL);
        double d = pow(10, (rssi + 35.75) / -35.63);

        printf("IP: %s, RSSI: %f dBm, Distance: %f meters\n", ip, rssi, d);
    }

    printf("Closing socket...\n");
    close(sockfd);
    return 0;
}