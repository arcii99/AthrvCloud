//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: creative
#include <pcap.h>
#include <stdio.h>

int main() {
    char* device = "lo";

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Could not open device %s: %s\n", device, errbuf);
        return 1;
    }

    while (1) {
        struct pcap_pkthdr header;
        const u_char* packet;

        packet = pcap_next(handle, &header);
        printf("Received packet Length: %d\n", header.len);
    }

    pcap_close(handle);
    return 0;
}