//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ether.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer);

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *ptr = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (ptr == NULL) {
        fprintf(stderr, "Could not open device: %s\n", errbuf);
        return 1;
    }

    if (pcap_loop(ptr, -1, process_packet, NULL) == -1) {
        fprintf(stderr, "Could not start packet capture\n");
        return 2;
    }

    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer)
{
    int size = header->len;

    struct ether_header *eth = (struct ether_header *)buffer;
    printf("Source MAC: %s\n", ether_ntoa((const struct ether_addr *)&eth->ether_shost));
    printf("Destination MAC: %s\n", ether_ntoa((const struct ether_addr *)&eth->ether_dhost));

    printf("Packet size: %d bytes\n", size);
    printf("Payload: ");

    for (int i = 0; i < size; i++) {
        printf("%02x ", *(buffer + i));
    }

    printf("\n\n");
}