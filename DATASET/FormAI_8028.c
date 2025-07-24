//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Claude Shannon
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFF_SIZE];
    struct sockaddr_in servaddr, cliaddr;

    // create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // set up the server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8888);

    // bind the socket with the server address
    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // loop forever, receiving packets and printing them
    while (1) {
        unsigned int len = sizeof(cliaddr);
        n = recvfrom(sockfd, buffer, BUFF_SIZE, 0, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
        printf("Received Packet from %s:%d\n%s\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port), buffer);
    }

    return 0;
}