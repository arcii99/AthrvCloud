//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define ETHER_ADDR_LEN 6

struct ether_header {
    unsigned char ether_dhost[ETHER_ADDR_LEN];
    unsigned char ether_shost[ETHER_ADDR_LEN];
    unsigned short ether_type;
};

void packet_handler(u_char *user_args, const struct pcap_pkthdr *packet_header, const u_char *packet_body) {
    struct ether_header *ethernet_header;
    ethernet_header = (struct ether_header*) packet_body;

    printf("Source MAC Address: %02x:%02x:%02x:%02x:%02x:%02x\n", ethernet_header->ether_shost[0], ethernet_header->ether_shost[1], ethernet_header->ether_shost[2], ethernet_header->ether_shost[3], ethernet_header->ether_shost[4], ethernet_header->ether_shost[5]);
    printf("Destination MAC Address: %02x:%02x:%02x:%02x:%02x:%02x\n", ethernet_header->ether_dhost[0], ethernet_header->ether_dhost[1], ethernet_header->ether_dhost[2], ethernet_header->ether_dhost[3], ethernet_header->ether_dhost[4], ethernet_header->ether_dhost[5]);

    switch (ntohs(ethernet_header->ether_type)) {
        case 0x0800: // IPv4
            printf("Packet Type: IPv4\n");
            break;

        case 0x0806: // ARP
            printf("Packet Type: ARP\n");
            break;

        case 0x86DD: // IPv6
            printf("Packet Type: IPv6\n");
            break;

        default:
            printf("Packet Type: Unknown\n");
    }
}

int main() {
    pcap_t *handle;
    char *dev, errbuf[PCAP_ERRBUF_SIZE];

    /* Find a capture device */
    dev = pcap_lookupdev(errbuf);

    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return 2;
    }

    /* Open the device for sniffing */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }

    printf("Listening on device: %s\n", dev);

    /* Start capturing packets */
    pcap_loop(handle, -1, packet_handler, NULL);

    /* Cleanup */
    pcap_close(handle);
    return 0;
}