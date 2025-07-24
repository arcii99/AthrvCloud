//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    struct ether_header *ethh;
    struct iphdr *iph;
    struct tcphdr *tcph;
    u_int ip_len;

    /* Get Ethernet header */
    ethh = (struct ether_header *)packet;

    /* Get IP header */
    iph = (struct iphdr *)(packet + sizeof(struct ether_header));
    ip_len = iph->ihl * 4;

    /* Get TCP header */
    tcph = (struct tcphdr *)(packet + sizeof(struct ether_header) + ip_len);

    /* Print packet details */
    printf("\n\nPacket captured:\n");
    printf("Source MAC address: %s\n", ether_ntoa((struct ether_addr *)ethh->ether_shost));
    printf("Destination MAC address: %s\n", ether_ntoa((struct ether_addr *)ethh->ether_dhost));
    printf("Source IP address: %s\n", inet_ntoa(*(struct in_addr *)&iph->saddr));
    printf("Destination IP address: %s\n", inet_ntoa(*(struct in_addr *)&iph->daddr));
    printf("Source port: %d\n", ntohs(tcph->source));
    printf("Destination port: %d\n", ntohs(tcph->dest));
}

int main(int argc, char *argv[])
{
    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    /* Select device to capture */
    if (argc == 2)
    {
        dev = argv[1];
    }
    else if (argc > 2)
    {
        fprintf(stderr, "Usage: %s [device]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        dev = pcap_lookupdev(errbuf);
        if (dev == NULL)
        {
            fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
            exit(EXIT_FAILURE);
        }
    }

    /* Open device for capture */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    /* Capture packets */
    printf("Listening on %s...\n", dev);
    pcap_loop(handle, -1, got_packet, NULL);

    /* Cleanup */
    pcap_close(handle);

    return 0;
}