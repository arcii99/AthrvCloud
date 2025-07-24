//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr header;
    const u_char *packet;
    int packet_count = 0;

    // Open the capture device
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return 1;
    }

    // Capture packets and print headers
    while (packet_count < 10) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) continue;

        printf("Packet %d:\n", ++packet_count);
        printf("Timestamp: %ld.%06ld\n", header.ts.tv_sec, header.ts.tv_usec);
        printf("Length: %d\n", header.len);
        printf("Capture Length: %d\n", header.caplen);
        printf("Hexdump:\n");
        for (int i = 0; i < header.caplen; i++) {
            printf("%02X ", packet[i]);
            if ((i + 1) % 16 == 0) printf("\n");
        }
        printf("\n\n");
    }

    // Close the capture device
    pcap_close(handle);
    return 0;
}