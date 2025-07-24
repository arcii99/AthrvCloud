//FormAI DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h> // for standard I/O operations
#include <stdlib.h> // for exit() function
#include <sys/socket.h> // for socket(), AF_INET, and SOCK_RAW constants
#include <netinet/in.h> // for IPPROTO_ICMP constant
#include <arpa/inet.h> // for inet_addr() function
#include <unistd.h> // for close() function
#include <string.h> // for memset() function
#include <netinet/ip_icmp.h> // for ICMP packet structure

// function to calculate checksum of packet
unsigned short calculate_checksum(unsigned short *paddress, int len);

int main(int argc, char *argv[]) {
    // initialize variables
    int sockfd, sent = 0, received = 0;
    struct sockaddr_in addr;
    struct icmphdr icmp;
    char packet[1024];
    memset(&icmp, 0, sizeof(struct icmphdr));
    memset(packet, 0, sizeof(packet));

    // check number of arguments
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    // create raw socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation error");
        exit(1);
    }

    // set socket options
    int on = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) < 0) {
        perror("Error setting socket options");
        exit(1);
    }

    // set destination address
    if (inet_addr(argv[1]) == -1) {
        printf("Invalid IP address\n");
        exit(1);
    }
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    // set ICMP packet parameters
    icmp.type = ICMP_ECHO;
    icmp.code = 0;
    icmp.checksum = 0;
    icmp.un.echo.id = getpid();

    // send ICMP packet
    while (sent < 10) {
        icmp.un.echo.sequence = sent++;
        memcpy(packet, &icmp, sizeof(struct icmphdr));
        icmp.checksum = calculate_checksum((unsigned short *) packet, sizeof(struct icmphdr));
        memcpy(packet, &icmp, sizeof(struct icmphdr));
        if ((sendto(sockfd, packet, sizeof(struct icmphdr), 0, (struct sockaddr *) &addr, sizeof(struct sockaddr))) < 0) {
            perror("Error sending packet");
            continue;
        }
        sleep(1);
    }

    // receive ICMP packets
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    int addrlen, len;
    struct sockaddr_in r_addr;
    while (received < sent) {
        addrlen = sizeof(r_addr);
        if ((len = recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr *) &r_addr, &addrlen)) < 0) {
            printf("Packet lost\n");
            continue;
        }
        // check if packet is ICMP
        struct iphdr *ipheader = (struct iphdr *) packet;
        struct icmphdr *icmpheader = (struct icmphdr *) (packet + sizeof(struct iphdr));
        if (icmpheader->type == ICMP_ECHOREPLY && icmpheader->un.echo.id == getpid()) {
            printf("Received reply from %s, RTT = %d ms\n", inet_ntoa(r_addr.sin_addr), len);
            received++;
        }
    }

    // close socket
    close(sockfd);

    return 0;
}

// function to calculate checksum of packet
unsigned short calculate_checksum(unsigned short *paddress, int len) {
    int nleft = len;
    int sum = 0;
    unsigned short *w = paddress;
    unsigned short answer = 0;

    while (nleft > 1) {
        sum += *w++;
        nleft -= 2;
    }

    if (nleft == 1) {
        *(unsigned char *) (&answer) = *(unsigned char *) w;
        sum += answer;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    answer = ~sum;
    return answer;
}