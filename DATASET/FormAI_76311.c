//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

/* callback function to print packet info */
void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    static int count = 1;

    // get Ethernet header
    struct ether_header *eth_header = (struct ether_header *) packet;

    // skip if not IP packet
    if (ntohs(eth_header->ether_type) != ETHERTYPE_IP) {
        return;
    }

    // get IP header
    const u_char *ip_header = packet + sizeof(struct ether_header);

    // get source and destination IP addresses
    struct in_addr source, destination;
    memcpy(&source, ip_header+12, sizeof(struct in_addr));
    memcpy(&destination, ip_header+16, sizeof(struct in_addr));

    printf("Packet #%d - From: %s, To: %s\n", count, inet_ntoa(source), inet_ntoa(destination));

    count++;
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    pcap_t *handle;
    int timeout = 1000; // in milliseconds

    // open default device - change it according to your network interface
    handle = pcap_open_live("en0", BUFSIZ, 1, timeout, errbuf);

    if (handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        exit(1);
    }

    // compile the filter (only packets with IP traffic)
    if (pcap_compile(handle, &filter, "ip", 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // apply the filter
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // start capture process
    pcap_loop(handle, -1, packetHandler, NULL);

    // cleanup
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}