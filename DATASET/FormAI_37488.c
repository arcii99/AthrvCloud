//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: excited
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    printf("Packet captured!\n");
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live failed: %s\n", errbuf);
        return 1;
    }
    if (pcap_setnonblock(handle, 1, errbuf) == -1) {
        fprintf(stderr, "pcap_setnonblock failed: %s\n", errbuf);
        return 1;
    }
    if (pcap_loop(handle, -1, packet_handler, NULL) == -1) {
        fprintf(stderr, "pcap_loop failed: %s\n", pcap_geterr(handle));
        return 1;
    }
    return 0;
}