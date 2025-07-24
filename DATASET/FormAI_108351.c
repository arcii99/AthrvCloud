//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <netinet/if_ether.h>
#include <net/if.h>
#include <netpacket/packet.h>

#define MAX_PACKET_LEN 65535
#define ETH_HDR_LEN 14

const char* WIFI_IF_NAME = "wlan0"; //Change this to match your wireless interface name

int main() {
    int sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sockfd == -1) {
        printf("Error in opening socket");
        exit(EXIT_FAILURE);
    }
    
    struct ifreq if_idx;
    memset(&if_idx, 0, sizeof(struct ifreq));
    strncpy(if_idx.ifr_name, WIFI_IF_NAME, strlen(WIFI_IF_NAME));
    if (ioctl(sockfd, SIOCGIFINDEX, &if_idx) == -1) {
        printf("Error in IOCTL");
        exit(EXIT_FAILURE);
    }

    struct ifreq if_mac;
    memset(&if_mac, 0, sizeof(struct ifreq));
    strncpy(if_mac.ifr_name, WIFI_IF_NAME, strlen(WIFI_IF_NAME));
    if (ioctl(sockfd, SIOCGIFHWADDR, &if_mac) == -1) {
        printf("Error in IOCTL");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_ll socket_address;
    socket_address.sll_family = AF_PACKET;
    socket_address.sll_ifindex = if_idx.ifr_ifindex;
    socket_address.sll_hatype = htons(ARPHRD_ETHER);
    socket_address.sll_pkttype = htons(PACKET_OTHERHOST);
    socket_address.sll_halen = ETH_ALEN;
    socket_address.sll_addr[0] = 0xff;
    socket_address.sll_addr[1] = 0xff;
    socket_address.sll_addr[2] = 0xff;
    socket_address.sll_addr[3] = 0xff;
    socket_address.sll_addr[4] = 0xff;
    socket_address.sll_addr[5] = 0xff;

    char packet[MAX_PACKET_LEN];
    memset(packet, 0, MAX_PACKET_LEN);

    struct ether_header *eh_ptr = (struct ether_header *) packet;
    memset(eh_ptr, 0, ETH_HDR_LEN);
    memcpy(eh_ptr->ether_shost, &if_mac.ifr_hwaddr.sa_data, ETH_ALEN);
    memcpy(eh_ptr->ether_dhost, "\xff\xff\xff\xff\xff\xff", ETH_ALEN);
    eh_ptr->ether_type = htons(0x0800);

    // Construct ARP request
    struct arphdr *arph_ptr = (struct arphdr *)(packet + ETH_HDR_LEN);
    memset(arph_ptr, 0, sizeof(struct arphdr));
    arph_ptr->ar_hrd = htons(ARPHRD_ETHER);
    arph_ptr->ar_pro = htons(ETH_P_IP);
    arph_ptr->ar_hln = ETH_ALEN;
    arph_ptr->ar_pln = 4;
    arph_ptr->ar_op = htons(ARPOP_REQUEST);
    
    unsigned char *arp_src_ptr = (packet + ETH_HDR_LEN + sizeof(struct arphdr));
    memcpy(arp_src_ptr, &if_mac.ifr_hwaddr.sa_data, ETH_ALEN);
    arp_src_ptr += ETH_ALEN;

    struct in_addr src_ip_addr;
    inet_aton("0.0.0.0", &src_ip_addr);
    memcpy(arp_src_ptr, &src_ip_addr.s_addr, 4);
    arp_src_ptr += 4;

    memset(arp_src_ptr, 0, ETH_ALEN);

    struct in_addr dst_ip_addr;
    inet_aton("192.168.0.1", &dst_ip_addr);
    unsigned char *arp_dest_ptr = (arp_src_ptr + 4);
    memcpy(arp_dest_ptr, &dst_ip_addr.s_addr, 4);

    int packet_len = ETH_HDR_LEN + sizeof(struct arphdr) + ETH_ALEN*2 + 4;
    int ret = sendto(sockfd, packet, packet_len, 0, (struct sockaddr*)&socket_address, sizeof(struct sockaddr_ll));

    if (ret == -1) {
        printf("Error in Sending Request");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    char recv_buf[MAX_PACKET_LEN];
    memset(recv_buf, 0, MAX_PACKET_LEN);

    struct sockaddr_in sockaddr_in_ip;
    socklen_t socklen = sizeof(struct sockaddr_in);
    struct ether_header *recv_eth_hdr;
    struct arphdr *recv_arphdr;

    time_t start = time(NULL);
    while (time(NULL) - start < 5) { //Scan for 5 seconds
        ssize_t recv_len = recvfrom(sockfd, recv_buf, MAX_PACKET_LEN, 0, (struct sockaddr *)&socket_address, &socklen);

        if (recv_len == -1) {
            printf("Error in receiving packet");
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        recv_eth_hdr = (struct ether_header *) recv_buf;
        if (ntohs(recv_eth_hdr->ether_type) != ETHERTYPE_ARP) {
            continue;
        }

        recv_arphdr = (struct arphdr *)(recv_buf + ETH_HDR_LEN);
        if (ntohs(recv_arphdr->ar_op) != ARPOP_REPLY || memcmp((recv_buf + ETH_HDR_LEN + sizeof(struct arphdr) + ETH_ALEN), &src_ip_addr.s_addr, 4) != 0) {
            continue;
        }

        unsigned char* recv_arp_ptr = recv_buf + ETH_HDR_LEN + sizeof(struct arphdr);
        printf("MAC Address: %02X:%02X:%02X:%02X:%02X:%02X, IP Address: %d.%d.%d.%d\n", recv_arp_ptr[0], recv_arp_ptr[1], recv_arp_ptr[2], recv_arp_ptr[3], recv_arp_ptr[4], recv_arp_ptr[5], recv_arp_ptr[6], recv_arp_ptr[7], recv_arp_ptr[8], recv_arp_ptr[9]);
    }

    close(sockfd);
    return 0;
}