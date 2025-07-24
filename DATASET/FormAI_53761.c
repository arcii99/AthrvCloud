//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // open device for capturing packets
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // start packet capture
    if (pcap_loop(handle, -1, packet_handler, NULL) != 0) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    int i;

    printf("Packet length: %d\n", header->len);
    printf("Number of bytes: %d\n", header->caplen);
    printf("Timestamp: %ld\n", header->ts.tv_sec);

    for (i = 0; i < header->caplen; i++) {
        printf("%02x ", pkt_data[i]);
    }
    printf("\n\n");
}