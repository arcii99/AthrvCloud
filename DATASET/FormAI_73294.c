//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX 1024

int main(){
    int sockfd;
    struct ifreq ifr;
    struct sockaddr_in *ipaddr;
    unsigned char sendpacket[MAX], recvpacket[MAX];
    int bytes_sent = 0, bytes_recv = 0;

    sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

    strncpy(ifr.ifr_name, "wlan0", IFNAMSIZ);

    if(ioctl(sockfd, SIOCGIFADDR, &ifr) < 0){
        perror("Error getting IP address: ");
        return 1;
    }

    ipaddr = (struct sockaddr_in *)&ifr.ifr_addr;

    printf("Scanning for wireless networks in range...\n\n");

    sprintf(sendpacket, "AT+CWLAP\r\n");

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("192.168.4.1");
    servaddr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to module: ");
        return 1;
    }

    bytes_sent = send(sockfd, sendpacket, strlen(sendpacket), 0);

    if(bytes_sent < 0){
        perror("Error sending packet: ");
        return 1;
    }

    bytes_recv = recv(sockfd, recvpacket, MAX, 0);

    if(bytes_recv < 0){
        perror("Error receiving packet: ");
        return 1;
    }

    else {
        printf("Wireless networks in range:\n\n");
        printf("%s", recvpacket);
    }

    close(sockfd);
    return 0;
}