//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: creative
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {
    int size = header->len;
    printf("Packet size: %d\n", size);
    printf("Packet data: ");
    for (int i = 0; i < size; i++) {
        printf("%02x", buffer[i]);
    }
    printf("\n");
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return 2;
    }
    printf("Starting packet capture on eth0...\n");
    pcap_loop(handle, 0, process_packet, NULL);
    pcap_close(handle);
    return 0;
}