//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <net/ethernet.h>
#include <netdb.h>

#define INTERFACE_NAME "wlan0"

void print_hex(unsigned char *buffer, int length) {
    int i;
    for(i = 0; i < length; ++i)
        printf("%02x ", buffer[i]);
}

void print_mac_address(unsigned char *mac) {
    int i;
    for(i = 0; i < 6; ++i)
        printf("%02x%c", mac[i], (i == 5) ? '\n' : ':');
}

int main() {
    int sock_fd;
    if((sock_fd=socket(AF_PACKET,SOCK_RAW,htons(ETH_P_ALL))) == -1) {
        perror("socket");
        exit(1);
    }

    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, INTERFACE_NAME, IFNAMSIZ);

    if(ioctl(sock_fd, SIOCGIFINDEX, &ifr) == -1) {
        perror("ioctl SIOCGIFINDEX");
        exit(1);
    }

    struct sockaddr_ll addr;
    memset(&addr, 0, sizeof(addr));
    addr.sll_family = AF_PACKET;
    addr.sll_ifindex = ifr.ifr_ifindex;
    addr.sll_pkttype = PACKET_OTHERHOST;
    addr.sll_halen = 6;

    unsigned char broadcast_mac[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    memcpy(addr.sll_addr, broadcast_mac, 6);

    int send_len;
    unsigned char packet_buffer[ETH_FRAME_LEN];

    memset(packet_buffer, 0, ETH_FRAME_LEN);

    struct ethhdr *eth_header;
    eth_header = (struct ethhdr *)packet_buffer;

    memcpy(eth_header->h_dest, broadcast_mac, 6);
    memset(&eth_header->h_source, 0, 6);
    eth_header->h_proto = htons(ETH_P_ARP);

    send_len = sendto(sock_fd, packet_buffer, ETH_FRAME_LEN, 0,
                      (struct sockaddr *)&addr, sizeof(addr));

    if(send_len < 0) {
        perror("Send failed");
        return 1;
    }

    printf("Wireless Network Scanner\n\n");

    while(1) {
        unsigned char recv_buffer[ETH_FRAME_LEN];
        int recv_len = recvfrom(sock_fd, recv_buffer, ETH_FRAME_LEN, 0, NULL, NULL);
        if(recv_len < 0) {
            perror("Receive failed");
            return 1;
        }

        struct ethhdr *header;
        header = (struct ethhdr *)recv_buffer;

        if(ntohs(header->h_proto) == ETH_P_ARP) {
            unsigned char *arp_buffer = (unsigned char *)(header + 1);
            if (ntohs(*(unsigned short *)(arp_buffer + 4)) == 2) {
                printf("------\n");
                printf("IP Address: %d.%d.%d.%d\n", arp_buffer[14], arp_buffer[15], arp_buffer[16], arp_buffer[17]);
                printf("MAC Address: ");
                print_mac_address((unsigned char *)(arp_buffer + 8));
                printf("------\n");
            }
        }
    }

    return 0;
}