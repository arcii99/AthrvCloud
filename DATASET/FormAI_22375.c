//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: artistic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>

void capture_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured\n");

    struct ethhdr *eth = (struct ethhdr *)packet;
    if (eth->h_proto != ntohs(ETH_P_IP))
    {
        printf("Non-IP Packet\n");
        return;
    }

    struct iphdr *ip = (struct iphdr *)(packet + sizeof(struct ethhdr));
    printf("IP Version: %d\n", ip->version);
    printf("IP Protocol: %d\n", ip->protocol);
    printf("Source IP Address: %s\n", inet_ntoa(*(struct in_addr *)&ip->saddr));
    printf("Destination IP Address: %s\n", inet_ntoa(*(struct in_addr *)&ip->daddr));
    
    // Additional processing for packet data can be done here
}

int main()
{
    char errbuff[PCAP_ERRBUF_SIZE];
    char *dev = pcap_lookupdev(errbuff);

    if (dev == NULL)
    {
        printf("Error finding device: %s\n", errbuff);
        return 1;
    }

    printf("Device: %s\n", dev);

    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuff);

    if (handle == NULL)
    {
        printf("Error opening device: %s\n", errbuff);
        return 1;
    }

    printf("Started capturing packets...\n");

    pcap_loop(handle, -1, capture_packet, NULL);

    pcap_close(handle);

    return 0;
}