//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define MAX_PACKETS 10

int main(int argc, char **argv) {
    char *dev_name, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr header;
    const u_char *packet;
    int packet_count = 0;

    /* Use the first available network device */
    dev_name = pcap_lookupdev(errbuf);
    if (dev_name == NULL) {
        fprintf(stderr, "Could not find available device: %s\n", errbuf);
        return 1;
    }

    /* Open the device for packet capture */
    handle = pcap_open_live(dev_name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev_name, errbuf);
        return 1;
    }

    /* Capture and print up to MAX_PACKETS packets */
    while (packet_count < MAX_PACKETS) {
        packet = pcap_next(handle, &header);
        if (packet != NULL) {
            printf("Packet #%d captured: %ld bytes\n", packet_count, header.len);
            for (u_int i = 0; i < header.caplen; i++) {
                /* Print the packet as ASCII characters */
                printf("%c", isprint(packet[i]) ? packet[i] : '.');
            }
            printf("\n");
            packet_count++;
        }
    }

    /* Clean up */
    pcap_close(handle);
    printf("Captured %d packets.\n", packet_count);
    return 0;
}