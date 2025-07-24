//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

/* Callback function for packet capture */
void packet_callback(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    struct ether_header *ethh;
    struct ip *iph;
    struct tcphdr *tcph;

    /* Extracting Ethernet header */
    ethh = (struct ether_header *) packet;

    /* Extracting IP header */
    iph = (struct ip *) (packet + sizeof(struct ether_header));

    /* Check if the packet is TCP */
    if (iph->ip_p == IPPROTO_TCP) {
        /* Extracting TCP header */
        tcph = (struct tcphdr *) (packet + sizeof(struct ether_header) + sizeof(struct ip));

        /* Printing packet details */
        printf("Packet captured at: %s", ctime((const time_t *)&header->ts.tv_sec));
        printf("Source MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n", ethh->ether_shost[0],
               ethh->ether_shost[1], ethh->ether_shost[2], ethh->ether_shost[3], ethh->ether_shost[4],
               ethh->ether_shost[5]);
        printf("Destination MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n", ethh->ether_dhost[0],
               ethh->ether_dhost[1], ethh->ether_dhost[2], ethh->ether_dhost[3], ethh->ether_dhost[4],
               ethh->ether_dhost[5]);
        printf("Source IP address: %s\n", inet_ntoa(iph->ip_src));
        printf("Destination IP address: %s\n", inet_ntoa(iph->ip_dst));
        printf("Source port: %d\n", ntohs(tcph->source));
        printf("Destination port: %d\n", ntohs(tcph->dest));
    }
}

/* Main function */
int main(int argc, char *argv[])
{
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer for pcap

    /* Check for valid CLI arguments */
    if (argc != 2) {
        printf("Usage: %s [Network Interface Name]\n", argv[0]);
        return 1;
    }

    /* Open network interface for packet capture */
    pcap_t *handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening network interface: %s\n", errbuf);
        return 1;
    }

    /* Capture packets */
    if (pcap_loop(handle, -1, packet_callback, NULL) < 0) {
        printf("Error while capturing packets: %s\n", pcap_geterr(handle));
        return 1;
    }

    /* Close handle */
    pcap_close(handle);

    return 0;
}