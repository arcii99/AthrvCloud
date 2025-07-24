//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: recursive
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

void recursive_capture(pcap_t *adapter, int count) {
    if (count > 0 && adapter != NULL) {
        struct pcap_pkthdr header;
        const u_char *pkt_data;
        int res = pcap_next_ex(adapter, &header, &pkt_data);
        if (res == 1) {
            printf("Packet captured! Length: %d\n", header.len);
            packet_handler(NULL, &header, pkt_data);
        }
        recursive_capture(adapter, count-1);
    } else {
        printf("Capture completed.\n");
        pcap_close(adapter);
    }
}

int main() {
    char errbuff[PCAP_ERRBUF_SIZE];
    pcap_t *adapter = pcap_open_offline("example.pcap", errbuff);
    
    if (adapter == NULL) {
        printf("Failed to open pcap file: %s\n", errbuff);
        return 1;
    }

    recursive_capture(adapter, 100);
    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    /* Implement custom packet handling logic */
    printf("Packet processed successfully.\n");
}