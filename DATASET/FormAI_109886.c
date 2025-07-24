//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: multiplayer
#include <stdio.h>
#include <pcap.h>
#include <string.h>
#include <stdlib.h>

#define ETHER_ADDR_LEN  6

// Ethernet header
struct ether_header {
    u_char  ether_dhost[ETHER_ADDR_LEN];      // Destination Host MAC Address
    u_char  ether_shost[ETHER_ADDR_LEN];      // Source Host MAC Address
    u_short ether_type;                       // Protocol
};

// IP Header
struct ip_header {
    u_char  ip_vhl;                           // Version and Header Length
    u_char  ip_tos;                           // Type of Service
    u_short ip_len;                           // Total Length
    u_short ip_id;                            // Identification
    u_short ip_off;                           // Fragment Offset
    u_char  ip_ttl;                           // Time to Live
    u_char  ip_p;                             // Protocol
    u_short ip_sum;                           // Checksum
    struct  in_addr ip_src,ip_dst;            // Source and Destination IP Addresses
};

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {

    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];

    dev = pcap_lookupdev(errbuf);

    if (dev == NULL) {
        fprintf(stderr, "Could not find default device: %s\n", errbuf);
        return 2;
    }

    printf("Device: %s\n", dev);

    pcap_t *handle;
    int status, packets_received;

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return 2;
    }

    status = pcap_loop(handle, -1, process_packet, (u_char *)&packets_received);

    if(status != 0) {
        printf("pcap_loop exited with status %d: %s\n", status, pcap_geterr(handle));
        return 2;
    }

    pcap_close(handle);

    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {

    int *packets_received = (int *)args;
    struct ether_header *eth_header;
    struct ip_header *ip_header;
    u_char *data;

    (*packets_received)++;

    printf("Packet %d\n", *packets_received);

    eth_header = (struct ether_header *) packet;
    ip_header = (struct ip_header *) (packet + sizeof(struct ether_header));

    printf("Source IP Address: %s\n", inet_ntoa(ip_header->ip_src));
    printf("Destination IP Address: %s\n", inet_ntoa(ip_header->ip_dst));
    printf("Protocol: %d\n", ip_header->ip_p);

    // Check for TCP packets
    if(ip_header->ip_p == IPPROTO_TCP) {
        printf("TCP Packet\n");
        data = (u_char *)(packet + sizeof(struct ether_header) + sizeof(struct ip_header));
        int data_length = ntohs(ip_header->ip_len) - sizeof(struct ip_header) - sizeof(struct ether_header);

        // Do something with the data
        // Examples: Save to file, analyze contents, extract relevant information
        // This will vary depending on what you want to do with the packets
    }
}