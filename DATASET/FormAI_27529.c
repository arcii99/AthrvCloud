//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: minimalist
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main(int argc, char *argv[]) {
    pcap_t *descr;
    char errbuf[PCAP_ERRBUF_SIZE];

    if(argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    descr = pcap_open_live(argv[1], BUFSIZ, 0, -1, errbuf);
    if(descr == NULL) {
        printf("pcap_open_live(): %s\n", errbuf);
        return 1;
    }

    if(pcap_datalink(descr) != DLT_EN10MB) {
        printf("This program only works on Ethernet networks.\n");
        return 1;
    }

    if(pcap_loop(descr, 0, packet_handler, NULL) < 0) {
        printf("pcap_loop(): %s\n", pcap_geterr(descr));
        return 1;
    }

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    printf("Packet captured.\n");
    // Do something with the captured packet data
}