//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/if_ether.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int count = 1;

    struct ether_header *eth_header = (struct ether_header *) packet;
    if (ntohs(eth_header->ether_type) != ETHERTYPE_IP) {
        printf("Packet %d is not an IP packet. Skipping...\n", count);
        return;
    }

    struct ip *ip_header = (struct ip *) (packet + sizeof(struct ether_header));
    printf("Packet %d:\n", count);
    printf("Source IP: %s\n", inet_ntoa(ip_header->ip_src));
    printf("Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));

    count++;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(1);
    }

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handle = pcap_open_live(argv[1], BUFSIZ, 0, 1000, errbuf);
    if (pcap_handle == NULL) {
        fprintf(stderr, "pcap_open_live() failed: %s\n", errbuf);
        exit(1);
    }

    if (pcap_datalink(pcap_handle) != DLT_EN10MB) {
        fprintf(stderr, "%s is not an Ethernet device\n", argv[1]);
        exit(1);
    }

    if (pcap_loop(pcap_handle, -1, packet_handler, NULL) < 0) {
        fprintf(stderr, "pcap_loop() failed: %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }

    pcap_close(pcap_handle);
    return 0;
}