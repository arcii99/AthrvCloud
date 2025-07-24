//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

void process_packet(u_char *, const struct pcap_pkthdr *, const u_char *);

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];

    char *device = "eth0";
    int packet_count_limit = -1;
    int timeout_limit = 10000;

    handle = pcap_open_live(device, BUFSIZ, packet_count_limit, timeout_limit, error_buffer);

    if (handle == NULL) {
        fprintf(stderr, "Failed to open device %s: %s\n", device, error_buffer);
        return 1;
    }

    pcap_loop(handle, packet_count_limit, process_packet, NULL);

    pcap_close(handle);

    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *packet_header, const u_char *packet) {
    static int packet_count = 0;

    printf("Packet #%d:\n", ++packet_count);

    printf("Packet size: %d bytes\n\n", packet_header->len);

    struct ether_header *eth_header;
    eth_header = (struct ether_header *) packet;

    if (ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
        printf("IP packet\n");
    } else if (ntohs(eth_header->ether_type) == ETHERTYPE_ARP) {
        printf("ARP packet\n");
    } else {
        printf("Other packet\n");
    }

    printf("\n\n");
}