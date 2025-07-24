//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: decentralized
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <netinet/ether.h>

#define MAX_PACKET_LEN 65535
#define READ_TIMEOUT_MS 1000

char *dev;
char errbuf[PCAP_ERRBUF_SIZE];
pcap_t *handle;
struct bpf_program fp;
char filter_exp[] = "ip";
int num_packets = -1;

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet capture successful!\n");

    // extract Ethernet header from packet
    const struct ether_header *ethernet_header;
    ethernet_header = (const struct ether_header*) packet;

    // print MAC addresses
    printf("Source MAC Address: %s\n", ether_ntoa((const struct ether_addr*) &ethernet_header->ether_shost));
    printf("Destination MAC Address: %s\n", ether_ntoa((const struct ether_addr*) &ethernet_header->ether_dhost));
}

int main(int argc, char *argv[]) {
    // get network device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("Error finding network device: %s\n", errbuf);
        return 1;
    }

    // open network device for packet capture
    handle = pcap_open_live(dev, MAX_PACKET_LEN, 1, READ_TIMEOUT_MS, errbuf);
    if (handle == NULL) {
        printf("Error opening network device for packet capture: %s\n", errbuf);
        return 1;
    }

    // compile filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("Error compiling filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    // apply filter expression
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error applying filter expression: %s\n", pcap_geterr(handle));
        return 1;
    }

    // start packet capture
    pcap_loop(handle, num_packets, process_packet, NULL);

    // cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}