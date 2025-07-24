//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <netinet/ip.h>

/* Callback function to print packet details */
void packet_handler(unsigned char *args, const struct pcap_pkthdr *header, const unsigned char *packet)
{
    struct ether_header *eth_header;
    struct ip *ip_header;
    unsigned int ip_header_length;

    /* Extracting data from Ethernet header */
    eth_header = (struct ether_header *)packet;
    if (ntohs(eth_header->ether_type) != ETHERTYPE_IP) {
        printf("Not an IP packet. Skipping...\n\n");
        return;
    }

    /* Extracting data from IP header */
    ip_header = (struct ip *)(packet + sizeof(struct ether_header));
    ip_header_length = ip_header->ip_hl * 4;

    /* Printing packet details */
    printf("Packet captured length: %d\n", header->caplen);
    printf("Packet total length %d\n", header->len);
    printf("Source MAC address: %s\n", ether_ntoa(eth_header->ether_shost));
    printf("Destination MAC address: %s\n", ether_ntoa(eth_header->ether_dhost));
    printf("Source IP address: %s\n", inet_ntoa(ip_header->ip_src));
    printf("Destination IP address: %s\n", inet_ntoa(ip_header->ip_dst));
    printf("Protocol: %d\n\n", ip_header->ip_p);
}

int main(int argc, char **argv)
{
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    char filter_exp[] = "ip";

    /* Open packet capture device */
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Unable to open capture device: %s\n", error_buffer);
        exit(1);
    }

    /* Compiling and setting packet filter */
    if (pcap_compile(handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Unable to compile packet filter: %s\n", pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting packet filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    /* Capturing packets */
    printf("Starting packet capture...\n");
    pcap_loop(handle, 0, packet_handler, NULL);

    /* Cleanup */
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}