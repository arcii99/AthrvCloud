//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_PING_PACKET_SIZE 1024
#define MAX_HOSTNAME_LENGTH 1024

int pingHost(char *hostname) {
    int sockfd;
    struct sockaddr_in servaddr;
    char ping_packet[MAX_PING_PACKET_SIZE];
    int ping_packet_size = sizeof(ping_packet);

    // create socket connection
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    // set up server address information
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, hostname, &(servaddr.sin_addr));

    // create ping packet
    memset(ping_packet, 0, ping_packet_size);
    int icmp_type = 8; // ICMP Echo Request
    int icmp_code = 0;
    int icmp_checksum = 0;
    int icmp_identifier = getpid();
    int icmp_seqnum = 1;
    sprintf(ping_packet, "%c%c%c%c%c%c%c%c%d%d", icmp_type, icmp_code, icmp_checksum, icmp_checksum, icmp_identifier, icmp_identifier, icmp_seqnum, icmp_seqnum, 0, 0);

    // send ping packet
    if (sendto(sockfd, ping_packet, ping_packet_size, 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error sending ping packet");
        return -1;
    }

    printf("%s - Host is UP\n", hostname);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    pingHost(hostname);

    return 0;
}