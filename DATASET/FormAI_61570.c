//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <net/if.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netpacket/packet.h>

#define MAX_INTERFACES 64
#define ETHER_TYPE 0x0800 // IP Protocol

int main(int argc, char **argv) {
    int sock, i, j;
    struct ifreq ifreqs[MAX_INTERFACES];
    struct sockaddr_ll saddr;
    unsigned char broadcast[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
    unsigned int len;
    unsigned char *buffer;
    struct ether_header *eth_header;
    struct in_addr source_ip, dest_ip;

    sock = socket(PF_PACKET, SOCK_RAW, htons(ETHER_TYPE));

    if (sock < 0) {
        perror("socket error");
        exit(1);
    }

    memset(&saddr, 0, sizeof(saddr));
    saddr.sll_family = AF_PACKET;
    saddr.sll_protocol = htons(ETHER_TYPE);
    saddr.sll_ifindex = if_nametoindex("eth0");

    if (bind(sock, (struct sockaddr*)&saddr, sizeof(saddr)) < 0) {
        perror("bind error");
        exit(1);
    }

    if (ioctl(sock, SIOCGIFCONF, ifreqs) < 0) {
        perror("ioctl SIOCGIFCONF error");
        exit(1);
    }

    len = 0;
    for (i = 0; i < MAX_INTERFACES; i++) {
        if (ifreqs[i].ifr_addr.sa_family == AF_INET) {
            printf("Interface %s:\n", ifreqs[i].ifr_name);
            if (ioctl(sock, SIOCGIFHWADDR, &ifreqs[i]) == 0) {
                printf("  MAC Address: ");
                for (j = 0; j < 6; j++) {
                    printf("%.2x", (unsigned char)ifreqs[i].ifr_hwaddr.sa_data[j]);
                    if (j < 5) {
                        printf(":");
                    }
                }
                printf("\n");
            }
            if (ioctl(sock, SIOCGIFADDR, &ifreqs[i]) == 0) {
                memcpy(&source_ip, &((struct sockaddr_in *)&ifreqs[i].ifr_addr)->sin_addr, sizeof(struct in_addr));
                printf("  IP Address: %s\n", inet_ntoa(source_ip));
            }
            printf("\n");
        }
    }

    buffer = (unsigned char*)malloc(ETH_FRAME_LEN);
    if (buffer == NULL) {
        perror("malloc error");
        exit(1);
    }

    memset(buffer, 0, ETH_FRAME_LEN);

    eth_header = (struct ether_header*)buffer;
    eth_header->ether_type = htons(ETHER_TYPE);
    memcpy(eth_header->ether_dhost, broadcast, 6);

    for (i = 0; i < MAX_INTERFACES; i++) {
        if (ifreqs[i].ifr_addr.sa_family == AF_INET) {
            if (ioctl(sock, SIOCGIFADDR, &ifreqs[i]) == 0) {
                memcpy(&source_ip, &((struct sockaddr_in *)&ifreqs[i].ifr_addr)->sin_addr, sizeof(struct in_addr));
            }
            saddr.sll_ifindex = if_nametoindex(ifreqs[i].ifr_name);
            memcpy(eth_header->ether_shost, &saddr.sll_addr, 6);
            if (sendto(sock, buffer, ETH_FRAME_LEN, 0, (struct sockaddr*)&saddr, sizeof(saddr)) < 0) {
                perror("sendto error");
            }
        }
    }

    free(buffer);
    close(sock);
    exit(0);
}