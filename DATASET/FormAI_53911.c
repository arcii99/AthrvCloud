//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scalable
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    printf("Received packet of length %d\n", pkthdr->len);
}

int main(void) {
    char *devname = "eth0";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap = pcap_open_live(devname, BUFSIZ, 0, 1000, errbuf);
    if (pcap == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return 1;
    }

    if (pcap_datalink(pcap) != DLT_EN10MB) {
        fprintf(stderr, "Error: only Ethernet links are supported\n");
        pcap_close(pcap);
        return 1;
    }

    pcap_loop(pcap, -1, packetHandler, NULL);

    pcap_close(pcap);
    return 0;
}