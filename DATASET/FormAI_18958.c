//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(unsigned char *param, const struct pcap_pkthdr *header, const unsigned char *pkt_data);

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* descr = pcap_open_live("eth0", BUFSIZ, 0, -1, errbuf);

    if(descr == NULL) {
        printf("pcap_open_live() failed due to [%s]\n", errbuf);
        return EXIT_FAILURE;
    }

    printf("Listening on eth0...\n");

    if(pcap_loop(descr, 0, packet_handler, NULL) < 0) {
        printf("pcap_loop() failed due to [%s]\n", pcap_geterr(descr));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void packet_handler(unsigned char *param, const struct pcap_pkthdr *header, const unsigned char *pkt_data) {
    printf("Packet received!\n");
    printf("Packet size: %d bytes\n", header->len);
    printf("Number of bytes displayed: %d\n", header->caplen);

    // Display packet data
    for(int i=0; i < header->caplen; i++) {
        printf("%.2x ", *(pkt_data + i));
    }
    printf("\n\n");
}