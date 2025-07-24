//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[]) {
    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    dev = pcap_lookupdev(errbuf);

    if (dev == NULL) {
        fprintf(stderr, "Couldn't find device: %s\n", errbuf);
        return 1;
    }

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    if (pcap_datalink(handle) != DLT_EN10MB) {
        fprintf(stderr, "Device %s doesn't provide Ethernet headers - not supported\n", dev);
        return 1;
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ethhdr *eth_header;

    eth_header = (struct ethhdr *) packet;

    printf("Source MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
           eth_header->h_source[0],
           eth_header->h_source[1],
           eth_header->h_source[2],
           eth_header->h_source[3],
           eth_header->h_source[4],
           eth_header->h_source[5]);

    printf("Destination MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
           eth_header->h_dest[0],
           eth_header->h_dest[1],
           eth_header->h_dest[2],
           eth_header->h_dest[3],
           eth_header->h_dest[4],
           eth_header->h_dest[5]);

    printf("Protocol type: %d\n", ntohs(eth_header->h_proto));

    printf("Packet size: %d bytes\n", header->len);
}